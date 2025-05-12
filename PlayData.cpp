#include "PlayData.h"
#include <fstream>
#include <string>

//データの読み込み
void PlayData::Load()
{
	//読み込み
	std::ifstream file(FileName);  

	int clearMap = 0;
	int bottleBit = 0;

	if (file.is_open())
	{
		file >> clearMap >> bottleBit;
	}

	m_clearMapNum = DecodeData(clearMap);
	m_bottleBit = DecodeData(bottleBit);
}

//データの書き込み
void PlayData::Save(int mapNum, int bottleBit)
{
	//上書き
	std::ofstream file(FileName);

	if (!file.is_open()) return;

	file << EncryptionData(mapNum) << std::endl << EncryptionData(bottleBit);
}

//データの削除
void PlayData::Reset()
{
	//データの初期化
	Save(8, 15);
}