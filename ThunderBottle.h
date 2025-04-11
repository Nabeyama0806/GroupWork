#pragma once
#include "Bottle.h"

class ThunderBottle : public Bottle
{
public:
	//コンストラクタ
	ThunderBottle(const Vector3& position, const Vector3& forward, Player* player);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};