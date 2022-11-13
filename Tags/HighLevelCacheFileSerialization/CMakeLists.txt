add_library(HighLevelCacheFileSerialization ${BCS_LIBRARY_TYPE}

	base/cache_cluster.h
	base/cache_file_api.cpp
	base/cache_file_api.h
	base/cache_file_header.cpp
	base/cache_file_header.h
	base/cache_file_reader.cpp
	base/cache_file_reader.h
	base/debug_reader.cpp
	base/debug_reader.h
	base/localization_reader.cpp
	base/localization_reader.h
	base/resource_reader.cpp
	base/resource_reader.h
	base/tag_group.cpp
	base/tag_group.h
	base/tag_instance.cpp
	base/tag_instance.h
	base/tag_reader.cpp
	base/tag_reader.h
	base/api_interop.cpp
	base/api_interop.h
	base/cache_cluster.cpp
	
	high_level_transplant_context.cpp
	high_level_transplant_context.h
	high_level_ctor.cpp

	highlevelcachefileserialization-private-pch.h
	highlevelcachefileserialization-public-pch.h)
	

if(${BCS_BUILD_HIGH_LEVEL_HALO_1})
	target_sources(HighLevelCacheFileSerialization PRIVATE
		halo1/halo1_cache_cluster.h
		halo1/halo1_cache_file_reader.cpp
		halo1/halo1_cache_file_reader.h
		halo1/halo1_debug_reader.cpp
		halo1/halo1_debug_reader.h
		halo1/halo1_localization_reader.cpp
		halo1/halo1_localization_reader.h
		halo1/halo1_resource_reader.cpp
		halo1/halo1_resource_reader.h
		halo1/halo1_tag_group.cpp
		halo1/halo1_tag_group.h
		halo1/halo1_tag_group_hierarchy.cpp
		halo1/halo1_tag_group_hierarchy.h
		halo1/halo1_tag_instance.cpp
		halo1/halo1_tag_instance.h
		halo1/halo1_tag_reader.cpp
		halo1/halo1_tag_reader.h
		halo1/halo1_cache_cluster.cpp)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_2})
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_3})
	target_sources(HighLevelCacheFileSerialization PRIVATE
		halo3/halo3_cache_cluster.cpp
		halo3/halo3_cache_cluster.h
		halo3/halo3_cache_file_reader.cpp
		halo3/halo3_cache_file_reader.h
		halo3/halo3_codec.cpp
		halo3/halo3_codec.h
		halo3/halo3_debug_reader.cpp
		halo3/halo3_debug_reader.h
		halo3/halo3_localization_reader.cpp
		halo3/halo3_localization_reader.h
		halo3/halo3_resource_reader.cpp
		halo3/halo3_resource_reader.h
		halo3/halo3_tag_group.cpp
		halo3/halo3_tag_group.h
		halo3/halo3_tag_instance.cpp
		halo3/halo3_tag_instance.h
		halo3/halo3_tag_reader.cpp
		halo3/halo3_tag_reader.h
		halo3/halo3_api_interop.cpp
		halo3/halo3_api_interop.h)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_3_ODST})
