#include "opusframework-private-pch.h"

#ifdef _WIN64


#pragma comment(lib, "steam_api64.lib")
#pragma comment(lib, "haloreachlib.lib")
#pragma comment(lib, "halo1lib.lib")
#pragma comment(lib, "halo2lib.lib")
//#pragma comment(lib, "halo5lib.lib")
#pragma comment(lib, "groundhoglib.lib")

extern void register_haloreachlib();
extern void register_halo1lib();
extern void register_halo2lib();
//extern void register_halo5lib();
extern void register_groundhoglib();

void register_platforms()
{
	register_haloreachlib();
	register_halo1lib();
	register_halo2lib();
	//register_halo5lib();
	register_groundhoglib();
}

#else
#pragma comment(lib, "eldoradolib.lib")

extern void register_eldoradolib();

void register_platforms()
{
	register_eldoradolib();
}

#endif
