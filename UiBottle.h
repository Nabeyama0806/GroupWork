#pragma once
#include "SpriteActor.h"
#include "Bottle.h"

class Player;

class UiBottle : public SpriteActor
{
private:
	static constexpr Vector3 SizeOffset = Vector3(0.07f, 0.07f, 0.07f);
	static constexpr Vector3 ScreenOffset = Vector3(-140, -140, 0);

	//画像のファイルパス
	const char* FilePath[static_cast<int>(Bottle::Type::Length)] =
	{
		"Resource/Texture/bottle_fire2.png",
		"Resource/Texture/bottle_thunder2.png",
		"Resource/Texture/bottle_water2.png",
		"Resource/Texture/bottle_wind2.png"
	};

	//画像の名前
	const char* TextureName[static_cast<int>(Bottle::Type::Length)] =
	{
		"Fire",
		"Thunder",
		"Water",
		"WInd"
	};

	Bottle::Type m_type;	//自身の属性
	int m_select;			//選択している属性

protected:
	virtual void Update() override;	//更新
	virtual void Draw() override;	//描画

public:
	//コンストラクタ
	UiBottle();

	//選択されているボトルの取得
	Bottle::Type GetType()
	{
		return m_type;
	}
};
