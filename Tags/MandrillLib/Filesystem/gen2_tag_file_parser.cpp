#include <mandrilllib-private-pch.h>

struct s_field_set_header_v1
{
	blofeld::e_field_id signature;
	unsigned short struct_version;
	short element_count;
	int32_t element_size;
};

template<> void byteswap_inplace(s_field_set_header_v1& value)
{
	byteswap_inplace(*reinterpret_cast<__underlying_type(blofeld::e_field_id)*>(&value.signature));
	byteswap_inplace(value.struct_version);
	byteswap_inplace(value.element_count);
	byteswap_inplace(value.element_size);
}

struct s_field_set_header_v2
{
	blofeld::e_field_id signature;
	uint32_t struct_version;
	int32_t element_count;
	int32_t element_size;

	s_field_set_header_v2& operator=(s_field_set_header_v1 const& field_set_header_v1)
	{
		signature = field_set_header_v1.signature;
		struct_version = field_set_header_v1.struct_version;
		element_count = field_set_header_v1.element_count;
		element_size = field_set_header_v1.element_size;
		return *this;
	}
};

template<> void byteswap_inplace(s_field_set_header_v2& value)
{
	byteswap_inplace(*reinterpret_cast<__underlying_type(blofeld::e_field_id)*>(&value.signature));
	byteswap_inplace(value.struct_version);
	byteswap_inplace(value.element_count);
	byteswap_inplace(value.element_size);
}

int32_t indent = -1;
#define indent_write(string, ...) if(BCS_SUCCEEDED(command_line_has_argument_internal("verbose"))) { for(int32_t i=0;i<indent;i++) { console_write("|  ");  } console_write_line(string, __VA_ARGS__); } (void)(0)
//#define indent_write(...) 

BCS_RESULT c_gen2_tag_file_parse_context::calculate_tag_struct_definition_size2(
	const blofeld::s_tag_struct_definition& tag_struct_definition,
	const char* const struct_data_start,
	const char* struct_data_expected_end,
	const char* const external_data_start,
	uint32_t& tag_struct_size,
	uint32_t& tag_struct_external_size,
	uint32_t tag_struct_version) const
{
	uint32_t tag_struct_definition_size = 0;
	const char* struct_data_end = struct_data_start;
	const char* external_data_end = external_data_start;
	BCS_RESULT rs = calculate_tag_struct_definition_size_iterator(
		tag_struct_definition,
		struct_data_end,
		struct_data_expected_end,
		external_data_end,
		tag_struct_version);
	tag_struct_size = struct_data_end - struct_data_start;
	tag_struct_external_size = external_data_end - external_data_start;

	indent_write("END>");

	return rs;
}

