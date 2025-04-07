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
#include "HitCollider.h"
#include "Camera.h"
#include "Player.h"
#include "UiBottle.h"
#include "DxLib.h"

#include "FireGimmick.h"	
#include "WaterGimmick.h"

//������
void SceneGame::Initialize()
{
	//���[�g
	m_rootNode = new Node();

	//���C���J����
	m_mainCamera = new Camera();
	m_rootNode->AddChild(m_mainCamera);

	//�w�i
	m_stage = new ModelActor("Ground", "Environment/BaseStage3.0.mv1");
	m_rootNode->AddChild(m_stage);

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

	//��
	Vector3 wallPos	 = Vector3(0, 100, 2000);
	Vector3 wallSize = Vector3(4000, 500, 100);

	actorLayer->AddChild(new HitCollider(
		"Wall",
		Vector3(0, 100, 2000),
		Vector3(4000, 500, 100)
	));
	actorLayer->AddChild(new HitCollider(
		"Wall",
		Vector3(0, 100, -2000),
		Vector3(4000, 500, 100)
	));
	actorLayer->AddChild(new HitCollider(
		"Wall",
		Vector3(2000, 100, 0),
		Vector3(100, 500, 4000)
	));
	actorLayer->AddChild(new HitCollider(
		"Wall",
		Vector3(-2000, 100, 0),
		Vector3(100, 500, 4000)
	));

	// ��
	Vector3 floorPos = Vector3(0, -20, 0);
	Vector3 floorSize = Vector3(4000, 40, 4000);
	actorLayer->AddChild(new HitCollider(
		"Ground",
		floorPos,
		floorSize
	));

	actorLayer->AddChild(new FireGimmick(Vector3(-100, 100, 100)));
	actorLayer->AddChild(new WaterGimmick(Vector3(300, 0, 100), Vector3(50, 100, 50)));

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