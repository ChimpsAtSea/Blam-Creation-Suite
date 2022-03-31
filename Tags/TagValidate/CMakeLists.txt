add_library(TagValidate STATIC
	field_validation_result.cpp
	field_validation_result.h
	tagvalidate-private-pch.h
	tagvalidate-public-pch.h)

bcs_set_common_properties(TagValidate)

# this isn't the actual libs required but i don't care
target_link_libraries(TagValidate PRIVATE
	blamlib Platform TemplateLibrary Shared TagDefinitions)
	
target_precompile_headers(TagValidate PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagvalidate-private-pch.h>")
	
set_target_properties(TagValidate PROPERTIES
	FOLDER "Tags")
