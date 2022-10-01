#include "tagcodegen-private-pch.h"

using namespace blofeld;


static uint32_t calculate_struct_size(s_engine_platform_build engine_platform_build, const blofeld::s_tag_struct_definition& struct_definition)
{
	using namespace blofeld;

	uint32_t computed_size = 0;

	for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (execute_tag_field_versioning(*current_field, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		uint32_t field_size = 0;
		switch (current_field->field_type)
		{
		case _field_useless_pad:
			//computed_size += current_field->padding;
			break;
		case _field_pad:
			field_size = current_field->padding;
			break;
		case _field_skip:
			field_size = current_field->length;
			break;
		case _field_struct:
			field_size = calculate_struct_size(engine_platform_build , *current_field->struct_definition);
			break;
		case _field_array:
		{
			const s_tag_array_definition& array_definition = *current_field->array_definition;
			REFERENCE_ASSERT(array_definition);
			const s_tag_struct_definition& struct_definition = array_definition.struct_definition;
			REFERENCE_ASSERT(struct_definition);
			uint32_t struct_size = calculate_struct_size(engine_platform_build, struct_definition);
			uint32_t array_data_size = struct_size * array_definition.count(engine_platform_build);
			field_size = array_data_size;
			break;
		}
		default:
			field_size = blofeld::get_blofeld_field_size(engine_platform_build.platform_type, current_field->field_type);
			break;
		}

		computed_size += field_size;
	}

	//ASSERT((computed_size % (1u << struct_definition.alignment_bits)) == 0);

	return computed_size;
}


c_low_level_tag_source_generator::c_low_level_tag_source_generator(s_engine_platform_build _engine_platform_build) :
	c_source_generator_base(_engine_platform_build),
	output_directory(),
	output_header_file_path(),
	output_ida_header_file_path(),
	output_enum_header_file_path(),
	output_source_file_path()
{
	const char* _output_directory;
	BCS_RESULT get_output_argument_result = command_line_get_argument("output", _output_directory); // #TODO: rename to 'output-directory'
	BCS_FAIL_THROW_DBG(get_output_argument_result);

	std::stringstream output_directory_stream;
	output_directory_stream << _output_directory << "low_level_" << get_engine_namespace(false) << "_" + get_platform_namespace(false);
	output_directory = output_directory_stream.str();

	std::stringstream output_header_file_path_stream;
	output_header_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + ".h";
	output_header_file_path = output_header_file_path_stream.str();

	std::stringstream output_ida_header_file_path_stream;
	output_ida_header_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + "_ida.h";
	output_ida_header_file_path = output_ida_header_file_path_stream.str();

	std::stringstream output_enum_header_file_path_stream;
	output_enum_header_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + "_enum.h";
	output_enum_header_file_path = output_enum_header_file_path_stream.str();

	std::stringstream output_source_file_path_stream;
	output_source_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + ".cpp";
	output_source_file_path = output_source_file_path_stream.str();
}

c_low_level_tag_source_generator::~c_low_level_tag_source_generator()
{
}

const char* c_low_level_tag_source_generator::field_type_to_low_level_source_type(e_platform_type platform_type, e_field field_type)
{
	switch (field_type)
	{
	case _field_string:								return "c_static_string<32>";
	case _field_long_string:						return "c_static_string<256>";
	case _field_string_id:							return "string_id";
	case _field_old_string_id:						return "c_old_string_id";
	case _field_char_integer:						return "char";
	case _field_short_integer:						return "short";
	case _field_long_integer:						return "int32_t";
	case _field_int64_integer:						return "int64_t";
	case _field_angle:								return "angle";
	case _field_tag:								return "tag";
	case _field_char_enum:							return "char";
	case _field_short_enum:							return "short";
	case _field_long_enum:							return "int32_t";
	case _field_long_flags:							return "int32_t";
	case _field_word_flags:							return "word";
	case _field_byte_flags:							return "byte";
	case _field_point_2d:							return "s_point2d";
	case _field_rectangle_2d:						return "s_rectangle2d";
	case _field_rgb_color:							return "pixel32";
	case _field_argb_color:							return "pixel32";
	case _field_real:								return "real";
	case _field_real_slider:						return "real";
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
	case _field_short_integer_bounds:				return "short_bounds";
	case _field_angle_bounds:						return "angle_bounds";
	case _field_real_bounds:						return "real_bounds";
	case _field_real_fraction_bounds:				return "real_bounds";
	case _field_tag_reference:						return "s_tag_reference";
	case _field_block:								return "s_tag_block";
	case _field_long_block_flags:					return "int32_t";
	case _field_word_block_flags:					return "word";
	case _field_byte_block_flags:					return "byte";
	case _field_char_block_index:					return "char";
	case _field_char_block_index_custom_search:		return "char";
	case _field_short_block_index:					return "short";
	case _field_short_block_index_custom_search:	return "short";
	case _field_long_block_index:					return "int32_t";
	case _field_long_block_index_custom_search:		return "int32_t";
	case _field_data:								return "s_tag_data";
	case _field_vertex_buffer:						return "s_tag_d3d_vertex_buffer";
	case _field_pad:								return nullptr;	// dynamic
	case _field_useless_pad:						return nullptr;	// dynamic
	case _field_skip:								return nullptr;	// dynamic
	case _field_non_cache_runtime_value:			return nullptr;	// empty
	case _field_explanation:						return nullptr;	// empty
	case _field_custom:								return nullptr;	// empty
	case _field_struct:								return nullptr;	// dynamic
	case _field_array:								return nullptr;	// dynamic
	case _field_pageable_resource:					return "s_tag_resource";
	case _field_api_interop:						return "s_tag_interop";
	case _field_terminator:							return nullptr;	// empty
	case _field_byte_integer:						return "byte";
	case _field_word_integer:						return "word";
	case _field_dword_integer:						return "dword";
	case _field_qword_integer:						return "qword";
	case _field_data_path:							return "c_static_string<256>";
	case _field_embedded_tag:						return "s_tag_reference";
	case _field_pointer: // #NONSTANDARD
	{
		uint32_t pointer_size;
		ASSERT(BCS_SUCCEEDED(get_platform_pointer_size(platform_type, &pointer_size)));

		switch (pointer_size)
		{
		case 8: return "int64_t";
		case 4: return "int32_t";
		default: FATAL_ERROR("bad pointer size");
		}
		break;
	}
	case _field_half:						return "short";
	default: FATAL_ERROR("Unknown field type");
	}
}

void c_low_level_tag_source_generator::generate_header()
{
	std::string namespace_without_semicolons = get_namespace(false);

	std::stringstream stream;

	stream << "#pragma once" << std::endl;
	stream << indent << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace | _namespace_tree_write_pragma_pack);

	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		stream << indent << "struct " << struct_definition->struct_name << std::endl;
		stream << indent << "{" << std::endl;
		increment_indent();
		std::unordered_map<std::string, int> field_name_unique_counter;

		for (const s_tag_field* tag_field_iterator = struct_definition->fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
		{
			const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max);

			std::unordered_map<std::string, int>* field_name_unique_counter_ptr = nullptr;
			switch (tag_field.field_type)
			{
			case _field_custom:
				break;
			default:
				field_name_unique_counter_ptr = &field_name_unique_counter;
				break;
			}

			c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
				tag_field.name,
				tag_field.field_type == blofeld::_field_block,
				&field_name_unique_counter);

			const char* field_type_string;
			ASSERT(BCS_SUCCEEDED(field_to_tagfile_field_type(tag_field.field_type, field_type_string)));

			if (!custom_structure_codegen(_custom_structure_codegen_low_level_header, stream, indent.c_str(), &field_formatter, *struct_definition, tag_field, namespace_without_semicolons.c_str()))
			{
				switch (tag_field.field_type)
				{
				case _field_pad:
					stream << indent << "char " << field_formatter.code_name.c_str() << "[" << tag_field.padding << "]; // padding" << std::endl;
					break;
				case _field_skip:
					stream << indent << "char " << field_formatter.code_name.c_str() << "[" << tag_field.padding << "]; // skip" << std::endl;
					break;
				case _field_useless_pad:
					stream << indent << "// char " << field_formatter.code_name.c_str() << "[" << tag_field.padding << "]; // useless padding" << std::endl;
					break;
				case _field_non_cache_runtime_value:
					stream << indent << "// " << field_formatter.code_name.c_str() << "[" << tag_field.padding << "]; // non cache runtime value" << std::endl;
					break;
				case _field_custom:
					stream << indent << "// " << field_type_string;
					if (!field_formatter.code_name.empty())
					{
						stream << " " << field_formatter.code_name.c_str();
					}
					stream << indent << std::endl;
					break;
				case _field_terminator:
					stream << indent << "// " << field_type_string << std::endl;
					break;
				case _field_explanation:
				{
					if (tag_field.name)
					{
						if (tag_field.explanation && *tag_field.explanation)
						{
							stream << indent << std::endl;
							stream << indent << "/* " << tag_field.name << std::endl;
							stream << indent << " ";
							const char* current_pos = tag_field.explanation;
							while (*current_pos)
							{
								switch (*current_pos)
								{
								case '\n':
									stream << *current_pos;
									stream << indent << " ";
									break;
								default:
									stream << *current_pos;
								}
								current_pos++;
							}
							stream << indent << std::endl;
							stream << indent << "*/" << std::endl << std::endl;
						}
						else
						{
							stream << indent << std::endl;
							stream << indent << "/* " << tag_field.name << " */" << std::endl << std::endl;
						}
					}
					break;
				}
				case _field_array:
				{
					uint32_t count = tag_field.array_definition->count(engine_platform_build);
					if (count == 0)
					{
						debug_point;
					}
					stream << indent << "" << tag_field.array_definition->struct_definition.struct_name << " " << field_formatter.code_name.c_str() << "[" << count << "];";
					break;
				}
				case _field_struct:
				{
					uint32_t field_struct_size = calculate_struct_size(engine_platform_build, *tag_field.struct_definition);
					if (field_struct_size > 0)
					{
						stream << indent << "" << tag_field.struct_definition->struct_name << " " << field_formatter.code_name.c_str() << ";";
					}
					else
					{
						stream << indent << "// " << tag_field.struct_definition->struct_name << " " << field_formatter.code_name.c_str() << "; // empty struct";
					}
					break;
				}
				case _field_block:
				{
					stream << indent << "c_typed_tag_block<" << tag_field.block_definition->struct_definition.struct_name << "> " << field_formatter.code_name.c_str() << ";";
					break;
				}
				case _field_tag_reference:
				{
					//if (tag_field.tag_reference_definition == nullptr)
					//{
					//	console_write_line("%s(%i): error TSG0001: _field_tag_reference is null", tag_field.filename, tag_field.line);
					//	has_error = true;
					//}
					//else
					{
						bool handled = false;

						std::vector<unsigned long> group_tags;
						if (tag_field.tag_reference_definition)
						{
							int32_t group_tag = tag_field.tag_reference_definition->group_tag;
							uint32_t group_tag_count = tag_field.tag_reference_definition->group_tag;

							if (tag_field.tag_reference_definition->group_tag != INVALID_TAG)
							{
								group_tags.emplace_back(tag_field.tag_reference_definition->group_tag);
							}
							else if (tag_field.tag_reference_definition->group_tags)
							{
								for (const uint32_t* current_group_tag = tag_field.tag_reference_definition->group_tags; *current_group_tag != INVALID_TAG; current_group_tag++)
								{
									group_tags.push_back(*current_group_tag);
								}
							}
						}

						if (group_tags.empty())
						{
							stream << indent << "s_tag_reference " << field_formatter.code_name.c_str() << ";";
						}
						else
						{

							stream << indent << "c_typed_tag_reference<";

							for (size_t group_tag_index = 0; group_tag_index < group_tags.size(); group_tag_index++)
							{
								const s_tag_group* tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, group_tags[group_tag_index]);
								if (tag_group == nullptr)
								{
									debug_point;
								}
								ASSERT(tag_group != nullptr);
								if (group_tag_index > 0)
								{
									stream << ", ";
								}

								//c_fixed_string_128 tag_group_name = tag_group->name;
								//tag_group_name += "_TAG";
								//tag_group_name.uppercase();

								//stream << tag_group_name.data;

								stream << get_namespace(true) << tag_group->group_tag_macro_symbol;
							}
							stream << "> " << field_formatter.code_name.c_str() << ";";
						}
					}

					break;
				}
				case _field_char_enum:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "c_enum<e_" << string_list.name << ", char> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_short_enum:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "c_enum<e_" << string_list.name << ", short> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_long_enum:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "c_enum<e_" << string_list.name << ", long> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_byte_flags:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "c_flags<e_" << string_list.name << ", char, k_" << string_list.name << "_count> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_word_flags:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "c_flags<e_" << string_list.name << ", short, k_" << string_list.name << "_count> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_long_flags:
				{

					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "c_flags<e_" << string_list.name << ", int32_t, k_" << string_list.name << "_count> " << field_formatter.code_name.data << ";";

					break;
				}
				default:
				{
					std::string field_source_type = field_type_to_low_level_source_type(engine_platform_build.platform_type, tag_field.field_type);
					ASSERT(!field_formatter.code_name.empty());
					stream << indent << "" << field_source_type << " " << field_formatter.code_name.data << ";";
				}
				}

				constexpr bool k_write_field_types = false;
				switch (tag_field.field_type)
				{
				case _field_pad:
				case _field_skip:
				case _field_useless_pad:
				case _field_custom:
				case _field_terminator:
				case _field_explanation:
				case _field_non_cache_runtime_value:
					break;
				default:
					if (!field_formatter.description.empty() || k_write_field_types)
					{
						stream << " // ";
						if constexpr (k_write_field_types) stream << field_type_string << " ";
						const char* current_pos = field_formatter.description.data;
						while (*current_pos)
						{
							switch (*current_pos)
							{
							case '\n':
								stream << ' ';
								break;
							default:
								stream << *current_pos;
							}
							current_pos++;
						}
					}
					stream << indent << std::endl;
				}

			}
		}

		decrement_indent();
		stream << indent << "};" << std::endl;

		uint32_t struct_size = calculate_struct_size(engine_platform_build, *struct_definition);
		stream << indent << "static_assert(sizeof(" << struct_definition->struct_name << ") == " << std::uppercase << std::dec << __max(1u, struct_size) << ", \"struct " << struct_definition->struct_name << " is invalid size\");" << std::endl;

		stream << indent << std::endl;
	}

	end_namespace_tree(stream, _namespace_tree_write_namespace | _namespace_tree_write_pragma_pack);

	ASSERT(indent.empty());
	std::string source_code = stream.str();
	BCS_RESULT rs = write_output_with_logging(output_header_file_path.c_str(), source_code.data(), source_code.size());
	ASSERT(BCS_SUCCEEDED(rs));
}

