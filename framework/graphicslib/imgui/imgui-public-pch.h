#pragma once

#ifdef BCS_IMGUI
#pragma push_macro("new")
#undef new
#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#pragma pop_macro("new")

#include "imgui_math.h"
#include "imgui_memory_editor.h"
#include "begin_popup_modal_ex.h"
#include "imgui_text_editor.h"
#include "imgui_async_file_dialog.h"
#endif
