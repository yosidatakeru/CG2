#pragma once

#include <Windows.h>
#include <cstdint>

#include "imGui/imgui.h"
#include "imGui/imgui_impl_dx12.h"
#include "imGui/imgui_impl_win32.h"


//extern...グローバル変数を共有する
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class WinApp 
{
public:

	//コンストラクタ
	WinApp();


	//Window Procedure
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);


	//ウィンドウクラスを登録
	void RegisterWindowsClass();

	//WINodwを表示
	void DisplayWindow();


	void Initialize(const wchar_t* title, const int32_t WindowSizeWidth, const int32_t WindowSizeHeight);





	void WindowsMSG(MSG& msg);


	void Close();


	//Getter
	int GetClientWidth() {
		return kClientWidth_;
	}
	int GetClientHeight() {
		return kClientHeight_;
	}

	HWND GetHwnd() {
		return hwnd_;
	}

private:

	////ウィンドウクラスを登録する
	const wchar_t* title_;
	int32_t kClientWidth_;
	int32_t kClientHeight_;



	HWND hwnd_;

	WNDCLASS wc_{};



};

