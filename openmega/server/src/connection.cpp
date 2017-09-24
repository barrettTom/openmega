#include "connection.hpp"

Connection::Connection(TCPsocket s)
{
	socket = s;
	char name[MAXLEN];
	SDLNet_TCP_Recv(socket, name, MAXLEN);
	json j;
	j[name] = {{"X",40},{"Y",50}};
	SDLNet_TCP_Send(socket, j.dump().c_str(), j.dump().size()+1);
}

bool Connection::active()
{
	return SDLNet_SocketReady(socket);
}

json Connection::recv()
{
	char msg[MAXLEN];
	SDLNet_TCP_Recv(socket, msg, MAXLEN);
	try{
		json j = json::parse(msg);
		return j;
	}
	catch(std::invalid_argument){
		//std::cout << "parser error:\n" << msg << std::endl;
		SDLNet_TCP_Close(socket);
		return NULL;
	}
}

void Connection::send(json j)
{
	SDLNet_TCP_Send(socket, j.dump().c_str(), j.dump().size()+1);
}
