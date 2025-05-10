#pragma once
#include "Node.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Transform.h"
#include "ModelActor.h"

class Camera : public Node
{
private:
	static constexpr Vector3 SpawnPos = Vector3(0, 170, -400);
	static constexpr float CameraAngleSpeed = 0.1f;	//カメラの回転速度
	static constexpr float CameraScaling = 60;		//カメラの拡大率
	static constexpr float CameraNear = 10.0f;
	static constexpr float CameraFar = 1000000.0f;

	static constexpr float PlayerLookAtHeight = 50;			//注視点からの高さのオフセット
	static constexpr float StageLookAtHeight = 0;
	static constexpr float PlayerCameraDistance = 1.0f;		//カメラ座標までの距離
	static constexpr float MaxStageCameraDistance = 2000;
	static constexpr float MinStageCameraDistance = 1000;

	static constexpr float CameraMaxVAngle = 80.0f;		//カメラの縦回転の最大値
	static constexpr float CameraMinVAngle = -40.0f;	//カメラの縦回転の最小値

	static constexpr Vector3 StageCenter = Vector3(450, 750, 450);

	Transform* m_transform;		//姿勢情報
	ModelActor* m_lookAt;		//注視するオブジェクト
	Vector3 m_targetPos;		//注視点座標
	Vector3 m_cameraPos;		//カメラ座標
	Vector3 m_cameraAngle;		//カメラ角度

	float m_lookAtHeight;
	float m_cameraDistance;
	float m_stageCameraDistance;
	float m_cameraHAngle;		//横回転
	float m_cameraVAngle;		//縦回転

	bool m_isDisplayMouse;		//マウスカーソルの表示
	bool m_isPlayer;

	void MouseCamera();

protected:
	virtual void Update();	//更新
	virtual void Draw();	//描画

public:
	//コンストラクタ
	Camera() :
		m_transform(nullptr),
		m_lookAt(nullptr),
		m_lookAtHeight(0),
		m_cameraDistance(1500),
		m_stageCameraDistance(1500),
		m_cameraHAngle(0),
		m_cameraVAngle(0),
		m_isDisplayMouse(false),
		m_isPlayer(false)
	{
		m_transform = new Transform();
	}

	//注視点の取得
	void SetLookAt(ModelActor* actor, bool isPlayer)
	{
		m_lookAt = actor;
		m_lookAtHeight = isPlayer ? PlayerLookAtHeight : StageLookAtHeight;
		m_cameraDistance = isPlayer ? PlayerCameraDistance : m_stageCameraDistance;
		m_isPlayer = isPlayer;
	}

	bool GetIsPlayer()
	{
		return m_isPlayer;
	}

	float GetHAngle()
	{
		return m_cameraHAngle;
	}

	float GetVAngle()
	{
		return m_cameraVAngle;
	}

	Vector3 GetForward() const
	{
		return (m_targetPos - m_cameraPos).Normalized();
	}

	Vector3 GetRight() const
	{
		return Vector3::Cross(Vector3(0, 1, 0), GetForward()).Normalized();
	}

	Vector3 GetCameraPos() const
	{
		return m_cameraPos;
	}
};