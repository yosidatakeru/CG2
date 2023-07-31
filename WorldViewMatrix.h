#pragma once
#include "Matrix4x4.h"

struct WorldViewMatrix 
{
	Matrix4x4 viewMatrix;
	Matrix4x4 projectionMatrix;
};
