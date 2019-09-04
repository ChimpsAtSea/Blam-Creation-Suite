#include "haloshared-private-pch.h"

SOCKET LocalSocket = INVALID_SOCKET;
int send_to_port = 2000;

void IGameEngineHost::CreateClientConnection(int port)
{
	if (LocalSocket == INVALID_SOCKET)
	{
		/* Open a datagram socket */
		LocalSocket = socket(AF_INET, SOCK_DGRAM, 0);
		if (LocalSocket == INVALID_SOCKET)
		{
			FATAL_ERROR("Could not create socket.");
			WSACleanup();
			exit(0);
		}

		u_long nonblocking_enabled = TRUE;
		ioctlsocket(LocalSocket, FIONBIO, &nonblocking_enabled);

		sockaddr_in addr = {};
		addr.sin_family = AF_INET;
		addr.sin_port = port ? port : 2001;
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		auto bind_result = bind(LocalSocket, (sockaddr*)& addr, sizeof(addr));
		assert(bind_result == 0);
	}
}

void IGameEngineHost::CreateServerConnection()
{
	CreateClientConnection(2000);
	send_to_port = 2001;
}

bool IGameEngineHost::g_enableGameEngineHostOverride = false;
IGameEngineHost::InputUpdatePatchState IGameEngineHost::g_inputUpdatePatchState = InputUpdatePatchState::WaitingForRun;
IGameEngineHost IGameEngineHost::g_gameEngineHost;

IGameEngineHost::IGameEngineHost()
	:pGameEvents(&IGameEvents::g_gameEvents)
{

}

IGameEngineHost::~IGameEngineHost()
{

}

char __fastcall IGameEngineHost::Member00() 
{ 
	//WriteLineVerbose("IGameEngineHost::Member00");
	return 0;
};

void __fastcall IGameEngineHost::Member01(IDXGISwapChain *pSwapChain, _QWORD a2) 
{
	DebugUI::RenderFrame();

	//WriteLineVerbose("IGameEngineHost::Member01 0x%p 0x%llx", pSwapChain, a2);
};

void __fastcall IGameEngineHost::Member02(__int64 a1, unsigned int a2, __int64 a3, float a4, float a5, float a6, float a7)
{
	//WriteLineVerbose("IGameEngineHost::Member02");
};

void __fastcall IGameEngineHost::GameStatusUpdated(unsigned int a1)
{
	/*WriteLineVerbose("IGameEngineHost::Member03 GameStatusUpdated %d", a1);*/
};

__int64 __fastcall IGameEngineHost::GameExited(int a1, int a2, int a3)
{
	GameLauncher::s_currentGameState = GameLauncher::CurrentState::eFinished;
	SplashScreen::Destroy();

	WriteLineVerbose("IGameEngineHost::Member04 GameExited");
	return __int64(0);
};

__int64 __fastcall IGameEngineHost::WriteBufferToFile(LPVOID pBuffer, size_t bufferSize)
{
	WriteLineVerbose("IGameEngineHost::Member05 WriteBufferToFile %p %016llx", pBuffer, bufferSize);
	return __int64(0);
};

void __fastcall IGameEngineHost::Member06(Member06Struct *buffer)
{
	WriteLineVerbose("IGameEngineHost::Member06");
};
void __fastcall IGameEngineHost::Member07(unsigned int) { WriteLineVerbose("IGameEngineHost::Member07"); };
void __fastcall IGameEngineHost::Member08(const wchar_t *, const wchar_t *) { WriteLineVerbose("IGameEngineHost::Member08"); };
void __fastcall IGameEngineHost::Member09(wchar_t buffer0[1024], wchar_t buffer1[1024]) { WriteLineVerbose("IGameEngineHost::Member09"); };
IGameEvents*__fastcall IGameEngineHost::GetGameEvents()
{
	return pGameEvents;
};
void __fastcall IGameEngineHost::GameVariantCreated(IGameVariant *variant) { WriteLineVerbose("IGameEngineHost::Member10 GameVariantCreated"); };
void __fastcall IGameEngineHost::MapVariantCreated(IMapVariant *variant) { WriteLineVerbose("IGameEngineHost::Member11 MapVariantCreated"); };
void __fastcall IGameEngineHost::Member13(const wchar_t *, const wchar_t *, const void *, unsigned int) { WriteLineVerbose("IGameEngineHost::Member12"); };

char __fastcall IGameEngineHost::Member14(int controllerIndex, BYTE *flags)
{
	WriteLineVerbose("IGameEngineHost::Member13");
	return 0;
};

