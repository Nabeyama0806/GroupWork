#pragma once
#include "Vector3.h"
#include "Transform.h"

class BoxCollider;
class CircleCollider;

class Collider
{
public:

	//���W�̒���
	Vector3 m_offset;

	//�R���X�g���N�^
	Collider(const Vector3& offset) :
		m_offset(offset) { }

	//�_�u���f�B�X�p�b�`�ɂ��`�󎯕ʂŏՓ˔�����s��
	virtual bool CheckCollision(const Transform& transfrom1, const Transform& transform2, const Collider* collider) const = 0;
	virtual bool CheckCollision(const Transform& transfrom1, const Transform& transform2, const BoxCollider* collider) const = 0;
	virtual bool CheckCollision(const Transform& transfrom1, const Transform& transform2, const CircleCollider* collider) const = 0;
};