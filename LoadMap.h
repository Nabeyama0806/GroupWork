#pragma once
#include "DxLib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class LoadMap
{
public:
	//�V���O���g��
	static LoadMap* GetInstance()
	{
		static LoadMap instance;
		return &instance;
	}

	std::vector<std::vector<int>> ReadCSV(const std::string& filename);
};