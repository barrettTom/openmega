#ifndef window_h
#define window_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Window
{
	public:
		Window();
		void clear();
		void render();
		void destroy();
		SDL_Renderer* getRenderer();

	private:
		SDL_Window* main;
		SDL_Renderer* renderer;
};

#endif
