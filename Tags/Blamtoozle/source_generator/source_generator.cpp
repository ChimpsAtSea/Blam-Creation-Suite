#include "blamtoozle-private-pch.h"

#include <TagCodegen/blamlib_string_parser.h>
#include <TagCodegen/blamlib_string_parser.inl>

#include <TagDefinitions/types/field_id.inl>
#include <TagDefinitions/types/field_type.inl>

static std::string escape_string(std::string str)
{
	std::string result;
	result.reserve(str.size() * 2); // worst case scenario

	const char* current_pos = str.data();
	while (*current_pos)
	{
		char ch = *current_pos;

		if (ch == '\r' && current_pos[1] == '\n') {}
		else
		{
			switch (ch)
			{
			case '\'': result += "\\'"; break;
			case '\"': result += "\\\""; break;
			case '\\': result += "\\\\"; break;
			case '\a': result += "\\a"; break;
			case '\b': result += "\\b"; break;
			case '\f': result += "\\f"; break;
			case '\n': result += "\\n"; break;
			case '\r': result += "\\r"; break;
			case '\t': result += "\\t"; break;
			case '\v': result += "\\v"; break;
			case '\1': result += "\\x1"; break;
			default: result += ch; break;
			}
		}

		current_pos++;
	}

	return result;
}

static void escape_string(
	const char* source,
	char* destination,
	bool remove_return,
	bool unescaped_comma)
{
	const char* source_pos = source;
	char* buffer_pos = destination;

	do
	{
		switch (*source_pos)
		{
		case '\r':
		{
			if (!remove_return)
			{
				(*buffer_pos++) = '\\';
				(*buffer_pos++) = '\r';
			}
			continue;
		}
		case '\'':
		{
			if (!unescaped_comma)
			{
				(*buffer_pos++) = '\\';
			}
			(*buffer_pos++) = '\'';
			continue;
		}
		case '\"': (*buffer_pos++) = '\\'; (*buffer_pos++) = '\"'; continue;
		case '\\': (*buffer_pos++) = '\\'; (*buffer_pos++) = '\\'; continue;
		case '\a': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'a'; continue;
		case '\b': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'b'; continue;
		case '\f': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'f'; continue;
		case '\n': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'n'; continue;
		case '\t': (*buffer_pos++) = '\\'; (*buffer_pos++) = 't'; continue;
		case '\v': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'v'; continue;
		case '\1': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'x'; (*buffer_pos++) = '1'; continue;
		}
		(*buffer_pos++) = *source_pos;
	} while (*source_pos++);
}

c_blamtoozle_source_generator::c_blamtoozle_source_generator(
	c_blamtoozle_tag_definition_manager& _tag_definition_manager,
	const char* _engine_namespace,
	const char* _platform_namespace) :
	tag_definition_manager(_tag_definition_manager),
	engine_namespace(strdup(_engine_namespace)),
	platform_namespace(strdup(_platform_namespace)),
	group_definitions(),
	block_definitions(),
	tag_reference_definitions(),
	array_definitions(),
	struct_definitions(),
	data_definitions(),
	string_list_definitions(),
	resource_definitions(),
	api_interop_definitions(),
	block_index_custom_search_definitions(),
	group_definitions_helpers(),
	block_definitions_helpers(),
	tag_reference_definitions_helpers(),
	array_definitions_helpers(),
	struct_definitions_helpers(),
	data_definitions_helpers(),
	string_list_definitions_helpers(),
	resource_definitions_helpers(),
	api_interop_definitions_helpers(),
	block_index_custom_search_definitions_helpers()
{
	coerce_definitions();
}

c_blamtoozle_source_generator::~c_blamtoozle_source_generator()
{
	untracked_free(engine_namespace);
	untracked_free(platform_namespace);
}

