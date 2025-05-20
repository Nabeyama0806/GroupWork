#pragma once
#include "SpriteActor.h"
#include "Sprite.h"
#include "Screen.h"

class TitleSelect : public SpriteActor
{
public:
	enum class SelectType
	{
		GameSelect,
		StageSelect,

		Length,
	};

private:
	const char* SelectAnimeName[static_cast<int>(SelectType::Length)] =
	{
		"GameSelect",
		"StageSelect",
	};
	const SpriteAnimation SelectAnimeData[static_cast<int>(SelectType::Length)] =
	{
		SpriteAnimation("Resource/Texture/save_select.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/start_select.png", 1, 1, false),
	};

	static constexpr Vector2 StartSize = Vector2(440, 100);		//�{�^���̃T�C�Y
	static constexpr Vector2 NewGamePos = Vector2(679, 618);	//�V�K�Q�[���̃{�^���̈ʒu
	static constexpr Vector2 ContinuePos = Vector2(1223, 618);	//�Â�����̃{�^���̈ʒu

	static constexpr Vector2 SelectSize = Vector2(131, 200);	//�I�������{�^���̃T�C�Y
	static constexpr Vector2 RightPos = Vector2(165, 385);	//�E�̃{�^���̈ʒu
	static constexpr Vector2 LeftPos = Vector2(1735, 385);	//���̃{�^���̈ʒu

	SelectType m_selectType;	//�I�������^�C�v
	Sprite* m_buttonImg;	//�{�^���̉摜

	bool m_isContinued;	//�Â�����
	bool m_isRight;		//�I����������
	bool m_isKey;		//�L�[�{�[�h�ł̑��삵�����ǂ���
	bool m_cursor;		//�}�E�X�J�[�\�����{�^���̏�ɂ��邩�ǂ���
	bool m_cursorPost;	//�O�t���[���̃}�E�X�J�[�\�����{�^���̏�ɂ��邩�ǂ���

	void StageSelect(bool isContinue);	//�X�e�[�W�I��

	bool IsMouseContain(const Vector2& position, const Vector2& size);

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

	void SetPhase(SelectType phase)
	{
		m_selectType = phase;
	}

	bool RightButton();

	bool LeftButton();

	bool SelectButtonLeft();

	bool SelectButtonRight();
};