#pragma once
#include "SpriteActor.h"

class TitleSelect : public SpriteActor
{
private:
	bool m_isContinued;	//�Â�����

protected:
	virtual void Update() override;

public:
	//�R���X�g���N�^
	TitleSelect();

	bool GetIsContinued()
	{
		return m_isContinued;
	}
};