#pragma once
#include "ModelActor.h"
#include "Model.h"
#include "GetBottle.h"
#include <vector>

class Camera;
class PlayerFoot;
class UiBottle;
class Bottle;

class Player : public ModelActor
{
private:
	static constexpr Vector3 Scale = Vector3(10.0f, 10.0f, 10.0f);	//���g�̃T�C�Y
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);	// �R���C�_�[�̃I�t�Z�b�g
	static constexpr Vector3 ColliderSize = Vector3(30, 30, 30);	// �R���C�_�[�̃T�C�Y
	static constexpr float Speed = 0.6f * Scale.y;	//���g�̃T�C�Y�ɍ������ړ����x
	static constexpr float GravityScale = 13.0f;			// �d��
	static constexpr float DashSpeed = 1.4f;		//�_�b�V�����̑��x�{��
	static constexpr int AnimeAmount = 1;			//�A�j���[�V�����̑���

	Camera* m_camera;
	UiBottle* m_uiBottle;
	Vector3 m_holdMove;
	Vector3 m_spawnPos;			//�X�|�[���n�_
	PlayerFoot* m_playerFoot;	//�v���C���[�̑�

	bool m_createBottle;//�{�g���������Ă��邩�ǂ���
	bool m_onWallHit;	// �n�ʂɂ��Ă��邩�ǂ���
	bool m_getKey;		// ���������Ă��邩�ǂ���
	bool m_canWindBottleThrow;
	bool m_isGoal;

	int m_getBottleFlag;	// �{�g���������Ă��邩�ǂ���

	void Move();			//�ړ�����
	void CreateBottle();	//�w�肳�ꂽ�{�g���̍쐬

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	// �`��

public:
	//�R���X�g���N�^
	Player(Camera* camera, UiBottle* uiBottle);

	void GetElement(GetBottle::Type type)
	{
		m_getBottleFlag |= 1 << static_cast<int>(type);
	}

	void SetSpawnPosition(const Vector3& position)
	{
		m_spawnPos = position;
		m_transform.position = position;
	}

	// �v���C���[�̈ʒu��ݒ�
	void SetPosition(Vector3 position)
	{
		m_transform.position = position;
	}

	bool IsGetKey() const 
	{
		return m_getKey;
	}

	void DestroyBottle() //�{�g����j������
	{
		m_createBottle = false;
	}	

	void SetCanWindBottleThrow()
	{
		m_canWindBottleThrow = true;
	}

	Vector3& GetHoldMove()
	{
		return m_holdMove;
	}

	bool GetOnWallHit()
	{
		return m_onWallHit;
	}

	bool GetIsGoal()
	{
		return m_isGoal;
	}

	void SetIsGoal()
	{
		m_isGoal = false;
	}

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};