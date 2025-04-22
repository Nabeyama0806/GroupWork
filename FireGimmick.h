#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class FireGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);		//���g�̃T�C�Y
	static constexpr float FireTime = 3;	// �R�������鎞��

	bool m_destroyWall;	// ���̃I�u�W�F�N�g�������邩�ǂ���
	float m_fireTime;	// �R���鎞��

protected:
	//���ʂ̔���
	virtual void Active() override;

public:
	//�R���X�g���N�^
	FireGimmick(const Vector3& position);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};