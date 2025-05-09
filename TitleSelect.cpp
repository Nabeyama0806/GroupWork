#include "TitleSelect.h"
#include "Input.h"
#include "Sprite.h"

//�R���X�g���N�^
TitleSelect::TitleSelect() : 
	SpriteActor("TitleSelect"),
	m_isContinued(true)
{
	//�p�����
	m_transform.position = Screen::Center;

	//�摜�̓o�^
	m_sprite = new Sprite();
	m_sprite->Register("Resource/Texture/select_cursor.png");
}

void TitleSelect::Update()
{
	//�{���̍X�V
	SpriteActor::Update();

	//���[�h�I��
	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_D))
	{
		if (m_isContinued)
		{
			m_sprite->flipX = true;
			m_isContinued = false;
		}
	}
	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_A))
	{
		if (!m_isContinued)
		{
			m_sprite->flipX = false;
			m_isContinued = true;
		}
	}
}