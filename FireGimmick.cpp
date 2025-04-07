#include "FireGimmick.h"
#include "BoxCollider.h"
#include "Time.h"

FireGimmick::FireGimmick(Vector3 position) :
	ModelActor("Fire"),
	m_destroyWall(false),
	m_fireTime(FireTime)
{
	m_model = new Model("Resource/bottle_fire.mv1");
	m_transform.position = position;
	m_transform.scale = Scale;

	//衝突判定
	Vector3 colliderScale = ColliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale, ColliderOffset.Scale(m_transform.scale));
}

void FireGimmick::Update()
{
	//本来の更新
	ModelActor::Update();

	if (m_destroyWall)
	{
		m_fireTime -= Time::GetInstance()->GetDeltaTime();
		if (m_fireTime <= 0) Destroy();
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