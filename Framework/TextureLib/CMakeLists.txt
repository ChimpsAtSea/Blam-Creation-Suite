add_library(TextureLib ${BCS_LIBRARY_TYPE}
	directxtex_texture.cpp
	directxtex_texture.h
	texture.cpp
	texture.h
	texturelib.cpp
	texturelib.h
    texturelib-private-pch.h
    texturelib-public-pch.h)

bcs_set_common_properties(TextureLib)

target_link_libraries(TextureLib PRIVATE
	Platform
	TemplateLibrary
	DirectX-Headers
	GraphicsLib
	DirectXTex)

target_precompile_headers(TextureLib PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:texturelib-private-pch.h>")
	
set_target_properties(TextureLib PROPERTIES
	FOLDER "!Framework")
