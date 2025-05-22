#include "PlayerFoot.h"
#include "Player.h"
#include "TransparentGimmick.h"

//コンストラクタ
PlayerFoot::PlayerFoot(Player* player, Vector3& position) :
	ModelActor("PlayerFoot", nullptr, position),
	m_player(player),
	m_isGrounded(false),
	m_holdMove(Vector3())
{
	//プレイヤーの足元の当たり判定
	m_collider = new BoxCollider(ColliderSize);
}

//更新
void PlayerFoot:: Update()
{
	//本来の更新
	ModelActor::Update();

	//プレイヤーの足元座標に移動
	FollowPlayer();

	m_isGrounded = false;
}

//衝突イベント
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
