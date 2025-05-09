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
	for (int i = 0; i < static_cast<int>(Anime::Length); ++i)
	{
		m_sprite->Register(AnimeName[i], AnimeDate[i]);
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
		
		//�L�[�������ꂽ��Q�[���V�[���ֈړ�
		if (Input::GetInstance()->IsDecision())
		{
			//���ʉ�
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);
			
			//�Z�[�u�f�[�^�̓ǂݍ���
			if (!m_select->GetIsContinued()) m_playData->Reset();
			m_playData->Load();
			m_phase = Phase::Start;
		}
		break;

	case Phase::Start:
		m_select->Destroy();

		//�A�j���[�V�����̍X�V
		m_sprite->Update();
		m_sprite->Play(AnimeName[static_cast<int>(m_anime)]);
		
		//�A�j���[�V�������I���ƃX�e�[�W�I���֑J��
		if (m_sprite->IsFinishAnime())
		{
			if (m_anime == Anime::Initial) m_anime = Anime::Final;
			else m_phase = Phase::StageSelect;
		}
		break;

	case Phase::StageSelect:
		if (Input::GetInstance()->IsKeyDown(KEY_INPUT_SPACE)
		||  Input::GetInstance()->IsPadDown(PAD_INPUT_1))
		{
			return new SceneGame(m_playData->GetData());
		}
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