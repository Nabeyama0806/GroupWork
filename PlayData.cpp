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
	m_clearMapNum = DecodeData(clearMap);
	m_bottleBit = DecodeData(bottleBit);
}

//�f�[�^�̏�������
void PlayData::Save(int mapNum, int bottleBit)
{
	//���݂̃}�b�v�ԍ�������܂ł̃}�b�v�ԍ���菬�����ꍇ�͏㏑�����Ȃ�
	if (m_clearMapNum > mapNum) return;

	//�t�@�C�����J���Ȃ�������I��
	std::ofstream file(FileName);
	if (!file.is_open()) return;

	//�㏑��
	file << EncryptionData(mapNum) << std::endl << EncryptionData(bottleBit);
}

//�f�[�^�̍폜
void PlayData::Reset()
{
	//�f�[�^�̏�����
	Save(0, 0);
}