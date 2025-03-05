#include "ShaderLoader.h"

namespace Blue
{
	ShaderLoader* ShaderLoader::instance = nullptr;

	ShaderLoader::ShaderLoader()
	{
		instance = this;
	}

	ShaderLoader& ShaderLoader::Get()
	{
		return *instance;
	}
}