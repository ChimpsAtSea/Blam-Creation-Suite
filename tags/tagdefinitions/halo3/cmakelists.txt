add_library(Halo3TagDefinitions ${BCS_LIBRARY_TYPE}
	halo3-tools-pc64.cpp
	halo3-tools-pc64.h
	halo3-tools-pc64-groups.cpp
	halo3-tools-pc64-groups.h
	halo3tagdefinitions-public-pch.h
	halo3tagdefinitions-private-pch.h)

bcs_set_common_properties(Halo3TagDefinitions)
bcs_set_post_build_symbol_preprocess(Halo3TagDefinitions)

target_link_libraries(Halo3TagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(Halo3TagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo3tagdefinitions-private-pch.h>")
	
set_target_properties(Halo3TagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	