#include "PlayerFoot.h"
#include "Player.h"
#include "TransparentGimmick.h"

//�R���X�g���N�^
PlayerFoot::PlayerFoot(Player* player, Vector3& position) :
	ModelActor("PlayerFoot", nullptr, position),
	m_player(player),
	m_isGrounded(false),
	m_holdMove(Vector3())
{
	//�v���C���[�̑����̓����蔻��
	m_collider = new BoxCollider(ColliderSize);
}

//�X�V
void PlayerFoot:: Update()
{
	//�{���̍X�V
	ModelActor::Update();

	//�v���C���[�̑������W�Ɉړ�
	FollowPlayer();

	m_isGrounded = false;
}

//�Փ˃C�x���g
 void PlayerFoot::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Wall" || other->GetName() == "Fire"  || other->GetName() == "KeyBlock"
	||	other->GetName() == "Wind" || other->GetName() == "Water" || other->GetName() == "Transparent")
	{
		m_isGrounded = true;
		
		m_transform.position.y = other->GetPosition().y + other->GetCollider()->GetSize().y / 2 + ColliderSize.y / 2;

		Vector3 playerPos = m_player->GetPosition();
		playerPos.y = m_transform.position.y - ColliderOffset.y;
		m_player->SetPosition(playerPos);
	}
}

void PlayerFoot::FollowPlayer()
{
	m_transform.position = m_player->GetPosition() + ColliderOffset;
}
