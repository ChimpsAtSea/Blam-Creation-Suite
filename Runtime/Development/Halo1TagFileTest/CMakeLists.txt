add_executable(Halo1TagFileTest
	halo1tagfiletest-private-pch.h
	main.cpp)

bcs_set_common_properties(Halo1TagFileTest)
bcs_set_post_build_shared_lib_dep_copy(Halo1TagFileTest)
bcs_link_platform_resources(Halo1TagFileTest)

target_link_libraries(Halo1TagFileTest PRIVATE
	Platform blamlib DeviceCommunication MandrillLib SymbolsLib ${BCS_GENERATED_TAG_PROJECTS})

target_precompile_headers(Halo1TagFileTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo1tagfiletest-private-pch.h>")
	
set_target_properties(Halo1TagFileTest PROPERTIES
	FOLDER "Runtime/Development")