void c_low_level_tag_source_generator::generate_ida_header()
{
	std::string namespace_without_semicolons = get_namespace(false);

	std::stringstream stream;

	stream << "#pragma once" << std::endl;
	stream << indent << std::endl;
	stream << "#pragma pack(push, 1)" << std::endl;
	stream << indent << std::endl;

	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		stream << indent << "struct " << struct_definition->struct_name << std::endl;
		stream << indent << "{" << std::endl;

		std::unordered_map<std::string, int> field_name_unique_counter;

		increment_indent();
		for (const s_tag_field* tag_field_iterator = struct_definition->fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
		{
			const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max);

			c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
				tag_field.name,
				tag_field.field_type == blofeld::_field_block,
				&field_name_unique_counter);

			const char* field_type_string;
			ASSERT(BCS_SUCCEEDED(field_to_tagfile_field_type(tag_field.field_type, field_type_string)));

			if (!custom_structure_codegen(_custom_structure_codegen_low_level_header, stream, indent.c_str(), &field_formatter, *struct_definition, tag_field, namespace_without_semicolons.c_str()))
			{
				switch (tag_field.field_type)
				{
				case _field_pad:
					stream << indent << "char " << field_formatter.code_name.c_str() << "[" << tag_field.padding << "]; // padding" << std::endl;
					break;
				case _field_skip:
					stream << indent << "char " << field_formatter.code_name.c_str() << "[" << tag_field.padding << "]; // skip" << std::endl;
					break;
				case _field_useless_pad:
					stream << indent << "// char " << field_formatter.code_name.c_str() << "[" << tag_field.padding << "]; // useless padding" << std::endl;
					break;
				case _field_non_cache_runtime_value:
					stream << indent << "// " << field_formatter.code_name.c_str() << "[" << tag_field.padding << "]; // non cache runtime value" << std::endl;
					break;
				case _field_custom:
					stream << indent << "// " << field_type_string;
					if (!field_formatter.code_name.empty())
					{
						stream << " " << field_formatter.code_name.c_str();
					}
					stream << indent << std::endl;
					break;
				case _field_terminator:
					stream << indent << "// " << field_type_string << std::endl;
					break;
				case _field_explanation:
				{
					if (tag_field.name)
					{
						if (tag_field.explanation && *tag_field.explanation)
						{
							stream << indent << std::endl;
							write_field_description_comment(stream, tag_field);
						}
						else
						{
							stream << indent << std::endl;
							stream << indent << "/* " << tag_field.name << " */" << std::endl << std::endl;
						}
					}
					break;
				}
				case _field_array:
				{
					uint32_t count = tag_field.array_definition->count(engine_platform_build);
					if (count == 0)
					{
						debug_point;
					}
					stream << indent << "" << tag_field.array_definition->struct_definition.struct_name << " " << field_formatter.code_name.c_str() << "[" << count << "];";
					break;
				}
				case _field_struct:
				{
					uint32_t field_struct_size = calculate_struct_size(engine_platform_build, *tag_field.struct_definition);
					if (field_struct_size > 0)
					{
						stream << indent << "" << tag_field.struct_definition->struct_name << " " << field_formatter.code_name.c_str() << ";";
					}
					else
					{
						stream << indent << "// " << tag_field.struct_definition->struct_name << " " << field_formatter.code_name.c_str() << "; // empty struct";
					}
					break;
				}
				case _field_block:
				{
					stream << indent << "s_tag_block " << field_formatter.code_name.c_str() << "; // " << tag_field.block_definition->struct_definition.struct_name;
					break;
				}
				case _field_tag_reference:
				{
					stream << indent << "s_tag_reference " << field_formatter.code_name.c_str() << ";";
					break;
				}
				case _field_char_enum:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "char " << field_formatter.code_name.data << "; // e_" << string_list.name;
					break;
				}
				case _field_short_enum:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "short " << field_formatter.code_name.data << "; // e_" << string_list.name;
					break;
				}
				case _field_long_enum:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "int32_t " << field_formatter.code_name.data << "; // e_" << string_list.name;
					break;
				}
				case _field_byte_flags:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "unsigned char " << field_formatter.code_name.data << "; // " << string_list.name;
					break;
				}
				case _field_word_flags:
				{
					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "unsigned short " << field_formatter.code_name.data << "; // " << string_list.name;
					break;
				}
				case _field_long_flags:
				{

					const blofeld::s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "int32_t " << field_formatter.code_name.data << "; // " << string_list.name;

					break;
				}
				default:
				{
					std::string field_source_type = field_type_to_low_level_source_type(engine_platform_build.platform_type, tag_field.field_type);
					ASSERT(!field_formatter.code_name.empty());
					stream << indent << "" << field_source_type << " " << field_formatter.code_name.data << ";";
				}
				}

				constexpr bool k_write_field_types = false;
				switch (tag_field.field_type)
				{
				case _field_pad:
				case _field_skip:
				case _field_useless_pad:
				case _field_custom:
				case _field_terminator:
				case _field_explanation:
				case _field_non_cache_runtime_value:
					break;
				default:
					if (!field_formatter.description.empty() || k_write_field_types)
					{
						stream << " // ";
						if constexpr (k_write_field_types) stream << field_type_string << " ";
						const char* current_pos = field_formatter.description.data;
						while (*current_pos)
						{
							switch (*current_pos)
							{
							case '\n':
								stream << ' ';
								break;
							default:
								stream << *current_pos;
							}
							current_pos++;
						}
					}
					stream << indent << std::endl;
				}

			}
		}
		decrement_indent();

		stream << indent << "};" << std::endl;
		stream << indent << std::endl;
	}

	stream << indent << "#pragma pack(pop)" << std::endl;
	stream << indent << std::endl;

	ASSERT(indent.empty());
	std::string source_code = stream.str();
	BCS_RESULT rs = write_output_with_logging(output_ida_header_file_path.c_str(), source_code.data(), source_code.size());
	ASSERT(BCS_SUCCEEDED(rs));
}

