add_library(MandrillUI ${BCS_LIBRARY_TYPE}
	CustomTools/CustomTools.h
	CustomTools/custom_tool_base.cpp
	CustomTools/custom_tool_base.h
	HaloScript/HaloScript.h
	HaloScript/halo_script_function_definition.cpp
	HaloScript/halo_script_function_definition.h
	HaloScript/halo_script_function_documentation.cpp
	HaloScript/halo_script_function_documentation.h
	HaloScript/halo_script_globals_definition.cpp
	HaloScript/halo_script_globals_definition.h
	HaloScript/halo_script_type_definition.cpp
	HaloScript/halo_script_type_definition.h
	HaloScript/lisp_ast_parser.cpp
	HaloScript/lisp_ast_parser.h
	UserInterface/Editors/surface.cpp
	UserInterface/Editors/surface.h
	UserInterface/Foundation/mandrill_event_queue.cpp
	UserInterface/Foundation/mandrill_event_queue.h
	UserInterface/Foundation/mandrill_tab.cpp
	UserInterface/Foundation/mandrill_tab.h
	UserInterface/Foundation/mandrill_tab_container.cpp
	UserInterface/Foundation/mandrill_tab_container.h
	UserInterface/Foundation/mandrill_user_interface.cpp
	UserInterface/Foundation/mandrill_user_interface.h
	UserInterface/Tabs/blofeld_tag_debugger_tab.cpp
	UserInterface/Tabs/blofeld_tag_debugger_tab.h
	UserInterface/Tabs/blofeld_tag_editor.cpp
	UserInterface/Tabs/blofeld_tag_editor.h
	UserInterface/Tabs/halo_script_editor.cpp
	UserInterface/Tabs/halo_script_editor.h
	UserInterface/Tabs/high_level_tag_editor_tab.cpp
	UserInterface/Tabs/high_level_tag_editor_tab.h
	UserInterface/Tabs/high_level_tag_tab.cpp
	UserInterface/Tabs/high_level_tag_tab.h
	UserInterface/Tabs/tag_project_configurator_tab.cpp
	UserInterface/Tabs/tag_project_configurator_tab.h
	UserInterface/Tabs/tag_project_tab.cpp
	UserInterface/Tabs/tag_project_tab.export_sounds.inl
	UserInterface/Tabs/tag_project_tab.h
	UserInterface/UserInterface.h
	UserInterface/imgui_status_interface.cpp
	UserInterface/imgui_status_interface.h
	UserInterface/shader_profile.h
	mandrillui-private-pch.h
	mandrillui-public-pch.h)
	
if(${BCS_BUILD_ENGINE_HALO_1})
	add_compile_definitions(BCS_BUILD_ENGINE_HALO_1)
	target_sources(MandrillUI PRIVATE
		UserInterface/Tabs/Halo1/halo1_bitmap_tag_viewer_tab.cpp
		UserInterface/Tabs/Halo1/halo1_bitmap_tag_viewer_tab.h)
endif()
if(${BCS_BUILD_ENGINE_HALO_2})
	add_compile_definitions(BCS_BUILD_ENGINE_HALO_2)
endif()
if(${BCS_BUILD_ENGINE_HALO_3})
	add_compile_definitions(BCS_BUILD_ENGINE_HALO_3)
endif()
if(${BCS_BUILD_ENGINE_HALO_3_ODST})
	add_compile_definitions(BCS_BUILD_ENGINE_HALO_3_ODST)
endif()
if(${BCS_BUILD_ENGINE_HALO_REACH})
	add_compile_definitions(BCS_BUILD_ENGINE_HALO_REACH)
	target_sources(MandrillUI PRIVATE
		UserInterface/Editors/haloreach_bitmap_test.cpp
		UserInterface/Editors/haloreach_bitmap_test.h)
endif()
if(${BCS_BUILD_ENGINE_HALO_4})
	add_compile_definitions(BCS_BUILD_ENGINE_HALO_4)
endif()
if(${BCS_BUILD_ENGINE_HALO_GROUNDHOG})
	add_compile_definitions(BCS_BUILD_ENGINE_HALO_GROUNDHOG)
endif()
if(${BCS_BUILD_ENGINE_HALO_5})
	add_compile_definitions(BCS_BUILD_ENGINE_HALO_5)
endif()
if(${BCS_BUILD_ENGINE_HALO_INFINITE})
	add_compile_definitions(BCS_BUILD_ENGINE_HALO_INFINITE)
	target_sources(MandrillUI PRIVATE
		#UserInterface/Editors/infinite_tag_mesh.cpp
		#UserInterface/Editors/infinite_tag_mesh.h
		#UserInterface/Editors/infinite_tag_model.cpp
		#UserInterface/Editors/infinite_tag_model.h
		#UserInterface/Editors/model_preview_test.cpp
		#UserInterface/Editors/model_preview_test.h
		)
endif()
if(${BCS_BUILD_HIGH_LEVEL_STUBBS})
	add_compile_definitions(BCS_BUILD_HIGH_LEVEL_STUBBS)
endif()

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
