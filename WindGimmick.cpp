#include "WindGimmick.h"
#include "BoxCollider.h"
#include "Time.h"

//コンストラクタ
WindGimmick::WindGimmick(const Vector3& position) :
	GimmickBase("Wind", position),
	m_elapsedTime(0)
{
	//エフェクト
	m_effect = new Effect("Data/wind.efk", 25, 130);

	//姿勢情報
	m_transform.position = position + SpawnOffset;
	m_transform.scale = Scale;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale);
}

//更新
void WindGimmick::Update()
{
	//本来の更新
	GimmickBase::Update();

	//時間経過で削除
	m_elapsedTime += Time::GetInstance()->GetDeltaTime();
	if (EffectDrawTime < m_elapsedTime)
	{
		Destroy();
	}
}

//効果の発動
void WindGimmick::Active()
{
	//風エフェクトの表示
	m_effect->Play();
}