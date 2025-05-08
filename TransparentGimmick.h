#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class TransparentGimmick : public GimmickBase
{
private:
	static constexpr float AppearTime = 5.0f;	// ������Ŏ~�܂鎞��

	bool m_appear;		// �����邩�ǂ���
	float m_appearTime;	// �����Ă���Ԃ̎���

	void DrawFrameLine();

protected:
	//���ʂ̔���
	virtual void Active() override;
	virtual void Draw() override;

public:
	//�R���X�g���N�^
	TransparentGimmick(const Vector3& spawnPos);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;

	bool GetAppear()
	{
		return m_appear;
	}
};