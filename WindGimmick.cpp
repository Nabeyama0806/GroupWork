#include "WindGimmick.h"
#include "BoxCollider.h"
#include "Time.h"

//�R���X�g���N�^
WindGimmick::WindGimmick(const Vector3& position) :
	GimmickBase("Wind", position),
	m_elapsedTime(0)
{
	//�G�t�F�N�g
	m_effect = new Effect("Data/wind.efk", 25, 130);

	//�p�����
	m_transform.position = position + SpawnOffset;
	m_transform.scale = Scale;

	//�Փ˔���
	Vector3 colliderScale = m_colliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale);
}

//�X�V
void WindGimmick::Update()
{
	//�{���̍X�V
	GimmickBase::Update();

	//���Ԍo�߂ō폜
	m_elapsedTime += Time::GetInstance()->GetDeltaTime();
	if (EffectDrawTime < m_elapsedTime)
	{
		Destroy();
	}
}

//���ʂ̔���
void WindGimmick::Active()
{
	//���G�t�F�N�g�̕\��
	m_effect->Play();
}