#include "Instructions.h"
#include "Sprite.h"
#include "Input.h"

Instructions::Instructions() :
SpriteActor("Instructions"),
m_isDraw(false)
{
	//姿勢情報
	m_transform.position = Screen::Center;

	//画像の登録
	m_sprite = new Sprite();
	for (int i = 0; i < static_cast<int>(Device::Length); ++i)
	{
		m_sprite->Register(TextureName[i], TextureData[i]);
	}
}

//更新
void Instructions::Update()
{
	//本来の更新
	SpriteActor::Update();

	//キーマウ
	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_TAB))
	{
		m_isDraw = !m_isDraw;
		m_sprite->Play(TextureName[static_cast<int>(Device::Keyboard)]);
	}

	//ゲームパッド
	if (Input::GetInstance()->IsPadDown(PAD_INPUT_8))
	{
		m_isDraw = !m_isDraw;
		m_sprite->Play(TextureName[static_cast<int>(Device::Gamepad)]);
	}
}

//描画
void Instructions::Draw()
{
	if (!m_isDraw) return;

	//本来の描画
	SpriteActor::Draw();
}