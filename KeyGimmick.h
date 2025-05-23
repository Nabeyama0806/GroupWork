#pragma once
#include "GimmickBase.h"
#include "Model.h"

class Player;
class Effect;

class KeyGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(25, 25, 25);		//���g�̃T�C�Y
	static constexpr float DestroyTime = 1;	//�����J����̂ɕK�v�Ȏ���

	Player* m_player;		//�v���C���[
	bool m_destroyWall;		// ���̃I�u�W�F�N�g�������邩�ǂ���
	bool m_isFake;			// �U�����ǂ���	
	float m_destroyTime;	// �o�ߎ���

protected:
	//���ʂ̔���
	virtual void Active() override;

public:
	//�R���X�g���N�^
	KeyGimmick(const Vector3& position, Player* player, bool isFake);

	//�Փ˃C�x���g
	virtual void OnCollision(const ModelActor* other) override;
};