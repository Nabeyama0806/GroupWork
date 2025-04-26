#pragma once
#include "Bottle.h"

class WindBottle : public Bottle
{
private:
	Vector3 m_forward;
	Vector3 m_holdMove;

protected:
	virtual void Update() override;
	virtual void DestroyBottle() override;

public:
	//�R���X�g���N�^
	WindBottle(const Vector3& position, const Vector3& forward, Player* player);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
}; 
