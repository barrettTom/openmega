#include "entity.hpp"

Entity::Entity(Window m)
{
	x = y = 500;
	height = width = 40;
	renderer = m.getRenderer();

	TTF_Font *font = TTF_OpenFont("fonts/DejaVuSerif.ttf",24);
	SDL_Color color = {100,100,100};

	SDL_Surface* textSurface = TTF_RenderText_Solid(font,"@",color);
	texture = SDL_CreateTextureFromSurface(renderer,textSurface);
}

void Entity::place()
{
	SDL_Rect rect = {x, y, width, height};
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL,SDL_FLIP_NONE);
}

void Entity::setAction(std::string s)
{
	actionString = s;
}

std::string Entity::action()
{
	std::string tmp = actionString;
	actionString = "none";
	return tmp;
}

void Entity::conclusion(std::string s)
{
	x = stoi(s.substr(0,3));
	y = stoi(s.substr(4,3));
}
