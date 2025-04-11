#include "WaterGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"

WaterGimmick::WaterGimmick(const Vector3& position, const Vector3& size, const Vector3& offset) :
	GimmickBase("Water", position),
	m_isPlay(false),
	m_isWaterHeight(false)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/bottle_water.mv1");
	m_effect = new Effect("Data/water.efk", 40);
	m_effectOffset = Vector3(0, 100, 0);

	//�p�����
	m_transform.position = position;
	m_transform.scale = size;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale, offset.Scale(m_transform.scale));

}

//���ʂ̔���
void WaterGimmick::Active()
{
	// ���������Ă���
	if (m_isWaterHeight)
	{
		if (UpWaterHeight > m_transform.position.y)
		{
			if (!m_isPlay) m_effect->Play(false);
			m_transform.position.y += VariableWater;
			m_isPlay = m_isWaterHeight;
		}
	}
	else
	{
		if (DownWaterHeight < m_transform.position.y)
		{
			if (m_isPlay) m_effect->Play(false);
			m_transform.position.y -= VariableWater;
			m_isPlay = m_isWaterHeight;
		}
	}
}

//�Փ˃C�x���g
void WaterGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "WaterBottle")
	{
		m_isWaterHeight = !m_isWaterHeight;
	}
}