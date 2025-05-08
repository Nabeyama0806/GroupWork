#include "Input.h"
#include "DxLib.h"
#include <cstring>

//�X�V
void Input::Update()
{
	//�L�[�{�[�h

	//�O�t���[���̃L�[���͏�Ԃ�ۑ�
	std::memcpy(m_keyStatePost, m_keyState, sizeof(char) * KeyStateNum);

	//���t���[���̃L�[���͏�Ԃ��擾
	GetHitKeyStateAll(m_keyState);

	//�}�E�X

	//�O�t���[���̃}�E�X�{�^�����͏�Ԃ�ۑ�
	m_mouseButtonPost = m_mouseButton;

	//���݂̃}�E�X�{�^�����͏�Ԃ��擾
	m_mouseButton = DxLib::GetMouseInput();

	//�}�E�X�ʒu���擾
	int mouseX = 0;
	int mouseY = 0;
	DxLib::GetMousePoint(&mouseX, &mouseY);
	m_mousePoint = Vector2(mouseX, mouseY);

	//�}�E�X�z�C�[�����擾
	m_mouseWheel = DxLib::GetMouseWheelRotVol();

	//�}�E�X�̍��{�^���������ꂽ��AZ�L�[�����͂��ꂽ���Ƃɂ���
	if (m_mouseButton & MOUSE_INPUT_LEFT) m_keyState[KEY_INPUT_Z] = 1;

	// �p�b�h
	m_padButtonPost = m_padButton;
	m_padButton = GetJoypadInputState(DX_INPUT_PAD1);

	//�p�b�h�̕����{�^������������WASD�������ꂽ���Ƃɂ���i�v���C���[�x���j
	if (IsPadPress(PAD_INPUT_UP)) m_keyState[KEY_INPUT_W] = 1;
	if (IsPadPress(PAD_INPUT_LEFT)) m_keyState[KEY_INPUT_A] = 1;
	if (IsPadPress(PAD_INPUT_DOWN)) m_keyState[KEY_INPUT_S] = 1;
	if (IsPadPress(PAD_INPUT_RIGHT)) m_keyState[KEY_INPUT_D] = 1;
	// �p�b�h��10(�E�X�e�B�b�N��������)��Space�L�[�ɂ���
	if (IsPadDown(PAD_INPUT_10)) m_keyState[KEY_INPUT_SPACE] = 1;
	// �p�b�h��1�{�^��(�~)�����N���b�N�ɂ���
	if (IsPadDown(PAD_INPUT_1)) m_mouseButton |= MOUSE_INPUT_LEFT;

	// �p�b�h�̉E�X�e�B�b�N�Ń}�E�X�J�[�\���𓮂���
	int padPointX = 0;
	int padPointY = 0;
	DxLib::GetJoypadAnalogInputRight(&padPointX, &padPointY, DX_INPUT_PAD1);
	// ���x����
	Vector2 movePadPoint = Vector2(padPointX, padPointY) * PadStickSensitivity;
	m_mousePoint += movePadPoint;

#ifdef _DEBUG
	// �p�b�h��Share�{�^����ESC�L�[�ɂ���
	if (IsPadDown(PAD_INPUT_7)) m_keyState[KEY_INPUT_ESCAPE] = 1;
#endif // DEBUG
}

//�����L�[�������ꂽ�u��
bool Input::IsAnyKeyDown()
{
	//�}�E�X
	if (m_mouseButton && (m_mouseButton ^ m_mouseButtonPost))
	{
		return true;
	}

	//�L�[�{�[�h

	//�z��̔�r
	if (std::memcpy(m_keyStatePost, m_keyState, sizeof(char) * KeyStateNum) == 0)
	{
		return false;
	}

	// �p�b�h
	if ((m_padButton & ~m_padButtonPost) != 0)
	{
		return true;
	}

	//�z�񂩂�P��T���o��
	return std::memchr(m_keyState, 1, sizeof(char) * KeyStateNum) != nullptr;
}

//�����L�[��������Ă���
bool Input::IsAnyKeyPress()
{
	//�}�E�X
	if (m_mouseButton)
	{
		return true;
	}

	// �p�b�h
	if (m_padButton != 0)
	{
		return true;
	}

	//�L�[�{�[�h

	//�z�񂩂�P��T���o��
	return std::memchr(m_keyState, 1, sizeof(char) * KeyStateNum) != nullptr;
}