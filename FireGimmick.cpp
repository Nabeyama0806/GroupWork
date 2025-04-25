#include "FireGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "SoundManager.h"
#include "Time.h"

//�R���X�g���N�^
FireGimmick::FireGimmick(const Vector3& position) :
	GimmickBase("Fire", position),
	m_destroyWall(false),
	m_fireTime(FireTime)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/Ice.mv1");
	m_effect = new Effect("Resource/Effect/fire.efk", 10, 70);

	//�p�����
	m_transform.position = position;

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
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

void FireGimmick::OnDestroy()
{
	m_effect->Stop();
}

//�Փ˃C�x���g
void FireGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "FireBottle")
	{
		m_destroyWall = true;

		//���ʉ�
		SoundManager::Play("Resource/sound/se_gimmick_fire.mp3");
	}
}