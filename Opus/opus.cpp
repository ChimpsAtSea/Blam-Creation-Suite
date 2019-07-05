#include "opus-private-pch.h"



Opus::Opus()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());






	DetourTransactionCommit();
}

Opus::~Opus()
{




}

