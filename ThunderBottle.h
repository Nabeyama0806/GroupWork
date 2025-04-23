#pragma once
#include "Bottle.h"

class HitCollider;
class Effect;
class Player;

class ThunderBottle : public Bottle
{
private:
	static constexpr float FlushSize = 80;	//光が届く範囲
	static constexpr float FlushTime = 0.1f;	//光の当たる時間

	HitCollider* m_flushCollider;	//光の当たり判定
	Effect* m_effect;	//エフェクト

	float m_time;	//時間

protected:
	virtual void Update() override;	//更新

public:
	//コンストラクタ
	ThunderBottle(const Vector3& position, const Vector3& forward, Player* player);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};