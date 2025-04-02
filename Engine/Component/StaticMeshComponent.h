#pragma once

#include "Component.h"
#include <memory>
#include <vector>

namespace Blue
{
    class Mesh;
    class Shader;

    // �𵨸� �����Ϳ� ���̴��� Ȱ���� �׸��� ������Ʈ
    class StaticMeshComponent : public Component
    {
    public:
        StaticMeshComponent();
        ~StaticMeshComponent();

        // �׸��� �Լ�
        virtual void Draw() override;

        // �޽� ���� �Լ�
        void SetMesh(std::shared_ptr<Mesh> newMesh);

        // ���̴� ���� �Լ�
        void AddShader(std::weak_ptr<Shader> newShader);
        
    private:
        // �޽�(�𵨸�) ������
        std::shared_ptr<Mesh> mesh;
        // ���̴� (���� �޽� ����ŭ �ʿ�)
        std::vector<std::weak_ptr<Shader>> shaders;
    };    
}
