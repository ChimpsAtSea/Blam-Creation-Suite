add_executable(ImGUIUIPrototype WIN32
	imguiuiprototype-private-pch.h
	main.cpp
	mandrill_ui_prototype.cpp)

bcs_set_common_properties(ImGUIUIPrototype)
bcs_set_post_build_shared_lib_dep_copy(ImGUIUIPrototype)
bcs_link_platform_resources(ImGUIUIPrototype)

target_link_libraries(ImGUIUIPrototype PRIVATE
	Platform TemplateLibrary GraphicsLib imgui)

target_precompile_headers(ImGUIUIPrototype PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:imguiuiprototype-private-pch.h>")
	
set_target_properties(ImGUIUIPrototype PROPERTIES
	FOLDER "Runtime")
