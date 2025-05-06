#include "SceneTitle.h"
#include "SceneGame.h"
#include "SoundManager.h"
#include "SoundLoader.h"
#include "Input.h"
#include "Screen.h"
#include "DxLib.h"

//������
void SceneTitle::Initialize()
{
	m_transform.position = Screen::Center;

	//�A�j���[�V�����̓o�^
	m_sprite = new Sprite();
	m_sprite->gridSize = Screen::Size;
	for (int i = 0; i < static_cast<int>(Anime::Length); ++i)
	{
		m_sprite->Register(AnimeName[i], AnimeDate[i]);
	}
	m_sprite->Load();

	//BGM
	m_bgm = SoundLoader::GetInstance()->Load("Resource/sound/bgm_title.mp3");
	SoundManager::Play(m_bgm, DX_PLAYTYPE_LOOP);

	//�w�i�F�̕ύX
	SetBackgroundColor(255, 255, 255); 
}

//�X�V
SceneBase* SceneTitle::Update()
{
	switch (m_phase)
	{
	case Phase::Run:
		//�����ꂩ�̃L�[�������ꂽ��Q�[���V�[���ֈړ�
		if (Input::GetInstance()->IsAnyKeyDown())
		{
			//���ʉ�
			SoundManager::Play("Resource/sound/se_start.mp3");
			SoundManager::SoundStop(m_bgm);
			m_phase = Phase::OpenBook;
		}
		break;

	case Phase::OpenBook:
		//�A�j���[�V�����̍X�V
		m_sprite->Update();
		m_sprite->Play(AnimeName[static_cast<int>(m_anime)]);
		
		//�A�j���[�V�������I���ƃV�[���J��
		if (m_sprite->IsFinishAnime())
		{
			if (m_anime == Anime::Initial) m_anime = Anime::Final;
			else return new SceneGame();
		}
		break;
	}

	return this;
}

//�`��
void SceneTitle::Draw()
{
	m_sprite->Draw(m_transform);
}