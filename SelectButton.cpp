#include "SelectButton.h"
#include "SceneTitle.h"
#include "Input.h"
#include "DxLib.h"

//コンストラクタ
SelectButton::SelectButton(const char* textureName, const Vector2& size, const Vector2& position, std::function<void()> callbackFunction) :
	SpriteActor("SelectButton", textureName, position),
	m_button(size, MOUSE_INPUT_LEFT, callbackFunction)
{
}

//更新
void SelectButton::Update()
{
	//本来の処理
	SpriteActor::Update();

	//ボタンの更新
	m_button.Update(m_transform.position);
}

//描画
void SelectButton::Draw()
{
	//本来の処理
	SpriteActor::Draw();

	//ボタンの描画
	m_button.Draw(m_transform.position);
}