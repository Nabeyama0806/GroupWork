#pragma once
#include "DxLib.h"

class BoxCollider
{
public:
	Vector3 m_size;
	Vector3 m_offset;

	//コンストラクタ
	BoxCollider(const Vector3& size, const Vector3& offset = Vector3()) : 
		m_size(size),
		m_offset(offset){ }


	bool Check(
		const Transform& transform1, const BoxCollider* box1,
		const Transform& transform2, const BoxCollider* box2
	)
	{
		//
		Vector3 center1 = transform1.position + box1->m_offset;
		Vector3 size1 = box1->m_size;

		Vector3 center2 = transform2.position + box2->m_offset;
		Vector3 size2 = box2->m_size;

		//
		if (abs(center1.x - center2.x) <= (size1.x + size2.x) / 2
			&& abs(center1.y - center2.y) <= (size1.y + size2.y) / 2
			&& abs(center1.z - center2.z) <= (size1.z + size2.z) / 2)
		{
			return true;
		}
		return false;
	}

	Vector3 GetSize() const
	{
		return m_size;
	}


#ifdef _DEBUG
	// 描画
	void Draw(const Transform& transform) const
	{
		DrawBoxLine(transform);
	}
#endif

	void DrawBoxLine(const Transform& transform) const
	{
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				if (i == 0 || j == 0) continue;

				// X
				DrawLine3D(
					VGet(transform.position.x - m_size.x / 2 + m_offset.x, transform.position.y + m_size.y / 2 * i + m_offset.y, transform.position.z + m_size.z / 2 * j + m_offset.z),
					VGet(transform.position.x + m_size.x / 2 + m_offset.x, transform.position.y + m_size.y / 2 * i + m_offset.y, transform.position.z + m_size.z / 2 * j + m_offset.z),
					GetColor(255, 255, 255));

				// Y
				DrawLine3D(
					VGet(transform.position.x + m_size.x / 2 * j + m_offset.x, transform.position.y + m_size.y / 2 + m_offset.y, transform.position.z + m_size.z / 2 * i + m_offset.z),
					VGet(transform.position.x + m_size.x / 2 * j + m_offset.x, transform.position.y - m_size.y / 2 + m_offset.y, transform.position.z + m_size.z / 2 * i + m_offset.z),
					GetColor(255, 255, 255));

				// Z
				DrawLine3D(
					VGet(transform.position.x + m_size.x / 2 * i + m_offset.x, transform.position.y + m_size.y / 2 * j + m_offset.y, transform.position.z + m_size.z / 2 + m_offset.z),
					VGet(transform.position.x + m_size.x / 2 * i + m_offset.x, transform.position.y + m_size.y / 2 * j + m_offset.y, transform.position.z - m_size.z / 2 + m_offset.z),
					GetColor(255, 255, 255));
			}
		}
	}
};