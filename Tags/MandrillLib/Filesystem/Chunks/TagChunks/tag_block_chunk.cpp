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
	block_name(),
	struct_name(),
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

	debug_point;

	unsigned long current_block_index = reader.metadata_stack.top();
	reader.metadata_stack.pop();

	block_entry = &reader.layout_reader.get_block_definition_by_index(current_block_index);
	block_name = reader.layout_reader.get_string_by_string_character_index(block_entry->string_character_index);
	structure_entry = &reader.layout_reader.get_struct_definition_by_index(block_entry->structure_entry_index);
	struct_name = reader.layout_reader.get_string_by_string_character_index(structure_entry->string_character_index);
	struct_size = reader.layout_reader.calculate_structure_size_by_index(block_entry->structure_entry_index);
	block_data_size = struct_size * tag_block_chunk_header.count;

	block_structure_data_begin = next_contiguous_pointer<char>(src_tag_block_chunk_header);
	block_structure_data_position = block_structure_data_begin;

	block_child_chunk_data_start = block_structure_data_begin + block_data_size;
	block_child_chunk_data_position = block_child_chunk_data_start;

	log_pad(); log_signature(); console_write_line_verbose("count:0x%08X\tis_simple_data_type:0x%08X\t%s", tag_block_chunk_header.count, tag_block_chunk_header.is_simple_data_type, block_name);
	log_pad(); console_write_line_verbose("calculated structure size for %s", struct_name);
	log_pad(); console_write_line_verbose("> 0x%08lX", struct_size);

	auto stack_start_size = reader.metadata_stack.size();


	for (unsigned long block_index = 0; block_index < tag_block_chunk_header.count; block_index++)
	{
		read_structure_metadata(reader, *structure_entry);
	}

	bool has_children = block_child_chunk_data_position < chunk_data_end;
	if (has_children)
	{
		if (parse_children)
		{
			read_child_chunks(userdata, use_read_only, block_child_chunk_data_position);

			unsigned long child_count = get_num_children_unsafe();
			ASSERT(child_count == tag_block_chunk_header.count);
		}
	}

	auto stack_end_size = reader.metadata_stack.size();
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
	if (children != nullptr)
	{
		result = dynamic_cast<c_tag_struct_chunk*>(children[index]);
	}
	return result;
}


void c_tag_block_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("metadata:0x%08X\tcount:0x%08X\tis_simple_data_type:0x%08X\t%s", metadata, tag_block_chunk_header.count, tag_block_chunk_header.is_simple_data_type, block_name);

	debug_point;
}

void c_tag_block_chunk::read_structure_metadata(c_single_tag_file_reader& reader, s_tag_persist_struct_definition& structure_entry)
{
	std::stack<unsigned long> metadata_stack;
	read_structure_metadata_impl(reader, structure_entry, metadata_stack);

	/*if (verbose)*/ { log_pad(); console_write_verbose("> read_structure_metadata %u", static_cast<unsigned long>(metadata_stack.size())); }
	while (metadata_stack.size() > 0)
	{
		unsigned long metadata = metadata_stack.top();
		metadata_stack.pop();
		reader.metadata_stack.push(metadata);
	}
	/*if (verbose)*/ { console_write_line_verbose(" %u", static_cast<unsigned long>(reader.metadata_stack.size())); }
}

void c_tag_block_chunk::read_structure_metadata_impl(c_single_tag_file_reader& reader, s_tag_persist_struct_definition& structure_entry, std::stack<unsigned long>& metadata_stack) const
{
	for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
	{
		s_tag_persist_field& field_entry = reader.layout_reader.get_field_by_index(field_index);
		s_tag_persist_field_type& field_type = reader.layout_reader.get_field_type_by_index(field_entry.field_type_index);

		const char* type_string = reader.layout_reader.get_string_by_string_character_index(field_type.string_character_index);
		const char* name_string = reader.layout_reader.get_string_by_string_character_index(field_entry.string_character_index);

		blofeld::e_field blofeld_field_type;
		BCS_RESULT rs = blofeld::tag_field_type_to_field(type_string, blofeld_field_type);
		ASSERT(BCS_SUCCEEDED(rs));

		if (field_type.metadata)
		{
			switch (blofeld_field_type)
			{
			case blofeld::_field_block:
			{
				debug_point;
				s_tag_persist_block_definition& block_entry = reader.layout_reader.get_block_definition_by_index(field_entry.metadata);
				const char* block_name = reader.layout_reader.get_string_by_string_character_index(block_entry.string_character_index);
				/*if (verbose)*/ { log_pad(); console_write_line_verbose("\tpushing block %s", block_name); }
				metadata_stack.push(field_entry.metadata);
				debug_point;
			}
			break;
			case blofeld::_field_tag_reference:
			case blofeld::_field_string_id:
			case blofeld::_field_old_string_id:
			case blofeld::_field_data:
				break;
			case blofeld::_field_struct:
			{
				unsigned long structure_entry_index = field_entry.metadata;
				s_tag_persist_struct_definition& structure_entry = reader.layout_reader.get_struct_definition_by_index(structure_entry_index);
				read_structure_metadata_impl(reader, structure_entry, metadata_stack);
			}
			break;
			default:
				//throw;
				break;
			}
		}

		if (blofeld_field_type == blofeld::_field_terminator)
		{
			break;
		}
	}
}

