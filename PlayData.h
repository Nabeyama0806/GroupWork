#pragma once
#include <cstdint>

class PlayData
{
private:
	static constexpr int KeyBit = 0x5A5A5A5A;	//XORのキー
	static constexpr int LoopCount = 10;		//暗号化、複合化のループ回数

	const char* FileName = "SaveData.dat";	//ファイルパス

	int m_clearMapNum;	//クリアしたマップ番号
	int m_bottleBit;	//取得したボトルのビットフラグ

	//暗号化
	int EncryptInt(int num)
	{
		int temp = num ^ KeyBit;	//XOR
		temp = ~temp;				//ビット反転
		return temp;
	}

	// 復号化
	int DecryptInt(int num) 
	{
		int temp = ~num;         //ビット反転
		temp ^= KeyBit;          //XOR
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