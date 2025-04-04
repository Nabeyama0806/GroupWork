#pragma once
#include "Bottle.h"

class Player;

class FireBottle : public Bottle
{
private :
	Vector3 m_forward;
	Player* m_player;

protected:
	virtual void Update() override;			//�X�V
	virtual void Draw() override;			//�`��
	virtual void ActiveEffect() override;	//���ʔ���

public:
	//�R���X�g���N�^
	FireBottle(const Vector3& position, const Vector3& forward, Player* player);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};