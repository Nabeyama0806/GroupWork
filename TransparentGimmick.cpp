#include "TransparentGimmick.h"
#include "BoxCollider.h"
#include "SoundManager.h"
#include "Time.h"
#include "Effect.h"

//�R���X�g���N�^
TransparentGimmick::TransparentGimmick(const Vector3& position) :
	GimmickBase("Transparent", position),
	m_appear(false),
	m_appearTime(0)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/Brock.mv1");

	//�p�����
	m_transform.position = position;

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
}

//���ʂ̔���
void TransparentGimmick::Active()
{
	//���点��t���O�������Ă��鎞
	if (m_appear)
	{
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
	//�����Ă��Ȃ��Ƃ��͘g����\��
	m_appear ? GimmickBase::Draw() : DrawFrameLine();
}

//�g���̕\��
void TransparentGimmick::DrawFrameLine()
{
	if(m_collider) m_collider->DrawBoxLine(m_transform);
}

//�Փ˃C�x���g
void TransparentGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Flush")
	{
		//���点��t���O�𗧂Ă�
		m_appear = true;
		m_appearTime = 0;

		//���ʉ�
		SoundManager::Play("Resource/sound/se_gimmick_flush.mp3");
	}
}