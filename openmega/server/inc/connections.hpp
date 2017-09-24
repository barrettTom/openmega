#ifndef connections_h
#define connections_h

#define SERVERTIMEOUT 1000

#include <iostream>
#include <SDL2/SDL_net.h>
#include <list>
#include <string>

#include "connection.hpp"
#include "json.hpp"
using json = nlohmann::json;

class Connections
{
	public:
		Connections();
		void 		querySockets();
		void 		sendData(json j);
		json 		getData(){return data;};
	private:
		IPaddress 		ip;
		int 			port;
		TCPsocket 		server;
		json 			data;
		std::list<Connection> connections;
};

#endif
