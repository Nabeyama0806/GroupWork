#include "Player.h"
#include "Bottle.h"
#include "FireBottle.h"
#include "ThunderBottle.h"
#include "WaterBottle.h"
#include "WindBottle.h"
#include "UiBottle.h"
#include "Input.h"
#include "Time.h"
#include "Quaternion.h"
#include "SoundManager.h"
#include "BoxCollider.h"
#include "ModelLoader.h"
#include "ModelAnimation.h"

//コンストラクタ
Player::Player(Camera* camera, UiBottle* uiBottle) :
	ModelActor("Player"),
	m_camera(camera),
	m_uiBottle(uiBottle),
	m_createBottle(false),
	m_onGround(false),
	m_onWall(false),
	m_holdMove(0,0,0)
{
	//アニメーションの登録
	m_model = new Model("Man/Player.mv1");
	for (int i = 0; i < AnimeAmount; ++i)
	{
		//アニメーションのファイルパスを渡す
		m_model->Register(AnimeFileName[i]);
	}

	//姿勢情報の調整
	m_transform.position = SpawnPos;
	m_transform.scale = Scale;

	//衝突判定
	Vector3 colliderScale = ColliderSize * Scale.x;
	m_collider = new BoxCollider(colliderScale);
}

//更新
void Player::Update()
{

	if (!m_camera->GetIsPlayer())
	{
		//本来の更新
		ModelActor::Update();
		return;
	}

	//移動
	Move();

	//左クリックでボトルを生成
	if (Input::GetInstance()->IsMouseDown(MOUSE_INPUT_LEFT))
	{
		CreateBottle();
	}

	// 地面と壁との当たり判定のリセット
	m_onGround = false;
	m_onWall = false;
}

//指定されたボトルの作成
void Player::CreateBottle()
{
	if (m_createBottle) return;

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
		break;

	default:
		break;
	}

	m_createBottle = true;
	SoundManager::GetInstance()->SoundPlay("sound/se_bottle_create.mp3");
}

//移動
void Player::Move()
{
	//入力方向の取得
	Vector3 move = Vector3(0, 0, 0);
	float speedRate = 1.0f;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_LSHIFT))	speedRate = DashSpeed;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_W)) move.z = 1;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_S)) move.z = -1;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_D)) move.x = 1;
	if (Input::GetInstance()->IsKeyPress(KEY_INPUT_A)) move.x = -1;

	//カメラの正面ベクトルを作成
	Vector3 cameraForward = Vector3::Scale(m_camera->GetForward(), Vector3(1, 0, 1)).Normalized();

	//カメラの向きを考慮した移動量
	move = cameraForward * move.z + m_camera->GetRight() * move.x;

	//待機アニメーションを設定
	int animeIndex = static_cast<int>(Model::Anime::Idle);

	//動いている時
	if (!move.IsZero())
	{
		//移動
		move.Normalize();
		m_holdMove = move * Speed * speedRate;
		m_transform.position += m_holdMove;

		//回転
		m_transform.rotation = Quaternion::Slerp(
			m_transform.rotation,
			Quaternion::LookRotation(move),
			0.2f);

		//移動アニメーションを設定
		//animeIndex = static_cast<int>(Model::Anime::Run);
	}

	// 重力
	if (!m_onGround)
	{
		m_transform.position.y -= GravityScale;
		m_holdMove.y = 0;
		m_holdMove.y -= GravityScale;
	}

	if (m_transform.position.y < -500)
	{
		m_transform.position = SpawnPos;
	}

	//設定したアニメーションの再生
	//m_model->PlayAnime(animeIndex);
}

void Player::Draw()
{
	if (!m_camera->GetIsPlayer())
	{
		//本来の更新
		ModelActor::Draw();
	}

#ifdef _DEBUG	
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

void Player::DestroyBottle()
{
	m_createBottle = false;
}

//衝突イベント
void Player::OnCollision(const ModelActor* other)
{
	//壁
	if (other->GetName() == "Wall")
	{

		m_onWall = true;
		// 壁のサイズ
		Vector3 colSize = other->GetCollider()->GetSize(other->GetCollider());
		Vector3 colCenter = other->GetPosition();
		
		float yRatio = 0.6f;
		float xRatio = colSize.z / colSize.x;

		float distanceX = abs(colCenter.x - abs(m_transform.position.x - m_holdMove.x));
		float distanceY = abs(colCenter.y - abs(m_transform.position.y - m_holdMove.y));
		float distanceZ = abs(colCenter.z - abs(m_transform.position.z - m_holdMove.z));

		// プレイヤーが当たっている壁がどの方向か
		if (distanceX > distanceY && distanceX > distanceZ)			
		{
			m_transform.position.x -= m_holdMove.x;	// 動いた分戻す
		}
		else if (distanceY > distanceZ)
		{
			m_transform.position.y -= m_holdMove.y;	// 動いた分戻す
		}
		else
		{
			m_transform.position.z -= m_holdMove.z;	// 動いた分戻す
		}
	}

	if (other->GetName() == "Wind" || other->GetName() == "Water")
	{
		m_onGround = true;
		m_transform.position.y += GravityScale;
	}
}