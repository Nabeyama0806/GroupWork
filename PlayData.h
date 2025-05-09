#pragma once

class PlayData
{
private:
	 const char* FileName = "SaveData.dat";	//�t�@�C���p�X

	int m_clearMapNum; //�N���A�����}�b�v�ԍ�

public:
	//�f�[�^�̓ǂݍ���
	void Load();

	//�f�[�^�̏�������
	void Save(int data);

	//�f�[�^�̍폜
	void Reset(int num = 0);

	int GetData()
	{
		return m_clearMapNum;
	}
};