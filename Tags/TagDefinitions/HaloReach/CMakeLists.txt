add_library(HaloReachTagDefinitions ${BCS_LIBRARY_TYPE}
	haloreach-tagtest-xbox360.cpp
	haloreach-tagtest-xbox360.h
	haloreach-tagtest-xbox360-groups.cpp
	haloreach-tagtest-xbox360-groups.h
	#haloreach-tools-pc64.cpp
	#haloreach-tools-pc64.h
	#haloreach-tools-pc64-groups.cpp
	#haloreach-tools-pc64-groups.h
	haloreachtagdefinitions-public-pch.h
	haloreachtagdefinitions-private-pch.h)

bcs_set_common_properties(HaloReachTagDefinitions)
bcs_set_post_build_symbol_preprocess(HaloReachTagDefinitions)

target_link_libraries(HaloReachTagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(HaloReachTagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:haloreachtagdefinitions-private-pch.h>")
	
set_target_properties(HaloReachTagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	