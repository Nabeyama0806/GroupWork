#pragma once
#include "ModelActor.h"
#include "Model.h"

class WindGimmick : public ModelActor
{
private:
	static constexpr Vector3 SpawnOffset = Vector3(0, 150, 0);	//�I�t�Z�b�g
	static constexpr Vector3 Scale = Vector3(50, 50, 50);	//���g�̃T�C�Y
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);	// �R���C�_�[�̃I�t�Z�b�g
	static constexpr Vector3 ColliderSize = Vector3(4, 4, 4);	// �R���C�_�[�̃T�C�Y

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	// �`��

public:
	//�R���X�g���N�^
	WindGimmick(Vector3 position);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};