BCS_RESULT c_gen2_tag_file_parse_context::calculate_tag_struct_definition_size_iterator(
	const blofeld::s_tag_struct_definition& tag_struct_definition,
	const char*& struct_data_position,
	const char* struct_data_expected_end,
	const char*& external_data_position,
	uint32_t tag_struct_version) const
{
	indent++;
	indent_write("STRUCT> 0x%X 0x%X %s [version:%u]", (int)(struct_data_position - tag_file_structure_data_start), (int)(external_data_position - tag_file_structure_data_start), tag_struct_definition.name, tag_struct_version);

#define peek_read(t_type) \
	byteswap(*reinterpret_cast<const t_type*>(struct_data_position));
#define advance_read(t_type) \
	peek_read(t_type); \
	struct_data_position += sizeof(t_type)
#define peek_read_external(t_type) \
	byteswap(*reinterpret_cast<const t_type*>(external_data_position));
#define advance_read_external(t_type) \
	peek_read_external(t_type); \
	external_data_position += sizeof(t_type)

	BCS_RESULT rs = BCS_S_OK;

	for (const blofeld::s_tag_field* tag_field_iterator = tag_struct_definition.fields; tag_field_iterator->field_type != blofeld::_field_terminator; tag_field_iterator++)
	{
		const blofeld::s_tag_field& tag_field = tag_field_iterator_versioning(tag_struct_definition, tag_field_iterator, engine_platform_build, tag_struct_version);


		s_field_set_header_v2 field_set_header = {};
		switch (tag_field.field_type)
		{
		case blofeld::_field_struct:
		{
			const char* struct_data_position2 = struct_data_position;
			const char* external_data_position2 = external_data_position;
			if (tag_file_version == _tag_file_version1)
			{
				field_set_header = advance_read_external(s_field_set_header_v1);
			}
			else
			{
				field_set_header = advance_read_external(s_field_set_header_v2);
			}
			ASSERT(field_set_header.signature == tag_field.id);
			ASSERT(field_set_header.element_count == 1);
		}
		break;
		}

		if (struct_data_expected_end != nullptr && struct_data_position >= struct_data_expected_end)
		{
			ASSERT(struct_data_position == struct_data_expected_end); // shouldn't read past the end
			continue;
		}

		switch (tag_field.field_type)
		{
		case blofeld::_field_array:
		{
			indent++;
			indent_write("ARRAYY> 0x%X 0x%X %s", (int)(struct_data_position - tag_file_structure_data_start), (int)(external_data_position - tag_file_structure_data_start), tag_field.array_definition->name);

			uint32_t array_element_count = tag_field.array_definition->count(engine_platform_build);
			for (uint32_t array_index = 0; array_index < array_element_count; array_index++)
			{
				if (BCS_FAILED(rs = calculate_tag_struct_definition_size_iterator(
					tag_field.array_definition->struct_definition,
					struct_data_position,
					nullptr,
					external_data_position,
					tag_field_version_max)))
				{
					return rs;
				}
			}

			debug_point;

			indent--;
		}
		break;
		case blofeld::_field_struct:
		{


			const char* const field_struct_data_start = struct_data_position;
			const char* const field_struct_data_end = field_struct_data_start + field_set_header.element_size;

			static int x = 0;
			x++;
			if (x == 11)
			{
				debug_point;
			}

			if (BCS_FAILED(rs = calculate_tag_struct_definition_size_iterator(
				*tag_field.struct_definition,
				struct_data_position,
				field_struct_data_end,
				external_data_position,
				field_set_header.struct_version)))
			{
				return rs;
			}
			uint32_t tag_struct_size = struct_data_position - field_struct_data_start;
			ASSERT(field_set_header.element_size == tag_struct_size);
			debug_point;
		}
		break;
		case blofeld::_field_block:
		{
			indent++;
			s_tag_block tag_block_peek = peek_read(s_tag_block);
			auto pos = struct_data_position;
			indent_write("BLOCKK> 0x%X 0x%X %s count:%i", (int)(struct_data_position - tag_file_structure_data_start), (int)(external_data_position - tag_file_structure_data_start), tag_field.block_definition->name, tag_block_peek.count);

			s_tag_block tag_block = advance_read(s_tag_block);
			if (tag_block.count > 0)
			{
				if (tag_file_version == _tag_file_version1)
				{
					field_set_header = advance_read_external(s_field_set_header_v2);
				}
				else
				{
					field_set_header = advance_read_external(s_field_set_header_v2);
				}

				// validation
				ASSERT(field_set_header.signature == k_tag_block_field_set_definition);
				ASSERT(tag_block.count == field_set_header.element_count);

				const blofeld::s_tag_struct_definition& tag_struct_definition = tag_field.block_definition->struct_definition;

				const char* const block_data_start = external_data_position;
				const char* const block_data_end = block_data_start + field_set_header.element_size * field_set_header.element_count;

				const char* block_data_position = block_data_start;
				external_data_position = block_data_end;

				static int x = 0;
				static int y = 0;

				x++;
				if (x == 8)
				{
					debug_point;
				}

				int a = x;
				int b = y;

				if (a == 1 && b == 0)
				{
					debug_point;
				}
				for (uint32_t block_index = 0; block_index < field_set_header.element_count; block_index++)
				{
					const char* const block_entry_data_start = block_data_start + field_set_header.element_size * block_index;
					const char* const block_entry_data_end = block_entry_data_start + field_set_header.element_size;
					if (BCS_FAILED(rs = calculate_tag_struct_definition_size_iterator(
						tag_struct_definition,
						block_data_position,
						block_entry_data_end,
						external_data_position,
						field_set_header.struct_version)))
					{
						return rs;
					}
					int size = block_data_position - block_entry_data_start;
					ASSERT(size <= field_set_header.element_size); // #TODO: Why does this happen?
					if (size < field_set_header.element_size)
					{
						debug_point;
					}
					block_data_position = block_entry_data_end; // #TODO: Why does this happen?
					debug_point;
				}

				y++;
				if (y == 8)
				{
					debug_point;
				}

				int bytes_expected = field_set_header.element_size * field_set_header.element_count;
				int bytes_read = block_data_position - block_data_start;
				int bytes_remaining = block_data_end - block_data_position;
				if (block_data_position != block_data_end)
				{
					console_write_line("Unexpected block end");
					return BCS_E_FAIL;
				}
				ASSERT(block_data_position == block_data_end);
			}
			indent--;
		}
		break;
		case blofeld::_field_tag_reference:
		{
			s_tag_reference tag_reference = advance_read(s_tag_reference);
			if (tag_reference.name_length > 0)
			{
				external_data_position += tag_reference.name_length + 1;
			}
			debug_point;
		}
		break;
		case blofeld::_field_data:
		{
			s_tag_data tag_data = advance_read(s_tag_data);
			if (tag_data.size > 0)
			{
				external_data_position += tag_data.size;
			}
		}
		break;
		case blofeld::_field_old_string_id:
		{
			if (tag_field.field_type == blofeld::_field_old_string_id && (tag_file_version <= _tag_file_version2))
			{
				::c_static_string<32> string = advance_read(::c_static_string<32>);

				debug_point;
				break;
			}
		}
		// break; fallthrough
		case blofeld::_field_string_id:
		{
			string_id _string_id = advance_read(string_id);

			uint32_t string_id_length = _string_id >> 24;
			if (string_id_length > 0)
			{
				external_data_position += string_id_length;
			}
			debug_point;
		}
		break;
		case blofeld::_field_vertex_buffer:
		{
			s_tag_d3d_vertex_buffer d3d_vertex_buffer = advance_read(s_tag_d3d_vertex_buffer);

			//uint32_t checksum = 0;
			//for (auto x : d3d_vertex_buffer.data) checksum += (unsigned long)x;
			//ASSERT(checksum == 0); // #TODO: Map this out

			debug_point;
		}
		break;
		case blofeld::_field_string:
		case blofeld::_field_long_string:
		case blofeld::_field_char_integer:
		case blofeld::_field_short_integer:
		case blofeld::_field_long_integer:
		case blofeld::_field_int64_integer:
		case blofeld::_field_angle:
		case blofeld::_field_tag:
		case blofeld::_field_char_enum:
		case blofeld::_field_short_enum:
		case blofeld::_field_long_enum:
		case blofeld::_field_long_flags:
		case blofeld::_field_word_flags:
		case blofeld::_field_byte_flags:
		case blofeld::_field_point_2d:
		case blofeld::_field_rectangle_2d:
		case blofeld::_field_rgb_color:
		case blofeld::_field_argb_color:
		case blofeld::_field_real:
		case blofeld::_field_real_fraction:
		case blofeld::_field_real_point_2d:
		case blofeld::_field_real_point_3d:
		case blofeld::_field_real_vector_2d:
		case blofeld::_field_real_vector_3d:
		case blofeld::_field_real_quaternion:
		case blofeld::_field_real_euler_angles_2d:
		case blofeld::_field_real_euler_angles_3d:
		case blofeld::_field_real_plane_2d:
		case blofeld::_field_real_plane_3d:
		case blofeld::_field_real_rgb_color:
		case blofeld::_field_real_argb_color:
		case blofeld::_field_real_hsv_color:
		case blofeld::_field_real_ahsv_color:
		case blofeld::_field_short_integer_bounds:
		case blofeld::_field_angle_bounds:
		case blofeld::_field_real_bounds:
		case blofeld::_field_real_fraction_bounds:
		case blofeld::_field_long_block_flags:
		case blofeld::_field_word_block_flags:
		case blofeld::_field_byte_block_flags:
		case blofeld::_field_char_block_index:
		case blofeld::_field_char_block_index_custom_search:
		case blofeld::_field_short_block_index:
		case blofeld::_field_short_block_index_custom_search:
		case blofeld::_field_long_block_index:
		case blofeld::_field_long_block_index_custom_search:
		{
			uint32_t field_size;
			if (BCS_FAILED(rs = blofeld::get_blofeld_tag_file_field_size(tag_field.field_type, engine_platform_build, field_size)))
			{
				return rs;
			}

			struct_data_position += field_size;
			debug_point;
		}
		break;
		case blofeld::_field_useless_pad:
		{
			if (tag_file_version <= _tag_file_version3)
			{
				struct_data_position += tag_field.padding;
			}
		}
		break;
		case blofeld::_field_pad:
		{
			if (tag_field.id != blofeld::_field_id_pd64)
			{
				struct_data_position += tag_field.padding;
			}
		}
		break;
		case blofeld::_field_skip:
		{
			struct_data_position += tag_field.length;
		}
		break;
		case blofeld::_field_pointer:
		{
			struct_data_position += 4;
		}
		break;
		case blofeld::_field_custom:
		case blofeld::_field_explanation:
			break;
		default: FATAL_ERROR("Unsupported field type");
		}
	}

	indent--;
	return rs;
#undef peek_read
#undef advance_read
#undef peek_read_external
#undef advance_read_external
}

