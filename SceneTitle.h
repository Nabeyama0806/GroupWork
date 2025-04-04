#pragma once
#include "SceneBase.h"
#include "Node.h"

class Node;

//�^�C�g���V�[��
class SceneTitle : public SceneBase
{
private:
	Node* m_rootNode;
	int m_bgm;

public:
	//�R���X�g���N�^
	SceneTitle() :
		m_rootNode(nullptr),
		m_bgm(0){}

	virtual void Initialize() override;				//������
	virtual void Finalize() override;				//�I��
	virtual SceneBase* Update() override;			//�X�V
	virtual void Draw() override;					//�`��
};