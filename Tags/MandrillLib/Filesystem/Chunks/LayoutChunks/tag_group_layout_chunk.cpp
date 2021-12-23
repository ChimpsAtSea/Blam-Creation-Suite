#include "mandrilllib-private-pch.h"

c_tag_group_layout_chunk::c_tag_group_layout_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	tag_group_layout_header(reinterpret_cast<s_tag_group_layout_header*>(chunk_data_begin)),
	layout_header_prechunk(),
	layout_header_preinterop(),
	layout_header_v3()
{
	debug_point;

	switch (tag_group_layout_header->layout_version)
	{
	case _tag_persist_layout_version_prechunk:
	{
		layout_header_prechunk = reinterpret_cast<s_tag_persist_layout_header_prechunk*>(tag_group_layout_header + 1);
		chunk_data_begin = reinterpret_cast<char*>(layout_header_prechunk + 1);

		// #HACK: The same data for this chunk is passed down to the child. This means that the child chunk has the same data
		// begin and end positions as this current chunk.
		c_tag_layout_prechunk_chunk* layout_prechunk_chunk = new c_tag_layout_prechunk_chunk(chunk_data, *this);
		children = new c_chunk * [2]{ layout_prechunk_chunk, nullptr };
	}
	break;
	case _tag_persist_layout_version_preinterop:
	{
		layout_header_preinterop = reinterpret_cast<s_tag_persist_layout_header_preinterop*>(tag_group_layout_header + 1);
		chunk_data_begin = reinterpret_cast<char*>(layout_header_preinterop + 1);
		parse_children(tag_group_layout_header);
	}
	break;
	case _tag_persist_layout_version_v3:
	{
		layout_header_v3 = reinterpret_cast<s_tag_persist_layout_header_v3*>(tag_group_layout_header + 1);
		layout_header_preinterop = layout_header_v3;
		chunk_data_begin = reinterpret_cast<char*>(layout_header_v3 + 1);
		parse_children(tag_group_layout_header);
	}
	break;
	default: FATAL_ERROR("Unknown layout version");
	}
}

unsigned long c_tag_group_layout_chunk::get_tag_group_block_index() const
{
	//if (layout_header_prechunk) return layout_header_prechunk->tag_group_block_index; // #TODO: how to get this???
	if (layout_header_preinterop) return layout_header_preinterop->tag_group_block_index;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_string_data_size() const
{
	if (layout_header_prechunk) return layout_header_prechunk->string_data_size;
	if (layout_header_preinterop) return layout_header_preinterop->string_data_size;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_string_offset_count() const
{
	if (layout_header_prechunk) return layout_header_prechunk->string_offset_count;
	if (layout_header_preinterop) return layout_header_preinterop->string_offset_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_string_list_count() const
{
	if (layout_header_prechunk) return layout_header_prechunk->string_list_count;
	if (layout_header_preinterop) return layout_header_preinterop->string_list_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_custom_block_index_search_names_count() const
{
	if (layout_header_prechunk) return layout_header_prechunk->custom_block_index_search_names_count;
	if (layout_header_preinterop) return layout_header_preinterop->custom_block_index_search_names_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_data_definition_name_count() const
{
	if (layout_header_prechunk) return layout_header_prechunk->data_definition_name_count;
	if (layout_header_preinterop) return layout_header_preinterop->data_definition_name_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_array_definition_count() const
{
	if (layout_header_prechunk) return layout_header_prechunk->array_definition_count;
	if (layout_header_preinterop) return layout_header_preinterop->array_definition_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_field_type_count() const
{
	if (layout_header_prechunk) return layout_header_prechunk->field_type_count;
	if (layout_header_preinterop) return layout_header_preinterop->field_type_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_field_count() const
{
	if (layout_header_prechunk) return layout_header_prechunk->field_count;
	if (layout_header_preinterop) return layout_header_preinterop->field_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_block_definition_count() const
{
	if (layout_header_prechunk) return layout_header_prechunk->aggregate_definition_count;
	if (layout_header_preinterop) return layout_header_preinterop->block_definition_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_struct_definition_count() const
{
	if (layout_header_prechunk) return layout_header_prechunk->aggregate_definition_count;
	if (layout_header_preinterop) return layout_header_preinterop->struct_definition_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_resource_definition_count() const
{
	if (layout_header_preinterop) return layout_header_preinterop->resource_definition_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_interop_definition_count() const
{
	if (layout_header_v3) return layout_header_v3->interop_definition_count;
	return 0;
}

unsigned long c_tag_group_layout_chunk::get_aggregate_definition_count() const
{
	if (layout_header_prechunk) layout_header_prechunk->aggregate_definition_count;
	return 0;
}
