#include "TitleSelect.h"
#include "Input.h"
#include "Sprite.h"

//�R���X�g���N�^
TitleSelect::TitleSelect() :
	SpriteActor("TitleSelect"),
	m_selectType(SelectType::GameSelect),
	m_isContinued(true),
	m_isRight(false),
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
	m_buttonImg = new Sprite();
	for (int i = 0; i < static_cast<int>(SelectType::Length); ++i)
	{
		m_buttonImg->Register(SelectAnimeName[i], SelectAnimeData[i]);
	}
	m_buttonImg->Load();
}

//�X�V
void TitleSelect::Update()
{
	// �}�E�X�̑O�̃t���[���̏�Ԃ�ۑ�
	m_cursorPost = m_cursor;

	//�{���̍X�V
	SpriteActor::Update();
	m_buttonImg->Update();
	m_buttonImg->Play(SelectAnimeName[static_cast<int>(m_selectType)]);

	//���E�L�[�A�Q�[���p�b�h�ł̑���
	if (!IsMouseContain(NewGamePos, StartSize) && !IsMouseContain(ContinuePos, StartSize))
	{
		//�E�{�^���������ꂽ��O�̉�ʂɖ߂�
		if (Input::GetInstance()->StageSelectRight())
		{
			StageSelect(false);
			m_isKey = true;
		}

		//���{�^���������ꂽ��Q�[���J�n
		if (Input::GetInstance()->StageSelectLeft())
		{
			StageSelect(true);
			m_isKey = true;
		}

		if (m_cursorPost && !m_isKey) m_cursor = false;
	}
	//�}�E�X�J�[�\���̑���
	else
	{
		m_isKey = false;
		if (IsMouseContain(NewGamePos, StartSize))
		{
			StageSelect(true);
		}
		else if (IsMouseContain(ContinuePos, StartSize))
		{
			StageSelect(false);
		}
	}
}

//�`��
void TitleSelect::Draw()
{
	m_buttonImg->Draw(m_transform);
	if (m_cursor)
	{
		//�{���̕`��
		SpriteActor::Draw();
		m_sprite->Draw(m_transform);
	}

#ifdef _DEBUG
	switch (m_selectType)
	{
	case SelectType::GameSelect:
		DrawBox
		(
			static_cast<int>(NewGamePos.x - StartSize.x / 2), static_cast<int>(NewGamePos.y - StartSize.y / 2),
			static_cast<int>(NewGamePos.x + StartSize.x / 2), static_cast<int>(NewGamePos.y + StartSize.y / 2),
			GetColor(255, 0, 0), false
		);
		DrawBox
		(
			static_cast<int>(ContinuePos.x - StartSize.x / 2), static_cast<int>(ContinuePos.y - StartSize.y / 2),
			static_cast<int>(ContinuePos.x + StartSize.x / 2), static_cast<int>(ContinuePos.y + StartSize.y / 2),
			GetColor(255, 0, 0), false
		);
		break;

	case SelectType::StageSelect:
		DrawBox
		(
			static_cast<int>(RightPos.x - SelectSize.x / 2), static_cast<int>(RightPos.y - SelectSize.y / 2),
			static_cast<int>(RightPos.x + SelectSize.x / 2), static_cast<int>(RightPos.y + SelectSize.y / 2),
			GetColor(255, 0, 0), false
		);
		DrawBox
		(
			static_cast<int>(LeftPos.x - SelectSize.x / 2), static_cast<int>(LeftPos.y - SelectSize.y / 2),
			static_cast<int>(LeftPos.x + SelectSize.x / 2), static_cast<int>(LeftPos.y + SelectSize.y / 2),
			GetColor(255, 0, 0), false
		);
		break;
	}
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

bool TitleSelect::IsMouseContain(const Vector2& position, const Vector2& size)
{
	// ��`(�{�^��)�Ɠ_(�}�E�X)�̓����蔻��
	Vector2 mousePoint = Input::GetInstance()->GetMousePoint();
	if (position.x - size.x / 2 <= mousePoint.x && mousePoint.x <= position.x + size.x / 2
		&& position.y - size.y / 2 <= mousePoint.y && mousePoint.y <= position.y + size.y / 2)
	{
		return true;
	}
	return false;
}

bool TitleSelect::RightButton()
{
	if (Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT) && 
		IsMouseContain(RightPos, SelectSize))
	{
		return true;
	}

	return false;
}

bool TitleSelect::LeftButton()
{
	if (Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT) &&
		IsMouseContain(LeftPos, SelectSize))
	{
		return true;
	}
	return false;
}

bool TitleSelect::SelectButtonLeft()
{
	if (!Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT)) return false;

	//���{�^���������ꂽ��Q�[���J�n
	if (!IsMouseContain(NewGamePos, StartSize))
	{
		if (m_cursorPost && !m_isKey) m_cursor = false;
		if (Input::GetInstance()->StageSelectLeft())
		{
			return true;
		}
	}
	else if (IsMouseContain(NewGamePos, StartSize))
	{
		m_isKey = false;
		StageSelect(true);
		return true;
	}

	return false;
}

bool TitleSelect::SelectButtonRight()
{
	if (!Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT)) return false;

	//�E�{�^���������ꂽ��Q�[���J�n
	if (!IsMouseContain(ContinuePos, StartSize))
	{
		if (Input::GetInstance()->StageSelectLeft())
		{
			return true;
		}		
	}
	else if (IsMouseContain(ContinuePos, StartSize))
	{
		m_isKey = false;
		StageSelect(false);
		return true;
	}
	return false;
}