#include "WindGimmick.h"
#include "BoxCollider.h"

WindGimmick::WindGimmick(const Vector3& position) :
	GimmickBase("Wind", position)
{
	//エフェクト
	m_effect = new Effect("Data/wind.efk", 25);

	//姿勢情報
	m_transform.position = position + SpawnOffset;
	m_transform.scale = Scale;

	//衝突判定
	Vector3 colliderScale = m_colliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale);
}

//効果の発動
void WindGimmick::Active()
{
	//風エフェクトの表示
	m_effect->Play();
}