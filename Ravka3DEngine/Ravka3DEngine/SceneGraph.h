#pragma once
#include "SceneNode.h"
#pragma once

namespace Ravka3DEngine
{

	class SceneGraph
	{
	public:
		SceneGraph();
		~SceneGraph();

		SceneNode* getRootSceneNode()
		{
			return rootSceneNode;
		}

		std::vector<SceneNode*> getNodeList();

		void setWireframeMode(bool wireframeMode);

		void addNode(SceneNode* node);

		int getWorldSize()
		{
			return worldSize;
		}
	private:
		std::vector<SceneNode*> nodeList;
		SceneNode *rootSceneNode;
		int worldSize;
		bool wireframeSwitched;
	};


}
