add_library(imgui ${BCS_LIBRARY_TYPE}
	imgui/backends/imgui_impl_dx12.h
	imgui/backends/imgui_impl_win32.h
	imgui/imgui.h
	imgui/imgui_internal.h
	imgui/imstb_rectpack.h
	imgui/imstb_textedit.h
	imgui/imstb_truetype.h
	imgui_user_config.h
	
	imgui/backends/imgui_impl_dx12.cpp
	imgui/backends/imgui_impl_win32.cpp
	imgui/imgui.cpp
	imgui/imgui_demo.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp)

bcs_set_common_properties(imgui)

target_compile_definitions(imgui PRIVATE
	$<$<CONFIG:DEBUG>:IMGUI_DISABLE_DEFAULT_ALLOCATORS>
	$<$<BOOL:BCS_BUILD_SHARED_LIBRARIES>:IMGUI_DLL_EXPORT>)

target_include_directories(imgui PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/imgui)

set_target_properties(imgui PROPERTIES
	FOLDER "ThirdParty")
