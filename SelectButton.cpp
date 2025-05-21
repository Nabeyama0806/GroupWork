#include "SelectButton.h"
#include "SceneTitle.h"
#include "Input.h"
#include "DxLib.h"

//�R���X�g���N�^
SelectButton::SelectButton(const char* textureName, const Vector2& size, const Vector2& position, std::function<void()> callbackFunction) :
	SpriteActor("SelectButton", textureName, position),
	m_button(size, MOUSE_INPUT_LEFT, callbackFunction)
{
}

//�X�V
void SelectButton::Update()
{
	//�{���̏���
	SpriteActor::Update();

	//�{�^���̍X�V
	m_button.Update(m_transform.position);
}

//�`��
void SelectButton::Draw()
{
	//�{���̏���
	SpriteActor::Draw();

	//�{�^���̕`��
	m_button.Draw(m_transform.position);
}