#pragma once

#pragma push_macro("new")
#undef new
#define IM_ASSERT(_EXPR) ASSERT_NO_THROW(_EXPR)
#include <imgui\imgui.h>
#include <imgui\imgui_internal.h>
#pragma pop_macro("new") 

#include "font_awesome_icons.h"
#include "imgui_memory_editor.h"
#include "begin_popup_modal_ex.h"
#include "imgui_text_editor.h"
#include "imgui_async_file_dialog.h"
