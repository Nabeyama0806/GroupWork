#include "FireGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Time.h"

//コンストラクタ
FireGimmick::FireGimmick(const Vector3& position, const Vector3& size) :
	GimmickBase("Fire", position),
	m_destroyWall(false),
	m_fireTime(FireTime)
{
	//モデルとエフェクト
	m_model = new Model("Resource/bottle_fire.mv1");
	m_effect = new Effect("Data/fire.efk", 10, 70);

	//姿勢情報
	m_transform.position = position;
	m_transform.scale = size;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale);
}

//効果の発動
void FireGimmick::Active()
{
	if (m_destroyWall)
	{
		m_fireTime -= Time::GetInstance()->GetDeltaTime();
		if (m_fireTime <= 0) Destroy();
		m_effect->Play();
	}
}

//衝突イベント
void FireGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "FireBottle")
	{
		m_destroyWall = true;
	}
}