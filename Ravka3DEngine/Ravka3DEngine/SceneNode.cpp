#include "SceneNode.h"
#include <algorithm>

namespace Ravka3DEngine
{

	SceneNode::SceneNode()
	{
		rotation = glm::vec3(0, 0, 0);
		scale = glm::vec3(1, 1, 1);
		position = glm::vec3(0, 0, 0);
		numModels = 0;
	}

	SceneNode::~SceneNode()
	{

	}

	void SceneNode::appendChild(SceneNode * node)
	{
		childList.push_back(node);
	}

	void SceneNode::removeChild(SceneNode * node)
	{

	}

	std::vector<SceneNode*> SceneNode::getChildren() const
	{
		return childList;
	}


	void SceneNode::setModel(SHAPEGL * _model)
	{

		model = _model;
		numModels++;
	}

	SHAPEGL * SceneNode::getModel() const
	{
		return model;
	}

	std::vector<SHAPEGL*> SceneNode::getModels() const
	{
		std::vector<SHAPEGL*> models;


		std::vector<SceneNode*> childNodes;
		childNodes = childList;
		for (int i = 0; i < this->childList.size(); i++)
		{
			for (int j = 0; j < childList.at(i)->numModels; j++)
			{
				models.push_back(this->childList.at(i)->getModels().at(j));

			}
		}

		return models;

	}
}
