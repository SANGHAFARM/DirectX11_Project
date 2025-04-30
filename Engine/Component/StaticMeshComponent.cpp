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
        // ���� �޽ø� ��ȸ�ϸ鼭 DrawCall
        uint32 meshCount = mesh->SubMeshCount();

        // ���� ó��
        if (meshCount != (uint32)shaders.size())
        {
            return;
        }
        
        for (int i = 0; i < meshCount; i++)
        {
            // ���� �޽� ��������
            auto subMesh = mesh->GetSubMesh(i);

            // �޽ð� ��ȿ�ϸ� Draw
            if (subMesh.lock() && shaders[i].lock())
            {
                // ���� �޽� ���ε�
                subMesh.lock()->Bind();
                // ���̴� ���ε�
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
