#include "tagcodegen-private-pch.h"

using namespace blofeld;

c_high_level_tag_source_generator::c_high_level_tag_source_generator(s_engine_platform_build engine_platform_build) :
	engine_platform_build(engine_platform_build)
{

}

const blofeld::s_tag_group* c_high_level_tag_source_generator::get_tag_struct_tag_group(const blofeld::s_tag_struct_definition& tag_struct_definition) const
{
	for (const s_tag_group** tag_group = tag_groups[engine_platform_build.engine_type]; *tag_group; tag_group++)
	{
		const s_tag_struct_definition& current_struct_definition = (*tag_group)->block_definition.struct_definition;

		if (&current_struct_definition == &tag_struct_definition)
		{
			return *tag_group;
		}
	}
	return nullptr;
}

const char* c_high_level_tag_source_generator::field_type_to_high_level_source_type(e_platform_type platform_type, blofeld::e_field field_type)
{
	switch (field_type)
	{
	case _field_string:								return "c_fixed_string_32";
	case _field_long_string:						return "c_fixed_string_256";
	case _field_string_id:							return "h_string_id";
	case _field_old_string_id:						return "h_string_id";
	case _field_char_integer:						return "char";
	case _field_short_integer:						return "short";
	case _field_long_integer:						return "long";
	case _field_int64_integer:						return "long long";
	case _field_angle:								return "angle";
	case _field_tag:								return "tag";
	case _field_char_enum:							return "char";
	case _field_enum:								return "short";
	case _field_long_enum:							return "long";
	case _field_long_flags:							return "long";
	case _field_word_flags:							return "word";
	case _field_byte_flags:							return "byte";
	case _field_point_2d:							return "s_point2d";
	case _field_rectangle_2d:						return "s_rectangle2d";
	case _field_rgb_color:							return "pixel32";
	case _field_argb_color:							return "pixel32";
	case _field_real:								return "real";
	case _field_real_fraction:						return "real_fraction";
	case _field_real_point_2d:						return "real_point2d";
	case _field_real_point_3d:						return "real_point3d";
	case _field_real_vector_2d:						return "real_vector2d";
	case _field_real_vector_3d:						return "real_vector3d";
	case _field_real_quaternion:					return "real_quaternion";
	case _field_real_euler_angles_2d:				return "real_euler_angles2d";
	case _field_real_euler_angles_3d:				return "real_euler_angles3d";
	case _field_real_plane_2d:						return "real_plane2d";
	case _field_real_plane_3d:						return "real_plane3d";
	case _field_real_rgb_color:						return "rgb_color";
	case _field_real_argb_color:					return "argb_color";
	case _field_real_hsv_color:						return "real_hsv_color";
	case _field_real_ahsv_color:					return "real_ahsv_color";
	case _field_short_bounds:						return "short_bounds";
	case _field_angle_bounds:						return "angle_bounds";
	case _field_real_bounds:						return "real_bounds";
	case _field_real_fraction_bounds:				return "real_bounds";
	case _field_tag_reference:						return "h_tag*";
	case _field_block:								return "h_block";
	case _field_long_block_flags:					return "long";
	case _field_word_block_flags:					return "word";
	case _field_byte_block_flags:					return "byte";
	case _field_char_block_index:					return "char";
	case _field_custom_char_block_index:			return "char";
	case _field_short_block_index:					return "short";
	case _field_custom_short_block_index:			return "short";
	case _field_long_block_index:					return "long";
	case _field_custom_long_block_index:			return "long";
	case _field_data:								return "h_data";
	case _field_vertex_buffer:						return "s_tag_d3d_vertex_buffer";
	case _field_pad:								return nullptr;	// dynamic
	case _field_useless_pad:						return nullptr;	// dynamic
	case _field_skip:								return nullptr;	// dynamic
	case _field_non_cache_runtime_value:			return nullptr;	// empty
	case _field_explanation:						return nullptr;	// empty
	case _field_custom:								return nullptr;	// empty
	case _field_struct:								return nullptr;	// dynamic
	case _field_array:								return nullptr;	// dynamic
	case _field_pageable:							return "h_resource*";
	case _field_api_interop:						return "h_interop*";
	case _field_terminator:							return nullptr;	// empty
	case _field_byte_integer:						return "byte";
	case _field_word_integer:						return "word";
	case _field_dword_integer:						return "dword";
	case _field_qword_integer:						return "qword";
	case _field_data_path:							return "c_fixed_string_256";
	case _field_embedded_tag:						return "h_tag*";
	case _field_pointer: // #NONSTANDARD
	{
		uint32_t pointer_size;
		ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(platform_type, &pointer_size)));

		switch (pointer_size)
		{
		case 8: return "long long";
		case 4: return "long";
		default: FATAL_ERROR("bad pointer size");
		}
		break;
	}
	case _field_half:						return "short";
	default: FATAL_ERROR("Unknown field type");
	}
}

