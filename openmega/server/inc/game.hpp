#ifndef game_h
#define game_h

#include <iostream>
#include <string>
#include "json.hpp"
using json = nlohmann::json;

class Game
{
	public:
		void giveData(json j){data = j;};
		json getData(){return data;};
		void processData();
	private:
		json data;
};

#endif
