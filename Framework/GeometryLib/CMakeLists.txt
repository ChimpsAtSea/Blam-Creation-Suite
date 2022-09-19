add_library(GeometryLib ${BCS_LIBRARY_TYPE}
	geometrylib.cpp
    geometrylib-private-pch.h
    geometrylib-public-pch.h)

bcs_set_common_properties(GeometryLib)

target_link_libraries(GeometryLib PRIVATE
	Platform TemplateLibrary DirectX-Headers)

target_precompile_headers(GeometryLib PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:geometrylib-private-pch.h>")
	
set_target_properties(GeometryLib PROPERTIES
	FOLDER "!Framework")
