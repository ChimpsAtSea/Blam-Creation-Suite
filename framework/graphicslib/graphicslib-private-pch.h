#pragma once

#define __IMGUI_ASYNC_FILE_DIALOG_IMPL__

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <hidusage.h>
#include <shellscalingapi.h>

#include <intrin.h>

#include <dxgi.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>
#include <d3d12.h>
#include <d3dx12.h>

#ifdef BCS_DX12_RAY_TRACING_FALLBACK
#include <D3D12RaytracingFallback.h>
#endif

#define IM_ASSERT(_EXPR) 
#include <imgui.h>
#include <imgui_internal.h>

#include <platform\platform-public-pch.h>
#include <templatelibrary\templatelibrary-public-pch.h>

#include <platform/platform-exports-pch.h>

#include "graphicslib-public-pch.h"
#include "d3d12/d3d12-private-pch.h"
#include "windows/windows-private-pch.h"
#include "thirdparty/thirdparty-public-pch.h"

#include "scenes\imgui_viewport_render_context.h"
#include "scenes\window_render_context.h"

#define _XM_NO_INTRINSICS_
#include <DirectXMath.h>

#if defined(_M_X64) || defined(_M_ARM64)
#define USE_PIX
#endif
BCS_WARNING_PUSH();
BCS_WARNING_DIAGNOSTIC_IGNORED("-Wmicrosoft-cast");
#include <WinPixEventRuntime/pix3.h>
BCS_WARNING_POP();