char __fastcall IGameEngineHost::Member15(int controllerIndex, BYTE *buffer)
{
	WriteLineVerbose("IGameEngineHost::Member15");
	return 0;
};

char __fastcall IGameEngineHost::GetNextLevelInfo(e_map_id *map_id, int *campaign_insertion_point, FILETIME *filetime, _DWORD *)
{
	WriteLineVerbose("IGameEngineHost::Member16 GetNextLevelInfo");
	return 0;
};

bool __fastcall IGameEngineHost::Member17(int a1)
{
	WriteLineVerbose("IGameEngineHost::Member17");
	return false;
};
void __fastcall IGameEngineHost::Member18(int) { WriteLineVerbose("IGameEngineHost::Member18"); };

__int64 __fastcall IGameEngineHost::MapLoadPecentStatus(__int64 a1, __int64 a2, float a3)
{
	/*WriteLineVerbose("GameEngineHostCallback::Member19 MapLoadPecentStatus %016llx", a1);*/
	return __int64(0);
};

void __fastcall IGameEngineHost::Member20(__int64 a1, __int8 a2) { WriteLineVerbose("IGameEngineHost::Member20"); };

__int64 __fastcall IGameEngineHost::Member21(_QWORD a1)
{
	return __int64(0);
};

__int64 __fastcall IGameEngineHost::Member22(Member22Struct *buffer, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member22");
	return __int64(0);
};
char __fastcall IGameEngineHost::Member23(__int64 a1, __int64 a2)
{
	WriteLineVerbose("IGameEngineHost::Member23");
	return 0;
};

__int64 __fastcall IGameEngineHost::Member24(BYTE *a1)
{
	WriteVerbose("IGameEngineHost::Member24 ");
	WriteLineVerbose("GameLoaded");
	SplashScreen::Destroy();
	CustomWindow::Show();

	return __int64(0);
};

void __fastcall IGameEngineHost::MembershipUpdate(Member25Struct* buffer, uint32_t playercount)
{
	WriteLineVerbose("IGameEngineHost::Member25 MembershipUpdate");
};

bool __fastcall IGameEngineHost::Member26()
{
	WriteLineVerbose("IGameEngineHost::Member26");
	return false;
};
void __fastcall IGameEngineHost::Member27() { /*WriteLineVerbose("IGameEngineHost::Member27");*/ };

bool __fastcall IGameEngineHost::Member28(Member28Struct *buffer)
{
	if (!buffer)
	{
		return false;
	}
	WriteLineVerbose("IGameEngineHost::Member28");
	return true;
};

__int64 __fastcall IGameEngineHost::Member29(wchar_t playerNames[4][32], Member29Struct *buffer)
{
	WriteLineVerbose("IGameEngineHost::Member29");
	return __int64(0);
};

bool __fastcall IGameEngineHost::Member30(_QWORD, InputBuffer* pInputBuffer)
{
	/*
		When we load the level, we set the g_waitingForInputUpdate to true allowing us
		to reset the input system. This function sets the engine to use the keyboard
		or mouse input.
		*/

	memset(pInputBuffer, 0, sizeof(*pInputBuffer));
	pInputBuffer->unknown0 = 1;

	bool debugUIVisible = DebugUI::IsVisible();
	bool windowFocused = CustomWindow::IsWindowFocused();

	MouseAcquireMode acquireMode = MouseAcquireMode::None;
	if (windowFocused)
	{
		acquireMode = debugUIVisible ? MouseAcquireMode::UI : MouseAcquireMode::Exclusive;
	}
	MouseInput::SetAcquireMode(acquireMode);

	// don't update and return an empty zero buffer
	if (debugUIVisible)
	{
		return unsigned __int8(1);
	}

	// get keyboard state
	BYTE keyboardState[256] = {};
	pInputBuffer->MouseX = 0.0f;
	pInputBuffer->MouseY = 0.0f;
	pInputBuffer->mouseButtonBits = 0;

	if (windowFocused)
	{
		GetKeyState(-1); // force keys to update
		if (GetKeyboardState(keyboardState))
		{
			for (int i = 0; i < 256; i++)
			{
				pInputBuffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
			}
		}

		bool mouseConnected = MouseInput::Read();
		if (mouseConnected)
		{
			float mouseInputX = MouseInput::GetMouseX();
			float mouseInputY = MouseInput::GetMouseY();

			pInputBuffer->MouseX += mouseInputX;
			pInputBuffer->MouseY += mouseInputY;

			bool leftButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Left);
			bool rightButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Right);
			bool middleButtonPressed = MouseInput::GetMouseButton(MouseInputButton::Middle);

			pInputBuffer->mouseButtonBits |= BYTE(leftButtonPressed) << 0;
			pInputBuffer->mouseButtonBits |= BYTE(middleButtonPressed) << 1;
			pInputBuffer->mouseButtonBits |= BYTE(rightButtonPressed) << 2;
		}
	}

	if (g_inputUpdatePatchState == IGameEngineHost::InputUpdatePatchState::WaitingForRun)
	{
		IGameEngineHost::g_inputUpdatePatchState = IGameEngineHost::InputUpdatePatchState::Patched;
		return unsigned __int8(1);
	}
	return unsigned __int8(1);
};


