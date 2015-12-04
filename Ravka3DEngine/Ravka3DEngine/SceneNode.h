#pragma once
#include "GLM\glm.hpp"
#include "SHAPEGL.h"
#include <vector>

namespace Ravka3DEngine
{
	class SceneNode
	{
	public:

		SceneNode();
		~SceneNode();


		void appendChild(SceneNode *node);
		void removeChild(SceneNode *node);

		std::vector<SceneNode*> getChildren() const;

		void setModel(SHAPEGL *_model);

		SHAPEGL* getModel() const;

		std::vector<SHAPEGL*> getModels() const;


	private:
		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 rotation;
		int numModels;
		std::vector<SceneNode*> childList;
		SHAPEGL* model;
	};
}
