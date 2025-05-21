#pragma once
#include "SpriteActor.h"
#include "SceneTitle.h"
#include "Button.h"

class SceneTitle;
class Button;

class SelectButton : public SpriteActor
{
private:
	static constexpr Vector2 Size = Vector2(440, 100);		//�{�^���̃T�C�Y

protected:
	Button m_button;

	virtual void Update() override;	//�X�V
	virtual void Draw() override;	//�`��

public:
	//�R���X�g���N�^
	SelectButton(
		const char* textureName,
		const Vector2& position,
		std::function<void()> callbackFunction
	);
};
