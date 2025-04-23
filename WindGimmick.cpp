#include "WindGimmick.h"
#include "SoundManager.h"
#include "Player.h"
#include "BoxCollider.h"
#include "Time.h"

//コンストラクタ
WindGimmick::WindGimmick(const Vector3& position, Player* player) :
	GimmickBase("Wind", position),
	m_elapsedTime(0)
{
	//エフェクト
	m_effect = new Effect("Resource/Effect/wind.efk", 10, 130);
	m_effectOffset = Vector3(0, -50, 0);

	//姿勢情報
	m_transform.position = SnapPosition(position + SpawnOffset);
	m_transform.scale = Scale;

	//衝突判定
	m_collider = new BoxCollider(ColliderSize);

	//プレイヤーの取得
	m_player = player;

	//効果音
	SoundManager::Play("Resource/sound/se_gimmick_wind.mp3");
}

//更新
void WindGimmick::Update()
{
	//本来の更新
	GimmickBase::Update();

	//時間経過で削除
	m_elapsedTime += Time::GetInstance()->GetDeltaTime();
	if (EffectDrawTime < m_elapsedTime)
	{
		m_player->SetCanWindBottleThrow();
		Destroy();
	}
}

//効果の発動
void WindGimmick::Active()
{
	//風エフェクトの表示
	m_effect->Play();
}

Vector3 WindGimmick::SnapPosition(const Vector3& playerPos)
{
	//一マスのサイズ
	const int TileSize = 100;

	//小数点を省く
	Vector3 position;
	int posX = static_cast<int>(playerPos.x);
	int posY = static_cast<int>(playerPos.y);
	int posZ = static_cast<int>(playerPos.z);

	//接触したマス目の座標を算出
	position.x = static_cast<float>(posX % TileSize > 50 ? posX / TileSize * TileSize + TileSize : posX / TileSize * TileSize);
	position.y = static_cast<float>(posY / TileSize * TileSize);
	position.z = static_cast<float>(posZ % TileSize > 50 ? posZ / TileSize * TileSize + TileSize : posZ / TileSize * TileSize);
	
	return position;
}