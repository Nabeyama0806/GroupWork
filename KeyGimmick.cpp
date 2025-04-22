#include "KeyGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Player.h"
#include "Time.h"

//コンストラクタ
KeyGimmick::KeyGimmick(const Vector3& position, Player* player) :
	GimmickBase("KeyBlock", position),
	m_player(player),
	m_destroyWall(false),
	m_destroyTime(DestroyTime)
{
	//モデルとエフェクト
	m_model = new Model("Resource/Model/key_block.mv1");
	m_effect = new Effect("Resource/Effect/open.efk", 10, 70);

	//姿勢情報
	m_transform.position = position;
	m_transform.scale = Scale * 1.25;

	//衝突判定
	m_collider = new BoxCollider(ColliderSize);
}

//効果の発動
void KeyGimmick::Active()
{
	if (m_destroyWall)
	{
		m_destroyTime -= Time::GetInstance()->GetDeltaTime();
		m_effect->Play();
		if (m_destroyTime <= 0) Destroy();
	}
}

//衝突イベント
void KeyGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Player")
	{
		if (m_player->IsGetKey()) m_destroyWall = true;
	}
}