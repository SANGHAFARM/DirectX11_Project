#include "QuadMesh.h"
#include "Shader/Shader.h"
#include "Shader/TextureMappingShader.h"

namespace Blue
{
	QuadMesh::QuadMesh()
	{
		// 정점 배열
		std::vector<Vertex> vertices =
		{
			Vertex(Vector3(-0.5f, 0.5f, 0.5f), Vector3(1.0f, 0.0f, 0.0f), Vector2(0.0f, 0.0f)),
			Vertex(Vector3(0.5f, 0.5f, 0.5f), Vector3(0.0f, 1.0f, 0.0f), Vector2(1.0f, 0.0f)),
			Vertex(Vector3(0.5f, -0.5f, 0.5f), Vector3(0.0f, 0.0f, 1.0f), Vector2(1.0f, 1.0f)),
			Vertex(Vector3(-0.5f, -0.5f, 0.5f), Vector3(1.0f, 1.0f, 0.0f), Vector2(0.0f, 1.0f))
		};

		// 인덱스 배열
		std::vector<uint32> indices = { 0, 1, 3, 1, 2, 3 };
		meshes.emplace_back(std::make_shared<MeshData>(vertices, indices));

		shaders.emplace_back(std::make_shared<TextureMappingShader>("T_coord.png"));
	}
}