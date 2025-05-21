#pragma once
#include "SpriteActor.h"
#include "SpriteAnimation.h"

class Instructions : public SpriteActor
{
public:
	enum class Device
	{
		Keyboard,
		Gamepad,

		Length,
	};

private:
	//画像配列
	const char* TextureName[static_cast<int>(Device::Length)] =
	{
		"Keyboard",
		"Gamepad",
	};
	const SpriteAnimation TextureData[static_cast<int>(Device::Length)] =
	{
		SpriteAnimation("Resource/Texture/tutorial1.jpg", 1, 1, true),
		SpriteAnimation("Resource/Texture/tutorial2.jpg", 1, 1, true),
	};

	bool m_isDraw; //表示中かどうか

protected:
	virtual void Update() override;		//更新
	virtual void Draw() override;		//描画

public:
	//コンストラクタ
	Instructions();

	bool GetIsDraw()
	{
		return m_isDraw;
	}
};
