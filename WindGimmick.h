#pragma once
#include "GimmickBase.h"
#include "Model.h"
#include "Effect.h"

class WindGimmick : public GimmickBase
{
private:
	static constexpr Vector3 Scale = Vector3(50, 50, 50);		//���g�̃T�C�Y
	static constexpr Vector3 SpawnOffset = Vector3(0, 100, 0);	//�I�t�Z�b�g
	
protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	// �`��
	virtual void ActiveEffect() override;
public:
	//�R���X�g���N�^
	WindGimmick(const Vector3& position);
};