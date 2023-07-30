#include "Triangle.h"
Triangle::Triangle() {

}



void Triangle::Initialize(DirectXCommon* directXCommon) {
	directXCommon_ = directXCommon;

	//ここでBufferResourceを作る
	vertexResouce_ = CreateBufferResource(sizeof(Vector4) * 3);
	materialResource = CreateBufferResource(sizeof(Vector4) * 3);

	GenerateVertexBufferView();
	//GenarateVertexResource();



}


//Resource作成の関数化
//deviceいるかな？と思ったので消します！
ID3D12Resource* Triangle::CreateBufferResource(size_t sizeInBytes) {
	//void返り値も忘れずに
	ID3D12Resource* resource = nullptr;

	////VertexResourceを生成
	//頂点リソース用のヒープを設定

	uploadHeapProperties_.Type = D3D12_HEAP_TYPE_UPLOAD;

	//頂点リソースの設定

	//バッファリソース。テクスチャの場合はまた別の設定をする
	vertexResourceDesc_.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	vertexResourceDesc_.Width = sizeInBytes;
	//バッファの場合はこれらは1にする決まり
	vertexResourceDesc_.Height = 1;
	vertexResourceDesc_.DepthOrArraySize = 1;
	vertexResourceDesc_.MipLevels = 1;
	vertexResourceDesc_.SampleDesc.Count = 1;

	//バッファの場合はこれにする決まり
	vertexResourceDesc_.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

	//実際に頂点リソースを作る
	//ID3D12Resource* vertexResource_ = nullptr;
	//hrは調査用
	hr_ = directXCommon_->GetDevice()->CreateCommittedResource(
		&uploadHeapProperties_,
		D3D12_HEAP_FLAG_NONE,
		&vertexResourceDesc_,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr, IID_PPV_ARGS(&resource));
	assert(SUCCEEDED(hr_));

	return resource;
}



//頂点バッファビューを作成する
void Triangle::GenerateVertexBufferView() {

	//リソースの先頭のアドレスから使う
	vertexBufferView_.BufferLocation = vertexResouce_->GetGPUVirtualAddress();
	//使用するリソースのサイズは頂点３つ分のサイズ
	vertexBufferView_.SizeInBytes = sizeof(Vector4) * 3;
	//１頂点あたりのサイズ
	vertexBufferView_.StrideInBytes = sizeof(Vector4);
	//書き込むためのアドレスを取得
	vertexResouce_->Map(0, nullptr, reinterpret_cast<void**>(&vertexData_));
}


//三角形
void Triangle::GenarateVertexResource() {


#pragma region 02_01で移動する

	////VertexResourceを生成
	//頂点リソース用のヒープを設定

	uploadHeapProperties_.Type = D3D12_HEAP_TYPE_UPLOAD;

	//頂点リソースの設定
	D3D12_RESOURCE_DESC vertexResourceDesc_{};
	//バッファリソース。テクスチャの場合はまた別の設定をする
	vertexResourceDesc_.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	vertexResourceDesc_.Width = sizeof(Vector4) * 3;
	//バッファの場合はこれらは1にする決まり
	vertexResourceDesc_.Height = 1;
	vertexResourceDesc_.DepthOrArraySize = 1;
	vertexResourceDesc_.MipLevels = 1;
	vertexResourceDesc_.SampleDesc.Count = 1;

	//バッファの場合はこれにする決まり
	vertexResourceDesc_.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;



	//実際に頂点リソースを作る
	//ID3D12Resource* vertexResource_ = nullptr;
	//hrは調査用
	hr_ = directXCommon_->GetDevice()->CreateCommittedResource(
		&uploadHeapProperties_,
		D3D12_HEAP_FLAG_NONE,
		&vertexResourceDesc_,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr, IID_PPV_ARGS(&vertexResouce_));
	assert(SUCCEEDED(hr_));

#pragma endregion

	//頂点バッファビューを作成する
	GenerateVertexBufferView();

}







//Material用のResourceを作る
void Triangle::GenerateMaterialResource() {
	////マテリアl用のリソースを作る。今回はcolor1つ分のサイズを用意する
	//materialResource = CreateBufferResource(directXSetup_->GetDevice(), sizeof(Vector4));
	////マテリアルにデータを書き込む
	//Vector4* materialData_ = nullptr;
	//
	////書き込むためのアドレスを取得
	////reinterpret_cast...char* から int* へ、One_class* から Unrelated_class* へなどの変換に使用
	//materialResource->Map(0, nullptr, reinterpret_cast<void**>(&materialData_));
	//
	////今回は赤を書き込んでみる
	//*materialData_ = Vector4(1.0f, 0.0f, 0.0, 1.0f);

	//サイズに注意を払ってね！！！！！
	//どれだけのサイズが必要なのか考えよう
}


void Triangle::Draw(Vector4 left, Vector4 top, Vector4 right, Vector4 color) {
	////VertexResourceを生成
	//GenarateVertexResource();



	//左下
	vertexData_[0] = left;
	//上
	vertexData_[1] = top;
	//右下
	vertexData_[2] = right;
	//範囲外は危険だよ！！

	//マテリアルにデータを書き込む


	//書き込むためのアドレスを取得
	//reinterpret_cast...char* から int* へ、One_class* から Unrelated_class* へなどの変換に使用
	materialResource->Map(0, nullptr, reinterpret_cast<void**>(&materialData_));

	//今回は赤を書き込んでみる
	*materialData_ = color;



	//RootSignatureを設定。PSOに設定しているけど別途設定が必要
	directXCommon_->GetCommandList()->IASetVertexBuffers(0, 1, &vertexBufferView_);
	//形状を設定。PSOに設定しているものとはまた別。同じものを設定すると考えよう
	directXCommon_->GetCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	//マテリアルCBufferの場所を設定
	//ここでの[0]はregisterの0ではないよ。rootParameter配列の0番目
	directXCommon_->GetCommandList()->SetGraphicsRootConstantBufferView(0, materialResource->GetGPUVirtualAddress());
	//描画(DrawCall)３頂点で１つのインスタンス。
	directXCommon_->GetCommandList()->DrawInstanced(3, 1, 0, 0);


}



void Triangle::Release() {
	vertexResouce_->Release();
	materialResource->Release();
}

Triangle::~Triangle() {

}

