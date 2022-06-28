function(bcs_low_level_tag_project TARGET_NAME PCH_NAME GEN_NAME)
	set(PFX_LOWLEVEL_MACRO_${TARGET_NAME} ${CMAKE_CURRENT_BINARY_DIR}/low_level_${GEN_NAME})

	add_library(LowLevel_${TARGET_NAME} STATIC
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.cpp
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.enum.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_ida.h)
	
	bcs_set_compile_properties(LowLevel_${TARGET_NAME})
	
	get_target_property(LowLevel_${TARGET_NAME}_SOURCES LowLevel_${TARGET_NAME} SOURCES)
	source_group(TREE ${PFX_LOWLEVEL_MACRO_${TARGET_NAME}} FILES ${LowLevel_${TARGET_NAME}_SOURCES})
	
	set_source_files_properties(
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.cpp
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.enum.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_ida.h
		PROPERTIES GENERATED ON)
		
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lowlevel-private-pch.h.in ${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lowlevel-public-pch.h.in ${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h)
		
	target_include_directories(LowLevel_${TARGET_NAME} PRIVATE
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}})
	
	target_link_libraries(LowLevel_${TARGET_NAME} PUBLIC
		blamlib Platform TemplateLibrary TagDefinitions TagReflection)
		
	target_precompile_headers(LowLevel_${TARGET_NAME} PRIVATE
		"$<$<COMPILE_LANGUAGE:CXX>:${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h>")
		
	set_target_properties(LowLevel_${TARGET_NAME} PROPERTIES
		FOLDER "Tags/Generated")
	
	list(APPEND BCS_GENERATED_TAG_PROJECTS LowLevel_${TARGET_NAME})
	set(BCS_GENERATED_TAG_PROJECTS ${BCS_GENERATED_TAG_PROJECTS} PARENT_SCOPE)
endfunction()

bcs_low_level_tag_project("Groundhog" "lowlevel-groundhog" "groundhog")
bcs_low_level_tag_project("Halo1" "lowlevel-halo1" "halo1")
bcs_low_level_tag_project("Halo2" "lowlevel-halo2" "halo2")
bcs_low_level_tag_project("Halo3" "lowlevel-halo3" "halo3")
bcs_low_level_tag_project("Halo3ODST" "lowlevel-halo3odst" "halo3odst")
bcs_low_level_tag_project("Halo4" "lowlevel-halo4" "halo4")
bcs_low_level_tag_project("HaloReach" "lowlevel-haloreach" "haloreach")
bcs_low_level_tag_project("Infinite" "lowlevel-infinite" "infinite")
bcs_low_level_tag_project("Stubbs" "lowlevel-stubbs" "stubbs")
bcs_low_level_tag_project("Xbox360Gen3" "lowlevel-xbox360gen3" "xbox360_gen3")

function(bcs_high_level_tag_project TARGET_NAME PCH_NAME GEN_NAME)
	set(PFX_HIGHLEVEL_MACRO_${TARGET_NAME} ${CMAKE_CURRENT_BINARY_DIR}/high_level_${GEN_NAME})

	add_library(HighLevel_${TARGET_NAME} ${BCS_LIBRARY_TYPE}
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_high_level.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_high_level.misc.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_high_level.virtual.cpp)
	
	math(EXPR COUNT_HIGHLEVEL_MACRO_${TARGET_NAME} "${BCS_NUM_GENERATED_CTORS} - 1")
	foreach(INDEX RANGE ${COUNT_HIGHLEVEL_MACRO_${TARGET_NAME}})
		list(APPEND HighLevel_${TARGET_NAME}_SOURCES ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_high_level.ctor${INDEX}.cpp)
		target_sources(HighLevel_${TARGET_NAME} PRIVATE
			${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_high_level.ctor${INDEX}.cpp)
		set_source_files_properties(
			${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_high_level.ctor${INDEX}.cpp
			PROPERTIES GENERATED ON)
	endforeach()
	
	bcs_set_compile_properties(HighLevel_${TARGET_NAME})
	
	source_group(TREE ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}} FILES ${HighLevel_${TARGET_NAME}_SOURCES})
	
	set_source_files_properties(
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_high_level.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_high_level.misc.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_high_level.virtual.cpp
		PROPERTIES GENERATED ON)
		
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/highlevel-private-pch.h.in ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/highlevel-public-pch.h.in ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h)
		
	target_include_directories(HighLevel_${TARGET_NAME} PRIVATE
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}})
	
	target_link_libraries(HighLevel_${TARGET_NAME} PRIVATE
		blamlib Platform TemplateLibrary TagDefinitions TagReflection LowLevel_${TARGET_NAME})
		
	target_precompile_headers(HighLevel_${TARGET_NAME} PRIVATE
		"$<$<COMPILE_LANGUAGE:CXX>:${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h>")
		
	set_target_properties(HighLevel_${TARGET_NAME} PROPERTIES
		FOLDER "Tags/Generated")
		
	list(APPEND BCS_GENERATED_TAG_PROJECTS HighLevel_${TARGET_NAME})
	set(BCS_GENERATED_TAG_PROJECTS ${BCS_GENERATED_TAG_PROJECTS} PARENT_SCOPE)
endfunction()

bcs_high_level_tag_project("Groundhog" "highlevel-groundhog" "groundhog")
bcs_high_level_tag_project("Halo1" "highlevel-halo1" "halo1")
bcs_high_level_tag_project("Halo2" "highlevel-halo2" "halo2")
bcs_high_level_tag_project("Halo3" "highlevel-halo3" "halo3")
bcs_high_level_tag_project("Halo3ODST" "highlevel-halo3odst" "halo3odst")
bcs_high_level_tag_project("Halo4" "highlevel-halo4" "halo4")
bcs_high_level_tag_project("HaloReach" "highlevel-haloreach" "haloreach")
bcs_high_level_tag_project("Infinite" "highlevel-infinite" "infinite")
bcs_high_level_tag_project("Stubbs" "highlevel-stubbs" "stubbs")
bcs_high_level_tag_project("Xbox360Gen3" "highlevel-xbox360gen3" "xbox360_gen3")

set(BCS_GENERATED_TAG_PROJECTS ${BCS_GENERATED_TAG_PROJECTS} PARENT_SCOPE)
