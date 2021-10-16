#include "tagcodegen-private-pch.h"

using namespace blofeld;

c_low_level_tag_source_generator::c_low_level_tag_source_generator(s_engine_platform_build engine_platform_build) :
	engine_platform_build(engine_platform_build),
	has_error(false)
{

}

std::string c_low_level_tag_source_generator::format_structure_symbol(const blofeld::s_tag_struct_definition& struct_definition) const
{
	std::string result = "s_";
	// #TODO: reexport other definitions
	if (engine_platform_build.engine_type == _engine_type_halo3)
	{
		result += struct_definition.struct_name + 2;
	}
	else
	{
		result += struct_definition.name;
	}
	return result;
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
	case _field_tag_reference:						return "s_tag_reference";
	case _field_block:								return "s_tag_block";
	case _field_long_block_flags:					return "long";
	case _field_word_block_flags:					return "word";
	case _field_byte_block_flags:					return "byte";
	case _field_char_block_index:					return "char";
	case _field_custom_char_block_index:			return "char";
	case _field_short_block_index:					return "short";
	case _field_custom_short_block_index:			return "short";
	case _field_long_block_index:					return "long";
	case _field_custom_long_block_index:			return "long";
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
	case _field_pageable:							return "s_tag_resource";
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
		unsigned long pointer_size;
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

void c_low_level_tag_source_generator::generate_header() const
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
	stream << "\t{" << std::endl;
	stream << "#pragma pack(push, 1)" << std::endl << std::endl;

	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		std::string low_level_structure_name = format_structure_symbol(*struct_definition);

		stream << "\t\tstruct " << low_level_structure_name << std::endl;
		stream << "\t\t{" << std::endl;

		std::map<std::string, int> field_name_unique_counter;

		for (const s_tag_field* current_field = struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			unsigned long field_skip_count;
			if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			std::map<std::string, int>* field_name_unique_counter_ptr = nullptr;
			switch (current_field->field_type)
			{
			case _field_custom:
				break;
			default:
				field_name_unique_counter_ptr = &field_name_unique_counter;
				break;
			}

			c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
				current_field->name,
				current_field->field_type == blofeld::_field_block,
				&field_name_unique_counter);

			const char* field_type_string;
			ASSERT(BCS_SUCCEEDED(field_to_tag_field_type(current_field->field_type, field_type_string)));

			if (!custom_structure_codegen(_custom_structure_codegen_low_level_header, stream, "\t\t\t", &field_formatter, *struct_definition, *current_field, namespace_name))
			{
				switch (current_field->field_type)
				{
				case _field_pad:
					stream << "\t\t\tchar " << field_formatter.code_name.c_str() << "[" << current_field->padding << "]; // padding" << std::endl;
					break;
				case _field_skip:
					stream << "\t\t\tchar " << field_formatter.code_name.c_str() << "[" << current_field->padding << "]; // skip" << std::endl;
					break;
				case _field_useless_pad:
					stream << "\t\t\t// char " << field_formatter.code_name.c_str() << "[" << current_field->padding << "]; // useless padding" << std::endl;
					break;
				case _field_non_cache_runtime_value:
					stream << "\t\t\t// " << field_formatter.code_name.c_str() << "[" << current_field->padding << "]; // non cache runtime value" << std::endl;
					break;
				case _field_custom:
					stream << "\t\t\t// " << field_type_string;
					if (!field_formatter.code_name.empty())
					{
						stream << " " << field_formatter.code_name.c_str();
					}
					stream << std::endl;
					break;
				case _field_terminator:
					stream << "\t\t\t// " << field_type_string << std::endl;
					break;
				case _field_explanation:
				{
					if (current_field->name)
					{
						if (current_field->explanation && *current_field->explanation)
						{
							stream << std::endl << "\t\t\t/* " << current_field->name << std::endl;
							stream << "\t\t\t ";
							const char* current_pos = current_field->explanation;
							while (*current_pos)
							{
								switch (*current_pos)
								{
								case '\n':
									stream << *current_pos;
									stream << "\t\t\t ";
									break;
								default:
									stream << *current_pos;
								}
								current_pos++;
							}
							stream << std::endl;
							stream << "\t\t\t*/" << std::endl << std::endl;
						}
						else
						{
							stream << std::endl << "\t\t\t/* " << current_field->name << " */" << std::endl << std::endl;
						}
					}
					break;
				}
				case _field_array:
				{

					std::string field_source_type = format_structure_symbol(current_field->array_definition->struct_definition);
					unsigned long count = current_field->array_definition->count(engine_platform_build);
					if (count == 0)
					{
						debug_point;
					}
					stream << "\t\t\t" << field_source_type << " " << field_formatter.code_name.c_str() << "[" << count << "];";
					break;
				}
				case _field_struct:
				{
					unsigned long field_struct_size = calculate_struct_size(engine_platform_build, *current_field->struct_definition);
					std::string field_source_type = format_structure_symbol(*current_field->struct_definition);
					if (field_struct_size > 0)
					{
						stream << "\t\t\t" << field_source_type << " " << field_formatter.code_name.c_str() << "; // test";
					}
					else
					{
						stream << "\t\t\t// " << field_source_type << " " << field_formatter.code_name.c_str() << "; // empty struct";
					}
					break;
				}
				case _field_block:
				{
					std::string field_source_type = format_structure_symbol(current_field->block_definition->struct_definition);
					stream << "\t\t\tc_typed_tag_block<" << field_source_type << "> " << field_formatter.code_name.c_str() << ";";
					break;
				}
				case _field_tag_reference:
				{
					//if (current_field->tag_reference_definition == nullptr)
					//{
					//	console_write_line("%s(%i): error TSG0001: _field_tag_reference is null", current_field->filename, current_field->line);
					//	has_error = true;
					//}
					//else
					{
						bool handled = false;

						std::vector<unsigned long> group_tags;
						if (current_field->tag_reference_definition)
						{
							long group_tag = current_field->tag_reference_definition->group_tag;
							unsigned long group_tag_count = current_field->tag_reference_definition->group_tag;

							if (current_field->tag_reference_definition->group_tag != INVALID_TAG)
							{
								group_tags.emplace_back(current_field->tag_reference_definition->group_tag);
							}
							else if (current_field->tag_reference_definition->group_tags)
							{
								for (const unsigned long* current_group_tag = current_field->tag_reference_definition->group_tags; *current_group_tag != INVALID_TAG; current_group_tag++)
								{
									group_tags.push_back(*current_group_tag);
								}
							}
						}

						if (group_tags.empty())
						{
							stream << "\t\t\ts_tag_reference " << field_formatter.code_name.c_str() << ";";
						}
						else
						{

							stream << "\t\t\tc_typed_tag_reference<";

							for (size_t group_tag_index = 0; group_tag_index < group_tags.size(); group_tag_index++)
							{
								const s_tag_group* tag_group = get_tag_group_by_group_tag(engine_platform_build.engine_type, group_tags[group_tag_index]);
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

								stream << tag_group->group_tag_code_string;
							}
							stream << "> " << field_formatter.code_name.c_str() << ";";
						}
					}

					break;
				}
				case _field_char_enum:
				{
					const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
					stream << "\t\t\tc_enum<e_" << string_list.name << ", char> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_enum:
				{
					const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
					stream << "\t\t\tc_enum<e_" << string_list.name << ", short> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_long_enum:
				{
					const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
					stream << "\t\t\tc_enum<e_" << string_list.name << ", long> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_byte_flags:
				{
					const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
					stream << "\t\t\tc_flags<e_" << string_list.name << ", char, k_" << string_list.name << "_count> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_word_flags:
				{
					const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
					stream << "\t\t\tc_flags<e_" << string_list.name << ", short, k_" << string_list.name << "_count> " << field_formatter.code_name.data << ";";
					break;
				}
				case _field_long_flags:
				{

					const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
					stream << "\t\t\tc_flags<e_" << string_list.name << ", long, k_" << string_list.name << "_count> " << field_formatter.code_name.data << ";";

					break;
				}
				default:
				{
					std::string field_source_type = field_type_to_low_level_source_type(engine_platform_build.platform_type, current_field->field_type);
					ASSERT(!field_formatter.code_name.empty());
					stream << "\t\t\t" << field_source_type << " " << field_formatter.code_name.data << ";";
				}
				}

				constexpr bool k_write_field_types = false;
				switch (current_field->field_type)
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
					stream << std::endl;
				}

			}
		}

		stream << "\t\t};" << std::endl;

		unsigned long struct_size = calculate_struct_size(engine_platform_build, *struct_definition);

		// stream << "\t\tstatic constexpr size_t " << tag_struct_definition->name << "_size = sizeof(s_" << tag_struct_definition->name << ");" << std::endl;
		// stream << "\t\tstatic_assert(" << tag_struct_definition->name << "_size == " << std::uppercase << std::dec << __max(1u, struct_size) << ", \"struct s_" << tag_struct_definition->name << " is invalid size\");" << std::endl;

		stream << "\t\tstatic_assert(sizeof(" << low_level_structure_name << ") == " << std::uppercase << std::dec << __max(1u, struct_size) << ", \"struct " << low_level_structure_name << " is invalid size\");" << std::endl;

		stream << std::endl;


	}

	stream << "#pragma pack(pop)" << std::endl;
	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;



	std::string source_code = stream.str();
	const char* output;
	ASSERT(BCS_SUCCEEDED(command_line_get_argument("output", output)));
	std::string output_filepath = std::string(output) + "LowLevel/low_level_" + namespace_name + "/" + namespace_name + ".h";

	BCS_RESULT rs = write_output_with_logging(output_filepath.c_str(), source_code.data(), source_code.size());
	ASSERT(BCS_SUCCEEDED(rs));
}

void c_low_level_tag_source_generator::generate_source() const
{
	std::stringstream stream;

	const char* namespace_name;
	BCS_RESULT engine_type_to_folder_name_result = get_engine_type_folder_string(engine_platform_build.engine_type, &namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result));

	const char* source_namespace_name;
	BCS_RESULT engine_type_to_folder_name_result2 = get_engine_type_source_string(engine_platform_build.engine_type, &source_namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result2));

	stream << "#include <lowlevel-" << source_namespace_name << "-private-pch.h>" << std::endl << std::endl;
	stream << std::endl;
	stream << std::endl;

	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		std::string low_level_structure_name = format_structure_symbol(*struct_definition);

		stream << "template<> void byteswap<blofeld::" << namespace_name << "::" << low_level_structure_name << ">(blofeld::" << namespace_name << "::" << low_level_structure_name << "& value)" << std::endl;
		stream << "{" << std::endl;

		std::map<std::string, int> field_name_unique_counter;

		for (const s_tag_field* current_field = struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			unsigned long field_skip_count;
			if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			std::map<std::string, int>* field_name_unique_counter_ptr = nullptr;
			switch (current_field->field_type)
			{
			case _field_custom:
				break;
			default:
				field_name_unique_counter_ptr = &field_name_unique_counter;
				break;
			}

			c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
				current_field->name,
				current_field->field_type == blofeld::_field_block,
				&field_name_unique_counter);

			const char* field_type_string;
			ASSERT(BCS_SUCCEEDED(field_to_tag_field_type(current_field->field_type, field_type_string)));

			if (!custom_structure_codegen(_custom_structure_codegen_low_level_byteswap, stream, "\t", &field_formatter, *struct_definition, *current_field, namespace_name))
			{
				switch (current_field->field_type)
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
					unsigned long field_struct_size = calculate_struct_size(engine_platform_build, *current_field->struct_definition);
					if (field_struct_size == 0)
					{
						stream << "\t// byteswap(value." << field_formatter.code_name.c_str() << "); // empty struct" << std::endl;
						break;
					}
				}
				default:
					stream << "\tbyteswap(value." << field_formatter.code_name.c_str() << ");" << std::endl;
				}
			}
		}

		stream << "}" << std::endl;

		stream << std::endl;
	}

	std::string source_code = stream.str();	const char* output;
	ASSERT(BCS_SUCCEEDED(command_line_get_argument("output", output)));
	std::string output_filepath = std::string(output) + "LowLevel/low_level_" + namespace_name + "/" + namespace_name + ".cpp";

	BCS_RESULT rs = write_output_with_logging(output_filepath.c_str(), source_code.data(), source_code.size());
	ASSERT(BCS_SUCCEEDED(rs));
}

