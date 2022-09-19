add_executable(GraphicsTest WIN32
	graphicstest-private-pch.h
	main.cpp)

bcs_set_common_properties(GraphicsTest)
bcs_set_post_build_shared_lib_dep_copy(GraphicsTest)
bcs_link_platform_resources(GraphicsTest)

target_link_libraries(GraphicsTest PRIVATE
	Platform TemplateLibrary GraphicsLib)

target_precompile_headers(GraphicsTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:graphicstest-private-pch.h>")
	
set_target_properties(GraphicsTest PROPERTIES
	FOLDER "Runtime/Development")
