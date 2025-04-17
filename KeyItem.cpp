#include "KeyItem.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "Time.h"

//コンストラクタ
KeyItem::KeyItem(const Vector3& position, const Vector3& size) :
	GimmickBase("Key", position),
	m_destroyKey(false),
	m_destroyTime(DestroyTime)
{
	//モデルとエフェクト
	m_model = new Model("Resource/Model/(KeyBlockはまだない).mv1");
	m_keyModel = new Model("Resource/Model/key.mv1");
	//m_effect = new Effect("Resource/Effect/keyget.efk", 10, 70);

	//姿勢情報
	m_transform.position = position;
	m_transform.scale = size;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * size.x;
	m_collider = new BoxCollider(colliderScale);
}

//効果の発動
void KeyItem::Active()
{
	if (m_destroyKey)
	{
		m_destroyTime -= Time::GetInstance()->GetDeltaTime();
		if (m_destroyTime <= 0) Destroy();
		//m_effect->Play();
	}
}

//衝突イベント
void KeyItem::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Player")
	{
		m_destroyKey = true;
	}
}