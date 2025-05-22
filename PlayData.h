#pragma once
#include <cstdint>

class PlayData
{
private:
	static constexpr int KeyBit = 0x5A5A5A5A;	//XOR�̃L�[
	static constexpr int LoopCount = 10;		//�Í����A�������̃��[�v��

	const char* FileName = "SaveData.dat";	//�t�@�C���p�X

	int m_clearMapNum;	//�N���A�����}�b�v�ԍ�
	int m_bottleBit;	//�擾�����{�g���̃r�b�g�t���O

	//�Í���
	int EncryptInt(int num)
	{
		int temp = num ^ KeyBit;	//XOR
		temp = ~temp;				//�r�b�g���]
		return temp;
	}

	// ������
	int DecryptInt(int num) 
	{
		int temp = ~num;         //�r�b�g���]
		temp ^= KeyBit;          //XOR
		return temp;
	}

public:
	//�R���X�g���N�^
	PlayData();

	//�f�[�^�̏�������
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