#pragma once
#include "ModelActor.h"
#include "Model.h"
#include "GetBottle.h"
#include "PlayerFoot.h"
#include <vector>

class Camera;
class UiBottle;
class Bottle;
class CreateMap;
class Instructions;

class Player : public ModelActor
{
private:
	static constexpr Vector3 Scale = Vector3(10.0f, 10.0f, 10.0f);	//自身のサイズ
	static constexpr Vector3 ColliderOffset = Vector3(0, 0, 0);	// コライダーのオフセット
	static constexpr Vector3 ColliderSize = Vector3(30, 30, 30);	// コライダーのサイズ
	static constexpr float Speed = 0.5f * Scale.y;	//自身のサイズに合せた移動速度
	static constexpr float GravityScale = 13.0f;	// 重力
	static constexpr float DashSpeed = 1.4f;		//ダッシュ時の速度倍率
	static constexpr int AnimeAmount = 1;			//アニメーションの総数
	static constexpr int FallEndPos = -500;			// 落下したときのリスポーンする値

	static constexpr float PlayerSpeed = 0.85f;	// プレイヤーの移動速度

	Camera* m_camera;
	PlayerFoot* m_playerFoot;	//プレイヤーの足
	UiBottle* m_uiBottle;
	Vector3 m_holdMove;
	Vector3 m_spawnPos;			//スポーン地点
	CreateMap* m_map;			//マップ
	Instructions* m_instructions;

	bool m_onWallHit;			// 壁と接触しているか
	bool m_isExistenceKey;		// ステージに鍵が存在しているかどうか
	bool m_getKey;				// 鍵を持っているかどうか
	bool m_canWindBottleThrow;	// 風ボトルを投げられるかどうか
	bool m_isGoal;				// 現在のステージをクリアしたかどうか

	int m_getBottleFlag;	// ボトルを持っているかどうか

	void Move(bool canMove);			//移動処理
	void CreateBottle();	//指定されたボトルの作成

protected:
	virtual void Update() override;	//更新
	virtual void Draw() override;	// 描画

public:
	//コンストラクタ
	Player(Camera* camera, UiBottle* uiBottle, Instructions* instructions);

	void SetElement(GetBottle::Type type)
	{
		m_getBottleFlag |= 1 << static_cast<int>(type);
	}
	void SetElement(int bottleBit)
	{
		m_getBottleFlag = bottleBit;
	}
	int GetElement() const
	{
		return m_getBottleFlag;
	}

	void SetSpawnPosition(const Vector3& position)
	{
		m_spawnPos = position;
		m_transform.position = position;
		m_playerFoot->SetPosition(position);
	}

	// プレイヤーの位置を設定
	void SetPosition(Vector3 position)
	{
		m_transform.position = position;
	}

	void SetMap(CreateMap* map)
	{
		m_map = map;
	}

	void UseKey()
	{
		m_getKey = false;
	}
	bool GetIsKey() const 
	{
		return m_getKey;
	}

	void SetCanWindBottleThrow()
	{
		m_canWindBottleThrow = true;
	}

	Vector3& GetHoldMove()
	{
		return m_holdMove;
	}

	bool GetOnWallHit() const
	{
		return m_onWallHit;
	}

	bool GetIsGoal() const
	{
		return m_isGoal;
	}
	void SetIsGoal()
	{
		m_isGoal = false;
	}

	const Vector3& GetSpawnPos() const 
	{
		return m_spawnPos;
	}

	bool GetIsExistenceKey()
	{
		return m_isExistenceKey;
	}
	void SetIsExistenceKey(bool flag)
	{
		m_isExistenceKey = flag;
	}

	//衝突イベント
	virtual void OnCollision(const ModelActor* other) override;
};