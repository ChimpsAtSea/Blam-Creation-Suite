add_library(TagRegistry ${BCS_LIBRARY_TYPE}
	entry.cpp
	tagregistry-public-pch.h
	tagregistry-private-pch.h)

bcs_set_common_properties(TagRegistry)
bcs_set_post_build_shared_lib_dep_copy(TagRegistry)
bcs_link_platform_resources(TagRegistry)

target_link_libraries(TagRegistry PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework
	TagReflection
	TagDefinitions
	${BCS_GENERATED_TAG_PROJECTS})
	
target_precompile_headers(TagRegistry PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagregistry-private-pch.h>")
	
set_target_properties(TagRegistry PROPERTIES
	FOLDER "Tags")
	