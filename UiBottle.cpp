#include "UiBottle.h"
#include "FireBottle.h"
#include "ThunderBottle.h"
#include "WaterBottle.h"
#include "WindBottle.h"
#include "SoundManager.h"
#include "Sprite.h"
#include "Player.h"
#include "Input.h"

//コンストラクタ
UiBottle::UiBottle() :
	SpriteActor("UiBottle"),
	m_type(Bottle::Type::Fire),
	m_select(0),
	m_crossDrawFlag(false),
	m_getBottleFlag(0),
	m_canWind(true)
{	
	//画像の登録	
	m_sprite = new Sprite();
	for (int i = 0; i < static_cast<int>(Bottle::Type::Length); ++i)
	{
		m_sprite->Register(TextureName[i], SpriteAnimation(FilePath[i]));
	}
	m_sprite->Play(TextureName[m_select]);

	m_crossImg = new Sprite();
	m_crossImg->Register("Cross", SpriteAnimation("Resource/Texture/cross.png"));
	m_crossImg->Play("Cross");
	m_crossImg->Load();

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
	int mouseHweel = Input::GetInstance()->GetMouseHweelRot();
	if (mouseHweel != 0)
	{
		if (mouseHweel < 0)
		{
			m_select == static_cast<int>(Bottle::Type::Length) - 1 ?
				m_select = static_cast<int>(Bottle::Type::Fire) :
				m_select++;
		}
		if (mouseHweel > 0)
		{
			m_select == static_cast<int>(Bottle::Type::Fire) ?
				m_select = static_cast<int>(Bottle::Type::Length) - 1 :
				m_select--;
		}
		SoundManager::Play("Resource/sound/se_bottle_select.mp3");
	}

	m_type = static_cast<Bottle::Type>(m_select);
	m_sprite->Play(TextureName[m_select]);

	// ×を描画するかどうか
	m_crossDrawFlag = m_getBottleFlag & (1 << m_select);
	m_crossImg->Update();
}

//描画
void UiBottle::Draw()
{
	//本来の描画
	SpriteActor::Draw();

	//十字の描画
	if (!m_crossDrawFlag || m_select == static_cast<int>(Bottle::Type::Wind) && !m_canWind ||
		m_createBottle)
	{
		m_crossImg->Draw(m_transform);
	}
}