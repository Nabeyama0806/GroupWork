#pragma once
#include"SceneBase.h"
#include "ModelLoader.h"
#include "SpriteLoader.h"
#include "SoundLoader.h"
#include "Vector3.h"
#include <list>

//クラスの前方宣言
class Node;
class ModelActor;
class Player;
class Camera;
class SpriteActor;
class UiBottle;

//ゲームシーン
class SceneGame : public SceneBase
{
private:
	const std::list<const char*> SpritePreload =
	{
		//特になし
	};

	const std::list<const char*> ModelPreload =
	{
		"Resource/Model/bottle_fire.mv1",
		"Resource/Model/bottle_thunder.mv1",
		"Resource/Model/bottle_water.mv1",
		"Resource/Model/bottle_wind.mv1",
	};

	static constexpr float ResultTransitionTime = 2.0f;	//プレイヤーが死んでからリザルト画面に遷移するまでの時間
	Node* m_rootNode;	//ツリーノード
	ModelActor* m_stage;	// 背景ステージ
	Player* m_player;	//プレイヤー
	Camera* m_mainCamera;	//プレイヤー
	SpriteActor* m_tmpUi;	// 仮置きのUI
	UiBottle* m_uiBottle;	

	Vector3 cameraPos = Vector3(0, 0, -700);

	bool m_isLookPlayer;

	float m_resultTransitionTime;
	int m_bgm;
public:
	//コンストラクタ
	SceneGame() :
		m_rootNode(nullptr), 
		m_stage(nullptr),
		m_player(nullptr),
		m_mainCamera(nullptr),
		m_tmpUi(nullptr),
		m_uiBottle(nullptr),
		m_isLookPlayer(true),
		m_resultTransitionTime(ResultTransitionTime),
		m_bgm(0)
	{
		//画像の事前読み込み
		for (auto sprite : SpritePreload)
		{
			SpriteLoader::GetInstance()->Load(sprite);
		}

		//モデルの事前読み込み
		for (auto model : ModelPreload)
		{
			ModelLoader::GetInstance()->Load(model);
		}
	}

	virtual void Initialize() override;		//初期化
	virtual void Finalize() override;		//終了
	virtual SceneBase* Update() override;	//更新
	virtual void Draw() override;			//描画
};