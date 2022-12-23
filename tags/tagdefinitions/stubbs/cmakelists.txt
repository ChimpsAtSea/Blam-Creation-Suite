add_library(StubbsTagDefinitions ${BCS_LIBRARY_TYPE}
	stubbs-pc64.cpp
	stubbs-pc64.h
	stubbs-pc64-groups.cpp
	stubbs-pc64-groups.h
	stubbstagdefinitions-public-pch.h
	stubbstagdefinitions-private-pch.h)

bcs_set_common_properties(StubbsTagDefinitions)
bcs_set_post_build_symbol_preprocess(StubbsTagDefinitions)

target_link_libraries(StubbsTagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(StubbsTagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:stubbstagdefinitions-private-pch.h>")
	
set_target_properties(StubbsTagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	