#pragma once

#define IM_ASSERT(_EXPR) ASSERT_NO_THROW(_EXPR)
#include <imgui\imgui.h>
#include <imgui\imgui_internal.h>
#include <imgui\imgui_impl_win32.h>
#include <imgui\imgui_impl_dx11.h>

#include "hexrays_defs.h" // #TODO: Integrate this into a global types definition list

#include "shared-system-pch.h"
#include "shared-tbb-pch.h"
#include "shared-types-pch.h"

#include "xxhash_cx.h"
using namespace xxhash;
using namespace xxhash::literals;

#include "string_helpers.h"

#include "high_precision_timer.h"
#include "ThreadPrimitives/ThreadPrimitives.h"
#include "StringUtilities.h"
#include "AtomicLock.h"
#include "ThreadSafeQueue.h"
#include "ImGuiAddons/!imgui_addons.h"
#include "Rendering/Rendering.h"
#include "Blam/Blam.h"

