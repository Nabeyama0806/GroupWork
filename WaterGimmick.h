#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class WaterGimmick : public GimmickBase
{
private:
	static constexpr float VariableWater = 2.0f;	// �ϓ����鐅�̑��x
	static constexpr float StopTime = 5.0f;	// ������Ŏ~�܂鎞��

	bool m_waterHeight;	// ���r�ɓ����������ǂ���
	bool m_canUp;		//�㏸�\���ǂ���
	float m_stopTime;	// ������Ŏ~�܂��Ă��鎞��
	Vector3 m_startPos;	// ���̏����ʒu

protected:
	//���ʂ̔���
	virtual void Active() override;

public:
	//�R���X�g���N�^
	WaterGimmick(const Vector3& spawnPos, const Vector3& scale, const Vector3& offset = Vector3(0, 0, 0));

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};