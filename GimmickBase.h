#pragma once
#include "ModelActor.h"
#include "Vector3.h"

class Player;
class Effect;

class GimmickBase : public ModelActor
{
protected:
	Effect* m_effect;
	Vector3 m_effectOffset;
	Vector3 m_scale;
	Player* m_player;

	virtual void Update() override;	//�X�V
	virtual void Draw() override;	//�`��

public:
	//�R���X�g���N�^
	GimmickBase(const char* name, const Vector3& position);

	//���ʂ̔���
	virtual void Active() = 0;
};