static bool tag_struct_definition_has_external_data(
	const blofeld::s_tag_struct_definition& struct_definition,
	s_engine_platform_build engine_platform_build,
	uint32_t struct_version)
{
	BCS_RESULT rs = BCS_S_OK;

	for (const blofeld::s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != blofeld::_field_terminator; tag_field_iterator++)
	{
		const blofeld::s_tag_field& tag_field = tag_field_iterator_versioning(struct_definition, tag_field_iterator, engine_platform_build, struct_version);

		uint32_t field_size;
		switch (tag_field.field_type)
		{
		case blofeld::_field_tag_reference:
		case blofeld::_field_block:
		case blofeld::_field_data:
			return true;
		}
	}
	return false;
}

#include <numeric>
#include <bit>

c_gen2_tag_file_parse_context::c_gen2_tag_file_parse_context(
	const void* _tag_file_data,
	uint64_t _tag_file_data_size,
	s_engine_platform_build _engine_platform_build) :
	is_big_endian(),
	is_little_endian(),
	tag_file_version(),
	tag_file_data_start(),
	tag_file_structure_data_start(),
	tag_file_data_end(),
	engine_platform_build(),
	tag_file_header()
{
	const s_single_tag_file_header_v1* tag_file_header_v1_pointer = static_cast<const s_single_tag_file_header_v1*>(_tag_file_data);

	bool is_known_version = false;
#define identify_version(_signature, _target_signature, _tag_file_version) \
	if (_signature == _target_signature) \
	{ \
		ASSERT(is_known_version == false); \
		tag_file_version = _tag_file_version; \
		is_big_endian = false; \
		is_little_endian = true; \
		is_known_version = true; \
	} \
	if (_signature == ::byteswap<__underlying_type(decltype(_target_signature))>(_target_signature)) \
	{ \
		ASSERT(is_known_version == false); \
		tag_file_version = _tag_file_version; \
		is_big_endian = true; \
		is_little_endian = false; \
		is_known_version = true; \
	}

	identify_version(tag_file_header_v1_pointer->signature, _tag_file_version_signature0, _tag_file_version0);
	identify_version(tag_file_header_v1_pointer->signature, _tag_file_version_signature1, _tag_file_version1);
	identify_version(tag_file_header_v1_pointer->signature, _tag_file_version_signature2, _tag_file_version2);
	identify_version(tag_file_header_v1_pointer->signature, _tag_file_version_signature3, _tag_file_version3);
	identify_version(tag_file_header_v1_pointer->signature, _tag_file_version_signature4, _tag_file_version4);

#undef identify_version

	ASSERT(is_known_version);

	tag_file_header = byteswap(*tag_file_header_v1_pointer);

	ASSERT(is_big_endian || is_little_endian); // valid signature
	ASSERT(is_big_endian != is_little_endian); // valid signature

	tag_file_data_start = static_cast<const char*>(_tag_file_data);
	tag_file_structure_data_start = tag_file_data_start + tag_file_header.data_offset;
	tag_file_data_end = tag_file_data_start + _tag_file_data_size;
	engine_platform_build = _engine_platform_build;

	if (!is_little_endian && !is_big_endian)
	{
		throw BCS_E_FAIL;
	}
}

