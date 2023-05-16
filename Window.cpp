#include"Window.h"


//ウィンドウプロシージャー
LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//メッセージに応じてゲーム固有の処理を行う
	switch (msg)
	{
		//ウィンドウが破壊された
	case WM_DESTROY:

		//OSに対して、アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}
	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}
void Log(const std::string& message)
{
	OutputDebugStringA(message.c_str());
}

void  Window::Initialize(const wchar_t* title, const int32_t kClientWidth, const int32_t kClientHeight)
{
	//ウィンドウプロシージャ
	wc.lpfnWndProc = WindowProc;

	//ウィンドウクラス名
	wc.lpszClassName = L"%s", title;

	//インスタンスハンドル
	wc.hInstance = GetModuleHandle(nullptr);

	//カーソル
	wc.hCursor = LoadCursor(nullptr,IDC_ARROW);

	//ウインドウクラスを登録
	RegisterClass(&wc);

	//ウインドウサイズを表す構造体にクライアント領域を入れる
	RECT wrc = { 0,0,kClientWidth,kClientHeight };
	//クライアント領域をもとに実際のサイズにｗｒｃを変更してもらう
	AdjustWindowRect(&wrc,WS_OVERLAPPEDWINDOW,false);

	//ウインドウの生成
	 hwnd = CreateWindow
	(
		wc.lpszClassName,
		L"CG2",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wrc.right - wrc.left,
		wrc.bottom - wrc.top,
		nullptr,
		nullptr,
		wc.hInstance,
		nullptr
	);
	 //ウィンドウを表示
	 ShowWindow(hwnd, SW_SHOW);
}