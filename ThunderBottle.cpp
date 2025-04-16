#include "ThunderBottle.h"
#include "BoxCollider.h"
#include "Model.h"
#include "Player.h"

//コンストラクタ
ThunderBottle::ThunderBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("ThunderBottle", position, forward, player)
{
	//モデル
	m_model = new Model("Resource/bottle_thunder.mv1");

	//姿勢情報
	m_transform.scale = Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	//衝突判定
	m_collider = new BoxCollider(ColliderSize.Scale(Scale));
}

//衝突イベント
void ThunderBottle::OnCollision(const ModelActor* other)
{
	if (other->GetName() != "Player" && other->GetName() != "Bottle")
	{
		ActiveEffect();
	}
}