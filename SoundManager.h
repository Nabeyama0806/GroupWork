#pragma once

class SoundManager
{
public:
	//ƒVƒ“ƒOƒ‹ƒgƒ“
	static SoundManager* GetInstance()
	{
		static SoundManager instance;
		return &instance;
	}

	void SoundPlay(int id, int type, int topPositionFlag = 1);
};