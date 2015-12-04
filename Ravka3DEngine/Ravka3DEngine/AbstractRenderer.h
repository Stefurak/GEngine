#pragma once
//#include "Model.h" // To get access to Vertex and BasicTypes
//#include "BasicTypes.h" // To be able to actualy use Primitives

#include "PrimitiveType.h"
#include "Camera3D.h"
#include "ShaderNova.h"
#include "SHAPEGL.h"

namespace Ravka3DEngine
{
	class AbstractRenderer
	{

	public:
		AbstractRenderer() { /*empty*/ }
		~AbstractRenderer() { /*empty*/ }
		virtual void renderPrimitive(PrimitiveTypeDef type) = 0;
		virtual void renderPrimitive(SHAPEGL * shape, Camera3D * camera, ShaderNova * program) = 0;
		//virtual void renderModel(const ModelType type) = 0;
	};
}