endif()
if(${BCS_BUILD_HIGH_LEVEL_ELDORADO})
	target_sources(HighLevelCacheFileSerialization PRIVATE
		eldorado/eldorado_cache_file_reader.cpp
		eldorado/eldorado_cache_file_reader.h
		eldorado/eldorado_debug_reader.cpp
		eldorado/eldorado_debug_reader.h
		eldorado/eldorado_localization_reader.cpp
		eldorado/eldorado_localization_reader.h
		eldorado/eldorado_resource_reader.cpp
		eldorado/eldorado_resource_reader.h
		eldorado/eldorado_tag_group.cpp
		eldorado/eldorado_tag_group.h
		eldorado/eldorado_tag_instance.cpp
		eldorado/eldorado_tag_instance.h
		eldorado/eldorado_tag_reader.cpp
		eldorado/eldorado_tag_reader.h
		eldorado/eldorado_api_interop.cpp
		eldorado/eldorado_api_interop.h
		eldorado/eldorado_cache_cluster.cpp
		eldorado/eldorado_cache_cluster.h)
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_REACH})
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_4})
	#target_sources(HighLevelCacheFileSerialization PRIVATE
	#	halo4/halo4_api_interop.h
	#	halo4/halo4_cache_cluster.cpp
	#	halo4/halo4_cache_cluster.h
	#	halo4/halo4_cache_file_reader.cpp
	#	halo4/halo4_cache_file_reader.h
	#	halo4/halo4_codec.cpp
	#	halo4/halo4_codec.h
	#	halo4/halo4_debug_reader.cpp
	#	halo4/halo4_debug_reader.h
	#	halo4/halo4_localization_reader.cpp
	#	halo4/halo4_localization_reader.h
	#	halo4/halo4_resource_container.cpp
	#	halo4/halo4_resource_container.h
	#	halo4/halo4_resource_reader.cpp
	#	halo4/halo4_resource_reader.h
	#	halo4/halo4_tag_group.cpp
	#	halo4/halo4_tag_group.h
	#	halo4/halo4_tag_group_hierarchy.cpp
	#	halo4/halo4_tag_group_hierarchy.h
	#	halo4/halo4_tag_instance.cpp
	#	halo4/halo4_tag_instance.h
	#	halo4/halo4_tag_reader.cpp
	#	halo4/halo4_tag_reader.h
	#	halo4/halo4.natvis
	#	halo4/halo4_api_interop.cpp)
endif()
if(${BCS_BUILD_HIGH_LEVEL_GROUNDHOG})
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_5})
endif()
if(${BCS_BUILD_HIGH_LEVEL_HALO_INFINITE})
	target_sources(HighLevelCacheFileSerialization PRIVATE
	haloinfinite/infinite_debug_reader.cpp
	haloinfinite/infinite_debug_reader.h
	haloinfinite/infinite_file_entry_block_map.cpp
	haloinfinite/infinite_file_entry_block_map.h
	haloinfinite/infinite_generic_module_file_entry.cpp
	haloinfinite/infinite_generic_module_file_entry.h
	haloinfinite/infinite_localization_reader.cpp
	haloinfinite/infinite_localization_reader.h
	haloinfinite/infinite_resource_reader.cpp
	haloinfinite/infinite_resource_reader.h
	haloinfinite/infinite_tag_group.cpp
	haloinfinite/infinite_tag_group.h
	haloinfinite/infinite_tag_instance.cpp
	haloinfinite/infinite_tag_instance.h
	haloinfinite/infinite_tag_reader.cpp
	haloinfinite/infinite_tag_reader.h
	haloinfinite/infinite_ucs_reader.cpp
	haloinfinite/infinite_ucs_reader.h
	haloinfinite/infinite_cache_cluster.cpp
	haloinfinite/infinite_cache_cluster.h
	haloinfinite/infinite_cache_file_reader.cpp
	haloinfinite/infinite_cache_file_reader.h)
endif()
if(${BCS_BUILD_HIGH_LEVEL_STUBBS})
endif()


bcs_set_common_properties(HighLevelCacheFileSerialization)

target_link_libraries(HighLevelCacheFileSerialization PRIVATE
	murmur3
	Oozle
	lzxlib
	pugixml
	xxhash
	zlib
	Platform
	TemplateLibrary
	Shared
	TagDefinitions
	StringDefinitions
	CacheFileSerialization
	TagFileSerialization
	TagReflection
	blamlib
	${BCS_GENERATED_TAG_PROJECTS})
	
target_precompile_headers(HighLevelCacheFileSerialization PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:highlevelcachefileserialization-private-pch.h>")
	
set_target_properties(HighLevelCacheFileSerialization PROPERTIES
	FOLDER "Tags")
