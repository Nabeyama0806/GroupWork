#include "ThunderBottle.h"
#include "BoxCollider.h"
#include "HitCollider.h"
#include "Model.h"
#include "Player.h"
#include "Effect.h"
#include "Time.h"

//コンストラクタ
ThunderBottle::ThunderBottle(const Vector3& position, const Vector3& forward, Player* player) :
	Bottle("ThunderBottle", position, forward, player),
	m_flushCollider(nullptr),
	m_time(0)
{
	//モデル
	m_model = new Model("Resource/Model/bottle_thunder.mv1");
	m_effect = new Effect("Resource/Effect/draw.efk", 40, 120);

	//姿勢情報
	m_transform.scale = Scale;
	m_transform.position = position;
	m_transform.rotation = Quaternion::LookRotation(-forward);

	//衝突判定
	m_collider = new BoxCollider(ColliderSize.Scale(Scale));
}

void ThunderBottle::Update()
{
	//本来の更新
	Bottle::Update();
	m_effect->Update(m_transform.position);

	if (m_flushCollider)
	{
		m_time += Time::GetInstance()->GetDeltaTime();
		if (m_time > FlushTime)
		{
			Bottle::DestroyBottle();
			m_time = 0;
		}
	}
}

//衝突イベント
void ThunderBottle::OnCollision(const ModelActor* other)
{
	std::string hit = other->GetName();
	if (hit != "Player" && hit != "Bottle" && hit != "WaterGimmickEnd" && hit != "PlayerFoot")
	{
		if (!m_flushCollider)
		{
			m_effect->Play();
			m_flushCollider = new HitCollider("Flush", m_transform.position, ColliderSize * FlushSize);
			AddChild(m_flushCollider);
		}
	}
}