BCS_RESULT c_gen2_tag_file_parse_context::traverse_tag_block(const char*& global_data_position, h_block& block) const
{
#define advance_read(t_type) \
	byteswap(*reinterpret_cast<const t_type*>(global_data_position)); \
	global_data_position += sizeof(t_type)

	BCS_RESULT rs = BCS_S_OK;

	s_field_set_header_v2 field_set_header;

	if (tag_file_version == _tag_file_version1)
	{
		s_field_set_header_v1 field_set_header_v1 = advance_read(s_field_set_header_v1);
		field_set_header.signature = field_set_header_v1.signature;
		field_set_header.struct_version = field_set_header_v1.struct_version;
		field_set_header.element_count = field_set_header_v1.element_count;
		field_set_header.element_size = field_set_header_v1.element_size;
	}
	else
	{
		field_set_header = advance_read(s_field_set_header_v2);
	}
	ASSERT(field_set_header.signature == k_tag_block_field_set_definition);

	const blofeld::s_tag_struct_definition& tag_struct_definition = block.get_tag_struct_definition();


	const char* const block_data_start = global_data_position;
	const char* const block_data_end = block_data_start + field_set_header.element_count * field_set_header.element_size;

	const char* block_data_position = block_data_start;
	global_data_position = block_data_end;

	block.resize(field_set_header.element_count);
	for (uint32_t block_index = 0; block_index < field_set_header.element_count; block_index++)
	{
		h_prototype& block_entry = block.get(block_index);

		const char* const block_entry_data_start = block_data_start + field_set_header.element_size * block_index;
		const char* const block_entry_data_end = block_entry_data_start + field_set_header.element_size;

		uint32_t tag_struct_size2;
		uint32_t tag_struct_ext_size2;
		if (BCS_FAILED(rs = calculate_tag_struct_definition_size2(
			tag_struct_definition,
			block_data_position,
			block_entry_data_end,
			global_data_position,
			tag_struct_size2,
			tag_struct_ext_size2,
			field_set_header.struct_version)))
		{
			return rs;
		}
		ASSERT(tag_struct_size2 <= field_set_header.element_size);

		if (BCS_FAILED(rs = traverse_tag_struct(block_data_position, block_entry_data_end, global_data_position, block_entry, field_set_header.struct_version)))
		{
			return rs;
		}

		block_data_position = block_entry_data_end; // #TODO: Why can the structure size be smaller? Is that correct?
	}
	ASSERT(block_data_position == block_data_end);

	return rs;
#undef advance_read
}

