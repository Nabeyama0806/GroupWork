#include "WaterGimmick.h"
#include "BoxCollider.h"
#include "Time.h"
#include "Effect.h"

//コンストラクタ
WaterGimmick::WaterGimmick(const Vector3& position, const Vector3& size, const Vector3& offset) :
	GimmickBase("Water", position),
	m_waterHeight(false),
	m_stopTime(0),
	m_startPos(position)
{
	//モデルとエフェクト
	m_model = new Model("Resource/bottle_water.mv1");
	m_effect = new Effect("Data/water.efk", 40, 120);
	m_effectOffset = Vector3(0, 100, 0);

	//姿勢情報
	m_transform.position = m_startPos;
	m_transform.scale = size;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale, offset.Scale(m_transform.scale));

}

//効果の発動
void WaterGimmick::Active()
{
	if (m_waterHeight)
	{
		m_transform.position.y += VariableWater;
		m_stopTime = 0;
	}

	if (m_transform.position.y > m_startPos.y)
	{
		m_stopTime += Time::GetInstance()->GetDeltaTime();
		if (m_stopTime > StopTime) m_transform.position.y -= VariableWater;
	}
}

//衝突イベント
void WaterGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "WaterBottle")
	{
		m_waterHeight = true;
	}

	if (other->GetName() == "WaterGimmickEnd")
	{
		m_waterHeight = false;
	}
}