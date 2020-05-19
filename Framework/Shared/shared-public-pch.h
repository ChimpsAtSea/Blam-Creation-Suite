#pragma once

#include "shared-system-pch.h"
#include "shared-tbb-pch.h"
#include "shared-types-pch.h"

#include "xxhash_cx.h"
using namespace xxhash;
using namespace xxhash::literals;

#include "debug_util.h"
#include "string_helpers.h"

#include "high_precision_timer.h"
#include "ThreadPrimitives/ThreadPrimitives.h"
#include "StringUtilities.h"
#include "Runtime.h"
#include "console.h"
#include "AtomicLock.h"
#include "ThreadSafeQueue.h"
#include "ImGuiAddons/!imgui_addons.h"
#include "DebugLogging.h"
#include "command_line.h"
#include "filesystem_util.h"
#include "Rendering/Rendering.h"
#include "Blam/Blam.h"

