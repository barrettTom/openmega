#include "connections.hpp"

Connections::Connections()
{
	SDLNet_Init();
	port = 5555;
	SDLNet_ResolveHost(&ip, NULL, port);
	server = SDLNet_TCP_Open(&ip);
}

void Connections::querySockets()
{
	static SDLNet_SocketSet set = NULL;
	if(set)
		SDLNet_FreeSocketSet(set);
	
	set = SDLNet_AllocSocketSet(connections.size()+1);

	SDLNet_TCP_AddSocket(set, server);

	for(auto it = connections.begin(); it != connections.end(); it++)
		SDLNet_TCP_AddSocket(set, it->getSocket());
	
	SDLNet_CheckSockets(set, 1);
	if(SDLNet_SocketReady(server)){
		TCPsocket sock = SDLNet_TCP_Accept(server);
		if(sock){
			connections.push_back(Connection(sock));
		}
	}

	data.clear();
	for(auto it = connections.begin(); it != connections.end(); it++)
		if(it->active()){
			json j = it->recv();
			if(j.is_object())
				data += j;
			else{
				connections.erase(it--);
			}
		}
}

void Connections::sendData(json j)
{
	for(auto it = connections.begin(); it != connections.end(); it++)
		it->send(j);
}
