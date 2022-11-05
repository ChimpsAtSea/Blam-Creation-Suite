#pragma once

class c_monolithic_partition_view;

class c_monolithic_resource_handle :
	public h_resource
{
public:
	BCS_SHARED c_monolithic_resource_handle(
		c_monolithic_partition_view& resource_partition_view,
		s_monolithic_resource_xsync_state_v2& resource_xsync_state);
	~c_monolithic_resource_handle();

	virtual BCS_RESULT add_reference(const void*& buffer, uint32_t& buffer_size) override;
	virtual BCS_RESULT remove_reference() override;
	virtual const char* get_debug_type_string() override;

protected:
	s_monolithic_resource_xsync_state_v2 resource_xsync_state;
	const wchar_t* partition_filepath;
	int32_t reference_count;
	t_memory_mapped_file* tag_memory_mapped_file;
	s_memory_mapped_file_info tag_memory_mapped_file_info;
};
