#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Effect;

class KeyItem : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);		//���g�̃T�C�Y
	static constexpr float DestroyTime = 1.5f;	//���̔j�󎞊�

	float m_destroyTime;//���̔j�󎞊�
	bool m_destroyKey;	// ������������ǂ���

protected:
	//���ʂ̔���
	virtual void Active() override;

public:
	//�R���X�g���N�^
	KeyItem(const Vector3& position, const Vector3& size);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};