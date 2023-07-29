#include "Triangle.h"
Triangle::Triangle() {

}

void Triangle::Initialize(DirectXCommon* directXSetup) {
	directXCommon = directXSetup;



	GenarateVertexResource();

}

void Triangle::SetVertexData0(Vector4 vD0) {
	vertexData_[0] = vD0;
}

void Triangle::SetVertexData1(Vector4 vD1) {
	vertexData_[1] = vD1;
}

void Triangle::SetVertexData2(Vector4 vD2) {
	vertexData_[2] = vD2;
}

//三角形
void Triangle::GenarateVertexResource() {
	////VertexResourceを生成
	//頂点リソース用のヒープを設定
	D3D12_HEAP_PROPERTIES uploadHeapProperties{};
	uploadHeapProperties.Type = D3D12_HEAP_TYPE_UPLOAD;

	//頂点リソースの設定
	D3D12_RESOURCE_DESC vertexResourceDesc{};
	//バッファリソース。テクスチャの場合はまた別の設定をする
	vertexResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	vertexResourceDesc.Width = sizeof(Vector4) * 3;
	//バッファの場合はこれらは1にする決まり
	vertexResourceDesc.Height = 1;
	vertexResourceDesc.DepthOrArraySize = 1;
	vertexResourceDesc.MipLevels = 1;
	vertexResourceDesc.SampleDesc.Count = 1;

	//バッファの場合はこれにする決まり
	vertexResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;



	//実際に頂点リソースを作る
	//ID3D12Resource* vertexResource_ = nullptr;
	//hrは調査用

	HRESULT hr_ = directXCommon->GetDevice()->CreateCommittedResource(
		&uploadHeapProperties,
		D3D12_HEAP_FLAG_NONE,
		&vertexResourceDesc,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr, IID_PPV_ARGS(&vertexResouce_));
	assert(SUCCEEDED(hr_));





	////VertexBufferViewを作成
	//頂点バッファビューを作成する

	//リソースの先頭のアドレスから使う
	vertexBufferView_.BufferLocation = vertexResouce_->GetGPUVirtualAddress();
	//使用するリソースのサイズは頂点３つ分のサイズ
	vertexBufferView_.SizeInBytes = sizeof(Vector4) * 3;
	//１頂点あたりのサイズ
	vertexBufferView_.StrideInBytes = sizeof(Vector4);
	//書き込むためのアドレスを取得
	vertexResouce_->Map(0, nullptr, reinterpret_cast<void**>(&vertexData_));
}



void Triangle::Draw() {
	////VertexResourceを生成
	//GenarateVertexResource();


	////左下
	//vertexData_[0] = left;
	////上
	//vertexData_[1] =  top ;
	////右下
	//vertexData_[2] =  right ;
	////範囲外は危険だよ！！



	//RootSignatureを設定。PSOに設定しているけど別途設定が必要
	directXCommon->GetCommandList()->IASetVertexBuffers(0, 1, &vertexBufferView_);
	//形状を設定。PSOに設定しているものとはまた別。同じものを設定すると考えよう
	directXCommon->GetCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//描画(DrawCall)３頂点で１つのインスタンス。
	directXCommon->GetCommandList()->DrawInstanced(3, 1, 0, 0);


}

void Triangle::Release() {
	vertexResouce_->Release();
}

Triangle::~Triangle() {

}



