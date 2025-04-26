#include "WindBottle.h"
#include "WindGimmick.h"
#include "BoxCollider.h"
#include "Model.h"
#include "Player.h"

//コンストラクタ
WindBottle::WindBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("WindBottle", position, forward, player),
	m_forward(forward),
	m_holdMove(0,0,0)
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

void WindBottle::Update()
{
	//本来の更新
	ModelActor::Update();

	//投げる
	m_holdMove = Throw(m_forward);
	m_transform.position += m_holdMove;

	if (m_transform.position.y < -300)
	{
		DestroyBottle();
	}
}

void WindBottle::DestroyBottle()
{
	Bottle::DestroyBottle();
	m_player->SetCanWindBottleThrow();
}

//衝突イベント
void WindBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Wall")
	{
		m_player->AddChild(new WindGimmick(m_transform.position - m_holdMove, m_player));
	}

	std::string hit = other->GetName();
	if (hit != "Player" && hit != "Bottle" && hit != "WaterGimmickEnd" &&
		hit != "Transparent" && hit != "PlayerFoot")
	{
		// 自身の削除
		Bottle::DestroyBottle();
		if (other->GetName() != "Wall") m_player->SetCanWindBottleThrow();
	}
}