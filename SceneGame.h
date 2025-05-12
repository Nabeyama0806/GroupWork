#pragma once
#include"SceneBase.h"
#include "ModelLoader.h"
#include "SoundLoader.h"
#include "Vector3.h"
#include <list>

//クラスの前方宣言
class Node;
class ModelActor;
class SpriteActor;
class CreateMap;
class UiBottle;
class Camera;
class Player;
class PlayData;

//ゲームシーン
class SceneGame : public SceneBase
{
private:
	static constexpr float ResultTransitionTime = 2.0f;	//プレイヤーが死んでからリザルト画面に遷移するまでの時間
	
	// 太陽の数値
	static constexpr Vector3 SunPosition = Vector3(1000, 1500, 0);
	static constexpr float SunRange = 20000.0f;
	static constexpr Vector3 SunAtten = Vector3(0.0f, 0.002f, 0.0f);

	//フェーズ
	enum class Phase
	{
		Run,		//実行中
		FadeOut,	//フェードアウト
		Transition,	//遷移
	};


	//モデルの事前読み込み
	const std::list<const char*> ModelPreload =
	{
		"Resource/Model/bottle_fire.mv1",
		"Resource/Model/bottle_thunder.mv1",
		"Resource/Model/bottle_water.mv1",
		"Resource/Model/bottle_wind.mv1",
	};

	Node* m_rootNode;		//ツリーノード
	PlayData* m_playData;
	ModelActor* m_stage;	// 背景ステージ
	CreateMap* m_map;
	UiBottle* m_uiBottle;	
	Camera* m_mainCamera;	//プレイヤー
	Player* m_player;		//プレイヤー
	Phase m_phase;
	Vector3 cameraPos = Vector3(0, 0, -700);

	bool m_isLookPlayer;

	float m_resultTransitionTime;
	int m_stageNum;
	int m_bgm;

public:
	//コンストラクタ
	SceneGame(PlayData* playData, int stageNum) :
		m_rootNode(nullptr), 
		m_playData(playData),
		m_stage(nullptr),
		m_map(nullptr),
		m_player(nullptr),
		m_phase(Phase::Run),
		m_mainCamera(nullptr),
		m_uiBottle(nullptr),
		m_isLookPlayer(true),
		m_resultTransitionTime(ResultTransitionTime),
		m_stageNum(stageNum),
		m_bgm(0)
	{
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