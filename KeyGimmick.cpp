#include "KeyGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Time.h"

//コンストラクタ
KeyGimmick::KeyGimmick(const Vector3& position, const Vector3& size) :
	GimmickBase("KeyBlock", position),
	m_destroyWall(false),
	m_fireTime(FireTime)
{
	//モデルとエフェクト
	m_model = new Model("Resource/Model/(KeyBlockはまだない).mv1");
	//m_effect = new Effect("Resource/Effect/fire.efk", 10, 70);

	//姿勢情報
	m_transform.position = position;
	m_transform.scale = size;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale);
}

//効果の発動
void KeyGimmick::Active()
{
	if (m_destroyWall)
	{
		m_fireTime -= Time::GetInstance()->GetDeltaTime();
		if (m_fireTime <= 0) Destroy();
		m_effect->Play();
	}
}

//衝突イベント
void KeyGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "KeyBottle")
	{
		m_destroyWall = true;
	}
}