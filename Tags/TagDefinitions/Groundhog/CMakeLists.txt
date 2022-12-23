add_library(GroundhogTagDefinitions ${BCS_LIBRARY_TYPE}
	groundhog-pc64.cpp
	groundhog-pc64.h
	groundhog-pc64-groups.cpp
	groundhog-pc64-groups.h
	groundhogtagdefinitions-public-pch.h
	groundhogtagdefinitions-private-pch.h)

bcs_set_common_properties(GroundhogTagDefinitions)
bcs_set_post_build_symbol_preprocess(GroundhogTagDefinitions)

target_link_libraries(GroundhogTagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(GroundhogTagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:groundhogtagdefinitions-private-pch.h>")
	
set_target_properties(GroundhogTagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	