#pragma once
#include "ModelActor.h"
#include "Vector3.h"

class Effect;

class GimmickBase : public ModelActor
{
protected:
	Vector3 m_scale;			//自身のサイズ
	Effect* m_effect;

	virtual void Update() override;	//更新

public:
	//コンストラクタ
	GimmickBase(const char* name, const Vector3& position);

	//効果の発動
	virtual void ActiveEffect() = 0;

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};