void c_blamtoozle_source_generator::export_single_tag_definitions_header(const wchar_t* file_path)
{
	clear_is_exported();
	c_blamtoozle_file_stream file_stream(*this, file_path);

#define stream file_stream.stream

	stream << "#pragma once" << std::endl;
	stream << std::endl;
	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	if (engine_namespace)
	{
		stream << "namespace " << engine_namespace << std::endl;
		stream << "{" << std::endl;
	}
	if (platform_namespace)
	{
		stream << "namespace " << platform_namespace << std::endl;
		stream << "{" << std::endl;
	}
	stream << std::endl;

	for (auto& group_definition : group_definitions)
	{
		if (!is_group_exported(*group_definition))
		{
			union
			{
				unsigned long long _byteswap_group_tag;
				char _group_tag_str[sizeof(_byteswap_group_tag)];
			};
			_byteswap_group_tag = _byteswap_ulong(group_definition->get_group_tag());
			const char* group_tag_string = _group_tag_str;
			while (*group_tag_string == 0)
			{
				group_tag_string++;
			}

			stream << "\tstatic constexpr unsigned long " << group_definition->get_group_tag_macro_name() << " = '" << group_tag_string << "';" << std::endl;
			stream << "\t" << "extern s_tag_group " << group_definition->get_code_symbol_name() << ";" << std::endl;
			//stream << "\t" << "extern s_tag_group " << group_definition->get_display_name() << "_group;" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& block_definition : block_definitions)
	{
		if (!is_block_exported(*block_definition))
		{
			stream << "\t" << "extern s_tag_block_definition " << block_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& array_definition : array_definitions)
	{
		if (!is_array_exported(*array_definition))
		{
			stream << "\t" << "extern s_tag_array_definition " << array_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& struct_definition : struct_definitions)
	{
		if (!is_struct_exported(*struct_definition))
		{
			stream << "\t" << "extern s_tag_struct_definition " << struct_definition->get_code_symbol_name() << ";" << std::endl;

			write_tag_types_header(stream, struct_definition->fields);

			stream << std::endl;
		}
	}

	for (auto& data_definition : data_definitions)
	{
		if (!is_data_exported(*data_definition))
		{
			stream << "\t" << "extern s_tag_data_definition " << data_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& resource_definition : resource_definitions)
	{
		if (!is_resource_exported(*resource_definition))
		{
			stream << "\t" << "extern s_tag_resource_definition " << resource_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& api_interop_definition : api_interop_definitions)
	{
		if (!is_api_interop_exported(*api_interop_definition))
		{
			stream << "\t" << "extern s_tag_interop_definition " << api_interop_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& block_index_custom_search_definition : block_index_custom_search_definitions)
	{
		if (!is_block_index_custom_search_exported(*block_index_custom_search_definition))
		{
			stream << "\t" << "extern s_block_index_custom_search_definition " << block_index_custom_search_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	stream << std::endl;
	if (platform_namespace)
	{
		stream << "} // namespace " << platform_namespace << std::endl;
		stream << std::endl;
	}
	if (engine_namespace)
	{
		stream << "} // namespace " << engine_namespace << std::endl;
		stream << std::endl;
	}
	stream << "} // namespace blofeld" << std::endl;
	stream << std::endl;

#undef stream

	file_stream.write();
}

void c_blamtoozle_source_generator::write_tag_types_header(std::stringstream& stream, c_blamtoozle_tag_struct_definition::t_fields& fields)
{
	for (auto& _field : fields)
	{
		if (c_blamtoozle_tag_field* tag_field = dynamic_cast<c_blamtoozle_tag_field*>(_field))
		{
			switch (tag_field->get_field_type())
			{
			case blofeld::_field_char_enum:
			case blofeld::_field_short_enum:
			case blofeld::_field_long_enum:
			case blofeld::_field_long_flags:
			case blofeld::_field_word_flags:
			case blofeld::_field_byte_flags:
			{
				c_blamtoozle_string_list_definition* string_list_definition = tag_field->get_string_list_definition();
				ASSERT(string_list_definition != nullptr);

				if (!is_string_list_exported(*string_list_definition))
				{
					stream << "\t" << "extern s_string_list_definition " << string_list_definition->get_code_symbol_name() << ";";
					stream << std::endl;
				}
			}
			break;
			case blofeld::_field_tag_reference:
			{
				c_blamtoozle_tag_reference_definition* tag_reference_definition = tag_field->get_tag_reference_definition();
				ASSERT(tag_reference_definition != nullptr);

				if (!is_tag_reference_exported(*tag_reference_definition))
				{
					stream << "\textern s_tag_reference_definition " << tag_reference_definition->get_code_symbol_name() << ";";
					stream << std::endl;
				}
			}
			break;
			}
		}
	}
}

void c_blamtoozle_source_generator::write_tag_types_source(std::stringstream& stream, c_blamtoozle_tag_struct_definition::t_fields& fields)
{
	for (auto& _field : fields)
	{
		if (c_blamtoozle_tag_field* tag_field = dynamic_cast<c_blamtoozle_tag_field*>(_field))
		{
			switch (tag_field->get_field_type())
			{
			case blofeld::_field_char_enum:
			case blofeld::_field_short_enum:
			case blofeld::_field_long_enum:
			case blofeld::_field_long_flags:
			case blofeld::_field_word_flags:
			case blofeld::_field_byte_flags:
			{
				c_blamtoozle_string_list_definition* string_list_definition = tag_field->get_string_list_definition();
				ASSERT(string_list_definition != nullptr);

				if (!is_string_list_exported(*string_list_definition))
				{
					if (string_list_definition->options.size() > 0)
					{
						stream << "\tSTRINGS(" << string_list_definition->get_code_symbol_name() << ")" << std::endl;
						stream << "\t{" << std::endl;
						for (unsigned long i = 0; i < string_list_definition->options.size(); i++)
						{
							const char* option = string_list_definition->options[i];
							std::string escaped_option = escape_string(option);
							if (escaped_option.empty()) escaped_option = "unused";
							if (i != string_list_definition->options.size() - 1)
							{
								stream << "\t\t\"" << escaped_option << "\"," << std::endl;
							}
							else
							{
								stream << "\t\t\"" << escaped_option << "\"" << std::endl;
							}
						}
						stream << "\t};" << std::endl;

						stream << "\tSTRING_LIST(" << string_list_definition->get_code_symbol_name() << ", " << string_list_definition->get_code_symbol_name() << "_strings, _countof(" << string_list_definition->get_code_symbol_name() << "_strings));" << std::endl;
					}
					else
					{
						stream << "\tSTRING_LIST(" << string_list_definition->get_code_symbol_name() << ", empty_string_list, 0);" << std::endl;
					}

					stream << std::endl;
				}
			}
			break;
			case blofeld::_field_tag_reference:
			{
				c_blamtoozle_tag_reference_definition* tag_reference_definition = tag_field->get_tag_reference_definition();
				if (!is_tag_reference_exported(*tag_reference_definition))
				{
					if (tag_reference_definition->group_tags.size() > 1)
					{
						stream << "\tTAG_REFERENCE_GROUP(" << tag_reference_definition->get_code_symbol_name();
						write_tag_reference_flags(stream, *tag_reference_definition);
						stream << ")" << std::endl;
						stream << "\t{" << std::endl;
						bool first = true;
						for (c_blamtoozle_tag_group_definition* group_definition : tag_reference_definition->tag_group_definitions)
						{
							stream << "\t\t" << group_definition->get_group_tag_macro_name() << "," << std::endl;
							first = false;
						}
						stream << "\t\tINVALID_TAG" << std::endl;

						stream << "\t};" << std::endl;
					}
					else if (tag_reference_definition->group_tags.size() == 1)
					{
						stream << "\tTAG_REFERENCE(" << tag_reference_definition->get_code_symbol_name() << ", " << tag_reference_definition->tag_group_definitions[0]->get_group_tag_macro_name();
						write_tag_reference_flags(stream, *tag_reference_definition);
						stream << ");" << std::endl;
					}
					else
					{
						stream << "\tTAG_REFERENCE(" << tag_reference_definition->get_code_symbol_name() << ", INVALID_TAG";
						write_tag_reference_flags(stream, *tag_reference_definition);
						stream << ");" << std::endl;
					}

					stream << std::endl;
				}
			}
			break;
			}
		}
	}
}

void c_blamtoozle_source_generator::write_tag_reference_flags(std::stringstream& stream, c_blamtoozle_tag_reference_definition& tag_reference_definition)
{
	// #TODO: The conversion from flag to string could be improved here

	std::stringstream flags_stream;

	c_flags<blofeld::e_tag_reference_flags> flags = tag_reference_definition.get_tag_reference_flags();

	if (flags.test(blofeld::_tag_reference_flag_not_a_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_not_a_dependency";
	}
	if (flags.test(blofeld::_tag_reference_flag_dont_resolve_in_editor))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_dont_resolve_in_editor";
	}
	if (flags.test(blofeld::_tag_reference_flag_resolved_manually))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_resolved_manually";
	}
	if (flags.test(blofeld::_tag_reference_flag_resolved_by_game))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_resolved_by_game";
	}
	if (flags.test(blofeld::_tag_reference_flag_not_a_resource_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_not_a_resource_dependency";
	}
	if (flags.test(blofeld::_tag_reference_flag_dependency_for_cache_file_sharing))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_dependency_for_cache_file_sharing";
	}
	if (flags.test(blofeld::_tag_reference_flag_reference_ignored_by_bundle_builder))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_reference_ignored_by_bundle_builder";
	}
	std::string flags_string = flags_stream.str();
	if (!flags_string.empty())
	{
		stream << ", " << flags_string;
	}
}

void c_blamtoozle_source_generator::export_single_tag_definitions_source(const wchar_t* file_path)
{
	clear_is_exported();

	c_blamtoozle_file_stream file_stream(*this, file_path);

#define stream file_stream.stream

	stream << "#include <tagdefinitions-private-pch.h>" << std::endl;
	stream << "#include <blofeld_field_type_override.h>" << std::endl;
	stream << std::endl;
	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	if (engine_namespace)
	{
		stream << "namespace " << engine_namespace << std::endl;
		stream << "{" << std::endl;
	}
	if (platform_namespace)
	{
		stream << "namespace " << platform_namespace << std::endl;
		stream << "{" << std::endl;
	}
	stream << std::endl;

	for (auto& group_definition : group_definitions)
	{
		if (!is_group_exported(*group_definition))
		{
			c_blamtoozle_tag_block_definition& block_definition = group_definition->get_block_definition();
			c_blamtoozle_tag_struct_definition& struct_definition = block_definition.get_struct_definition();

			stream << "\tTAG_GROUP(" << std::endl;
			stream << "\t\t" << group_definition->get_code_symbol_name() << "," << std::endl;
			//stream << "\t\t" << group_definition->get_display_name() << "_group," << std::endl;
			stream << "\t\t" << group_definition->get_group_tag_macro_name() << "," << std::endl;
			if (c_blamtoozle_tag_group_definition* parent_group_definition = tag_definition_manager.get_tag_group_definition_by_group_tag(group_definition->get_parent_group_tag()))
			{
				stream << "\t\t&" << parent_group_definition->get_code_symbol_name() << "," << std::endl;
				//stream << "\t\t&" << parent_group_definition->get_display_name() << "_group," << std::endl;
				stream << "\t\t" << parent_group_definition->get_group_tag_macro_name() << "," << std::endl;
			}
			else
			{
				stream << "\t\t" << "nullptr," << std::endl;
				stream << "\t\t" << "INVALID_TAG," << std::endl;
			}
			stream << "\t\t" << block_definition.get_code_symbol_name() << ");" << std::endl;
			stream << std::endl;
		}
	}
	for (auto& block_definition : block_definitions)
	{
		if (!is_block_exported(*block_definition))
		{
			c_blamtoozle_tag_struct_definition& struct_definition = block_definition->get_struct_definition();

			stream << "\tTAG_BLOCK_FROM_STRUCT_V2(" << std::endl;
			stream << "\t\t" << block_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << "\"" << block_definition->get_display_name() << "\"," << std::endl;
			stream << "\t\t" << "\"" << block_definition->get_name() << "\"," << std::endl;
			//stream << "\t\t" << "" << block_definition->get_max_count_string() << "," << std::endl; // #TODO: Need a new list of macros
			stream << "\t\t" << "" << block_definition->get_max_count() << "," << std::endl;
			stream << "\t\t" << struct_definition.get_code_symbol_name() << ");" << std::endl;
			stream << std::endl;
		}
	}
	for (auto& array_definition : array_definitions)
	{
		if (!is_array_exported(*array_definition))
		{
			c_blamtoozle_tag_struct_definition& struct_definition = array_definition->get_struct_definition();

			stream << "\tTAG_ARRAY_FROM_STRUCT(" << std::endl;
			stream << "\t\t" << array_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << "\"" << array_definition->get_name() << "\"," << std::endl;
			stream << "\t\t" << "" << array_definition->get_element_count() << "," << std::endl;
			stream << "\t\t" << struct_definition.get_code_symbol_name() << ");" << std::endl;
			stream << std::endl;
		}
	}
	for (auto& struct_definition : struct_definitions)
	{
		if (!is_struct_exported(*struct_definition))
		{
			const blofeld::s_tag_persistent_identifier& persistent_identifier = struct_definition->get_persistent_identifier();
			char persistent_identifier_buffer[256];
			snprintf(
				persistent_identifier_buffer,
				256,
				"0x%08X, 0x%08X, 0x%08X, 0x%08X",
				persistent_identifier.identifier_part_0,
				persistent_identifier.identifier_part_1,
				persistent_identifier.identifier_part_2,
				persistent_identifier.identifier_part_3);

			char persistent_identifier_name_buffer[256];
			snprintf(
				persistent_identifier_name_buffer,
				256,
				"%s_id",
				struct_definition->get_code_symbol_name());
			for (char* persistent_identifier_name_pos = persistent_identifier_name_buffer; *persistent_identifier_name_pos; persistent_identifier_name_pos++)
			{
				*persistent_identifier_name_pos = toupper(*persistent_identifier_name_pos);
			}

			//std::string runtime_flags = create_struct_definition_runtime_flags(tag_struct.runtime_flags, "\n\t\t");
			//std::string memory_attributes = create_struct_definition_memory_attributes(tag_struct.memory_attributes.memory_type, tag_struct.memory_attributes.usage_flags, "\n\t\t");

			stream << "\t#define " << persistent_identifier_name_buffer << " { " << persistent_identifier_buffer << " }" << std::nouppercase << std::endl;

			stream << "\tTAG_STRUCT(" << std::endl;
			stream << "\t\t" << struct_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << "\"" << struct_definition->get_display_name() << "\"," << std::endl;
			stream << "\t\t" << "\"" << struct_definition->get_name() << "\"," << std::endl;
			stream << "\t\t" << "\"" << struct_definition->get_structure_type_name() << "\"," << std::endl;

			c_flags<blofeld::e_tag_field_set_bit> default_flags;
			default_flags.set(blofeld::_tag_field_set_unknown0_bit, true);
			default_flags.set(blofeld::_tag_field_set_unknown1_bit, true);
			default_flags.set(blofeld::_tag_field_set_has_aggregate_types_bit, true);
			default_flags.set(blofeld::_tag_field_set_delete_recursively_bit, true);
			default_flags.set(blofeld::_tag_field_set_postprocess_recursively_bit, true);

			c_flags<blofeld::e_tag_field_set_bit> flags = struct_definition->get_field_set_bits();
			if (flags.is_clear())
			{
				flags = default_flags;
			}

			if (flags == default_flags)
			{
				stream << "\t\t" << "SET_DEFAULT," << std::endl;
			}
			else
			{
				stream << "\t\t";
				bool is_first = true;
				for (__underlying_type(blofeld::e_tag_field_set_bit) _tag_field_set = 0; _tag_field_set < blofeld::k_num_runtime_flags; _tag_field_set++)
				{
					blofeld::e_tag_field_set_bit tag_field_set = static_cast<blofeld::e_tag_field_set_bit>(_tag_field_set);
					if (flags.test(tag_field_set))
					{
						const char* macro = tag_field_set_bit_to_field_set_bit_macro(tag_field_set);

						if (!is_first)
						{
							stream << " | ";
						}

						stream << macro;

						is_first = false;
					}
				}
				stream << "," << std::endl;
			}
			stream << "\t\t" << "TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY)," << std::endl;
			stream << "\t\t" << persistent_identifier_name_buffer;
			if (struct_definition->get_alignment_bits())
			{
				stream << "," << std::endl;
				stream << "\t\t" << struct_definition->get_alignment_bits();
			}
			stream << ")" << std::endl;
			stream << "\t" << "{" << std::endl;
			write_fields(stream, struct_definition->fields);
			stream << "\t" << "};" << std::endl;
			stream << std::endl;

			write_tag_types_source(stream, struct_definition->fields);
		}
	}
	for (auto& data_definition : data_definitions)
	{
		if (!is_data_exported(*data_definition))
		{
			stream << "\tTAG_DATA(" << std::endl;
			stream << "\t\t" << data_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << "\"" << data_definition->get_name() << "\"," << std::endl;
			stream << "\t\t" << "" << data_definition->get_flags() << "," << std::endl;
			stream << "\t\t" << "" << data_definition->get_alignment_bits() << "," << std::endl;
			stream << "\t\t" << "" << data_definition->get_maximum_element_count() << "," << std::endl;
			stream << "\t\t" << "" << data_definition->get_maximum_element_count_string() << ");" << std::endl;
			stream << std::endl;
		}
	}

	for (auto& resource_definition : resource_definitions)
	{
		if (!is_resource_exported(*resource_definition))
		{
			c_blamtoozle_tag_struct_definition& struct_definition = resource_definition->get_struct_definition();

			stream << "\tTAG_RESOURCE(" << std::endl;
			stream << "\t\t" << resource_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << "\"" << resource_definition->get_code_symbol_name() << "\"," << std::endl;
			stream << "\t\t" << struct_definition.get_code_symbol_name() << ");" << std::endl;
			stream << std::endl;
		}
	}

	for (auto& api_interop_definition : api_interop_definitions)
	{
		if (!is_api_interop_exported(*api_interop_definition))
		{
			c_blamtoozle_tag_struct_definition& struct_definition = api_interop_definition->get_struct_definition();

			const blofeld::s_tag_persistent_identifier& persistent_identifier = api_interop_definition->get_persistent_identifier();
			char persistent_identifier_buffer[256];
			snprintf(
				persistent_identifier_buffer,
				256,
				"0x%08X, 0x%08X, 0x%08X, 0x%08X",
				persistent_identifier.identifier_part_0,
				persistent_identifier.identifier_part_1,
				persistent_identifier.identifier_part_2,
				persistent_identifier.identifier_part_3);

			char persistent_identifier_name_buffer[256];
			snprintf(
				persistent_identifier_name_buffer,
				256,
				"%s_id",
				api_interop_definition->get_code_symbol_name());
			for (char* persistent_identifier_name_pos = persistent_identifier_name_buffer; *persistent_identifier_name_pos; persistent_identifier_name_pos++)
			{
				*persistent_identifier_name_pos = toupper(*persistent_identifier_name_pos);
			}

			stream << "\t#define " << persistent_identifier_name_buffer << " { " << persistent_identifier_buffer << " }" << std::nouppercase << std::endl;

			stream << "\tTAG_INTEROP(" << std::endl;
			stream << "\t\t" << api_interop_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << "\"" << api_interop_definition->get_code_symbol_name() << "\"," << std::endl;
			stream << "\t\t" << struct_definition.get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << persistent_identifier_name_buffer << ");" << std::endl;
			stream << std::endl;
		}
	}

	for (auto& block_index_custom_search_definition : block_index_custom_search_definitions)
	{
		if (!is_block_index_custom_search_exported(*block_index_custom_search_definition))
		{
			stream << "\tBLOCK_INDEX_CUSTOM_SEARCH_DEFINITION(" << std::endl;
			stream << "\t\t" << block_index_custom_search_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << "\"" << block_index_custom_search_definition->get_code_symbol_name() << "\");" << std::endl;
			stream << std::endl;
		}
	}


	stream << std::endl;
	if (platform_namespace)
	{
		stream << "} // namespace " << platform_namespace << std::endl;
		stream << std::endl;
	}
	if (engine_namespace)
	{
		stream << "} // namespace " << engine_namespace << std::endl;
		stream << std::endl;
	}
	stream << "} // namespace blofeld" << std::endl;
	stream << std::endl;

#undef stream

	file_stream.write();
}

void c_blamtoozle_source_generator::export_tag_groups_header(const wchar_t* file_path)
{
	clear_is_exported();

	c_blamtoozle_file_stream file_stream(*this, file_path);

#define stream file_stream.stream

	stream << "#pragma once" << std::endl;
	stream << std::endl;
	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	if (engine_namespace)
	{
		stream << "\t" << "namespace " << engine_namespace << std::endl;
		stream << "\t" << "{" << std::endl;
	}
	if (platform_namespace)
	{
		stream << "\t\t" << "namespace " << platform_namespace << std::endl;
		stream << "\t\t" << "{" << std::endl;
	}
	stream << std::endl;

	stream << "\t\t\t" << "BCS_DEBUG_API extern const s_tag_group* tag_groups[];" << std::endl;

	stream << std::endl;
	if (platform_namespace)
	{
		stream << "\t\t" << "} // namespace " << platform_namespace << std::endl;
		stream << std::endl;
	}
	if (engine_namespace)
	{
		stream << "\t" << "} // namespace " << engine_namespace << std::endl;
		stream << std::endl;
	}
	stream << "} // namespace blofeld" << std::endl;
	stream << std::endl;

#undef stream

	file_stream.write();
}

void c_blamtoozle_source_generator::export_tag_groups_source(const wchar_t* file_path)
{
	clear_is_exported();

	c_blamtoozle_file_stream file_stream(*this, file_path);

#define stream file_stream.stream

	stream << "#pragma once" << std::endl;
	stream << std::endl;
	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	if (engine_namespace)
	{
		stream << "\t" << "namespace " << engine_namespace << std::endl;
		stream << "\t" << "{" << std::endl;
	}
	if (platform_namespace)
	{
		stream << "\t\t" << "namespace " << platform_namespace << std::endl;
		stream << "\t\t" << "{" << std::endl;
	}
	stream << std::endl;

	stream << "\t\t\t" << "const s_tag_group* tag_groups[] =" << std::endl;
	stream << "\t\t\t" << "{" << std::endl;
	for (auto& group_definition : group_definitions)
	{
		if (!is_group_exported(*group_definition))
		{
			stream << "\t\t\t\t" << "&" << group_definition->get_code_symbol_name() << "," << std::endl;
		}
	}
	stream << "\t\t\t" << "};" << std::endl;

	stream << std::endl;
	if (platform_namespace)
	{
		stream << "\t\t" << "} // namespace " << platform_namespace << std::endl;
		stream << std::endl;
	}
	if (engine_namespace)
	{
		stream << "\t" << "} // namespace " << engine_namespace << std::endl;
		stream << std::endl;
	}
	stream << "} // namespace blofeld" << std::endl;
	stream << std::endl;

#undef stream

	file_stream.write();
}

const char* c_blamtoozle_source_generator::tag_field_set_bit_to_field_set_bit_macro(blofeld::e_tag_field_set_bit flag)
{
	switch (flag)
	{
	case blofeld::_tag_field_set_unknown0_bit:										return "SET_UNKNOWN0";
	case blofeld::_tag_field_set_unknown1_bit:										return "SET_UNKNOWN1";
	case blofeld::_tag_field_set_has_inlined_children_with_placement_new_bit:		return "SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW";
	case blofeld::_tag_field_set_unknown3_bit:										return "SET_UNKNOWN3";
	case blofeld::_tag_field_set_unknown4_bit:										return "SET_UNKNOWN4";
	case blofeld::_tag_field_set_has_aggregate_types_bit:										return "SET_UNKNOWN5";
	case blofeld::_tag_field_set_is_temporary_bit:									return "SET_IS_TEMPORARY";
	case blofeld::_tag_field_set_unknown7_bit:										return "SET_UNKNOWN7";
	case blofeld::_tag_field_set_unknown8_bit:										return "SET_UNKNOWN8";
	case blofeld::_tag_field_set_delete_recursively_bit:							return "SET_DELETE_RECURSIVELY";
	case blofeld::_tag_field_set_postprocess_recursively_bit:						return "SET_POSTPROCESS_RECURSIVELY";
	case blofeld::_tag_field_set_is_memcpyable_bit:									return "SET_IS_MEMCPYABLE";
	case blofeld::_tag_field_set_unknown12_bit:										return "SET_UNKNOWN12";
	case blofeld::_tag_field_set_has_resources_bit:									return "SET_HAS_RESOURCES";
	case blofeld::_tag_field_set_unknown14_bit:										return "SET_UNKNOWN14";
	case blofeld::_tag_field_set_unknown15_bit:										return "SET_UNKNOWN15";
	case blofeld::_tag_field_set_has_level_specific_fields_bit:						return "SET_HAS_LEVEL_SPECIFIC_FIELDS";
	case blofeld::_tag_field_set_can_memset_to_initialize_bit:						return "SET_CAN_MEMSET_TO_INITIALIZE";
	case blofeld::_tag_field_set_unknown18_bit:										return "SET_UNKNOWN18";
	case blofeld::_tag_field_set_exist_in_cache_build_bit:										return "SET_UNKNOWN19";
	}
	throw;
}

void c_blamtoozle_source_generator::write_fields(std::stringstream& stream, c_blamtoozle_tag_struct_definition::t_fields& fields)
{
	for (auto& _field : fields)
	{
		if (c_blamtoozle_tag_field_combined_fixup* combined_fixup_field = dynamic_cast<c_blamtoozle_tag_field_combined_fixup*>(_field))
		{
			switch (combined_fixup_field->fixup_type)
			{
			case _blamtoozle_tag_field_combined_fixup_type_equal:
				stream << "\t\t{ _version_mode_tag_group_equal, &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << combined_fixup_field->group_definition.get_code_symbol_name() << ", " << combined_fixup_field->count << " }," << std::endl;
				break;
			case _blamtoozle_tag_field_combined_fixup_type_not_equal:
				stream << "\t\t{ _version_mode_tag_group_not_equal, &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << combined_fixup_field->group_definition.get_code_symbol_name() << ", " << combined_fixup_field->count << " }," << std::endl;
				break;
			}


		}
		else if (c_blamtoozle_tag_field_dummy_space* dummy_space_field = dynamic_cast<c_blamtoozle_tag_field_dummy_space*>(_field))
		{
			stream << std::endl;


		}
		else if (c_blamtoozle_tag_field* tag_field = dynamic_cast<c_blamtoozle_tag_field*>(_field))
		{
			blofeld::e_field field_type = tag_field->get_field_type();
			const char* field_generic_type_name;
			BCS_RESULT rs = blofeld::field_to_string(field_type, field_generic_type_name);
			ASSERT(BCS_SUCCEEDED(rs));

			c_blamlib_string_parser_v2 string_parser = c_blamlib_string_parser_v2(tag_field->get_name());

			c_fixed_string_4096 display_name;
			c_fixed_string_4096 description;
			c_fixed_string_4096 units;
			c_fixed_string_4096 limits;
			c_fixed_string_4096 limits_legacy;
			c_fixed_string_4096 old_name;

			if (tag_field->get_name())
			{
				escape_string(string_parser.pretty_name, display_name, true, true);
				escape_string(string_parser.description, description, true, true);
				escape_string(string_parser.units, units, true, true);
				escape_string(string_parser.limits, limits, true, true);
				escape_string(string_parser.limits_legacy, limits_legacy, true, true);
				escape_string(string_parser.old_name, old_name, true, true);
			}
			if (display_name.empty())
			{
				display_name = "value";
			}

			bool write_limits = !limits.empty();
			bool write_units = write_limits || !units.empty();
			bool write_description = write_units || !description.empty();
			bool write_old_name = !old_name.empty();
			bool write_flags =
				string_parser.flag_unknown0 ||
				string_parser.flag_read_only ||
				string_parser.flag_index ||
				string_parser.flag_unknown3 ||
				string_parser.flag_pointer;
			bool write_pointer = false; // todo
			bool write_tag = tag_field->get_field_id() != 0;

			const char* field_id_string = blofeld::field_id_to_string(tag_field->get_field_id());

			switch (field_type)
			{
			case blofeld::_field_custom:
			{
				ASSERT(!write_flags);

				if (tag_field->get_field_id() == blofeld::_field_id_field_group_begin)
				{
					ASSERT(!display_name.empty());
					ASSERT(description.empty());
					stream << "\t\tFIELD_GROUP_BEGIN(";
					if (!display_name.empty() && strcmp(display_name, "value") != 0) stream << "\"" << display_name.c_str() << "\"";
					stream << ")," << std::endl;
				}
				else if (tag_field->get_field_id() == blofeld::_field_id_field_group_end)
				{
					//ASSERT(display_name == "value" || display_name.empty());
					ASSERT(description.empty());

					if (display_name.empty() || strcmp(display_name, "value") == 0) // #TODO: improve this with function
					{
						stream << "\t\tFIELD_GROUP_END()," << std::endl;
					}
					else
					{
						stream << "\t\tFIELD_GROUP_END2(";
						stream << "\"" << display_name.c_str() << "\"";
						stream << ")," << std::endl;
					}

					//stream << "\t\tFIELD_GROUP_END(";
					//if (!display_name.empty() && strcmp(display_name, "value") != 0) stream << "\"" << display_name.c_str() << "\"";
					//stream << ")," << std::endl;
				}
				else if (tag_field->get_field_id() == blofeld::_field_id_hide_begin)
				{
					ASSERT(display_name.empty() || strcmp(display_name, "value") == 0);
					ASSERT(description.empty());
					stream << "\t\tFIELD_HIDE_BEGIN(";
					if (!display_name.empty() && strcmp(display_name, "value") != 0) stream << "\"" << display_name.c_str() << "\"";
					stream << ")," << std::endl;
				}
				else if (tag_field->get_field_id() == blofeld::_field_id_hide_end)
				{
					ASSERT(display_name.empty() || strcmp(display_name, "value") == 0);
					ASSERT(description.empty());
					stream << "\t\tFIELD_HIDE_END(";
					if (!display_name.empty() && strcmp(display_name, "value") != 0) stream << "\"" << display_name.c_str() << "\"";
					stream << ")," << std::endl;
				}
				else if (tag_field->get_field_id() == blofeld::_field_id_ifp_begin)
				{
					ASSERT(display_name.empty() || strcmp(display_name, "value") == 0);
					ASSERT(description.empty());
					stream << "\t\tFIELD_IFP_BEGIN(";
					if (!display_name.empty() && strcmp(display_name, "value") != 0) stream << "\"" << display_name.c_str() << "\"";
					stream << ")," << std::endl;
				}
				else if (tag_field->get_field_id() == blofeld::_field_id_ifp_end)
				{
					ASSERT(display_name.empty() || strcmp(display_name, "value") == 0);
					ASSERT(description.empty());
					stream << "\t\tFIELD_IFP_END(";
					if (!display_name.empty() && strcmp(display_name, "value") != 0) stream << "\"" << display_name.c_str() << "\"";
					stream << ")," << std::endl;
				}
				else if (tag_field->get_field_id() == blofeld::_field_id_dont_checksum_begin)
				{
					ASSERT(display_name.empty() || strcmp(display_name, "value") == 0);
					ASSERT(description.empty());
					stream << "\t\tFIELD_DONT_CHECKSUM_BEGIN(";
					if (!display_name.empty() && strcmp(display_name, "value") != 0) stream << "\"" << display_name.c_str() << "\"";
					stream << ")," << std::endl;
				}
				else if (tag_field->get_field_id() == blofeld::_field_id_dont_checksum_end)
				{
					ASSERT(display_name.empty() || strcmp(display_name, "value") == 0);
					ASSERT(description.empty());
					stream << "\t\tFIELD_DONT_CHECKSUM_END(";
					if (!display_name.empty() && strcmp(display_name, "value") != 0) stream << "\"" << display_name.c_str() << "\"";
					stream << ")," << std::endl;
				}
				else
				{
					stream << "\t\tFIELD_CUSTOM(";
					if (!display_name.empty())
					{
						if (!display_name.empty()) stream << "\"" << display_name.c_str() << "\"";
					}
					/*if (!description.empty())
					{
						if (!description.empty()) stream << ", \"" << description.c_str() << "\"";
					*/
					stream << ", " << (field_id_string ? field_id_string : "_field_id_default");
					if (write_flags)
					{
						stream << ", "; write_tag_field_flags(stream, string_parser);
					}
					stream << ")," << std::endl;
				}
				break;
			}
			case blofeld::_field_pad:
			{
				ASSERT(!write_limits);
				ASSERT(!write_units);

				stream << "\t\tFIELD_PAD(";
				if (!display_name.empty())
				{
					if (!display_name.empty()) stream << "\"" << display_name.c_str() << "\"";
				}
				if (!description.empty())
				{
					if (!description.empty()) stream << ", \"" << description.c_str() << "\"";
				}
				stream << ", " << tag_field->get_padding();
				if (write_flags)
				{
					stream << ", "; write_tag_field_flags(stream, string_parser);
				}
				stream << ")," << std::endl;
			}
			break;
			case blofeld::_field_skip:
			{
				ASSERT(!write_limits);
				ASSERT(!write_units);
				ASSERT(!write_flags);

				stream << "\t\tFIELD_SKIP(";
				if (!display_name.empty())
				{
					if (!display_name.empty()) stream << "\"" << display_name.c_str() << "\"";
				}
				if (!description.empty())
				{
					if (!description.empty()) stream << ", \"" << description.c_str() << "\"";
				}
				stream << ", " << tag_field->get_skip_length();
				if (write_flags)
				{
					stream << ", "; write_tag_field_flags(stream, string_parser);
				}
				stream << ")," << std::endl;
			}
			break;
			case blofeld::_field_explanation:
			{

				stream << "\t\tFIELD_EXPLANATION(";
				if (!display_name.empty())
				{
					if (!display_name.empty()) stream << "\"" << display_name.c_str() << "\"";
				}
				if (!description.empty())
				{
					if (!description.empty()) stream << ", \"" << description.c_str() << "\"";
				}
				else if (tag_field->get_explanation() != nullptr && *tag_field->get_explanation())
				{
					std::string explanation = escape_string(tag_field->get_explanation());
					stream << ", \"" << explanation << "\"";
				}
				else stream << ", nullptr";
				if (write_flags)
				{
					stream << ", "; write_tag_field_flags(stream, string_parser);
				}
				stream << ")," << std::endl;
			}
			break;
			case blofeld::_field_array:
			{
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				c_blamtoozle_tag_array_definition* array_definition = tag_field->get_array_definition();
				ASSERT(array_definition != nullptr);
				stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << array_definition->get_code_symbol_name();
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}

				stream << " }," << std::endl;
			}
			break;
			case blofeld::_field_char_block_index:
			case blofeld::_field_short_block_index:
			case blofeld::_field_long_block_index:
			case blofeld::_field_byte_block_flags:
			case blofeld::_field_word_block_flags:
			case blofeld::_field_long_block_flags:
			case blofeld::_field_block:
			{
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				//ASSERT(tag_field->get_block_definition());
				if (tag_field->get_block_definition())
				{
					stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << tag_field->get_block_definition()->get_code_symbol_name();
				}
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}

				stream << " }," << std::endl;
			}
			break;
			case blofeld::_field_struct:
			{
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				ASSERT(tag_field->get_struct_definition());
				if (tag_field->get_struct_definition())
				{
					stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << tag_field->get_struct_definition()->get_code_symbol_name();
				}
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}

				stream << " }," << std::endl;
			}
			break;
			case blofeld::_field_api_interop:
			{
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				ASSERT(tag_field->get_api_interop_definition());
				if (tag_field->get_api_interop_definition())
				{
					stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << tag_field->get_api_interop_definition()->get_code_symbol_name();
				}
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}

				stream << " }," << std::endl;
			}
			break;
			case blofeld::_field_data:
			{
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				//ASSERT(tag_field->get_data_definition());
				if (tag_field->get_data_definition())
				{
					stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << tag_field->get_data_definition()->get_code_symbol_name();
				}
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}

				stream << " }," << std::endl;
			}
			break;
			case blofeld::_field_char_block_index_custom_search:
			case blofeld::_field_short_block_index_custom_search:
			case blofeld::_field_long_block_index_custom_search:
			{
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				//ASSERT(tag_field->get_block_index_custom_search_definition());
				if (tag_field->get_block_index_custom_search_definition())
				{
					stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << tag_field->get_block_index_custom_search_definition()->get_code_symbol_name();
				}
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}

				stream << " }," << std::endl;
			}
			break;
			case blofeld::_field_pageable_resource:
			{
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				ASSERT(tag_field->get_tag_resource_definition());
				if (tag_field->get_tag_resource_definition())
				{
					stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << tag_field->get_tag_resource_definition()->get_code_symbol_name();
				}
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}

				stream << " }," << std::endl;
			}
			break;
			case blofeld::_field_tag_reference:
			{
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				ASSERT(tag_field->get_tag_reference_definition());
				if (tag_field->get_tag_reference_definition())
				{
					stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << tag_field->get_tag_reference_definition()->get_code_symbol_name();
				}
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}

				stream << " }," << std::endl;
			}
			break;
			case blofeld::_field_terminator:
			{
				stream << "\t\t{ _field_terminator }" << std::endl;
			}
			break;
			case blofeld::_field_char_enum:
			case blofeld::_field_short_enum:
			case blofeld::_field_long_enum:
			case blofeld::_field_long_flags:
			case blofeld::_field_word_flags:
			case blofeld::_field_byte_flags:
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				ASSERT(tag_field->get_string_list_definition());
				if (tag_field->get_string_list_definition())
				{
					stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << tag_field->get_string_list_definition()->get_code_symbol_name();
				}
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}

				stream << " }," << std::endl;
				break;
			default:
			{
				stream << "\t\t{ ";
				stream << field_generic_type_name << ", ";
				stream << "\"" << display_name.c_str() << "\"";
				if (write_description)
				{
					if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_units)
				{
					if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_limits)
				{
					if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
					else stream << ", " << "nullptr";
				}
				if (write_old_name)
				{
					stream << ", MAKE_ALT_NAMES(\"" << old_name.c_str() << "\")";
				}
				if (write_flags)
				{
					stream << ", ";
					write_tag_field_flags(stream, string_parser);
				}
				if (write_pointer) stream << ", " << "nullptr";
				if (write_tag)
				{
					stream << ", " << field_id_string;
				}
				stream << " }," << std::endl;
			}
			break;
			}
		}
	}
}