BCS_RESULT c_gen2_tag_file_parse_context::traverse_tag_struct(
	const char*& struct_data_position,
	const char* struct_data_expected_end,
	const char*& external_data_position,
	h_prototype& prototype,
	uint32_t struct_version) const
{
	uint32_t prototype_version = prototype.get_version();
	if (struct_version != prototype_version)
	{
		//console_write_line("Missing structure upgrade for %s from %lu -> %lu", prototype.get_blofeld_struct_definition().name, struct_version, prototype_version);
		//return BCS_E_UNSUPPORTED;
	}

#define peek_read(t_type) \
	byteswap(*reinterpret_cast<const t_type*>(struct_data_position));
#define advance_read(t_type) \
	peek_read(t_type); \
	struct_data_position += sizeof(t_type)
#define peek_read_external(t_type) \
	byteswap(*reinterpret_cast<const t_type*>(external_data_position));
#define advance_read_external(t_type) \
	peek_read_external(t_type); \
	external_data_position += sizeof(t_type)

	BCS_RESULT rs = BCS_S_OK;

	const blofeld::s_tag_struct_definition& tag_struct_definition = prototype.get_blofeld_struct_definition();
	for (const blofeld::s_tag_field* tag_field_iterator = tag_struct_definition.fields; tag_field_iterator->field_type != blofeld::_field_terminator; tag_field_iterator++)
	{
		const blofeld::s_tag_field& tag_field = tag_field_iterator_versioning(tag_struct_definition, tag_field_iterator, engine_platform_build, struct_version);

		s_field_set_header_v2 field_set_header = {};
		switch (tag_field.field_type)
		{
		case blofeld::_field_struct:
		{
			if (tag_file_version == _tag_file_version1)
			{
				field_set_header = advance_read_external(s_field_set_header_v1);
			}
			else
			{
				field_set_header = advance_read_external(s_field_set_header_v2);
			}
			ASSERT(field_set_header.signature == tag_field.id);
			ASSERT(field_set_header.element_count == 1);
		}
		break;
		}

		if (struct_data_expected_end != nullptr && struct_data_position >= struct_data_expected_end)
		{
			ASSERT(struct_data_position == struct_data_expected_end); // shouldn't read past the end
			continue;
		}

		switch (tag_field.field_type)
		{
		case blofeld::_field_array:
		{
			h_enumerable* tag_field_enumerable = prototype.get_field_data<h_enumerable>(tag_field);
			ASSERT(tag_field_enumerable != nullptr);

			uint32_t array_element_count = tag_field.array_definition->count(engine_platform_build);
			for (uint32_t array_index = 0; array_index < array_element_count; array_index++)
			{
				h_prototype& prototype = tag_field_enumerable->get(array_index);
				if (BCS_FAILED(rs = traverse_tag_struct(struct_data_position, nullptr, external_data_position, prototype, tag_field_version_max)))
				{
					return rs;
				}
			}

			debug_point;
		}
		break;
		case blofeld::_field_struct:
		{
			h_prototype* tag_field_prototype = prototype.get_field_data<h_prototype>(tag_field);
			ASSERT(tag_field_prototype != nullptr);

			const char* const field_struct_data_start = struct_data_position;
			const char* const field_struct_data_end = field_struct_data_start + field_set_header.element_size;

			uint32_t tag_struct_size2;
			uint32_t tag_struct_ext_size2;
			if (BCS_FAILED(rs = calculate_tag_struct_definition_size2(
				*tag_field.struct_definition,
				struct_data_position,
				field_struct_data_end,
				external_data_position,
				tag_struct_size2,
				tag_struct_ext_size2,
				field_set_header.struct_version)))
			{
				return rs;
			}

			ASSERT(field_set_header.signature == tag_field.id); // #TODO: Macro?
			ASSERT(field_set_header.element_size == tag_struct_size2); // #TODO: Macro?

			if (BCS_FAILED(rs = traverse_tag_struct(struct_data_position, field_struct_data_end, external_data_position, *tag_field_prototype, field_set_header.struct_version)))
			{
				return rs;
			}
			debug_point;
		}
		break;
		case blofeld::_field_block:
		{
			h_block* tag_field_block_data = prototype.get_field_data<h_block>(tag_field);
			ASSERT(tag_field_block_data != nullptr);
			s_tag_block tag_block = advance_read(s_tag_block);

			if (tag_block.count > 0)
			{
				// validation
				s_field_set_header_v2 field_set_header;
				if (tag_file_version == _tag_file_version1)
				{
					s_field_set_header_v1 field_set_header_v1 = peek_read_external(s_field_set_header_v1);
					field_set_header.signature = field_set_header_v1.signature;
					field_set_header.struct_version = field_set_header_v1.struct_version;
					field_set_header.element_count = field_set_header_v1.element_count;
					field_set_header.element_size = field_set_header_v1.element_size;
				}
				else
				{
					field_set_header = peek_read_external(s_field_set_header_v2);
				}

				ASSERT(field_set_header.signature == k_tag_block_field_set_definition); // #TODO: Macro?
				ASSERT(tag_block.count == field_set_header.element_count);

				traverse_tag_block(external_data_position, *tag_field_block_data);
			}
		}
		break;
		case blofeld::_field_tag_reference:
		{
			h_tag_reference* tag_field_tag_reference = prototype.get_field_data<h_tag_reference>(tag_field);
			ASSERT(tag_field_tag_reference != nullptr);
			s_tag_reference tag_reference = advance_read(s_tag_reference);

			const char* unqualified_path = "";
			if (tag_reference.name_length > 0)
			{
				unqualified_path = external_data_position;
				external_data_position += tag_reference.name_length + 1;
			}
			tag_field_tag_reference->set_unqualified_file_path_without_extension(tag_reference.group_tag, unqualified_path);

			debug_point;
		}
		break;
		case blofeld::_field_data:
		{
			h_data* tag_field_data = prototype.get_field_data<h_data>(tag_field);
			ASSERT(tag_field_data != nullptr);
			s_tag_data tag_data = advance_read(s_tag_data);

			if (tag_data.size > 0)
			{
				tag_field_data->resize(tag_data.size);
				memcpy(tag_field_data->data(), external_data_position, tag_data.size);
				external_data_position += tag_data.size;
			}
		}
		break;
		case blofeld::_field_old_string_id:
		{
			if (tag_field.field_type == blofeld::_field_old_string_id && (tag_file_version <= _tag_file_version2))
			{
				h_string_id* tag_field_string_id = prototype.get_field_data<h_string_id>(tag_field);
				ASSERT(tag_field_string_id != nullptr);
				::c_static_string<32> string = advance_read(::c_static_string<32>);

				const char* cstring = string.get_string();
				tag_field_string_id->set_string(cstring);

				debug_point;
				break;
			}
		}
		// break; fallthrough
		case blofeld::_field_string_id:
		{
			h_string_id* tag_field_string_id = prototype.get_field_data<h_string_id>(tag_field);
			ASSERT(tag_field_string_id != nullptr);
			string_id _string_id = advance_read(string_id);

			uint32_t string_id_length = _string_id >> 24;
			if (string_id_length > 0)
			{
				tag_field_string_id->set_string(external_data_position, external_data_position + string_id_length);
				external_data_position += string_id_length;
			}

			debug_point;
		}
		break;
		case blofeld::_field_vertex_buffer:
		{
			s_tag_d3d_vertex_buffer d3d_vertex_buffer = advance_read(s_tag_d3d_vertex_buffer);

			if (d3d_vertex_buffer.type || d3d_vertex_buffer.stride || d3d_vertex_buffer.count)
			{
				debug_point;
			}

			if (d3d_vertex_buffer.count)
			{
				debug_point;
			}

			debug_point;
		}
		break;
		case blofeld::_field_string:
		case blofeld::_field_long_string:
		case blofeld::_field_char_integer:
		case blofeld::_field_short_integer:
		case blofeld::_field_long_integer:
		case blofeld::_field_int64_integer:
		case blofeld::_field_angle:
		case blofeld::_field_tag:
		case blofeld::_field_char_enum:
		case blofeld::_field_short_enum:
		case blofeld::_field_long_enum:
		case blofeld::_field_long_flags:
		case blofeld::_field_word_flags:
		case blofeld::_field_byte_flags:
		case blofeld::_field_point_2d:
		case blofeld::_field_rectangle_2d:
		case blofeld::_field_rgb_color:
		case blofeld::_field_argb_color:
		case blofeld::_field_real:
		case blofeld::_field_real_fraction:
		case blofeld::_field_real_point_2d:
		case blofeld::_field_real_point_3d:
		case blofeld::_field_real_vector_2d:
		case blofeld::_field_real_vector_3d:
		case blofeld::_field_real_quaternion:
		case blofeld::_field_real_euler_angles_2d:
		case blofeld::_field_real_euler_angles_3d:
		case blofeld::_field_real_plane_2d:
		case blofeld::_field_real_plane_3d:
		case blofeld::_field_real_rgb_color:
		case blofeld::_field_real_argb_color:
		case blofeld::_field_real_hsv_color:
		case blofeld::_field_real_ahsv_color:
		case blofeld::_field_short_integer_bounds:
		case blofeld::_field_angle_bounds:
		case blofeld::_field_real_bounds:
		case blofeld::_field_real_fraction_bounds:
		case blofeld::_field_long_block_flags:
		case blofeld::_field_word_block_flags:
		case blofeld::_field_byte_block_flags:
		case blofeld::_field_char_block_index:
		case blofeld::_field_char_block_index_custom_search:
		case blofeld::_field_short_block_index:
		case blofeld::_field_short_block_index_custom_search:
		case blofeld::_field_long_block_index:
		case blofeld::_field_long_block_index_custom_search:
		{
			uint32_t field_size;
			if (BCS_FAILED(rs = blofeld::get_blofeld_tag_file_field_size(tag_field.field_type, engine_platform_build, field_size)))
			{
				return rs;
			}

			void* high_level_field_data = prototype.get_field_data_unsafe(tag_field);

			memcpy(high_level_field_data, struct_data_position, field_size);
			if (is_big_endian)
			{
				blofeld::byteswap_field_data_inplace(tag_field.field_type, high_level_field_data, engine_platform_build);
			}

			struct_data_position += field_size;

			debug_point;
		}
		break;
		case blofeld::_field_useless_pad:
		{
			if (tag_file_version <= _tag_file_version3)
			{
				struct_data_position += tag_field.padding;
			}
		}
		break;
		case blofeld::_field_pad:
		{
			if (tag_field.id != blofeld::_field_id_pd64)
			{
				struct_data_position += tag_field.padding;
			}
		}
		break;
		case blofeld::_field_skip:
		{
			struct_data_position += tag_field.length;
		}
		break;
		case blofeld::_field_pointer:
		{
			struct_data_position += 4;
		}
		break;
		case blofeld::_field_custom:
		case blofeld::_field_explanation:
			break;
		default: FATAL_ERROR("Unsupported field type");
		}
	}

	return rs;
#undef peek_read
#undef advance_read
#undef peek_read_external
#undef advance_read_external
}

