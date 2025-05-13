#include "TransparentGimmick.h"
#include "BoxCollider.h"
#include "SoundManager.h"
#include "Time.h"
#include "Camera.h"
#include "Effect.h"

//�R���X�g���N�^
TransparentGimmick::TransparentGimmick(const Vector3& position, Camera* camera) :
	GimmickBase("Transparent", position),
	m_camera(camera),
	m_appear(false),
	m_appearTime(0)
{
	//���f���ƃG�t�F�N�g
	m_model = new Model("Resource/Model/block.mv1");

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
	//�����Ă��Ȃ��Ƃ��A
	if (!m_camera->GetIsPlayer() || m_appear)
	{
		GimmickBase::Draw();
	}
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