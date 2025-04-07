#include "WaterGimmick.h"
#include "BoxCollider.h"

WaterGimmick::WaterGimmick(const Vector3& spawnPos, const Vector3& size, const Vector3& offset) :
	ModelActor("Water"),
	waterHeight(false)
{
	m_model = new Model("Resource/bottle_water.mv1");
	m_transform.position = spawnPos;
	m_transform.scale = size;

	//衝突判定
	Vector3 colliderScale = ColliderSize * size.x;
	m_collider = new BoxCollider(colliderScale, offset.Scale(m_transform.scale));
}

void WaterGimmick::Update()
{
	//本来の更新
	ModelActor::Update();

	if (waterHeight)	// 水が増している
	{
		if (UpWater > m_transform.position.y) m_transform.position.y += VariableWater;
	}
	else
	{
		if (DownWater < m_transform.position.y) m_transform.position.y -= VariableWater;
	}
}

void WaterGimmick::Draw()
{
	//本来の更新
	ModelActor::Draw();
}

void WaterGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "WaterBottle")
	{
		waterHeight = !waterHeight;
	}
}