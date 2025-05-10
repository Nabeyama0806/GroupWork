#pragma once

class PlayData
{
private:
	 const char* FileName = "SaveData.dat";	//�t�@�C���p�X

	int m_clearMapNum; //�N���A�����}�b�v�ԍ�
	int m_bottleBit;

public:
	//�f�[�^�̓ǂݍ���
	void Load();

	//�f�[�^�̏�������
	void Save(int mapNum, int bottleBit);

	//�f�[�^�̍폜
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