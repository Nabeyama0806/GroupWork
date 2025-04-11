#pragma once
#include "Bottle.h"

class WaterBottle : public Bottle
{
public:
	//�R���X�g���N�^
	WaterBottle(const Vector3& position, const Vector3& forward, Player* player);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};