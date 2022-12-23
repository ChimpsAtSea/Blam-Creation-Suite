#pragma once

enum e_monolithic_partition_view_type
{
	_monolithic_partition_view_type_none,
	_monolithic_partition_view_type_mapped_file,
	_monolithic_partition_view_type_memory,
};

class c_monolithic_partition_view
{
public:
	c_monolithic_partition_view(wchar_t* partition_filepath, e_monolithic_partition_view_type partition_view_type);
	~c_monolithic_partition_view();

	const wchar_t* partition_filepath;		
	void* buffer;
	uint64_t buffer_size;
	e_monolithic_partition_view_type partition_view_type;
	t_memory_mapped_file* tag_memory_mapped_file;
	s_memory_mapped_file_info tag_memory_mapped_file_info;
};
