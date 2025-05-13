#pragma once
#include "SpriteActor.h"
#include "Screen.h"

class TitleSelect : public SpriteActor
{
private:
	static constexpr Vector2 Size = Vector2(440, 100);	//ボタンのサイズ
	static constexpr Vector2 NewGamePos = Vector2(679, 618);	//新規ゲームのボタンの位置
	static constexpr Vector2 ContinuePos = Vector2(1223, 618);	//つづきからのボタンの位置

	bool m_isContinued;	//つづきから

	bool m_isKey;		//キーボードでの操作したかどうか
	bool m_cursor;		//マウスカーソルがボタンの上にあるかどうか
	bool m_cursorPost;	//前フレームのマウスカーソルがボタンの上にあるかどうか

	void StageSelect(bool isContinue);	//ステージ選択

	bool IsMouseContain(const Vector2& position);

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
};