#pragma once

class PlayData
{
private:
	 const char* FileName = "SaveData.dat";	//ファイルパス

	int m_clearMapNum; //クリアしたマップ番号
	int m_bottleBit;

public:
	//データの読み込み
	void Load();

	//データの書き込み
	void Save(int mapNum, int bottleBit);

	//データの削除
	void Reset();

	int GetMapData()
	{
		return m_clearMapNum;
	}

	int GetBottleData()
	{
		return m_bottleBit;
	}
};