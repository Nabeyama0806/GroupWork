#pragma once
#include "Bottle.h"

class HitCollider;

class ThunderBottle : public Bottle
{
private:
	static constexpr float FlushSize = 80;	//光が届く範囲

	HitCollider* m_flushCollider;	//光の当たり判定

public:
	//コンストラクタ
	ThunderBottle(const Vector3& position, const Vector3& forward, Player* player);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};