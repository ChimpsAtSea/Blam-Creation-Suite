add_library(TagDefinitions ${BCS_LIBRARY_TYPE}
	tagdefinitions.natvis
	entry.cpp
	tagdefinitions-public-pch.h
	tagdefinitions-private-pch.h
	tagdefinitions-generated-pch.h)

bcs_set_common_properties(TagDefinitions)
bcs_set_post_build_symbol_preprocess(TagDefinitions)

target_link_libraries(TagDefinitions PRIVATE
	Platform
	TemplateLibrary
	SymbolsLib
	TagFramework
	TagReflection)
	
if(${BCS_BUILD_HIGH_LEVEL_HALO_1})
	target_link_libraries(TagDefinitions PUBLIC Halo1TagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_STUBBS})
	target_link_libraries(TagDefinitions PUBLIC StubbsTagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_2})
	target_link_libraries(TagDefinitions PUBLIC Halo2TagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_3})
	target_link_libraries(TagDefinitions PUBLIC Halo3TagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_3_ODST})
	target_link_libraries(TagDefinitions PUBLIC Halo3ODSTTagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_ELDORADO})
	target_link_libraries(TagDefinitions PUBLIC EldoradoTagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_REACH})
	target_link_libraries(TagDefinitions PUBLIC HaloReachTagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_4})
	target_link_libraries(TagDefinitions PUBLIC Halo4TagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_GROUNDHOG})
	target_link_libraries(TagDefinitions PUBLIC GroundhogTagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_5})
	target_link_libraries(TagDefinitions PUBLIC Halo5TagDefinitions)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_INFINITE})
	target_link_libraries(TagDefinitions PUBLIC HaloInfiniteTagDefinitions)
endif()
	
target_precompile_headers(TagDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:tagdefinitions-private-pch.h>")
	
set_target_properties(TagDefinitions PROPERTIES
	FOLDER "Tags/TagDefinitions")
	