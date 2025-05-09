#include "UiBottle.h"
#include "FireBottle.h"
#include "ThunderBottle.h"
#include "WaterBottle.h"
#include "WindBottle.h"
#include "SoundManager.h"
#include "Sprite.h"
#include "Player.h"
#include "Camera.h"
#include "Input.h"

//コンストラクタ
UiBottle::UiBottle(Camera* camera) :
	SpriteActor("UiBottle"),
	m_camera(camera),
	m_type(Bottle::Type::Fire),
	m_select(0),
	m_crossDrawFlag(false),
	m_getBottleFlag(0),
	m_canWind(true)
{
	//画像の登録	
	m_sprite = new Sprite();
	m_nextImg = new Sprite();
	m_prevImg = new Sprite();
	for (int i = 0; i < static_cast<int>(Bottle::Type::Length); ++i)
	{
		m_sprite->Register(TextureName[i], SpriteAnimation(FilePath[i]));
		m_nextImg->Register(TextureName[i], SpriteAnimation(FilePath[i]));
		m_prevImg->Register(TextureName[i], SpriteAnimation(FilePath[i]));
	}
	m_nextImg->Load();
	m_prevImg->Load();

	m_sprite->Play(TextureName[m_select]);

	m_crossImg = new Sprite();
	m_crossImg->Register("Cross", SpriteAnimation("Resource/Texture/cross.png"));
	m_crossImg->Play("Cross");
	m_crossImg->Load();

	//サイズ調整
	m_transform.scale = SizeOffset;
	m_nextTransform.scale = SizeOffset / 2;
	m_prevTransform.scale = SizeOffset / 2;

	//表示する座標の調整
	m_transform.position = Screen::BottomRight + ScreenOffset;
	m_nextTransform.position = m_transform.position - SubBottleOffset;
	m_prevTransform.position = m_transform.position + SubBottleOffset;
}

//更新
void UiBottle::Update()
{
	if (!m_camera->GetIsPlayer()) return;
	//本来の更新
	SpriteActor::Update();

	//属性ビンの切り替え
	int mouseHweel = Input::GetInstance()->GetMouseHweelRot();

	if (mouseHweel != 0 && mouseHweel < 0 || Input::GetInstance()->IsPadDown(PAD_INPUT_5))
	{
		m_select == static_cast<int>(Bottle::Type::Length) - 1 ?
			m_select = static_cast<int>(Bottle::Type::Fire) :
			m_select++;
		SoundManager::Play("Resource/sound/se_bottle_select.mp3");
	}
	if (mouseHweel != 0 && mouseHweel > 0 || Input::GetInstance()->IsPadDown(PAD_INPUT_6))
	{
		m_select == static_cast<int>(Bottle::Type::Fire) ?
			m_select = static_cast<int>(Bottle::Type::Length) - 1 :
			m_select--;
		SoundManager::Play("Resource/sound/se_bottle_select.mp3");
	}
		

	m_type = static_cast<Bottle::Type>(m_select);
	m_sprite->Play(TextureName[m_select]);
	m_nextImg->Play(TextureName[SelectBottle(m_select + 1)]);
	m_prevImg->Play(TextureName[SelectBottle(m_select - 1)]);
	m_nextImg->Update();
	m_prevImg->Update();

	// ×を描画するかどうか
	m_crossDrawFlag = m_getBottleFlag & (1 << m_select);
	m_crossImg->Update();
}

//描画
void UiBottle::Draw()
{
	if (!m_camera->GetIsPlayer()) return;
	//本来の描画
	SpriteActor::Draw();
	m_nextImg->Draw(m_nextTransform);
	m_prevImg->Draw(m_prevTransform);

	//十字の描画
	if (!(m_getBottleFlag & (1 << m_select)) || m_select == static_cast<int>(Bottle::Type::Wind) && !m_canWind)
	{
		m_crossImg->Draw(m_transform);
	}
	if (!(m_getBottleFlag & (1 << SelectBottle(m_select + 1))) || SelectBottle(m_select + 1) == static_cast<int>(Bottle::Type::Wind) && !m_canWind)
	{
		m_crossImg->Draw(m_nextTransform);
	}
	if (!(m_getBottleFlag & (1 << SelectBottle(m_select - 1))) || SelectBottle(m_select - 1) == static_cast<int>(Bottle::Type::Wind) && !m_canWind)
	{
		m_crossImg->Draw(m_prevTransform);
	}
}
