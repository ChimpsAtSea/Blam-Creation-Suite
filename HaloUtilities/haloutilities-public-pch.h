#pragma once


#define FATAL_ERROR(reason) _wassert(_CRT_WIDE(reason), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)); throw


#include "HaloGameID.h"
#include "logging.h"
#include "detour_helpers.h"
#include "defs.h"
