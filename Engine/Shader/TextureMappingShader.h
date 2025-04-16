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
		TextureMappingShader(const std::string& textureName);
		
		virtual void Bind() override;

		// �ؽ�ó ���� �Լ�
		void SetTexture(const std::weak_ptr<Texture>& newTexture);
		
	private:
		// �ؽ�ó ���ҽ�
		std::weak_ptr<Texture> texture;
	};
}