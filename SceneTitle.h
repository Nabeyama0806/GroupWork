#pragma once
#include "SceneBase.h"
#include "Transform.h"
#include "Sprite.h"
#include "PlayData.h"
#include "CreateMap.h"

class Node;
class TitleSelect;

//�^�C�g���V�[��
class SceneTitle : public SceneBase
{
private:
	//�t�F�[�Y
	enum class Phase
	{
		Run,			//���s��
		Start,			//�{���J��
		StageSelect,	//�X�e�[�W�̑I��

		Length,
	};

	enum class OpenAnime
	{
		First,		
		Second,		

		Length,
	};
	
	enum class SelectAnime
	{
		Prev,
		Next,
		FinishAnime,

		Length,
	};

	const char* OpenAnimeName [static_cast<int>(OpenAnime::Length)] =
	{
		"Initial",
		"Final",
	};
	const SpriteAnimation OpenAnimeDate[static_cast<int>(OpenAnime::Length)] =
	{
		SpriteAnimation("Resource/LoadBook/open1.png", 10, 20, false),
		SpriteAnimation("Resource/LoadBook/open2.png", 10, 17, false),
	};

	const char* SelectAnimeName[static_cast<int>(SelectAnime::Length)] =
	{
		"Prev",
		"Next",
		"End",
	};
	const SpriteAnimation SelectAnimeData[static_cast<int>(SelectAnime::Length)] =
	{
		SpriteAnimation("Resource/Book/page_prev.png", 13, 17, false),
		SpriteAnimation("Resource/Book/page_next.png", 13, 17, false),
		SpriteAnimation("Resource/LoadBook/0100.png", 1, 1, false),
	};

	const char* SelectStage[static_cast<int>(CreateMap::MapType::Length)] =
	{
		"Map0",
		"Map1",
		"Map2",
		"Map3",
		"Map4",
		"Map5",
		"Map6",
		"Map7",
		"Map8",
		"Map9",
	};
	const SpriteAnimation SelectStageData[static_cast<int>(CreateMap::MapType::Length)] =
	{
		SpriteAnimation("Resource/Texture/Map0.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map1.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map2.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map3.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map4.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map5.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map6.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map7.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map8.png", 1, 1, false),
		SpriteAnimation("Resource/Texture/Map9.png", 1, 1, false),
	};



	Node* m_rootNode;
	PlayData* m_playData;
	Sprite* m_sprite;
	Sprite* m_stageSprite;
	TitleSelect* m_select;
	Phase m_phase;
	OpenAnime m_openAnime;
	Transform m_transform;
	float m_elapsedTime;
	int m_stageNum;
	int m_bgm;

public:
	//�R���X�g���N�^
	SceneTitle() :
		m_phase(Phase::Run),
		m_openAnime(OpenAnime::First),
		m_rootNode(nullptr),
		m_playData(nullptr),
		m_sprite(nullptr),
		m_stageSprite(nullptr),
		m_select(nullptr),
		m_elapsedTime(1.0f),
		m_stageNum(0),
		m_bgm(0)
	{
		m_playData = new PlayData();
	}

	virtual void Initialize() override;				//������
	virtual void Finalize() override;				//�I��
	virtual SceneBase* Update() override;			//�X�V
	virtual void Draw() override;					//�`��
};