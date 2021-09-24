#pragma once



#ifndef NO_IMGUI
#define IM_ASSERT(_EXPR) ASSERT_NO_THROW(_EXPR)
#include <imgui\imgui.h>
#include <imgui\imgui_internal.h>
#include "IconsFontAwesome5.h"
#endif

#include "shared-system-pch.h"
#include "shared-types-pch.h"

#include "string_helpers.h"

#ifndef NO_IMGUI
#include "ImGuiAddons/!imgui_addons.h"
#endif
#include "Blam/Blam.h"

