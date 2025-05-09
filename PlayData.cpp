#include "PlayData.h"
#include <fstream>
#include <string>

//�f�[�^�̓ǂݍ���
void PlayData::Load()
{
	//�ǂݍ���
	std::ifstream file(FileName);  

	if (!file.is_open()) return;

	int data = 0;
	file >> data;

	m_clearMapNum = data;
}

//�f�[�^�̏�������
void PlayData::Save(int data)
{
	//�㏑��
	std::ofstream file(FileName);

	if (!file.is_open()) return;

	file << data;
}

//�f�[�^�̍폜
void PlayData::Reset(int num)
{
	//�f�[�^�̏�����
	Save(num);
}