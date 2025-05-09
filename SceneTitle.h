#pragma once
#include "SceneBase.h"
#include "Transform.h"
#include "Sprite.h"

class Node;
class TitleSelect;

//�^�C�g���V�[��
class SceneTitle : public SceneBase
{
private:
	//�t�F�[�Y
	enum class Phase
	{
		Run,		//���s��
		OpenBook,	//�{���J��

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
		SpriteAnimation("Resource/Book/open1.png", 10, 15, false),
		SpriteAnimation("Resource/Book/open2.png", 10, 13, false),
	};

	Node* m_rootNode;
	Sprite* m_sprite;
	TitleSelect* m_select;
	Phase m_phase;
	Anime m_anime;
	Transform m_transform;
	int m_bgm;

	//�f�[�^�̓ǂݍ���
	int DataLoad();

	//�f�[�^�̏�������
	void DataSeve(int data);

public:
	//�R���X�g���N�^
	SceneTitle() :
		m_phase(Phase::Run),
		m_anime(Anime::Initial),
		m_rootNode(nullptr),
		m_sprite(nullptr),
		m_select(nullptr),
		m_bgm(0){}

	virtual void Initialize() override;				//������
	virtual void Finalize() override;				//�I��
	virtual SceneBase* Update() override;			//�X�V
	virtual void Draw() override;					//�`��
};