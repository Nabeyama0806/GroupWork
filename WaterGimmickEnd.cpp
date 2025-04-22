#include "WaterGimmickEnd.h"
#include "BoxCollider.h"
#include "Effect.h"

//コンストラクタ
WaterGimmickEnd::WaterGimmickEnd(const Vector3& position) :
	ModelActor("WaterGimmickEnd")
{
	//姿勢情報
	m_transform.position = position;
	m_transform.scale = Scale;

	//衝突判定
	m_collider = new BoxCollider(ColliderSize);
}