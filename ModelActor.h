#pragma once
#include "ActorBase.h"
#include "Transform.h"
#include <string>

class Model;
class Collider;

class ModelActor : public ActorBase
{
protected:
	Model* m_model;						//3D���f��		
	Collider* m_collider;				//�Փ˔���	

	virtual void Load() override;		//���\�[�X�̓ǂݍ���
	virtual void Release() override;	//���\�[�X�̉��
	virtual void Draw() override;		//�`��

public:
	//�R���X�g���N�^
	ModelActor(
		const char* name,
		const char* modelFileName = nullptr,
		const Vector3& position = Vector3()
	);

	//�q�m�[�h���܂ލX�V
	virtual void TreeUpdate() override;

	//�Փ˔���̌`��擾
	const Collider* GetCollider() const
	{
		return m_collider;
	}

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) {}
};