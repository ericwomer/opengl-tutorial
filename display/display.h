#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

class Display
{
public:
	Display (int width, int height, const std::string& title);
	virtual ~Display();

	void SwapBuffers();

	void Update();
	bool IsClosed();

	void Clear();
	void Clear(float r, float g, float b, float a);

private:
	// Display(const Display& other) {};
	// void operator=(const Display& other) {};

	SDL_Window *m_window;
	SDL_GLContext m_glcontext;

	bool m_isClosed;

};

#endif // DISPLAY_H
