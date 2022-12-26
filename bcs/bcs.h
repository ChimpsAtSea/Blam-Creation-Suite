#pragma once

#ifdef BCS_SHARED_LIBRARY
#ifdef _WIN32
#define BCS_SHARED __declspec(dllexport)
#else
#define BCS_SHARED
#endif
#endif