#pragma once
#include "ModelActor.h"
#include "Model.h"
#include "GetBottle.h"
#include "PlayerFoot.h"
#include <vector>

class Camera;
class UiBottle;
class Bottle;
class CreateMap;

class Player : public ModelActor
{
private:
	static constexpr Vector3 Scale = Vector3(10.0f, 10.0f, 10.0f);	//���g�̃T�C�Y
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);	// �R���C�_�[�̃I�t�Z�b�g
	static constexpr Vector3 ColliderSize = Vector3(30, 30, 30);	// �R���C�_�[�̃T�C�Y
	static constexpr float Speed = 0.5f * Scale.y;	//���g�̃T�C�Y�ɍ������ړ����x
	static constexpr float GravityScale = 13.0f;			// �d��
	static constexpr float DashSpeed = 1.4f;		//�_�b�V�����̑��x�{��
	static constexpr int AnimeAmount = 1;			//�A�j���[�V�����̑���

	Camera* m_camera;
	UiBottle* m_uiBottle;
	Vector3 m_holdMove;
	Vector3 m_spawnPos;			//�X�|�[���n�_
	PlayerFoot* m_playerFoot;	//�v���C���[�̑�
	CreateMap* m_map;			//�}�b�v

	bool m_createBottle;		// �{�g���������Ă��邩�ǂ���
	bool m_onWallHit;			// �n�ʂɂ��Ă��邩�ǂ���
	bool m_isExistenceKey;		// �X�e�[�W�Ɍ������݂��Ă��邩�ǂ���
	bool m_getKey;				// ���������Ă��邩�ǂ���
	bool m_canWindBottleThrow;	// ���{�g���𓊂����邩�ǂ���
	bool m_isGoal;				// ���݂̃X�e�[�W���N���A�������ǂ���

	int m_getBottleFlag;	// �{�g���������Ă��邩�ǂ���
	int ModelHandle, LightHandle;//���C�g�n���h��

	void Move();			//�ړ�����
	void CreateBottle();	//�w�肳�ꂽ�{�g���̍쐬

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	// �`��

public:
	//�R���X�g���N�^
	Player(Camera* camera, UiBottle* uiBottle);

	void SetElement(GetBottle::Type type)
	{
		m_getBottleFlag |= 1 << static_cast<int>(type);
	}

	int GetElement() const
	{
		return m_getBottleFlag;
	}

	void SetSpawnPosition(const Vector3& position)
	{
		m_spawnPos = position;
		m_transform.position = position;
		m_playerFoot->SetPosition(position);
	}

	// �v���C���[�̈ʒu��ݒ�
	void SetPosition(Vector3 position)
	{
		m_transform.position = position;
	}

	void SetMap(CreateMap* map)
	{
		m_map = map;
	}

	void UseKey()
	{
		m_getKey = false;
	}
	bool GetIsKey() const 
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

	bool GetOnWallHit() const
	{
		return m_onWallHit;
	}

	bool GetIsGoal() const
	{
		return m_isGoal;
	}
	void SetIsGoal()
	{
		m_isGoal = false;
	}

	bool GetIsExistenceKey()
	{
		return m_isExistenceKey;
	}
	void SetIsExistenceKey(bool flag)
	{
		m_isExistenceKey = flag;
	}

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};