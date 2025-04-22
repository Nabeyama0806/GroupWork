#pragma once
#include "ModelActor.h"
#include "Model.h"
#include <vector>

class Camera;
class UiBottle;
class Bottle;

class Player : public ModelActor
{
private:
	static constexpr Vector3 Scale = Vector3(10.0f, 10.0f, 10.0f);	//���g�̃T�C�Y
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);	// �R���C�_�[�̃I�t�Z�b�g
	static constexpr Vector3 ColliderSize = Vector3(30.0f, 30.0f, 30.0f);	// �R���C�_�[�̃T�C�Y
	static constexpr float Speed = 0.6f * Scale.y;	//���g�̃T�C�Y�ɍ������ړ����x
	static constexpr float GravityScale = 13.0f;			// �d��
	static constexpr float DashSpeed = 1.4f;		//�_�b�V�����̑��x�{��
	static constexpr int AnimeAmount = 1;			//�A�j���[�V�����̑���

	const char* AnimeFileName[AnimeAmount] =
	{
		"Resource/Model/Tmp.mv1",		//�ҋ@
	};

	Camera* m_camera;
	UiBottle* m_uiBottle;
	Vector3 m_holdMove;
	Vector3 m_spawnPos;	//�X�|�[���n�_
	ModelActor* m_playerFoot;	//�v���C���[�̑�

	bool m_createBottle;//�{�g���������Ă��邩�ǂ���
	bool m_onGround;	// �n�ʂɂ��Ă��邩�ǂ���
	bool m_getKey;	// ���������Ă��邩�ǂ���
	bool m_canWindBottleThrow;	//���{�g���𓊂����邩

	void Move();			//�ړ�����
	void CreateBottle();	//�w�肳�ꂽ�{�g���̍쐬

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	// �`��

public:
	//�R���X�g���N�^
	Player(Camera* camera, UiBottle* uiBottle);

	// �v���C���[�̈ʒu��ݒ�
	void SetPosition(Vector3 position)
	{
		m_spawnPos = position;
		m_transform.position = m_spawnPos;
	}

	bool IsGetKey() const 
	{
		return m_getKey;
	}

	void DestroyBottle();	//�{�g����j������
	void SetCanWindBottleThrow(bool flag);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};