#define write_pad()
#define verbose true
void c_tag_block_chunk::read_structure_data(c_single_tag_file_reader& reader, s_tag_persist_struct_definition& structure_entry, const char* structure_data_pos, c_tag_struct_chunk* tag_struct_chunk)
{
	const char* struct_name = reader.layout_reader.get_string_by_string_character_index(structure_entry.string_character_index);
	if (verbose) { write_pad(); console_write_line_verbose("STRUCT> %s", struct_name); }

	unsigned long metadata_child_index = 0;
	for (unsigned long field_index = structure_entry.fields_start_index;; field_index++)
	{
		s_tag_persist_field& field_entry = reader.layout_reader.get_field_by_index(field_index);
		s_tag_persist_field_type& field_type = reader.layout_reader.get_field_type_by_index(field_entry.field_type_index);

		const char* type_string = reader.layout_reader.get_string_by_string_character_index(field_type.string_character_index);
		const char* name_string = reader.layout_reader.get_string_by_string_character_index(field_entry.string_character_index);

		blofeld::e_field blofeld_field_type;
		BCS_RESULT rs = blofeld::tag_field_type_to_field(type_string, blofeld_field_type);
		ASSERT(BCS_SUCCEEDED(rs));


		unsigned long field_size = field_type.size;

		if (field_type.metadata)
		{
			ASSERT(tag_struct_chunk);
		}

		switch (blofeld_field_type)
		{
		case blofeld::_field_struct:
		{
			unsigned long structure_size = reader.layout_reader.calculate_structure_size_by_index(field_entry.metadata);
			field_size = structure_size;
		}
		break;
		case blofeld::_field_array:
		{
			s_tag_persist_array_definition& array_entry = reader.layout_reader.get_array_definition_by_index(field_entry.metadata);
			unsigned long array_structure_size = reader.layout_reader.calculate_structure_size_by_index(array_entry.structure_entry_index);
			unsigned long array_size = array_structure_size * array_entry.count;
			field_size = array_size;
		}
		break;
		case blofeld::_field_pad:
		{
			unsigned long pad_size = field_entry.metadata;
			field_size = pad_size;
		}
		break;
		}

		switch (blofeld_field_type)
		{
		case blofeld::_field_struct:
		{
			unsigned long structure_entry_index = field_entry.metadata;
			s_tag_persist_struct_definition& structure_entry = reader.layout_reader.get_struct_definition_by_index(structure_entry_index);
			const char* struct_name = reader.layout_reader.get_string_by_string_character_index(structure_entry.string_character_index);
			unsigned long structure_size = reader.layout_reader.calculate_structure_size_by_index(field_entry.metadata);
			unsigned long expected_children = reader.layout_reader.calculate_structure_expected_children(field_entry.metadata);

			ASSERT(tag_struct_chunk != nullptr);
			c_tag_struct_chunk* next_tag_struct_chunk = nullptr;
			unsigned long num_children;
			do
			{
				next_tag_struct_chunk = tag_struct_chunk->get_child_unsafe<c_tag_struct_chunk>(metadata_child_index++);
				ASSERT(next_tag_struct_chunk != nullptr);
				num_children = next_tag_struct_chunk->get_num_children_unsafe();
				if (num_children < expected_children && num_children == 0)
				{
					next_tag_struct_chunk = nullptr; // skip over to the next struct definition
					debug_point;
				}
			} while (next_tag_struct_chunk == nullptr && tag_struct_chunk->get_child_unsafe(metadata_child_index));
			ASSERT(next_tag_struct_chunk != nullptr);
			ASSERT(num_children >= expected_children);

			read_structure_data(reader, structure_entry, structure_data_pos, next_tag_struct_chunk);
			debug_point;

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
			if (verbose) { write_pad(); console_write_line_verbose("%s %s '%s'", type_string, name_string, tag_string_id_chunk->string); }
			debug_point;
		}
		break;
		case blofeld::_field_data:
		{
			ASSERT(tag_struct_chunk != nullptr);
			c_tag_data_chunk* tag_data_chunk = tag_struct_chunk->get_child_unsafe<c_tag_data_chunk>(metadata_child_index++);
			ASSERT(tag_data_chunk != nullptr);

			s_tag_data data = chunk_byteswap(*reinterpret_cast<const s_tag_data*>(structure_data_pos));
			if (verbose) { write_pad(); console_write_line_verbose("%s %s size:%li", type_string, name_string, data.size); }
			debug_point;
		}
		break;
		case blofeld::_field_pageable:
		{
			ASSERT(tag_struct_chunk != nullptr);
			c_tag_resource_xsynced_chunk* resource_xsynced_chunk = tag_struct_chunk->get_child_unsafe<c_tag_resource_xsynced_chunk>(metadata_child_index);
			c_tag_resource_null_chunk* resource_null_chunk = tag_struct_chunk->get_child_unsafe<c_tag_resource_null_chunk>(metadata_child_index);
			ASSERT(resource_xsynced_chunk != nullptr || resource_null_chunk != nullptr); 
			metadata_child_index++;


		}
		break;
		case blofeld::_field_block:
		{
			ASSERT(tag_struct_chunk != nullptr);
			c_tag_block_chunk* tag_block_chunk = tag_struct_chunk->get_child_unsafe<c_tag_block_chunk>(metadata_child_index++);
			ASSERT(tag_block_chunk != nullptr);

			s_tag_persist_block_definition& block_entry = reader.layout_reader.get_block_definition_by_index(field_entry.metadata);
			auto& structure_entry = reader.layout_reader.get_struct_definition_by_index(block_entry.structure_entry_index);
			const char* block_name = reader.layout_reader.get_string_by_string_character_index(block_entry.string_character_index);
			const char* struct_name = reader.layout_reader.get_string_by_string_character_index(structure_entry.string_character_index);

			s_tag_block block = chunk_byteswap(*reinterpret_cast<const s_tag_block*>(structure_data_pos));
			if (verbose) { write_pad(); console_write_line_verbose("%s %s count:%li", type_string, name_string, block.count); }

			debug_point;

			debug_point;

			break;
		}
		case blofeld::_field_char_integer:
		case blofeld::_field_char_enum:
		{
			long number = chunk_byteswap(*reinterpret_cast<const char*>(structure_data_pos));
			
			if (verbose) { write_pad(); console_write_line_verbose("%s %s %li", type_string, name_string, number); }
			debug_point;
			break;
		}
		case blofeld::_field_short_integer:
		case blofeld::_field_word_flags:
		case blofeld::_field_enum:
		{
			long number = chunk_byteswap(*reinterpret_cast<const short*>(structure_data_pos));

			if (verbose) { write_pad(); console_write_line_verbose("%s %s %li", type_string, name_string, number); }
			debug_point;
			break;
		}
		case blofeld::_field_long_integer:
		{
			long number = chunk_byteswap(*reinterpret_cast<const long*>(structure_data_pos));

			if (verbose) { write_pad(); console_write_line_verbose("%s %s %li", type_string, name_string, number); }
			debug_point;
			break;
		}
		case blofeld::_field_real:
		case blofeld::_field_real_fraction:
		{
			real _real = chunk_byteswap(*reinterpret_cast<const real*>(structure_data_pos));

			if (verbose) { write_pad(); console_write_line_verbose("%s %s %f", type_string, name_string, _real); }
			debug_point;
			break;
		}
		case blofeld::_field_real_point_3d:
		{
			real_vector3d _real3 = chunk_byteswap(*reinterpret_cast<const real_vector3d*>(structure_data_pos));
			if (verbose) { write_pad(); console_write_line_verbose("%s %s %f %f %f", type_string, name_string, _real3.i, _real3.j, _real3.k); }
			debug_point;
			break;
		}
		case blofeld::_field_real_plane_3d:
		{
			real_vector4d _real4 = chunk_byteswap(*reinterpret_cast<const real_vector4d*>(structure_data_pos));
			if (verbose) { write_pad(); console_write_line_verbose("%s %s %f %f %f %f", type_string, name_string, _real4.i, _real4.j, _real4.k, _real4.w); }
			debug_point;
			break;
		}
		case blofeld::_field_custom:
		case blofeld::_field_pad:
		case blofeld::_field_terminator:
			break;
		//default: FATAL_ERROR("Unhandled field");
		}

		structure_data_pos += field_size;

		if (blofeld_field_type == blofeld::_field_terminator)
		{
			goto end;
		}
	}
end:;
	debug_point;
}
