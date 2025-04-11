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
	while (std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ',')) {
			try {
				row.push_back(std::stod(cell));  // ������𐔒l�ɕϊ�
			}
			catch (...) {
				row.push_back(0.0);  // �G���[����0.0���i�[
			}
		}
		data.push_back(row);
	}
	return data;
}