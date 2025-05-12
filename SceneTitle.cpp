#include "Node.h"
#include "PlayData.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Input.h"
#include "Screen.h"
#include "TitleSelect.h"
#include "DxLib.h"

//������
void SceneTitle::Initialize()
{
	m_rootNode = new Node();
	m_transform.position = Screen::Center;

	//�A�j���[�V�����̓o�^
	m_sprite = new Sprite();
	m_sprite->gridSize = Screen::Size;
	for (int i = 0; i < static_cast<int>(OpenAnime::Length); ++i)
	{
		m_sprite->Register(OpenAnimeName[i], OpenAnimeDate[i]);
	}
	for (int i = 0; i < static_cast<int>(SelectAnime::Length); ++i)
	{
		m_sprite->Register(SelectAnimeName[i], SelectAnimeData[i]);
	}
	m_sprite->Load();
	
	//�I��p�̃J�[�\��
	m_select = new TitleSelect();
	m_rootNode->AddChild(m_select);

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Resource/sound/bgm_title.mp3");
	SoundManager::Play(m_bgm, DX_PLAYTYPE_LOOP);

	//�w�i�F�̕ύX
	SetBackgroundColor(255, 255, 255); 
}

void SceneTitle::Finalize()
{
	//�m�[�h�̍폜
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//�X�V
SceneBase* SceneTitle::Update()
{
	//�m�[�h�̍X�V
	m_rootNode->TreeUpdate();

	switch (m_phase)
	{
	case Phase::Run:
		
		//�L�[�������ꂽ��X�e�[�W�I���ֈړ�
		if (Input::GetInstance()->IsDecision())
		{
			//���ʉ�
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);
			
			//�Z�[�u�f�[�^�̓ǂݍ���
			if (!m_select->GetIsContinued()) m_playData->Reset();
			m_playData->Load();
			m_stageNum = m_playData->GetMapData();
			m_phase = Phase::Start;
		}

		break;

	case Phase::Start:
		m_select->Destroy();

		//�A�j���[�V�������I���ƃX�e�[�W�I���֑J��
		m_sprite->Update();
		m_sprite->Play(OpenAnimeName[static_cast<int>(m_openAnime)]);
		if (m_sprite->IsFinishAnime())
		{
			if (m_openAnime == OpenAnime::First) m_openAnime = OpenAnime::Second;
			else m_phase = Phase::StageSelect;
		}
		break;

	case Phase::StageSelect:

		//�A�j���[�V�����̍X�V
		if (m_sprite->IsFinishAnime()) m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::FinishAnime)]);
		m_sprite->Update();

		//�ЂƂO�̃X�e�[�W
		if (Input::GetInstance()->StageSelectLeft() && m_sprite->IsFinishAnime())
		{
			m_stageNum--;

			if (m_stageNum < 0) m_stageNum = 0;
			else m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::Prev)]);
		}

		//�ЂƂ�̃X�e�[�W
		if (Input::GetInstance()->StageSelectRight() && m_sprite->IsFinishAnime())
		{
			m_stageNum++;

			if (m_stageNum > m_playData->GetMapData()) m_stageNum = m_playData->GetMapData();
			else m_sprite->Play(SelectAnimeName[static_cast<int>(OpenAnime::Second)]);
		}

		//����{�^���������ꂽ��Q�[���J�n
		if (Input::GetInstance()->IsDecision()) return new SceneGame(m_playData, m_stageNum);
	}

	return this;
}

//�`��
void SceneTitle::Draw()
{
	//�m�[�h�̕`��
	m_sprite->Draw(m_transform);
	m_rootNode->TreeDraw();
}