#include "SoundManager.h"
#include "SoundLoader.h"
#include "DxLib.h"

void SoundManager::SoundPlay(int se, int type, int topPositionFlag)
{
	PlaySoundMem(se, static_cast<int>(type), topPositionFlag);
}

void SoundManager::SoundPlay(const char* path, int type, int topPositionFlag)
{
	int se = SoundLoader::GetInstance()->Load(path);
	SoundPlay(se, type, topPositionFlag);
}