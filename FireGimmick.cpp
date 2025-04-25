#include "FireGimmick.h"
#include "BoxCollider.h"
#include "Effect.h"
#include "SoundManager.h"
#include "Time.h"

//コンストラクタ
FireGimmick::FireGimmick(const Vector3& position) :
	GimmickBase("Fire", position),
	m_destroyWall(false),
	m_fireTime(FireTime)
{
	//モデルとエフェクト
	m_model = new Model("Resource/Model/Ice.mv1");
	m_effect = new Effect("Resource/Effect/fire.efk", 10, 70);

	//姿勢情報
	m_transform.position = position;

	//衝突判定
	m_collider = new BoxCollider(ColliderSize);
}

//効果の発動
void FireGimmick::Active()
{
	if (m_destroyWall)
	{
		m_fireTime -= Time::GetInstance()->GetDeltaTime();
		if (m_fireTime <= 0) Destroy();
		m_effect->Play();
	}
}

void FireGimmick::OnDestroy()
{
	m_effect->Stop();
}

//衝突イベント
void FireGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "FireBottle")
	{
		m_destroyWall = true;

		//効果音
		SoundManager::Play("Resource/sound/se_gimmick_fire.mp3");
	}
}