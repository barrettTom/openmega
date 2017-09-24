#include "main.hpp"

int main(){
	Game game;
	Connections connections;
	while(true){
		connections.querySockets();
		game.giveData(connections.getData());
		game.processData();
		connections.sendData(game.getData());
		SDL_Delay(10);
	}
}
