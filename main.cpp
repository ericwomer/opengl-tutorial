#include <iostream>
#include <GL/glew.h>

#include "display/display.h"
#include "mesh/mesh.h"
#include "shader/shader.h"

std::string dataDir = "/home/salamanderrake/src/personal/OpenGl";

int main()
{
	Display display(800, 600, "Hello World!");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0)),
						  Vertex(glm::vec3(0.0, 0.5, 0.0)),
						  Vertex(glm::vec3(0.5, -0.5, 0.0)), };

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	// Shader shader("/home/salamanderrake/src/personal/OpenGl/res/shaders/basicShader");
	Shader shader(dataDir + "/res/shaders/basicShader");
	shader.Bind();

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.32f, 1.0f);

		mesh.Draw();

		display.Update();

	}


	return 0;
}

