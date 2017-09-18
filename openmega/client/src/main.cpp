#include "main.hpp"

int main()
{
	Window main;
	Event e;
	Timer fps;
	Socket connection;

	Entity me(main);

	while(e.gRun()){
		fps.Start();
		while(e.Poll()){
			if(e.gEventType() == SDL_QUIT)
				e.off();
			else if(e.gEventType() == SDL_KEYDOWN)
				switch(e.gEvent().key.keysym.sym){
		    			case(SDLK_w): me.setAction("up");    break;
					case(SDLK_s): me.setAction("down");  break;
					case(SDLK_a): me.setAction("left");  break;
					case(SDLK_d): me.setAction("right"); break;
				}
		}
	
		connection.send(me.action());
		me.conclusion(connection.recv());

		main.clear();
		me.place();
		main.render();

		if(fps.getTicks() < (1000 / 60))
		    SDL_Delay((1000 / 60) - fps.getTicks());
	}

	main.destroy();

	return 0;
}
