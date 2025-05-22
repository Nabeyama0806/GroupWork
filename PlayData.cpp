#include "PlayData.h"
#include <fstream>
#include <string>

//�R���X�g���N�^
PlayData::PlayData() :
	m_clearMapNum(0),
	m_bottleBit(0)
{
	//�t�@�C�����J���Ȃ�������I��
	std::ifstream file(FileName);
	if (!file.is_open()) return;

	//�ǂݍ���
	int clearMap = 0;
	int bottleBit = 0;
	file >> clearMap >> bottleBit;
	file.close();

	//�l�̕ێ�
	m_clearMapNum = DecryptInt(clearMap);
	m_bottleBit = DecryptInt(bottleBit);

	//Save(9, 1, true);
}

//�f�[�^�̏�������
void PlayData::Save(int mapNum, int bottleBit, bool overwrite)
{
	//�t�@�C�����J���Ȃ���ΐV�����쐬���ĊJ��
	std::fstream file(FileName);
	if (!file.is_open()) file.open(FileName, std::ios::out);

	//�㏑�����邩�ǂ���
	if (overwrite || m_clearMapNum < mapNum)
	{
		//�㏑��
		file << EncryptInt(mapNum) << std::endl << EncryptInt(bottleBit);

		//�l�̕ێ�
		m_clearMapNum = mapNum;
		m_bottleBit = bottleBit;
	}

	file.close();
}