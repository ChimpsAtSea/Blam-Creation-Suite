#include "haloshared-private-pch.h"

bool IGameEngineHost::g_enableGameEngineHostOverride = false;
bool IGameEngineHost::g_waitingForInputUpdate = false;
IGameEngineHost IGameEngineHost::g_gameEngineHost;

IGameEngineHost::IGameEngineHost()
{

}

IGameEngineHost::~IGameEngineHost()
{

}

void IGameEngineHost::Member00() {};
void IGameEngineHost::Member01() {};
void IGameEngineHost::Member02() {};
void IGameEngineHost::Member03() {};
void IGameEngineHost::Member04() {};

void __fastcall IGameEngineHost::WriteGameState(LPVOID, size_t)
{

};

void IGameEngineHost::Member06() {};
void IGameEngineHost::Member07() {};
void IGameEngineHost::Member08() {};
void IGameEngineHost::Member09() {};
void IGameEngineHost::GetGameEvents() {};
void IGameEngineHost::Member11() {};
void IGameEngineHost::Member12() {};
void IGameEngineHost::Member13() {};
void IGameEngineHost::Member14() {};
void IGameEngineHost::GetNextLevelInfo() {};
void IGameEngineHost::Member16() {};
void IGameEngineHost::Member17() {};
void IGameEngineHost::Member18() {};

__int64 __fastcall IGameEngineHost::Member19(__int64 arg)
{
	WriteLineVerbose("GameEngineHostCallback::Member19 %016llx", arg);
	return __int64(0);
};

void IGameEngineHost::Member20() {};
void IGameEngineHost::Member21() {};
void IGameEngineHost::Member22() {};
void IGameEngineHost::Member23() {};

void IGameEngineHost::Member24()
{
	WriteLineVerbose("GameLoaded");
	SplashScreen::Destroy();
	ShowWindow(CustomWindow::s_hwnd, SW_SHOW);
	SetFocus(CustomWindow::s_hwnd);
};

void IGameEngineHost::Member25() {};
void IGameEngineHost::Member26() {};
void IGameEngineHost::Member27() {};
void IGameEngineHost::Member28() {};
void IGameEngineHost::Member29() {};

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
				pInputBuffer->data0[i] = (keyboardState[i] & 0b10000000) != 0;
			}
		}
	}

	if (IGameEngineHost::g_waitingForInputUpdate) // #TODO: Remove when mouse input is figured out
	{
		IGameEngineHost::g_waitingForInputUpdate = false;
		return unsigned __int8(1);
	}
	return unsigned __int8(0);
};

void IGameEngineHost::SetPlayerName() {};
void IGameEngineHost::Member32() {};
void IGameEngineHost::Member33() {};
void IGameEngineHost::NetworkSendTo() {};
void IGameEngineHost::NetworkReceiveFrom() {};
void IGameEngineHost::Member36() {};
void IGameEngineHost::Member37() {};
void IGameEngineHost::Member38() {};
void IGameEngineHost::Member39() {};
void IGameEngineHost::Member40() {};
void IGameEngineHost::Member41() {};
void IGameEngineHost::FileAccessed() {};
void IGameEngineHost::Member43() {};


