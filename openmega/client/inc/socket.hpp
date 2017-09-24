#ifndef socket_h
#define socket_h

#include <SDL2/SDL_net.h>
#include <iostream>
#include <string>
#include "json.hpp"
using json = nlohmann::json;

#define MAXLEN 1024

class Socket
{
	public:
		Socket(std::string name);
		~Socket();
		void send(json j);
		json recv();
		
	private:
		IPaddress 	ip;
		TCPsocket 	socket;
		int 		port = 5555;
};

#endif
