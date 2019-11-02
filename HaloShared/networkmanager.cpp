#include "haloshared-private-pch.h"

SOCKET LocalSocket = INVALID_SOCKET;
int send_to_port = 2000;

void NetworkManager::CreateClientConnection(u_short port)
{
	//if (LocalSocket == INVALID_SOCKET)
	//{
	//	/* Open a datagram socket */
	//	LocalSocket = socket(AF_INET, SOCK_DGRAM, 0);
	//	if (LocalSocket == INVALID_SOCKET)
	//	{
	//		FATAL_ERROR("Could not create socket.");
	//		WSACleanup();
	//		exit(0);
	//	}

	//	u_long nonblocking_enabled = TRUE;
	//	ioctlsocket(LocalSocket, FIONBIO, &nonblocking_enabled);

	//	int nbo_ipv4 = inet_addr("127.0.0.1");
	//	u_short nbo_port = htons(port ? port : 2001);

	//	sockaddr_in addr = {};
	//	addr.sin_family = AF_INET;
	//	addr.sin_port = nbo_port;
	//	addr.sin_addr.s_addr = nbo_ipv4;
	//	auto bind_result = bind(LocalSocket, (sockaddr*)& addr, sizeof(addr));
	//	assert(bind_result == 0);
	//}
}

void NetworkManager::CreateServerConnection()
{
	//CreateClientConnection(2000);
	//send_to_port = 2001;
}

int NetworkManager::RecieveFrom(char* buffer, uint32_t buffersize)
{
	memset(buffer, 0, buffersize);
	return 0;

	/* // terrible testing code that didn't work

	auto recvfrom_result = recvfrom(LocalSocket, buffer, buffersize, 0, NULL, 0);

	if (recvfrom_result >= 0)
	{
		WriteLineVerbose("IGameEngineHost::NetworkReceiveFrom %i", recvfrom_result);
		return recvfrom_result;
	}
	else
	{
		int err = WSAGetLastError();
		if (err != WSAEWOULDBLOCK)
		{
			WriteLineVerbose("IGameEngineHost::NetworkReceiveFrom (error) %i", err);
			return -1;
		}
		else
		{
			return 0;
		}
	}
	*/
}

int NetworkManager::SendTo(char* buffer, uint32_t buffersize)
{
	memset(buffer, 0, buffersize);
	return 0;

	/* // terrible testing code that didn't work
	//assert(networkID != NetworkID::Invalid && networkID < NetworkID::k_NumNetworkID);

	sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = send_to_port;
	//addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (IGameEngineHost::g_isHost)
	{
		addr.sin_addr.s_addr = inet_addr("10.255.0.2");
		addr.sin_port = htons(2001);
	}
	else
	{
		addr.sin_addr.s_addr = inet_addr("10.255.0.1");
		addr.sin_port = htons(2000);
	}
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	//addr.sin_addr.s_addr = htonl(networkID);
	auto result = sendto(LocalSocket, buffer, buffersize, 0, (sockaddr*)& addr, sizeof(addr));
	//assert(result == buffersize);

	// recvfrom
	WriteLineVerbose("IGameEngineHost::NetworkSendTo %i", result);

	return result;
	*/
}
