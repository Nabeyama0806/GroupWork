#pragma once
#include "Bottle.h"

class FireBottle : public Bottle
{
public:
	//�R���X�g���N�^
	FireBottle(const Vector3& position, const Vector3& forward, Player* player);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};