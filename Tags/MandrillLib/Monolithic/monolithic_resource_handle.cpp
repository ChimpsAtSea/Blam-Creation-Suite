#include "mandrilllib-private-pch.h"

c_monolithic_resource_handle::c_monolithic_resource_handle(
	c_monolithic_partition_view& resource_partition_view,
	s_monolithic_resource_xsync_state_v2& resource_xsync_state) :
	resource_xsync_state(resource_xsync_state),
	partition_filepath(_wcsdup(resource_partition_view.partition_filepath)),
	reference_count(0),
	tag_memory_mapped_file(),
	tag_memory_mapped_file_info()
{
	
}

c_monolithic_resource_handle::~c_monolithic_resource_handle()
{
	ASSERT(reference_count == 0);
	untracked_free(partition_filepath);
}

BCS_RESULT c_monolithic_resource_handle::add_reference(const void*& buffer, uint32_t& buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	int32_t reference_index = reference_count;
	
	if (reference_index == 0)
	{
		if (BCS_FAILED(rs = create_memory_mapped_file(partition_filepath, true, tag_memory_mapped_file)))
		{
			return rs;
		}

		if (BCS_FAILED(rs = get_memory_mapped_file_info(tag_memory_mapped_file, tag_memory_mapped_file_info)))
		{
			destroy_memory_mapped_file(tag_memory_mapped_file);
			return rs;
		}
	}
	reference_count++;
	ASSERT(reference_count > 0);

	const char* resource_data_start = tag_memory_mapped_file_info.file_view_begin + resource_xsync_state.cache_location_offset;
	const char* resource_data_end = resource_data_start + resource_xsync_state.cache_location_size;

	buffer = resource_data_start;
	buffer_size = static_cast<unsigned long>(resource_data_end - resource_data_start);

	return rs;
}

BCS_RESULT c_monolithic_resource_handle::remove_reference()
{
	BCS_RESULT rs = BCS_S_OK;
	int32_t reference_index = reference_count--;
	ASSERT(reference_count >= 0);

	if (reference_index == 0)
	{
		if (BCS_FAILED(rs = destroy_memory_mapped_file(tag_memory_mapped_file)))
		{
			return rs;
		}
	}

	return rs;
}

const char* c_monolithic_resource_handle::get_debug_type_string()
{
	return "c_monolithic_resource_handle";
}
