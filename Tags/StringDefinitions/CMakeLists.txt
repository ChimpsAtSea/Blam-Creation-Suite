add_library(StringDefinitions ${BCS_LIBRARY_TYPE}
	
	legacy_string_id_manager.cpp
	legacy_string_id_manager.h
	string_id_manager.cpp
	string_id_manager.h
	constant_string_id_table.cpp
	constant_string_id_table.h

	StringIDs/eldorado_1_106708_cert_ms23_string_ids.cpp
	StringIDs/eldorado_1_106708_cert_ms23_string_ids.h
	
	stringdefinitions-private-pch.h
	stringdefinitions-public-pch.h)
	
bcs_set_common_properties(StringDefinitions)

target_link_libraries(StringDefinitions PRIVATE
	Platform
	TemplateLibrary)
	
target_precompile_headers(StringDefinitions PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:stringdefinitions-private-pch.h>")
	
set_target_properties(StringDefinitions PROPERTIES
	FOLDER "Tags")
