#include "SoundManager.h"
#include "DxLib.h"

void SoundManager::SoundPlay(int se, int type, int topPositionFlag)
{
	PlaySoundMem(se, type, topPositionFlag);
}