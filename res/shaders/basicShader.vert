#version 120

attribute vec3 position;

void Main()
{
	gl_Position = vec4(position, 1.0);
}
