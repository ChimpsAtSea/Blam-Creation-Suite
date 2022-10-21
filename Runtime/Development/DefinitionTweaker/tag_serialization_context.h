#pragma once

class c_serializtion_error;
class c_tag_struct_serializtion_context;

struct s_file_last_modification_date
{
	unsigned long filetime_low;
	unsigned long filetime_high;
};

struct s_cache_file_tags_header
{
	dword __unknown0;
	int tag_cache_offsets;
	int tag_count;
	dword __unknownC;
	s_file_last_modification_date creation_date;
	dword __unknown18;
	dword __unknown1C;
};
static_assert(sizeof(s_cache_file_tags_header) == 0x20);

struct s_cache_file_tag_instance
{
	dword checksum;
	dword total_size;
	short dependency_count;
	short data_fixup_count;
	short resource_fixup_count;
	short : 16;
	dword offset; // offset from `base`
	tag group_tags[3];
	dword group_name; // string id
};
static_assert(sizeof(s_cache_file_tag_instance) == 0x24);

class c_group_serialization_context;

class c_tag_serialization_context
{
public:
	s_engine_platform_build engine_platform_build;
	const char* tag_data_start;
	const char* tag_data_end;
	const s_cache_file_tag_instance* tag_header;
	const int* dependencies;
	const int* data_fixups;
	const int* resource_fixups;
	const int* _end;
	const char* tag_root_structure;
	unsigned int expected_main_struct_size;
	c_tag_struct_serializtion_context* root_struct_serialization_context;
	c_group_serialization_context* group_serialization_context;;
	std::vector<c_serializtion_error*> serialization_errors;

	c_tag_serialization_context(c_group_serialization_context* group_serialization_context, s_engine_platform_build _engine_platform_build, const char* _tag_data_start);
	c_tag_serialization_context(c_tag_serialization_context const&) = delete;
	~c_tag_serialization_context();
	unsigned int read();
	unsigned int traverse();
};
