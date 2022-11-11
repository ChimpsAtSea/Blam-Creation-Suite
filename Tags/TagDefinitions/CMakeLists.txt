add_library(TagDefinitions ${BCS_LIBRARY_TYPE}
	entry.cpp
	tagdefinitions-public-pch.h
	tagdefinitions-private-pch.h
	tagdefinitions-generated-pch.h)

bcs_set_common_properties(TagDefinitions)
bcs_set_post_build_symbol_preprocess(TagDefinitions)

target_link_libraries(TagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(TagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagdefinitions-private-pch.h>")
	
set_target_properties(TagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	