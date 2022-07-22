add_executable(Halo2CacheFileBuilderTest
	halo2cachefilebuildertest-private-pch.h
	main.cpp)

bcs_set_common_properties(Halo2CacheFileBuilderTest)
bcs_set_post_build_shared_lib_dep_copy(Halo2CacheFileBuilderTest)
bcs_link_platform_resources(Halo2CacheFileBuilderTest)

target_link_libraries(Halo2CacheFileBuilderTest PRIVATE
	Platform blamlib DeviceCommunication MandrillLib SymbolsLib ${BCS_GENERATED_TAG_PROJECTS})

target_precompile_headers(Halo2CacheFileBuilderTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:halo2cachefilebuildertest-private-pch.h>")
	
set_target_properties(Halo2CacheFileBuilderTest PROPERTIES
	FOLDER "Runtime")
