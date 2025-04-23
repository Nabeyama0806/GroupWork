#pragma once
#include "ModelActor.h"
#include "Model.h"
#include "GetBottle.h"
#include <vector>

class Camera;
class PlayerFoot;
class UiBottle;
class Bottle;

class Player : public ModelActor
{
private:
	static constexpr Vector3 Scale = Vector3(10.0f, 10.0f, 10.0f);	//自身のサイズ
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);	// コライダーのオフセット
	static constexpr Vector3 ColliderSize = Vector3(30.0f, 30.0f, 30.0f);	// コライダーのサイズ
	static constexpr float Speed = 0.6f * Scale.y;	//自身のサイズに合せた移動速度
	static constexpr float GravityScale = 13.0f;			// 重力
	static constexpr float DashSpeed = 1.4f;		//ダッシュ時の速度倍率
	static constexpr int AnimeAmount = 1;			//アニメーションの総数

	const char* AnimeFileName[AnimeAmount] =
	{
		"Resource/Model/Tmp.mv1",		//待機
	};

	Camera* m_camera;
	UiBottle* m_uiBottle;
	Vector3 m_holdMove;
	Vector3 m_spawnPos;			//スポーン地点
	PlayerFoot* m_playerFoot;	//プレイヤーの足

	bool m_createBottle;//ボトルが生きているかどうか
	bool m_onGround;	// 地面についているかどうか
	bool m_getKey;	// 鍵を持っているかどうか

	int m_getBottleFlag;	// ボトルを持っているかどうか

	void Move();			//移動処理
	void CreateBottle();	//指定されたボトルの作成

protected:
	virtual void Update() override;	//更新
	virtual void Draw() override;	// 描画

public:
	//コンストラクタ
	Player(Camera* camera, UiBottle* uiBottle);

	void GetElement(GetBottle::Type type)
	{
		m_getBottleFlag |= 1 << static_cast<int>(type);
	}

	// プレイヤーの位置を設定
	void SetPosition(Vector3 position)
	{
		m_spawnPos = position;
		m_transform.position = m_spawnPos;
	}

	bool IsGetKey() const 
	{
		return m_getKey;
	}

	void DestroyBottle() //ボトルを破棄する
	{
		m_createBottle = false;
	}	

	void SetCanWindBottleThrow()
	{
		m_getBottleFlag |= 1 << static_cast<int>(GetBottle::Type::Wind);
	}

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};