#pragma once
#include "GLM\glm.hpp"
#include "glew.h"
#include <string>
#include <vector>
#include "src\SOIL.h"

namespace Ravka3DEngine
{
	class Image
	{
	public:
		Image();
		void LoadImage(char* imageName);
		unsigned char* GetImage();
		void Use();

	private:
		unsigned char* image;
		int width, height;
	};
}