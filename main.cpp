#include <iostream>
#include <GL/glew.h>

#include "display/display.h"
#include "mesh/mesh.h"
#include "shader/shader.h"
#include "texture/texture.h"
#include "transform/transform.h"
#include "camera/camera.h"

// we are in c++ not c
const unsigned int width = 800;
const unsigned int height = 600;

std::string dataDir = "/home/salamanderrake/src/personal/OpenGl";

int main()
{
	Display display(width, height, "Hello World!");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
						  Vertex(glm::vec3(0.0, 0.5, 0.0), glm::vec2(0.5, 1.0)),
						  Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0)), };

	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

	Shader shader(dataDir + "/res/shaders/basicShader");
	Texture texture(dataDir + "/res/textures/bricks.jpg");

	Camera camera(glm::vec3(0, 0, -3), 70.0f, float(width)/float(height), 0.01f, 1000.0f);

	Transform transform;

	float counter = 0.0f;

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.32f, 1.0f);

		float sinCounter = sinf(counter);
		float cosCounter = cosf(counter);

		transform.GetPos().x = sinCounter;
		transform.GetPos().z = cosCounter;

		transform.GetRot().x = counter * 50;
		transform.GetRot().y = counter * 50;
		transform.GetRot().z = counter * 50;

		// transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

		shader.Bind();

		texture.Bind(0);

		shader.Update(transform, camera);

		mesh.Draw();

		display.Update();

		counter += 0.0001f;
	}


	return 0;
}

