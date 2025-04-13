#include "GimmickBase.h"
#include "Effect.h"

//コンストラクタ
GimmickBase::GimmickBase(const char* name, const Vector3& position) :
	ModelActor(name),
	m_scale(Vector3(50, 50, 50)),
	m_effectOffset(Vector3(0, -20, 0)),
	m_effect(nullptr)
{
	m_transform.position = position;
}

//更新
void GimmickBase::Update()
{
	//本来の描画
	ModelActor::Update();

	//効果の発動
	Active();

	//エフェクトの更新
	if (m_effect)
	{
		Vector3 pos = m_transform.position + m_effectOffset;
		m_effect->Update(pos);
	}
}