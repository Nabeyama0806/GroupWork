#pragma once
#include "ModelActor.h"

class Bottle : public ModelActor
{
public:
	//�{�g���̑���
	enum class  Type
	{
		Fire,		//��
		Thunder,	//��
		Water,		//��
		Wind,		//��

		Length
	};

	static constexpr int Scale = 20;		//�傫���̒���
private:
	static constexpr float Gravity = 1.2f;	//�d��
	static constexpr float AddForce = 20;	//�������
	static constexpr float Mass = 2;		//����

	Vector3 m_effectiveArea;	//���ʂ̗L���͈�
	Type m_type;				//���g�̑���

protected:
	virtual void ActiveEffect() = 0;		//�ڐG���̔�������
	Vector3 Throw(Vector3& position, float addforce) const;
	Vector3 m_addForce;			//���������

public:
	//�R���X�g���N�^
	Bottle(const Vector3& position);
};