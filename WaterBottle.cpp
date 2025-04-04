#include "WaterBottle.h"
#include "Model.h"
#include "BoxCollider.h"
#include "Player.h"

//コンストラクタ
WaterBottle::WaterBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle(position, Bottle::Type::Water),
	m_forward(forward),
	m_player(player)
{
	m_model = new Model("Resource/bottle_water.mv1");
	m_transform.scale *= Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	m_collider = new BoxCollider(ColliderSize);
}

//更新
void WaterBottle::Update()
{
	//本来の更新
	ModelActor::Update();

	m_transform.position += Bottle::Throw(m_forward);
}

//描画
void WaterBottle::Draw()
{
	//本来の描画
	ModelActor::Draw();
}

//効果発動
void WaterBottle::ActiveEffect()
{
	m_player->DestroyBottle();
	//自身を削除
	Destroy();
}

//衝突イベント
void WaterBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() != "Player" && other->GetName() != "Bottle")
	{
		ActiveEffect();
	}
}