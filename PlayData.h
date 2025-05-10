#pragma once

class PlayData
{
private:
	 const char* FileName = "SaveData.dat";	//�t�@�C���p�X

	int m_clearMapNum; //�N���A�����}�b�v�ԍ�
	int m_bottleBit;

	int EncryptionData(int num) 
	{
		// XOR �� �r�b�g���] �� ���V�t�g �� ��XOR
		int temp = num ^ 1;
		temp = ~temp;
		temp = (temp << 3) | ((temp >> (32 - 3)) & 0x07); // �����[�e�[�g3�r�b�g
		temp ^= (1 << 1);  // �L�[�����炵�Ă�����xXOR
		return temp;
	}

	int DecodeData(int num)
	{
		// �Í����菇�̋t���ɖ߂�
		int temp = num ^ (1 << 1);
		temp = ((temp >> 3) & 0x1FFFFFFF) | (temp << (32 - 3)); // �E���[�e�[�g3�r�b�g
		temp = ~temp;
		temp ^= 1;
		return temp;
	}

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