add_library(Halo1TagDefinitions ${BCS_LIBRARY_TYPE}
	halo1-tools-pc64.cpp
	halo1-tools-pc64.h
	halo1-tools-pc64-groups.cpp
	halo1-tools-pc64-groups.h
	#halo1-tools-pc32cpp
	#halo1-tools-pc32h
	#halo1-tools-pc32groups.cpp
	#halo1-tools-pc32groups.h
	halo1tagdefinitions-public-pch.h
	halo1tagdefinitions-private-pch.h)

bcs_set_common_properties(Halo1TagDefinitions)
bcs_set_post_build_symbol_preprocess(Halo1TagDefinitions)

target_link_libraries(Halo1TagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(Halo1TagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo1tagdefinitions-private-pch.h>")
	
set_target_properties(Halo1TagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	