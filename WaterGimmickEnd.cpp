#include "WaterGimmickEnd.h"
#include "BoxCollider.h"
#include "Effect.h"

//コンストラクタ
WaterGimmickEnd::WaterGimmickEnd(const Vector3& position, const Vector3& size, const Vector3& offset) :
	ModelActor("WaterGimmickEnd")
{
	//姿勢情報
	m_transform.position = position;
	m_transform.scale = size;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale, offset.Scale(m_transform.scale));
}