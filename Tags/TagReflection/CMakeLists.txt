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
	block.cpp
	block.h
	prototype.cpp
	prototype.h)

bcs_set_common_properties(TagReflection)

if(BCS_BUILD_HIGH_LEVEL_VERSION2)
	target_sources(TagReflection PRIVATE
		#Version2/block.cpp
		#Version2/block.h
		Version2/extended_type.cpp
		Version2/extended_type.h
		Version2/field.h
		Version2/high_level_cast.h
		#Version2/prototype.cpp
		#Version2/prototype.h
		Version2/prototype_field.h
		Version2/typed_field.h
		Version2/type.h)
else()
	target_sources(TagReflection PRIVATE
		#Version1/block.cpp
		#Version1/block.h
		Version1/data.cpp
		Version1/data.h
		Version1/enumerable.cpp
		Version1/enumerable.h
		Version1/field.cpp
		Version1/field.h
		Version1/typed_field.cpp
		Version1/typed_field.h
		#Version1/prototype.cpp
		#Version1/prototype.h
		Version1/resource.cpp
		Version1/resource.h
		Version1/resource_field.cpp
		Version1/resource_field.h
		Version1/tag_reference.cpp
		Version1/tag_reference.h
		Version1/type.cpp
		Version1/type.h
		Version1/extended_type.cpp
		Version1/extended_type.h
		Version1/typed_array.cpp
		Version1/typed_array.h
		Version1/typed_block.cpp
		Version1/typed_block.h
		Version1/watchdog.cpp
		Version1/watchdog.h)
endif()

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
