#include "WindGimmick.h"
#include "BoxCollider.h"

WindGimmick::WindGimmick(const Vector3& position) :
	GimmickBase("Wind", position)
{
	m_effect = new Effect("Data/wind.efk", 25);

	m_transform.position = position + SpawnOffset;
	m_transform.scale = Scale;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale, m_transform.scale);
}

//更新
void WindGimmick::Update()
{
	//本来の更新
	GimmickBase::Update();
	m_effect->Play(true);
}

//描画
void WindGimmick::Draw()
{
	//本来の更新
	ModelActor::Draw();
}

//効果の発動
void WindGimmick::ActiveEffect()
{
	//風エフェクトの表示
	m_effect->Play();
}