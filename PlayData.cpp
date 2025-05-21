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

	//�l�̕ێ�
	m_clearMapNum = clearMap;
	m_bottleBit = bottleBit;
}

//�f�[�^�̏�������
void PlayData::Save(int mapNum, int bottleBit, bool overwrite)
{
	//�t�@�C�����J���Ȃ�������I��
	std::ofstream file(FileName);
	if (!file.is_open()) return;

	//�㏑��
	if (m_clearMapNum < mapNum && !overwrite || overwrite)
	{
		file << mapNum << std::endl << bottleBit;
	}
	else
	{
		file << m_clearMapNum << std::endl << m_bottleBit;
	}
}

//�f�[�^�̍폜
void PlayData::Reset(bool overwrite)
{
	//�f�[�^�̏�����
	Save(0, 0, overwrite);
}