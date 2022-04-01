#include "mandrilllib-private-pch.h"

c_tag_group_layout_chunk::c_tag_group_layout_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	tag_group_layout_header(),
	layout_header_prechunk(),
	layout_header_preinterop(),
	layout_header_v3()
{
}

c_tag_group_layout_chunk::~c_tag_group_layout_chunk()
{
	
}

BCS_RESULT c_tag_group_layout_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, false)))
	{
		return rs;
	}


	const s_tag_group_layout_header* src_tag_group_layout_header = reinterpret_cast<const s_tag_group_layout_header*>(get_chunk_data_start());
	tag_group_layout_header = chunk_byteswap(*src_tag_group_layout_header);

	

	switch (tag_group_layout_header.layout_version)
	{
	case _tag_persist_layout_version_prechunk:
	{
		const s_tag_persist_layout_header_prechunk* src_layout_header_prechunk = next_contiguous_pointer<s_tag_persist_layout_header_prechunk>(src_tag_group_layout_header);
		layout_header_prechunk_data = chunk_byteswap(*src_layout_header_prechunk);
		layout_header_prechunk = &layout_header_prechunk_data;

		const char* chunk_children_start = next_contiguous_pointer<char>(src_layout_header_prechunk);

		// #HACK: The same data for this chunk is passed down to the child. This means that the child chunk has the same data
		// begin and end positions as this current chunk.
		FATAL_ERROR("TODO: RESTORE THIS");
		//c_tag_layout_prechunk_chunk* layout_prechunk_chunk = new() c_tag_layout_prechunk_chunk(chunk_data, *this);
		//children = new() c_chunk * [2]{ layout_prechunk_chunk, nullptr };
	}
	break;
	case _tag_persist_layout_version_preinterop:
	{
		const s_tag_persist_layout_header_preinterop* src_layout_header_preinterop = next_contiguous_pointer<s_tag_persist_layout_header_preinterop>(src_tag_group_layout_header);
		layout_header_preinterop_data = chunk_byteswap(*src_layout_header_preinterop);
		layout_header_preinterop = &layout_header_preinterop_data;

		const char* chunk_children_start = next_contiguous_pointer<char>(src_layout_header_preinterop);
		if (parse_children)
		{
			read_child_chunks(&tag_group_layout_header, use_read_only, chunk_children_start);
		}
	}
	break;
	case _tag_persist_layout_version_v3:
	{
		const s_tag_persist_layout_header_v3* src_layout_header_v3 = next_contiguous_pointer<s_tag_persist_layout_header_v3>(src_tag_group_layout_header);
		layout_header_v3_data = chunk_byteswap(*src_layout_header_v3);
		layout_header_v3 = &layout_header_v3_data;

		layout_header_preinterop = layout_header_v3;
		const char* chunk_children_start = next_contiguous_pointer<char>(src_layout_header_v3);
		if (parse_children)
		{
			read_child_chunks(&tag_group_layout_header, use_read_only, chunk_children_start);
		}
	}
	break;
	default: FATAL_ERROR("Unknown layout version");
	}

	return rs;
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

template<> void byteswap_inplace(s_tag_group_layout_header& value)
{
	byteswap_inplace(value.unknown);
	byteswap_inplace(*reinterpret_cast<__underlying_type(s_tag_group_layout_header_version)*>(&value.layout_version));
}

template<> void byteswap_inplace(s_tag_persist_layout_header_prechunk& value)
{
	byteswap_inplace(value.string_data_size);
	byteswap_inplace(value.string_offset_count);
	byteswap_inplace(value.string_list_count);
	byteswap_inplace(value.custom_block_index_search_names_count);
	byteswap_inplace(value.data_definition_name_count);
	byteswap_inplace(value.array_definition_count);
	byteswap_inplace(value.field_type_count);
	byteswap_inplace(value.field_count);
	byteswap_inplace(value.aggregate_definition_count);
}

template<> void byteswap_inplace(s_tag_persist_layout_header_preinterop& value)
{
	byteswap_inplace(value.tag_group_block_index);
	byteswap_inplace(value.string_data_size);
	byteswap_inplace(value.string_offset_count);
	byteswap_inplace(value.string_list_count);
	byteswap_inplace(value.custom_block_index_search_names_count);
	byteswap_inplace(value.data_definition_name_count);
	byteswap_inplace(value.array_definition_count);
	byteswap_inplace(value.field_type_count);
	byteswap_inplace(value.field_count);
	byteswap_inplace(value.struct_definition_count);
	byteswap_inplace(value.block_definition_count);
	byteswap_inplace(value.resource_definition_count);
}

template<> void byteswap_inplace(s_tag_persist_layout_header_v3& value)
{
	byteswap_inplace(static_cast<s_tag_persist_layout_header_preinterop&>(value));
	byteswap_inplace(value.interop_definition_count);
}
