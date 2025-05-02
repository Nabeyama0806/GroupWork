#pragma once
#include "SpriteActor.h"
#include "Vector3.h"
#include "Player.h"

class UiKeyItem : public SpriteActor
{
private:
	static constexpr Vector3 Offset = Vector3(-200, 100, 0);
	static constexpr Vector3 Scale = Vector3(0.1f, 0.1f, 0.1f);

	Player* m_player;

protected:
	virtual void Draw() override
	{
		//Œ®‚ðŽ‚Á‚Ä‚¢‚ê‚Î•\Ž¦
		if (m_player->GetIsKey())
		{
			SpriteActor::Draw();
		}
	}

public:
	UiKeyItem(Player* player) :
		SpriteActor("UiKeyItem", "Resource/Texture/bottle_thunder2.png"),
		m_player(player)
	{
		m_transform.scale = Scale;
		m_transform.position = Screen::TopRight + Offset;
	}
};