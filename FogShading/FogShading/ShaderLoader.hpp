#pragma once

#include "glew.h"
#include "freeglut.h"
#include <iostream>

namespace Shader
{

	class ShaderLoader
	{
	private:

		std::string ReadShader(char *filename);
		GLuint CreateShader(GLenum shaderType,
			std::string source,
			char* shaderName);

	public:

		ShaderLoader(void);
		~ShaderLoader(void);
		GLuint CreateProgram(char* VertexShaderFilename,
			char* FragmentShaderFilename);

	};
}