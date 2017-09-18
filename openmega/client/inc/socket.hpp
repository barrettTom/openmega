#ifndef socket_h
#define socket_h

#include <SDL2/SDL_net.h>
#include <iostream>
#include <string>

#define MAXLEN 1024

class Socket
{
	public:
		Socket();
		~Socket();
		void send(std::string s);
		std::string recv();
		
	private:
		IPaddress 	ip;
		TCPsocket 	socket;
		int 		port = 5555;
};

#endif
