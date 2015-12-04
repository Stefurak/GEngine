#version 120

attribute vec3 vPosition;

void main()
{
	gl_Position = vec4(vPosition, 1.0);
}
