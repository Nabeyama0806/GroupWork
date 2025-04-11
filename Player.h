#pragma once
#include "ModelActor.h"
#include "Model.h"
#include "Vector3.h"
#include "Camera.h"
#include <vector>

class Camera;
class UiBottle;
class Bottle;

class Player : public ModelActor
{
private:
	static constexpr Vector3 SpawnPos = Vector3(0, 200, 400);	//開始時の座標
	static constexpr Vector3 Scale = Vector3(20.0f, 20.0f, 20.0f);	//自身のサイズ
	static constexpr Vector3 ColliderOffset = Vector3(0, 2, 0);	// コライダーのオフセット
	static constexpr Vector3 ColliderSize = Vector3(3.0f, 5.0f, 3.0f);	// コライダーのサイズ
	static constexpr float Speed = 0.6f * Scale.y;	//自身のサイズに合せた移動速度
	static constexpr float GravityScale = 13.0f;			// 重力
	static constexpr float DashSpeed = 1.4f;		//ダッシュ時の速度倍率
	static constexpr int AnimeAmount = 1;			//アニメーションの総数

	const char* AnimeFileName[AnimeAmount] =
	{
		"Man/Tmp.mv1",		//待機
	};

	Camera* m_camera;
	UiBottle* m_uiBottle;
	Vector3 m_holdMove;

	bool m_createBottle;//ボトルが生きているかどうか
	bool m_onGround;	// 地面についているかどうか
	bool m_onWall;		// 壁に当たっているかどうか

	void Move();			//移動処理
	void CreateBottle();	//指定されたボトルの作成

protected:
	virtual void Update() override;	//更新
	virtual void Draw() override;	// 描画

public:
	//コンストラクタ
	Player(Camera* camera, UiBottle* uiBottle);

	void DestroyBottle();	//ボトルを破棄する

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};