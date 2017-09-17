#include "main.hpp"
#define MAXLEN 1024
#include <SDL2/SDL_net.h>
#include <string>
#include <iostream>

int main(){
	IPaddress ip;
	TCPsocket server;
	int port = 5555;

	SDLNet_Init();

	SDLNet_ResolveHost(&ip, NULL, port);

	server = SDLNet_TCP_Open(&ip);
	if(!server) {
	    	printf("SDLNet_TCP_Open: %s\n", SDLNet_GetError());
	    	exit(2);
	}

	TCPsocket new_tcpsock;
	int result;
	char msg[MAXLEN];
	int x = 400, y = 500;

	while(true){
		new_tcpsock = SDLNet_TCP_Accept(server);
		if(!new_tcpsock)
			SDL_Delay(20);
		else{
			result = 1;
			while(result){
				result = SDLNet_TCP_Recv(new_tcpsock, msg, MAXLEN);
				std::string mess(msg);
				if (!mess.find("up"))
					y--;
				else if(!mess.find("down"))
					y++;
				else if (!mess.find("right"))
					x++;
				else if(!mess.find("left"))
					x--;
				std::string s;
				s.append(std::to_string(x));
				s.append(",");
				s.append(std::to_string(y));
				s.append("\0");
				SDLNet_TCP_Send(new_tcpsock, s.c_str(), s.size()+1);
				SDL_Delay(20);
			}
		}
	}
}
