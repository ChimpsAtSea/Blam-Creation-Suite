add_executable(SymbolsPreprocessor
	main.cpp)

bcs_set_common_properties(SymbolsPreprocessor)
bcs_set_post_build_shared_lib_dep_copy(SymbolsPreprocessor)

target_link_libraries(SymbolsPreprocessor PRIVATE
	Platform SymbolsLib)

target_link_libraries(SymbolsPreprocessor PUBLIC
	Dbghelp)
	
set_target_properties(SymbolsPreprocessor PROPERTIES
	FOLDER "DebugFileTools")

function(bcs_set_post_build_symbol_preprocess TARGET_NAME)
	if (BCS_BUILD_SHARED_LIBRARIES)
		add_dependencies(${TARGET_NAME} SymbolsPreprocessor)
		add_custom_command(
			TARGET ${TARGET_NAME} POST_BUILD
			COMMAND "$<TARGET_FILE:SymbolsPreprocessor>"
				"-symbolfile:$<TARGET_FILE_DIR:${TARGET_NAME}>/$<TARGET_FILE_BASE_NAME:${TARGET_NAME}>.map" "-outputfile:$<TARGET_FILE:${TARGET_NAME}>.sym"
			VERBATIM)
		install(FILES "$<TARGET_FILE:${TARGET_NAME}>.sym" DESTINATION bin)
	endif()
endfunction()
