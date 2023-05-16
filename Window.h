#pragma once
#include <Windows.h>
#include <cstdint>
#include <string>
class Window
{
public:

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	void Initialize(const wchar_t* title, const int32_t kClientWidth, const int32_t kClientHeight);

private:

	WNDCLASS wc{};
	HWND hwnd;
};

