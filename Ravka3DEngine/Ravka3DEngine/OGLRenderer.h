#pragma once
#include "ViewPort.h"
#include "ShaderNova.h"
#include "Camera3D.h"
#include "SHAPEGL.h"
#include "AbstractRenderer.h"

namespace Ravka3DEngine
{
	class OGLRenderer
		: public AbstractRenderer
	{
	public:
		OGLRenderer();
		~OGLRenderer();

		virtual void renderPrimitive(SHAPEGL * shape, Camera3D * camera, ShaderNova * program) override;
		virtual void renderPrimitive(PrimitiveTypeDef type) override;
	};
}