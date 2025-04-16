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

		// 텍스처 설정 함수
		void SetTexture(const std::weak_ptr<Texture>& newTexture);
		
	private:
		// 텍스처 리소스
		std::weak_ptr<Texture> texture;
	};
}