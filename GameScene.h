#pragma once
#include <cstdint>
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Triangle.h"

#include "ColorConvert.h"

class GameScene {
public:

	//コンストラクタ
	GameScene();


	//初期化
	void Initialize();



#pragma region ゲームループの中


	//ウィンドウのメッセージ
	void WindowMSG(MSG& msg);


	//フレームの始め
	void BeginFrame();


	//更新処理
	void UpDate();


	//描画処理
	void Draw();


	//フレーム終わり
	void EndFrame();


#pragma endregion



	//解放処理
	void Release();



	//デストラクタ
	~GameScene();


private:

	//画面のサイズ
	const int32_t WINDOW_SIZE_WIDTH_ = 1280;
	const int32_t WINDOW_SIZE_HEIGHT_ = 720;



	//インスタンス(空)
	WinApp* winSetup = nullptr;
	DirectXCommon* directXSetup = nullptr;




};