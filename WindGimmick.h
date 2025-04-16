#pragma once
#include "GimmickBase.h"
#include "Model.h"
#include "Effect.h"

class WindGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(25, 25, 25);		//���g�̃T�C�Y
	static constexpr Vector3 SpawnOffset = Vector3(0, 50, 0);	//�I�t�Z�b�g
	static constexpr float EffectDrawTime = 6.5f;				//�G�t�F�N�g��\�����鎞��
		
	float m_elapsedTime;	//�o�ߎ���

	Vector3 SnapPosition(const Vector3& playerPos);

protected:
	virtual void Update() override;		//�X�V
	virtual void Active() override;		//���ʂ̔���
	
public:
	//�R���X�g���N�^
	WindGimmick(const Vector3& position, Player* m_player);
};