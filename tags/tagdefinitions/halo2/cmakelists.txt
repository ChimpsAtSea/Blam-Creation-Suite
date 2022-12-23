add_library(Halo2TagDefinitions ${BCS_LIBRARY_TYPE}
	halo2-tools-pc64.cpp
	halo2-tools-pc64.h
	halo2-tools-pc64-groups.cpp
	halo2-tools-pc64-groups.h
	#halo2-tools-pc32cpp
	#halo2-tools-pc32h
	#halo2-tools-pc32groups.cpp
	#halo2-tools-pc32groups.h
	halo2tagdefinitions-public-pch.h
	halo2tagdefinitions-private-pch.h)

bcs_set_common_properties(Halo2TagDefinitions)
bcs_set_post_build_symbol_preprocess(Halo2TagDefinitions)

target_link_libraries(Halo2TagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(Halo2TagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo2tagdefinitions-private-pch.h>")
	
set_target_properties(Halo2TagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	