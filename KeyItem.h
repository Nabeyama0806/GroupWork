#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class KeyItem : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);		//自身のサイズ
	static constexpr float DestroyTime = 1.5f;	//鍵の破壊時間

	float m_destroyTime;//鍵の破壊時間
	bool m_destroyKey;	// 鍵を取ったかどうか

protected:
	//効果の発動
	virtual void Active() override;

public:
	//コンストラクタ
	KeyItem(const Vector3& position, const Vector3& size);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};