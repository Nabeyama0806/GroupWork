#include "WaterGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"

WaterGimmick::WaterGimmick(const Vector3& position, const Vector3& size, const Vector3& offset) :
	GimmickBase("Water", position),
	isPlay(false),
	waterHeight(false)
{
	m_model = new Model("Resource/bottle_water.mv1");
	m_transform.position = position;
	m_transform.scale = size;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale, offset.Scale(m_transform.scale));

	m_effect = new Effect("Data/water.efk", 40);
}

void WaterGimmick::Update()
{
	//�{���̍X�V
	GimmickBase::Update();

	if (waterHeight)	// ���������Ă���
	{
		if (UpWater > m_transform.position.y)
		{
			if (!isPlay) m_effect->Play(false);
			m_transform.position.y += VariableWater;
			isPlay = waterHeight;
		}
	}
	else
	{
		if (DownWater < m_transform.position.y)
		{
			if (isPlay) m_effect->Play(false);
			m_transform.position.y -= VariableWater;
			isPlay = waterHeight;
		}
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

void WaterGimmick::ActiveEffect()
{

}