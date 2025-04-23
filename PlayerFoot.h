#pragma once
#include "ModelActor.h"
#include "Player.h"
#include "Vector3.h"
#include "BoxCollider.h"

class PlayerFoot : public ModelActor
{
private:
	static constexpr Vector3 ColliderSize = Vector3(10, 5, 10);
	static constexpr Vector3 ColliderOffset = Vector3(0, -10, 0);

	Player* m_player;
	bool m_isGrounded;

protected:
	//�X�V
	virtual void Update() override
	{
		m_transform.position = m_player->GetPosition() + ColliderOffset;

		m_isGrounded = false;
	}

public:
	//�R���X�g���N�^
	PlayerFoot(Player* player, Vector3& position) :
		ModelActor("PlayerFoot", nullptr, position),
		m_player(player),
		m_isGrounded(false)
	{
		//�v���C���[�̑����̓����蔻��
		m_collider = new BoxCollider(ColliderSize, ColliderOffset);
	}

	//�ڒn����̎擾
	bool GetIsGronded()
	{
		return m_isGrounded;
	}

	//�ڒn����̐ݒ�
	void SetIsGrounded(bool flag)
	{
		m_isGrounded = flag;
	}

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override
	{
		if (other->GetName() == "Wall")
		{
			m_isGrounded = true;
		}
	}
};