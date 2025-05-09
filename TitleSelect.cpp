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

	//�I��p�̃{�^��
	AddChild(new SpriteActor("Select", "Resource/Texture/select.png", Screen::Center));
}

//�X�V
void TitleSelect::Update()
{
	//�{���̍X�V
	SpriteActor::Update();

	//���[�h�I��
	if (Input::GetInstance()->MoveRight())
	{
		if (!m_isContinued) return;
		m_sprite->flipX = true;
		m_isContinued = false;
	}
	if (Input::GetInstance()->MoveLeft())
	{
		if (m_isContinued) return;
		m_sprite->flipX = false;
		m_isContinued = true;
	}
}