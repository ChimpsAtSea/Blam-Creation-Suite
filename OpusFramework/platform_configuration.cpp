#include "opusframework-private-pch.h"

#ifdef _WIN64


#pragma comment(lib, "steam_api64.lib")
#pragma comment(lib, "haloreachlib.lib")
#pragma comment(lib, "halo1lib.lib")

extern void register_haloreachlib();
extern void register_halo1lib();

void register_platforms()
{
	register_haloreachlib();
	register_halo1lib();
}

#else
#pragma comment(lib, "eldoradolib.lib")

extern void register_eldoradolib();

void register_platforms()
{
	register_eldoradolib();
}

#endif
