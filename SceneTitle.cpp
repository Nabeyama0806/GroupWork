#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "Input.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Screen.h"
#include "DxLib.h"

//������
void SceneTitle::Initialize()
{
	m_rootNode = new Node();
	m_transform.position = Screen::Center;

	m_sprite = new Sprite();
	m_sprite->Register("Book", SpriteAnimation("Resource/Book/open.png",30,10,false));
	m_sprite->gridSize = Screen::Size;
	m_sprite->Load();
	m_sprite->Play("Book");

	//�w�i
	//m_rootNode->AddChild(new SpriteActor("BackGround", "Resource/Texture/title.png", Screen::Center));

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Resource/sound/bgm_title.mp3");
	SoundManager::Play(m_bgm, DX_PLAYTYPE_LOOP);

	SetBackgroundColor(255, 255, 255); //�w�i�F�̕ύX
}

//�I��
void SceneTitle::Finalize()
{
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//�X�V
SceneBase* SceneTitle::Update()
{
	switch (m_phase)
	{
	case Phase::Run:
		//�����ꂩ�̃L�[�������ꂽ��Q�[���V�[���ֈړ�
		if (Input::GetInstance()->IsAnyKeyDown())
		{
			//���ʉ�
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);
			m_phase = Phase::OpenBook;
		}
		break;

	case Phase::OpenBook:
		return new SceneGame();
		
		break;
	}

	//�m�[�h�̍X�V
	m_rootNode->TreeUpdate();

	return this;
}

//�`��
void SceneTitle::Draw()
{
	//�m�[�h�̕`��
	m_rootNode->TreeDraw();
	m_sprite->Draw(m_transform);
}