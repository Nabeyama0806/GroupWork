#include "WaterGimmick.h"
#include "BoxCollider.h"

WaterGimmick::WaterGimmick(const Vector3& spawnPos, const Vector3& size, const Vector3& offset) :
	ModelActor("Water"),
	waterHeight(false)
{
	m_model = new Model("Resource/bottle_water.mv1");
	m_transform.position = spawnPos;
	m_transform.scale = size;

	//�Փ˔���
	Vector3 colliderScale = ColliderSize * size.x;
	m_collider = new BoxCollider(colliderScale, offset.Scale(m_transform.scale));
}

void WaterGimmick::Update()
{
	//�{���̍X�V
	ModelActor::Update();

	if (waterHeight)	// ���������Ă���
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
	//�{���̍X�V
	ModelActor::Draw();
}

void WaterGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "WaterBottle")
	{
		waterHeight = !waterHeight;
	}
}