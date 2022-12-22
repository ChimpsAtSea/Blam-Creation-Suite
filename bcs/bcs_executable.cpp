#include "bcs.h"

#pragma comment(lib, "libcmt.lib")

__declspec(dllimport) extern int shared_proc();
extern int static_proc();

int main()
{
	return shared_proc() + static_proc() + 1;
}
