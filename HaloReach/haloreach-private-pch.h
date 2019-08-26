#pragma once

#ifdef __cplusplus

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_MEAN_AND_LEAN
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include <d3d11.h>
#include <D3Dcompiler.h>

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <assert.h>
#include <inttypes.h>

#include <thread>
#include <atomic>

#include <imgui\imgui.h>
#include <imgui\imgui_impl_win32.h>
#include <imgui\imgui_impl_dx11.h>

#include "resource.h"
#include "splash_screen.h"

#include <detours.h>
#include <HaloUtilities/logging.h>
#include <HaloUtilities/detour_helpers_private.h>

#include <HaloUtilities/haloutilities-public-pch.h>
#include <MCC/mcc-public-pch.h>
#include "haloreach-public-pch.h"

#include "local_types.h"
#include <HaloShared/haloshared-public-pch.h>

#endif
