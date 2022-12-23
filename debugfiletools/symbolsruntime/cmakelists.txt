add_library(SymbolsRuntime ${BCS_LIBRARY_TYPE}
	runtime_symbols.h
	runtime_symbols.cpp
	
	symbol_manager.h
	symbol_manager.cpp
	
	symbolsruntime-private-pch.h
	symbolsruntime-public-pch.h
	symbol_file_header.h
	symbol_file_public.h
	symbol_file_section.h
	symbol_file_static.h)

bcs_set_common_properties(SymbolsRuntime)

target_link_libraries(SymbolsRuntime PRIVATE
	Platform Shlwapi)
	
target_precompile_headers(SymbolsRuntime PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:symbolsruntime-private-pch.h>")
	
set_target_properties(SymbolsRuntime PROPERTIES
	FOLDER "DebugFileTools")
