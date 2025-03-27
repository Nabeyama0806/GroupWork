#pragma once
#include "Collider.h"
#include "Collision.h"
#include "DxLib.h"

class CircleCollider : public Collider
{
public:
	int m_radius;

	//�R���X�g���N�^
	CircleCollider(int radius, const Vector3& offset = Vector3()) :
		Collider(offset),
		m_radius(radius) {
	}

	//�Փ˔���
	virtual bool CheckCollision(const Transform& transform1, const Transform& transform2, const Collider* collider) const override
	{
		//�_�u���f�B�X�p�b�`�ɂ��`�󎯕�
		return collider->CheckCollision(transform1, transform2, this);
	}

	//��`�Ɖ~�`�̓����蔻��
	virtual bool CheckCollision(const Transform& transform1, const Transform& transform2, const BoxCollider* collider) const override
	{
		return Collision::Check(transform1, collider, transform2, this);
	}

	//�~�`�Ɖ~�`�̓����蔻��
	virtual bool CheckCollision(const Transform& transform1, const Transform& transform2, const CircleCollider* collider) const override
	{
		return Collision::Check(transform1, this, transform2, collider);
	}
};