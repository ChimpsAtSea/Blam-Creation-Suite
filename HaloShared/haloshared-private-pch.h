#pragma once

// System headers

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_MEAN_AND_LEAN
#include <windows.h>
#include <d3d11.h>
#include <D3Dcompiler.h>
#include <dxgi.h>
#include <d3d11_4.h>
#include <dinput.h>

#include <assert.h>
#include <detours.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <intrin.h>
#include <immintrin.h>

#include <functional>
#include <thread>

#include <imgui\imgui.h>
#include <imgui\imgui_impl_win32.h>
#include <imgui\imgui_impl_dx11.h>

// External headers

#include <HaloUtilities/logging.h>
#include <HaloUtilities/detour_helpers_private.h>
#include <HaloUtilities/haloutilities-public-pch.h>
#include <MCC/mcc-public-pch.h>

// Project headers

#include <HaloReach/local_types.h>
#include <HaloShared/haloshared-public-pch.h>

// crazy nasty shit to be removed



