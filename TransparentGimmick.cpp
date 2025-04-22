#include "TransparentGimmick.h"
#include "BoxCollider.h"
#include "Time.h"
#include "Effect.h"

//�R���X�g���N�^
TransparentGimmick::TransparentGimmick(const Vector3& position) :
	GimmickBase("Transparent", position),
	m_appear(false),
	m_appearTime(0)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/Transparent.mv1");

	m_effect = new Effect("Resource/Effect/draw.efk", 15, 120);

	//�p�����
	m_transform.position = position;
	m_transform.scale = Scale;

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
}

//���ʂ̔���
void TransparentGimmick::Active()
{
	//���点��t���O�������Ă��鎞
	if (m_appear)
	{
		m_effect->Play(false);

		//�w�肵�����ԕ����点��
		m_appearTime += Time::GetInstance()->GetDeltaTime();
		if (m_appearTime > AppearTime)
		{
			//���Ԍo�߂Ńt���O��܂�
			m_appear = false;
			m_appearTime = 0;
		}
	}
}

//�`��
void TransparentGimmick::Draw()
{
	//���点��t���O�������Ă��Ȃ���Ε`�悵�Ȃ�
	if (!m_appear) return;

	//�{���̕`��
	GimmickBase::Draw();
}

//�Փ˃C�x���g
void TransparentGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Flush")
	{
		//���点��t���O�𗧂Ă�
		m_appear = true;
		m_appearTime = 0;
	}
}