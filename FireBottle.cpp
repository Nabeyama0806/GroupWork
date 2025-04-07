#include "FireBottle.h"
#include "Model.h"
#include "BoxCollider.h"
#include "Player.h"

//コンストラクタ
FireBottle::FireBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("FireBottle", position),
	m_forward(forward),
	m_player(player)
{
	m_model = new Model("Resource/bottle_fire.mv1");
	m_transform.scale *= Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	m_collider = new BoxCollider(ColliderSize);
}

//更新
void FireBottle::Update()
{
	//本来の更新
	ModelActor::Update();

	m_transform.position += Bottle::Throw(m_forward);
}

//描画
void FireBottle::Draw()
{
	//本来の描画
	ModelActor::Draw();
}

//効果発動
void FireBottle::ActiveEffect()
{
	m_player->DestroyBottle();
	//自身を削除
	Destroy();
}

//衝突イベント
void FireBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() != "Player" && other->GetName() != "Bottle")
	{
		ActiveEffect();
	}
}