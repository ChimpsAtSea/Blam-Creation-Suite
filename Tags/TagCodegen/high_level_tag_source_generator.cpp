#include "tagcodegen-private-pch.h"

using namespace blofeld;

c_high_level_tag_source_generator::c_high_level_tag_source_generator(s_engine_platform_build _engine_platform_build) :
	c_source_generator_base(_engine_platform_build),
	output_directory(),
	output_header_file_path(),
	output_source_file_path(),
	output_forward_declare_file_path(),
	output_virtual_file_path(),
	output_misc_file_path()
{
	const char* _output_directory;
	if (BCS_SUCCEEDED(command_line_get_argument("output", _output_directory))) // #TODO: rename to 'output-directory'
	{
		std::stringstream output_directory_stream;
		output_directory_stream << _output_directory << "high_level_" << get_engine_namespace(false) << "_" + get_platform_namespace(false);
		output_directory = output_directory_stream.str();

		std::stringstream output_header_file_path_stream;
		output_header_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + ".h";
		output_header_file_path = output_header_file_path_stream.str();

		std::stringstream output_virtual_file_path_stream;
		output_virtual_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + "_virtual.cpp";
		output_virtual_file_path = output_virtual_file_path_stream.str();

		std::stringstream output_misc_file_path_stream;
		output_misc_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + "_misc.cpp";
		output_misc_file_path = output_misc_file_path_stream.str();

		std::stringstream output_source_file_path_stream;
		output_source_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + ".cpp";
		output_source_file_path = output_source_file_path_stream.str();

		std::stringstream output_forward_declare_file_path_stream;
		output_forward_declare_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + "_forward_declare.h";
		output_forward_declare_file_path = output_forward_declare_file_path_stream.str();
	}
}

c_high_level_tag_source_generator::~c_high_level_tag_source_generator()
{
}

std::string c_high_level_tag_source_generator::format_structure_symbol(const s_tag_struct_definition& struct_definition)
{
	const char* low_level_type_name = struct_definition.type_name;
	if (strstr(low_level_type_name, "s_") != low_level_type_name)
	{
		console_write_line("Warning: Structure symbol '%s' doesn't start with 's_' prefix [%s]", struct_definition.symbol_name, low_level_type_name);
		std::string high_level_type_name = "h_";
		high_level_type_name += low_level_type_name;
		return high_level_type_name;
	}
	else
	{
		std::string high_level_type_name = low_level_type_name;
		high_level_type_name[0] = 'h';
		return high_level_type_name;
	}
}

const s_tag_group* c_high_level_tag_source_generator::get_tag_struct_tag_group(const s_tag_struct_definition& struct_definition)
{
	t_tag_group_collection tag_group_collection;
	BCS_RESULT rs = tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_group_collection);
	if (BCS_SUCCEEDED(rs))
	{
		for (t_tag_group_iterator tag_group_iterator = tag_group_collection; *tag_group_iterator; tag_group_iterator++)
		{
			s_tag_group const& tag_group = **tag_group_iterator;

			const s_tag_struct_definition& current_struct_definition = tag_group.block_definition.struct_definition;

			if (&current_struct_definition == &struct_definition)
			{
				return &tag_group;
			}
		}
	}

	return nullptr;
}

