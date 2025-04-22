#include "ThunderBottle.h"
#include "BoxCollider.h"
#include "HitCollider.h"
#include "Model.h"
#include "Player.h"

//�R���X�g���N�^
ThunderBottle::ThunderBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("ThunderBottle", position, forward, player),
	m_flushCollider(nullptr)
{
	//���f��
	m_model = new Model("Resource/Model/bottle_thunder.mv1");

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
	std::string hit = other->GetName();
	if (hit != "Player" && hit != "Bottle" && hit != "WaterGimmickEnd")
	{
		if (!m_flushCollider)
		{
			m_flushCollider = new HitCollider("Flush", m_transform.position, ColliderSize * FlushSize);
			AddChild(m_flushCollider);
		}
		else
		{
			Bottle::ActiveEffect();
		}
	}
}