#include "TitleSelect.h"
#include "Input.h"
#include "Sprite.h"

//コンストラクタ
TitleSelect::TitleSelect() : 
	SpriteActor("TitleSelect"),
	m_isContinued(true)
{
	//姿勢情報
	m_transform.position = Screen::Center;

	//画像の登録
	m_sprite = new Sprite();
	m_sprite->Register("Resource/Texture/select_cursor.png");

	//選択用のボタン
	AddChild(new SpriteActor("Select", "Resource/Texture/select.png", Screen::Center));
}

//更新
void TitleSelect::Update()
{
	//本来の更新
	SpriteActor::Update();

	//モード選択
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