#pragma once
#pragma once

#include <cassert>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dxcompiler.lib")



#include <cstdint>
#include <string>
#include <dxcapi.h>
#include <format>


#include"MyFunction.h"


class DirectXCommon {
public:

	DirectXCommon();

	//まとめたのが下の「Initialize」
#pragma region 初期化について
	//初期化へ

	void GenerateDXGIFactory();
	void SelectAdapter();


	void GenerateD3D12Device();


	void StopErrorWarning();


	void GenerateCommand();


	void GenerateSwapChain();

	void MakeDescriptorHeap();

	void PullResourcesFromSwapChain();

	void SetRTV();

	void InitializeDXC();

	void MakePSO();

	void GenarateViewport();
	void GenerateScissor();


#pragma endregion

	void Initialize(int32_t windowsizeWidth, int32_t windowsizeHeight, HWND hwnd_);

#pragma region whileの中身
	//whileの中身
	void BeginFlame();

	void EndFlame();

#pragma endregion


#pragma region 解放処理
	//解放
	void Release();

	void CheckRelease();

	~DirectXCommon();

#pragma endregion


#pragma region アクセッサ

	HRESULT GetHr_() {
		return hr_;
	}

	ID3D12Device* GetDevice() {
		return device_;
	}

	ID3D12GraphicsCommandList* GetCommandList() {
		return commandList_;
	}

#pragma endregion


private:
	

	////CompileShader関数
	IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils* dxcUtils,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler);



private:
	int32_t kClientWidth_;
	int32_t kClientHeight_;

	HRESULT hr_;



	HWND hwnd_;

	ID3D12Resource* vertexResource_ = nullptr;

	ID3D12PipelineState* graphicsPipelineState_ = nullptr;

	ID3DBlob* signatureBlob_ = nullptr;

	ID3DBlob* errorBlob_ = nullptr;

	ID3D12RootSignature* rootSignature_ = nullptr;

	IDxcBlob* pixelShaderBlob_ = nullptr;

	IDxcBlob* vertexShaderBlob_ = nullptr;

	HANDLE fenceEvent_ = nullptr;












	ID3D12InfoQueue* infoQueue_ = nullptr;

	//
	IDXGIFactory7* dxgiFactory_ = nullptr;
	//
	IDXGIAdapter4* useAdapter_ = nullptr;

	//
	ID3D12Device* device_ = nullptr;





	ID3D12GraphicsCommandList* commandList_ = nullptr;

	ID3D12CommandQueue* commandQueue_ = nullptr;

	D3D12_COMMAND_QUEUE_DESC commandQueueDesc_{};

	ID3D12CommandAllocator* commandAllocator_ = nullptr;





	UINT backBufferIndex_;





	IDXGISwapChain4* swapChain_ = nullptr;

	ID3D12Resource* swapChainResources_[2] = { nullptr };

	ID3D12DescriptorHeap* rtvDescriptorHeap_ = nullptr;

	D3D12_DESCRIPTOR_HEAP_DESC rtvDescriptorHeapDesc_{};



	D3D12_RENDER_TARGET_VIEW_DESC rtvDesc_{};
	D3D12_CPU_DESCRIPTOR_HANDLE rtvStartHandle_;
	D3D12_CPU_DESCRIPTOR_HANDLE rtvHandles_[2] = {};

	typedef struct D3D12_CPU_DESCRIPTOR_HANDLE {
		SIZE_T ptr_;
	}D3D12_CPU_DESCRIPTOR_HANDLE;

	D3D12_RESOURCE_BARRIER barrier_{};

	ID3D12Fence* fence_ = nullptr;

	uint64_t fenceValue_ = 0;


	ID3D12Debug1* debugController_ = nullptr;



#pragma region DXCの初期化について
	IDxcUtils* dxcUtils_ = nullptr;
	IDxcCompiler3* dxcCompiler_ = nullptr;
	D3D12_ROOT_SIGNATURE_DESC descriptionRootSignature_{};
	IDxcIncludeHandler* includeHandler_ = nullptr;

#pragma endregion

	D3D12_VIEWPORT viewport_{};
	D3D12_RECT scissorRect_{};




	D3D12_VERTEX_BUFFER_VIEW vertexBufferView_{};

	Vector4* vertexData_ = nullptr;

	IDXGIDebug1* debug_;

};
