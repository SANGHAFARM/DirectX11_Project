#pragma once

#include "Mesh.h"

namespace Blue
{
	// �ﰢ�� �޽�
	class QuadMesh : public Mesh
	{
	public:
		QuadMesh();

		void Update(float deltaTime);

	private:
		void Rotate(float angle);
	};
}
