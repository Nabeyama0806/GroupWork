#pragma once

class PlayData
{
private:
	 const char* FileName = "SaveData.dat";	//�t�@�C���p�X

	int m_clearMapNum; //�N���A�����}�b�v�ԍ�
	int m_bottleBit;

	//�Í���
	int EncryptionData(int num) 
	{
		int temp = num ^ 1;
		temp = ~temp;
		temp = (temp << 3) | ((temp >> (32 - 3)) & 0x07);
		temp ^= (1 << 1);
		return temp;
	}

	//������
	int DecodeData(int num)
	{
		int temp = num ^ (1 << 1);
		temp = ((temp >> 3) & 0x1FFFFFFF) | (temp << (32 - 3)); 
		temp = ~temp;
		temp ^= 1;
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