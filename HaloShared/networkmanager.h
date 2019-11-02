#pragma once
class NetworkManager
{
public: /* static functions */
	static void CreateClientConnection(u_short port = 0);
	static void CreateServerConnection();
	static int RecieveFrom(char* buffer, uint32_t buffersize);
	static int SendTo(char* buffer, uint32_t buffersize);
};

