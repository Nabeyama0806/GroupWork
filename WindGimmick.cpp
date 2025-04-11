#include "WindGimmick.h"
#include "BoxCollider.h"

WindGimmick::WindGimmick(const Vector3& position) :
	GimmickBase("Wind", position)
{
	//�G�t�F�N�g
	m_effect = new Effect("Data/wind.efk", 25);

	//�p�����
	m_transform.position = position + SpawnOffset;
	m_transform.scale = Scale;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale);
}

//���ʂ̔���
void WindGimmick::Active()
{
	//���G�t�F�N�g�̕\��
	m_effect->Play();
}