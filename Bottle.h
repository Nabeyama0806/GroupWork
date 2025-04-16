#pragma once
#include "ModelActor.h"

class Player;

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

	static constexpr Vector3 Scale = Vector3(10, 10, 10);		//�傫���̒���
private:
	static constexpr float Gravity = 0.01f;	//�d��
	static constexpr float AddForce = 1700;	//�������
	static constexpr float Mass = 2;		//����

	Vector3 m_forward;

protected:
	static constexpr Vector3 ColliderSize = Vector3(4, 4, 4);

	Player* m_player;

	virtual void Update() override;		//�X�V
	virtual void ActiveEffect();				//���ʂ̔���
	Vector3 Throw(Vector3& position) const;

public:
	//�R���X�g���N�^
	Bottle(const char* bottleName, const Vector3& position, const Vector3& forward, Player* player);
};