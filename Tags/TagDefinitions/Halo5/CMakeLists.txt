add_library(Halo5TagDefinitions ${BCS_LIBRARY_TYPE}
	halo5-runtime-pc64.cpp
	halo5-runtime-pc64.h
	halo5-runtime-pc64-groups.cpp
	halo5-runtime-pc64-groups.h
	halo5tagdefinitions-public-pch.h
	halo5tagdefinitions-private-pch.h)

bcs_set_common_properties(Halo5TagDefinitions)
bcs_set_post_build_symbol_preprocess(Halo5TagDefinitions)

target_link_libraries(Halo5TagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(Halo5TagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo5tagdefinitions-private-pch.h>")
	
set_target_properties(Halo5TagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	