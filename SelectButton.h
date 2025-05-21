#pragma once
#include "SpriteActor.h"
#include "SceneTitle.h"
#include "Button.h"

class SceneTitle;
class Button;

class SelectButton : public SpriteActor
{
protected:
	Button m_button;

	virtual void Update() override;	//�X�V
	virtual void Draw() override;	//�`��

public:
	//�R���X�g���N�^
	SelectButton(
		const char* textureName,
		const Vector2& size,
		const Vector2& position,
		std::function<void()> callbackFunction
	);
};
