#pragma once
#include"SceneBase.h"
#include "ModelLoader.h"
#include "SoundLoader.h"
#include "Vector3.h"
#include <list>

//�N���X�̑O���錾
class Node;
class ModelActor;
class SpriteActor;
class CreateMap;
class UiBottle;
class Camera;
class Player;

//�Q�[���V�[��
class SceneGame : public SceneBase
{
private:

	//�t�F�[�Y
	enum class Phase
	{
		Run,		//���s��
		FadeOut,	//�t�F�[�h�A�E�g
		Transition,	//�J��
	};


	//���f���̎��O�ǂݍ���
	const std::list<const char*> ModelPreload =
	{
		"Resource/Model/bottle_fire.mv1",
		"Resource/Model/bottle_thunder.mv1",
		"Resource/Model/bottle_water.mv1",
		"Resource/Model/bottle_wind.mv1",
	};

	static constexpr float ResultTransitionTime = 2.0f;	//�v���C���[������ł��烊�U���g��ʂɑJ�ڂ���܂ł̎���
	Node* m_rootNode;		//�c���[�m�[�h
	ModelActor* m_stage;	// �w�i�X�e�[�W
	CreateMap* m_map;
	UiBottle* m_uiBottle;	
	Camera* m_mainCamera;	//�v���C���[
	Player* m_player;		//�v���C���[
	Phase m_phase;
	Vector3 cameraPos = Vector3(0, 0, -700);

	bool m_isLookPlayer;

	float m_resultTransitionTime;
	int m_bgm;

public:
	//�R���X�g���N�^
	SceneGame() :
		m_rootNode(nullptr), 
		m_stage(nullptr),
		m_map(nullptr),
		m_player(nullptr),
		m_mainCamera(nullptr),
		m_uiBottle(nullptr),
		m_isLookPlayer(true),
		m_resultTransitionTime(ResultTransitionTime),
		m_bgm(0)
	{
		//���f���̎��O�ǂݍ���
		for (auto model : ModelPreload)
		{
			ModelLoader::GetInstance()->Load(model);
		}
	}

	virtual void Initialize() override;		//������
	virtual void Finalize() override;		//�I��
	virtual SceneBase* Update() override;	//�X�V
	virtual void Draw() override;			//�`��
};