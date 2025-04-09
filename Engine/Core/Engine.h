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
	class ModelLoader;
	class Level;
	class InputController;

	// ���� Ŭ����
	class Engine
	{
	public:
		Engine(uint32 width, uint32 height, const std::wstring& title, HINSTANCE hInstance);
		virtual ~Engine();

		// ���� ���� �Լ�
		void Run();

		// ���� ���� ���� �Լ�
		void SetLevel(std::shared_ptr<Level> newLevel);

		// ������ �޽��� ó�� ����
		static LRESULT CALLBACK WindowProc(HWND hande, UINT message, WPARAM wparam, LPARAM lparam);

		// �̱��� ���� �Լ�
		static Engine& Get();

		// ȭ�� ũ�� ���� �̺�Ʈ ���� �Լ�
		void OnResize(uint32 width, uint32 height);

		// ���� ���� �Լ�
		void Quit();

		// Getter
		ID3D11Device& Device() const;
		ID3D11DeviceContext& Context() const;

	protected:
		// ���� ���� �÷���
		bool isQuit = false;
		
		// â ��ü
		std::shared_ptr<Window> window;

		// ������ ��ü
		std::shared_ptr<Renderer> renderer;

		// ���̴� �δ� ��ü
		std::unique_ptr<ShaderLoader> shaderLoader;

		// �ؽ�ó �δ� ��ü
		std::unique_ptr<TextureLoader> textureLoader;

		// �� �δ� ��ü
		std::unique_ptr<ModelLoader> modelLoader;

		// �Է� ������ ��ü
		std::unique_ptr<InputController> inputController;

		// ���� ����
		std::shared_ptr<Level> mainLevel;

		// �̱��� ��ü
		static Engine* instance;
	};
}
