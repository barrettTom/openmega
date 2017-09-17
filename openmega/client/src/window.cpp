#include "window.hpp"

Window::Window() 
{
	SDL_Init(SDL_INIT_VIDEO);
    	TTF_Init();
	main = SDL_CreateWindow("main",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1280,800,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(main,-1,SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Window::destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(main);
	SDL_Quit();
}

void Window::clear(){
	SDL_RenderClear(renderer);
}

void Window::render() 
{
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Window::getRenderer()
{
	return renderer;
}
