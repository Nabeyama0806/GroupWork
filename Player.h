#pragma once
#include "ModelActor.h"
#include "Model.h"
#include "Vector3.h"
#include "Camera.h"
#include <vector>

class Camera;

class Player : public ModelActor
{
private:
	static constexpr Vector3 SpawnPos = Vector3(0, 100, 400);	//�J�n���̍��W
	static constexpr Vector3 Scale = Vector3(1.5f, 1.5f, 1.5f);	//���g�̃T�C�Y
	static constexpr Vector3 ColliderOffset = Vector3(0, 80, 0);	// �R���C�_�[�̃I�t�Z�b�g
	static constexpr float Speed = 7.5f * Scale.y;	//���g�̃T�C�Y�ɍ������ړ����x
	static constexpr float GravityScale = 0.8f;			// �d��
	static constexpr float DashSpeed = 1.4f;		//�_�b�V�����̑��x�{��
	static constexpr int AnimeAmount = 2;			//�A�j���[�V�����̑���

	const char* AnimeFileName[AnimeAmount] =
	{
		"Man/Idle.mv1",		//�ҋ@
		"Man/Sprint.mv1"	//�_�b�V��
	};

	Camera* m_camera;

	bool m_onGround;	// �n�ʂɂ��Ă��邩�ǂ���
	bool m_onWall;		// �ǂɓ������Ă��邩�ǂ���
protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	//�`��

public:
	//�R���X�g���N�^
	Player(Camera* camera);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};