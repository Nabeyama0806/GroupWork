#pragma once
#include "Collider.h"
#include "Collision.h"
#include "DxLib.h"

class CircleCollider : public Collider
{
public:
	float m_radius;

	//コンストラクタ
	CircleCollider(float radius, const Vector3& offset = Vector3()) :
		Collider(offset),
		m_radius(radius) {
	}

	//衝突判定
	virtual bool CheckCollision(const Transform& transform1, const Transform& transform2, const Collider* collider) const override
	{
		//ダブルディスパッチによる形状識別
		return collider->CheckCollision(transform1, transform2, this);
	}

	//矩形と円形の当たり判定
	virtual bool CheckCollision(const Transform& transform1, const Transform& transform2, const BoxCollider* collider) const override
	{
		return Collision::Check(transform1, collider, transform2, this);
	}

	//円形と円形の当たり判定
	virtual bool CheckCollision(const Transform& transform1, const Transform& transform2, const CircleCollider* collider) const override
	{
		return Collision::Check(transform1, collider, transform2, this);
	}

	virtual Vector3 GetSize(const Collider* collider) const override
	{
		return Vector3(m_radius, m_radius, m_radius);
	}

#ifdef _DEBUG
	// 描画
	virtual void Draw(const Transform& transform) const override
	{
		DrawSphere3D(transform.position + m_offset, m_radius, 10, GetColor(255, 255, 0), GetColor(255, 255, 0), false);
	}
#endif

};