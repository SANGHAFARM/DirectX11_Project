#pragma once

#include <memory>
#include <Windows.h>
#include <string>
#include <d3d11.h>

#include "../Core/Type.h"

namespace Blue
{
	class Window;
	class Renderer;
	class ShaderLoader;
	class TextureLoader;

	// ���� Ŭ����
	class Engine
	{
	public:
		Engine(uint32 width, uint32 height, const std::wstring& title, HINSTANCE hInstance);
		virtual ~Engine();

		// ���� ���� �Լ�
		void Run();

		// ������ �޽��� ó�� ����
		static LRESULT CALLBACK WindowProc(HWND hande, UINT message, WPARAM wparam, LPARAM lparam);

		// �̱��� ���� �Լ�
		static Engine& Get();

		// Getter
		ID3D11Device& Device() const;
		ID3D11DeviceContext& Context() const;

	protected:
		// â ��ü
		std::shared_ptr<Window> window;

		// ������ ��ü
		std::shared_ptr<Renderer> renderer;

		// ���̴� �δ� ��ü
		std::unique_ptr<ShaderLoader> shaderLoader;

		// �ؽ�ó �δ� ��ü
		std::unique_ptr<TextureLoader> textureLoader;

		// �̱��� ��ü
		static Engine* instance;
	};
}