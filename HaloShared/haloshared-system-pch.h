#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_MEAN_AND_LEAN
#define DIRECTINPUT_VERSION 0x0800

#include <mmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <tmmintrin.h>
#include <smmintrin.h>
#include <nmmintrin.h>
//#include <ammintrin.h>
//#include <wmmintrin.h>
//#include <immintrin.h>

#define __int128 __m128

#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <sqltypes.h>
#include <shlwapi.h>

#include <dinput.h>
#include <D3Dcompiler.h>
#include <dxgi.h>
#include <d3d11.h>
#include <d3d11_4.h>

#include <detours.h>

#include <assert.h>
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <intrin.h>
#include <immintrin.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <thread>
#include <atomic>
#include <functional>
#include <algorithm>

#include <imgui\imgui.h>
#include <imgui\imgui_impl_win32.h>
#include <imgui\imgui_impl_dx11.h>

#include "hexrays_defs.h"
#include "resource.h"

#define FATAL_ERROR(reason, ...) _wassert(_CRT_WIDE(reason), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)); throw

