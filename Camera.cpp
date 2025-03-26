#include "Camera.h"
#include "Input.h"
#include "Math.h"

//�X�V
void Camera::Update()
{
	//�����L�[�ŃJ�����̑���
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		m_cameraHAngle += m_cameraAngleSpeed;
		if (m_cameraHAngle >= 180.0f) m_cameraHAngle -= 360.0f;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		m_cameraHAngle -= m_cameraAngleSpeed;
		if (m_cameraHAngle <= -180.0f) m_cameraHAngle += 360.0f;
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		m_cameraVAngle += m_cameraAngleSpeed;
		if (m_cameraVAngle >= 80.0f) m_cameraVAngle = 80.0f;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		m_cameraVAngle -= m_cameraAngleSpeed;
		if (m_cameraVAngle <= 0.0f) m_cameraVAngle = 0.0f;
	}

	Vector3 TempPosition1;
	Vector3 TempPosition2;
	Vector3 CameraLookAtPosition;						//�����_
	CameraLookAtPosition = m_lookAt->GetPosition();		//�����_��ݒ�
	CameraLookAtPosition.y += LookAtHeight;				//�����_�̃I�t�Z�b�g

	//�ŏ��ɐ����p�x�𔽉f�����ʒu���Z�o
	float sinParam = sin(Math::DegToRad(m_cameraVAngle));
	float cosParam = cos(Math::DegToRad(m_cameraVAngle));
	TempPosition1.x = 0.0f;
	TempPosition1.y = sinParam * m_cameraDistance;
	TempPosition1.z = -cosParam * m_cameraDistance;

	//���ɐ����p�x�𔽉f�����ʒu���Z�o
	sinParam = sin(Math::DegToRad(m_cameraHAngle));
	cosParam = cos(Math::DegToRad(m_cameraHAngle));
	TempPosition2.x = cosParam * TempPosition1.x - sinParam * TempPosition1.z;
	TempPosition2.y = TempPosition1.y;
	TempPosition2.z = sinParam * TempPosition1.x + cosParam * TempPosition1.z;

	//�Z�o�������W�ɒ����_�̈ʒu�����Z�������̂��J�����̈ʒu
	m_cameraPos = TempPosition2 + CameraLookAtPosition;
	m_targetPos = CameraLookAtPosition;
}

//�`��
void Camera::Draw()
{
	// �J�������W�̐ݒ�
	SetCameraPositionAndTarget_UpVecY(m_cameraPos, m_targetPos);
}