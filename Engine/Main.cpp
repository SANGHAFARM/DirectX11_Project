#include "Core/Engine.h"
#include "Level/DemoLevel.h"

#include <iostream>

using namespace Blue;

// 창 모드로 할 때 메인 함수 (Entry Point)
//int WINAPI WinMain(
//    _In_ HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_ LPSTR lpCmdLine,
//    _In_ int nShowCmd)
//{
//    // 엔진 생성 및 실행
//    Engine engine(1280, 800, TEXT("Engine Demo"), hInstance);
//    engine.Run();
//
//    return 0;
//}

/*
 * IA (입력 정리) -> VS ...(Option) -> RS/보간기 -> PS -> OM (출력 조립)
 * - VS (정점 변환 Object->World->View->Projection)
 * - PS (조명 처리) - PBR / 디퓨즈 / 스페큘러
 * - 엔진 개발자 (렌더러 개발자)
 */

int main()
{
	Engine engine(1280, 800, TEXT("Engine Demo"), GetModuleHandle(nullptr));
	engine.SetLevel(std::make_shared<DemoLevel>());
	engine.Run();
}