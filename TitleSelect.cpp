#include "TitleSelect.h"
#include "Input.h"
#include "Sprite.h"

//�R���X�g���N�^
TitleSelect::TitleSelect() :
	SpriteActor("TitleSelect"),
	m_isContinued(true),
	m_isKey(false),
	m_cursor(false),
	m_cursorPost(false)
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
	// �}�E�X�̑O�̃t���[���̏�Ԃ�ۑ�
	m_cursorPost = m_cursor;

	//�{���̍X�V
	SpriteActor::Update();

	bool onMouseLeft = IsMouseContain(NewGamePos);
	bool onMouseRight = IsMouseContain(ContinuePos);

	if (!onMouseLeft && !onMouseRight)
	{
		if (Input::GetInstance()->StageSelectRight())
		{
			StageSelect(false);
			m_isKey = true;
		}
		if (Input::GetInstance()->StageSelectLeft())
		{
			StageSelect(true);
			m_isKey = true;
		}

		if (m_cursorPost && !m_isKey) m_cursor = false;
	}
	else
	{
		m_isKey = false;
		if (onMouseLeft) StageSelect(true);
		else if (onMouseRight) StageSelect(false);
	}
}

//�`��
void TitleSelect::Draw()
{
	if (m_cursor)
	{
		//�{���̕`��
		SpriteActor::Draw();
		m_sprite->Draw(m_transform);
	}

#ifdef _DEBUG
	DrawBox
	(
		static_cast<int>(NewGamePos.x - Size.x / 2), static_cast<int>(NewGamePos.y - Size.y / 2),
		static_cast<int>(NewGamePos.x + Size.x / 2), static_cast<int>(NewGamePos.y + Size.y / 2),
		GetColor(255, 0, 0), false
	);
	DrawBox
	(
		static_cast<int>(ContinuePos.x - Size.x / 2), static_cast<int>(ContinuePos.y - Size.y / 2),
		static_cast<int>(ContinuePos.x + Size.x / 2), static_cast<int>(ContinuePos.y + Size.y / 2),
		GetColor(255, 0, 0), false
	);
#endif // _DEBUG

}

void TitleSelect::StageSelect(bool isContinue)
{
	m_cursor = true;
	m_cursorPost = false;
	if (m_isContinued == isContinue) return;
	m_sprite->flipX = !isContinue;
	m_isContinued = isContinue;
}

bool TitleSelect::IsMouseContain(const Vector2& position)
{
	// ��`(�{�^��)�Ɠ_(�}�E�X)�̓����蔻��
	Vector2 mousePoint = Input::GetInstance()->GetMousePoint();
	if (position.x - Size.x / 2 <= mousePoint.x && mousePoint.x <= position.x + Size.x / 2
		&& position.y - Size.y / 2 <= mousePoint.y && mousePoint.y <= position.y + Size.y / 2)
	{
		return true;
	}
	return false;
}