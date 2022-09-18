function(bcs_low_level_tag_project TARGET_NAME PCH_NAME GEN_ENGINE GEN_PLATFORM)
	set(PFX_LOWLEVEL_MACRO_${TARGET_NAME} ${CMAKE_CURRENT_BINARY_DIR}/low_level_${GEN_ENGINE}_${GEN_PLATFORM})
	set(PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT LowLevel_${TARGET_NAME}_${GEN_PLATFORM})

	add_library(${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT} STATIC
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}.cpp
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_enum.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_ida.h)
	
	bcs_set_compile_properties(${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT})
	
	get_target_property(${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT}_SOURCES ${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT} SOURCES)
	source_group(TREE ${PFX_LOWLEVEL_MACRO_${TARGET_NAME}} FILES ${${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT}_SOURCES})
	
	set_source_files_properties(
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}.cpp
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_enum.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_ida.h
		PROPERTIES GENERATED ON)
		
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lowlevel-private-pch.h.in ${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lowlevel-public-pch.h.in ${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h)
		
	target_include_directories(${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT} PRIVATE
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}})
	
	target_link_libraries(${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT} PUBLIC
		blamlib Platform TemplateLibrary TagDefinitions TagReflection)
		
	target_precompile_headers(${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT} PRIVATE
		"$<$<COMPILE_LANGUAGE:CXX>:${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h>")
		
	set_target_properties(${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT} PROPERTIES
		FOLDER "Tags/Generated")
	
	list(APPEND BCS_GENERATED_TAG_PROJECTS ${PFX_LOWLEVEL_MACRO_${TARGET_NAME}_PROJECT})
	set(BCS_GENERATED_TAG_PROJECTS ${BCS_GENERATED_TAG_PROJECTS} PARENT_SCOPE)
endfunction()

function(bcs_high_level_tag_project TARGET_NAME PCH_NAME GEN_ENGINE GEN_PLATFORM)
	set(PFX_HIGHLEVEL_MACRO_${TARGET_NAME} ${CMAKE_CURRENT_BINARY_DIR}/high_level_${GEN_ENGINE}_${GEN_PLATFORM})
	set(PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT HighLevel_${TARGET_NAME}_${GEN_PLATFORM})

	add_library(${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT} ${BCS_LIBRARY_TYPE}
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_misc.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_virtual.cpp)
	
	math(EXPR COUNT_HIGHLEVEL_MACRO_${TARGET_NAME} "${BCS_NUM_GENERATED_CTORS} - 1")
	foreach(INDEX RANGE ${COUNT_HIGHLEVEL_MACRO_${TARGET_NAME}})
		list(APPEND ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT}_SOURCES ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_constructor${INDEX}.cpp)
		target_sources(${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT} PRIVATE
			${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_constructor${INDEX}.cpp)
		set_source_files_properties(
			${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_constructor${INDEX}.cpp
			PROPERTIES GENERATED ON)
	endforeach()
	
	bcs_set_compile_properties(${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT})
	
	source_group(TREE ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}} FILES ${${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT}_SOURCES})
	
	set_source_files_properties(
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_misc.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${GEN_ENGINE}_${GEN_PLATFORM}_virtual.cpp
		PROPERTIES GENERATED ON)
		
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/highlevel-private-pch.h.in ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/highlevel-public-pch.h.in ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h)
		
	target_include_directories(${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT} PRIVATE
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}})
	
	target_link_libraries(${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT} PRIVATE
		blamlib Platform TemplateLibrary TagDefinitions TagReflection LowLevel_${TARGET_NAME}_${GEN_PLATFORM})
		
	target_precompile_headers(${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT} PRIVATE
		"$<$<COMPILE_LANGUAGE:CXX>:${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h>")
		
	set_target_properties(${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT} PROPERTIES
		FOLDER "Tags/Generated")
		
	list(APPEND BCS_GENERATED_TAG_PROJECTS ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}_PROJECT})
	set(BCS_GENERATED_TAG_PROJECTS ${BCS_GENERATED_TAG_PROJECTS} PARENT_SCOPE)
endfunction()

function(bcs_tag_project_platforms TARGET_NAME GEN_ENGINE)
	foreach(GEN_PLATFORM IN LISTS ARGN)
		bcs_low_level_tag_project(${TARGET_NAME} "lowlevel-${GEN_ENGINE}-${GEN_PLATFORM}" ${GEN_ENGINE} ${GEN_PLATFORM})
		bcs_high_level_tag_project(${TARGET_NAME} "highlevel-${GEN_ENGINE}-${GEN_PLATFORM}" ${GEN_ENGINE} ${GEN_PLATFORM})
	endforeach()
	set(BCS_GENERATED_TAG_PROJECTS ${BCS_GENERATED_TAG_PROJECTS} PARENT_SCOPE)
endfunction()

#bcs_tag_project_platforms("Groundhog" "groundhog" "pc64")
#bcs_tag_project_platforms("Halo1" "halo1" "xbox" "pc32" "pc64")
#bcs_tag_project_platforms("Halo2" "halo2" "xbox" "pc32" "pc64")
#bcs_tag_project_platforms("Halo3" "halo3" "xbox360" "pc64")
#bcs_tag_project_platforms("Halo3ODST" "halo3odst" "xbox360" "pc64")
#bcs_tag_project_platforms("Halo4" "halo4" "xbox360" "pc64")
#bcs_tag_project_platforms("HaloReach" "haloreach" "xbox360" "pc64")
#bcs_tag_project_platforms("Infinite" "infinite" "pc64")
#bcs_tag_project_platforms("Stubbs" "stubbs" "pc64")

bcs_tag_project_platforms("Groundhog" "groundhog" "pc64")
bcs_tag_project_platforms("Halo1" "halo1" "pc64")
bcs_tag_project_platforms("Halo2" "halo2" "pc64")
bcs_tag_project_platforms("Halo3" "halo3" "pc64")
bcs_tag_project_platforms("Halo3ODST" "halo3odst" "pc64")
bcs_tag_project_platforms("Halo4" "halo4" "xbox360")
bcs_tag_project_platforms("HaloReach" "haloreach" "xbox360")
bcs_tag_project_platforms("Stubbs" "stubbs" "pc64")
bcs_tag_project_platforms("Infinite" "infinite" "pc64")

set(BCS_GENERATED_TAG_PROJECTS ${BCS_GENERATED_TAG_PROJECTS} PARENT_SCOPE)
