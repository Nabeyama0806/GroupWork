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

	static constexpr Vector2 StartSize = Vector2(440, 100);		//ボタンのサイズ
	static constexpr Vector2 NewGamePos = Vector2(679, 618);	//新規ゲームのボタンの位置
	static constexpr Vector2 ContinuePos = Vector2(1223, 618);	//つづきからのボタンの位置

	static constexpr Vector2 SelectSize = Vector2(131, 200);	//選択したボタンのサイズ
	static constexpr Vector2 RightPos = Vector2(165, 385);	//右のボタンの位置
	static constexpr Vector2 LeftPos = Vector2(1735, 385);	//左のボタンの位置

	SelectType m_selectType;	//選択したタイプ
	Sprite* m_buttonImg;	//ボタンの画像

	bool m_isContinued;	//つづきから
	bool m_isRight;		//選択した方向
	bool m_isKey;		//キーボードでの操作したかどうか
	bool m_cursor;		//マウスカーソルがボタンの上にあるかどうか
	bool m_cursorPost;	//前フレームのマウスカーソルがボタンの上にあるかどうか

	void StageSelect(bool isContinue);	//ステージ選択

	bool IsMouseContain(const Vector2& position, const Vector2& size);

protected:
	virtual void Update() override;
	virtual void Draw() override;

public:
	//コンストラクタ
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