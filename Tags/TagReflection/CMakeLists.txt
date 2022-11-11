add_library(TagReflection STATIC
	tagreflection-private-pch.h
	tagreflection-public-pch.h
	
	block.cpp
	block.h
	data.cpp
	data.h
	enumerable.cpp
	enumerable.h
	field.cpp
	field.h
	group.cpp
	group.h
	object.cpp
	object.h
	resource.cpp
	resource.h
	resource_field.cpp
	resource_field.h
	string_id.cpp
	string_id.h
	tag.cpp
	tag.h
	tag_reference.cpp
	tag_reference.h
	type.cpp
	type.h
	typed_array.cpp
	typed_array.h
	typed_block.cpp
	typed_block.h
	watchdog.cpp
	watchdog.h)

bcs_set_common_properties(TagReflection)

target_compile_definitions(TagReflection PRIVATE
	BCS_IS_HIGH_LEVEL_BUILD_PROJECT)

target_link_libraries(TagReflection PUBLIC
	Platform 
	TemplateLibrary 
	Shared 
	SymbolsLib 
	TagFramework
	TagDefinitions
	blamlib)
	
target_precompile_headers(TagReflection PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagreflection-private-pch.h>")
	
set_target_properties(TagReflection PROPERTIES
	FOLDER "Tags")

add_dependencies(TagReflection TagCodegenGenerate)
