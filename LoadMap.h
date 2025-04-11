#pragma once
#include "DxLib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class LoadMap
{
private:
	//std::string filename = "openfile.csv";  // 読み込むCSVファイル名
	//auto data = ReadCSV(filename);

public:
	//シングルトン
	static LoadMap* GetInstance()
	{
		static LoadMap instance;
		return &instance;
	}

	std::vector<std::vector<int>> ReadCSV(const std::string& filename);
};