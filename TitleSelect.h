#pragma once
#include "SpriteActor.h"
#include "Screen.h"

class TitleSelect : public SpriteActor
{
private:
	static constexpr Vector2 Size = Vector2(440, 100);	//�{�^���̃T�C�Y
	static constexpr Vector2 NewGamePos = Vector2(679, 618);	//�V�K�Q�[���̃{�^���̈ʒu
	static constexpr Vector2 ContinuePos = Vector2(1223, 618);	//�Â�����̃{�^���̈ʒu

	bool m_isContinued;	//�Â�����

	bool m_isKey;		//�L�[�{�[�h�ł̑��삵�����ǂ���
	bool m_cursor;		//�}�E�X�J�[�\�����{�^���̏�ɂ��邩�ǂ���
	bool m_cursorPost;	//�O�t���[���̃}�E�X�J�[�\�����{�^���̏�ɂ��邩�ǂ���

	void StageSelect(bool isContinue);	//�X�e�[�W�I��

	bool IsMouseContain(const Vector2& position);

protected:
	virtual void Update() override;
	virtual void Draw() override;

public:
	//�R���X�g���N�^
	TitleSelect();

	bool GetIsContinued()
	{
		return m_isContinued;
	}

	bool GetOnCursor()
	{
		return m_cursor;
	}

	bool GetIsKey()
	{
		return m_isKey;
	}
};