#pragma once
#include "SpriteActor.h"
#include "Vector3.h"

class Player;
class Camera;

class UiKeyItem : public SpriteActor
{
private:
	static constexpr Vector3 Offset = Vector3(-80, 80, 0);				//表示する座標
	static constexpr Vector3 Scale = Vector3(0.14f, 0.14f, 0.14f);		//表示する大きさ

	//表示する画像パターン
	enum class TextureType
	{
		None,
		Get,

		Length,
	};

	//画像のファイルパス
	const char* FilePath[static_cast<int>(TextureType::Length)] =
	{
		"Resource/Texture/uikey_none.png",
		"Resource/Texture/uikey_get.png",
	};

	//画像の名前
	const char* TextureName[static_cast<int>(TextureType::Length)] =
	{
		"None",
		"Get",
	};

	Player* m_player;
	Camera* m_camera;	//カメラ
	TextureType m_textureType;

protected:
	virtual void Update() override;		//更新
	virtual void Draw() override;		//描画

public:
	UiKeyItem(Player* player, Camera* camera);	//コンストラクタ
};