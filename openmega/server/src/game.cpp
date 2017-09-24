#include "game.hpp"

void Game::processData()
{
	for(auto entity = data.begin(); entity != data.end(); ++entity){
		if((*entity).is_object()){
			for(auto details = (*entity).begin(); details != (*entity).end(); details++){
				std::string action = (*details)["action"];
				int X = (*details)["X"];
				int Y = (*details)["Y"];
				if (action == "up")
					Y++;
				(*details)["X"] = X;
				(*details)["Y"] = Y;
			}
		}
	}
}
