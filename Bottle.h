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
	static constexpr float Gravity = 0.01f;	//�d��
	static constexpr float AddForce = 2000;	//�������
	static constexpr float Mass = 2;		//����

	Type m_type;				//���g�̑���

protected:
	static constexpr Vector3 ColliderSize = Vector3(80, 80, 80);

	virtual void ActiveEffect() = 0;		//�ڐG���̔�������
	Vector3 Throw(Vector3& position) const;


public:
	//�R���X�g���N�^
	Bottle(const Vector3& position, Type type);

	Type GetType() { return m_type; }
};