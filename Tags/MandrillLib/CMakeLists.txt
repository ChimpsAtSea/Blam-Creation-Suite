add_library(MandrillLib ${BCS_LIBRARY_TYPE}
	Filesystem/Filesystem.h
	Filesystem/gen1_tag_file_parser.cpp
	Filesystem/gen1_tag_file_parser.h
	Filesystem/gen2_tag_file_parser.cpp
	Filesystem/gen2_tag_file_parser.h
	Filesystem/high_level_tag_file_writer.cpp
	Filesystem/high_level_tag_file_writer.h
	Filesystem/high_level_tag_file_reader.cpp
	Filesystem/high_level_tag_file_reader.h
	Filesystem/tag_file_high_level_transplant.cpp
	Filesystem/tag_file_high_level_transplant.h
	HighLevel/HighLevel.h
	HighLevel/cache_file_project.cpp
	HighLevel/cache_file_project.h
	HighLevel/filesystem_project.cpp
	HighLevel/filesystem_project.h
	HighLevel/high_level_cache_cluster_transplant.cpp
	HighLevel/high_level_cache_cluster_transplant.h
	HighLevel/infinite_string_id_manager.cpp
	HighLevel/infinite_string_id_manager.h
	HighLevel/monolithic_project.cpp
	HighLevel/monolithic_project.h
	HighLevel/simple_resource_container.cpp
	HighLevel/simple_resource_container.h
	HighLevel/tag_project.cpp
	HighLevel/tag_project.h
	HighLevel/infinite_high_level_moule_file_transplant.h
	HighLevel/infinite_high_level_moule_file_transplant.cpp
	Monolithic/Monolithic.h
	Monolithic/monolithic_partition_view.cpp
	Monolithic/monolithic_partition_view.h
	Monolithic/monolithic_resource_handle.cpp
	Monolithic/monolithic_resource_handle.h
	logging_interface.cpp
	logging_interface.h
	mandrilllib-private-pch.h
	mandrilllib-public-pch.h
	status_interface.cpp
	status_interface.h)
		
bcs_set_common_properties(MandrillLib)

target_link_libraries(MandrillLib PUBLIC
	Shared
	Platform
	TemplateLibrary
	TagDefinitions
	TagReflection
	TagValidate
	TagFileSerialization
	murmur3
	Oozle
	lzxlib
	blamlib
	pugixml
	xxhash
	zlib
	CacheFileSerialization
	HighLevelCacheFileSerialization
	StringDefinitions
	${BCS_GENERATED_TAG_PROJECTS})

target_precompile_headers(MandrillLib PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:mandrilllib-private-pch.h>")
	
set_target_properties(MandrillLib PROPERTIES
	FOLDER "Tags")
