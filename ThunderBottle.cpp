#include "ThunderBottle.h"
#include "BoxCollider.h"
#include "Model.h"
#include "Player.h"

//�R���X�g���N�^
ThunderBottle::ThunderBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("ThunderBottle", position, forward, player)
{
	//���f��
	m_model = new Model("Resource/bottle_thunder.mv1");

	//�p�����
	m_transform.scale = Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize.Scale(Scale));
}

//�Փ˃C�x���g
void ThunderBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() != "Player" && other->GetName() != "Bottle")
	{
		ActiveEffect();
	}
}