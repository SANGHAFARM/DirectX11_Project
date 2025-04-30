#include "DemoLevel.h"

#include "Actor/Actor.h"
#include "Actor/QuadActor.h"
#include "Actor/SphereActor.h"
#include "Actor/CameraActor.h"

#include "Math/Transform.h"
#include "Component/CameraComponent.h"

#include "Resource/ShaderLoader.h"


namespace Blue
{
    DemoLevel::DemoLevel()
    {
        // 데모 씬(레벨) 구성

        // 액터 생성
        std::shared_ptr<SphereActor> actor = std::make_shared<SphereActor>();
        std::shared_ptr<QuadActor> actor2 = std::make_shared<QuadActor>();
        std::shared_ptr<QuadActor> actor3 = std::make_shared<QuadActor>();
        actor->transform.position.x = -1.0f;
        actor2->transform.position.x = 1.0f;
        actor3->transform.position.x = 2.5f;
        
        // 카메라 액터 생성
        std::shared_ptr<CameraActor> cameraActor = std::make_shared<CameraActor>();
        cameraActor->transform.position.z = -3.0f;
        //cameraActor->AddComponent(std::make_shared<CameraComponent>());        

        // 액터를 레벨에 추가
        AddActor(actor);
        AddActor(actor2);
        AddActor(actor3);
        AddActor(cameraActor);
    }

    DemoLevel::~DemoLevel()
    {
    }
}
