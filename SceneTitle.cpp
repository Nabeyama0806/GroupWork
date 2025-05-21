#include "Node.h"
#include "PlayData.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Input.h"
#include "Time.h"
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
	for (int i = 0; i < static_cast<int>(TitleAnime::Length); ++i)
	{
		m_sprite->Register(TitleAnimeName[i], TitleAnimeData[i]);
	}
	for (int i = 0; i < static_cast<int>(SelectAnime::Length); ++i)
	{
		m_sprite->Register(SelectAnimeName[i], SelectAnimeData[i]);
	}
	m_sprite->Load();
	
	m_stageSprite = new Sprite();
	for (int i = 0; i < static_cast<int>(CreateMap::MapType::Length); ++i)
	{
		m_stageSprite->Register(SelectStage[i], SelectStageData[i]);
	}
	m_stageSprite->Load();

	//�I��p�̃J�[�\��
	m_select = new TitleSelect();
	m_rootNode->AddChild(m_select);
	Input::GetInstance()->SetMouseDispFlag(true);

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
		m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);

		//�L�[�������ꂽ��X�e�[�W�I���ֈړ�
		if (Input::GetInstance()->IsDecision() && m_select->GetIsKey() ||
			Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT) && !m_select->GetIsKey())
		{
			if (!m_select->GetOnCursor()) break;

			//���ʉ�
			SoundManager::Play("Resource/sound/se_start.mp3");

			if (!m_select->GetIsContinued())
			{
				m_stageNum = 0;
				m_isReset = true;
			}
			else  m_stageNum = m_playData->GetMapData();
			m_phase = Phase::Start;
		}
		break;

	case Phase::Start:
		//�A�j���[�V�������I���ƃX�e�[�W�I���֑J��
		m_select->SetPhase(TitleSelect::SelectType::StageSelect);
		m_sprite->Update();
		m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
		if (m_sprite->IsFinishAnime())
		{
			m_phase = Phase::StageSelect;
			m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::FinishAnime)]);
		}
		break;

	case Phase::StageSelect:
		//�A�j���[�V�����̍X�V
		m_sprite->Update();
		if (m_titleAnime == TitleAnime::Close)
		{
			m_select->SetPhase(TitleSelect::SelectType::GameSelect);
			m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
			if (m_sprite->IsFinishAnime())
			{
				m_titleAnime = TitleAnime::Open;
				m_phase = Phase::Run;
				break;
			}
		}

		m_stageSprite->Update();
		if (m_sprite->IsFinishAnime())
		{
			m_stageSprite->Play(SelectStage[m_stageNum]);
			m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::FinishAnime)]);
		}

		if (!m_sprite->IsFinishAnime()) return this;

		//�ЂƂ�̃X�e�[�W
		if (m_select->RightButton())
		{
			m_stageNum--;

			SoundManager::Play("Resource/sound/se_start.mp3");

			if (m_stageNum < 0) m_stageNum = 0;
			else
			{
				m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::Prev)]);
			}
		}

		//�ЂƂO�̃X�e�[�W
		if (m_select->LeftButton())
		{
			if (!m_isReset)
			{
				m_stageNum++;
				if (m_stageNum > m_playData->GetMapData())
				{
					m_stageNum = m_playData->GetMapData();
				}
				else
				{
					m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::Next)]);
				}
			}

			SoundManager::Play("Resource/sound/se_start.mp3");
		}

		//�J�n�{�^��
		if (m_select->SelectButtonLeft())
		{
			//���ʉ�
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);

			//�v���C�f�[�^�̋L�^
			m_playData->Save(m_stageNum, m_playData->GetBottleData());

			return new SceneGame(m_playData, m_stageNum, m_isReset);
		}

		//�߂�{�^��
		if (m_select->SelectButtonRight())
		{
			m_isReset = false;
			SoundManager::Play("Resource/sound/se_start.mp3");
			m_titleAnime = TitleAnime::Close;
		}
	}

	return this;
}

//�`��
void SceneTitle::Draw()
{
	m_sprite->Draw(m_transform);
	// �X�e�[�W�I���̕`��
	if (m_phase == Phase::StageSelect)
	{  
		if (m_sprite->IsFinishAnime()) m_stageSprite->Draw(m_transform);

		/*
		m_elapsedTime -= Time::GetInstance()->GetDeltaTime();
		if (m_elapsedTime > 0) return;
		*/
	}

	//�m�[�h�̕`��
	m_rootNode->TreeDraw();
}