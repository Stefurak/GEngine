#include "SceneGraph.h"

namespace Ravka3DEngine
{

	SceneGraph::SceneGraph()
	{
	}


	SceneGraph::~SceneGraph()
	{
	}

	std::vector<SceneNode*> SceneGraph::getNodeList()
	{
		return nodeList;
	}

	void SceneGraph::setWireframeMode(bool wireframeMode)
	{
		if (wireframeMode)
		{
			if (!wireframeSwitched)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				wireframeSwitched = true;
			}
		}
		else
		{
			if (wireframeSwitched)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				wireframeSwitched = false;
			}
		}
	}

	void SceneGraph::addNode(SceneNode* node)
	{

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		nodeList.push_back(node);
		worldSize++;
	}

}
