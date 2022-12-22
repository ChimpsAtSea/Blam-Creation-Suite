add_library(TagReflection ${BCS_LIBRARY_TYPE}
	tagreflection-private-pch.h
	tagreflection-public-pch.h
	global_high_level_configuration.cpp
	global_high_level_configuration.h
	high_level_library_registry.cpp
	high_level_library_registry.h
	pointer_to_member.h
	member_info.h
	serialization_info.h
	string_id_field.cpp
	string_id_field.h
	tag_group.cpp
	tag_group.h
	tag_instance.cpp
	tag_instance.h
	array.cpp
	array.h
	block.cpp
	block.h
	prototype.cpp
	prototype.h
	resource.cpp
	resource.h
	resource_field.cpp
	resource_field.h
	data.cpp
	data.h
	enumerable.cpp
	enumerable.h
	field.cpp
	field.h
	typed_field.cpp
	typed_field.h
	tag_reference.cpp
	tag_reference.h
	type.cpp
	type.h
	extended_type.cpp
	extended_type.h
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
	blamlib)
	
target_precompile_headers(TagReflection PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagreflection-private-pch.h>")
	
set_target_properties(TagReflection PROPERTIES
	FOLDER "Tags")

#add_dependencies(TagReflection TagCodegenGenerate)
