#pragma once
#include <cstdint>
#include <windows.h>
#include <string>



std::wstring ConvertString(const std::string& str);
std::string ConvertString(const std::wstring& str);
