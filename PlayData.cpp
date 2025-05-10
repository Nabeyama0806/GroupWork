#include "PlayData.h"
#include <fstream>
#include <string>

//�f�[�^�̓ǂݍ���
void PlayData::Load()
{
	//�ǂݍ���
	std::ifstream file(FileName);  

	int clearMap = 0;
	int bottleBit = 0;

	if (file.is_open())
	{
		file >> clearMap >> bottleBit;
	}

	m_clearMapNum = clearMap;
	m_bottleBit = bottleBit;
}

//�f�[�^�̏�������
void PlayData::Save(int mapNum, int bottleBit)
{
	//�㏑��
	std::ofstream file(FileName);

	if (!file.is_open()) return;

	file << mapNum << std::endl << bottleBit;
}

//�f�[�^�̍폜
void PlayData::Reset()
{
	//�f�[�^�̏�����
	Save(0, 0);
}