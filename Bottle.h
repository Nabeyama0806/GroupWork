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

	Type m_type;	//���g�̑���

private:
	static constexpr float Gravity = 1.2f;	//�d��

protected:
	void Throw();

public:
	//�R���X�g���N�^
	Bottle(Vector3& position);
};