void c_high_level_tag_source_generator::generate_header() const
{
	std::stringstream stream;

	const char* namespace_name;
	BCS_RESULT engine_type_to_folder_name_result = get_engine_type_folder_string(engine_platform_build.engine_type, &namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result));

	stream << "#pragma once" << std::endl;
	stream << std::endl;
	stream << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;

	stream << "\t\th_tag* create_high_level_tag(h_group& group, const char* tag_filepath);" << std::endl << std::endl;
	stream << "\t\th_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition);" << std::endl << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

		//if (tag_struct_definition == &blofeld::rasterizer_compiled_shader_struct_struct_definition)
		//{
		//	debug_point;
		//}

		uint32_t blofeld_field_list_size = 1;
		for (const s_tag_field* current_field = struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			if (current_field->field_type > _field_type_non_standard)
			{
				continue;
			}

			blofeld_field_list_size++;
		}

		stream << "\t\t" << "class h_" << struct_definition->name << " : " << std::endl;
		if (tag_group != nullptr)
		{
			stream << "\t\t\t" << "public h_tag" << std::endl;
		}
		else
		{
			stream << "\t\t\t" << "public h_object" << std::endl;
		}
		stream << "\t\t" << "{" << std::endl;
		stream << "\t\t\t" << "public:" << std::endl;
		stream << "\t\t\t\t" << "friend class std::vector<h_" << struct_definition->name << ">;" << std::endl;

		if (tag_group != nullptr)
		{
			stream << "\t\t\t\t" << "h_" << struct_definition->name << "(h_group& group, const char* tag_filepath);" << std::endl;
			stream << "\t\t\t\t" << "h_" << struct_definition->name << "(h_type* parent = nullptr);" << std::endl;
		}
		else
		{
			stream << "\t\t\t\t" << "h_" << struct_definition->name << "(h_type* parent = nullptr);" << std::endl;
		}
		stream << std::endl;

		if (tag_group != nullptr)
		{
			stream << "\t\t\t\t" << "virtual const blofeld::s_tag_group& get_blofeld_group_definition() const final;" << std::endl;
		}
		stream << "\t\t\t\t" << "virtual uint32_t get_high_level_type_size() const final;" << std::endl;
		stream << "\t\t\t\t" << "virtual uint32_t get_low_level_type_size() const final;" << std::endl;
		stream << "\t\t\t\t" << "virtual void* get_field_data(const blofeld::s_tag_field& field) final;" << std::endl;
		stream << "\t\t\t\t" << "virtual bool is_field_active(const blofeld::s_tag_field& field) const final;" << std::endl;
		stream << "\t\t\t\t" << "virtual const blofeld::s_tag_struct_definition& get_blofeld_struct_definition() const final;" << std::endl;
		stream << "\t\t\t\t" << "virtual const blofeld::s_tag_field* const* get_blofeld_field_list() const final;" << std::endl;
		stream << "\t\t\t\t" << "virtual void copy_from_memory(const void* data) final;" << std::endl;
		stream << "\t\t\t\t" << "virtual void copy_to_memory(void* data) const final;" << std::endl;

		stream << std::endl;

		stream << "\t\t\t\t" << "static uint32_t const high_level_type_size;" << std::endl;
		stream << "\t\t\t\t" << "static uint32_t const low_level_type_size;" << std::endl;
		stream << "\t\t\t\t" << "static const blofeld::s_tag_field* const blofeld_field_list[" << blofeld_field_list_size << "];" << std::endl;

		stream << std::endl;

		uint32_t field_index = 0;
		for (const s_tag_field* current_field = struct_definition->fields; current_field->field_type != _field_terminator; current_field++, field_index++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
			{
				current_field += field_skip_count;
				field_index += field_skip_count;
				continue;
			}

			if (current_field->field_type > _field_type_non_standard)
			{
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_skip:
			case _field_useless_pad:
			case _field_custom:
			case _field_terminator:
			case _field_explanation:
			case _field_non_cache_runtime_value:
				continue;
			}

			c_blamlib_string_parser field_formatter = c_blamlib_string_parser(
				current_field->name,
				current_field->field_type == blofeld::_field_block,
				&field_name_unique_counter);

			if (!custom_structure_codegen(_custom_structure_codegen_high_level_header, stream, "\t\t\t\t", &field_formatter, *struct_definition, *current_field, namespace_name))
			{

				switch (current_field->field_type)
				{
				case _field_array:
				{
					const char* field_source_type = current_field->array_definition->struct_definition.name;
					stream << "\t\t\t\t" << "h_typed_array<h_" << field_source_type << ", " << current_field->array_definition->count(engine_platform_build) << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_struct:
				{
					const char* field_source_type = current_field->struct_definition->name;
					stream << "\t\t\t\t" << "h_" << field_source_type << " " << field_formatter.code_name.c_str() << ";";
					break;
				}
				case _field_block:
				{
					const char* field_source_type = current_field->block_definition->struct_definition.name;
					stream << "\t\t\t\t" << "h_typed_block<h_" << field_source_type << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_data:
				{
					stream << "\t\t\t\t" << "h_data " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_long_flags:
				case _field_word_flags:
				case _field_byte_flags:
				{
					const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;

					stream << "\t\t\t\t" << "h_field<c_flags<e_" << string_list.name << ", dword>, h_" << struct_definition->name << ", " << field_index << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_char_enum:
				case _field_enum:
				case _field_long_enum:
				{
					const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
					stream << "\t\t\t\t" << "h_field<e_" << string_list.name << ", h_" << struct_definition->name << ", " << field_index << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				default:
				{
					const char* field_source_type = field_type_to_high_level_source_type(engine_platform_build.platform_type, current_field->field_type);
					ASSERT(field_source_type != nullptr);
					stream << "\t\t\t\t" << "h_field<" << field_source_type << ", h_" << struct_definition->name << ", " << field_index << "> " << field_formatter.code_name.c_str() << ";";
				}
				}
				stream << std::endl;

			}

		}
		field_name_unique_counter.clear();

		stream << "\t\t" << "};" << std::endl;

		stream << std::endl;
	}

	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + "HighLevel/high_level_" + namespace_name + "/generated/" + namespace_name + "_high_level.h";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if (filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
	{
		if (source_code.size() == existing_file_size && strncmp(existing_file_data, source_code.c_str(), existing_file_size) == 0)
		{
			write_output = false;
		}
		delete[] existing_file_data;
	}

	if (write_output)
	{
		bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
		ASSERT(filesystem_write_file_from_memory_result);
	}
}

void c_high_level_tag_source_generator::generate_tag_constructor_params(std::stringstream& stream, const s_tag_struct_definition& struct_definition) const
{
	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		if (current_field->field_type > _field_type_non_standard)
		{
			continue;
		}

		switch (current_field->field_type)
		{
		case _field_pad:
		case _field_skip:
		case _field_useless_pad:
		case _field_custom:
		case _field_terminator:
		case _field_explanation:
		case _field_non_cache_runtime_value:
			continue;
		}

		c_blamlib_string_parser field_formatter = c_blamlib_string_parser(
			current_field->name,
			current_field->field_type == blofeld::_field_block,
			&field_name_unique_counter);

		if (!custom_structure_codegen(_custom_structure_codegen_high_level_ctor, stream, "\t\t\t\t", &field_formatter, struct_definition, *current_field, nullptr))
		{
			switch (current_field->field_type)
			{
			case _field_array:
			{
				const s_tag_group* tag_group = get_tag_struct_tag_group(current_field->array_definition->struct_definition);

				const char* field_source_type = current_field->array_definition->struct_definition.name;
				if (tag_group)
				{
					stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "(this)" << std::endl;
				}
				else
				{
					stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "(this)" << std::endl;
				}

				break;
			}
			case _field_struct:
			{
				const s_tag_group* tag_group = get_tag_struct_tag_group(*current_field->struct_definition);

				const char* field_source_type = current_field->struct_definition->name;
				if (tag_group)
				{
					stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
				}
				else
				{
					stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
				}

				break;
			}
			case _field_block:
			{
				stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "(this)" << std::endl;
				break;
			}
			default:
			{
				stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
				break;
			}
			}
		}
	}
}

void c_high_level_tag_source_generator::generate_ctor_source(uint32_t source_index, uint32_t source_count) const
{
	std::stringstream stream;

	const char* namespace_name;
	BCS_RESULT engine_type_to_folder_name_result = get_engine_type_folder_string(engine_platform_build.engine_type, &namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result));

	const char* source_namespace_name;
	BCS_RESULT engine_type_to_folder_name_result2 = get_engine_type_source_string(engine_platform_build.engine_type, &source_namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result2));

	stream << "#include <highlevel-" << source_namespace_name << "-private-pch.h>" << std::endl << std::endl;
	stream << std::endl;

	stream << "#pragma warning(disable : 4065)" << std::endl;
	stream << "#pragma warning(error : 4172)" << std::endl;
	stream << std::endl;

	stream << std::endl;
	stream << "#ifndef __INTELLISENSE__" << std::endl;
	stream << std::endl;

	{
		uint32_t structure_index = 0;
		for (const blofeld::s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			if ((structure_index++ % source_count) == source_index)
			{
				stream << "_h_typed_block_ctor_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_array_operator_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_get_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_data_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_type_size_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_size_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_data_size_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_emplace_back_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_emplace_back_alt_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_reserve_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_resize_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_insert_hole_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_remove_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << "_h_typed_block_clear_impl(blofeld::" << namespace_name << "::h_" << struct_definition->name << ");" << std::endl;
				stream << std::endl;
			}
		}
	}
	stream << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;

	{
		std::map<std::string, int> field_name_unique_counter;
		uint32_t structure_index = 0;
		for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			if ((structure_index++ % source_count) == source_index)
			{
				const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);

				if (tag_group != nullptr)
				{
					stream << "\t\t" << "h_" << tag_struct_definition->name << "::h_" << tag_struct_definition->name;
					stream << "(h_group& group, const char* tag_filepath) :" << std::endl;
					stream << "\t\t\t" << "h_tag(&group, tag_filepath)" << std::endl;
					generate_tag_constructor_params(stream, *tag_struct_definition);
					stream << "\t\t" << "{" << std::endl;
					stream << "\t\t\t" << "high_level_tag_ctor(this);" << std::endl;
					stream << "\t\t" << "}" << std::endl;
					stream << std::endl;

					stream << "\t\t" << "h_" << tag_struct_definition->name << "::h_" << tag_struct_definition->name;
					stream << "(h_type* parent) :" << std::endl;
					stream << "\t\t\t" << "h_tag(parent)" << std::endl;
					generate_tag_constructor_params(stream, *tag_struct_definition);
					stream << "\t\t" << "{" << std::endl;
					stream << "\t\t\t" << "high_level_tag_ctor(this);" << std::endl;
					stream << "\t\t" << "}" << std::endl;
					stream << std::endl;
				}
				else
				{
					stream << "\t\t" << "h_" << tag_struct_definition->name << "::h_" << tag_struct_definition->name;
					stream << "(h_type* parent) :" << std::endl;
					stream << "\t\t\t" << "h_object(parent)" << std::endl;
					generate_tag_constructor_params(stream, *tag_struct_definition);
					stream << "\t\t" << "{" << std::endl;
					stream << "\t\t\t" << "high_level_tag_ctor(this);" << std::endl;
					stream << "\t\t" << "}" << std::endl;
					stream << std::endl;
				}
			}
		}
	}

	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	{
		std::map<std::string, int> field_name_unique_counter;
		uint32_t structure_index = 0;
		for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			if ((structure_index++ % source_count) == source_index)
			{

				const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

				uint32_t field_index = 0;
				for (const s_tag_field* current_field = struct_definition->fields; current_field->field_type != _field_terminator; current_field++, field_index++)
				{
					uint32_t field_skip_count;
					if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
					{
						current_field += field_skip_count;
						field_index += field_skip_count;
						continue;
					}

					if (current_field->field_type > _field_type_non_standard)
					{
						continue;
					}

					switch (current_field->field_type)
					{
					case _field_pad:
					case _field_skip:
					case _field_useless_pad:
					case _field_custom:
					case _field_terminator:
					case _field_explanation:
					case _field_non_cache_runtime_value:
						continue;
					}

					c_blamlib_string_parser field_formatter = c_blamlib_string_parser(
						current_field->name,
						current_field->field_type == blofeld::_field_block,
						&field_name_unique_counter);

					if (!custom_structure_codegen(_custom_structure_codegen_high_level_field_impl, stream, "\t\t\t\t", &field_formatter, *struct_definition, *current_field, namespace_name))
					{

						switch (current_field->field_type)
						{
						case _field_array:
						{
							const char* field_source_type = current_field->array_definition->struct_definition.name;
							stream << "using t_" << struct_definition->name << "_" << field_formatter.code_name.c_str() << " = " << "h_typed_array<blofeld::" << namespace_name << "::h_" << field_source_type << ", " << current_field->array_definition->count(engine_platform_build) << ">;" << std::endl;
							stream << "h_field_func_impl(t_" << struct_definition->name << "_" << field_formatter.code_name.c_str() << ", blofeld::" << namespace_name << "::h_" << struct_definition->name << ", " << field_index << ", " << field_formatter.code_name.c_str() << ");";
							break;
						}
						case _field_struct:
						{
							const char* field_source_type = current_field->struct_definition->name;
							stream << "h_field_func_impl(blofeld::" << namespace_name << "::h_" << field_source_type << ", blofeld::" << namespace_name << "::h_" << struct_definition->name << ", " << field_index << ", " << field_formatter.code_name.c_str() << ");";
							break;
						}
						case _field_block:
						{
							const char* field_source_type = current_field->block_definition->struct_definition.name;
							stream << "h_field_func_impl(h_typed_block<blofeld::" << namespace_name << "::h_" << field_source_type << ">, blofeld::" << namespace_name << "::h_" << struct_definition->name << ", " << field_index << ", " << field_formatter.code_name.c_str() << ");";
							break;
						}
						case _field_data:
						{
							stream << "h_field_func_impl(h_data, blofeld::" << namespace_name << "::h_" << struct_definition->name << ", " << field_index << ", " << field_formatter.code_name.c_str() << ");";
							break;
						}
						case _field_tag_reference:
						{
							stream << "h_field_func_impl(h_tag*, blofeld::" << namespace_name << "::h_" << struct_definition->name << ", " << field_index << ", " << field_formatter.code_name.c_str() << ");";
							break;
						}
						case _field_long_flags:
						case _field_word_flags:
						case _field_byte_flags:
						{
							const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
							stream << "using t_" << struct_definition->name << "_" << field_formatter.code_name.c_str() << " = c_flags<blofeld::" << namespace_name << "::e_" << string_list.name << ", dword>;" << std::endl;
							stream << "h_field_func_impl(t_" << struct_definition->name << "_" << field_formatter.code_name.c_str() << ", blofeld::" << namespace_name << "::h_" << struct_definition->name << ", " << field_index << ", " << field_formatter.code_name.c_str() << ");";
							break;
						}
						case _field_char_enum:
						case _field_enum:
						case _field_long_enum:
						{
							const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
							stream << "h_field_func_impl(blofeld::" << namespace_name << "::e_" << string_list.name << ", blofeld::" << namespace_name << "::h_" << struct_definition->name << ", " << field_index << ", " << field_formatter.code_name.c_str() << ");";
							break;
						}
						default:
						{
							const char* field_source_type = field_type_to_high_level_source_type(engine_platform_build.platform_type, current_field->field_type);
							ASSERT(field_source_type != nullptr);
							stream << "h_field_func_impl(" << field_source_type << ", blofeld::" << namespace_name << "::h_" << struct_definition->name << ", " << field_index << ", " << field_formatter.code_name.c_str() << ");";
						}
						}
						stream << std::endl;
					}

				}
				field_name_unique_counter.clear();

				stream << std::endl;
			}
		}
	}

	stream << std::endl;
	stream << "#endif" << std::endl;
	stream << std::endl;

	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + "HighLevel/high_level_" + namespace_name + "/generated/" + namespace_name + "_high_level.ctor" + std::to_string(source_index) + ".cpp";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if (filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
	{
		if (source_code.size() == existing_file_size && strncmp(existing_file_data, source_code.c_str(), existing_file_size) == 0)
		{
			write_output = false;
		}
		delete[] existing_file_data;
	}

	if (write_output)
	{
		bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
		ASSERT(filesystem_write_file_from_memory_result);
	}
}

