#include "bcs.h"

#ifdef BCS_SHARED_LIBRARY
__declspec(dllexport)
#endif
int shared_proc()
{
	return 100;
}
