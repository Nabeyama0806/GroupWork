#pragma once
#include "Vector3.h"

class UiTransform
{
public:
	Vector2 position;	//���W
	float angle;			//(�p�x)���W�A��
	float scale;			//�g�k

	UiTransform() :
		angle(0),
		scale(1){}
};