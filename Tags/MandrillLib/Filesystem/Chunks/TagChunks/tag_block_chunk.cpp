#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_tag_block_chunk_header& value)
{
	byteswap_inplace(value.count);
	byteswap_inplace(value.is_simple_data_type);
}

c_tag_block_chunk::c_tag_block_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	block_structure_data_begin(),
	block_structure_data_position(),
	block_child_chunk_data_start(),
	block_child_chunk_data_position(),
	block_entry(),
	structure_entry(),
	structure_index(),
	tag_block_chunk_header(),
	block_data_size(),
	struct_size()
{

}

c_tag_block_chunk::~c_tag_block_chunk()
{

}

BCS_RESULT c_tag_block_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	ASSERT(userdata != nullptr);
	c_single_tag_file_reader& reader = *static_cast<c_single_tag_file_reader*>(userdata);

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, false)))
	{
		return rs;
	}

	const char* const chunk_data_start = get_chunk_data_start();
	const char* const chunk_data_end = get_chunk_data_end();

	const s_tag_block_chunk_header* src_tag_block_chunk_header = reinterpret_cast<const s_tag_block_chunk_header*>(chunk_data_start);
	tag_block_chunk_header = chunk_byteswap(*src_tag_block_chunk_header);

	

	t_tag_file_reader_metadata_entry& _metadata_entry = reader.metadata_stack._pop_unsafe();
	unsigned long current_block_index = _metadata_entry.id;
	e_tag_file_reader_metadata_entry_type entry_type = _metadata_entry.entry_type;
	ASSERT(entry_type == _tag_file_reader_metadata_entry_type_block);

	block_entry = &reader.layout_reader.get_block_definition_by_index(current_block_index);
	structure_entry = &reader.layout_reader.get_struct_definition_by_index(block_entry->structure_entry_index);
	structure_index = block_entry->structure_entry_index;
	struct_size = reader.layout_reader.get_structure_size_by_index(block_entry->structure_entry_index);
	block_data_size = struct_size * tag_block_chunk_header.count;

	block_structure_data_begin = next_contiguous_pointer(char, src_tag_block_chunk_header);
	block_structure_data_position = block_structure_data_begin;

	block_child_chunk_data_start = block_structure_data_begin + block_data_size;
	block_child_chunk_data_position = block_child_chunk_data_start;

	auto stack_start_size = reader.metadata_stack.stack_length;

	read_tag_block_structures(reader);

	bool has_children = block_child_chunk_data_position < chunk_data_end;
	if (has_children)
	{
		if (parse_children)
		{
			read_child_chunks(userdata, use_read_only, block_child_chunk_data_position);
			ASSERT(num_children == tag_block_chunk_header.count);
		}
	}

	auto stack_end_size = reader.metadata_stack.stack_length;
	ASSERT(stack_start_size == stack_end_size);

	// #TODO: delete this
	for (unsigned long block_index = 0; block_index < tag_block_chunk_header.count; block_index++)
	{
		c_tag_struct_chunk* tag_struct_chunk = nullptr;
		if (has_children)
		{
			tag_struct_chunk = dynamic_cast<c_tag_struct_chunk*>(children[block_index]);
			ASSERT(tag_struct_chunk != nullptr);
		}
		read_structure_data(reader, *structure_entry, block_structure_data_position, tag_struct_chunk);
		block_structure_data_position += struct_size;
	}

	return rs;
}

const char* c_tag_block_chunk::get_sturcutre_data_by_index(unsigned long index) const
{
	const char* result = block_structure_data_begin + struct_size * index;
	return result;
}

c_tag_struct_chunk* c_tag_block_chunk::get_sturcutre_chunk_by_index(unsigned long index) const
{
	c_tag_struct_chunk* result = nullptr;
	if (index < num_children)
	{
		result = dynamic_cast<c_tag_struct_chunk*>(children[index]);
	}
	return result;
}


void c_tag_block_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	if (string_debugger)
	{
		const char* block_name = string_debugger->get_string_by_string_character_index(block_entry->string_character_index);
		const char* struct_name = string_debugger->get_string_by_string_character_index(structure_entry->string_character_index);
		console_write_line_verbose("metadata:0x%08X\tcount:0x%08X\tis_simple_data_type:0x%08X\t%s", metadata, tag_block_chunk_header.count, tag_block_chunk_header.is_simple_data_type, block_name);
	}
	else
	{
		console_write_line_verbose("metadata:0x%08X\tcount:0x%08X\tis_simple_data_type:0x%08X\tstring_character_index:0x%08X", metadata, tag_block_chunk_header.count, tag_block_chunk_header.is_simple_data_type, block_entry->string_character_index);
	}

	// log_pad(); log_signature(); console_write_line_verbose("count:0x%08X\tis_simple_data_type:0x%08X\t%s", tag_block_chunk_header.count, tag_block_chunk_header.is_simple_data_type, block_name);
	// log_pad(); console_write_line_verbose("calculated structure size for %s", struct_name);
	// log_pad(); console_write_line_verbose("> 0x%08lX", struct_size);

	
}

