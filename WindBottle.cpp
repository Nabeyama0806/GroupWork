#include "WindBottle.h"
#include "WindGimmick.h"
#include "BoxCollider.h"
#include "Model.h"
#include "Player.h"

//�R���X�g���N�^
WindBottle::WindBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("WindBottle", position, forward, player)
{
	//���f��
	m_model = new Model("Resource/bottle_wind.mv1");

	//�v���C���[�̎擾
	m_player = player;

	//�p�����
	m_transform.scale = Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	//�Փ˔���
	m_collider = new BoxCollider(ColliderSize);
}

//�Փ˃C�x���g
void WindBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Wall")
	{
		m_player->AddChild(new WindGimmick(m_transform.position));
	}

	// �������Ă���̂��v���C���[�M�~�b�N�p�����蔻��Ȃ�ʂ�Ȃ�
	if (other->GetName() != "Player" && other->GetName() != "WaterGimmickEnd" && other->GetName() != "Transparent")
	{
		// ���g�̍폜
		ActiveEffect();
	}
}