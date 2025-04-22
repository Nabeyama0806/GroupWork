#include "TransparentGimmick.h"
#include "BoxCollider.h"
#include "Time.h"
#include "Effect.h"

//コンストラクタ
TransparentGimmick::TransparentGimmick(const Vector3& position) :
	GimmickBase("Transparent", position),
	m_appear(false),
	m_appearTime(0)
{
	//モデルとエフェクト
	m_model = new Model("Resource/Model/Transparent.mv1");

	m_effect = new Effect("Resource/Effect/draw.efk", 15, 120);

	//姿勢情報
	m_transform.position = position;
	m_transform.scale = Scale;

	//衝突判定
	m_collider = new BoxCollider(ColliderSize);
}

//効果の発動
void TransparentGimmick::Active()
{
	//光らせるフラグが立っている時
	if (m_appear)
	{
		m_effect->Play(false);

		//指定した時間分光らせる
		m_appearTime += Time::GetInstance()->GetDeltaTime();
		if (m_appearTime > AppearTime)
		{
			//時間経過でフラグを折る
			m_appear = false;
			m_appearTime = 0;
		}
	}
}

//描画
void TransparentGimmick::Draw()
{
	//光らせるフラグが立っていなければ描画しない
	if (!m_appear) return;

	//本来の描画
	GimmickBase::Draw();
}

//衝突イベント
void TransparentGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Flush")
	{
		//光らせるフラグを立てる
		m_appear = true;
		m_appearTime = 0;
	}
}