add_library(SymbolsLib STATIC
    map_file_parser.cpp
	map_file_parser.h
	
	symbolslib-private-pch.h
	symbolslib-public-pch.h
	symbol_file_header_temp.h
	symbol_file_public_temp.h
	symbol_file_section_temp.h
	symbol_file_static_temp.h)

bcs_set_common_properties(SymbolsLib)

target_link_libraries(SymbolsLib PRIVATE
	Platform SymbolsRuntime Dbghelp)

target_precompile_headers(SymbolsLib PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:symbolslib-private-pch.h>")
	
set_target_properties(SymbolsLib PROPERTIES
	FOLDER "DebugFileTools")
