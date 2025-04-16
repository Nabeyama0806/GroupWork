#include "KeyGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Time.h"

//�R���X�g���N�^
KeyGimmick::KeyGimmick(const Vector3& position, const Vector3& size) :
	GimmickBase("KeyBlock", position),
	m_destroyWall(false),
	m_fireTime(FireTime)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/(KeyBlock�͂܂��Ȃ�).mv1");
	//m_effect = new Effect("Resource/Effect/fire.efk", 10, 70);

	//�p�����
	m_transform.position = position;
	m_transform.scale = size;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale);
}

//���ʂ̔���
void KeyGimmick::Active()
{
	if (m_destroyWall)
	{
		m_fireTime -= Time::GetInstance()->GetDeltaTime();
		if (m_fireTime <= 0) Destroy();
		m_effect->Play();
	}
}

//�Փ˃C�x���g
void KeyGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "KeyBottle")
	{
		m_destroyWall = true;
	}
}