#pragma once

class PlayData
{
private:
	 const char* FileName = "SaveData.dat";	//ファイルパス

	int m_clearMapNum; //クリアしたマップ番号
	int m_bottleBit;

	int EncryptionData(int num) 
	{
		// XOR → ビット反転 → 左シフト → 再XOR
		int temp = num ^ 1;
		temp = ~temp;
		temp = (temp << 3) | ((temp >> (32 - 3)) & 0x07); // 左ローテート3ビット
		temp ^= (1 << 1);  // キーをずらしてもう一度XOR
		return temp;
	}

	int DecodeData(int num)
	{
		// 暗号化手順の逆順に戻す
		int temp = num ^ (1 << 1);
		temp = ((temp >> 3) & 0x1FFFFFFF) | (temp << (32 - 3)); // 右ローテート3ビット
		temp = ~temp;
		temp ^= 1;
		return temp;
	}

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