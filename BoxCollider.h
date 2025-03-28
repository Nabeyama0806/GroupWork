#pragma once
#include "Collider.h"
#include "Collision.h"
#include "DxLib.h"

class BoxCollider : public Collider
{
public:
	Vector3 m_size;

	//�R���X�g���N�^
	BoxCollider(const Vector3& size, const Vector3& offset = Vector3()) : 
		Collider(offset),
		m_size(size) { }

	//�Փ˔���
	virtual bool CheckCollision(const Transform& transform1, const Transform& transform2, const Collider* collider) const override
	{
		//�_�u���f�B�X�p�b�`�ɂ��`�󎯕�
		return collider->CheckCollision(transform1, transform2, this);
	}
	
	//��`�Ƌ�`�̓����蔻��
	virtual bool CheckCollision(const Transform& transform1, const Transform& transform2, const BoxCollider* collider) const override
	{
		return Collision::Check(transform1, this, transform2, collider);
	}

	//��`�Ɖ~�`�̓����蔻��
	virtual bool CheckCollision(const Transform& transform1, const Transform& transform2, const CircleCollider* collider) const override
	{
		return Collision::Check(transform1, this, transform2, collider);
	}


#ifdef _DEBUG
	// �`��
	virtual void Draw(const Transform& transform) const override
	{
		// ��̎l�p
		DrawLine3D(
			VGet(transform.position.x - m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z - m_size.z / 2),
			VGet(transform.position.x + m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z - m_size.z / 2),
			GetColor(255, 255, 255));

		DrawLine3D(
			VGet(transform.position.x + m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z - m_size.z / 2),
			VGet(transform.position.x + m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z + m_size.z / 2),
			GetColor(255, 255, 255));

		DrawLine3D(
			VGet(transform.position.x + m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z + m_size.z / 2),
			VGet(transform.position.x - m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z + m_size.z / 2),
			GetColor(255, 255, 255));

		DrawLine3D(
			VGet(transform.position.x - m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z + m_size.z / 2),
			VGet(transform.position.x - m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z - m_size.z / 2),
			GetColor(255, 255, 255));

		// �c�̖_
		DrawLine3D(
			VGet(transform.position.x - m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z - m_size.z / 2),
			VGet(transform.position.x - m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z - m_size.z / 2),
			GetColor(255, 255, 255));

		DrawLine3D(
			VGet(transform.position.x + m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z - m_size.z / 2),
			VGet(transform.position.x + m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z - m_size.z / 2),
			GetColor(255, 255, 255));

		DrawLine3D(
			VGet(transform.position.x - m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z + m_size.z / 2),
			VGet(transform.position.x - m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z + m_size.z / 2),
			GetColor(255, 255, 255));

		DrawLine3D(
			VGet(transform.position.x + m_size.x / 2, transform.position.y + m_size.y / 2, transform.position.z + m_size.z / 2),
			VGet(transform.position.x + m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z + m_size.z / 2),
			GetColor(255, 255, 255));

		// ���̎l�p
		DrawLine3D(
			VGet(transform.position.x - m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z - m_size.z / 2),
			VGet(transform.position.x + m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z - m_size.z / 2),
			GetColor(255, 255, 255));

		DrawLine3D(
			VGet(transform.position.x + m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z - m_size.z / 2),
			VGet(transform.position.x + m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z + m_size.z / 2),
			GetColor(255, 255, 255));

		DrawLine3D(
			VGet(transform.position.x + m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z + m_size.z / 2),
			VGet(transform.position.x - m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z + m_size.z / 2),
			GetColor(255, 255, 255));

		DrawLine3D(
			VGet(transform.position.x - m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z + m_size.z / 2),
			VGet(transform.position.x - m_size.x / 2, transform.position.y - m_size.y / 2, transform.position.z - m_size.z / 2),
			GetColor(255, 255, 255));

	}
#endif
};