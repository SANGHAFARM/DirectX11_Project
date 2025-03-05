#pragma once

#include "Shader.h"

#include <memory>

namespace Blue
{
	class Texture;

	class TextureMappingShader : public Shader
	{
	public:
		TextureMappingShader();
		TextureMappingShader(const std::string& textureName = "");
				
		virtual void Bind() override;

	private:
		// �ؽ�ó ���ҽ�
		std::weak_ptr<Texture> texture;
	};
}