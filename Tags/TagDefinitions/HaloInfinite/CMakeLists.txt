add_library(HaloInfiniteTagDefinitions ${BCS_LIBRARY_TYPE}
	Reference/haloinfinite-flight2-runtime-pc64.h
	Reference/haloinfinite-flight2-runtime-pc64.cpp
	Reference/haloinfinite-flight2-runtime-pc64-groups.cpp
	Reference/haloinfinite-flight2-runtime-pc64-groups.h
	Reference/haloinfinite-flight1-runtime-pc64.h
	Reference/haloinfinite-flight1-runtime-pc64.cpp
	Reference/haloinfinite-flight1-runtime-pc64-groups.cpp
	Reference/haloinfinite-flight1-runtime-pc64-groups.h
	Reference/haloinfinite-release-runtime-pc64.h
	Reference/haloinfinite-release-runtime-pc64.cpp
	Reference/haloinfinite-release-runtime-pc64-groups.cpp
	Reference/haloinfinite-release-runtime-pc64-groups.h
	haloinfinite-runtime-pc64.cpp
	haloinfinite-runtime-pc64.h
	haloinfinite-runtime-pc64-groups.cpp
	haloinfinite-runtime-pc64-groups.h
	haloinfinitetagdefinitions-public-pch.h
	haloinfinitetagdefinitions-private-pch.h)

bcs_set_common_properties(HaloInfiniteTagDefinitions)
bcs_set_post_build_symbol_preprocess(HaloInfiniteTagDefinitions)

target_link_libraries(HaloInfiniteTagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework)
	
target_precompile_headers(HaloInfiniteTagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:haloinfinitetagdefinitions-private-pch.h>")
	
set_target_properties(HaloInfiniteTagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	