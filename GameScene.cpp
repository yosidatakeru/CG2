#include "GameScene.h"


GameScene::GameScene() {
	winSetup = new WinApp();
	directXSetup = new DirectXCommon();
}

void GameScene::Initialize() {
	//初期化
	winSetup->Initialize(L"DirectX", WINDOW_SIZE_WIDTH_, WINDOW_SIZE_HEIGHT_);
	directXSetup->Initialize(WINDOW_SIZE_WIDTH_, WINDOW_SIZE_HEIGHT_, winSetup->GetHwnd());


	//三角形の情報
	const int32_t TRIANGLE_AMOUNT_MAX = 15;

	Triangle* triangle[TRIANGLE_AMOUNT_MAX];
	for (int i = 0; i < TRIANGLE_AMOUNT_MAX; i++) {
		triangle[i] = new Triangle();
		triangle[i]->Initialize(directXSetup);

	}




}

//ウィンドウのメッセージ
void GameScene::WindowMSG(MSG& msg) {
	winSetup->WindowsMSG(msg);
}


//フレームの始め
void GameScene::BeginFrame() {
	directXSetup->BeginFrame();
}

void GameScene::UpDate() {


}



void GameScene::Draw() {

}


//フレーム終わり
void GameScene::EndFrame() {

}

void GameScene::Release() {

}




GameScene::~GameScene() {

}
