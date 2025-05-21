#include "Player.h"
#include "PlayerFoot.h"
#include "Instructions.h"
#include "Bottle.h"
#include "FireBottle.h"
#include "ThunderBottle.h"
#include "WaterBottle.h"
#include "WindBottle.h"
#include "UiBottle.h"
#include "Input.h"
#include "Time.h"
#include "SoundManager.h"
#include "BoxCollider.h"
#include "ModelLoader.h"
#include "ModelAnimation.h"
#include "CreateMap.h"
#include "Camera.h"

//コンストラクタ
Player::Player(Camera* camera, UiBottle* uiBottle, Instructions* instructions) :
	ModelActor("Player"),
	m_camera(camera),
	m_uiBottle(uiBottle),
	m_holdMove(0, 0, 0),
	m_isExistenceKey(false),
	m_getKey(false),
	m_canWindBottleThrow(true),
	m_onWallHit(false),
	m_isGoal(false),
	m_getBottleFlag(0),
	m_playerFoot(nullptr),
	m_instructions(instructions),
	m_map(nullptr)
{
	//姿勢情報の調整
	m_transform.scale = Scale;

	//モデル
	m_model = new Model("Resource/Model/Player.mv1");

	//衝突判定
	m_collider = new BoxCollider(ColliderSize);
	m_playerFoot = new PlayerFoot(this, m_transform.position);
	AddChild(m_playerFoot, false);
}

//更新
void Player::Update()
{
	//動きを封じる
	if (m_instructions->GetIsDraw() || m_isGoal) return;

	if (!m_camera->GetIsPlayer())
	{
		//本来の更新
		ModelActor::Update();
		return;
	}

	//移動
	Move();

	// 決定ボタンでボトルを生成
	if (Input::GetInstance()->NewBottle())
	{
		CreateBottle();
	}

	m_uiBottle->SetGetBottleFlag(m_getBottleFlag, m_canWindBottleThrow);

#ifdef _DEBUG
	if (Input::GetInstance()->IsKeyDown(KEY_INPUT_0)) m_isGoal = true;
#endif // _DEBUG

}

//指定されたボトルの作成
void Player::CreateBottle()
{
	if (m_uiBottle->GetType() == Bottle::Type::Wind && !m_canWindBottleThrow) return;
	if (!(m_getBottleFlag & (1 << static_cast<int>(m_uiBottle->GetType())))) return;

	switch (m_uiBottle->GetType())
	{
	case Bottle::Type::Fire:
		AddChild(new FireBottle(m_camera->GetCameraPos(), m_camera->GetForward(), this));
		break;

	case Bottle::Type::Thunder:
		AddChild(new ThunderBottle(m_camera->GetCameraPos(), m_camera->GetForward(), this));
		break;

	case Bottle::Type::Water:
		AddChild(new WaterBottle(m_camera->GetCameraPos(), m_camera->GetForward(), this));
		break;

	case Bottle::Type::Wind:
		AddChild(new WindBottle(m_camera->GetCameraPos(), m_camera->GetForward(), this));
		m_canWindBottleThrow = false;
		break;

	default:
		break;
	}

	SoundManager::Play("Resource/sound/se_bottle_create.mp3");
}

//移動
void Player::Move()
{
	//入力方向の取得
	Vector3 move = Vector3(0, 0, 0);
	if (Input::GetInstance()->MoveUp()) move.z = 1;
	if (Input::GetInstance()->MoveDown()) move.z = -1;
	if (Input::GetInstance()->MoveRight()) move.x = 1;
	if (Input::GetInstance()->MoveLeft()) move.x = -1;

	//カメラの正面ベクトルを作成
	Vector3 cameraForward = Vector3::Scale(m_camera->GetForward(), Vector3(1, 0, 1)).Normalized();

	//カメラの向きを考慮した移動量
	move = cameraForward * move.z + m_camera->GetRight() * move.x;

	//動いている時
	if (!move.IsZero())
	{
		//移動
		move.Normalize();
		m_holdMove = move * Speed;
		m_transform.position += m_holdMove;

		//回転
		m_transform.rotation = Quaternion::Slerp(
			m_transform.rotation,
			Quaternion::LookRotation(move),
			0.2f
		);
	}

	// 重力
	if (!m_playerFoot->GetIsGronded())
	{
		m_holdMove.y = GravityScale;
		m_transform.position.y -= m_holdMove.y;
	}
	
	//落下処理
	if (m_transform.position.y < FallEndPos)
	{
		m_getKey = false;
		m_map->LoadMap(false);
	}

	m_onWallHit = false;
}

void Player::Draw()
{
	if (!m_camera->GetIsPlayer())
	{
		//本来の更新
		ModelActor::Draw();
	}

#ifdef _DEBUG	
	// XYZの方向を描画
	// X
	DrawLine3D(
		VGet(m_transform.position.x, m_transform.position.y, m_transform.position.z),
		VGet(m_transform.position.x + 30, m_transform.position.y, m_transform.position.z),
		GetColor(255, 0, 0));

	// Y
	DrawLine3D(
		VGet(m_transform.position.x, m_transform.position.y, m_transform.position.z),
		VGet(m_transform.position.x, m_transform.position.y + 30, m_transform.position.z),
		GetColor(255, 255, 0));

	// Z
	DrawLine3D(
		VGet(m_transform.position.x, m_transform.position.y, m_transform.position.z),
		VGet(m_transform.position.x, m_transform.position.y, m_transform.position.z + 30),
		GetColor(0, 0, 255));
#endif
}

//衝突イベント
void Player::OnCollision(const ModelActor* other)
{
	//壁
	if (other->GetName() == "Wall" || other->GetName() == "Fire" || 
		other->GetName() == "KeyBlock")
	{

		// 壁のサイズ
		Vector3 colCenter = other->GetPosition();

		// プレイヤーが当たっている壁がどの方向か
		float distanceX = abs(colCenter.x - abs(m_transform.position.x - m_holdMove.x));
		float distanceZ = abs(colCenter.z - abs(m_transform.position.z - m_holdMove.z));
		distanceX > distanceZ ? 
			m_transform.position.x -= m_holdMove.x:
			m_transform.position.z -= m_holdMove.z;

		m_onWallHit = true;
		m_playerFoot->FollowPlayer();
	}

	if (other->GetName() == "Key")
	{
		m_getKey = true;
	}

	if (other->GetName() == "Goal")
	{
		m_isGoal = true;
	}
}