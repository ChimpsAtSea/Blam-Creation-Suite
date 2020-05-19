#include "ketchup-private-pch.h"

_test::_test(const char* pMask, ...)
	: Instruction(pMask, false)
{
	va_list args;
	va_start(args, pMask);
	init(pMask, args);
	va_end(args);
}