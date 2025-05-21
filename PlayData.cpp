#include "PlayData.h"
#include <fstream>
#include <string>

//データの読み込み
void PlayData::Load()
{
	//ファイルが開けなかったら終了
	std::ifstream file(FileName);  
	if (!file.is_open()) return;

	//読み込み
	int clearMap = 0;
	int bottleBit = 0;
	file >> clearMap >> bottleBit;

	//値の保持
	m_clearMapNum = clearMap;
	m_bottleBit = bottleBit;
}

//データの書き込み
void PlayData::Save(int mapNum, int bottleBit, bool overwrite)
{
	//ファイルが開けなかったら終了
	std::ofstream file(FileName);
	if (!file.is_open()) return;

	//上書き
	if (m_clearMapNum < mapNum && !overwrite || overwrite)
	{
		file << mapNum << std::endl << bottleBit;
	}
	else
	{
		file << m_clearMapNum << std::endl << m_bottleBit;
	}
}

//データの削除
void PlayData::Reset(bool overwrite)
{
	//データの初期化
	Save(0, 0, overwrite);
}