void c_high_level_tag_source_generator::generate_source_virtual() const
{
	std::stringstream stream;

	const char* namespace_name;
	BCS_RESULT engine_type_to_folder_name_result = get_engine_type_folder_string(engine_platform_build.engine_type, &namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result));

	const char* source_namespace_name;
	BCS_RESULT engine_type_to_folder_name_result2 = get_engine_type_source_string(engine_platform_build.engine_type, &source_namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result2));

	stream << "#include <highlevel-" << source_namespace_name << "-private-pch.h>" << std::endl << std::endl;
	stream << std::endl;

	stream << "#pragma warning(disable : 4065)" << std::endl;
	stream << "#pragma warning(error : 4172)" << std::endl;
	stream << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;

	stream << std::endl;
	stream << "#ifndef __INTELLISENSE__" << std::endl;
	stream << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);

		//if (tag_struct_definition == &blofeld::rasterizer_compiled_shader_struct_struct_definition)
		//{
		//	debug_point;
		//}

		uint32_t blofeld_field_list_count = 1;
		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			if (current_field->field_type > _field_type_non_standard)
			{
				continue;
			}

			blofeld_field_list_count++;
		}

		uint32_t low_level_type_size = calculate_struct_size(engine_platform_build, *tag_struct_definition);

		stream << "\t\t" << "uint32_t const h_" << tag_struct_definition->name << "::high_level_type_size = sizeof(h_" << tag_struct_definition->name << ");" << std::endl;
		stream << "\t\t" << "uint32_t const h_" << tag_struct_definition->name << "::low_level_type_size = " << low_level_type_size << "u;" << std::endl;
		stream << "\t\t" << "const blofeld::s_tag_field* const h_" << tag_struct_definition->name << "::blofeld_field_list[" << blofeld_field_list_count << "] = " << std::endl;
		stream << "\t\t" << "{" << std::endl;
		{
			uint32_t field_index = 0;
			for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++, field_index++)
			{
				uint32_t field_skip_count;
				if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
				{
					current_field += field_skip_count;
					field_index += field_skip_count;
					continue;
				}

				if (current_field->field_type > _field_type_non_standard)
				{
					continue;
				}

				stream << "\t\t\t" << tag_struct_definition->symbol->symbol_name << ".fields" << " + " << field_index << "," << std::endl;
			}
		}
		stream << "\t\t\t" << "nullptr" << std::endl;
		stream << "\t\t" << "};" << std::endl;
		stream << std::endl;

		if (tag_group != nullptr)
		{
			stream << "\t\t" << "const blofeld::s_tag_group& h_" << tag_struct_definition->name << "::get_blofeld_group_definition() const" << std::endl;
			stream << "\t\t{" << std::endl;
			stream << "\t\t\treturn " << tag_group->symbol->symbol_name << ";" << std::endl;
			stream << "\t\t}" << std::endl;
			stream << std::endl;
		}

		stream << "\t\t" << "uint32_t h_" << tag_struct_definition->name << "::get_high_level_type_size() const" << std::endl;
		stream << "\t\t{" << std::endl;
		stream << "\t\t\treturn high_level_type_size;" << std::endl;
		stream << "\t\t}" << std::endl;
		stream << std::endl;

		stream << "\t\t" << "uint32_t h_" << tag_struct_definition->name << "::get_low_level_type_size() const" << std::endl;
		stream << "\t\t{" << std::endl;
		stream << "\t\t\treturn low_level_type_size;" << std::endl;
		stream << "\t\t}" << std::endl;
		stream << std::endl;

		stream << "\t\t" << "const blofeld::s_tag_struct_definition& h_" << tag_struct_definition->name << "::get_blofeld_struct_definition() const" << std::endl;
		stream << "\t\t{" << std::endl;
		stream << "\t\t\treturn " << tag_struct_definition->symbol->symbol_name << ";" << std::endl;
		stream << "\t\t}" << std::endl;
		stream << std::endl;

		stream << "\t\t" << "const blofeld::s_tag_field* const* h_" << tag_struct_definition->name << "::get_blofeld_field_list() const" << std::endl;
		stream << "\t\t{" << std::endl;
		stream << "\t\t\treturn blofeld_field_list;" << std::endl;
		stream << "\t\t}" << std::endl;
		stream << std::endl;

		stream << "\t\t" << "void h_" << tag_struct_definition->name << "::copy_from_memory(const void* data)" << std::endl;
		stream << "\t\t{" << std::endl;
		stream << "\t\t}" << std::endl;
		stream << std::endl;

		stream << "\t\t" << "void h_" << tag_struct_definition->name << "::copy_to_memory(void* data) const" << std::endl;
		stream << "\t\t{" << std::endl;
		stream << "\t\t}" << std::endl;
		stream << std::endl;
	}

	stream << std::endl;
	stream << "#endif" << std::endl;
	stream << std::endl;

	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + "HighLevel/high_level_" + namespace_name + "/generated/" + namespace_name + "_high_level.virtual.cpp";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if (filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
	{
		if (source_code.size() == existing_file_size && strncmp(existing_file_data, source_code.c_str(), existing_file_size) == 0)
		{
			write_output = false;
		}
		delete[] existing_file_data;
	}

	if (write_output)
	{
		bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
		ASSERT(filesystem_write_file_from_memory_result);
	}
}

