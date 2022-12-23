add_library(Halo3ODSTTagDefinitions ${BCS_LIBRARY_TYPE}
	halo3odst-tools-pc64.cpp
	halo3odst-tools-pc64.h
	halo3odst-tools-pc64-groups.cpp
	halo3odst-tools-pc64-groups.h
	halo3odsttagdefinitions-public-pch.h
	halo3odsttagdefinitions-private-pch.h)

bcs_set_common_properties(Halo3ODSTTagDefinitions)
bcs_set_post_build_symbol_preprocess(Halo3ODSTTagDefinitions)

target_link_libraries(Halo3ODSTTagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(Halo3ODSTTagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo3odsttagdefinitions-private-pch.h>")
	
set_target_properties(Halo3ODSTTagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	