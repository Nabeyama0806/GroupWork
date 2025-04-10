#pragma once
#include "ModelActor.h"
#include "Vector3.h"

class Effect;

class GimmickBase : public ModelActor
{
protected:
	Vector3 m_scale;			//���g�̃T�C�Y
	Effect* m_effect;

	virtual void Update() override;	//�X�V

public:
	//�R���X�g���N�^
	GimmickBase(const char* name, const Vector3& position);

	//���ʂ̔���
	virtual void ActiveEffect() = 0;

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};