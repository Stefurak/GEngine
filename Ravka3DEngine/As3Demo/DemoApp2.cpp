#include "DemoApp2.h"

#include <iostream>



	DemoApp2::DemoApp2() :
		width(1024), height(768)
	{
		// Start the Engine
		m_engine.onStart();

		// Set the camera frustum
		m_cam3D.setFieldOfView(70.0f);
		m_cam3D.setViewportAspectRatio((float)width / (float)height);
		m_cam3D.setPosition(glm::vec3(0.0f, 0.0f, 4.0f));
		m_cam3D.setNearAndFarPlanes(1.0f, 1000.0f);
	}


	DemoApp2::~DemoApp2()
	{
		// empty
	}

	void DemoApp2::run()
	{
		// create the viewport
		std::string title = "Game Engine Design Assignment 2";

		ViewPort display(title, width, height, 0);
		setViewPort(display);

		init();
	}

	void DemoApp2::init()
	{

		for (int i = 0; i < 5; i++)
		{
			colourData[i] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
		}

		colourData[0] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
		colourData[1] = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
		colourData[2] = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
		colourData[3] = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
		colourData[4] = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);
		colourData[5] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);

		

		// create the shape
		/**/
		m_cube.createShape(COLOURED_CUBE, 2.0f, 2.0f, 16, 1.0f, 1.0f, 1.0f, colourData);
		MESHGL cubeMesh(m_cube.getVertices(), m_cube.getVertices().size());

		m_node1.setModel(&m_cube);
		m_sceneGraph.addNode(&m_node1);
		/**/

		//Creating a sphere
		/**/
		m_sphere.createShape(SPHERE, 1.0f, 2.0f, 16, 1.0f, 1.0f, 1.0f, colourData);
		MESHGL cubeMesh2(m_sphere.getVertices(), m_sphere.getVertices().size());

		m_node2.setModel(&m_sphere);
		m_sceneGraph.addNode(&m_node2);
		/**/

		// create the shaders
		ShaderNova tempShader;
		std::vector<std::string> shaders;
		shaders.push_back("./Assets/Shaders/basicShaderVert.glsl");
		shaders.push_back("./Assets/Shaders/basicShaderFrag.glsl");

		tempShader.compileShadersFromFile(shaders);
		tempShader.addAttributes("position");
		tempShader.addAttributes("textureCoords");
		tempShader.addAttributes("normal");
		tempShader.addAttributes("colourData");
		tempShader.linkShaders();

		// set the shaders
		setShaderProgram(tempShader);

		update();
	}

	void DemoApp2::update()
	{
		while (true)
		{
			// update the viewport
			m_viewPort.Update();
			m_viewPort.swapBuffer(cosf(m_counter), sinf(m_counter), 0.0f, 1.0f);
			m_viewPort.swapBuffer(255, 255, 255, 1);
			draw();
		}
	}

	void DemoApp2::draw()
	{
		//Sphere
		m_sphere.setRotation(glm::vec3(0, m_counter, 0));
		m_sphere.setScale(glm::vec3(2.0));
		m_cam3D.updateCamera();


		m_sceneGraph.setWireframeMode(m_cam3D.wireFrame);

		// RENDER USING THE ENGINE'S SCENE GRAPH
		for (int i = 0; i < m_sceneGraph.getWorldSize(); i++)
		{
			m_program.startUse();

			GLint camUniform = m_program.getUniformLocation("camera");
			glUniformMatrix4fv(camUniform, 1, GL_FALSE, &m_cam3D.matrix()[0][0]);

			GLint modelUniform = m_program.getUniformLocation("model");
			glUniformMatrix4fv(modelUniform, 1, GL_FALSE, &m_sceneGraph.getNodeList().at(i)->getModel()->getModel()[0][0]);

			m_engine.render(m_sceneGraph.getNodeList().at(i)->getModel(), &m_cam3D, &m_program);
		}
		//m_frustum.cameraChanged(m_cam3D.position, m_cam3D.orientation, m_cam3D.up);
		//std::cout << "POINT INSIDE FRUSTUM? " << m_frustum.isInside(glm::vec3(500, 500, 500)) << std::endl;

		m_program.stopUse();

		m_counter += 0.0005f;
	}

