#pragma once
#include "SceneBase.h"
#include "Transform.h"
#include "Sprite.h"
#include "PlayData.h"

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

	enum class Anime
	{
		Initial,	//�J�n
		Final,		//�I���

		Length,
	};

	//�A�j����
	const char* AnimeName[static_cast<int>(Anime::Length)] =
	{
		"Initial",
		"Final",
	};
		
	//�A�j���̃t�@�C���p�X
	const SpriteAnimation AnimeDate[static_cast<int>(Anime::Length)] =
	{
		SpriteAnimation("Resource/LoadBook/open1.png", 10, 20, false),
		SpriteAnimation("Resource/LoadBook/open2.png", 10, 17, false),
	};

	Node* m_rootNode;
	PlayData* m_playData;
	Sprite* m_sprite;
	TitleSelect* m_select;
	Phase m_phase;
	Anime m_anime;
	Transform m_transform;
	int m_bgm;

public:
	//�R���X�g���N�^
	SceneTitle() :
		m_phase(Phase::Run),
		m_anime(Anime::Initial),
		m_rootNode(nullptr),
		m_playData(nullptr),
		m_sprite(nullptr),
		m_select(nullptr),
		m_bgm(0)
	{
		m_playData = new PlayData();
	}

	virtual void Initialize() override;				//������
	virtual void Finalize() override;				//�I��
	virtual SceneBase* Update() override;			//�X�V
	virtual void Draw() override;					//�`��
};