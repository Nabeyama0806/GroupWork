#pragma once
#include "SceneBase.h"
#include "Node.h"
#include "Transform.h"

class Node;
class Sprite;

//�^�C�g���V�[��
class SceneTitle : public SceneBase
{
private:
	//�t�F�[�Y
	enum class Phase
	{
		Run,		//���s��
		OpenBook,	//�{���J��
	};

	Node* m_rootNode;
	Phase m_phase;
	Sprite* m_sprite;
	Transform m_transform;
	int m_bgm;

public:
	//�R���X�g���N�^
	SceneTitle() :
		m_rootNode(nullptr),
		m_phase(Phase::Run),
		m_sprite(nullptr),
		m_bgm(0){}

	virtual void Initialize() override;				//������
	virtual void Finalize() override;				//�I��
	virtual SceneBase* Update() override;			//�X�V
	virtual void Draw() override;					//�`��
};