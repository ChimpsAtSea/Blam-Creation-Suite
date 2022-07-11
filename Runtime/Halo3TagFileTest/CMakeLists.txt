add_executable(Halo3TagFileTest
	halo3tagfiletest-private-pch.h
	main.cpp)

bcs_set_common_properties(Halo3TagFileTest)
bcs_set_post_build_shared_lib_dep_copy(Halo3TagFileTest)
bcs_link_platform_resources(Halo3TagFileTest)

target_link_libraries(Halo3TagFileTest PRIVATE
	Platform blamlib DeviceCommunication MandrillLib SymbolsLib ${BCS_GENERATED_TAG_PROJECTS})

target_precompile_headers(Halo3TagFileTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo3tagfiletest-private-pch.h>")
	
set_target_properties(Halo3TagFileTest PROPERTIES
	FOLDER "Runtime")
