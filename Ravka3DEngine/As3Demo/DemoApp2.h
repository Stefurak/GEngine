#pragma once
#include <Ravka3DEngine\GameEngine.h>

using namespace Ravka3DEngine;


	class DemoApp2
	{
	public:
		DemoApp2();
		~DemoApp2();

		void run();
		bool wireFrame = false;


	private:

		void init();
		void draw();
		void update();

		void setShaderProgram(ShaderNova & program) { m_program = program; }
		void setViewPort(ViewPort & view) { m_viewPort = view; }

		GameEngine m_engine;
		ShaderNova m_program;
		glm::vec4 colourData[6];
		SHAPEGL m_cube;
		SHAPEGL m_sphere;
		Camera3D m_cam3D;
		ViewPort m_viewPort;
		int width, height;
		SceneNode m_node1;
		SceneNode m_node2;
		SceneGraph m_sceneGraph;
		Frustum m_frustum;
		float m_counter = 0.0f;
	};



