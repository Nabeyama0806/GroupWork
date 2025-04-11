#pragma once
#include "DxLib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class LoadMap
{
private:
	//std::string filename = "openfile.csv";  // �ǂݍ���CSV�t�@�C����
	//auto data = ReadCSV(filename);

public:
	//�V���O���g��
	static LoadMap* GetInstance()
	{
		static LoadMap instance;
		return &instance;
	}

	std::vector<std::vector<int>> ReadCSV(const std::string& filename);
};