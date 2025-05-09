#pragma once

class PlayData
{
private:
	 const char* FileName = "SaveData.dat";	//ファイルパス

	int m_clearMapNum; //クリアしたマップ番号

public:
	//データの読み込み
	void Load();

	//データの書き込み
	void Save(int data);

	//データの削除
	void Reset(int num = 0);

	int GetData()
	{
		return m_clearMapNum;
	}
};