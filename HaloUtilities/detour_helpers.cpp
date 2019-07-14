#include "haloutilities-private-pch.h"

void init_detours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
}

void end_detours()
{
	DetourTransactionCommit();
}

