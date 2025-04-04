#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "Input.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Screen.h"
#include "DxLib.h"

//‰Šú‰»
void SceneTitle::Initialize()
{
	m_rootNode = new Node();

	//”wŒi
	m_rootNode->AddChild(new SpriteActor("BackGround", "Resource/title.png", Screen::Center));

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("sound/bgm_title.mp3");
	SoundManager::GetInstance()->SoundPlay(m_bgm, DX_PLAYTYPE_LOOP);
}

//I—¹
void SceneTitle::Finalize()
{
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//XV
SceneBase* SceneTitle::Update()
{
	//‚¢‚¸‚ê‚©‚ÌƒL[‚ª‰Ÿ‚³‚ê‚½‚çƒQ[ƒ€ƒV[ƒ“‚ÖˆÚ“®
	if (Input::GetInstance()->IsAnyKeyDown())
	{
		//Œø‰Ê‰¹
		SoundManager::GetInstance()->SoundPlay("sound/se_start.mp3");
		StopSoundMem(m_bgm);

		return new SceneGame();
	}

	//ƒm[ƒh‚ÌXV
	m_rootNode->TreeUpdate();

	return this;
}

//•`‰æ
void SceneTitle::Draw()
{
	//ƒm[ƒh‚Ì•`‰æ
	m_rootNode->TreeDraw();

}