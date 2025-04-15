#include "WaterGimmickEnd.h"
#include "BoxCollider.h"
#include "Effect.h"

//�R���X�g���N�^
WaterGimmickEnd::WaterGimmickEnd(const Vector3& position, const Vector3& size, const Vector3& offset) :
	ModelActor("WaterGimmickEnd")
{
	//�p�����
	m_transform.position = position;
	m_transform.scale = size;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale, offset.Scale(m_transform.scale));
}