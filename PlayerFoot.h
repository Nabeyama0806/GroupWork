#pragma once
#include "ModelActor.h"
#include "Player.h"
#include "Vector3.h"
#include "BoxCollider.h"

class PlayerFoot : public ModelActor
{
private:
	static constexpr Vector3 ColliderSize = Vector3(25, 5, 25);
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);

	Player* m_player;
protected:
	virtual void Update() override
	{
		m_transform.position = m_player->GetPosition();
	}

public:
	//コンストラクタ
	PlayerFoot(Player* player, Vector3& position) :
		ModelActor("PlayerFoot", nullptr, position),
		m_player(player)
	{
		//プレイヤーの足元の当たり判定
		m_collider = new BoxCollider(ColliderSize, ColliderOffset);
	}

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override
	{
		//床との接地判定
	}
};