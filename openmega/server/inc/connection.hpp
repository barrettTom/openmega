#ifndef connection_h
#define connection_h

#include <SDL2/SDL_net.h>
#include <string>

#define MAXLEN 1000

#include "json.hpp"
using json = nlohmann::json;

class Connection
{
	public:
		Connection(TCPsocket s);
		TCPsocket 	getSocket(){return socket;};
		bool 		active();
		void 		send(json j);
		json 		recv();
	private:
		TCPsocket	socket;
};

#endif