unsigned int c_high_level_tag_source_generator::get_tag_struct_version(const s_tag_struct_definition& struct_definition)
{
	uint32_t struct_version = 0;
	if (struct_definition.runtime_flags.test(_tag_field_set_mandrill_has_versioning))
	{
		for (const s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
		{
			const s_tag_field& tag_field = *tag_field_iterator;
			if (tag_field.field_type == _field_version && tag_field.versioning.mode == _struct_version_mode_greater_or_equal)
			{
				struct_version = __max(struct_version, tag_field.versioning.struct_version);
			}
		}
	}
	return struct_version;
}

const char* c_high_level_tag_source_generator::field_type_to_high_level_source_type(e_platform_type platform_type, e_field field_type)
{
	switch (field_type)
	{
	case _field_string:								return "c_fixed_string_32";
	case _field_long_string:						return "c_fixed_string_256";
	case _field_string_id:							return "h_string_id";
	case _field_old_string_id:						return "h_string_id";
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
	case _field_tag_reference:						return "h_tag*";
	case _field_block:								return "h_block";
	case _field_long_block_flags:					return "int32_t";
	case _field_word_block_flags:					return "word";
	case _field_byte_block_flags:					return "byte";
	case _field_char_block_index:					return "char";
	case _field_char_block_index_custom_search:		return "char";
	case _field_short_block_index:					return "short";
	case _field_short_block_index_custom_search:	return "short";
	case _field_long_block_index:					return "int32_t";
	case _field_long_block_index_custom_search:		return "int32_t";
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
	case _field_pageable_resource:					return "h_resource*";
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

void c_high_level_tag_source_generator::generate_header()
{
	std::string namespace_without_semicolons = get_namespace(false);

	std::stringstream stream;

	stream << "#pragma once" << std::endl;
	stream << std::endl;

	std::stringstream header_define_stream;
	header_define_stream << "high_level_" << get_engine_namespace(false) << "_" << get_platform_namespace(false);
	std::string header_define = header_define_stream.str();
	std::transform(header_define.begin(), header_define.end(), header_define.begin(), ::toupper);
	stream << "#define " << header_define << std::endl;
	stream << indent << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace);

	stream << indent << "BCS_SHARED extern h_tag* create_high_level_tag(h_group& group, const char* tag_filepath);" << std::endl;
	stream << indent << "BCS_SHARED extern h_prototype* create_high_level_object(const s_tag_struct_definition& tag_struct_definition);" << std::endl;
	stream << indent << std::endl;

	std::unordered_map<std::string, int> field_name_unique_counter;
	union
	{
		struct
		{
			uint32_t engine_platform_build_hash;
			int32_t structure_index;
		};
		uint64_t structure_guid;
	};
	engine_platform_build_hash = XXH32(&engine_platform_build, sizeof(engine_platform_build), 0);
	structure_index = -1;
	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		structure_index++;
		const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

		//if (struct_definition == &rasterizer_compiled_shader_struct_struct_definition)
		//{
		//	debug_point;
		//}

		uint32_t blofeld_field_list_size = 1;
		for (const s_tag_field* tag_field_iterator = struct_definition->fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
		{
			const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, ANY_TAG, tag_field_version_all);

			if (tag_field.field_type >= k_number_of_blofeld_field_types)
			{
				continue;
			}

			blofeld_field_list_size++;
		}

		std::string high_level_structure_name = format_structure_symbol(*struct_definition);

		stream << indent << "class " << high_level_structure_name << " : " << std::endl;
		increment_indent();
		if (tag_group != nullptr)
		{
			stream << indent << "\t" << "public h_tag" << std::endl;
		}
		else
		{
			stream << indent << "\t" << "public h_prototype" << std::endl;
		}
		decrement_indent();
		stream << indent << "{" << std::endl;
		increment_indent();
		stream << indent << "\t" << "public:" << std::endl;
		increment_indent();
		stream << indent << "\t\t" << "friend class std::vector<" << high_level_structure_name << ">;" << std::endl;

		if (tag_group != nullptr)
		{
			stream << indent << "\t\t" << "BCS_SHARED " << high_level_structure_name << "(h_group& group, const char* tag_filepath);" << std::endl;
			stream << indent << "\t\t" << "BCS_SHARED " << high_level_structure_name << "(h_type* parent = nullptr);" << std::endl;
		}
		else
		{
			stream << indent << "\t\t" << "BCS_SHARED " << high_level_structure_name << "(h_type* parent = nullptr);" << std::endl;
		}
		stream << std::endl;

		if (tag_group != nullptr)
		{
			stream << indent << "\t\t" << "virtual const s_tag_group& get_blofeld_group_definition() const;" << std::endl;
		}

		//if (struct_definition->runtime_flags.test(_tag_field_set_mandrill_has_versioning))
		{
			stream << indent << "\t\t" << "virtual uint32_t get_version() const override;" << std::endl;
		}
		stream << indent << "\t\t" << "virtual const void* get_field_data_unsafe(const s_tag_field& field) const override;" << std::endl;
		stream << indent << "\t\t" << "virtual void* get_field_data_unsafe(const s_tag_field& field) override;" << std::endl;
		stream << indent << "\t\t" << "virtual bool is_field_active(const s_tag_field& field) const override;" << std::endl;
		stream << indent << "\t\t" << "virtual const s_tag_struct_definition& get_blofeld_struct_definition() const override;" << std::endl;
		stream << indent << "\t\t" << "virtual const s_tag_field* const* get_blofeld_field_list() const override;" << std::endl;
		stream << indent << "\t\t" << "virtual const s_tag_field* const* get_blofeld_field_list_deprecated() const override;" << std::endl;

		stream << std::endl;

		stream << indent << "\t\t" << "static const s_tag_struct_definition& tag_struct_definition;" << std::endl;

		stream << std::endl;

		for (const s_tag_field* tag_field_iterator = struct_definition->fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
		{
			const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, ANY_TAG, tag_field_version_all);
			uint32_t field_index = tag_field_iterator - struct_definition->fields;

			if (tag_field.field_type >= k_number_of_blofeld_field_types)
			{
				continue;
			}

			switch (tag_field.field_type)
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

			c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
				tag_field.name,
				tag_field.field_type == _field_block,
				&field_name_unique_counter);

			if (!custom_structure_codegen(_custom_structure_codegen_high_level_header, stream, indent.c_str(), &field_formatter, *struct_definition, tag_field, namespace_without_semicolons.c_str()))
			{

				switch (tag_field.field_type)
				{
				case _field_array:
				{
					std::string field_source_type = format_structure_symbol(tag_field.array_definition->struct_definition);
					stream << indent << "\t\t" << "h_typed_array<" << field_source_type << ", " << tag_field.array_definition->element_count(engine_platform_build) << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_struct:
				{
					std::string field_source_type = format_structure_symbol(*tag_field.struct_definition);
					stream << indent << "\t\t" << field_source_type << " " << field_formatter.code_name.c_str() << ";";
					break;
				}
				case _field_block:
				{
					std::string field_source_type = format_structure_symbol(tag_field.block_definition->struct_definition);
					stream << indent << "\t\t" << "h_typed_block<" << field_source_type << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_data:
				{
					stream << indent << "\t\t" << "h_data " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_long_flags:
				case _field_word_flags:
				case _field_byte_flags:
				{
					const s_string_list_definition& string_list = *tag_field.string_list_definition;

					stream << indent << "\t\t" << "h_field_flags<e_" << string_list.name << ", " << high_level_structure_name << ", " << field_index << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_char_enum:
				case _field_short_enum:
				case _field_long_enum:
				{
					const s_string_list_definition& string_list = *tag_field.string_list_definition;
					stream << indent << "\t\t" << "h_field<e_" << string_list.name << ", " << high_level_structure_name << ", " << field_index << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_pageable_resource:
				{
					const char* field_source_type = field_type_to_high_level_source_type(engine_platform_build.platform_type, tag_field.field_type);
					ASSERT(field_source_type != nullptr);
					std::string struct_field_source_type = format_structure_symbol(tag_field.tag_resource_definition->struct_definition);
					stream << indent << "\t\t" << "h_resource_field<" << struct_field_source_type << ", " << high_level_structure_name << ", " << field_index << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				case _field_tag_reference:
				{
					stream << indent << "\t\t" << "h_tag_reference_field<" << high_level_structure_name << ", " << field_index << "> " << field_formatter.code_name.c_str() << ";";
				}
				break;
				default:
				{
					const char* field_source_type = field_type_to_high_level_source_type(engine_platform_build.platform_type, tag_field.field_type);
					ASSERT(field_source_type != nullptr);
					stream << indent << "\t\t" << "h_field<" << field_source_type << ", " << high_level_structure_name << ", " << field_index << "> " << field_formatter.code_name.c_str() << ";";
				}
				}
				stream << std::endl;

			}

		}
		field_name_unique_counter.clear();

		decrement_indent(); // end public:
		decrement_indent();
		stream << indent << "};" << std::endl;

		stream << std::endl;
	}

	end_namespace_tree(stream, _namespace_tree_write_namespace);

	ASSERT(indent.empty());
	std::string source_code = stream.str();

	if (!output_header_file_path.empty())
	{
		BCS_RESULT rs = write_output_with_logging(output_header_file_path.c_str(), source_code.data(), source_code.size());
		ASSERT(BCS_SUCCEEDED(rs));
	}
}

void c_high_level_tag_source_generator::generate_forward_declare()
{
	std::string namespace_without_semicolons = get_namespace(false);

	std::stringstream stream;

	stream << "#pragma once" << std::endl;
	stream << std::endl;

	std::stringstream header_define_stream;
	header_define_stream << "high_level_" << get_engine_namespace(false) << "_" << get_platform_namespace(false);
	std::string header_define = header_define_stream.str();
	std::transform(header_define.begin(), header_define.end(), header_define.begin(), ::toupper);
	stream << "#define " << header_define << std::endl;
	stream << indent << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace);

	stream << indent << "BCS_SHARED extern h_tag* create_high_level_tag(h_group& group, const char* tag_filepath);" << std::endl;
	stream << indent << "BCS_SHARED extern h_prototype* create_high_level_object(const s_tag_struct_definition& tag_struct_definition);" << std::endl;
	stream << indent << std::endl;

	std::unordered_map<std::string, int> field_name_unique_counter;
	union
	{
		struct
		{
			uint32_t engine_platform_build_hash;
			int32_t structure_index;
		};
		uint64_t structure_guid;
	};
	engine_platform_build_hash = XXH32(&engine_platform_build, sizeof(engine_platform_build), 0);
	structure_index = -1;
	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		structure_index++;
		const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

		//if (struct_definition == &rasterizer_compiled_shader_struct_struct_definition)
		//{
		//	debug_point;
		//}

		uint32_t blofeld_field_list_size = 1;
		for (const s_tag_field* tag_field_iterator = struct_definition->fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
		{
			const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, ANY_TAG, tag_field_version_all);

			if (tag_field.field_type >= k_number_of_blofeld_field_types)
			{
				continue;
			}

			blofeld_field_list_size++;
		}

		std::string high_level_structure_name = format_structure_symbol(*struct_definition);

		stream << indent << "class " << high_level_structure_name << ";" << std::endl;
	}
	stream << std::endl;

	end_namespace_tree(stream, _namespace_tree_write_namespace);

	ASSERT(indent.empty());
	std::string source_code = stream.str();
	if (!output_forward_declare_file_path.empty())
	{
		BCS_RESULT rs = write_output_with_logging(output_forward_declare_file_path.c_str(), source_code.data(), source_code.size());
		ASSERT(BCS_SUCCEEDED(rs));
	}
}

void c_high_level_tag_source_generator::generate_tag_constructor_params(std::stringstream& stream, const s_tag_struct_definition& struct_definition)
{
	std::unordered_map<std::string, int> field_name_unique_counter;
	increment_indent();
	for (const s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
	{
		const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, ANY_TAG, tag_field_version_all);

		if (tag_field.field_type >= k_number_of_blofeld_field_types)
		{
			continue;
		}

		switch (tag_field.field_type)
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

		c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
			tag_field.name,
			tag_field.field_type == _field_block,
			&field_name_unique_counter);

		if (!custom_structure_codegen(_custom_structure_codegen_high_level_ctor, stream, indent.c_str(), &field_formatter, struct_definition, tag_field, nullptr))
		{
			stream << "," << std::endl;

			switch (tag_field.field_type)
			{
			case _field_tag_reference:
			case _field_array:
			case _field_block:
			{
				stream << indent << field_formatter.code_name.c_str() << "(this)";
				break;
			}
			case _field_struct:
			{
				const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_field.struct_definition);

				std::string field_source_type = format_structure_symbol(*tag_field.struct_definition);
				if (tag_group)
				{
					stream << indent << field_formatter.code_name.c_str() << "()";
				}
				else
				{
					stream << indent << field_formatter.code_name.c_str() << "()";
				}

				break;
			}
			case _field_char_block_index:
			case _field_short_block_index:
			case _field_long_block_index:
			{
				stream << indent << field_formatter.code_name.c_str() << "(-1)";
				break;
			}
			default:
			{
				stream << indent << field_formatter.code_name.c_str() << "()";
				break;
			}
			}
		}
	}
	decrement_indent();
}

void c_high_level_tag_source_generator::generate_ctor_source(uint32_t source_index, uint32_t source_count)
{
	std::string namespace_without_semicolons = get_namespace(false);

	std::stringstream stream;

	stream << "#include <highlevel-" << get_engine_namespace(false) << "-" << get_platform_namespace(false) << "-private-pch.h>" << std::endl;
	stream << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_intellisense | _namespace_tree_write_warnings);

	{
		uint32_t structure_index = 0;
		for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			if ((structure_index++ % source_count) == source_index)
			{
				std::string high_level_structure_name = format_structure_symbol(*struct_definition);

				stream << "_h_typed_block_ctor_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_get_tag_struct_definition_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_array_operator_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_get_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_data_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_size_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_data_size_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_emplace_back_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_emplace_back_alt_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_reserve_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_resize_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_insert_hole_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_remove_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << "_h_typed_block_clear_impl(" << get_namespace(true) << high_level_structure_name << ");" << std::endl;
				stream << std::endl;
			}
		}
	}
	stream << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace);

	{
		std::unordered_map<std::string, int> field_name_unique_counter;
		uint32_t structure_index = 0;
		for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			if ((structure_index++ % source_count) == source_index)
			{
				std::string high_level_structure_name = format_structure_symbol(*struct_definition);

				const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

				if (tag_group != nullptr)
				{
					stream << indent << high_level_structure_name << "::" << high_level_structure_name;
					stream << "(h_group& group, const char* tag_filepath) :" << std::endl;
					stream << indent << "\t" << "h_tag(&group, tag_filepath)";
					generate_tag_constructor_params(stream, *struct_definition);
					stream << std::endl;
					stream << indent << "{" << std::endl;
					stream << indent << "\t" << "high_level_tag_ctor(this);" << std::endl;
					stream << indent << "}" << std::endl;
					stream << std::endl;

					stream << indent << high_level_structure_name << "::" << high_level_structure_name;
					stream << "(h_type* parent) :" << std::endl;
					stream << indent << "\t" << "h_tag(parent)";
					generate_tag_constructor_params(stream, *struct_definition);
					stream << std::endl;
					stream << indent << "{" << std::endl;
					stream << indent << "\t" << "high_level_tag_ctor(this);" << std::endl;
					stream << indent << "}" << std::endl;
					stream << std::endl;
				}
				else
				{
					stream << indent << high_level_structure_name << "::" << high_level_structure_name;
					stream << "(h_type* parent) :" << std::endl;
					stream << indent << "\t" << "h_prototype(parent)";
					generate_tag_constructor_params(stream, *struct_definition);
					stream << std::endl;
					stream << indent << "{" << std::endl;
					stream << indent << "\t" << "high_level_tag_ctor(this);" << std::endl;
					stream << indent << "}" << std::endl;
					stream << std::endl;
				}
			}
		}
	}

	end_namespace_tree(stream, _namespace_tree_write_namespace);
	stream << std::endl;

	{
		std::unordered_map<std::string, int> field_name_unique_counter;
		uint32_t structure_index = 0;
		for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			if ((structure_index++ % source_count) == source_index)
			{

				const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

				for (const s_tag_field* tag_field_iterator = struct_definition->fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
				{
					const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, ANY_TAG, tag_field_version_all);
					uint32_t field_index = tag_field_iterator - struct_definition->fields;

					if (tag_field.field_type >= k_number_of_blofeld_field_types)
					{
						continue;
					}

					switch (tag_field.field_type)
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

					c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
						tag_field.name,
						tag_field.field_type == _field_block,
						&field_name_unique_counter);

					if (!custom_structure_codegen(_custom_structure_codegen_high_level_field_impl, stream, indent.c_str(), &field_formatter, *struct_definition, tag_field, namespace_without_semicolons.c_str()))
					{
						std::string high_level_structure_name = format_structure_symbol(*struct_definition);


						std::stringstream field_type_stream;
						std::stringstream field_type_stream2;

						switch (tag_field.field_type)
						{
						case _field_array:
						{
							std::string field_source_type = format_structure_symbol(tag_field.array_definition->struct_definition);
							stream << "using t_" << high_level_structure_name << "_" << field_formatter.code_name.c_str() << " = " << "h_typed_array<" << get_namespace(true) << field_source_type << ", " << tag_field.array_definition->element_count(engine_platform_build) << ">;" << std::endl;

							field_type_stream << "t_" << high_level_structure_name << "_" << field_formatter.code_name.c_str();
							break;
						}
						case _field_struct:
						{
							std::string field_source_type = format_structure_symbol(*tag_field.struct_definition);

							field_type_stream << get_namespace(true) << field_source_type;
							break;
						}
						case _field_block:
						{
							std::string field_source_type = format_structure_symbol(tag_field.block_definition->struct_definition);

							field_type_stream << "h_typed_block<" << get_namespace(true) << field_source_type << ">";
							break;
						}
						case _field_data:
						{
							field_type_stream << "h_data";
							break;
						}
						case _field_tag_reference:
						{
							field_type_stream << "h_tag*";
							break;
						}
						case _field_long_flags:
						case _field_word_flags:
						case _field_byte_flags:
						{
							const s_string_list_definition& string_list = *tag_field.string_list_definition;
							stream << "using t_" << high_level_structure_name << "_" << field_formatter.code_name.c_str() << " = c_flags<" << get_namespace(true) << "e_" << string_list.name << ", qword>;" << std::endl;
							field_type_stream << "t_" << high_level_structure_name << "_" << field_formatter.code_name.c_str();
							field_type_stream2 << get_namespace(true) << "e_" << string_list.name;
							break;
						}
						case _field_char_enum:
						case _field_short_enum:
						case _field_long_enum:
						{
							const s_string_list_definition& string_list = *tag_field.string_list_definition;
							field_type_stream << get_namespace(true) << "e_" << string_list.name;

							break;
						}
						default:
						{
							const char* field_source_type = field_type_to_high_level_source_type(engine_platform_build.platform_type, tag_field.field_type);
							ASSERT(field_source_type != nullptr);
							field_type_stream << field_source_type;
							break;
						}
						}

						std::stringstream args_stream;
						args_stream << field_type_stream.str() << ", " << get_namespace(true) << high_level_structure_name << ", " << field_index << ", " << field_formatter.code_name.c_str();
						std::string args = args_stream.str();

						stream << "h_field_func_impl_cast_const(" << args << ");" << std::endl;
						stream << "h_field_func_impl_cast(" << args << ");" << std::endl;
						stream << "h_field_func_impl_rvalue_assignment(" << args << ");" << std::endl;
						stream << "h_field_func_impl_lvalue_assignment(" << args << ");" << std::endl;
						stream << "h_field_func_impl_rvalue_equality(" << args << ");" << std::endl;
						stream << "h_field_func_impl_lvalue_equality(" << args << ");" << std::endl;
						stream << "h_field_func_impl_rvalue_inequality(" << args << ");" << std::endl;
						stream << "h_field_func_impl_lvalue_inequality(" << args << ");" << std::endl;
						stream << "h_field_func_impl_pointer_const(" << args << ");" << std::endl;
						stream << "h_field_func_impl_pointer(" << args << ");" << std::endl;
						
						switch (tag_field.field_type)
						{
						case _field_long_flags:
						case _field_word_flags:
						case _field_byte_flags:
						{
							std::stringstream flags_args_stream;
							flags_args_stream << field_type_stream2.str() << ", " << get_namespace(true) << high_level_structure_name << ", " << field_index << ", " << field_formatter.code_name.c_str();
							std::string flags_args = flags_args_stream.str();

							stream << "h_field_enum_func_impl_or(" << flags_args << ");" << std::endl;
							stream << "h_field_enum_func_impl_is_clear(" << flags_args << ");" << std::endl;
							stream << "h_field_enum_func_impl_xor(" << flags_args << ");" << std::endl;
							stream << "h_field_enum_func_impl_clear(" << flags_args << ");" << std::endl;
							stream << "h_field_enum_func_impl_test(" << flags_args << ");" << std::endl;
							stream << "h_field_enum_func_impl_set(" << flags_args << ");" << std::endl;
							stream << "h_field_enum_func_impl_valid(" << flags_args << ");" << std::endl;

							break;
						}
						}

					}

				}
				field_name_unique_counter.clear();

				stream << std::endl;
			}
		}
	}

	end_namespace_tree(stream, _namespace_tree_write_intellisense | _namespace_tree_write_warnings);

	std::string source_code = stream.str();
	if (!output_directory.empty())
	{
		std::stringstream output_constructor_file_path_stream;
		output_constructor_file_path_stream << output_directory << "\\" << get_engine_namespace(false) << "_" + get_platform_namespace(false) + "_constructor" << source_index << ".cpp";
		std::string output_constructor_file_path = output_constructor_file_path_stream.str();

		BCS_RESULT rs = write_output_with_logging(output_constructor_file_path.c_str(), source_code.data(), source_code.size());
		ASSERT(BCS_SUCCEEDED(rs));
	}
}

