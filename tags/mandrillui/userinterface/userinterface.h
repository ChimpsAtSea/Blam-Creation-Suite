#pragma once

#include "shader_profile.h"
#include "imgui_status_interface.h"

#include "Foundation\mandrill_event_queue.h"
#include "Foundation\mandrill_tab_container.h"
#include "Foundation\mandrill_tab.h"
#include "Foundation\mandrill_user_interface.h"

#include "Tabs\blofeld_tag_debugger_tab.h"
#include "Tabs\blofeld_tag_editor.h"
#include "Tabs\tag_project_tab.h"
#include "Tabs\high_level_tag_tab.h"
#include "Tabs\high_level_tag_editor_tab.h"
#include "Tabs\halo_script_editor.h"
#include "Tabs\tag_project_configurator_tab.h"

#include "Editors\surface.h"

#ifdef BCS_BUILD_ENGINE_HALO_1
#include "Tabs\Halo1\halo1_bitmap_tag_viewer_tab.h"
#endif
#ifdef BCS_BUILD_ENGINE_HALO_REACH
#include "Editors\haloreach_bitmap_test.h"
#endif
#ifdef BCS_BUILD_ENGINE_HALO_INFINITE
//#include "Editors\model_preview_test.h"
//#include "Editors\infinite_tag_model.h"
//#include "Editors\infinite_tag_mesh.h"
#endif
