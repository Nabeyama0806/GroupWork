#include "Node.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "SelectButton.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "PlayData.h"
#include "Input.h"
#include "Screen.h"
#include "DxLib.h"

//������
void SceneTitle::Initialize()
{
	//�m�[�h
	m_rootNode = new Node();
	m_ModeSelectButtonNode = new Node();
	m_StageSelectButtonNode = new Node();

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
	Input::GetInstance()->SetMouseDispFlag(true);

	//�{�^��
	m_ModeSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/continue.png", SelectButtonSize, LeftSelectButtonPos, std::bind(&SceneTitle::ContinueButton, this)));
	m_ModeSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/newgame.png", SelectButtonSize, RightSelectButtonPos, std::bind(&SceneTitle::NewGameButton, this)));

	m_StageSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/arrow_left.png", ArrowButtonSize, LeftArrowButtonPos, std::bind(&SceneTitle::LeftArrowButton, this)));
	m_StageSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/arrow_right.png", ArrowButtonSize, RightArrowButtonPos, std::bind(&SceneTitle::RightArrowButton, this)));
	m_StageSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/start.png", SelectButtonSize, LeftSelectButtonPos, std::bind(&SceneTitle::StartButton, this)));
	m_StageSelectButtonNode->AddChild(new SelectButton("Resource/Texture/Button/back.png", SelectButtonSize, RightSelectButtonPos, std::bind(&SceneTitle::BackButton, this)));

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
	if (m_phase == Phase::ModeSelect) m_ModeSelectButtonNode->TreeUpdate();
	if (m_phase == Phase::StageSelect) m_StageSelectButtonNode->TreeUpdate();

	// �p�b�h�̉E�X�e�B�b�N�Ń}�E�X�J�[�\���𓮂���
	int padPointX = 0;
	int padPointY = 0;
	DxLib::GetJoypadAnalogInput(&padPointX, &padPointY, DX_INPUT_PAD1);
	// ���x����
	Vector2 movePadPoint = Vector2(padPointX, padPointY);
	Input::GetInstance()->SetPadStick(movePadPoint);

	switch (m_phase)
	{
	case Phase::ModeSelect:
		m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
		break;

	case Phase::OpenBook:
		//�A�j���[�V�������I���ƃX�e�[�W�I���֑J��
		m_sprite->Update();
		m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
		if (m_sprite->IsFinishAnime())
		{
			m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::FinishAnime)]);
			m_phase = Phase::StageSelect;
		}
		break;

	case Phase::StageSelect:
		//�A�j���[�V�����̍X�V
		m_sprite->Update();
		m_stageSprite->Update();

		if (m_titleAnime == TitleAnime::Close)
		{
			m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);
			if (m_sprite->IsFinishAnime())
			{
				m_titleAnime = TitleAnime::Open;
				m_phase = Phase::ModeSelect;
				break;
			}
		}
		if (m_sprite->IsFinishAnime())
		{
			m_stageSprite->Play(SelectStage[m_stageNum]);
			m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::FinishAnime)]);
		}
		break;

	case Phase::GameStart:
		SoundManager::SoundStop(m_bgm);
		return new SceneGame(m_playData, m_stageNum, m_isReset);
		break;
	}

	return this;
}

//�`��
void SceneTitle::Draw()
{
	//�m�[�h�̕`��
	m_sprite->Draw(m_transform);

	// �X�e�[�W�I���̕`��
	if (m_phase == Phase::StageSelect)
	{
		if (m_sprite->IsFinishAnime()) m_stageSprite->Draw(m_transform);
	}

	m_rootNode->TreeDraw();
	if (m_phase == Phase::ModeSelect) m_ModeSelectButtonNode->TreeDraw();
	if (m_phase == Phase::StageSelect) m_StageSelectButtonNode->TreeDraw();
}

//�X�e�[�W�I���̍��E�{�^��
void SceneTitle::LeftArrowButton()
{
	//�A�j���[�V�������I���܂Ń{�^���������Ȃ�
	if (!m_sprite->IsFinishAnime()) return;

	m_stageNum--;

	if (m_stageNum < 0) m_stageNum = 0;
	else
	{
		m_sprite->Play(SelectAnimeName[static_cast<int>(SelectAnime::Prev)]);
	}
}
void SceneTitle::RightArrowButton()
{
	//�A�j���[�V�������I���܂Ń{�^���������Ȃ�
	if (!m_sprite->IsFinishAnime()) return;

	//�����f�[�^�Ȃ牽�����Ȃ�
	if (m_isReset) return;
	
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

//���[�h�I���̃{�^��
void SceneTitle::ContinueButton()
{
	//�A�j���[�V�������I���܂Ń{�^���������Ȃ�
	m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);

	//�f�[�^�̓ǂݍ���
	m_stageNum = m_playData->GetMapData();
	m_phase = Phase::OpenBook;
}
void SceneTitle::NewGameButton()
{
	//�A�j���[�V�������I���܂Ń{�^���������Ȃ�
	m_sprite->Play(TitleAnimeName[static_cast<int>(m_titleAnime)]);

	//�����f�[�^�̍쐬
	m_stageNum = 0;
	m_isReset = true;
	m_phase = Phase::OpenBook;
}

//�X�e�[�W�I���̃{�^��
void SceneTitle::BackButton()
{
	//�A�j���[�V�������I���܂Ń{�^���������Ȃ�
	if (!m_sprite->IsFinishAnime()) return;

	//�����f�[�^�̔j��
	m_isReset = false;

	//�A�j���[�V�����̕ύX
	m_titleAnime = TitleAnime::Close;
}
void SceneTitle::StartButton()
{
	//�A�j���[�V�������I���܂Ń{�^���������Ȃ�
	if (!m_sprite->IsFinishAnime()) return;

	//�v���C�f�[�^�̋L�^
	m_playData->Save(m_stageNum, m_isReset ? 0 : m_playData->GetBottleData(), true);

	//�Q�[���V�[���̋N��
	m_phase = Phase::GameStart;
}