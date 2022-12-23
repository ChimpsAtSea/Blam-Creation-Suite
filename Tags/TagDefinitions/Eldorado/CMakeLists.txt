add_library(EldoradoTagDefinitions ${BCS_LIBRARY_TYPE}
	eldorado-pc32.cpp
	eldorado-pc32.h
	eldorado-pc32-groups.cpp
	eldorado-pc32-groups.h
	eldoradotagdefinitions-public-pch.h
	eldoradotagdefinitions-private-pch.h)

bcs_set_common_properties(EldoradoTagDefinitions)
bcs_set_post_build_symbol_preprocess(EldoradoTagDefinitions)

target_link_libraries(EldoradoTagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(EldoradoTagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:eldoradotagdefinitions-private-pch.h>")
	
set_target_properties(EldoradoTagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	