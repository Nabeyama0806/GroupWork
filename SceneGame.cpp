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
	uiLayer->AddChild(new SpriteActor("reticle", "Resource/Texture/reticle.png", Screen::Center));

	//�v���C���[
	m_player = new Player(m_mainCamera, m_uiBottle);
	actorLayer->AddChild(m_player);
	m_mainCamera->SetLookAt(m_player, m_isLookPlayer);

	//�}�b�v
	m_map = new CreateMap(m_player);
	actorLayer->AddChild(m_map);

	//�X�J�C�{�b�N�X
	ModelActor* skyBox = new ModelActor("SkyBox", "Resource/Model/Skybox.mv1");
	skyBox->ChangeScale(1700);
	actorLayer->AddChild(skyBox);

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Resource/Sound/bgm_game.mp3");
	SoundManager::ChangeVolume(m_bgm, 180);
	SoundManager::Play(m_bgm, DX_PLAYTYPE_LOOP);
}

//�I��
void SceneGame::Finalize()
{
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
	SoundManager::SoundStop(m_bgm);
}

//�X�V
SceneBase* SceneGame::Update()
{
	//�m�[�h�̍X�V
	m_rootNode->TreeUpdate();

	//�v���C���[���S�[������Ύ��̃X�e�[�W�ɑJ��
	switch (m_phase)
	{
	case Phase::Run: //�t�F�[�h�A�E�g�J�n
		if (m_player->GetIsGoal())
		{
			//���ʉ�
			SoundManager::Play("Resource/sound/se_goal.mp3");
			
			if (m_map->GetMapIndex() == static_cast<int>(CreateMap::MapType::Length) - 1)
			{
				return new SceneResult(0);
				break;
			}
			m_phase = Phase::FadeOut;
			Fade::GetInstance()->StartFadeOut(0.8f, Fade::Color::White);
		}
		break;

	case Phase::FadeOut:
		if (!Fade::GetInstance()->IsFade())
		{
			m_player->SetIsGoal();
			m_map->LoadMap();
			m_phase = Phase::Transition;
		}
		break;

	case Phase::Transition:
		Fade::GetInstance()->StartFadeIn(1.2f, Fade::Color::White);
		m_phase = Phase::Run;
		break;
	}

	//0�L�[�������ꂽ�王�_��؂�ւ���
	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_SPACE))
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