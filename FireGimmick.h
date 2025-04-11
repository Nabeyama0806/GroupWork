#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class FireGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);		//自身のサイズ
	static constexpr float FireTime = 3;	// 燃え続ける時間

	bool m_destroyWall;	// このオブジェクトが消えるかどうか
	float m_fireTime;	// 燃える時間

protected:
	//効果の発動
	virtual void Active() override;

public:
	//コンストラクタ
	FireGimmick(const Vector3& position);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};