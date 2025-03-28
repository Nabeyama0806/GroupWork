#pragma once
#include <list>

class ModelActor;

class ModelActorCollision
{
private:
	std::list<ModelActor*> m_modelActorList;	//�Փ˔�����s�����X�g

public:
	//�R���X�g���N�^
	ModelActorCollision() {}

	//�V���O���g��
	static ModelActorCollision* GetInstance()
	{
		static ModelActorCollision instance;
		return &instance;
	}

	//�o�^
	void Register(ModelActor* actor)
	{
		m_modelActorList.push_back(actor);
	}

	//�폜
	void Remove(ModelActor* actor)
	{
		m_modelActorList.remove(actor);
	}

	//�X�V
	void Update();
	// �`��
	void Draw();
};