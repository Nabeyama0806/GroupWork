#pragma once
#include "Bottle.h"

class ThunderBottle : public Bottle
{
private:
	Vector3 m_forward;

protected:
	virtual void Update() override;			//�X�V
	virtual void Draw() override;			//�`��
	virtual void ActiveEffect() override;	//���ʔ���

public:
	//�R���X�g���N�^
	ThunderBottle(const Vector3& position, const Vector3& forward, const Quaternion& rotation);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};