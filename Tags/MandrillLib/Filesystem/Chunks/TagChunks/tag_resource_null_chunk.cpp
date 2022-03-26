#include "mandrilllib-private-pch.h"

c_tag_resource_null_chunk::c_tag_resource_null_chunk(c_chunk& parent) :
	c_typed_chunk(&parent)
{
	debug_point;
}

c_tag_resource_null_chunk::~c_tag_resource_null_chunk()
{
}

BCS_RESULT c_tag_resource_null_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	ASSERT(userdata != nullptr);
	c_single_tag_file_reader& reader = *static_cast<c_single_tag_file_reader*>(userdata);

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	t_tag_file_reader_metadata_entry& _metadata_entry = reader.metadata_stack.top();
	unsigned long current_block_index = _metadata_entry.id;
	e_tag_file_reader_metadata_entry_type entry_type = _metadata_entry.entry_type;
	ASSERT(entry_type == _tag_file_reader_metadata_entry_type_resource);
	reader.metadata_stack.pop();

	return rs;
}

void c_tag_resource_null_chunk::log_signature() const
{
	console_write_verbose("tg\\0c ");
}