void c_tag_block_chunk::read_tag_block_structures(c_single_tag_file_reader& reader) const
{
	t_tag_file_reader_metadata_stack metadata_stack;
	for (unsigned long block_index = 0; block_index < tag_block_chunk_header.count; block_index++)
	{
		read_structure_metadata(reader, *structure_entry, metadata_stack);
		reader.metadata_stack.copy_from(metadata_stack);
	}
}

void c_tag_block_chunk::read_structure_metadata(
	c_single_tag_file_reader& reader,
	s_tag_persist_struct_definition& structure_entry,
	t_tag_file_reader_metadata_stack& metadata_stack) const
{
	// #NOTE: If this is required, shove the structure_entry_index into the functiona and lookup via that
	// lookup up via entry/persistent_id is expensive
	// unsigned long expected_children = reader.layout_reader.get_structure_expected_children_by_entry(structure_entry);

	unsigned long metadata_child_index = 0;

	for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
	{
		s_tag_persist_field& field_entry = reader.layout_reader.get_field_by_index(field_index);
		s_tag_persist_field_type& field_type = reader.layout_reader.get_field_type_by_index(field_entry.field_type_index);
		blofeld::e_field blofeld_field_type = reader.layout_reader.get_blofeld_type_by_field_type_index(field_entry.field_type_index);

		if (field_type.has_child_chunk)
		{
			switch (blofeld_field_type)
			{
			case blofeld::_field_struct:
			{
				unsigned long structure_entry_index = field_entry.metadata;
				s_tag_persist_struct_definition& structure_entry = reader.layout_reader.get_struct_definition_by_index(structure_entry_index);
				read_structure_metadata(reader, structure_entry, metadata_stack);
			}
			break;
			case blofeld::_field_pageable_resource:
			{
				unsigned long resource_entry_index = field_entry.metadata;
				s_tag_persist_resource_definition& resource_entry = reader.layout_reader.get_resource_definition_by_index(resource_entry_index);
				// const char* resource_name = reader.layout_reader.get_string_by_string_character_index(resource_entry.string_character_index);
				t_tag_file_reader_metadata_entry& metadata_entry = metadata_stack._push();
				metadata_entry.id = field_entry.metadata;
				metadata_entry.entry_type = _tag_file_reader_metadata_entry_type_resource;
			}
			break;
			case blofeld::_field_block:
			{
				s_tag_persist_block_definition& block_entry = reader.layout_reader.get_block_definition_by_index(field_entry.metadata);
				// const char* block_name = reader.layout_reader.get_string_by_string_character_index(block_entry.string_character_index);
				t_tag_file_reader_metadata_entry& metadata_entry = metadata_stack._push();
				metadata_entry.id = field_entry.metadata;
				metadata_entry.entry_type = _tag_file_reader_metadata_entry_type_block;
			}
			break;
			}
		}
		else if (blofeld_field_type == blofeld::_field_terminator)
		{
			return;
		}
	}
}

