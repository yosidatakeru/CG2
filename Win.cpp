////#include "Win.h"
////
////WNDCLASS wc{};
////
////ウィンドウプロシージャ
////wc.lpfnWndProc = WindowProc;
////
////ウィンドウクラス名
////wc.lpszClassName = L"CG2WindowClass";
////
////インスタンスハンドル
////wc.hInstance = GetModuleHandle(nullptr);
////
////カーソル
////wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
////ウインドウクラスを登録
////RegisterClass(&wc);
////
////クライアント領域のサイズ
////const int32_t kClientWidth = 1280;
////const int32_t kClientHeight = 720;
////
////ウインドウサイズを表す構造体にクライアント領域を入れる
////RECT wrc = { 0,0,kClientWidth,kClientHeight };
////
////クライアント領域をもとに実際のサイズにｗｒｃを変更してもらう
////AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);
////ウインドウの生成
////HWND hwnd = CreateWindow
////(
////	wc.lpszClassName,
////	L"CG2",
////	WS_OVERLAPPEDWINDOW,
////	CW_USEDEFAULT,
////	CW_USEDEFAULT,
////	wrc.right - wrc.left,
////	wrc.bottom - wrc.top,
////	nullptr,
////	nullptr,
////	wc.hInstance,
////	nullptr
////);