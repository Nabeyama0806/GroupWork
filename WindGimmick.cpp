#include "WindGimmick.h"
#include "BoxCollider.h"

WindGimmick::WindGimmick(const Vector3& position) :
	GimmickBase("Wind", position)
{
	m_effect = new Effect("Data/wind.efk", 25);

	m_transform.position = position + SpawnOffset;
	m_transform.scale = Scale;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale, m_transform.scale);
}

//�X�V
void WindGimmick::Update()
{
	//�{���̍X�V
	GimmickBase::Update();
	m_effect->Play(true);
}

//�`��
void WindGimmick::Draw()
{
	//�{���̍X�V
	ModelActor::Draw();
}

//���ʂ̔���
void WindGimmick::ActiveEffect()
{
	//���G�t�F�N�g�̕\��
	m_effect->Play();
}