#include "PlayData.h"
#include <fstream>
#include <string>

//データの読み込み
void PlayData::Load()
{
	//読み込み
	std::ifstream file(FileName);  

	if (!file.is_open()) return;

	int data = 0;
	file >> data;

	m_clearMapNum = data;
}

//データの書き込み
void PlayData::Save(int data)
{
	//上書き
	std::ofstream file(FileName);

	if (!file.is_open()) return;

	file << data;
}

//データの削除
void PlayData::Reset(int num)
{
	//データの初期化
	Save(num);
}