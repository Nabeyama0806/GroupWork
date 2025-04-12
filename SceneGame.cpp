#include "SceneGame.h"
#include "SceneResult.h"
#include "SoundManager.h"
#include "Screen.h"
#include "Fade.h"
#include "Time.h"
#include "Input.h"
#include "Node.h"
#include "Sprite.h"
#include "ModelActor.h"
#include "SpriteActor.h"
#include "Camera.h"
#include "Player.h"
#include "UiBottle.h"
#include "CreateMap.h"
#include "DxLib.h"

//������
void SceneGame::Initialize()
{
	//���[�g
	m_rootNode = new Node();

	//���C���J����
	m_mainCamera = new Camera();
	m_rootNode->AddChild(m_mainCamera);

	//�w�i
	//m_stage = new ModelActor("Ground", "Environment/BaseStage3.0.mv1");
	//m_rootNode->AddChild(m_stage);

	//�A�N�^�[���C���[
	Node* actorLayer = new Node();
	m_rootNode->AddChild(actorLayer);

	//UI���C���[
	Node* uiLayer = new Node();
	m_rootNode->AddChild(uiLayer);

	//�{�g��UI�̕\��
	m_uiBottle = new UiBottle();
	uiLayer->AddChild(m_uiBottle);

	//�Ə��̕\��
	uiLayer->AddChild(new SpriteActor("reticle", "Resource/reticle.png", Screen::Center));

	//�v���C���[
	m_player = new Player(m_mainCamera, m_uiBottle);
	actorLayer->AddChild(m_player);
	m_mainCamera->SetLookAt(m_player, m_isLookPlayer);

	// �}�b�v
	actorLayer->AddChild(new CreateMap());

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Sound/bgm_game.mp3");
	SoundManager::GetInstance()->SoundPlay(m_bgm, DX_PLAYTYPE_LOOP);

	//�w�i�F�̕ύX
	SetBackgroundColor(230, 230, 230);
}

//�I��
void SceneGame::Finalize()
{
	//�摜�̎��O�ǂݍ���
	for (auto sprite : SpritePreload)
	{
		SpriteLoader::GetInstance()->Delete(sprite);
	}

	//���f���̎��O�ǂݍ���
	for (auto model : ModelPreload)
	{
		ModelLoader::GetInstance()->Delete(model);
	}

	//�m�[�h�̍폜
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;

	//BGM
	DeleteSoundMem(m_bgm);
}

//�X�V
SceneBase* SceneGame::Update()
{
	//�m�[�h�̍X�V
	m_rootNode->TreeUpdate();

	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_1))
	{
		m_isLookPlayer = !m_isLookPlayer;
		m_mainCamera->SetLookAt(m_isLookPlayer ? m_player : m_stage, m_isLookPlayer);
	}

	return this;
}

//�`��
void SceneGame::Draw()
{
	//�m�[�h�̕`��
	m_rootNode->TreeDraw();
}