#include "FireBottle.h"
#include "BoxCollider.h"
#include "Model.h"
#include "Player.h"

//コンストラクタ
FireBottle::FireBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("FireBottle", position, forward, player)
{
	//モデル
	m_model = new Model("Resource/Model/bottle_fire.mv1");

	//姿勢情報
	m_transform.scale = Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	//衝突判定
	m_collider = new BoxCollider(ColliderSize.Scale(Scale));
}

//衝突イベント
void FireBottle::OnCollision(const ModelActor* other)
{
	std::string hit = other->GetName();
	if (hit != "Player" && hit != "PlayerFoot" && hit != "Bottle" && 
		hit != "WaterGimmickEnd" && hit != "Transparent")
	{
		Destroy();
	}
}