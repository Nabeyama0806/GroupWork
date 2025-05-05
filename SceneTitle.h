#pragma once
#include "SceneBase.h"
#include "Node.h"
#include "Transform.h"

class Node;
class Sprite;

//タイトルシーン
class SceneTitle : public SceneBase
{
private:
	//フェーズ
	enum class Phase
	{
		Run,		//実行中
		OpenBook,	//本を開く
	};

	Node* m_rootNode;
	Phase m_phase;
	Sprite* m_sprite;
	Transform m_transform;
	int m_bgm;

public:
	//コンストラクタ
	SceneTitle() :
		m_rootNode(nullptr),
		m_phase(Phase::Run),
		m_sprite(nullptr),
		m_bgm(0){}

	virtual void Initialize() override;				//初期化
	virtual void Finalize() override;				//終了
	virtual SceneBase* Update() override;			//更新
	virtual void Draw() override;					//描画
};