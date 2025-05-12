#include "TransparentGimmick.h"
#include "BoxCollider.h"
#include "SoundManager.h"
#include "Time.h"
#include "Effect.h"

//コンストラクタ
TransparentGimmick::TransparentGimmick(const Vector3& position) :
	GimmickBase("Transparent", position),
	m_appear(false),
	m_appearTime(0)
{
	//モデルとエフェクト
	m_model = new Model("Resource/Model/Brock.mv1");

	//姿勢情報
	m_transform.position = position;

	//衝突判定
	m_collider = new BoxCollider(ColliderSize);
}

//効果の発動
void TransparentGimmick::Active()
{
	//光らせるフラグが立っている時
	if (m_appear)
	{
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
	//光っていないときは枠線を表示
	m_appear ? GimmickBase::Draw() : DrawFrameLine();
}

//枠線の表示
void TransparentGimmick::DrawFrameLine()
{
	if(m_collider) m_collider->DrawBoxLine(m_transform);
}

//衝突イベント
void TransparentGimmick::OnCollision(const ModelActor* other)
{
	if (other->GetName() == "Flush")
	{
		//光らせるフラグを立てる
		m_appear = true;
		m_appearTime = 0;

		//効果音
		SoundManager::Play("Resource/sound/se_gimmick_flush.mp3");
	}
}