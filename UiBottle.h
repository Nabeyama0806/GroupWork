#pragma once
#include "SpriteActor.h"
#include "Bottle.h"

class Player;
class Camera;
class Instructions;

class UiBottle : public SpriteActor
{
private:
	static constexpr Vector3 SizeOffset = Vector3(0.07f, 0.07f, 0.07f);
	static constexpr Vector3 ScreenOffset = Vector3(-140, -140, 0);
	static constexpr Vector3 SubBottleOffset = Vector3(110, 0, 0);	//次と前の属性の位置オフセット

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

	Sprite* m_crossImg;	// 使用不可時の画像
	Sprite* m_nextImg;	//次の属性の画像
	Sprite* m_prevImg;	//前の属性の画像
	Instructions* m_instructions;
	Transform m_nextTransform;	//次の属性の位置
	Transform m_prevTransform;	//前の属性の位置

	Camera* m_camera;
	Bottle::Type m_type;	//自身の属性
	int m_select;			//選択している属性
	int m_getBottleFlag;	//ボトルを持っているかどうか
	bool m_crossDrawFlag;	//十字の描画フラグ
	bool m_canWind;			// 風瓶を投げれるかどうか

	int SelectBottle(int select)
	{
		int bottleNum = select;
		if (bottleNum > static_cast<int>(Bottle::Type::Length) - 1) bottleNum = static_cast<int>(Bottle::Type::Fire);
		else if (bottleNum < static_cast<int>(Bottle::Type::Fire)) bottleNum = static_cast<int>(Bottle::Type::Length) - 1;
		return bottleNum;
	};

protected:
	virtual void Update() override;	//更新
	virtual void Draw() override;	//描画

public:
	//コンストラクタ
	UiBottle(Camera* camera, Instructions* instructions);

	//選択されているボトルの取得
	Bottle::Type GetType()
	{
		return m_type;
	}

	void SetGetBottleFlag(int getBottleFlag, bool canWind)
	{
		m_getBottleFlag = getBottleFlag;
		m_canWind = canWind;
	}
};