void c_high_level_tag_source_generator::generate_source_misc() const
{
	std::stringstream stream;

	const char* namespace_name;
	BCS_RESULT engine_type_to_folder_name_result = get_engine_type_folder_string(engine_platform_build.engine_type, &namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result));

	const char* source_namespace_name;
	BCS_RESULT engine_type_to_folder_name_result2 = get_engine_type_source_string(engine_platform_build.engine_type, &source_namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result2));

	stream << "#include <highlevel-" << source_namespace_name << "-private-pch.h>" << std::endl << std::endl;
	stream << std::endl;

	stream << "#pragma warning(disable : 4065)" << std::endl;
	stream << "#pragma warning(error : 4172)" << std::endl;
	stream << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;

	stream << "\t\t" << "h_tag* create_high_level_tag(h_group& group, const char* tag_filepath)" << std::endl;
	stream << "\t\t" << "{" << std::endl;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);
		if (tag_group == nullptr) continue;

		stream << "\t\t\t" << "if (&group.tag_group == &" << tag_group->symbol->symbol_name << ")";
		stream << " " << "return new h_" << tag_struct_definition->name << "(group, tag_filepath);" << std::endl;
	}
	stream << std::endl;
	stream << "\t\t\t" << "return nullptr;" << std::endl;
	stream << "\t\t" << "}" << std::endl;
	stream << std::endl;

	stream << "\t\t" << "h_object* create_high_level_object(const blofeld::s_tag_struct_definition& struct_definition)" << std::endl;
	stream << "\t\t" << "{" << std::endl;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);

		stream << "\t\t\t" << "if (&struct_definition == &" << tag_struct_definition->symbol->symbol_name << ")";
		if (tag_group != nullptr)
		{
			stream << " " << "return new h_" << tag_struct_definition->name << "();" << std::endl;
		}
		else
		{
			stream << " " << "return new h_" << tag_struct_definition->name << "();" << std::endl;
		}
	}
	stream << std::endl;
	stream << "\t\t\t" << "return nullptr;" << std::endl;
	stream << "\t\t" << "}" << std::endl;
	stream << std::endl;

	stream << std::endl;
	stream << "#ifndef __INTELLISENSE__" << std::endl;
	stream << std::endl;

	{
		std::map<std::string, int> field_name_unique_counter;
		for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

			stream << "\t\t" << "void* h_" << struct_definition->name << "::get_field_data(const blofeld::s_tag_field& field)" << std::endl;
			stream << "\t\t{" << std::endl;
			stream << "\t\t\tintptr_t const _index = &field - " << struct_definition->symbol->symbol_name << ".fields;" << std::endl;
			stream << std::endl;
			stream << "\t\t\tswitch (_index)" << std::endl;
			stream << "\t\t\t{" << std::endl;


			field_name_unique_counter.clear();
			uint32_t field_index = 0;
			for (const s_tag_field* current_field = struct_definition->fields; current_field->field_type != _field_terminator; current_field++, field_index++)
			{
				uint32_t field_skip_count;
				if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
				{
					current_field += field_skip_count;
					field_index += field_skip_count;
					continue;
				}

				if (current_field->field_type > _field_type_non_standard)
				{
					continue;
				}

				switch (current_field->field_type)
				{
				case _field_pad:
				case _field_skip:
				case _field_useless_pad:
				case _field_custom:
				case _field_terminator:
				case _field_explanation:
				case _field_non_cache_runtime_value:
					continue;
				}

				c_blamlib_string_parser field_formatter = c_blamlib_string_parser(
					current_field->name, 
					current_field->field_type == blofeld::_field_block, 
					&field_name_unique_counter);

				if (!custom_structure_codegen(_custom_structure_codegen_high_level_get_field_data_func, stream, "\t\t\t\t", &field_formatter, *struct_definition, *current_field, namespace_name))
				{
					stream << "\t\t\t\tcase " << field_index << ": return &" << field_formatter.code_name.c_str() << ";" << std::endl;
				}
			}
			stream << "\t\t\t\tdefault: return nullptr;" << std::endl;

			stream << "\t\t\t}" << std::endl;
			stream << std::endl;

			stream << "\t\t}" << std::endl;
			stream << std::endl;
		}
	}

	{
		std::map<std::string, int> field_name_unique_counter;
		for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);

			stream << "\t\t" << "bool h_" << tag_struct_definition->name << "::is_field_active(const blofeld::s_tag_field& field) const" << std::endl;
			stream << "\t\t{" << std::endl;
			stream << "\t\t\tintptr_t const _index = &field - " << tag_struct_definition->symbol->symbol_name << ".fields;" << std::endl;
			stream << std::endl;
			stream << "\t\t\tswitch (_index)" << std::endl;
			stream << "\t\t\t{" << std::endl;

			field_name_unique_counter.clear();
			uint32_t field_index = 0;
			for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++, field_index++)
			{
				uint32_t field_skip_count;
				if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
				{
					current_field += field_skip_count;
					field_index += field_skip_count;
					continue;
				}

				if (current_field->field_type > _field_type_non_standard)
				{
					continue;
				}

				stream << "\t\t\t\tcase " << field_index << ": return true;" << std::endl;
			}
			stream << "\t\t\t\tdefault: return false;" << std::endl;

			stream << "\t\t\t}" << std::endl;
			stream << std::endl;

			stream << "\t\t}" << std::endl;
			stream << std::endl;
		}
	}

	stream << std::endl;
	stream << "#endif" << std::endl;
	stream << std::endl;

	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + "HighLevel/high_level_" + namespace_name + "/generated/" + namespace_name + "_high_level.misc.cpp";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if (filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
	{
		if (source_code.size() == existing_file_size && strncmp(existing_file_data, source_code.c_str(), existing_file_size) == 0)
		{
			write_output = false;
		}
		delete[] existing_file_data;
	}

	if (write_output)
	{
		bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
		ASSERT(filesystem_write_file_from_memory_result);
	}
}
