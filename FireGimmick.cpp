#include "FireGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Time.h"

//�R���X�g���N�^
FireGimmick::FireGimmick(const Vector3& position) :
	GimmickBase("Fire", position),
	m_destroyWall(false),
	m_fireTime(FireTime)
{
	m_model = new Model("Resource/bottle_fire.mv1");
	m_transform.position = position;
	m_transform.scale = Scale;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale, m_transform.scale);

	m_effect = new Effect("Data/fire.efk", 10, 70);
}

void FireGimmick::Update()
{
	//�{���̍X�V
	GimmickBase::Update();

	if (m_destroyWall)
	{
		m_fireTime -= Time::GetInstance()->GetDeltaTime();
		if (m_fireTime <= 0) Destroy();
		m_effect->Play();
	}
}

void FireGimmick::Draw()
{
	//�{���̍X�V
	ModelActor::Draw();
}

//�Փ˃C�x���g
void FireGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "FireBottle")
	{
		m_destroyWall = true;
	}
}

void FireGimmick::ActiveEffect()
{

}