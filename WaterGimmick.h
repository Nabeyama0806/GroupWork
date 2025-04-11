#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class WaterGimmick : public GimmickBase
{
private:
	static constexpr float DownWaterHeight = 10.0f;
	static constexpr float UpWaterHeight = 250.0f;

	static constexpr float VariableWater = 2.0f;	// �ϓ����鐅�̑��x

	bool m_isWaterHeight;	// ���������Ȃ��Ă��邩�ǂ���
	bool m_isPlay;

protected:
	//���ʂ̔���
	virtual void Active() override;

public:
	//�R���X�g���N�^
	WaterGimmick(const Vector3& spawnPos, const Vector3& scale, const Vector3& offset = Vector3(0, 0, 0));

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};