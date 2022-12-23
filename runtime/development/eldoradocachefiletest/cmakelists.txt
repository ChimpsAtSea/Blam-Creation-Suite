add_executable(EldoradoCacheFileTest
	eldoradocachefiletest-private-pch.h
	main.cpp)

bcs_set_common_properties(EldoradoCacheFileTest)
bcs_set_post_build_shared_lib_dep_copy(EldoradoCacheFileTest)
bcs_link_platform_resources(EldoradoCacheFileTest)
bcs_executable_setup(EldoradoCacheFileTest)

target_link_libraries(EldoradoCacheFileTest PRIVATE
	murmur3
	Oozle
	lzxlib
	blamlib
	pugixml
	xxhash
	zlib
	Shared
	Platform
	TemplateLibrary
	TagDefinitions
	TagRegistry
	TagReflection
	TagFileSerialization
	CacheFileSerialization
	HighLevelCacheFileSerialization
	${BCS_GENERATED_TAG_PROJECTS})

target_precompile_headers(EldoradoCacheFileTest PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:eldoradocachefiletest-private-pch.h>")
	
set_target_properties(EldoradoCacheFileTest PROPERTIES
	FOLDER "Runtime/Development")
