#pragma once
#include "ModelActor.h"
#include "Model.h"
#include "Vector3.h"
#include "Camera.h"
#include <vector>

class Camera;
class UiBottle;
class Bottle;

class Player : public ModelActor
{
private:
	static constexpr Vector3 SpawnPos = Vector3(0, 200, 400);	//�J�n���̍��W
	static constexpr Vector3 Scale = Vector3(20.0f, 20.0f, 20.0f);	//���g�̃T�C�Y
	static constexpr Vector3 ColliderOffset = Vector3(0, 2, 0);	// �R���C�_�[�̃I�t�Z�b�g
	static constexpr Vector3 ColliderSize = Vector3(3.0f, 5.0f, 3.0f);	// �R���C�_�[�̃T�C�Y
	static constexpr float Speed = 0.6f * Scale.y;	//���g�̃T�C�Y�ɍ������ړ����x
	static constexpr float GravityScale = 13.0f;			// �d��
	static constexpr float DashSpeed = 1.4f;		//�_�b�V�����̑��x�{��
	static constexpr int AnimeAmount = 1;			//�A�j���[�V�����̑���

	const char* AnimeFileName[AnimeAmount] =
	{
		"Man/Tmp.mv1",		//�ҋ@
	};

	Camera* m_camera;
	UiBottle* m_uiBottle;
	Vector3 m_holdMove;

	bool m_createBottle;//�{�g���������Ă��邩�ǂ���
	bool m_onGround;	// �n�ʂɂ��Ă��邩�ǂ���
	bool m_onWall;		// �ǂɓ������Ă��邩�ǂ���

	void Move();			//�ړ�����
	void CreateBottle();	//�w�肳�ꂽ�{�g���̍쐬

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	// �`��

public:
	//�R���X�g���N�^
	Player(Camera* camera, UiBottle* uiBottle);

	void DestroyBottle();	//�{�g����j������

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};