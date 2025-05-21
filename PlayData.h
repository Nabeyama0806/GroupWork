#pragma once

class PlayData
{
private:
	 const char* FileName = "SaveData.dat";	//ファイルパス

	int m_clearMapNum; //クリアしたマップ番号
	int m_bottleBit;

	//暗号化
	int EncryptionData(int num) 
	{
		int temp = num ^ 1;
		temp = ~temp;
		temp = (temp << 3) | ((temp >> (32 - 3)) & 0x07);
		temp ^= (1 << 1);
		return temp;
	}

	//復号化
	int DecodeData(int num)
	{
		int temp = num ^ (1 << 1);
		temp = ((temp >> 3) & 0x1FFFFFFF) | (temp << (32 - 3)); 
		temp = ~temp;
		temp ^= 1;
		return temp;
	}

public:
	//コンストラクタ
	PlayData();

	//データの書き込み
	void Save(int mapNum, int bottleBit, bool overwrite = false);

	int GetMapData()
	{
		return m_clearMapNum;
	}

	int GetBottleData()
	{
		return m_bottleBit;
	}
};