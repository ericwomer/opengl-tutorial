#include <iostream>
#include <GL/glew.h>

#include "display/display.h"
#include "mesh/mesh.h"
#include "shader/shader.h"
#include "texture/texture.h"

std::string dataDir = "/home/salamanderrake/src/personal/OpenGl";

int main()
{
	Display display(800, 600, "Hello World!");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
						  Vertex(glm::vec3(0.0, 0.5, 0.0), glm::vec2(0.5, 1.0)),
						  Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0)), };

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	Shader shader(dataDir + "/res/shaders/basicShader");
	Texture texture(dataDir + "/res/textures/bricks.jpg");

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.32f, 1.0f);

		shader.Bind();
		texture.Bind(0);

		mesh.Draw();

		display.Update();

	}


	return 0;
}

