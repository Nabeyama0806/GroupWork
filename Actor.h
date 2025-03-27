#pragma once
#include "Node.h"
#include "Transform.h"
#include <string>

class Model;
class Sprite;

class Actor : public Node
{
protected:
	std::string m_name;					//�I�u�W�F�N�g��
	Transform m_transform;				//�p�����
	Model* m_model;
	Sprite* m_sprite;

	virtual void Load() override;		//���\�[�X�̓ǂݍ���
	virtual void Release() override;	//���\�[�X�̉��
	virtual void Draw() override;		//�`��

public:
	//�R���X�g���N�^
	Actor(
		const char* name,
		const char* modelFileName = nullptr,
		const Vector3& position = Vector3()
	);

	//�q�m�[�h���܂ލX�V
	virtual void TreeUpdate() override;

	//�p���̎擾
	const Transform& GetTransform() const
	{
		return m_transform;
	}

	//���W�̎擾
	const Vector3& GetPosition() const
	{
		return m_transform.position;
	}

	//���O�̎擾
	const std::string& GetName() const
	{
		return m_name;
	}

	//�Փ˃C�x���g
/*	virtual void OnCollision(const Actor* other)
	{
		//�������Ȃ�
	}*/
};