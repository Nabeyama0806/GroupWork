#pragma once

class SoundManager
{
public:
	//�V���O���g��
	static SoundManager* GetInstance()
	{
		static SoundManager instance;
		return &instance;
	}

	void SoundPlay(int id, int type, int topPositionFlag = 1);
};