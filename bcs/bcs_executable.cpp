#include "bcs.h"
#include <stdio.h>

extern int shared_proc();
extern int static_proc();

extern "C" int bcs_main()
{
	puts("Hello BCS World");

	return shared_proc() + static_proc() + 1;
}
