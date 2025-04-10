#include "GimmickBase.h"
#include "Effect.h"

//�R���X�g���N�^
GimmickBase::GimmickBase(const char* name, const Vector3& position) :
	ModelActor(name),
	m_scale(Vector3(50, 50, 50)),
	m_effect(nullptr)
{
	m_transform.position = position;
}

//�X�V
void GimmickBase::Update()
{
	//�{���̕`��
	ModelActor::Update();

	//�G�t�F�N�g�̍X�V
	if (m_effect)
	{
		m_effect->Update(m_transform.position);
	}
}

//�Փ˃C�x���g
void GimmickBase::OnCollision(const ModelActor* other)
{
	//���ʔ���
	ActiveEffect();
}