#include "bcs.h"

BCS_SHARED extern "C" int python_test(int a, int b)
{
	return a + b;
}