void c_low_level_tag_source_generator::generate_source()
{
	std::string namespace_without_semicolons = get_namespace(false);

	std::stringstream stream;

	stream << "#include <lowlevel-" << get_engine_namespace(false) << "-" << get_platform_namespace(false) << "-private-pch.h>" << std::endl << std::endl;
	stream << indent << std::endl;

	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		stream << indent << "template<> void byteswap_inplace<" << get_namespace(true) << struct_definition->struct_name << ">(" << get_namespace(true) << struct_definition->struct_name << "& value)" << std::endl;
		stream << indent << "{" << std::endl;

		increment_indent();

		std::unordered_map<std::string, int> field_name_unique_counter;
		for (const s_tag_field* tag_field_iterator = struct_definition->fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
		{
			const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, blofeld::ANY_TAG, tag_field_version_max);
			uint32_t field_index = tag_field_iterator - struct_definition->fields;

			c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
				tag_field.name,
				tag_field.field_type == blofeld::_field_block,
				&field_name_unique_counter);

			const char* field_type_string;
			ASSERT(BCS_SUCCEEDED(field_to_tagfile_field_type(tag_field.field_type, field_type_string)));

			if (!custom_structure_codegen(_custom_structure_codegen_low_level_byteswap, stream, "\t", &field_formatter, *struct_definition, tag_field, namespace_without_semicolons.c_str()))
			{
				switch (tag_field.field_type)
				{
				case _field_pad:
				case _field_skip:
				case _field_useless_pad:
				case _field_custom:
				case _field_terminator:
				case _field_explanation:
				case _field_non_cache_runtime_value:
					break;
				case _field_struct:
				{
					uint32_t field_struct_size = calculate_struct_size(engine_platform_build, *tag_field.struct_definition);
					if (field_struct_size == 0)
					{
						stream << indent << "// byteswap_inplace(value." << field_formatter.code_name.c_str() << "); // empty struct" << std::endl;
						break;
					}
				}
				default:
					stream << indent << "byteswap_inplace(value." << field_formatter.code_name.c_str() << ");" << std::endl;
				}
			}
		}
		decrement_indent();

		stream << indent << "}" << std::endl;
		stream << indent << std::endl;
	}

	ASSERT(indent.empty());
	std::string source_code = stream.str();
	BCS_RESULT rs = write_output_with_logging(output_source_file_path.c_str(), source_code.data(), source_code.size());
	ASSERT(BCS_SUCCEEDED(rs));
}

