#include "FireGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Time.h"

//コンストラクタ
FireGimmick::FireGimmick(const Vector3& position) :
	GimmickBase("Fire", position),
	m_destroyWall(false),
	m_fireTime(FireTime)
{
	m_model = new Model("Resource/bottle_fire.mv1");
	m_transform.position = position;
	m_transform.scale = Scale;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale, m_transform.scale);

	m_effect = new Effect("Data/fire.efk", 10, 70);
}

void FireGimmick::Update()
{
	//本来の更新
	GimmickBase::Update();

	if (m_destroyWall)
	{
		m_fireTime -= Time::GetInstance()->GetDeltaTime();
		if (m_fireTime <= 0) Destroy();
		m_effect->Play();
	}
}

void FireGimmick::Draw()
{
	//本来の更新
	ModelActor::Draw();
}

//衝突イベント
void FireGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "FireBottle")
	{
		m_destroyWall = true;
	}
}

void FireGimmick::ActiveEffect()
{

}