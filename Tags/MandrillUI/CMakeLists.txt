add_library(MandrillUI ${BCS_LIBRARY_TYPE}
	UserInterface/imgui_status_interface.h
	UserInterface/Editors/haloreach_bitmap_test.h
	UserInterface/Editors/infinite_tag_model.h
	UserInterface/Editors/infinite_tag_mesh.h
	UserInterface/Editors/model_preview_test.h
	UserInterface/Editors/surface.h
	UserInterface/Tabs/halo1_bitmap_tag_viewer_tab.h
	UserInterface/Tabs/high_level_tag_editor_tab.h
	UserInterface/Tabs/high_level_tag_tab.h
	UserInterface/Tabs/tag_project_configurator_tab.h
	UserInterface/Tabs/tag_project_tab.h
	UserInterface/Tabs/blofeld_tag_debugger_tab.h
	CustomTools/CustomTools.h
	CustomTools/custom_tool_base.h
	UserInterface/shader_profile.h
	HaloScript/HaloScript.h
	HaloScript/halo_script_function_definition.h
	HaloScript/halo_script_function_documentation.h
	HaloScript/halo_script_globals_definition.h
	HaloScript/halo_script_type_definition.h
	HaloScript/lisp_ast_parser.h
	mandrillui-private-pch.h
	mandrillui-public-pch.h
	UserInterface/Foundation/mandrill_tab_container.h
	UserInterface/Tabs/blofeld_tag_editor.h
	UserInterface/Foundation/mandrill_event_queue.h
	UserInterface/Foundation/mandrill_user_interface.h
	UserInterface/Foundation/mandrill_tab.h
	UserInterface/Tabs/halo_script_editor.h
	UserInterface/UserInterface.h
	UserInterface/imgui_status_interface.cpp
	UserInterface/Editors/haloreach_bitmap_test.cpp
	UserInterface/Editors/infinite_tag_model.cpp
	UserInterface/Editors/infinite_tag_mesh.cpp
	UserInterface/Editors/model_preview_test.cpp
	UserInterface/Editors/surface.cpp
	UserInterface/Tabs/halo1_bitmap_tag_viewer_tab.cpp
	UserInterface/Tabs/high_level_tag_editor_tab.cpp
	UserInterface/Tabs/high_level_tag_tab.cpp
	UserInterface/Tabs/tag_project_configurator_tab.cpp
	UserInterface/Tabs/tag_project_tab.cpp
	UserInterface/Tabs/blofeld_tag_debugger_tab.cpp
	CustomTools/custom_tool_base.cpp
	HaloScript/halo_script_function_definition.cpp
	HaloScript/halo_script_function_documentation.cpp
	HaloScript/halo_script_globals_definition.cpp
	HaloScript/halo_script_type_definition.cpp
	HaloScript/lisp_ast_parser.cpp
	UserInterface/Foundation/mandrill_tab_container.cpp
	UserInterface/Tabs/blofeld_tag_editor.cpp
	UserInterface/Foundation/mandrill_event_queue.cpp
	UserInterface/Foundation/mandrill_user_interface.cpp
	UserInterface/Foundation/mandrill_tab.cpp
	UserInterface/Tabs/halo_script_editor.cpp)

bcs_set_common_properties(MandrillUI)

target_link_libraries(MandrillUI PRIVATE
	blamlib
	GraphicsLib
	DeviceCommunication
	AudioConversion
	imgui
	MandrillLib)

target_link_libraries(MandrillUI PUBLIC
	Shared)

target_precompile_headers(MandrillUI PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:mandrillui-private-pch.h>")
	
set_target_properties(MandrillUI PROPERTIES
	FOLDER "Tags")
