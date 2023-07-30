#pragma once
#include <cstdint>
#include <windows.h>
#include <string>
//Window Procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

struct Vector4
{
	float x;
	float y;
	float z;
	float w;

};

Vector4 ColorAdapter(unsigned int color);
std::wstring ConvertString(const std::string& str);
std::string ConvertString(const std::wstring& str);
