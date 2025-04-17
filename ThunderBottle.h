#pragma once
#include "Bottle.h"

class HitCollider;

class ThunderBottle : public Bottle
{
private:
	static constexpr float FlushSize = 80;	//�����͂��͈�

	HitCollider* m_flushCollider;	//���̓����蔻��

public:
	//�R���X�g���N�^
	ThunderBottle(const Vector3& position, const Vector3& forward, Player* player);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};