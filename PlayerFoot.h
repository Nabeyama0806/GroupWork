#pragma once
#include "ModelActor.h"
#include "Vector3.h"
#include "BoxCollider.h"

class Player;

class PlayerFoot : public ModelActor
{
private:
	static constexpr Vector3 ColliderSize = Vector3(28, 2, 28);
	static constexpr Vector3 ColliderOffset = Vector3(0, -15, 0);

	Player* m_player;
	Vector3 m_holdMove;
	bool m_isGrounded;

protected:
	//�X�V
	virtual void Update() override;

public:
	//�R���X�g���N�^
	PlayerFoot(Player* player, Vector3& position);

	//�ڒn����̎擾
	bool GetIsGronded()
	{
		return m_isGrounded;
	}

	void SetPosition(const Vector3& position)
	{
		m_transform.position = position + ColliderOffset;
	}

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;

	void FollowPlayer();
};