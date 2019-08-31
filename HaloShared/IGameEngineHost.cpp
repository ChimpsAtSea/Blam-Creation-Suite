#include "haloshared-private-pch.h"

bool IGameEngineHost::g_enableGameEngineHostOverride = false;
IGameEngineHost::InputUpdatePatchState IGameEngineHost::g_inputUpdatePatchState = InputUpdatePatchState::WaitingForRun;
IGameEngineHost IGameEngineHost::g_gameEngineHost;

IGameEngineHost::IGameEngineHost()
{

}

IGameEngineHost::~IGameEngineHost()
{

}

void IGameEngineHost::Member00() { /*WriteLineVerbose("IGameEngineHost::Member00");*/ };
void IGameEngineHost::Member01() { /*WriteLineVerbose("IGameEngineHost::Member01");*/ };
void IGameEngineHost::Member02() { WriteLineVerbose("IGameEngineHost::Member02"); };
void IGameEngineHost::Member03() { /*WriteLineVerbose("IGameEngineHost::Member03");*/ };
void IGameEngineHost::GameRestart() { WriteLineVerbose("IGameEngineHost::GameRestart"); };

void __fastcall IGameEngineHost::WriteGameState(LPVOID a1, size_t a2)
{
	WriteLineVerbose("IGameEngineHost::WriteGameState %p %016llx", a1, a2);
};

void IGameEngineHost::Member06() { WriteLineVerbose("IGameEngineHost::Member06"); };
void IGameEngineHost::Member07() { WriteLineVerbose("IGameEngineHost::Member07"); };
void IGameEngineHost::Member08() { WriteLineVerbose("IGameEngineHost::Member08"); };
void IGameEngineHost::Member09() { WriteLineVerbose("IGameEngineHost::Member09"); };
GameEvents* IGameEngineHost::GetGameEvents()
{
	return this->pGameEvents;
};
void IGameEngineHost::Member11() { WriteLineVerbose("IGameEngineHost::Member10"); };
void IGameEngineHost::Member12() { WriteLineVerbose("IGameEngineHost::Member11"); };
void IGameEngineHost::Member13() { WriteLineVerbose("IGameEngineHost::Member12"); };
void IGameEngineHost::Member14() { WriteLineVerbose("IGameEngineHost::Member13"); };
void IGameEngineHost::GetNextLevelInfo() { WriteLineVerbose("IGameEngineHost::GetNextLevelInfo"); };
void IGameEngineHost::Member16() { WriteLineVerbose("IGameEngineHost::Member16"); };
void IGameEngineHost::Member17() { WriteLineVerbose("IGameEngineHost::Member17"); };
void IGameEngineHost::Member18() { WriteLineVerbose("IGameEngineHost::Member18"); };

__int64 __fastcall IGameEngineHost::Member19(__int64 arg)
{
	/*WriteLineVerbose("GameEngineHostCallback::Member19 %016llx", arg);*/
	return __int64(0);
};

void IGameEngineHost::Member20() { WriteLineVerbose("IGameEngineHost::Member20"); };
void IGameEngineHost::Member21() { WriteLineVerbose("IGameEngineHost::Member21"); };
void IGameEngineHost::Member22() { WriteLineVerbose("IGameEngineHost::Member22"); };
void IGameEngineHost::Member23() { WriteLineVerbose("IGameEngineHost::Member23"); };

void IGameEngineHost::Member24()
{
	WriteVerbose("IGameEngineHost::Member24 ");
	WriteLineVerbose("GameLoaded");
	SplashScreen::Destroy();
	ShowWindow(CustomWindow::s_hwnd, SW_SHOW);
	SetFocus(CustomWindow::s_hwnd);
};

void IGameEngineHost::Member25(Member25Struct& a1, uint32_t a2)
{ 
	WriteLineVerbose("IGameEngineHost::Member25");
};

void IGameEngineHost::Member26() { WriteLineVerbose("IGameEngineHost::Member26"); };
void IGameEngineHost::Member27() { /*WriteLineVerbose("IGameEngineHost::Member27");*/ };
bool IGameEngineHost::Member28()
{ 
	WriteLineVerbose("IGameEngineHost::Member28");
	return false;
};
bool IGameEngineHost::Member29() 
{ 
	WriteLineVerbose("IGameEngineHost::Member29");
	return false;
};

