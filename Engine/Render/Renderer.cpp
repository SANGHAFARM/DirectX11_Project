#include "Renderer.h"
#include "../Math/Vector3.h"
#include "TriangleMesh.h"
#include "QuadMesh.h"
#include "Core/Common.h"

#include <vector>
#include <d3dcompiler.h>

namespace Blue
{
	Renderer::Renderer(uint32 width, uint32 height, HWND window)
	{
		// ��ġ ������ ����ϴ� �ɼ�
		uint32 flag = 0u;

#if _DEBUG
		flag |= D3D11_CREATE_DEVICE_DEBUG;
#endif
		// ������ ���̺귯�� ����
		D3D_FEATURE_LEVEL featureLevels[] =
		{
			D3D_FEATURE_LEVEL_11_1,
			D3D_FEATURE_LEVEL_11_0
		};

		// ����ü�� ���� ����ü
		//DXGI_MODE_DESC BufferDesc;
		//DXGI_SAMPLE_DESC SampleDesc;
		//DXGI_USAGE BufferUsage;
		//UINT BufferCount;
		//HWND OutputWindow;
		//BOOL Windowed;
		//DXGI_SWAP_EFFECT SwapEffect;
		//UINT Flags;

		// ��ġ ����
		ThrowIfFailed(D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			flag,
			featureLevels,
			_countof(featureLevels),
			D3D11_SDK_VERSION,
			&device,
			nullptr,
			&context
		), TEXT("Failed to create devices."));

		// IDXGIFactory ���ҽ� ����
		IDXGIFactory* factory = nullptr;
		//CreateDXGIFactory(__uuidof(factory), reinterpret_cast<void**>(&factory));
		ThrowIfFailed(CreateDXGIFactory(IID_PPV_ARGS(&factory)), TEXT("Failed to create dxgifactory"));

		// ���� ü�� ���� ����ü
		DXGI_SWAP_CHAIN_DESC swapChainDesc = { };
		swapChainDesc.Windowed = true;			// â ���
		swapChainDesc.OutputWindow = window;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 2;			// ����� ����
		swapChainDesc.SampleDesc.Count = 1;		// ��Ƽ ���ø� ����
		swapChainDesc.SampleDesc.Quality = 0;	// ��Ƽ ���ø� ����
		swapChainDesc.BufferDesc.Width = width;
		swapChainDesc.BufferDesc.Height = height;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;

		// ��ġ ����
		//ThrowIfFailed(D3D11CreateDeviceAndSwapChain(
		//	nullptr,
		//	D3D_DRIVER_TYPE_HARDWARE,
		//	nullptr,
		//	flag,
		//	featureLevels,
		//	_countof(featureLevels),
		//	D3D11_SDK_VERSION,
		//	&swapChainDesc,
		//	&swapChain,
		//	&device,
		//	nullptr,
		//	&context
		//), TEXT("Failed to create devices"));

		// SwapChain ����
		ThrowIfFailed(factory->CreateSwapChain(
			device,
			&swapChainDesc,
			&swapChain
		), TEXT("Failed to create swap chain."));

		// ���� Ÿ�� �� ����
		ID3D11Texture2D* backbuffer = nullptr;
		//swapChain->GetBuffer(0, __uuidof(backbuffer), reinterpret_cast<void**>(&backbuffer));

		ThrowIfFailed(swapChain->GetBuffer(0, IID_PPV_ARGS(&backbuffer)), TEXT("Failed to get back buffer."));

		ThrowIfFailed(device->CreateRenderTargetView(backbuffer, nullptr, &renderTargetView), TEXT("Failed to create render target view."));
		
		// ���� Ÿ�� �� ���ε� (����)
		//context->OMSetRenderTargets(1, &renderTargetView, nullptr);

		// ����Ʈ (ȭ��)
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;
		viewport.Width = (float)width;
		viewport.Height = (float)height;
		viewport.MaxDepth = 1.0f;
		viewport.MinDepth = 0.0f;

		// ����Ʈ ����
		context->RSSetViewports(1, &viewport);
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Draw()
	{
		// @�ӽ�/Test
		//if (triangleMesh == nullptr)
		//{
		//	triangleMesh = std::make_unique<TriangleMesh>();
		//	triangleMesh->transform.scale = Vector3::One * 0.5f;
		//	triangleMesh->transform.position.y = 0.5f;
		//}

		if (quadMesh == nullptr)
		{
			quadMesh = std::make_unique<QuadMesh>();
			quadMesh->transform.scale = Vector3::One * 0.5f;
			quadMesh->transform.position.x = 0.5f;
		}

		if (quadMesh2 == nullptr)
		{
			quadMesh2 = std::make_unique<QuadMesh>();
			quadMesh2->transform.scale = Vector3::One * 0.5f;
			quadMesh2->transform.position.x = -0.5f;
		}

		// �׸��� �� �۾� (BeginScene)
		context->OMSetRenderTargets(1, &renderTargetView, nullptr);

		// �����/Clear
		float color[] = { 0.6f, 0.7f, 0.8f, 1.0f };
		context->ClearRenderTargetView(renderTargetView, color);

		// @Test
		quadMesh->Update(1.0f / 60.0f);
		quadMesh2->Update(1.0f / 60.0f);

		// ��ο�
		//triangleMesh->Draw();
		quadMesh->Draw();
		quadMesh2->Draw();

		// ���� ��ȯ (EndScene/Present)
		swapChain->Present(1u, 0u);
	}
}