#define write_pad()
void c_tag_block_chunk::read_structure_data(c_single_tag_file_reader& reader, s_tag_persist_struct_definition& structure_entry, const char* structure_data_pos, c_tag_struct_chunk* tag_struct_chunk)
{
	unsigned long metadata_child_index = 0;
	for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
	{
		s_tag_persist_field& field_entry = reader.layout_reader.get_field_by_index(field_index);
		s_tag_persist_field_type& field_type = reader.layout_reader.get_field_type_by_index(field_entry.field_type_index);

		unsigned long field_size = field_type.size;
		if (field_size == 0 || field_type.has_child_chunk)
		{
			blofeld::e_field blofeld_field_type = reader.layout_reader.get_blofeld_type_by_field_type_index(field_entry.field_type_index);

			switch (blofeld_field_type)
			{
			case blofeld::_field_block:
			{
				ASSERT(tag_struct_chunk != nullptr);
				c_tag_block_chunk* tag_block_chunk = tag_struct_chunk->get_child_unsafe<c_tag_block_chunk>(metadata_child_index++);
				ASSERT(tag_block_chunk != nullptr);

				s_tag_persist_block_definition& block_entry = reader.layout_reader.get_block_definition_by_index(field_entry.metadata);
				auto& structure_entry = reader.layout_reader.get_struct_definition_by_index(block_entry.structure_entry_index);
				//const char* block_name = reader.layout_reader.get_string_by_string_character_index(block_entry.string_character_index);
				//const char* struct_name = reader.layout_reader.get_string_by_string_character_index(structure_entry.string_character_index);

				s_tag_block block = chunk_byteswap(*reinterpret_cast<const s_tag_block*>(structure_data_pos));

				
			}
			break;
			case blofeld::_field_struct:
			{
				unsigned long structure_entry_index = field_entry.metadata;
				s_tag_persist_struct_definition& structure_entry = reader.layout_reader.get_struct_definition_by_index(structure_entry_index);
				//const char* struct_name = reader.layout_reader.get_string_by_string_character_index(structure_entry.string_character_index);
				unsigned long expected_children = reader.layout_reader.get_structure_expected_children_by_index(structure_entry_index);
				unsigned long structure_size = reader.layout_reader.get_structure_size_by_index(structure_entry_index);
				field_size = structure_size;

				ASSERT(tag_struct_chunk != nullptr);
				c_tag_struct_chunk* next_tag_struct_chunk = nullptr;
				unsigned long num_children;
				do
				{
					c_chunk* chunk = tag_struct_chunk->get_child_unsafe(metadata_child_index);
					next_tag_struct_chunk = dynamic_cast<c_tag_struct_chunk*>(chunk);
					ASSERT(next_tag_struct_chunk != nullptr);
					metadata_child_index++;
					num_children = next_tag_struct_chunk->num_children;
					if (num_children < expected_children && num_children == 0)
					{
						next_tag_struct_chunk = nullptr; // skip over to the next struct definition
						
					}
				} while (next_tag_struct_chunk == nullptr && tag_struct_chunk->get_child_unsafe(metadata_child_index));
				ASSERT(next_tag_struct_chunk != nullptr);
				ASSERT(num_children >= expected_children);

				read_structure_data(reader, structure_entry, structure_data_pos, next_tag_struct_chunk);
				
			}
			break;
			case blofeld::_field_array:
			{
				s_tag_persist_array_definition& array_entry = reader.layout_reader.get_array_definition_by_index(field_entry.metadata);
				unsigned long array_structure_size = reader.layout_reader.get_structure_size_by_index(array_entry.structure_entry_index);
				unsigned long array_size = array_structure_size * array_entry.count;
				field_size = array_size;
				
			}
			break;
			case blofeld::_field_tag_reference:
			{
				ASSERT(tag_struct_chunk != nullptr);
				c_tag_reference_chunk* tag_reference_chunk = tag_struct_chunk->get_child_unsafe<c_tag_reference_chunk>(metadata_child_index++);
				ASSERT(tag_reference_chunk != nullptr);
				
			}
			break;
			case blofeld::_field_old_string_id:
			case blofeld::_field_string_id:
			{
				ASSERT(tag_struct_chunk != nullptr);
				c_tag_string_id_chunk* tag_string_id_chunk = tag_struct_chunk->get_child_unsafe<c_tag_string_id_chunk>(metadata_child_index++);
				ASSERT(tag_string_id_chunk != nullptr);

				const s_tag_data* data = reinterpret_cast<const s_tag_data*>(structure_data_pos);
				
			}
			break;
			case blofeld::_field_data:
			{
				ASSERT(tag_struct_chunk != nullptr);
				c_tag_data_chunk* tag_data_chunk = tag_struct_chunk->get_child_unsafe<c_tag_data_chunk>(metadata_child_index++);
				ASSERT(tag_data_chunk != nullptr);

				s_tag_data data = chunk_byteswap(*reinterpret_cast<const s_tag_data*>(structure_data_pos));
				
			}
			break;
			case blofeld::_field_pageable_resource:
			{
				ASSERT(tag_struct_chunk != nullptr);
				c_chunk* resource_chunk = tag_struct_chunk->get_child_unsafe(metadata_child_index++);
				c_tag_resource_exploded_chunk* resource_exploded_chunk = dynamic_cast<c_tag_resource_exploded_chunk*>(resource_chunk);
				c_tag_resource_xsynced_chunk* resource_xsynced_chunk = dynamic_cast<c_tag_resource_xsynced_chunk*>(resource_chunk);
				c_tag_resource_null_chunk* resource_null_chunk = dynamic_cast<c_tag_resource_null_chunk*>(resource_chunk);
				ASSERT(resource_exploded_chunk != nullptr || resource_xsynced_chunk != nullptr || resource_null_chunk != nullptr);

				
			}
			break;
			case blofeld::_field_pad:
			{
				unsigned long pad_size = field_entry.metadata;
				field_size = pad_size;
			}
			break;
			case blofeld::_field_terminator:
				return;
			}
		}

		structure_data_pos += field_size;
	}
}
