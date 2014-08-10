#include "texture.h"

#include <iostream>

Texture::Texture(const std::string& fileName)
{
	unsigned int width, height, numComponents;

	SDL_Surface* image;
	image = IMG_Load(fileName.c_str());
	if(!image)
	{
		std::cerr << "IMG_Load: " << IMG_GetError() << std::endl;
	}

	width = image->w;
	height = image->h;
	numComponents = image->refcount;



	SDL_FreeSurface(image);
}

Texture::~Texture()
{

}
