set(TBB_BUILD_TBBMALLOC ON)
set(TBB_BUILD_TBBMALLOC_PROXY OFF)
set(TBB_BUILD_TESTS OFF)
set(TBB_BUILD_SHARED OFF)
set(TBB_BUILD_STATIC ON)
add_subdirectory(tbb)

set_target_properties(tbb_static tbbmalloc_static tbb_def_files PROPERTIES
	FOLDER "ThirdParty")

add_subdirectory(DirectX-Headers)

set_target_properties(DirectX-Guids PROPERTIES
	FOLDER "ThirdParty")

set(BUILD_TESTING OFF)
set(BUILD_SHARED_LIBS OFF)
add_subdirectory(pugixml)

set_target_properties(pugixml-shared pugixml-static pugixml PROPERTIES
	FOLDER "ThirdParty")

add_subdirectory(zlib)
add_subdirectory(Oozle)
add_subdirectory(murmur3)
add_subdirectory(lzxlib)
add_subdirectory(xxhash)
add_subdirectory(imgui)
