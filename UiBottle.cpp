#include "UiBottle.h"
#include "Sprite.h"
#include "Input.h"

//コンストラクタ
UiBottle::UiBottle(Vector3 position) :
	SpriteActor("UiBottle", nullptr, position),
	m_type(Bottle::Type::Fire),
	m_select(0)
{	
	//画像の登録	
	m_sprite = new Sprite();
	for (int i = 0; i < static_cast<int>(Bottle::Type::Length); ++i)
	{
		m_sprite->Register(TextureName[i], SpriteAnimation(FilePath[i]));
	}
	m_sprite->Play(TextureName[m_select]);

	//サイズ調整
	m_transform.scale = SizeOffset;

	//表示する座標の調整
	m_transform.position = Screen::BottomRight + ScreenOffset;
}

//更新
void UiBottle::Update()
{
	//本来の更新
	SpriteActor::Update();

	//属性ビンの切り替え
	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_RIGHT))
	{
		//インデックスを超えると先頭要素に戻す
		m_select == static_cast<int>(Bottle::Type::Length) - 1 ?
			m_select = static_cast<int>(Bottle::Type::Fire) :
			m_select++;

		m_sprite->Play(TextureName[m_select]);
	}
	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_LEFT))
	{
		//インデックスを超えると先頭要素に戻す
		m_select == static_cast<int>(Bottle::Type::Fire) ?
			m_select = static_cast<int>(Bottle::Type::Length) - 1 :
			m_select--;

		m_sprite->Play(TextureName[m_select]);
	}
}

//描画
void UiBottle::Draw()
{
	//本来の描画
	SpriteActor::Draw();
}