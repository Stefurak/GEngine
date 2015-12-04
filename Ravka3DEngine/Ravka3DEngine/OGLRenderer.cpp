#include "OGLRenderer.h"
#include <iostream>

namespace Ravka3DEngine
{
	OGLRenderer::OGLRenderer()
	{
		// empty
	}

	OGLRenderer::~OGLRenderer()
	{
		// empty
	}

	void OGLRenderer::renderPrimitive(SHAPEGL * shape, Camera3D * camera, ShaderNova * program)
	{
		shape->draw();

		//program->stopUse();
	}

	void OGLRenderer::renderPrimitive(PrimitiveTypeDef type)
	{

	}

}