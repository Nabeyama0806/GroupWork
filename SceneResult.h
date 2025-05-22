#pragma once
#include "SceneBase.h"
#include "Transform.h"
#include "Screen.h"
#include "Sprite.h"

class Node;
class Sprite;

class SceneResult : public SceneBase
{
private:
	enum class ClearAnime
	{
		First,
		Second,

		Length,
	};

	const char* ClearAnimeName[static_cast<int>(ClearAnime::Length)] =
	{
		"Initial",
		"Final",
	};
	const SpriteAnimation ClearAnimeDate[static_cast<int>(ClearAnime::Length)] =
	{
		SpriteAnimation("Resource/LoadBook/1920clear_anime1.png", 13, 10, false),
		SpriteAnimation("Resource/LoadBook/1920clear_anime2.png", 13, 10, false),
	};

	static constexpr float WaitTransitionTime = 1.5f;

	Node* m_rootNode;
	Sprite* m_sprite;
	ClearAnime m_clearAnime;
	Transform m_transform;
	int m_score;

	float m_waitTransitionTime;

public:
	//コンストラクタ
	SceneResult(int score) :
		m_rootNode(nullptr),
		m_sprite(nullptr),
		m_clearAnime(ClearAnime::First),
		m_score(score),
		m_waitTransitionTime(WaitTransitionTime)
	{
		m_transform.position = Screen::Center;
	}

	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual SceneBase* Update() override;
	virtual void Draw() override;
};