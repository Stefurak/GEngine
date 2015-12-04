#include "MESHGL.h"

namespace Ravka3DEngine
{
	MESHGL::MESHGL()
	{
	}

	MESHGL::MESHGL(std::vector<Vertex> & vertices, unsigned int numVertices, bool skyBox /* = false */)
	{
		if (image.GetImage() != 0)
			loadTexture(image.GetImage());



		m_vertexArrayObject = new GLuint;
		switch (skyBox)
		{
		case true:
			m_drawCount = numVertices;

			// Create Space for an Vertex array
			glGenVertexArrays(1, m_vertexArrayObject);

			// Binding the vertex array object make it so that any operation that effects a vertex array object, will affect this vertex array object
			glBindVertexArray(*m_vertexArrayObject);


			positions.reserve(numVertices);
			cubeTexCoords.reserve(numVertices);
			normals.reserve(numVertices);

			for (unsigned int i = 0; i < numVertices; i++)
			{
				positions.push_back(*vertices[i].getPosition());
				cubeTexCoords.push_back(*vertices[i].getSkyBoxTexCoords());
				normals.push_back(*vertices[i].getNormals());
			}


			// Generate all the buffers that we need so we can write to them.
			glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);


			//////---POSITIONS---/////////////////////////////////////////////////////////////////

			// Binding the buffer to the GPU
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]); // GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)

																			  // Store all our vertex data into the buffer (array)
			glBufferData
				(
					GL_ARRAY_BUFFER, // think of this as an array,
					(numVertices * sizeof(positions[0])), // size of array,
					&positions[0], // the array of vertices we want to store,
					GL_STATIC_DRAW // GL_STATIC_DRAW -- the data will not be changed, it doesn't need to be accessed repeatedly
					);

			// This tells the GPU that there are going to be attributes for these Vertices
			glEnableVertexAttribArray(0);

			// This tells the GPU how to actually read each attribute into an array
			glVertexAttribPointer(
				POSITION_VB, // Which attribute array its being told how to interpret
				3, // how many pieces of data in that attribute
				GL_FLOAT, // what kind of data are these attributes
				GL_FALSE, // Tell the GPU if you want to Normalize it
				0, // Tell the GPU how many pieces of data to skip between to find the next attribute
				0); // where to start to find the first attribute

					/////////////////////////////////////////////////////////////////////////////////////////////////

					///////---TEXTURE COORDINATES---/////////////////////////////////////////////////////////////////

					// Binding the buffer to the GPU
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORDS_VB]); // GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)

																			   // Store all our vertex data into the buffer (array)
			glBufferData
				(
					GL_ARRAY_BUFFER, // think of this as an array,
					(numVertices * sizeof(cubeTexCoords[0])), // size of array,
					&cubeTexCoords[0], // the array of vertices we want to store,
					GL_STATIC_DRAW // GL_STATIC_DRAW -- the data will not be changed, it doesn't need to be accessed repeatedly
					);

			// This tells the GPU that there are going to be attributes for these Vertices
			glEnableVertexAttribArray(1);

			// This tells the GPU how to actually read each attribute into an array
			glVertexAttribPointer(
				TEXCOORDS_VB, // Which attribute array its being told how to interpret
				3, // how many pieces of data in that attribute
				GL_FLOAT, // what kind of data are these attributes
				GL_FALSE, // Tell the GPU if you want to Normalize it
				0, // Tell the GPU how many pieces of data to skip between to find the next attribute
				0); // where to start to find the first attribute

					/////////////////////////////////////////////////////////////////////////////////////////


					////////---NORMALS---////////////////////////////////////////////////////////////////////

					// Binding the buffer to the GPU
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMALS_VB]); // GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)

																			 // Store all our vertex data into the buffer (array)
			glBufferData
				(
					GL_ARRAY_BUFFER, // think of this as an array,
					(numVertices * sizeof(normals[0])), // size of array,
					&normals[0], // the array of vertices we want to store,
					GL_STATIC_DRAW // GL_STATIC_DRAW -- the data will not be changed, it doesn't need to be accessed repeatedly
					);

			// This tells the GPU that there are going to be attributes for these Vertices
			glEnableVertexAttribArray(2);

			// This tells the GPU how to actually read each attribute into an array
			glVertexAttribPointer(
				NORMALS_VB, // Which attribute array its being told how to interpret
				3, // how many pieces of data in that attribute
				GL_FLOAT, // what kind of data are these attributes
				GL_FALSE, // Tell the GPU if you want to Normalize it
				0, // Tell the GPU how many pieces of data to skip between to find the next attribute
				0); // where to start to find the first attribute


					//////// Binding the buffer to the GPU
					//////glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
					//////// GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)

					//////// Store all our vertex data into the buffer (array)
					//////glBufferData(GL_ELEMENT_ARRAY_BUFFER, (vertices.size()), &vertices[0], GL_STATIC_DRAW);


					// This stops the GPU from affecting the vertex array object that we previously bound to the gpu, effectively unbinds it.
			glBindVertexArray(0);

			/////////////////////////////////////////////////////////////////////////////////////////
			break;


		case false:
			m_drawCount = numVertices;

			// Create Space for a Vertex array
			glGenVertexArrays(1, m_vertexArrayObject);

			// Binding the vertex array object make it so that any operation that effects a vertex array object, will affect this vertex array object
			glBindVertexArray(*m_vertexArrayObject);


			/////////////////ADDED IN TUT 4/////////////////////////////////////////

			positions.reserve(m_drawCount);
			textureCoords.reserve(m_drawCount);
			normals.reserve(m_drawCount);
			colourData.reserve(m_drawCount);

			for (unsigned int i = 0; i < m_drawCount; i++)
			{
				positions.push_back(*vertices[i].getPosition());
				textureCoords.push_back(*vertices[i].getTextureCoords());
				normals.push_back(*vertices[i].getNormals());
				colourData.push_back(*vertices[i].getColourData());
			}


			// Generate all the buffers that we need so we can write to them.
			glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);


			//////---POSITIONS---/////////////////////////////////////////////////////////////////

			// Binding the buffer to the GPU
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]); // GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)

																			  // Store all our vertex data into the buffer (array)
			glBufferData
				(
					GL_ARRAY_BUFFER, // think of this as an array,
					(m_drawCount * sizeof(positions[0])), // size of array,
					&positions[0], // the array of vertices we want to store,
					GL_STATIC_DRAW // GL_STATIC_DRAW -- the data will not be changed, it doesn't need to be accessed repeatedly
					);

			// This tells the GPU that there are going to be attributes for these Vertices
			glEnableVertexAttribArray(0);

			// This tells the GPU how to actually read each attribute into an array
			glVertexAttribPointer(
				POSITION_VB, // Which attribute array its being told how to interpret
				3, // how many pieces of data in that attribute
				GL_FLOAT, // what kind of data are these attributes
				GL_FALSE, // Tell the GPU if you want to Normalize it
				0, // Tell the GPU how many pieces of data to skip between to find the next attribute
				(void *)0); // where to start to find the first attribute

							/////////////////////////////////////////////////////////////////////////////////////////////////

							///////---TEXTURE COORDINATES---/////////////////////////////////////////////////////////////////

							// Binding the buffer to the GPU
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORDS_VB]); // GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)

																			   // Store all our vertex data into the buffer (array)
			glBufferData
				(
					GL_ARRAY_BUFFER, // think of this as an array,
					(m_drawCount * sizeof(textureCoords[0])), // size of array,
					&textureCoords[0], // the array of vertices we want to store,
					GL_STATIC_DRAW // GL_STATIC_DRAW -- the data will not be changed, it doesn't need to be accessed repeatedly
					);

			// This tells the GPU that there are going to be attributes for these Vertices
			glEnableVertexAttribArray(1);

			// This tells the GPU how to actually read each attribute into an array
			glVertexAttribPointer(
				TEXCOORDS_VB, // Which attribute array its being told how to interpret
				2, // how many pieces of data in that attribute
				GL_FLOAT, // what kind of data are these attributes
				GL_FALSE, // Tell the GPU if you want to Normalize it
				0, // Tell the GPU how many pieces of data to skip between to find the next attribute
				(void *)0); // where to start to find the first attribute

							/////////////////////////////////////////////////////////////////////////////////////////


							////////---NORMALS---////////////////////////////////////////////////////////////////////

							// Binding the buffer to the GPU
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMALS_VB]); // GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)

																			 // Store all our vertex data into the buffer (array)
			glBufferData
				(
					GL_ARRAY_BUFFER, // think of this as an array,
					(m_drawCount * sizeof(normals[0])), // size of array,
					&normals[0], // the array of vertices we want to store,
					GL_STATIC_DRAW // GL_STATIC_DRAW -- the data will not be changed, it doesn't need to be accessed repeatedly
					);

			// This tells the GPU that there are going to be attributes for these Vertices
			glEnableVertexAttribArray(2);

			// This tells the GPU how to actually read each attribute into an array
			glVertexAttribPointer(
				NORMALS_VB, // Which attribute array its being told how to interpret
				3, // how many pieces of data in that attribute
				GL_FLOAT, // what kind of data are these attributes
				GL_FALSE, // Tell the GPU if you want to Normalize it
				0, // Tell the GPU how many pieces of data to skip between to find the next attribute
				(void *)0); // where to start to find the first attribute

							//////////////////////////////////////////////////////////////////////////////////////////////////


							//////////---COLOR DATA---////////////////////////////////////////////////////////////////////////

							// Binding the buffer to the GPU
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[COLOR_DATA]); // GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)

																			 // Store all our vertex data into the buffer (array)
			glBufferData
				(
					GL_ARRAY_BUFFER, // think of this as an array,
					(m_drawCount * sizeof(colourData[0])), // size of array,
					&colourData[0], // the array of vertices we want to store,
					GL_STATIC_DRAW // GL_STATIC_DRAW -- the data will not be changed, it doesn't need to be accessed repeatedly
					);

			// This tells the GPU that there are going to be attributes for these Vertices
			glEnableVertexAttribArray(3);

			// This tells the GPU how to actually read each attribute into an array
			glVertexAttribPointer(
				COLOR_DATA, // Which attribute array its being told how to interpret
				4, // how many pieces of data in that attribute
				GL_FLOAT, // what kind of data are these attributes
				GL_FALSE, // Tell the GPU if you want to Normalize it
				0, // Tell the GPU how many pieces of data to skip between to find the next attribute
				(void *)0); // where to start to find the first attribute

							//// Binding the buffer to the GPU
							//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
							//// GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)

							//// Store all our vertex data into the buffer (array)
							//glBufferData(GL_ELEMENT_ARRAY_BUFFER, (vertices.size()), &vertices[0], GL_STATIC_DRAW);


							// This stops the GPU from affecting the vertex array object that we previously bound to the gpu, effectively unbinds it.
			glBindVertexArray(0);

			/////////////////////////////////////////////////////////////////////////////////////////
			break;
		}

	}

	//Mesh::Mesh(Vertex * vertices, unsigned int numVertices, unsigned int * indices, unsigned int numIndices)
	//{
	//	Model3D model;
	//
	//	for (unsigned int i = 0; i < numVertices; i++)
	//	{
	//		model.positions.push_back(*vertices[i].getPosition());
	//		model.texCoords.push_back(*vertices[i].getTextureCoords());
	//		model.normals.push_back(*vertices[i].getNormals());
	//	}
	//
	//	for (unsigned int i = 0; i < numIndices; i++)
	//	{
	//		model.indices.push_back(indices[i]);
	//	}
	//
	//	InitMesh(model);
	//}

	//Mesh::Mesh(Model3D indexedModel)
	//{
	//	InitMesh(indexedModel);
	//}

	//void Mesh::InitMesh(const Model3D & model)
	//{
	//	m_drawCount = model.indices.size();
	//	// Create Space for an Vertex array
	//	glGenVertexArrays(1, &m_vertexArrayObject);
	//
	//	// Binding the vertex array object make it so that any operation that effects a vertex array object, will affect this vertex array object
	//	glBindVertexArray(m_vertexArrayObject);
	//
	//
	//
	//	/////////VERTEX POSITIONS//////////////////////////////////////////////////////////////
	//	//
	//	// Generate all the buffers that we need so we can write to them.
	//	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	//	//
	//	// Binding the buffer to the GPU
	//	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]); // GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)
	//	//
	//	// Store all our vertex data into the buffer (array)
	//	glBufferData
	//		(
	//		GL_ARRAY_BUFFER, // think of this as an array,
	//		(model.positions.size() * sizeof(model.positions[0])), // size of array,
	//		&model.positions[0], // the array of vertices we want to store,
	//		GL_STATIC_DRAW // GL_STATIC_DRAW -- the data will not be changed, it doesn't need to be accessed repeatedly
	//		);
	//	//
	//	// This tells the GPU that there are going to be attributes for these Vertices
	//	glEnableVertexAttribArray(0);
	//	//
	//	// This tells the GPU how to actually read each attribute into an array
	//	glVertexAttribPointer(
	//		0, // Which attribute array its being told how to interpret
	//		3, // how many pieces of data in that attribute
	//		GL_FLOAT, // what kind of data are these attributes
	//		GL_FALSE, // Tell the GPU if you want to Normalize it
	//		0, // Tell the GPU how many pieces of data to skip between to find the next attribute
	//		0); // where to start to find the first attribute
	//
	//
	//
	//	///////TEXTURE COORDINATES/////////////////////////////////////////////////////////////////
	//	//
	//	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORDS_VB]);
	//	//
	//	glBufferData(GL_ARRAY_BUFFER, (model.texCoords.size() * sizeof(model.texCoords[0])),
	//		&model.texCoords[0], GL_STATIC_DRAW);
	//	//
	//	glEnableVertexAttribArray(1);
	//	//
	//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	//
	//
	//
	//	//////VERTEX NORMALS/////////////////////////////////////////////////////////////////////////////////////
	//	//
	//	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMALS_VB]);
	//	//
	//	glBufferData(GL_ARRAY_BUFFER, (model.normals.size() * sizeof(model.normals[0])),
	//		&model.normals[0], GL_STATIC_DRAW);
	//	//
	//	glEnableVertexAttribArray(2);
	//	//
	//	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//
	//
	//	/////////////////////////////////////////////////////////////////////////////////////////
	//
	//	// Binding the buffer to the GPU
	//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
	//	// GL_ARRAY_BUFFER -- tells the GPU to interpret this buffer of data as an array -> this array (m_vertexArrayBuffers)
	//
	//	// Store all our vertex data into the buffer (array)
	//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (model.indices.size() * sizeof(model.indices[0])), &model.indices[0], GL_STATIC_DRAW);
	//
	//
	//	// This stops the GPU from affecting the vertex array object that we previously bound to the gpu, effectively unbinds it.
	//	glBindVertexArray(0);
	//}

	MESHGL::~MESHGL()
	{
		// Delete the vertex array to free the space allocated to it
		if (m_vertexArrayObject)
		{
			glDeleteVertexArrays(1, m_vertexArrayObject);
		}
	}

	void MESHGL::draw()
	{

		glBindVertexArray(*m_vertexArrayObject);
		// mode - how to draw, (triangles, lines, points), first, count
		//glPolygonMode(GL_FRONT, GL_LINE);
		//glPolygonMode(GL_BACK, GL_LINE);
		glBindTexture(GL_TEXTURE_2D, m_texture[0]);
		glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
		//glDrawElements(GL_TRIANGLES, 8, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
	}

	void MESHGL::drawModel()
	{
		glBindVertexArray(*m_vertexArrayObject);

		glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);
	}

	void MESHGL::loadTexture(unsigned char* image)
	{
		glGenTextures(1, m_texture);

		glBindTexture(GL_TEXTURE_2D, m_texture[0]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	}
}