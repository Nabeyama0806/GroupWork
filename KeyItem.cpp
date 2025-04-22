#include "KeyItem.h"
#include "BoxCollider.h"
#include "SoundManager.h"
#include "Effect.h"

//�R���X�g���N�^
KeyItem::KeyItem(const Vector3& position) :
	GimmickBase("Key", position),
	m_destroyKey(false),
	m_destroyTime(DestroyTime)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/key.mv1");
	m_effect = new Effect("Resource/Effect/key.efk", 35, 700);
	m_effectOffset = Vector3(0, -100, 0);
	
	//�p�����
	m_transform.position = position;
	m_transform.scale = Scale;

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
}

//���ʂ̔���
void KeyItem::Active()
{
	//�G�t�F�N�g�̍Đ�
	m_effect->Play();

	if (m_destroyKey)
	{
		//���ʉ�
		SoundManager::Play("Resource/sound/se_keyget.mp3");

		//���g�̍폜
		Destroy();
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