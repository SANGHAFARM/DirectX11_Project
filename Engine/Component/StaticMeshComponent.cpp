#include "StaticMeshComponent.h"

#include "Render/Mesh.h"
#include "Shader/Shader.h"
#include "Core/Engine.h"

namespace Blue
{
    StaticMeshComponent::StaticMeshComponent()
    {
    }

    StaticMeshComponent::~StaticMeshComponent()
    {
    }

    void StaticMeshComponent::Draw()
    {
        // 서브 메시를 순회하면서 DrawCall
        uint32 meshCount = mesh->SubMeshCount();

        // 예외 처리
        if (meshCount != (uint32)shaders.size())
        {
            return;
        }
        
        for (int i = 0; i < meshCount; i++)
        {
            // 서브 메시 가져오기
            auto subMesh = mesh->GetSubMesh(i);

            // 메시가 유효하면 Draw
            if (subMesh.lock() && shaders[i].lock())
            {
                // 서브 메시 바인딩
                subMesh.lock()->Bind();
                // 셰이더 바인딩
                shaders[i].lock()->Bind();

                // DrawCall
                static ID3D11DeviceContext& context = Engine::Get().Context();                
                context.DrawIndexed(subMesh.lock()->IndexCount(), 0u, 0u);
            }
        }
    }

    void StaticMeshComponent::SetMesh(std::shared_ptr<Mesh> newMesh)
    {
        mesh = newMesh;
    }

    void StaticMeshComponent::AddShader(std::weak_ptr<Shader> newShader)
    {
        shaders.emplace_back(newShader);
    }

    bool StaticMeshComponent::UseRenderTexture()
    {
        for (auto const& shader : shaders)
        {
            if (shader.lock() && shader.lock()->UseRenderTexture())
            {
                return true;
            }
        }

        return false;
    }
}
