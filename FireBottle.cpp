#include "FireBottle.h"
#include "BoxCollider.h"
#include "Model.h"
#include "Player.h"

//�R���X�g���N�^
FireBottle::FireBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("FireBottle", position, forward, player)
{
	//���f��
	m_model = new Model("Resource/bottle_fire.mv1");

	//�p�����
	m_transform.scale = Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
}

//�Փ˃C�x���g
void FireBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() != "Player" && other->GetName() != "Bottle")
	{
		Bottle::ActiveEffect();
	}
}