#pragma once
#include "Node.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Transform.h"
#include "Actor.h"

class Camera : public Node
{
private:
	static constexpr Vector3 SpawnPos = Vector3(0, 170, -400);
	static constexpr float LookAtHeight = 10;			//�����_����̍����̃I�t�Z�b�g
	static constexpr float m_cameraDistance = 900;		//�J�������W�܂ł̋���
	static constexpr float m_cameraAngleSpeed = 1.5f;	//�J�����̉�]���x

	Transform* m_transform;		//�p�����
	Actor* m_lookAt;			//��������I�u�W�F�N�g
	Vector3 m_targetPos;		//�����_���W
	Vector3 m_cameraPos;		//�J�������W
	Vector3 m_cameraAngle;		//�J�����p�x
	
	float m_cameraHAngle;		//����]
	float m_cameraVAngle;		//�c��]

protected:
	virtual void Update();	//�X�V
	virtual void Draw();	//�`��

public:
	//�R���X�g���N�^
	Camera() :
		m_transform(nullptr),
		m_lookAt(nullptr),
		m_cameraHAngle(0),
		m_cameraVAngle(21)
	{
		m_transform = new Transform();
	}

	//�����_�̎擾
	void SetlookAt(Actor* actor)
	{
		m_lookAt = actor;
	}

	float GetHAngle()
	{
		return m_cameraHAngle;
	}

	float GetVAngle()
	{
		return m_cameraVAngle;
	}

	Vector3 GetForward() const
	{
		return (m_targetPos - m_cameraPos).Normalized();
	}

	Vector3 GetRight() const
	{
		return Vector3::Cross(Vector3(0, 1, 0), GetForward()).Normalized();
	}
};