void c_high_level_tag_source_generator::generate_source_virtual()
{
	std::stringstream stream;

	stream << "#include <highlevel-" << get_engine_namespace(false) << "-" << get_platform_namespace(false) << "-private-pch.h>" << std::endl;
	stream << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace | _namespace_tree_write_warnings | _namespace_tree_write_intellisense);

	std::unordered_map<std::string, int> field_name_unique_counter;
	union
	{
		struct
		{
			uint32_t engine_platform_build_hash;
			int32_t structure_index;
		};
		uint64_t structure_guid;
	};
	engine_platform_build_hash = XXH32(&engine_platform_build, sizeof(engine_platform_build), 0);
	structure_index = -1;
	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		structure_index++;
		const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

		//if (struct_definition == &rasterizer_compiled_shader_struct_struct_definition)
		//{
		//	debug_point;
		//}



		std::string high_level_structure_name = format_structure_symbol(*struct_definition);

		stream << indent << "const s_tag_struct_definition& " << high_level_structure_name << "::tag_struct_definition = " << struct_definition->symbol->symbol_name << ";" << std::endl;
		stream << std::endl;

		if (tag_group != nullptr)
		{
			stream << indent << "const s_tag_group& " << high_level_structure_name << "::get_blofeld_group_definition() const" << std::endl;
			stream << indent << "{" << std::endl;
			stream << indent << "\treturn " << tag_group->symbol->symbol_name << ";" << std::endl;
			stream << indent << "}" << std::endl;
			stream << std::endl;
		}

		stream << indent << "const s_tag_struct_definition& " << high_level_structure_name << "::get_blofeld_struct_definition() const" << std::endl;
		stream << indent << "{" << std::endl;
		stream << indent << "\treturn " << struct_definition->symbol->symbol_name << ";" << std::endl;
		stream << indent << "}" << std::endl;
		stream << std::endl;

		generate_function_get_blofeld_field_list(stream, *struct_definition);
		generate_function_get_blofeld_field_list_deprecated(stream, *struct_definition);
	}

	end_namespace_tree(stream, _namespace_tree_write_namespace | _namespace_tree_write_warnings | _namespace_tree_write_intellisense);

	std::string source_code = stream.str();
	if (!output_virtual_file_path.empty())
	{
		BCS_RESULT rs = write_output_with_logging(output_virtual_file_path.c_str(), source_code.data(), source_code.size());
		ASSERT(BCS_SUCCEEDED(rs));
	}
}

