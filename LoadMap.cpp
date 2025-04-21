#include "LoadMap.h"

// CSVを読み込む関数
std::vector<std::vector<int>> LoadMap::ReadCSV(const std::string& filename) 
{
	std::vector<std::vector<int>> data;
	std::ifstream file(filename);

	if (!file) {
		std::cerr << "CSVファイルを開けませんでした: " << filename << std::endl;
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
			// 前後の空白削除
			cell.erase(0, cell.find_first_not_of(" \t"));
			cell.erase(cell.find_last_not_of(" \t") + 1);

			try
			{
				row.push_back(std::stoi(cell));
			}
			catch (const std::invalid_argument&)
			{
				std::cerr << "数値に変換できません : " << cell << std::endl;
				row.push_back(0);  // 0で埋める
			}
			data.push_back(row);
		}
	}
	return data;
}