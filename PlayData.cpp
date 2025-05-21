#include "PlayData.h"
#include <fstream>
#include <string>

//�f�[�^�̓ǂݍ���
void PlayData::Load()
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
	m_clearMapNum = clearMap;
	m_bottleBit = bottleBit;
}

//�f�[�^�̏�������
void PlayData::Save(int mapNum, int bottleBit, bool overwrite)
{
	//�t�@�C�����J���Ȃ�������I��
	std::fstream file(FileName);
	if (!file.is_open())
	{
		//�t�@�C�����J���Ȃ���ΐV�����쐬���ĊJ��
		file.open(FileName, std::ios::out);
	}

	m_clearMapNum = 0;
	m_bottleBit = 0;

	//�㏑�����邩�ǂ���
	if (overwrite || m_clearMapNum < mapNum)
	{
		//�㏑��
		file << mapNum << std::endl << bottleBit;

		//�l�̕ێ�
		m_clearMapNum = mapNum;
		m_bottleBit = bottleBit;
	}

	file.close();
}