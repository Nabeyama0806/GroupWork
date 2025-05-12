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
class PlayData;

//�Q�[���V�[��
class SceneGame : public SceneBase
{
private:
	static constexpr float ResultTransitionTime = 2.0f;	//�v���C���[������ł��烊�U���g��ʂɑJ�ڂ���܂ł̎���
	
	// ���z�̐��l
	static constexpr Vector3 SunPosition = Vector3(1000, 1500, 0);
	static constexpr float SunRange = 20000.0f;
	static constexpr Vector3 SunAtten = Vector3(0.0f, 0.002f, 0.0f);

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

	Node* m_rootNode;		//�c���[�m�[�h
	PlayData* m_playData;
	ModelActor* m_stage;	// �w�i�X�e�[�W
	CreateMap* m_map;
	UiBottle* m_uiBottle;	
	Camera* m_mainCamera;	//�v���C���[
	Player* m_player;		//�v���C���[
	Phase m_phase;
	Vector3 cameraPos = Vector3(0, 0, -700);

	bool m_isLookPlayer;

	float m_resultTransitionTime;
	int m_stageNum;
	int m_bgm;

public:
	//�R���X�g���N�^
	SceneGame(PlayData* playData, int stageNum) :
		m_rootNode(nullptr), 
		m_playData(playData),
		m_stage(nullptr),
		m_map(nullptr),
		m_player(nullptr),
		m_phase(Phase::Run),
		m_mainCamera(nullptr),
		m_uiBottle(nullptr),
		m_isLookPlayer(true),
		m_resultTransitionTime(ResultTransitionTime),
		m_stageNum(stageNum),
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