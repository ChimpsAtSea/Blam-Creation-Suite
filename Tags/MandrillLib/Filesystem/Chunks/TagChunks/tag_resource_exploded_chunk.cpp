#include "mandrilllib-private-pch.h"

c_tag_resource_exploded_chunk::c_tag_resource_exploded_chunk(c_chunk& parent) :
	c_typed_chunk(&parent)
{
	
}

c_tag_resource_exploded_chunk::~c_tag_resource_exploded_chunk()
{
}

BCS_RESULT c_tag_resource_exploded_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	ASSERT(userdata != nullptr);
	c_single_tag_file_reader& reader = *static_cast<c_single_tag_file_reader*>(userdata);

	t_tag_file_reader_metadata_entry& _metadata_entry = reader.metadata_stack._pop_unsafe();
	uint32_t current_resource_index = _metadata_entry.id;
	e_tag_file_reader_metadata_entry_type entry_type = _metadata_entry.entry_type;
	ASSERT(entry_type == _tag_file_reader_metadata_entry_type_resource);

	s_tag_persist_resource_definition& resource_definition = reader.layout_reader.get_resource_definition_by_index(current_resource_index);
	s_tag_persist_struct_definition& struct_definition = reader.layout_reader.get_struct_definition_by_index(resource_definition.structure_entry_index);

	t_tag_file_reader_metadata_stack metadata_stack;
	reader.read_structure_metadata(struct_definition, metadata_stack);
	reader.metadata_stack.copy_from(metadata_stack);

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	return rs;
}
