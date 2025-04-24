#include "WaterBottle.h"
#include "BoxCollider.h"
#include "Model.h"
#include "Player.h"

//�R���X�g���N�^
WaterBottle::WaterBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("WaterBottle", position, forward, player)
{
	//���f��
	m_model = new Model("Resource/Model/bottle_water.mv1");

	//�p�����
	m_transform.scale = Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize.Scale(Scale));
}

//�Փ˃C�x���g
void WaterBottle::OnCollision(const ModelActor* other)
{
	std::string hit = other->GetName();
	if (hit != "Player" && hit != "Bottle" && hit != "WaterGimmickEnd" 
		&& hit != "Transparent" && hit != "PlayerFoot")
	{
		ActiveEffect();
	}
}