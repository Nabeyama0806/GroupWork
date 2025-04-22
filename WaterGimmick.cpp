#include "WaterGimmick.h"
#include "BoxCollider.h"
#include "SoundManager.h"
#include "Time.h"
#include "Effect.h"

//�R���X�g���N�^
WaterGimmick::WaterGimmick(const Vector3& position) :
	GimmickBase("Water", position),
	m_waterHeight(false),
	m_stopTime(0),
	m_canUp(true),
	m_startPos(position)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/water_block.mv1");
	m_effect = new Effect("Resource/Effect/water.efk", 15, 120);
	m_effectOffset = Vector3(0, 50, 0);

	//�p�����
	m_transform.position = m_startPos;
	m_transform.scale = Scale;

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
}

//���ʂ̔���
void WaterGimmick::Active()
{
	if (m_transform.position.y > m_startPos.y)
	{
		m_stopTime += Time::GetInstance()->GetDeltaTime();

		m_canUp = m_stopTime > StopTime;
		if (m_canUp) m_transform.position.y -= VariableWater;
	}
	
	if (m_waterHeight)
	{
		m_transform.position.y += VariableWater;
		m_stopTime = 0;
	}
}

//�Փ˃C�x���g
void WaterGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "WaterBottle" && !m_waterHeight)
	{
		if (!m_canUp) return;
		m_waterHeight = true;
		m_effect->Play(false);

		SoundManager::Play("Resource/sound/se_gimmick_water.mp3");
	}

	if (other->GetName() == "WaterGimmickEnd")
	{
		m_waterHeight = false;
	}
}