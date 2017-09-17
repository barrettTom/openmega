#include "socket.hpp"

Socket::Socket()
{
	SDLNet_Init();
	SDLNet_ResolveHost(&ip, "localhost", port);
	socket = SDLNet_TCP_Open(&ip);
}

Socket::~Socket()
{
	SDLNet_TCP_Close(socket);
}

void Socket::send(std::string s)
{
	SDLNet_TCP_Send(socket, s.c_str(), s.size()+1);
}

std::string Socket::recv()
{
	char message[MAXLEN];
	int len;
	SDLNet_TCP_Recv(socket, message, MAXLEN);
	std::string s(message);
	return s;
}