unsigned __int8 __fastcall IGameEngineHost::Member30(_QWORD, InputBuffer* pInputBuffer)
{
	/*
		When we load the level, we set the g_waitingForInputUpdate to true allowing us
		to reset the input system. This function sets the engine to use the keyboard
		or mouse input.
		*/

	memset(pInputBuffer, 0, sizeof(*pInputBuffer));
	pInputBuffer->unknown0 = 1;

	// don't update and return an empty zero buffer
	if (DebugUI::IsVisible())
	{
		return unsigned __int8(1);
	}

	// get keyboard state
	{
		BYTE keyboardState[256] = {};
		if (GetKeyboardState(keyboardState))
		{
			for (int i = 0; i < 256; i++)
			{
				pInputBuffer->keyboardState[i] = (keyboardState[i] & 0b10000000) != 0;
			}
		}
	}


	pInputBuffer->MouseX += GetAsyncKeyState(VK_F5) ? 0.1f : 0;
	pInputBuffer->MouseX -= GetAsyncKeyState(VK_F6) ? 0.1f : 0;
	pInputBuffer->MouseY += GetAsyncKeyState(VK_F7) ? 0.1f : 0;
	pInputBuffer->MouseY -= GetAsyncKeyState(VK_F8) ? 0.1f : 0;

	pInputBuffer->data2[8] = GetAsyncKeyState(VK_F1) ? -1 : 0; // MOUSE BUTTONS
	pInputBuffer->data2[9] = GetAsyncKeyState(VK_F2) ? -1 : 0;
	pInputBuffer->data2[10] = GetAsyncKeyState(VK_F3) ? -1 : 0;
	pInputBuffer->data2[11] = GetAsyncKeyState(VK_F4) ? -1 : 0;

	
	if (g_inputUpdatePatchState == IGameEngineHost::InputUpdatePatchState::WaitingForRun)
	{
		IGameEngineHost::g_inputUpdatePatchState = IGameEngineHost::InputUpdatePatchState::Patched;
		return unsigned __int8(1);
	}
	return unsigned __int8(1);
};

bool __fastcall IGameEngineHost::SetPlayerName(__int64*, wchar_t playerNames[4][32], size_t dataSize)
{
	if (playerNames && dataSize)
	{
		// #TODO: Clean this up and support multiple player indices

		size_t maxChars = (dataSize / sizeof(wchar_t));
		size_t maxLength = maxChars - 1;
		assert(maxLength == 31);
		assert(maxChars == 32);
		wcsncpy(playerNames[0], L"Squaresome", maxLength);
		playerNames[0][maxLength] = 0;

		return true;
	}
	return false;
};
void IGameEngineHost::Member32() { WriteLineVerbose("IGameEngineHost::Member32"); };
void IGameEngineHost::Member33() { WriteLineVerbose("IGameEngineHost::Member33"); };
void IGameEngineHost::NetworkSendTo() { 
	WriteLineVerbose("IGameEngineHost::NetworkSendTo");
};
__int64 IGameEngineHost::NetworkReceiveFrom(char* buffer, uint32_t buffersize, __int64 a4, int a5)
{
	//memset(buffer, 0, buffersize);
	//WriteLineVerbose("IGameEngineHost::NetworkReceiveFrom");
	// error codes are negative
	// 0 means no byte read
	// positive value for success
	return -1;
};
void IGameEngineHost::Member36() { WriteLineVerbose("IGameEngineHost::Member36"); };
void IGameEngineHost::Member37() { WriteLineVerbose("IGameEngineHost::Member37"); };
void IGameEngineHost::Member38() { WriteLineVerbose("IGameEngineHost::Member38"); };
void IGameEngineHost::Member39() { WriteLineVerbose("IGameEngineHost::Member39"); };
void IGameEngineHost::Member40() { WriteLineVerbose("IGameEngineHost::Member40"); };
void IGameEngineHost::Member41() { WriteLineVerbose("IGameEngineHost::Member41"); };
void IGameEngineHost::FileAccessed() { WriteLineVerbose("IGameEngineHost::FileAccessed"); };
void IGameEngineHost::Member43() { WriteLineVerbose("IGameEngineHost::Member43"); };

