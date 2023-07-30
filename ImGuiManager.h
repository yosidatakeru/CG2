
#include "WinApp.h"
#include "DirectXCommon.h"

class ImGuiManager {
public:

	//コンストラクタ
	ImGuiManager();

	//初期化
	void Initialize(WinApp* winSetup, DirectXCommon* directXSetup);

	//ここからフレームが始まる
	void BeginFrame();

	//更新
	void UpDate();


	//描画前の処理
	void PreDraw();

	//描画
	void Draw(DirectXCommon* directXSetup);


	void EndFrame(DirectXCommon* directXSetup);


	//解放処理
	void Release();



private:
	
};