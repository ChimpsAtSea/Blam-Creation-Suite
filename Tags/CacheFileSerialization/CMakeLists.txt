add_library(CacheFileSerialization ${BCS_LIBRARY_TYPE}

	halo3/halo3_cache_file_header.byteswap.inl
	halo3/halo3_cache_file_header.h
	halo3/halo3_cache_file_header.cpp

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
