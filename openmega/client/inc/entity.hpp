#ifndef entity_h
#define entity_h

#include "window.hpp"
#include <iostream>

class Entity
{
	public:
		Entity(Window m);
		void place();
		SDL_Texture* loadTexture(std::string path, Window main);
		void up();
		void down();
		void left();
		void right();
		std::string action();
		void conclusion(std::string s);

	protected:
		int x, y;
		int tX, tY;
		std::string s;
		int height, width;  //Dimensions of image on window
		int degrees = 0;
		SDL_Texture* texture;
		SDL_Renderer* renderer;
};

#endif
