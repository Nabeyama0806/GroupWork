#pragma once
#include "DxLib.h"

class SoundManager
{
public:
	//�V���O���g��
	static SoundManager* GetInstance()
	{
		static SoundManager instance;
		return &instance;
	}

	void SoundPlay(int id, int type = DX_PLAYTYPE_BACK, int topPositionFlag = 1);
	void SoundPlay(const char* path, int type = DX_PLAYTYPE_BACK, int topPositionFlag = 1);
};