#pragma once
#include "DirectXCommon.h"

#include "Vector4.h"
#include "Matrix4x4.h"
#include "Matrix4x4Calculation.h"
#include "Transform.h"

class Triangle {
public:
	Triangle();


	void Initialize(DirectXCommon* directXSetup);

	void GenarateVertexResource();

	////VertexBufferViewを作成
	void GenerateVertexBufferView();

	//Material用のリソースを作る
	void GenerateMaterialResource();

	//TransformationMatrix用のResourceを作る
	void GenerateTransformationMatrixResource();

	void Draw(Vector4 left,Vector4 top,  Vector4 right,Transform transform,Matrix4x4 viewMatrix,Matrix4x4 projectionMatrix ,Vector4 color);


	//Resource作成の関数化
	ID3D12Resource* CreateBufferResource(ID3D12Device* device,size_t sizeInBytes);


	void Release();
	
	~Triangle();





private:

	DirectXCommon* directXSetup_ = nullptr;

	HRESULT hr_;
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView_;

	//Resource
	ID3D12Resource* vertexResouce_;

	D3D12_HEAP_PROPERTIES uploadHeapProperties_{};
	D3D12_RESOURCE_DESC vertexResourceDesc_{};

	//Resourceにデータを書き込む
	Vector4* vertexData_ = nullptr;
	
	
	//マテリアル用のリソースを作る
	ID3D12Resource* materialResource = nullptr;
	Vector4* materialData_ = nullptr;
	

	//TransformationMatrix用のResource
	ID3D12Resource* wvpResource_ = nullptr;
	Matrix4x4* wvpData_=nullptr;

	
};
