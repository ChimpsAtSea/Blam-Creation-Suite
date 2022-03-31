add_executable(TagFieldTypeLookupTable
	blofeld_field_type_accelerator.h
	blofeld_field_type_accelerator.inl

	tagfieldtypelookuptable-private-pch.h

	main.cpp)

bcs_set_common_properties(TagFieldTypeLookupTable)
bcs_set_post_build_shared_lib_dep_copy(TagFieldTypeLookupTable)

target_link_libraries(TagFieldTypeLookupTable PRIVATE
	blamlib Platform TemplateLibrary TagDefinitions)

target_precompile_headers(TagFieldTypeLookupTable PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagfieldtypelookuptable-private-pch.h>")
	
set_target_properties(TagFieldTypeLookupTable PROPERTIES
	FOLDER "Tooling")
