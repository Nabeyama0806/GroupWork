#pragma once
#include "SceneBase.h"
#include "Transform.h"
#include "Sprite.h"
#include "PlayData.h"
#include "CreateMap.h"

class Node;

//�^�C�g���V�[��
class SceneTitle : public SceneBase
{
public:
	//�t�F�[�Y
	enum class Phase
	{
		ModeSelect,		//���[�h�̑I��
		OpenBook,		//�{���J��
		StageSelect,	//�X�e�[�W�̑I��
		GameStart,		//�Q�[���J�n

		Length,
	};

private:
	static constexpr Vector2 SelectButtonSize = Vector2(650, 150);	//���{�^���̑傫��
	static constexpr Vector2 ArrowButtonSize = Vector2(200, 300);	//�I���{�^���̑傫��
	
	static constexpr Vector2 LeftArrowButtonPos = Vector2(50, 540);		//�����{�^���̍��W
	static constexpr Vector2 RightArrowButtonPos = Vector2(1870, 540);	//�E���{�^���̍��W

	static constexpr Vector2 LeftSelectButtonPos = Vector2(350, 980);		//���I���{�^���̍��W
	static constexpr Vector2 RightSelectButtonPos = Vector2(1570, 980);		//�E�I���{�^���̍��W

	enum class TitleAnime
	{
		Open,
		Close,

		Length,
	};

	const char* TitleAnimeName[static_cast<int>(TitleAnime::Length)] =
	{
		"Open",
		"Close",
	};
	const SpriteAnimation TitleAnimeData[static_cast<int>(TitleAnime::Length)] =
	{
		SpriteAnimation("Resource/LoadBook/1920open_title.png", 12, 17, false),
		SpriteAnimation("Resource/LoadBook/1920close_title.png", 12, 17, false),
	};

	enum class SelectAnime
	{
		Prev,
		Next,
		FinishAnime,

		Length,
	};

	const char* SelectAnimeName[static_cast<int>(SelectAnime::Length)] =
	{
		"Prev",
		"Next",
		"End",
	};
	const SpriteAnimation SelectAnimeData[static_cast<int>(SelectAnime::Length)] =
	{
		SpriteAnimation("Resource/LoadBook/prev_page.png", 13, 17, false),
		SpriteAnimation("Resource/LoadBook/next_page.png", 13, 17, false),
		SpriteAnimation("Resource/LoadBook/end_page.png", 1, 16, false),
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
	Node* m_ModeSelectButtonNode;
	Node* m_StageSelectButtonNode;
	PlayData* m_playData;
	Sprite* m_sprite;
	Sprite* m_stageSprite;
	Phase m_phase;
	TitleAnime m_titleAnime;
	Transform m_transform;
	bool m_isReset;
	int m_stageNum;
	int m_bgm;

	void LeftArrowButton();		//�X�e�[�W�I��p�̍����{�^��
	void RightArrowButton();	//�X�e�[�W�I��p�̉E���{�^��

	void ContinueButton();		//�Â�����̃{�^��
	void NewGameButton();		//�͂��߂���̃{�^��

	void StartButton();			//�Q�[���X�^�[�g�̃{�^��	
	void BackButton();			//�߂�p�̃{�^��

protected:
	virtual void Initialize() override;		//������
	virtual void Finalize() override;		//�I��
	virtual SceneBase* Update() override;	//�X�V
	virtual void Draw() override;			//�`��

public:
	//�R���X�g���N�^
	SceneTitle() :
		m_phase(Phase::ModeSelect),
		m_titleAnime(TitleAnime::Open),
		m_isReset(false),
		m_rootNode(nullptr),
		m_ModeSelectButtonNode(nullptr),
		m_StageSelectButtonNode(nullptr),
		m_playData(nullptr),
		m_sprite(nullptr),
		m_stageSprite(nullptr),
		m_stageNum(0),
		m_bgm(0)
	{
		m_playData = new PlayData();
	}

	void SetPhase(Phase phase)
	{
		m_phase = phase;
	}
};