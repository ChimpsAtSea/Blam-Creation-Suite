add_executable(GeometryTest WIN32
	geometrytest-private-pch.h
	main.cpp)

bcs_set_common_properties(GeometryTest)
bcs_set_post_build_shared_lib_dep_copy(GeometryTest)
bcs_link_platform_resources(GeometryTest)

target_link_libraries(GeometryTest PRIVATE
	Platform TemplateLibrary GraphicsLib)

target_precompile_headers(GeometryTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:geometrytest-private-pch.h>")
	
set_target_properties(GeometryTest PROPERTIES
	FOLDER "Runtime/Development")
