#include "entity.hpp"

Entity::Entity(Window m, std::string n)
{
	height = width = 40;
	renderer = m.getRenderer();

	TTF_Font *font = TTF_OpenFont("fonts/DejaVuSerif.ttf",24);
	SDL_Color color = {100,100,100};

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, "@", color);
	texture = SDL_CreateTextureFromSurface(renderer, textSurface);

	name = n;
}

void Entity::place()
{
	SDL_Rect rect = {x, y, width, height};
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
}

void Entity::setAction(std::string s)
{
	actionString = s;
}

json Entity::action()
{
	json j;
	j[name] = {{"X",x},{"Y",y},{"action",actionString}};
	actionString.clear();
	return j;
}

void Entity::conclusion(json j)
{
	for(auto entity = j.begin(); entity != j.end(); ++entity){
		if((*entity).find(name) != (*entity).end()){
			x = (*entity)[name]["X"];
			y = (*entity)[name]["Y"];
		}

	}
}

