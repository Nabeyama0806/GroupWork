#include "SceneTitle.h"
#include "SceneGame.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "Input.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Screen.h"
#include "DxLib.h"

//‰Šú‰»
void SceneTitle::Initialize()
{
	m_rootNode = new Node();
	m_transform.position = Screen::Center;

	m_sprite = new Sprite();
	m_sprite->Register("Book", SpriteAnimation("Resource/Book/open.png",30,10,false));
	m_sprite->gridSize = Screen::Size;
	m_sprite->Load();
	m_sprite->Play("Book");

	//”wŒi
	//m_rootNode->AddChild(new SpriteActor("BackGround", "Resource/Texture/title.png", Screen::Center));

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Resource/sound/bgm_title.mp3");
	SoundManager::Play(m_bgm, DX_PLAYTYPE_LOOP);

	SetBackgroundColor(255, 255, 255); //”wŒiF‚Ì•ÏX
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
	switch (m_phase)
	{
	case Phase::Run:
		//‚¢‚¸‚ê‚©‚ÌƒL[‚ª‰Ÿ‚³‚ê‚½‚çƒQ[ƒ€ƒV[ƒ“‚ÖˆÚ“®
		if (Input::GetInstance()->IsAnyKeyDown())
		{
			//Œø‰Ê‰¹
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);
			m_phase = Phase::OpenBook;
		}
		break;

	case Phase::OpenBook:
		return new SceneGame();
		
		break;
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
	m_sprite->Draw(m_transform);
}