BCS_RESULT c_gen2_tag_file_parse_context::traverse_tag_group(h_tag& prototype) const
{
	BCS_RESULT rs = BCS_S_OK;

	if (tag_file_header.group_version != prototype.get_version())
	{
		console_write_line("Skipping gen2 tag file version upgrade");
		debug_point; // #TODO: version upgrading
		return BCS_S_OK;
	}

	const char* global_data_position = tag_file_structure_data_start;

#define advance_read(t_type) \
	byteswap(*reinterpret_cast<const t_type*>(global_data_position)); \
	global_data_position += sizeof(t_type)

	s_field_set_header_v2 field_set_header;
	if (tag_file_version == _tag_file_version1)
	{
		s_field_set_header_v1 field_set_header_v1 = advance_read(s_field_set_header_v1);
		field_set_header.signature = field_set_header_v1.signature;
		field_set_header.struct_version = field_set_header_v1.struct_version;
		field_set_header.element_count = field_set_header_v1.element_count;
		field_set_header.element_size = field_set_header_v1.element_size;
	}
	else
	{
		field_set_header = advance_read(s_field_set_header_v2);
	}

	ASSERT(field_set_header.element_count == 1);

	const blofeld::s_tag_struct_definition& tag_struct_definition = prototype.get_blofeld_struct_definition();

	const char* const group_data_start = global_data_position;
	const char* const group_data_end = group_data_start + field_set_header.element_count * field_set_header.element_size;
	const char* group_data_position = group_data_start;
	global_data_position = group_data_end;



	uint32_t tag_struct_size2;
	uint32_t tag_struct_ext_size2;
	if (BCS_FAILED(rs = calculate_tag_struct_definition_size2(
		tag_struct_definition,
		group_data_position,
		group_data_end,
		global_data_position,
		tag_struct_size2,
		tag_struct_ext_size2,
		field_set_header.struct_version)))
	{
		return rs;
	}

	//ASSERT(tag_struct_size2 == field_set_header.element_size);
	if (tag_struct_size2 != field_set_header.element_size)
	{
		console_write_line("Invalid structure size calculation for %s expected:%lu calculated:%lu", prototype.get_blofeld_struct_definition().name, field_set_header.element_size, tag_struct_size2);
		return BCS_E_FAIL;
	}

	if (BCS_FAILED(rs = traverse_tag_struct(group_data_position, group_data_end, global_data_position, prototype, field_set_header.struct_version)))
	{
		return rs;
	}
	//ASSERT(group_data_position == group_data_end);
	if (group_data_position != group_data_end)
	{
		console_write_line("Data position did not end at expected position");
		return BCS_E_FAIL;
	}

	return rs;
#undef advance_read
}

