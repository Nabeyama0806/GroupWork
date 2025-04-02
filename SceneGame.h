#pragma once
#include"SceneBase.h"
#include "SoundLoader.h"
#include "Vector3.h"
#include <list>

//�N���X�̑O���錾
class Node;
class ModelActor;
class Player;
class Camera;
class SpriteActor;
class UiBottle;

//	�Q�[���V�[��
class SceneGame : public SceneBase
{
private:
	const std::list<const char*> ImagePreload =
	{
		//"title.png"
	};

	static constexpr float ResultTransitionTime = 2.0f;	//�v���C���[������ł��烊�U���g��ʂɑJ�ڂ���܂ł̎���
	Node* m_rootNode;	//�c���[�m�[�h
	ModelActor* m_stage;	// �w�i�X�e�[�W
	Player* m_player;	//�v���C���[
	Camera* m_mainCamera;	//�v���C���[
	SpriteActor* m_tmpUi;	// ���u����UI
	UiBottle* m_uiBottle;	

	Vector3 cameraPos = Vector3(0, 0, -700);

	bool m_isLookPlayer;

	float m_resultTransitionTime;
	int m_bgm;
public:
	//�R���X�g���N�^
	SceneGame() :
		m_rootNode(nullptr), 
		m_stage(nullptr),
		m_player(nullptr),
		m_mainCamera(nullptr),
		m_tmpUi(nullptr),
		m_uiBottle(nullptr),
		m_isLookPlayer(true),
		m_resultTransitionTime(ResultTransitionTime),
		m_bgm(0)
	{
		m_bgm = SoundLoader::GetInstance()->Load("Sound/bgm_game.mp3");
	}

	virtual void Initialize() override;		//������
	virtual void Finalize() override;		//�I��
	virtual SceneBase* Update() override;	//�X�V
	virtual void Draw() override;			//�`��
};