#include "mandrilllib-private-pch.h"

c_monolithic_partition_view::c_monolithic_partition_view(wchar_t* partition_filepath, e_monolithic_partition_view_type partition_view_type) :
	partition_filepath(_wcsdup(partition_filepath)),
	buffer(),
	buffer_size(),
	partition_view_type(partition_view_type),
	tag_memory_mapped_file(),
	tag_memory_mapped_file_info()
{
	switch (partition_view_type)
	{
	case _monolithic_partition_view_type_mapped_file:
	{
		BCS_FAIL_THROW(create_memory_mapped_file(partition_filepath, true, tag_memory_mapped_file));
		BCS_FAIL_THROW(get_memory_mapped_file_info(tag_memory_mapped_file, tag_memory_mapped_file_info));

		buffer = tag_memory_mapped_file_info.file_view_begin;
		buffer_size = tag_memory_mapped_file_info.file_size;
	}
	break;
	case _monolithic_partition_view_type_memory:
	{
		BCS_FAIL_THROW(filesystem_read_file_to_memory(partition_filepath, buffer, buffer_size));
	}
	break;
	}
}

c_monolithic_partition_view::~c_monolithic_partition_view()
{
	switch (partition_view_type)
	{
	case _monolithic_partition_view_type_mapped_file:
	{
		BCS_FAIL_THROW(destroy_memory_mapped_file(tag_memory_mapped_file));
	}
	break;
	case _monolithic_partition_view_type_memory:
	{
		tracked_free(buffer);
	}
	break;
	}
	untracked_free(partition_filepath);
}
