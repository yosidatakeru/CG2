#pragma once

#include "DirectXCommon.h"




class Triangle {
public:
	Triangle();

	void Initialize(DirectXCommon* directXSetup);

	void GenarateVertexResource();

	void Draw();

	void SetVertexData0(Vector4 vD0);
	void SetVertexData1(Vector4 vD1);
	void SetVertexData2(Vector4 vD2);



	void Release();

	~Triangle();



private:

	DirectXCommon* directXCommon = nullptr;

	D3D12_VERTEX_BUFFER_VIEW vertexBufferView_ = {};
	ID3D12Resource* vertexResouce_ = nullptr;

	//Resourceにデータを書き込む
	Vector4* vertexData_ = nullptr;




};
