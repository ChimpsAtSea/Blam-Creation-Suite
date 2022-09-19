add_library(TextureLib ${BCS_LIBRARY_TYPE}
	texturelib.cpp
    texturelib-private-pch.h
    texturelib-public-pch.h)

bcs_set_common_properties(TextureLib)

target_link_libraries(TextureLib PRIVATE
	Platform TemplateLibrary DirectX-Headers)

target_precompile_headers(TextureLib PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:texturelib-private-pch.h>")
	
set_target_properties(TextureLib PROPERTIES
	FOLDER "!Framework")
