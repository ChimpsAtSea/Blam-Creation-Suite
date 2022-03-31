add_executable(Mandrill WIN32
	mandrill-private-pch.h
	main.cpp)

bcs_set_common_properties(Mandrill)
bcs_set_post_build_shared_lib_dep_copy(Mandrill)
bcs_link_platform_resources(Mandrill)

target_link_libraries(Mandrill PRIVATE
	Platform blamlib DeviceCommunication MandrillLib MandrillUI GraphicsLib SymbolsLib)

target_precompile_headers(Mandrill PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:mandrill-private-pch.h>")
	
set_target_properties(Mandrill PROPERTIES
	FOLDER "Runtime")
