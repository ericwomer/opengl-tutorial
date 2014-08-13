#include "texture.h"

#include <iostream>
#include <cassert>

Texture::Texture(const std::string& fileName)
{
	SDL_Surface* image;
	unsigned int mode;

	image = IMG_Load(fileName.c_str());
	if(!image)
	{
		std::cerr << "IMG_Load: " << IMG_GetError() << std::endl;
	}

	if(image->format->BytesPerPixel == 3)
	{
		mode = GL_RGB;
	}
	else if(image->format->BytesPerPixel == 4)
	{
		mode = GL_RGBA;
	}
	else
	{
		SDL_FreeSurface(image);
		// handle this
	}

	if(image)
	{
		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, mode, image->w, image->h, 0, mode, GL_UNSIGNED_BYTE, image->pixels);
		SDL_FreeSurface(image);
	}
	else
	{
		std::cerr << "Some thing went wrong!" << std::endl;
	}

}

Texture::~Texture()
{
	glDeleteTextures(1,&m_texture);
}

void Texture::Bind(unsigned int unit)
{
	assert(unit >= 0 && unit <= 31);

	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}
