#include "FireGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Time.h"

//�R���X�g���N�^
FireGimmick::FireGimmick(const Vector3& position, const Vector3& size) :
	GimmickBase("Fire", position),
	m_destroyWall(false),
	m_fireTime(FireTime)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/bottle_fire.mv1");
	m_effect = new Effect("Data/fire.efk", 10, 70);

	//�p�����
	m_transform.position = position;
	m_transform.scale = size;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale);
}

//���ʂ̔���
void FireGimmick::Active()
{
	if (m_destroyWall)
	{
		m_fireTime -= Time::GetInstance()->GetDeltaTime();
		if (m_fireTime <= 0) Destroy();
		m_effect->Play();
	}
}

//�Փ˃C�x���g
void FireGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "FireBottle")
	{
		m_destroyWall = true;
	}
}