void c_blamtoozle_source_generator::write_tag_field_flags(std::stringstream& stream, c_blamlib_string_parser_v2& string_parser)
{
	unsigned long flags_written = 0;

	if (string_parser.flag_unknown0)
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_UNKNOWN0";
	}
	if (string_parser.flag_read_only)
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_READ_ONLY";
	}
	if (string_parser.flag_index)
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_INDEX";
	}
	if (string_parser.flag_unknown3)
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_UNKNOWN3";
	}
	if (string_parser.flag_pointer)
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_POINTER";
	}

	if (flags_written == 0)
	{
		stream << "FIELD_FLAG_NONE";
	}
}

void c_blamtoozle_source_generator::coerce_definitions()
{
#define coerce_definition(input, output, helpers) for (auto& definition : input) { output.emplace_back(definition); helpers.emplace_back(definition); }
	coerce_definition(tag_definition_manager.tag_group_definitions, group_definitions, group_definitions_helpers);
	coerce_definition(tag_definition_manager.tag_struct_definitions, struct_definitions, struct_definitions_helpers);
	coerce_definition(tag_definition_manager.tag_block_definitions, block_definitions, block_definitions_helpers);
	coerce_definition(tag_definition_manager.tag_reference_definitions, tag_reference_definitions, tag_reference_definitions_helpers);
	coerce_definition(tag_definition_manager.tag_array_definitions, array_definitions, array_definitions_helpers);
	coerce_definition(tag_definition_manager.string_list_definitions, string_list_definitions, string_list_definitions_helpers);
	coerce_definition(tag_definition_manager.tag_resource_definitions, resource_definitions, resource_definitions_helpers);
	coerce_definition(tag_definition_manager.tag_data_definitions, data_definitions, data_definitions_helpers);
	coerce_definition(tag_definition_manager.tag_api_interop_definitions, api_interop_definitions, api_interop_definitions_helpers);
	coerce_definition(tag_definition_manager.block_index_custom_search_definitions, block_index_custom_search_definitions, block_index_custom_search_definitions_helpers);
#undef coerce_definition
}

