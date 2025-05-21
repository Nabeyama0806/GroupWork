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
	file.close();

	//値の保持
	m_clearMapNum = clearMap;
	m_bottleBit = bottleBit;
}

//データの書き込み
void PlayData::Save(int mapNum, int bottleBit, bool overwrite)
{
	//ファイルが開けなかったら終了
	std::fstream file(FileName);
	if (!file.is_open())
	{
		//ファイルが開けなければ新しく作成して開く
		file.open(FileName, std::ios::out);
	}

	m_clearMapNum = 0;
	m_bottleBit = 0;

	//上書きするかどうか
	if (overwrite || m_clearMapNum < mapNum)
	{
		//上書き
		file << mapNum << std::endl << bottleBit;

		//値の保持
		m_clearMapNum = mapNum;
		m_bottleBit = bottleBit;
	}

	file.close();
}