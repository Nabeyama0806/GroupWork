#include "UiKeyItem.h"
#include "Sprite.h"
#include "Player.h"
#include "Camera.h"
#include "Instructions.h"

//コンストラクタ
UiKeyItem::UiKeyItem(Player* player, Camera* camera, Instructions* instructions) :
	SpriteActor("UiKey"),
	m_player(player),
	m_camera(camera),
	m_instructions(instructions),
	m_textureType(TextureType::None)
{
	//姿勢情報
	m_transform.position = Screen::TopRight + Offset;
	m_transform.scale = Scale;

	//画像の登録
	m_sprite = new Sprite();
	for (int i = 0; i < static_cast<int>(TextureType::Length); ++i)
	{
		m_sprite->Register(TextureName[i], SpriteAnimation(FilePath[i]));
	}
	m_sprite->Play(TextureName[static_cast<int>(m_textureType)]);
}

//更新
void UiKeyItem::Update()
{
	//本来の更新
	SpriteActor::Update();

	//鍵の取得状況で表示する画像を切り替える
	m_textureType = m_player->GetIsKey() ? TextureType::Get : TextureType::None;
	m_sprite->Play(TextureName[static_cast<int>(m_textureType)]);
}

//描画
void UiKeyItem::Draw()
{
	//カメラがプレイヤーを注視していなければ描画しない
	if (!m_camera->GetIsPlayer()) return;

	//ステージに鍵が存在してなければ描画しない
	if (!m_player->GetIsExistenceKey()) return;

	//操作説明画面を表示していれば描画しない
	if (m_instructions->GetIsDraw()) return;

	//本来の描画
	SpriteActor::Draw();
}