add_library(TagReflection STATIC
	tagreflection-private-pch.h
	tagreflection-public-pch.h
	
	high_level_tag.h
	high_level_tag.cpp)

bcs_set_common_properties(TagReflection)

target_link_libraries(TagReflection PRIVATE
	blamlib Platform TemplateLibrary Shared SymbolsLib TagDefinitions)
	
target_precompile_headers(TagReflection PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagreflection-private-pch.h>")
	
set_target_properties(TagReflection PROPERTIES
	FOLDER "Tags")

add_dependencies(TagReflection TagCodegenGenerate)
