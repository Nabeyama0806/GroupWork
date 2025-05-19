#include "SceneResult.h"
#include "Input.h"
#include "SceneTitle.h"
#include "SpriteActor.h"
#include "Time.h"

//������
void SceneResult::Initialize()
{
	m_rootNode = new Node();

	//�A�j���[�V�����̓o�^
	m_sprite = new Sprite();
	m_sprite->gridSize = Screen::Size;
	for (int i = 0; i < static_cast<int>(ClearAnime::Length); ++i)
	{
		m_sprite->Register(ClearAnimeName[i], ClearAnimeDate[i]);
	}
	m_sprite->Load();

	SetBackgroundColor(255, 255, 255); //�w�i�F�̕ύX
}

//�I������
void SceneResult::Finalize()
{
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//�X�V
SceneBase* SceneResult::Update()
{
	if (m_waitTransitionTime > 0)
	{
		m_waitTransitionTime -= Time::GetInstance()->GetDeltaTime();
	}

	m_sprite->Update();
	m_sprite->Play(ClearAnimeName[static_cast<int>(m_clearAnime)]);
	if (m_sprite->IsFinishAnime() && m_clearAnime == ClearAnime::First)
	{
		m_clearAnime = ClearAnime::Second;
	}

	//�����ꂩ�̃L�[�������ꂽ��^�C�g����ʂɑJ��
	if (m_waitTransitionTime <= 0 && Input::GetInstance()->IsAnyKeyDown())
	{
		return new SceneTitle();
	}

	//�m�[�h�̍X�V
	m_rootNode->TreeUpdate();

	return this;
}

//�`��
void SceneResult::Draw()
{
	//�m�[�h�̍X�V
	m_rootNode->TreeDraw();

	m_sprite->Draw(m_transform);
}