add_library(Halo4TagDefinitions ${BCS_LIBRARY_TYPE}
	halo4-tagtest-xbox360.cpp
	halo4-tagtest-xbox360.h
	halo4-tagtest-xbox360-groups.cpp
	halo4-tagtest-xbox360-groups.h
	halo4-tools-pc64.cpp
	halo4-tools-pc64.h
	halo4-tools-pc64-groups.cpp
	halo4-tools-pc64-groups.h
	halo4tagdefinitions-public-pch.h
	halo4tagdefinitions-private-pch.h)

bcs_set_common_properties(Halo4TagDefinitions)
bcs_set_post_build_symbol_preprocess(Halo4TagDefinitions)

target_link_libraries(Halo4TagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(Halo4TagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo4tagdefinitions-private-pch.h>")
	
set_target_properties(Halo4TagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	