add_library(CacheFileSerialization ${BCS_LIBRARY_TYPE}

	gen3/gen3_cache_file_header.h
	gen3/gen3_cache_file_header.cpp

	cachefileserialization-private-pch.h
	cachefileserialization-public-pch.h)
	
bcs_set_common_properties(CacheFileSerialization)

target_link_libraries(CacheFileSerialization PRIVATE
	Platform
	TemplateLibrary
	Shared)
	
target_precompile_headers(CacheFileSerialization PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:cachefileserialization-private-pch.h>")
	
set_target_properties(CacheFileSerialization PROPERTIES
	FOLDER "Tags")


if(${BCS_BUILD_HIGH_LEVEL_HALO_1})
	target_sources(CacheFileSerialization PRIVATE
		halo1/halo1_cache_file_header.cpp
		halo1/halo1_cache_file_header.h)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_2})
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_3})
	target_sources(CacheFileSerialization PRIVATE
		halo3/halo3_cache_file_header.byteswap.inl
		halo3/halo3_cache_file_header.h
		halo3/halo3_cache_file_header.cpp)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_3_ODST})
endif()
if(${BCS_BUILD_HIGH_LEVEL_ELDORADO})
	target_sources(CacheFileSerialization PRIVATE
		eldorado/cache_file_tag_instance.h
		eldorado/cache_file_tags_header.h
		eldorado/strings_file_header.h)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_REACH})
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_4})
	target_sources(CacheFileSerialization PRIVATE
		halo4/halo4_cache_file_header.cpp
		halo4/halo4_cache_file_header.h)
endif()
if(${BCS_BUILD_HIGH_LEVEL_GROUNDHOG})
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_5})
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_INFINITE})
	target_sources(CacheFileSerialization PRIVATE
		haloinfinite/haloinfinite_cache_file_header.cpp
		haloinfinite/haloinfinite_cache_file_header.h)
endif()
if(${BCS_BUILD_HIGH_LEVEL_STUBBS})
endif()
