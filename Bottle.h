#pragma once
#include "ModelActor.h"

class Bottle : public ModelActor
{
public:
	//�{�g���̑���
	enum class  Type
	{
		Fire,		//��
		Water,		//��
		Thunder,	//��
		Wind,		//��

		Length
	};

	//���f����
	const char* ModelNames[static_cast<int>(Type::Length)] =
	{
		"Fire",
		"Water",
		"Thunder",
		"Wind"
	};

	//���f���̃t�@�C���p�X
	const char* ModelFilePath[static_cast<int>(Type::Length)] =
	{
		"Resource/honou�|�[�V����.mv1",
		"Resource/mizu�|�[�V����.mv1",
		"Resource/kaminari�|�[�V����.mv1",
		"Resource/kaminari�|�[�V����.mv1"
	};

private:
	static constexpr float Gravity = 1.2f;	//�d��

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	//�`��

public:
	//�R���X�g���N�^
	Bottle(Vector3& position) :
		ModelActor("Bottle", nullptr, position)
	{
	}
};