bool __fastcall IGameEngineHost::UpdatePlayerNames(__int64* playerIndices, wchar_t playerNames[4][32], size_t dataSize)
{
	if (playerNames && dataSize)
	{
		int index = 0;
		static wchar_t pPlayerNameBuffer[16] = L"";
		if (pPlayerNameBuffer[0] == 0)
		{
			if (Settings::ReadStringValueW(SettingsSection::Player, "Name", pPlayerNameBuffer, sizeof(pPlayerNameBuffer), L"Player") > 0)
			{
				if (wcsncmp(playerNames[index], pPlayerNameBuffer, 16) == 0)
				{
					WriteLineVerbose("player[%d].Name already set", index);
					return true;
				}
				wcsncpy_s(playerNames[index], 32, pPlayerNameBuffer, 16);
				WriteLineVerbose("player[%d].Name: set %ls", index, pPlayerNameBuffer);
			}
		}
		return true;
	}
	return false;
};
void IGameEngineHost::Member32(const wchar_t *, const wchar_t *) { WriteLineVerbose("IGameEngineHost::Member32"); };

bool IGameEngineHost::Member33(wchar_t *, __int64)
{
	WriteLineVerbose("IGameEngineHost::Member33");
	return 0;
};

__int64 __fastcall IGameEngineHost::NetworkSendTo(__int64 a2, char* buffer, uint32_t buffersize, int a5)
{
	sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = send_to_port;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	auto result = sendto(LocalSocket, buffer, buffersize, 0, (sockaddr*)& addr, sizeof(addr));
	assert(result == buffersize);

	// recvfrom
	WriteLineVerbose("IGameEngineHost::NetworkSendTo %i", result);

	return result;
};

__int64 IGameEngineHost::NetworkReceiveFrom(char* buffer, uint32_t buffersize, __int64 a4, s_transport_address *transport_address)
{
	memset(buffer, 0, buffersize);

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
};

char *__fastcall IGameEngineHost::Member36(unsigned int)
{
	WriteLineVerbose("IGameEngineHost::Member36");
	return 0;
};

int __fastcall IGameEngineHost::Member37(BYTE *buffer)
{
	WriteLineVerbose("IGameEngineHost::Member37");
	return 0;
};

bool __fastcall IGameEngineHost::Member38(signed int, __int64, __int64)
{
	WriteLineVerbose("IGameEngineHost::Member38");
	return 0;
};

// new wave/set
void __fastcall IGameEngineHost::FireFightNew(__int64 a1, float a2)
{
	WriteLineVerbose("IGameEngineHost::Member39 FireFightNew");
};

BOOL __fastcall IGameEngineHost::Member40(__int64, __int64)
{
	WriteLineVerbose("IGameEngineHost::Member40");
	return 0;
};

bool __fastcall IGameEngineHost::GetPathByType(int pathType, wchar_t *buffer, size_t bufferlength)
{
	WriteLineVerbose("IGameEngineHost::Member41 GetPathByType");
	return 0;
};

// this is correct implementation inline with MCC
bool __fastcall IGameEngineHost::GetWidePathByType(int pathType, wchar_t *buffer, size_t bufferlength)
{
	// this this should be in its function
	switch (pathType)
	{
	case 0:
		swprintf(buffer, bufferlength, L"DebugLogs\\");
		break;
	case 1:
		swprintf(buffer, bufferlength, L"Config\\");
		break;
	case 2:
		swprintf(buffer, bufferlength, L"Temp\\");
		break;
	case 3:
		swprintf(buffer, bufferlength, L"\\");
		break;
	}

	return 1;
};

unsigned __int8* IGameEngineHost::Member43(_QWORD a1, char *a2, _QWORD a3)
{
	return 0;
};
