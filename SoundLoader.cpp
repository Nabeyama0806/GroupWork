#include "SoundLoader.h"
#include "DxLib.h"

int SoundLoader::LoadResource(const char* path)
{
	return LoadGraph(path);
}

void SoundLoader::DeleteResource(int id)
{
	DeleteGraph(id);
}