#pragma once
#include "SpriteActor.h"
#include "Bottle.h"

class UiBottle : public SpriteActor
{
private:
	static constexpr Vector3 SizeOffset = Vector3(0.05f, 0.05f, 0.05f);
	static constexpr Vector3 ScreenOffset = Vector3(-100, -70, 0);

	//�摜�̃t�@�C���p�X
	const char* FilePath[static_cast<int>(Bottle::Type::Length)] =
	{
		"Resource/bottle_fire.png",
		"Resource/bottle_thunder.png",
		"Resource/bottle_water.png",
		"Resource/bottle_wind.png"
	};

	//�摜�̖��O
	const char* TextureName[static_cast<int>(Bottle::Type::Length)] =
	{
		"Fire",
		"Thunder",
		"Water",
		"WInd"
	};

	Bottle::Type m_type;	//���g�̑���
	int m_select;			//�I�����Ă��鑮��

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	//�`��

public:
	//�R���X�g���N�^
	UiBottle(Vector3 position);
};
