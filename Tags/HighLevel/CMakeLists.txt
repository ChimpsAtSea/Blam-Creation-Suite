function(bcs_macro_high_level_project TARGET_NAME PCH_NAME GEN_NAME)
	set(PFX_HIGHLEVEL_MACRO_${TARGET_NAME} ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/high_level_${GEN_NAME})

	add_library(${TARGET_NAME} ${BCS_LIBRARY_TYPE}
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor0.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor1.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor2.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor3.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor4.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor5.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor6.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor7.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor8.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor9.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor10.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor11.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor12.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor13.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor14.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor15.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor16.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor17.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor18.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor19.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor20.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor21.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor22.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor23.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor24.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor25.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor26.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor27.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor28.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor29.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor30.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor31.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor32.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor33.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor34.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor35.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor36.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor37.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor38.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor39.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor40.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor41.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor42.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor43.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor44.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor45.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor46.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor47.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor48.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor49.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor50.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor51.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor52.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor53.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor54.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor55.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor56.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor57.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor58.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor59.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor60.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor61.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor62.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor63.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.misc.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.virtual.cpp)
	
	bcs_set_compile_properties(${TARGET_NAME})
	
	get_target_property(${TARGET_NAME}_SOURCES ${TARGET_NAME} SOURCES)
	source_group(TREE ${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}} FILES ${${TARGET_NAME}_SOURCES})
	
	set_source_files_properties(
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.h
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor0.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor1.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor2.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor3.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor4.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor5.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor6.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor7.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor8.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor9.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor10.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor11.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor12.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor13.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor14.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor15.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor16.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor17.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor18.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor19.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor20.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor21.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor22.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor23.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor24.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor25.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor26.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor27.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor28.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor29.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor30.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor31.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor32.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor33.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor34.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor35.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor36.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor37.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor38.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor39.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor40.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor41.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor42.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor43.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor44.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor45.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor46.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor47.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor48.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor49.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor50.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor51.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor52.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor53.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor54.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor55.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor56.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor57.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor58.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor59.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor60.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor61.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor62.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.ctor63.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.misc.cpp
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/generated/${GEN_NAME}_high_level.virtual.cpp
		PROPERTIES GENERATED ON)
		
	target_include_directories(${TARGET_NAME} PUBLIC
		${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}})
	
	target_link_libraries(${TARGET_NAME} PRIVATE
		blamlib Platform TemplateLibrary TagDefinitions TagReflection)
		
	target_precompile_headers(${TARGET_NAME} PRIVATE
		"$<$<COMPILE_LANGUAGE:CXX>:${PFX_HIGHLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h>")
		
	set_target_properties(${TARGET_NAME} PROPERTIES
		FOLDER "Tags/HighLevel")
		
	list(APPEND BCS_GENERATED_TAG_PROJECTS ${TARGET_NAME})
	set(BCS_GENERATED_TAG_PROJECTS ${BCS_GENERATED_TAG_PROJECTS} PARENT_SCOPE)
endfunction()

bcs_macro_high_level_project("HighLevel_Groundhog" "highlevel-groundhog" "groundhog")
bcs_macro_high_level_project("HighLevel_Halo1" "highlevel-halo1" "halo1")
bcs_macro_high_level_project("HighLevel_Halo2" "highlevel-halo2" "halo2")
bcs_macro_high_level_project("HighLevel_Halo3" "highlevel-halo3" "halo3")
bcs_macro_high_level_project("HighLevel_Halo3ODST" "highlevel-halo3odst" "halo3odst")
bcs_macro_high_level_project("HighLevel_Halo4" "highlevel-halo4" "halo4")
bcs_macro_high_level_project("HighLevel_HaloReach" "highlevel-haloreach" "haloreach")
bcs_macro_high_level_project("HighLevel_Infinite" "highlevel-infinite" "infinite")
bcs_macro_high_level_project("HighLevel_Stubbs" "highlevel-stubbs" "stubbs")
bcs_macro_high_level_project("HighLevel_Xbox360Gen3" "highlevel-xbox360gen3" "xbox360_gen3")

set(BCS_GENERATED_TAG_PROJECTS ${BCS_GENERATED_TAG_PROJECTS} PARENT_SCOPE)