void c_blamtoozle_source_generator::clear_is_exported()
{
#define clear_definitions(generator_helpers) for (auto& generator_helper : generator_helpers) generator_helper.is_exported = false;
	clear_definitions(group_definitions_helpers);
	clear_definitions(struct_definitions_helpers);
	clear_definitions(block_definitions_helpers);
	clear_definitions(tag_reference_definitions_helpers);
	clear_definitions(array_definitions_helpers);
	clear_definitions(string_list_definitions_helpers);
	clear_definitions(resource_definitions_helpers);
	clear_definitions(data_definitions_helpers);
	clear_definitions(api_interop_definitions_helpers);
	clear_definitions(block_index_custom_search_definitions_helpers);
#undef clear_definitions
}

#define is_exported_helper(generator_helpers) \
{ \
	for (auto& generator_helper : generator_helpers) \
	{ \
		if (&definition == generator_helper.definition) \
		{ \
			bool is_exported = generator_helper.is_exported; \
			generator_helper.is_exported = true; \
			return is_exported; \
		} \
	} \
	FATAL_ERROR("couldn't find definition"); \
}

bool c_blamtoozle_source_generator::is_group_exported(c_blamtoozle_tag_group_definition& definition)											is_exported_helper(group_definitions_helpers);
bool c_blamtoozle_source_generator::is_block_exported(c_blamtoozle_tag_block_definition& definition)											is_exported_helper(block_definitions_helpers);
bool c_blamtoozle_source_generator::is_tag_reference_exported(c_blamtoozle_tag_reference_definition& definition)								is_exported_helper(tag_reference_definitions_helpers);
bool c_blamtoozle_source_generator::is_array_exported(c_blamtoozle_tag_array_definition& definition)											is_exported_helper(array_definitions_helpers);
bool c_blamtoozle_source_generator::is_struct_exported(c_blamtoozle_tag_struct_definition& definition)											is_exported_helper(struct_definitions_helpers);
bool c_blamtoozle_source_generator::is_data_exported(c_blamtoozle_tag_data_definition& definition)												is_exported_helper(data_definitions_helpers);
bool c_blamtoozle_source_generator::is_string_list_exported(c_blamtoozle_string_list_definition& definition)									is_exported_helper(string_list_definitions_helpers);
bool c_blamtoozle_source_generator::is_resource_exported(c_blamtoozle_tag_resource_definition& definition)										is_exported_helper(resource_definitions_helpers);
bool c_blamtoozle_source_generator::is_api_interop_exported(c_blamtoozle_tag_api_interop_definition& definition)								is_exported_helper(api_interop_definitions_helpers);
bool c_blamtoozle_source_generator::is_block_index_custom_search_exported(c_blamtoozle_tag_block_index_custom_search_definition& definition)	is_exported_helper(block_index_custom_search_definitions_helpers);

#undef is_exported_helper
