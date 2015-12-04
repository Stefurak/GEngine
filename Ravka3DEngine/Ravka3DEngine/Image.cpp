#include "Image.h"

namespace Ravka3DEngine
{
	Image::Image()
	{
	}

	void Image::LoadImage(char* imageName)
	{
		image = SOIL_load_image(imageName, &width, &height, 0, SOIL_LOAD_RGB);
	}

	unsigned char* Image::GetImage()
	{
		if (image != nullptr)
		{
			return image;
		}
		else
			return 0;
	}


}