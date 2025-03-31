#pragma once
#include "Bottle.h"

class FireBottle : public Bottle
{
protected:
	virtual void Update() override;			//�X�V
	virtual void Draw() override;			//�`��
	virtual void ActiveEffect() override;	//���ʔ���

public:
	//�R���X�g���N�^
	FireBottle(Vector3& position, Vector3& addForce);
};