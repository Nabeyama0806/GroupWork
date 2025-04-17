#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Player;
class Effect;

class KeyGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);		//���g�̃T�C�Y
	static constexpr float DestroyTime = 3;	// �R�������鎞��

	Player* m_player;	//�v���C���[
	bool m_destroyWall;	// ���̃I�u�W�F�N�g�������邩�ǂ���
	float m_destroyTime;	// �R���鎞��

protected:
	//���ʂ̔���
	virtual void Active() override;

public:
	//�R���X�g���N�^
	KeyGimmick(const Vector3& position, const Vector3& size, Player* player);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};