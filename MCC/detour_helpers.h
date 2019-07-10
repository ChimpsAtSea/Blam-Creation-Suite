#pragma once

#include <Windows.h>

#define roundup(n, denominator) (((n + denominator - 1) / denominator ) * denominator )

extern const char* GetDetourResultStr(LONG detourAttachResult);
