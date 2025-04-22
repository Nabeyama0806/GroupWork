#pragma once
#include "DxLib.h"
#include "SoundLoader.h"

struct SoundManager
{
public:
	//���ʉ��̍Đ�
	static void Play(int se, int type = DX_PLAYTYPE_BACK)
	{
		PlaySoundMem(se, type);
	}
	static int Play(const char* path, int type = DX_PLAYTYPE_BACK)
	{
		int se = SoundLoader::GetInstance()->Load(path);
		Play(se, type);
		return se;
	}

	//���ʂ̒���
	static void ChangeVolume(int id, int volume)
	{
		ChangeVolumeSoundMem(volume, id);
	}

	//���̒�~
	static void SoundStop(int id)
	{
		StopSoundMem(id);
	}
};