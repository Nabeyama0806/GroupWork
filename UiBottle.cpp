#include "UiBottle.h"
#include "FireBottle.h"
#include "ThunderBottle.h"
#include "WaterBottle.h"
#include "WindBottle.h"
#include "Sprite.h"
#include "Player.h"
#include "Input.h"

//コンストラクタ
UiBottle::UiBottle(Player* player) :
	SpriteActor("UiBottle"),
	m_type(Bottle::Type::Fire),
	m_select(0),
	m_player(player)
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
	if (Input::GetInstance()->GetMouseHweelRot())
	{
		//インデックスを超えると先頭要素に戻す
		m_select == static_cast<int>(Bottle::Type::Length) - 1 ?
			m_select = static_cast<int>(Bottle::Type::Fire) :
			m_select++;

		m_sprite->Play(TextureName[m_select]);
	}

	//左クリックでボトルを生成
	if (Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT))
	{
		AddChild(new ThunderBottle(m_player->GetPosition()));
	}
}

//描画
void UiBottle::Draw()
{
	//本来の描画
	SpriteActor::Draw();
}