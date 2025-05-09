#pragma once
#include "SpriteActor.h"

class TitleSelect : public SpriteActor
{
private:
	bool m_isContinued;	//つづきから

protected:
	virtual void Update() override;

public:
	//コンストラクタ
	TitleSelect();

	bool GetIsContinued()
	{
		return m_isContinued;
	}
};