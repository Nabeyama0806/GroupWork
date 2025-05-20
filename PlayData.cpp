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
	m_clearMapNum = DecodeData(clearMap);
	m_bottleBit = DecodeData(bottleBit);
}

//データの書き込み
void PlayData::Save(int mapNum, int bottleBit)
{
	//現在のマップ番号がこれまでのマップ番号より小さい場合は上書きしない
	if (m_clearMapNum > mapNum) return;

	//ファイルが開けなかったら終了
	std::ofstream file(FileName);
	if (!file.is_open()) return;

	//上書き
	file << EncryptionData(mapNum) << std::endl << EncryptionData(bottleBit);
}

//データの削除
void PlayData::Reset()
{
	//データの初期化
	Save(0, 0);
}