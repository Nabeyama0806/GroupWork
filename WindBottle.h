#pragma once
#include "Bottle.h"

class WindBottle : public Bottle
{
protected:
	virtual void Update() override;			//�X�V
	virtual void Draw() override;			//�`��
	virtual void ActiveEffect() override;	//���ʔ���

public:
	//�R���X�g���N�^
	WindBottle(Vector3& position, Vector3& addForce);
}; 