void c_low_level_tag_source_generator::generate_enum_header()
{
	std::stringstream stream;

	stream << "#pragma once" << std::endl;
	stream << indent << std::endl;
	stream << indent << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace | _namespace_tree_write_pragma_pack);

	std::unordered_map<std::string, int> string_list_value_unique_counter;
	for (const s_string_list_definition* string_list_definition : c_structure_relationship_node::sorted_string_list_definitions[engine_platform_build.engine_type])
	{
		string_list_value_unique_counter.clear();

		uint32_t count = string_list_definition->get_count(engine_platform_build);

		stream << indent << "enum e_" << string_list_definition->name << " : long" << std::endl;
		stream << indent << "{" << std::endl;

		increment_indent();
		for (uint32_t string_index = 0; string_index < count; string_index++)
		{
			const char* string = string_list_definition->get_string(engine_platform_build, string_index);
			c_blamlib_string_parser_v2 string_parser = c_blamlib_string_parser_v2(string, false, &string_list_value_unique_counter);

			stream << indent << "/* " << string_parser.pretty_name.c_str() << " */" << std::endl;

			stream << indent << "_" << string_list_definition->name << "_" << string_parser.code_name.c_str() << ",";
			if (!string_parser.description.empty())
			{
				stream << " /* " << string_parser.description.c_str() << " */" << std::endl;
			}
			stream << indent << std::endl;
		}
		stream << indent << "k_" << string_list_definition->name << "_count" << std::endl;;
		decrement_indent();

		stream << indent << "};" << std::endl;
		stream << indent << std::endl;

	}

	end_namespace_tree(stream, _namespace_tree_write_namespace | _namespace_tree_write_pragma_pack);

	ASSERT(indent.empty());
	std::string source_code = stream.str();
	BCS_RESULT rs = write_output_with_logging(output_enum_header_file_path.c_str(), source_code.data(), source_code.size());
	ASSERT(BCS_SUCCEEDED(rs));
}
