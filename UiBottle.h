#pragma once
#include "SpriteActor.h"
#include "Bottle.h"

class UiBottle : public SpriteActor
{
private:
	static constexpr Vector3 SizeOffset = Vector3(0.05f, 0.05f, 0.05f);
	static constexpr Vector3 ScreenOffset = Vector3(-100, -70, 0);

	//画像のファイルパス
	const char* FilePath[static_cast<int>(Bottle::Type::Length)] =
	{
		"Resource/bottle_fire.png",
		"Resource/bottle_thunder.png",
		"Resource/bottle_water.png",
		"Resource/bottle_wind.png"
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
	UiBottle(Vector3 position);
};