tag c_gen2_tag_file_parse_context::get_group_tag() const
{
	return tag_file_header.group_tag;
}

BCS_RESULT c_gen2_tag_file_parse_context::parse_gen2_tag_file_data(h_tag*& tag_prototype, const wchar_t* tag_file_path, s_engine_platform_build engine_platform_build)
{
	BCS_RESULT rs = BCS_S_OK;
	void* tag_file_data;
	uint64_t tag_file_data_size;
	if (BCS_FAILED(rs = filesystem_read_file_to_memory(tag_file_path, tag_file_data, tag_file_data_size)))
	{
		return rs;
	}

	rs = parse_gen2_tag_file_data(tag_prototype, tag_file_data, tag_file_data_size, engine_platform_build);

	tracked_free(tag_file_data);

	if (BCS_FAILED(rs))
	{
		console_write_line("Failed to parse '%S'", tag_file_path);
	}
	return rs;
}

BCS_RESULT c_gen2_tag_file_parse_context::parse_gen2_tag_file_data(h_tag*& tag_prototype, const void* tag_file_data, uint64_t tag_file_data_size, s_engine_platform_build engine_platform_build)
{
	BCS_RESULT rs = BCS_S_OK;

	try
	{
		c_gen2_tag_file_parse_context context = c_gen2_tag_file_parse_context(tag_file_data, tag_file_data_size, engine_platform_build);

		tag group_tag = context.get_group_tag();
		const blofeld::s_tag_group* blofeld_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, group_tag);
		if (blofeld_tag_group == nullptr)
		{
			union
			{
				char group_tag_str[5];
				uint64_t byteswap_group_tag;
			};
			byteswap_group_tag = ::byteswap(group_tag);
			console_write_line("Unknown tag group %s", group_tag_str);
			return BCS_E_FAIL;
		}

		ASSERT(blofeld_tag_group->version == context.tag_file_header.group_version);

		h_prototype* object_prototype = h_prototype::create_high_level_object(blofeld_tag_group->block_definition.struct_definition, engine_platform_build);

		if (object_prototype == nullptr) // #TODO: correctly pipe a resullt from this
		{
			return BCS_E_FAIL;
		}

		tag_prototype = dynamic_cast<h_tag*>(object_prototype);
		if (tag_prototype == nullptr) // #TODO: correctly pipe a resullt from this
		{
			delete object_prototype;
			return BCS_E_FAIL;
		}

		if (BCS_FAILED(rs = context.traverse_tag_group(*tag_prototype)))
		{
			return rs;
		}
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}

	return rs;
}
