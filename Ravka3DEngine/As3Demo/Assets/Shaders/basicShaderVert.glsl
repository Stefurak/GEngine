#version 120

attribute vec3 position;
attribute vec2 textureCoords;
attribute vec3 normal;
attribute vec4 colourData;

varying vec2 textureCoords0;
varying vec3 normal0;
varying vec4 colourData0;

uniform mat4 camera;
uniform mat4 model;

void main(void)
{
	colourData0 = colourData;
	mat4 modelView = camera * model;
	gl_Position = modelView * vec4(position, 1.0);
	textureCoords0 = textureCoords;
	normal0 = (model  * vec4(normal.xyz, 0.0)).xyz;
}