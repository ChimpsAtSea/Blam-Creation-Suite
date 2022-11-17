add_library(TagReflection ${BCS_LIBRARY_TYPE}
	tagreflection-private-pch.h
	tagreflection-public-pch.h
	global_high_level_configuration.cpp
	global_high_level_configuration.h
	high_level_library_registry.cpp
	high_level_library_registry.h)

bcs_set_common_properties(TagReflection)

if(BCS_BUILD_HIGH_LEVEL_VERSION2)
	target_sources(TagReflection PRIVATE
		Version2/block.cpp
		Version2/block.h
		Version2/extended_type.cpp
		Version2/extended_type.h
		Version2/field.h
		Version2/high_level_cast.h
		Version2/member_info.h
		Version2/prototype.cpp
		Version2/prototype.h
		Version2/prototype_field.h
		Version2/string_field.cpp
		Version2/string_field.h
		Version2/tag_group.cpp
		Version2/tag_group.h
		Version2/tag_instance.cpp
		Version2/tag_instance.h
		Version2/typed_field.h
		Version2/type.h)
else()
	target_sources(TagReflection PRIVATE
		TagReflection\Version1\data.h
		TagReflection\Version1\enumerable.cpp
		TagReflection\Version1\enumerable.h
		TagReflection\Version1\field.cpp
		TagReflection\Version1\field.h
		TagReflection\Version1\group.cpp
		TagReflection\Version1\group.h
		TagReflection\Version1\object.cpp
		TagReflection\Version1\object.h
		TagReflection\Version1\resource.cpp
		TagReflection\Version1\resource.h
		TagReflection\Version1\resource_field.cpp
		TagReflection\Version1\resource_field.h
		TagReflection\Version1\string_id.cpp
		TagReflection\Version1\string_id.h
		TagReflection\Version1\tag.cpp
		TagReflection\Version1\tag.h
		TagReflection\Version1\tag_reference.cpp
		TagReflection\Version1\tag_reference.h
		TagReflection\Version1\type.cpp
		TagReflection\Version1\type.h
		TagReflection\Version1\typed_array.cpp
		TagReflection\Version1\typed_array.h
		TagReflection\Version1\typed_block.cpp
		TagReflection\Version1\typed_block.h
		TagReflection\Version1\watchdog.cpp
		TagReflection\Version1\watchdog.h
		TagReflection\Version1\block.cpp
		TagReflection\Version1\block.h
		TagReflection\Version1\data.cpp)
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
