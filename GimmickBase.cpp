#include "GimmickBase.h"
#include "Effect.h"

//コンストラクタ
GimmickBase::GimmickBase(const char* name, const Vector3& position) :
	ModelActor(name),
	m_scale(Vector3(50, 50, 50)),
	m_effect(nullptr)
{
	m_transform.position = position;
}

//更新
void GimmickBase::Update()
{
	//本来の描画
	ModelActor::Update();

	//エフェクトの更新
	if (m_effect)
	{
		m_effect->Update(m_transform.position);
	}
}

//衝突イベント
void GimmickBase::OnCollision(const ModelActor* other)
{
	//効果発動
	ActiveEffect();
}