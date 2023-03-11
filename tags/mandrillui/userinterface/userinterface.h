#pragma once

#include "shader_profile.h"
#include "imgui_status_interface.h"

#include "foundation\mandrill_event_queue.h"
#include "foundation\mandrill_tab_container.h"
#include "foundation\mandrill_tab.h"
#include "foundation\mandrill_user_interface.h"

#include "tabs\blofeld_tag_debugger_tab.h"
#include "tabs\blofeld_tag_editor.h"
#include "tabs\tag_project_tab.h"
#include "tabs\high_level_tag_tab.h"
#include "tabs\high_level_tag_editor_tab.h"
#include "tabs\halo_script_editor.h"
#include "tabs\tag_project_configurator_tab.h"

#ifdef BCS_BUILD_ENGINE_HALO_1
#include "tabs\halo1\halo1_bitmap_tag_viewer_tab.h"
#endif
#ifdef BCS_BUILD_ENGINE_HALO_REACH
#include "editors\haloreach_bitmap_test.h"
#endif
#ifdef BCS_BUILD_ENGINE_HALO_INFINITE
//#include "editors\model_preview_test.h"
//#include "editors\infinite_tag_model.h"
//#include "editors\infinite_tag_mesh.h"
#endif
