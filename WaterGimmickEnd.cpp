#include "WaterGimmickEnd.h"
#include "BoxCollider.h"
#include "Effect.h"

//�R���X�g���N�^
WaterGimmickEnd::WaterGimmickEnd(const Vector3& position) :
	ModelActor("WaterGimmickEnd")
{
	//�p�����
	m_transform.position = position;
	m_transform.scale = Scale;

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
}