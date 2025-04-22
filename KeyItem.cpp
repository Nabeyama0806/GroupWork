#include "KeyItem.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Time.h"

//�R���X�g���N�^
KeyItem::KeyItem(const Vector3& position) :
	GimmickBase("Key", position),
	m_destroyKey(false),
	m_destroyTime(DestroyTime)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/key.mv1");
	//m_effect = new Effect("Resource/Effect/keyget.efk", 10, 70);

	//�p�����
	m_transform.position = position;
	m_transform.scale = Scale;

	//�Փ˔���
	Vector3 colliderScale = ColliderSize;
	m_collider = new BoxCollider(colliderScale);
}

//���ʂ̔���
void KeyItem::Active()
{
	if (m_destroyKey)
	{
		m_destroyTime -= Time::GetInstance()->GetDeltaTime();
		if (m_destroyTime <= 0) Destroy();
		//m_effect->Play();
	}
}

//�Փ˃C�x���g
void KeyItem::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Player")
	{
		m_destroyKey = true;
	}
}