void c_low_level_tag_source_generator::generate_enum_header() const
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
	stream << "\t{" << std::endl;
	stream << "#pragma pack(push, 1)" << std::endl << std::endl;

	std::map<std::string, int> string_list_value_unique_counter;
	for (const s_string_list_definition* string_list_definition : c_structure_relationship_node::sorted_string_list_definitions[engine_platform_build.engine_type])
	{
		string_list_value_unique_counter.clear();

		unsigned long count = string_list_definition->get_count(engine_platform_build);

		stream << "\t\tenum e_" << string_list_definition->name << " : long" << std::endl;
		stream << "\t\t{" << std::endl;

		for (unsigned long string_index = 0; string_index < count; string_index++)
		{
			const char* string = string_list_definition->get_string(engine_platform_build, string_index);
			c_blamlib_string_parser_v2 string_parser = c_blamlib_string_parser_v2(string, false, &string_list_value_unique_counter);

			stream << "\t\t\t/* " << string_parser.name.c_str() << " */" << std::endl;

			stream << "\t\t\t_" << string_list_definition->name << "_" << string_parser.code_name.c_str() << ",";
			if (!string_parser.description.empty())
			{
				stream << " /* " << string_parser.description.c_str() << " */" << std::endl;
			}
			stream << std::endl;
		}
		stream << "\t\t\tk_" << string_list_definition->name << "_count" << std::endl;;

		stream << "\t\t};" << std::endl;
		stream << std::endl;

	}

	stream << "#pragma pack(pop)" << std::endl;
	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = stream.str();	const char* output;
	ASSERT(BCS_SUCCEEDED(command_line_get_argument("output", output)));
	std::string output_filepath = std::string(output) + "LowLevel/low_level_" + namespace_name + "/" + namespace_name + ".enum.h";

	BCS_RESULT rs = write_output_with_logging(output_filepath.c_str(), source_code.data(), source_code.size());
	ASSERT(BCS_SUCCEEDED(rs));
}
