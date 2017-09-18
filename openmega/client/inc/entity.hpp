#ifndef entity_h
#define entity_h

#include "window.hpp"

class Entity
{
	public:
		Entity(Window m);
		void place();
		//SDL_Texture* loadTexture(std::string path, Window main);
		void setAction(std::string s);
		std::string action();
		void conclusion(std::string s);

	protected:
		int x, y;
		std::string actionString;
		int height, width;  //Dimensions of image on window
		SDL_Texture* texture;
		SDL_Renderer* renderer;
};

#endif
