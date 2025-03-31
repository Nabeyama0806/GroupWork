#pragma once
#include "SpriteActor.h"
#include "Bottle.h"

class UiBottle : public SpriteActor
{
private:
	static constexpr Vector3 SizeOffset = Vector3(100, 100, 100);

	//�摜�̃t�@�C���p�X
	const char* FilePath[static_cast<int>(Bottle::Type::Length)] =
	{
		"Resouce/bottle_fire.png",
		"Resouce/bottle_thunder.png",
		"Resouce/bottle_water.png"
	};

	//�摜�̖��O
	const char* TextureName[static_cast<int>(Bottle::Type::Length)] =
	{
		"Fire",
		"Thunder",
		"Water"
	};

	Bottle::Type m_type;	//���g�̑���
	int m_select;			//�I�����Ă��鑮��

protected:
	virtual void Update() override;	//�X�V
	virtual void Draw() override;	//�`��

public:
	//�R���X�g���N�^
	UiBottle();
};
