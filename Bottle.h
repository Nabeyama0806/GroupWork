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

private:
	static constexpr float Gravity = 1.2f;	//�d��

	Vector3 m_effectiveArea;	//���ʂ̗L���͈�
	Type m_type;				//���g�̑���

protected:
	virtual void ActiveEffect() = 0;		//�ڐG���̔�������
	void Throw(Vector3& position, Vector3& addforce);
	Vector3 m_addForce;			//���������

public:
	//�R���X�g���N�^
	Bottle(Vector3& position);
};