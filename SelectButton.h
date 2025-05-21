#pragma once
#include "SpriteActor.h"
#include "SceneTitle.h"
#include "Button.h"

class SceneTitle;
class Button;

class SelectButton : public SpriteActor
{
private:
	static constexpr Vector2 Size = Vector2(440, 100);		//ボタンのサイズ

protected:
	Button m_button;

	virtual void Update() override;	//更新
	virtual void Draw() override;	//描画

public:
	//コンストラクタ
	SelectButton(
		const char* textureName,
		const Vector2& position,
		std::function<void()> callbackFunction
	);
};
