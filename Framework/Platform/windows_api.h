#pragma once

#include <windows.h>
#include <hidusage.h>
#include <objidl.h>
#include <gdiplus.h>
#include <sqltypes.h>
#include <shlwapi.h>
#include <DbgHelp.h>
#include <Shlobj.h>
#include <ShellScalingApi.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <D3Dcompiler.h>
#include <dxgi.h>
#include <dxgi1_5.h>
#include <d3d11.h>
#include <d3d11_4.h>
#include <Xinput.h>
#include <DirectXMath.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#else
#define UWP_PLATFORM
#endif

#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

