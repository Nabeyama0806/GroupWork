#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;
class Camera;

class TransparentGimmick : public GimmickBase
{
private:
	static constexpr float AppearTime = 5.0f;	// ������Ŏ~�܂鎞��

	Camera* m_camera;
	bool m_appear;		// �����邩�ǂ���
	float m_appearTime;	// �����Ă���Ԃ̎���

protected:
	//���ʂ̔���
	virtual void Active() override;
	virtual void Draw() override;

public:
	//�R���X�g���N�^
	TransparentGimmick(const Vector3& spawnPos, Camera* camera);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;

	bool GetAppear() const
	{
		return m_appear;
	}
};