#pragma once
#include "Vector2.h"
#include "DxLib.h"

#define KEY_INPUT_ENTER KEY_INPUT_RETURN

//���̓N���X
class Input
{
private:
	//�L�[�{�[�h
	static constexpr int KeyStateNum = 256;	//�L�[���͏�Ԃ̗v�f��
	static constexpr float PadStickSensitivity = 0.04f;	//�X�e�B�b�N�̊��x

	char m_keyState[KeyStateNum];		//���t���[���̃L�[���͏��
	char m_keyStatePost[KeyStateNum];	//�O�t���[���̃L�[���͏��

	//�}�E�X
	Vector2 m_mousePoint;		//�}�E�X�ʒu
	int m_mouseWheel;			//�}�E�X�z�C�[��
	int m_mouseButton;			//���t���[���̃}�E�X�{�^�����͏��
	int m_mouseButtonPost;		//�O�t���[���̃}�E�X�{�^�����͏��

	// �p�b�h
	int m_padButton;
	int m_padButtonPost;

	//�R���X�g���N�^
	Input() :
		m_keyState{ 0 },
		m_keyStatePost{ 0 },
		m_mouseWheel(0),
		m_mouseButton(0),
		m_mouseButtonPost(0),
		m_padButton(0),
		m_padButtonPost(0){}	//�z��̏������́i�j�ł͂Ȃ��o�p���g��

public:
	//�V���O���g��
	static Input* GetInstance()
	{
		static Input instance;
		return &instance;
	}

	//�X�V
	void Update();

	//�L�[�������ꂽ�u��
	bool IsKeyDown(int key)
	{
		return !m_keyStatePost[key] && m_keyState[key];
	}

	//�L�[��������Ă���
	bool IsKeyPress(int key)
	{
		return m_keyState[key];
	}

	//�L�[�������ꂽ�u��
	bool IsKeyUp(int key)
	{
		return m_keyStatePost[key] && !m_keyState[key];
	}

	//�����̃L�[�������ꂽ�u��
	bool IsAnyKeyDown();

	//�����̃L�[��������Ă���
	bool IsAnyKeyPress();

	//�}�E�X�ʒu���擾
	Vector2 GetMousePoint()
	{
		return	m_mousePoint;
	}

	// �}�E�X�ʒu��ݒ�
	void SetMousePoint(int posX, int posY)
	{
		DxLib::SetMousePoint(posX, posY);
		m_mousePoint = Vector2(posX, posY);
	}

	// �}�E�X�J�[�\���̕\��
	void SetMouseDispFlag(bool isDisp)
	{
		DxLib::SetMouseDispFlag(isDisp);
	}
	
	//�}�E�X�z�C�[�����擾
	int GetMouseHweelRot()
	{
		return m_mouseWheel;
	}

	//�}�E�X�{�^���������ꂽ�u��
	bool IsMouseDown(int button)
	{
		return (m_mouseButton & button) && !(m_mouseButtonPost & button);
	}

	//�}�E�X�{�^����������Ă��鎞
	bool IsMousePress(int button)
	{
		return (m_mouseButton & button);
	}

	//�}�E�X�{�^���������ꂽ�u��
	bool IsMouseUp(int button)
	{
		return !(m_mouseButton & button) && (m_mouseButtonPost & button);
	}

	// �p�b�h�{�^���������ꂽ�u��
	bool IsPadDown(int button)
	{
		return (m_padButton & button) && !(m_padButtonPost & button);
	}

	// �p�b�h�{�^����������Ă���
	bool IsPadPress(int button)
	{
		return (m_padButton & button);
	}

	// �p�b�h�{�^���������ꂽ�u��
	bool IsPadUp(int button)
	{
		return !(m_padButton & button) && (m_padButtonPost & button);
	}
};