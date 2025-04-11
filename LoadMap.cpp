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
	while (std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ',')) {
			try {
				row.push_back(std::stod(cell));  // 文字列を数値に変換
			}
			catch (...) {
				row.push_back(0.0);  // エラー時は0.0を格納
			}
		}
		data.push_back(row);
	}
	return data;
}