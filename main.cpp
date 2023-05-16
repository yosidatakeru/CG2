#include"Window.h"

const wchar_t Title[] = { L"CG2WindowClass" };

//main関数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Window* window_ = new Window;

	//クライアント領域のサイズ
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;
	window_->Initialize(Title, kClientWidth, kClientHeight);

	MSG msg{};
	//ウインドウの×ボタンが押されるまでループ(メインループ)
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{

		}

	}
}