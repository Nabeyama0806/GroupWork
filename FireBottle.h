#pragma once
#include "Bottle.h"

class FireBottle : public Bottle
{
public:
	//コンストラクタ
	FireBottle(const Vector3& position, const Vector3& forward, Player* player);

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};