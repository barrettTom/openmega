#ifndef entity_h
#define entity_h

#include <iostream>
#include <string>

#include "window.hpp"
#include "json.hpp"
using json = nlohmann::json;

class Entity
{
	public:
		Entity(Window m, std::string n);
		void place();
		void setAction(std::string s);
		json action();
		void conclusion(json j);

	protected:
		std::string name;
		int x, y;
		std::string actionString;
		int height, width;
		SDL_Texture* texture;
		SDL_Renderer* renderer;
};

#endif
