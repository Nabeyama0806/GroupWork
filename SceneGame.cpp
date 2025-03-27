#include "SceneGame.h"
#include "SceneResult.h"
#include "ModelLoader.h"
#include "ImageLoader.h"
#include "Screen.h"
#include "Fade.h"
#include "Time.h"
#include "Input.h"
#include "Node.h"
#include "Sprite.h"
#include "ModelActor.h"
#include "SpriteActor.h"
#include "HitBox.h"
#include "Camera.h"
#include "Player.h"
#include "DxLib.h"

//������
void SceneGame::Initialize()
{
	//�摜�̎��O�ǂݍ���
	for (auto image : ImagePreload)
	{
		ModelLoader::GetInstance()->Load(image);
	}

	//���[�g
	m_rootNode = new Node();

	//���C���J����
	m_mainCamera = new Camera();
	m_rootNode->AddChild(m_mainCamera);

	//�w�i
	m_rootNode->AddChild(new ModelActor("Ground", "Environment/Environment.mv1"));

	//�A�N�^�[���C���[
	Node* actorLayer = new Node();
	m_rootNode->AddChild(actorLayer);

	//UI���C���[
	Node* uiLayer = new Node();
	m_rootNode->AddChild(uiLayer);

	//�v���C���[
	m_player = new Player(m_mainCamera);
	actorLayer->AddChild(m_player);
	m_mainCamera->SetlookAt(m_player);

	// Ui(���u��)
	//uiLayer->AddChild(new SpriteActor("ui", "Resource/title.png", Screen::Center));

	//��
	Vector3 pos	 = Vector3(0, 0, 600);
	Vector3 size = Vector3(300, 300, 50);
	actorLayer->AddChild(new HitBox(
		"Wall",
		pos,
		size
	));
	actorLayer->AddChild(new ModelActor("Pos", "Man/Man.mv1", pos));

	//BGM

}

//�I��
void SceneGame::Finalize()
{
	//���O�ǂݍ��݂����摜�̔j��
	for (auto image : ImagePreload)
	{
		ModelLoader::GetInstance()->Delete(image);
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
	return this;
}

//�`��
void SceneGame::Draw()
{
	//�m�[�h�̕`��
	m_rootNode->TreeDraw();
}