#include "Instructions.h"
#include "Sprite.h"
#include "Input.h"

Instructions::Instructions() :
SpriteActor("Instructions"),
m_isDraw(false)
{
	//�p�����
	m_transform.position = Screen::Center;

	//�摜�̓o�^
	m_sprite = new Sprite();
	for (int i = 0; i < static_cast<int>(Device::Length); ++i)
	{
		m_sprite->Register(TextureName[i], TextureData[i]);
	}
}

//�X�V
void Instructions::Update()
{
	//�{���̍X�V
	SpriteActor::Update();

	//�L�[�}�E
	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_TAB))
	{
		m_isDraw = !m_isDraw;
		m_sprite->Play(TextureName[static_cast<int>(Device::Keyboard)]);
	}

	//�Q�[���p�b�h
	if (Input::GetInstance()->IsPadDown(PAD_INPUT_8))
	{
		m_isDraw = !m_isDraw;
		m_sprite->Play(TextureName[static_cast<int>(Device::Gamepad)]);
	}
}

//�`��
void Instructions::Draw()
{
	if (!m_isDraw) return;

	//�{���̕`��
	SpriteActor::Draw();
}