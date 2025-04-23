#pragma once
#include "ModelActor.h"

class Player;

class GetBottle : public ModelActor
{
public:
	enum class Type
	{
		Fire,
		Thunder,
		Water,
		Wind,
	};

private:
	static constexpr Vector3 Scale = Vector3(10, 10, 10);		//���g�̃T�C�Y
	static constexpr Vector3 SpawnOffset = Vector3(0, -25, 0);	//�X�|�[���I�t�Z�b�g

	Player* m_player;	//�v���C���[
	GetBottle::Type m_type;

public:
	//�R���X�g���N�^
	GetBottle(const Vector3& spawnPos, Player* player, const char* fileName, GetBottle::Type);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};