#version 120

attribute vec3 position;
attribute vec2 textureCoords;
attribute vec3 normal;

uniform mat4 camera;
uniform mat4 model;

void main(void)
{
	mat4 modelView = camera * model;
	gl_Position = (modelView  * vec4(position, 1.0));
	textureCoords0 = textureCoords;
	normal0 = (model  * vec4(normal.xyz, 0.0)).xyz;
}