void c_high_level_tag_source_generator::generate_source_misc()
{
	std::string namespace_without_semicolons = get_namespace(false);

	std::stringstream stream;

	stream << "#include <highlevel-" << get_engine_namespace(false) << "-" << get_platform_namespace(false) << "-private-pch.h>" << std::endl;
	stream << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace | _namespace_tree_write_warnings | _namespace_tree_write_intellisense);

	std::vector<const s_tag_struct_definition*>& sorted_tag_struct_definitions = c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type];
	bool contains_tag_constructor = false;
	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);
		if (tag_group != nullptr)
		{
			contains_tag_constructor = true;
			break;
		}
	}

	if (!contains_tag_constructor)
	{
		stream << "#define HIGH_LEVEL_NO_TAG_CONSTRUCTORS" << std::endl;
	}
	else
	{
		for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);
			if (tag_group == nullptr) continue;

			std::string high_level_structure_name = format_structure_symbol(*struct_definition);
			stream << indent << "static h_tag* " << high_level_structure_name << "_tag_group_ctor(h_group& group, const char* tag_filepath) { return new() " << high_level_structure_name << "(group, tag_filepath); }" << std::endl;
		}
		stream << std::endl;

		stream << indent << "using t_create_high_level_tag_ctor = h_tag * (h_group& group, const char* tag_filepath);" << std::endl;
		stream << indent << "struct s_tag_ctor_pair" << std::endl;
		stream << indent << "{" << std::endl;
		stream << indent << "\ts_tag_group* tag_group;" << std::endl;
		stream << indent << "\tt_create_high_level_tag_ctor* ctor;" << std::endl;
		stream << indent << "};" << std::endl;
		stream << std::endl;

		stream << indent << "static s_tag_ctor_pair tag_ctors[] = " << std::endl;
		stream << indent << "{" << std::endl;
		for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);
			if (tag_group == nullptr) continue;

			std::string high_level_structure_name = format_structure_symbol(*struct_definition);
			stream << indent << "\t" << "{ &" << tag_group->symbol->symbol_name << ", " << high_level_structure_name << "_tag_group_ctor }," << std::endl;
		}
		stream << indent << "};" << std::endl;
		stream << std::endl;
	}
	if (sorted_tag_struct_definitions.empty())
	{
		stream << "#define HIGH_LEVEL_NO_OBJECT_CONSTRUCTORS" << std::endl;
	}
	else
	{
		for (const s_tag_struct_definition* struct_definition : sorted_tag_struct_definitions)
		{
			std::string high_level_structure_name = format_structure_symbol(*struct_definition);
			stream << indent << "static h_prototype* " << high_level_structure_name << "_object_ctor() { return new() " << high_level_structure_name << "(); }" << std::endl;
		}
		stream << std::endl;

		stream << indent << "using t_create_high_level_object_ctor = h_prototype * ();" << std::endl;
		stream << indent << "struct s_object_ctor_pair" << std::endl;
		stream << indent << "{" << std::endl;
		stream << indent << "\ts_tag_struct_definition* tag_struct_definition;" << std::endl;
		stream << indent << "\tt_create_high_level_object_ctor* ctor;" << std::endl;
		stream << indent << "};" << std::endl;
		stream << std::endl;

		stream << indent << "static s_object_ctor_pair object_ctors[] = " << std::endl;
		stream << indent << "{" << std::endl;
		for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			std::string high_level_structure_name = format_structure_symbol(*struct_definition);
			stream << indent << "\t" << "{ &" << struct_definition->symbol->symbol_name << ", " << high_level_structure_name << "_object_ctor }," << std::endl;
		}
		stream << indent << "};" << std::endl;
		stream << std::endl;
	}
	stream << "#include <TagCodegen/high_level_object_constructor.inl>" << std::endl;
	if (sorted_tag_struct_definitions.empty())
	{
		stream << "#undef HIGH_LEVEL_NO_OBJECT_CONSTRUCTORS" << std::endl;
	}
	if (!contains_tag_constructor)
	{
		stream << "#undef HIGH_LEVEL_NO_TAG_CONSTRUCTORS" << std::endl;
	}
	stream << std::endl;

	{
		for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
		{
			const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

			generate_function_get_version(stream, *struct_definition);
			generate_function_get_field_data_unsafe(stream, *struct_definition, false);
			generate_function_get_field_data_unsafe(stream, *struct_definition, true);
		}
	}

	for (const s_tag_struct_definition* struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*struct_definition);

		std::string high_level_structure_name = format_structure_symbol(*struct_definition);


		uint32_t field_count;
		BCS_RESULT calculate_tag_field_count_result = calculate_tag_field_count(struct_definition->fields, field_count);
		ASSERT(BCS_SUCCEEDED(calculate_tag_field_count_result));

		uint32_t num_bitfields = __max(1ul, ROUND_UP_VALUE(field_count, 64) / 64);
		uint64_t* bitfields = new() uint64_t[num_bitfields]{};

		for (const s_tag_field* tag_field_iterator = struct_definition->fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
		{
			const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, ANY_TAG, tag_field_version_all);
			uint32_t field_index = tag_field_iterator - struct_definition->fields;

			uint64_t bit_index = field_index & 0b111111;
			uint64_t bit_mask = 1llu << bit_index;
			uint64_t bitfield_index = field_index >> 6llu;
			ASSERT(bitfield_index < num_bitfields);
			bitfields[bitfield_index] |= bit_mask;
		}

		stream << indent << "static const uint64_t k_" << high_level_structure_name << "_is_active_bits[] = { ";

		for (uint32_t bitfield_index = 0; bitfield_index < num_bitfields; bitfield_index++)
		{
			if (bitfield_index > 0)
			{
				stream << ", ";
			}
			uint64_t bitfield = bitfields[bitfield_index];
			stream << "0x" << std::hex << bitfield << std::dec;
		}
		stream << " };" << std::endl;

		stream << indent << "bool " << high_level_structure_name << "::is_field_active(const s_tag_field& field) const" << std::endl;
		stream << indent << "{" << std::endl;
		increment_indent();
		stream << indent << "intptr_t const _index = &field - " << struct_definition->symbol->symbol_name << ".fields;" << std::endl;
		stream << indent << "DEBUG_ASSERT(static_cast<uintptr_t>(_index) < " << num_bitfields << ");" << std::endl;
		stream << indent << "return static_cast<bool>((k_" << high_level_structure_name << "_is_active_bits[_index >> 6ll] >> (_index & 63)) & 1);" << std::endl;
		decrement_indent();
		stream << indent << "}" << std::endl;
		stream << indent << std::endl;

		delete[] bitfields;

	}

	end_namespace_tree(stream, _namespace_tree_write_namespace | _namespace_tree_write_warnings | _namespace_tree_write_intellisense);

	std::string source_code = stream.str();
	if (!output_misc_file_path.empty())
	{
		BCS_RESULT rs = write_output_with_logging(output_misc_file_path.c_str(), source_code.data(), source_code.size());
		ASSERT(BCS_SUCCEEDED(rs));
	}
}

