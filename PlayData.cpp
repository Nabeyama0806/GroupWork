#include "PlayData.h"
#include <fstream>
#include <string>

//コンストラクタ
PlayData::PlayData() :
	m_clearMapNum(0),
	m_bottleBit(0)
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
	m_clearMapNum = DecodeData(clearMap);
	m_bottleBit = DecodeData(bottleBit);
}

//データの書き込み
void PlayData::Save(int mapNum, int bottleBit, bool overwrite)
{
	//ファイルが開けなければ新しく作成して開く
	std::fstream file(FileName);
	if (!file.is_open()) file.open(FileName, std::ios::out);

	m_clearMapNum = 0;
	m_bottleBit = 0;

	//上書きするかどうか
	if (overwrite || m_clearMapNum < mapNum)
	{
		//上書き
		file << EncryptionData(mapNum) << std::endl << EncryptionData(bottleBit);

		//値の保持
		m_clearMapNum = EncryptionData(mapNum);
		m_bottleBit = EncryptionData(bottleBit);
	}

	file.close();
}