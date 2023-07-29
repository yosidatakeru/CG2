#pragma once
#include <Windows.h>
#include "MyFunction.h"
//#include<string>
#include<format>

class WinApp
{
	
	public:

		//コンストラクタ
		WinApp();
		~WinApp();
		static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		//ウィンドウクラスを登録
		void RegisterWindowsClass();

		//WINodwを表示
		void DisplayWindow();


		void Initialize(const wchar_t* title, const int32_t WindowSizeWidth, const int32_t WindowSizeHeight);



		void WindowsMSG(MSG& msg);


		void Close();


		////Getter
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

