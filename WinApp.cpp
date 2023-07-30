#include"WinApp.h"
WinApp::WinApp(const wchar_t* title, const int32_t WindowSizeWidth, const int32_t WindowSizeHeight) {
	this->title_ = title;
	this->kClientWidth_ = WindowSizeWidth;
	this->kClientHeight_ = WindowSizeHeight;

}




void  WinApp::RegisterWindowsClass()
{




	//ウィンドウプロシャージャ
	wc_.lpfnWndProc = WindowProc;
	//ウィンドウクラス名
	wc_.lpszClassName = L"%s", title_;
	//インスタンドハンドル
	wc_.hInstance = GetModuleHandle(nullptr);
	//カーソル
	wc_.hCursor = LoadCursor(nullptr, IDC_ARROW);
	//ウィンドウクラス登録
	RegisterClass(&wc_);

	//クライアント領域サイズ
	//ウィンドウサイズを表す構造体にクライアント領域を入れる
	RECT wrc_ = { 0,0,kClientWidth_ ,kClientHeight_ };
	// クライアント領域を元に実際のサイズにwrcを変更
	AdjustWindowRect(&wrc_, WS_OVERLAPPEDWINDOW, false);
	// ウィンドウ生成
	hwnd_ = CreateWindow(
		wc_.lpszClassName,//　クラス名
		title_,                //　タイトルバーの文字
		WS_OVERLAPPEDWINDOW,  //　標準的なウィンドウスタイル
		CW_USEDEFAULT,        //　標準X座標
		CW_USEDEFAULT,        //　標準Y座標
		wrc_.right - wrc_.left, //　横幅
		wrc_.bottom - wrc_.top, //　縦幅ti
		nullptr,              //　親ハンドル
		nullptr,              //　メニューハンドル
		wc_.hInstance,         //　インスタンスハンドル
		nullptr               //　オプション
	);





}


void WinApp::DisplayWindow() {
	//ウィンドウを表示
	ShowWindow(hwnd_, SW_SHOW);
}

void WinApp::Initialize() {
	//ウィンドウクラスを登録
	RegisterWindowsClass();

	//ウィンドウを表示
	DisplayWindow();
}






void WinApp::WindowsMSG(MSG& msg) {
	TranslateMessage(&msg);
	DispatchMessage(&msg);
}



void WinApp::Close() {

	CloseWindow(hwnd_);
}





