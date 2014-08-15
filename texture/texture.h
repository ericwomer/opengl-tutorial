#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include <string>

class Texture
{
public:
	Texture(const std::string& fileName);
	~Texture();

	void Bind(unsigned int unit);

private:
	// Texture(Texture& other) {}
	// void operator=(Texture& lhs) {}

	GLuint m_texture;
};

#endif // TEXTURE_H
