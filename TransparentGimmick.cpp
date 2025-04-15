#include "TransparentGimmick.h"
#include "BoxCollider.h"
#include "Time.h"
#include "Effect.h"

//コンストラクタ
TransparentGimmick::TransparentGimmick(const Vector3& position, const Vector3& size, const Vector3& offset) :
	GimmickBase("Transparent", position),
	m_appear(false),
	m_appearTime(0)
{
	//モデルとエフェクト
	m_model = new Model("Resource/bottle_water.mv1");
	/*
	m_effect = new Effect("Data/water.efk", 40, 120);
	m_effectOffset = Vector3(0, 100, 0);
	*/

	//姿勢情報
	m_transform.position = position;
	m_transform.scale = size;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale, offset.Scale(m_transform.scale));

}

//効果の発動
void TransparentGimmick::Active()
{
	if (m_appear)
	{
		m_appearTime += Time::GetInstance()->GetDeltaTime();
		if (m_appearTime > AppearTime)
		{

			m_appear = false;
			m_appearTime = 0;
		}
	}
}

//衝突イベント
void TransparentGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Thunder")
	{
		m_appear = true;
		m_appearTime = 0;
	}
}