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

	virtual void Update() override;	//更新
	virtual void Draw() override;	//描画

public:
	//コンストラクタ
	SelectButton(
		const char* textureName,
		const Vector2& size,
		const Vector2& position,
		std::function<void()> callbackFunction
	);
};
