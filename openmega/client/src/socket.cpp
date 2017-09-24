#include "socket.hpp"

Socket::Socket(std::string name)
{
	SDLNet_Init();
	SDLNet_ResolveHost(&ip, "localhost", port);
	socket = SDLNet_TCP_Open(&ip);
	if(!socket){
		std::cout << "Cannot connect to server.\n" << std::endl;
		exit(1);
	}
	SDLNet_TCP_Send(socket, name.c_str(), name.size()+1);
}

Socket::~Socket()
{
	SDLNet_TCP_Close(socket);
}

void Socket::send(json j)
{
	SDLNet_TCP_Send(socket, j.dump().c_str(), j.dump().size()+1);
}

json Socket::recv()
{
	char msg[MAXLEN];
	SDLNet_TCP_Recv(socket, msg, MAXLEN);
	json j = json::parse(msg);
	return j;
}
