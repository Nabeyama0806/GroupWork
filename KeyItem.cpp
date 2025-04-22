#include "KeyItem.h"
#include "BoxCollider.h"
#include "SoundManager.h"
#include "Effect.h"

//コンストラクタ
KeyItem::KeyItem(const Vector3& position) :
	GimmickBase("Key", position),
	m_destroyKey(false),
	m_destroyTime(DestroyTime)
{
	//モデルとエフェクト
	m_model = new Model("Resource/Model/key.mv1");
	m_effect = new Effect("Resource/Effect/key.efk", 35, 700);
	m_effectOffset = Vector3(0, -100, 0);
	
	//姿勢情報
	m_transform.position = position;
	m_transform.scale = Scale;

	//衝突判定
	m_collider = new BoxCollider(ColliderSize);
}

//効果の発動
void KeyItem::Active()
{
	//エフェクトの再生
	m_effect->Play();

	if (m_destroyKey)
	{
		//効果音
		SoundManager::Play("Resource/sound/se_keyget.mp3");

		//自身の削除
		Destroy();
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