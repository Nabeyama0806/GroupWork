#include "LoadMap.h"

// CSV��ǂݍ��ފ֐�
std::vector<std::vector<int>> LoadMap::ReadCSV(const std::string& filename) 
{
	std::vector<std::vector<int>> data;
	std::ifstream file(filename);

	if (!file) {
		std::cerr << "CSV�t�@�C�����J���܂���ł���: " << filename << std::endl;
		return data;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::vector<int> row;
		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ','))
		{
			// �O��̋󔒍폜
			cell.erase(0, cell.find_first_not_of(" \t"));
			cell.erase(cell.find_last_not_of(" \t") + 1);

			try
			{
				row.push_back(std::stoi(cell));
			}
			catch (const std::invalid_argument&)
			{
				std::cerr << "���l�ɕϊ��ł��܂��� : " << cell << std::endl;
				row.push_back(0);  // 0�Ŗ��߂�
			}
			data.push_back(row);
		}
	}
	return data;
}