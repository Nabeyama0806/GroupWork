#include "WindBottle.h"
#include "WindGimmick.h"
#include "BoxCollider.h"
#include "Model.h"
#include "Player.h"

//コンストラクタ
WindBottle::WindBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("WindBottle", position, forward, player)
{
	//モデル
	m_model = new Model("Resource/Model/bottle_wind.mv1");

	//プレイヤーの取得
	m_player = player;

	//姿勢情報
	m_transform.scale = Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	//衝突判定
	m_collider = new BoxCollider(ColliderSize.Scale(Scale));
}

void WindBottle::ActiveEffect()
{
	Bottle::ActiveEffect();
	m_player->SetCanWindBottleThrow(true);
}

//衝突イベント
void WindBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Wall")
	{
		m_player->AddChild(new WindGimmick(m_transform.position, m_player));
	}

	// 当たっているのがプレイヤーギミック用当たり判定なら通らない
	if (other->GetName() != "Player" && other->GetName() != "WaterGimmickEnd" && other->GetName() != "Transparent")
	{
		// 自身の削除
		Bottle::ActiveEffect();
		if (other->GetName() != "Wall") m_player->SetCanWindBottleThrow(true);
	}
}