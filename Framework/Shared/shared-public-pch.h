#pragma once

#ifndef NO_IMGUI
#define IM_ASSERT(_EXPR) ASSERT_NO_THROW(_EXPR)
#include <imgui\imgui.h>
#include <imgui\imgui_internal.h>
#include <imgui\imgui_impl_win32.h>
#include <imgui\imgui_impl_dx11.h>
#include "IconsFontAwesome5.h"
#endif

#include "hexrays_defs.h" // #TODO: Integrate this into a global types definition list

#include "shared-system-pch.h"
#include "shared-types-pch.h"

#include "string_helpers.h"

#include "high_precision_timer.h"
#include "ThreadPrimitives/ThreadPrimitives.h"
#include "StringUtilities.h"
#include "ThreadSafeQueue.h"
#ifndef NO_IMGUI
#include "ImGuiAddons/!imgui_addons.h"
#endif
#include "Rendering/Rendering.h"
#include "Blam/Blam.h"

