#pragma once

#if !defined(_DEBUG) && defined(UWP_PLATFORM)
#define FATAL_ERROR(reason, ...) throw
#else
#define FATAL_ERROR(reason, ...) _wassert(_CRT_WIDE(reason), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)); throw
#endif

#define WriteLineVerbose(str, ...) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
printf(str, ##__VA_ARGS__); \
printf("\n")

#define WriteVerbose(str, ...) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
printf(str, ##__VA_ARGS__)

#define WriteColoredLineVerbose(color, str, ...) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  \
printf(str, ##__VA_ARGS__); printf("\n"); \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)

#define WriteColoredVerbose(color, str, ...)  \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  \
printf(str, ##__VA_ARGS__); \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)

#define WriteColoredPrefixVerbose(color, prefix, str, ...) \
WriteColoredVerbose(color, "%s ", prefix); \
WriteLineVerbose(str, ##__VA_ARGS__)


#include "resource.h"

#include <windows.h>
#include <hidusage.h>

#include <D3Dcompiler.h>
#include <dxgi.h>
#include <dxgi1_5.h>
#include <d3d11.h>
#include <d3d11_4.h>
#include <Xinput.h>
#include <DirectXMath.h>

#include <imgui\imgui.h>
#include <imgui\imgui_impl_win32.h>
#include <imgui\imgui_impl_dx11.h>

#include <vector>
#include <algorithm>

#include <stdio.h>
#include <assert.h>

#include "mantle-public-pch.h"

#include "opus_legacy/CustomWindow.h"
#include "opus_legacy/GameRender.h"
#include "opus_legacy/DebugUI.h"

