#pragma once
#include "Bottle.h"

class WindBottle : public Bottle
{
protected:
	virtual void ActiveEffect() override;

public:
	//�R���X�g���N�^
	WindBottle(const Vector3& position, const Vector3& forward, Player* player);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
}; 
