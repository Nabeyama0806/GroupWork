#include "Node.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Input.h"
#include "Screen.h"
#include "TitleSelect.h"
#include "DxLib.h"
#include <fstream>

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

	//�I��p�̃{�^��
	m_rootNode->AddChild(new SpriteActor("Select", "Resource/Texture/select.png", Screen::Center));

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
		//�G���^�[�L�[�������ꂽ��Q�[���V�[���ֈړ�
		if (Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT))
		{
			//���ʉ�
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);
			m_phase = Phase::OpenBook;
		}
		break;

	case Phase::OpenBook:
		//�A�j���[�V�����̍X�V
		m_sprite->Update();
		m_sprite->Play(AnimeName[static_cast<int>(m_anime)]);
		
		//�A�j���[�V�������I���ƃV�[���J��
		if (m_sprite->IsFinishAnime())
		{
			if (m_anime == Anime::Initial) m_anime = Anime::Final;
			//else return new SceneGame(m_select->GetIsContinued());
		}
		break;
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

//�f�[�^�̓ǂݍ���
int SceneTitle::DataLoad()
{
	std::fstream file;
	std::string data;

	//�Z�[�u�p�t�@�C�����J��
	file.open("SaveData.txt");

	//�I�[�v���ł��Ȃ������炱���ŏI��
	if (!file.is_open()) return -1;

	//�f�[�^�̓ǂݍ���
	getline(file, data);

	//�t�@�C�������
	file.close();

	return std::stoi(data);
}

//�f�[�^�̏�������
void SceneTitle::DataSeve(int data)
{
	std::fstream file;

	//�Z�[�u�p�t�@�C�����J��
	file.open("SaveData.txt");

	//�I�[�v���ł��Ȃ������炱���ŏI��
	if (!file.is_open()) return;

	//�f�[�^�̏�������
	file << std::to_string(data);

	//�t�@�C�������
	file.close();
}