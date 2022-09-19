add_executable(Halo2TagFileTest
	halo2tagfiletest-private-pch.h
	main.cpp)

bcs_set_common_properties(Halo2TagFileTest)
bcs_set_post_build_shared_lib_dep_copy(Halo2TagFileTest)
bcs_link_platform_resources(Halo2TagFileTest)

target_link_libraries(Halo2TagFileTest PRIVATE
	Platform blamlib DeviceCommunication MandrillLib SymbolsLib ${BCS_GENERATED_TAG_PROJECTS})

target_precompile_headers(Halo2TagFileTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo2tagfiletest-private-pch.h>")
	
set_target_properties(Halo2TagFileTest PROPERTIES
	FOLDER "Runtime/Development")