void c_high_level_tag_source_generator::generate_function_get_blofeld_field_list(std::stringstream& stream, const s_tag_struct_definition& struct_definition)
{
	std::string high_level_structure_name = format_structure_symbol(struct_definition);

	uint32_t blofeld_field_list_count = 1;
	for (const s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
	{
		const s_tag_field& tag_field = tag_field_iterator_versioning(struct_definition, tag_field_iterator, engine_platform_build, tag_field_version_max);

		if (tag_field.field_type >= k_number_of_blofeld_field_types)
		{
			continue;
		}

		blofeld_field_list_count++;
	}

	stream << indent << "const s_tag_field* const* " << high_level_structure_name << "::get_blofeld_field_list() const" << std::endl;
	stream << indent << "{" << std::endl;
	{
		stream << indent << "\t" << "static const s_tag_field* const blofeld_field_list[" << blofeld_field_list_count << "] = " << std::endl;
		stream << indent << "\t" << "{" << std::endl;
		{
			for (const s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
			{
				const s_tag_field& tag_field = tag_field_iterator_versioning(struct_definition, tag_field_iterator, engine_platform_build, tag_field_version_max);
				uint32_t field_index = tag_field_iterator - struct_definition.fields;

				if (tag_field.field_type >= k_number_of_blofeld_field_types)
				{
					continue;
				}

				stream << indent << "\t\t" << struct_definition.symbol->symbol_name << ".fields" << " + " << field_index << "," << std::endl;
			}
		}
		stream << indent << "\t\t" << "nullptr" << std::endl;
		stream << indent << "\t" << "};" << std::endl;
	}
	stream << indent << "\treturn blofeld_field_list;" << std::endl;
	stream << indent << "}" << std::endl;
	stream << std::endl;
}

void c_high_level_tag_source_generator::generate_function_get_blofeld_field_list_deprecated(std::stringstream& stream, const s_tag_struct_definition& struct_definition)
{
	std::string high_level_structure_name = format_structure_symbol(struct_definition);

	uint32_t blofeld_field_list_count = 1;
	for (const s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
	{
		const s_tag_field& tag_field = tag_field_iterator_versioning(struct_definition, tag_field_iterator, engine_platform_build, tag_field_version_all);

		if (tag_field.field_type >= k_number_of_blofeld_field_types)
		{
			continue;
		}

		blofeld_field_list_count++;
	}

	stream << indent << "const s_tag_field* const* " << high_level_structure_name << "::get_blofeld_field_list_deprecated() const" << std::endl;
	stream << indent << "{" << std::endl;
	{
		stream << indent << "\t" << "static const s_tag_field* const blofeld_field_list[" << blofeld_field_list_count << "] = " << std::endl;
		stream << indent << "\t" << "{" << std::endl;
		{
			for (const s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
			{
				const s_tag_field& tag_field = tag_field_iterator_versioning(struct_definition, tag_field_iterator, engine_platform_build, tag_field_version_all);
				uint32_t field_index = tag_field_iterator - struct_definition.fields;

				if (tag_field.field_type >= k_number_of_blofeld_field_types)
				{
					continue;
				}

				stream << indent << "\t\t" << struct_definition.symbol->symbol_name << ".fields" << " + " << field_index << "," << std::endl;
			}
		}
		stream << indent << "\t\t" << "nullptr" << std::endl;
		stream << indent << "\t" << "};" << std::endl;
	}
	stream << indent << "\treturn blofeld_field_list;" << std::endl;
	stream << indent << "}" << std::endl;
	stream << std::endl;
}

void c_high_level_tag_source_generator::generate_function_get_version(std::stringstream& stream, const s_tag_struct_definition& struct_definition)
{
	// #TODO: This is hacky as heck, figure out a better way or make it more clear in the code

	std::string high_level_structure_name = format_structure_symbol(struct_definition);
	unsigned int struct_version = get_tag_struct_version(struct_definition);

	stream << indent << "uint32_t " << high_level_structure_name << "::get_version() const" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "return " << struct_version << ";" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
}

void c_high_level_tag_source_generator::generate_function_get_field_data_unsafe(std::stringstream& stream, const s_tag_struct_definition& struct_definition, bool is_const)
{
	std::unordered_map<std::string, int> field_name_unique_counter;
	std::string high_level_structure_name = format_structure_symbol(struct_definition);
	std::string namespace_without_semicolons = get_namespace(false);

	stream << indent;
	if (is_const) stream << "const ";
	stream << "void* " << high_level_structure_name << "::get_field_data_unsafe(const s_tag_field& field)";
	if (is_const) stream << " const";
	stream << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "intptr_t const _index = &field - " << struct_definition.symbol->symbol_name << ".fields;" << std::endl;
	stream << indent << "DEBUG_ASSERT(_index >= 0);" << std::endl;
	stream << std::endl;
	stream << indent << "switch (_index)" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();


	field_name_unique_counter.clear();
	for (const s_tag_field* tag_field_iterator = struct_definition.fields; tag_field_iterator->field_type != _field_terminator; tag_field_iterator++)
	{
		const s_tag_field& tag_field = tag_field_iterator_versioning_deprecated(tag_field_iterator, engine_platform_build, ANY_TAG, tag_field_version_all);
		uint32_t field_index = tag_field_iterator - struct_definition.fields;

		if (tag_field.field_type >= k_number_of_blofeld_field_types)
		{
			continue;
		}

		switch (tag_field.field_type)
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

		c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
			tag_field.name,
			tag_field.field_type == _field_block,
			&field_name_unique_counter);

		if (!custom_structure_codegen(
			_custom_structure_codegen_high_level_get_field_data_func, 
			stream, 
			indent.c_str(), 
			&field_formatter, 
			struct_definition, 
			tag_field, 
			namespace_without_semicolons.c_str()))
		{
			switch (tag_field.field_type)
			{
			case _field_array:
			case _field_struct:
			case _field_data:
			case _field_tag_reference:
			case _field_block:
				stream << indent << "case " << field_index << ": return &" << field_formatter.code_name.c_str() << ";" << std::endl;
				break;
			default:
				stream << indent << "case " << field_index << ": return &" << field_formatter.code_name.c_str() << ".value;" << std::endl;
				break;
			}
		}
	}
	stream << indent << "default: return nullptr;" << std::endl;

	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;
}
