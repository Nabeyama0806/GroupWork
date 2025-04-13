#include "GimmickBase.h"
#include "Effect.h"

//�R���X�g���N�^
GimmickBase::GimmickBase(const char* name, const Vector3& position) :
	ModelActor(name),
	m_scale(Vector3(50, 50, 50)),
	m_effectOffset(Vector3(0, -20, 0)),
	m_effect(nullptr)
{
	m_transform.position = position;
}

//�X�V
void GimmickBase::Update()
{
	//�{���̕`��
	ModelActor::Update();

	//���ʂ̔���
	Active();

	//�G�t�F�N�g�̍X�V
	if (m_effect)
	{
		Vector3 pos = m_transform.position + m_effectOffset;
		m_effect->Update(pos);
	}
}