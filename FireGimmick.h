#pragma once
#include "ModelActor.h"
#include "Model.h"

class FireGimmick : public ModelActor
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);	//���g�̃T�C�Y
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);	// �R���C�_�[�̃I�t�Z�b�g
	static constexpr Vector3 ColliderSize = Vector3(4, 4, 4);	// �R���C�_�[�̃T�C�Y
	static constexpr float FireTime = 3;	// �R�������鎞��

	bool m_destroyWall;	// ���̃I�u�W�F�N�g�������邩�ǂ���
	float m_fireTime;	// �R���鎞��

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	// �`��

public:
	//�R���X�g���N�^
	FireGimmick(Vector3 position);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};