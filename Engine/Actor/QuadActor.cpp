#include "QuadActor.h"

#include "Component/StaticMeshComponent.h"

#include "Render/QuadMesh.h"
#include "render/RenderTexture.h"

#include "Resource/ShaderLoader.h"
#include "Resource/TextureLoader.h"

#include "Shader/TextureMappingShader.h"

namespace Blue
{
    QuadActor::QuadActor()
    {
        // 스태틱 메시 컴포넌트 생성
        std::shared_ptr<StaticMeshComponent> meshComponent = std::make_shared<StaticMeshComponent>();

        // 액터에 컴포넌트 추가
        AddComponent(meshComponent);

        // 리소스 로드 및 컴포넌트 설정
        meshComponent->SetMesh(std::make_shared<QuadMesh>());
        //meshComponent->SetMesh(std::make_shared<SphereMesh>());
        std::weak_ptr<TextureMappingShader> shader;
        if (ShaderLoader::Get().Load<TextureMappingShader>(shader))
        {
            meshComponent->AddShader(shader);
        }

        // 텍스처 로드 및 쉐이더 설정
        std::weak_ptr<RenderTexture> renderTexture;
        TextureLoader::Get().GetNewRenderTexture(renderTexture, 1280, 800);
        
        shader.lock()->SetTexture(renderTexture);
        
        // TextureLoader::Get().Load("5k_earth_day_map.png", diffuseMap);
        // shader.lock()->SetTexture(NormalMappingShader::ETextureBindType::Diffuse, diffuseMap);
        //
        // std::weak_ptr<Texture> normalMap;
        // TextureLoader::Get().Load("8k_earth_normal_map.png", normalMap);
        // shader.lock()->SetTexture(NormalMappingShader::ETextureBindType::NormalMap, normalMap);
    }

    void QuadActor::Tick(float deltaTime)
    {
        Actor::Tick(deltaTime);

        static const float rotationSpeed = 10.0f;
        
        // 회전
        //transform.rotation.y += deltaTime * rotationSpeed;
    }
}
