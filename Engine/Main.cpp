#include "Core/Engine.h"
#include "Level/DemoLevel.h"

#include <iostream>

using namespace Blue;

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// â ���� �� �� ���� �Լ� (Entry Point)
//int WINAPI WinMain(
//    _In_ HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_ LPSTR lpCmdLine,
//    _In_ int nShowCmd)
//{
//    // ���� ���� �� ����
//    Engine engine(1280, 800, TEXT("Engine Demo"), hInstance);
//    engine.Run();
//
//    return 0;
//}

/*
 * IA (�Է� ����) -> VS ...(Option) -> RS/������ -> PS -> OM (��� ����)
 * - VS (���� ��ȯ Object->World->View->Projection)
 * - PS (���� ó��) - PBR / ��ǻ�� / ����ŧ��
 * - ���� ������ (������ ������)
 */

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	
	Engine engine(1280, 800, TEXT("Engine Demo"), GetModuleHandle(nullptr));
	engine.SetLevel(std::make_shared<DemoLevel>());
	engine.Run();
}