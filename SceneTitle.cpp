#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "Input.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Screen.h"
#include "DxLib.h"

//������
void SceneTitle::Initialize()
{
	m_rootNode = new Node();

	//�w�i
	m_rootNode->AddChild(new SpriteActor("BackGround", "Resource/title.png", Screen::Center));

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("sound/bgm_title.mp3");
	SoundManager::GetInstance()->SoundPlay(m_bgm, DX_PLAYTYPE_LOOP);
}

//�I��
void SceneTitle::Finalize()
{
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//�X�V
SceneBase* SceneTitle::Update()
{
	//�����ꂩ�̃L�[�������ꂽ��Q�[���V�[���ֈړ�
	if (Input::GetInstance()->IsAnyKeyDown())
	{
		//���ʉ�
		SoundManager::GetInstance()->SoundPlay("sound/se_start.mp3");
		StopSoundMem(m_bgm);

		return new SceneGame();
	}

	//�m�[�h�̍X�V
	m_rootNode->TreeUpdate();

	return this;
}

//�`��
void SceneTitle::Draw()
{
	//�m�[�h�̕`��
	m_rootNode->TreeDraw();

}