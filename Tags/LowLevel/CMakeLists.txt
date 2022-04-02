function(bcs_macro_low_level_project TARGET_NAME PCH_NAME GEN_NAME)
	set(PFX_LOWLEVEL_MACRO_${TARGET_NAME} ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/low_level_${GEN_NAME})

	add_library(${TARGET_NAME} STATIC
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-public-pch.h
		
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.cpp
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.enum.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_ida.h)
	
	bcs_set_compile_properties(${TARGET_NAME})
	
	get_target_property(${TARGET_NAME}_SOURCES ${TARGET_NAME} SOURCES)
	source_group(TREE ${PFX_LOWLEVEL_MACRO_${TARGET_NAME}} FILES ${${TARGET_NAME}_SOURCES})
	
	set_source_files_properties(
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.cpp
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}.enum.h
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${GEN_NAME}_ida.h
		PROPERTIES GENERATED ON)
		
	target_include_directories(${TARGET_NAME} PUBLIC
		${PFX_LOWLEVEL_MACRO_${TARGET_NAME}})
	
	target_link_libraries(${TARGET_NAME} PRIVATE
		blamlib Platform TemplateLibrary TagDefinitions TagReflection)
		
	target_precompile_headers(${TARGET_NAME} PRIVATE
		"$<$<COMPILE_LANGUAGE:CXX>:${PFX_LOWLEVEL_MACRO_${TARGET_NAME}}/${PCH_NAME}-private-pch.h>")
		
	set_target_properties(${TARGET_NAME} PROPERTIES
		FOLDER "Tags/LowLevel")
endfunction()

bcs_macro_low_level_project("LowLevel_Groundhog" "lowlevel-groundhog" "groundhog")
bcs_macro_low_level_project("LowLevel_Halo1" "lowlevel-halo1" "halo1")
bcs_macro_low_level_project("LowLevel_Halo2" "lowlevel-halo2" "halo2")
bcs_macro_low_level_project("LowLevel_Halo3" "lowlevel-halo3" "halo3")
bcs_macro_low_level_project("LowLevel_Halo3ODST" "lowlevel-halo3odst" "halo3odst")
bcs_macro_low_level_project("LowLevel_Halo4" "lowlevel-halo4" "halo4")
bcs_macro_low_level_project("LowLevel_HaloReach" "lowlevel-haloreach" "haloreach")
bcs_macro_low_level_project("LowLevel_Infinite" "lowlevel-infinite" "infinite")
bcs_macro_low_level_project("LowLevel_Stubbs" "lowlevel-stubbs" "stubbs")
bcs_macro_low_level_project("LowLevel_Xbox360Gen3" "lowlevel-xbox360gen3" "xbox360_gen3")
