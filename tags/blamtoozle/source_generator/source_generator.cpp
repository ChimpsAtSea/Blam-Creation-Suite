#include "blamtoozle-private-pch.h"

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

static void escape_string(
	std::string& str,
	bool remove_return,
	bool unescaped_comma)
{
	char* destination = trivial_alloca(char, (str.size() + 1) * 2);
	escape_string(str.c_str(), destination, remove_return, unescaped_comma);
	str = destination;
}

c_blamtoozle_source_generator::c_blamtoozle_source_generator(
	c_blamtoozle_tag_definition_manager& _tag_definition_manager,
	const char* _engine_namespace,
	const char* _platform_namespace) :
	tag_definition_manager(_tag_definition_manager),
	engine_namespace(_strdup(_engine_namespace)),
	platform_namespace(_strdup(_platform_namespace)),
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
	stream << "namespace blofeld";
	if (engine_namespace)
	{
		stream << "::" << engine_namespace;
	}
	if (platform_namespace)
	{
		stream << "::" << platform_namespace;
	}
	stream << std::endl;
	stream << "{" << std::endl;
	stream << std::endl;

	for (auto& group_definition : group_definitions)
	{
		if (!is_group_exported(*group_definition))
		{
			union
			{
				uint64_t _byteswap_group_tag;
				char _group_tag_str[sizeof(_byteswap_group_tag)];
			};
			_byteswap_group_tag = _byteswap_ulong(group_definition->get_group_tag());
			const char* group_tag_string = _group_tag_str;
			while (*group_tag_string == 0)
			{
				group_tag_string++;
			}

			stream << "\tstatic constexpr uint32_t " << group_definition->get_group_tag_macro_name() << " = '" << group_tag_string << "';" << std::endl;
			stream << "\t" << "BCS_SHARED extern s_tag_group " << group_definition->get_code_symbol_name() << ";" << std::endl;
			//stream << "\t" << "BCS_SHARED extern s_tag_group " << group_definition->get_pretty_name() << "_group;" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& block_definition : block_definitions)
	{
		if (!is_block_exported(*block_definition))
		{
			stream << "\t" << "BCS_SHARED extern s_tag_block_definition " << block_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& array_definition : array_definitions)
	{
		if (!is_array_exported(*array_definition))
		{
			stream << "\t" << "BCS_SHARED extern s_tag_array_definition " << array_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& struct_definition : struct_definitions)
	{
		write_tag_struct_header(stream, *struct_definition);
	}

	for (auto& data_definition : data_definitions)
	{
		if (!is_data_exported(*data_definition))
		{
			stream << "\t" << "BCS_SHARED extern s_tag_data_definition " << data_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& resource_definition : resource_definitions)
	{
		if (!is_resource_exported(*resource_definition))
		{
			stream << "\t" << "BCS_SHARED extern s_tag_resource_definition " << resource_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& api_interop_definition : api_interop_definitions)
	{
		if (!is_api_interop_exported(*api_interop_definition))
		{
			stream << "\t" << "BCS_SHARED extern s_tag_interop_definition " << api_interop_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	for (auto& block_index_custom_search_definition : block_index_custom_search_definitions)
	{
		if (!is_block_index_custom_search_exported(*block_index_custom_search_definition))
		{
			stream << "\t" << "BCS_SHARED extern s_block_index_custom_search_definition " << block_index_custom_search_definition->get_code_symbol_name() << ";" << std::endl;

			stream << std::endl;
		}
	}

	stream << std::endl;
	stream << "} // namespace blofeld";
	if (engine_namespace)
	{
		stream << "::" << engine_namespace;
	}
	if (platform_namespace)
	{
		stream << "::" << platform_namespace;
	}
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
				if (c_blamtoozle_string_list_definition* string_list_definition = tag_field->get_string_list_definition())
				{
					if (!is_string_list_exported(*string_list_definition))
					{
						stream << "\t" << "BCS_SHARED extern s_string_list_definition " << string_list_definition->get_code_symbol_name() << ";";
						stream << std::endl;
					}
				}
				else
				{
					std::string const& field_name = tag_field->get_name();
					console_write_line("Failed to export null string list definition for field '%s'", field_name.c_str());
				}
				break;
			case blofeld::_field_tag_reference:
				if (c_blamtoozle_tag_reference_definition* tag_reference_definition = tag_field->get_tag_reference_definition())
				{
					if (!is_tag_reference_exported(*tag_reference_definition))
					{
						stream << "\t" << "BCS_SHARED extern s_tag_reference_definition " << tag_reference_definition->get_code_symbol_name() << ";";
						stream << std::endl;
					}
				}
				else
				{
					std::string const& field_name = tag_field->get_name();
					console_write_line("Failed to export null tag reference definition for field '%s'", field_name.c_str());
				}
				break;
			}
		}
	}
}

void c_blamtoozle_source_generator::write_string_list_header(std::stringstream& stream, c_blamtoozle_string_list_definition& string_list_definition)
{
	throw;
}

void c_blamtoozle_source_generator::write_string_list_source(std::stringstream& stream, c_blamtoozle_string_list_definition& string_list_definition)
{
	if (!is_string_list_exported(string_list_definition))
	{
		if (string_list_definition.options.size() > 0)
		{
			stream << "\tSTRINGS(" << string_list_definition.get_code_symbol_name() << ")" << std::endl;
			stream << "\t{" << std::endl;
			for (uint32_t i = 0; i < string_list_definition.options.size(); i++)
			{
				std::string option = string_list_definition.options[i];
				std::string escaped_option = escape_string(option);
				if (escaped_option.empty()) escaped_option = "unused";
				if (i != string_list_definition.options.size() - 1)
				{
					stream << "\t\t\"" << escaped_option << "\"," << std::endl;
				}
				else
				{
					stream << "\t\t\"" << escaped_option << "\"" << std::endl;
				}
			}
			stream << "\t};" << std::endl;

			stream << "\tSTRING_LIST(" << string_list_definition.get_code_symbol_name() << ", " << string_list_definition.get_code_symbol_name() << "_strings, _countof(" << string_list_definition.get_code_symbol_name() << "_strings));" << std::endl;
		}
		else
		{
			stream << "\tSTRING_LIST(" << string_list_definition.get_code_symbol_name() << ", empty_string_list, 0);" << std::endl;
		}

		stream << std::endl;
	}
}

void c_blamtoozle_source_generator::write_tag_reference_header(std::stringstream& stream, c_blamtoozle_tag_reference_definition& tag_reference_definition)
{
	throw;
}

void c_blamtoozle_source_generator::write_tag_reference_source(std::stringstream& stream, c_blamtoozle_tag_reference_definition& tag_reference_definition)
{
	if (!is_tag_reference_exported(tag_reference_definition))
	{
		if (tag_reference_definition.group_tags.size() > 1)
		{
			stream << "\tTAG_REFERENCE_GROUP(" << tag_reference_definition.get_code_symbol_name();
			write_tag_reference_flags(stream, tag_reference_definition);
			stream << ")" << std::endl;
			stream << "\t{" << std::endl;
			bool first = true;
			if (tag_reference_definition.tag_group_definitions.empty())
			{
				for (tag group_tag : tag_reference_definition.group_tags)
				{
					c_blamtoozle_tag_group_definition* group_definition = tag_definition_manager.get_tag_group_definition_by_group_tag(group_tag);
					if (group_definition == nullptr)
					{
						tag group_tag_swapped = byteswap(group_tag);
						console_write_line_verbose("Failed to get tag group for tag reference group_tag:'%.4s'", reinterpret_cast<char*>(&group_tag_swapped));
						throw BCS_E_FATAL;
					}
					stream << "\t\t" << group_definition->get_group_tag_macro_name() << "," << std::endl;
					first = false;
				}
			}
			else
			{
				for (c_blamtoozle_tag_group_definition* group_definition : tag_reference_definition.tag_group_definitions)
				{
					stream << "\t\t" << group_definition->get_group_tag_macro_name() << "," << std::endl;
					first = false;
				}
			}
			stream << "\t\tINVALID_TAG" << std::endl;

			stream << "\t};" << std::endl;
		}
		else if (__max(tag_reference_definition.group_tags.size(), tag_reference_definition.tag_group_definitions.size()) == 1)
		{
			if (!tag_reference_definition.tag_group_definitions.empty())
			{
				std::vector<c_blamtoozle_tag_group_definition*>::iterator first_group_iterator = tag_reference_definition.tag_group_definitions.begin();
				stream << "\tTAG_REFERENCE(" << tag_reference_definition.get_code_symbol_name() << ", " << (*first_group_iterator)->get_group_tag_macro_name();
				write_tag_reference_flags(stream, tag_reference_definition);
				stream << ");" << std::endl;
			}
			else
			{
				std::vector<tag>::iterator first_group_iterator = tag_reference_definition.group_tags.begin();
				tag group_tag = *first_group_iterator;
				c_blamtoozle_tag_group_definition* tag_group_definition = tag_definition_manager.get_tag_group_definition_by_group_tag(group_tag);
				if (tag_group_definition == nullptr)
				{
					tag group_tag_swapped = byteswap(group_tag);
					console_write_line_verbose("Failed to get tag group for tag reference group_tag:'%.4s'", reinterpret_cast<char*>(&group_tag_swapped));
					throw BCS_E_FATAL;
				}
				stream << "\tTAG_REFERENCE(" << tag_reference_definition.get_code_symbol_name() << ", " << tag_group_definition->get_group_tag_macro_name();
				write_tag_reference_flags(stream, tag_reference_definition);
				stream << ");" << std::endl;
			}
		}
		else
		{
			stream << "\tTAG_REFERENCE(" << tag_reference_definition.get_code_symbol_name() << ", INVALID_TAG";
			write_tag_reference_flags(stream, tag_reference_definition);
			stream << ");" << std::endl;
		}

		stream << std::endl;
	}
}

void c_blamtoozle_source_generator::write_tag_struct_header(std::stringstream& stream, c_blamtoozle_tag_struct_definition& tag_struct_definition)
{
	if (!is_struct_exported(tag_struct_definition))
	{
		stream << "\t" << "BCS_SHARED extern s_tag_struct_definition " << tag_struct_definition.get_code_symbol_name() << ";" << std::endl;

		for (c_blamtoozle_tag_struct_definition* version_definition = &tag_struct_definition.get_latest_struct_definition(); version_definition != nullptr; version_definition = version_definition->get_previous_struct_definition())
		{
			write_tag_types_header(stream, version_definition->fields);
		}

		stream << std::endl;
	}
}

void c_blamtoozle_source_generator::write_persistent_identifier_macro(
	std::stringstream& stream,
	const blofeld::s_tag_persistent_identifier& persistent_identifier,
	const char* code_symbol_name,
	std::string& persistent_identifier_macro_name)
{
	persistent_identifier_macro_name = "PERSISTENT_ID_EMPTY";
	if (persistent_identifier.identifier_part_0 != 0 ||
		persistent_identifier.identifier_part_1 != 0 ||
		persistent_identifier.identifier_part_2 != 0 ||
		persistent_identifier.identifier_part_3 != 0)
	{
		persistent_identifier_macro_name = code_symbol_name;
		persistent_identifier_macro_name += "_id";
		std::transform(
			persistent_identifier_macro_name.begin(),
			persistent_identifier_macro_name.end(),
			persistent_identifier_macro_name.begin(),
			::toupper);

		if (persistent_identifier.identifier_part_0 == UINT_MAX &&
			persistent_identifier.identifier_part_1 == UINT_MAX &&
			persistent_identifier.identifier_part_2 == UINT_MAX &&
			persistent_identifier.identifier_part_3 == UINT_MAX)
		{
			stream << "\t#define " << persistent_identifier_macro_name << " PERSISTENT_ID_UNKNOWN" << std::endl;
		}
		else if (persistent_identifier.identifier_part_0 == 0 &&
			persistent_identifier.identifier_part_1 == 0 &&
			persistent_identifier.identifier_part_2 == 0 &&
			persistent_identifier.identifier_part_3 == 0)
		{
			stream << "\t#define " << persistent_identifier_macro_name << " PERSISTENT_ID_EMPTY" << std::endl;
		}
		else
		{
			stream << "\t#define " << persistent_identifier_macro_name << " { ";
			stream << std::hex << std::uppercase;
			stream << "0x" << persistent_identifier.identifier_part_0 << ", ";
			stream << "0x" << persistent_identifier.identifier_part_1 << ", ";
			stream << "0x" << persistent_identifier.identifier_part_2 << ", ";
			stream << "0x" << persistent_identifier.identifier_part_3;
			stream << std::dec << std::nouppercase;
			stream << " }" << std::endl;
		}
	}
}

void c_blamtoozle_source_generator::write_tag_struct_source(std::stringstream& stream, c_blamtoozle_tag_struct_definition& tag_struct_definition)
{
	if (!is_struct_exported(tag_struct_definition))
	{
		std::string persistent_identifier_macro_name;
		write_persistent_identifier_macro(
			stream,
			tag_struct_definition.get_persistent_identifier(),
			tag_struct_definition.get_code_symbol_name(),
			persistent_identifier_macro_name);

		c_flags<blofeld::e_tag_field_set_bit> flags = tag_struct_definition.get_field_set_bits();
		bool is_legacy_struct = tag_struct_definition.is_legacy_struct() || flags.test(blofeld::_tag_field_set_mandrill_has_versioning);

		if (is_legacy_struct)
		{
			stream << "\tVERSIONED_TAG_STRUCT(" << std::endl;
		}
		else
		{
			stream << "\tTAG_STRUCT(" << std::endl;
		}
		stream << "\t\t" << tag_struct_definition.get_code_symbol_name() << "," << std::endl;
		stream << "\t\t" << "\"" << tag_struct_definition.get_pretty_name() << "\"," << std::endl;
		stream << "\t\t" << "\"" << tag_struct_definition.get_name() << "\"," << std::endl;
		stream << "\t\t" << "\"" << tag_struct_definition.get_structure_type_name() << "\"," << std::endl;

		c_flags<blofeld::e_tag_field_set_bit> default_flags;
		default_flags.set(blofeld::_tag_field_set_unknown0_bit, true);
		default_flags.set(blofeld::_tag_field_set_unknown1_bit, true);
		default_flags.set(blofeld::_tag_field_set_has_aggregate_types_bit, true);
		default_flags.set(blofeld::_tag_field_set_delete_recursively_bit, true);
		default_flags.set(blofeld::_tag_field_set_postprocess_recursively_bit, true);

		flags.set(blofeld::_tag_field_set_mandrill_has_versioning, false);
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
		stream << "\t\t" << persistent_identifier_macro_name;
		if (tag_struct_definition.get_alignment_bits())
		{
			stream << "," << std::endl;
			stream << "\t\t" << tag_struct_definition.get_alignment_bits();
		}
		stream << ")" << std::endl;
		stream << "\t" << "{" << std::endl;

		for (
			c_blamtoozle_tag_struct_definition* version_definition = &tag_struct_definition.get_latest_struct_definition();
			version_definition != nullptr;
			version_definition = version_definition->get_previous_struct_definition())
		{
			bool is_legacy_struct = version_definition->is_legacy_struct();
			if (is_legacy_struct)
			{
				size_t num_fields = version_definition->fields.size() - 1; // exclude terminator
				if (version_definition->is_latest_structure_version())
				{
					stream << "\t\t{ _struct_version_mode_greater_or_equal, " << version_definition->get_structure_version() << ", " << num_fields << " }," << std::endl;
				}
				else
				{
					stream << "\t\t{ _struct_version_mode_equal, " << version_definition->get_structure_version() << ", " << num_fields << " }," << std::endl;
				}
			}

			bool is_last = version_definition->get_previous_struct_definition() == nullptr;

			c_flags<blofeld::e_tag_field_set_bit> flags = version_definition->get_field_set_bits();
			bool is_versioned_struct = flags.test(blofeld::_tag_field_set_mandrill_has_versioning);
			bool terminator_new_line = is_legacy_struct || is_versioned_struct;
			write_fields(stream, version_definition->fields, is_last, terminator_new_line);

			if (!is_last)
			{
				stream << std::endl;
			}
		}

		stream << "\t" << "};" << std::endl;
		stream << std::endl;

		for (c_blamtoozle_tag_struct_definition* version_definition = &tag_struct_definition.get_latest_struct_definition(); version_definition != nullptr; version_definition = version_definition->get_previous_struct_definition())
		{
			write_tag_types_source(stream, version_definition->fields);
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
				if (c_blamtoozle_string_list_definition* string_list_definition = tag_field->get_string_list_definition())
				{
					ASSERT(string_list_definition != nullptr);
					write_string_list_source(stream, *string_list_definition);
				}
				else
				{
					std::string const& field_name = tag_field->get_name();
					console_write_line("Failed to export null string list definition for field '%s'", field_name.c_str());
				}
				break;
			case blofeld::_field_tag_reference:
				if (c_blamtoozle_tag_reference_definition* tag_reference_definition = tag_field->get_tag_reference_definition())
				{
					ASSERT(tag_reference_definition != nullptr);
					write_tag_reference_source(stream, *tag_reference_definition);
				}
				else
				{
					std::string const& field_name = tag_field->get_name();
					console_write_line("Failed to export null tag reference definition for field '%s'", field_name.c_str());
				}
				break;
			}
		}
	}
}

void c_blamtoozle_source_generator::write_tag_group_flags(std::stringstream& stream, c_blamtoozle_tag_group_definition& tag_group_definition)
{
	std::stringstream flags_stream;

	blofeld::f_tag_group_flags flags = tag_group_definition.get_tag_group_flags();

	if (flags.test(blofeld::_tag_group_flag_is_game_critical))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_IS_GAME_CRITICAL";
	}
	if (flags.test(blofeld::_tag_group_flag_can_be_reloaded))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_CAN_BE_RELOADED";
	}
	if (flags.test(blofeld::_tag_group_flag_forces_map_reload))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_FORCES_MAP_RELOAD";
	}
	if (flags.test(blofeld::_tag_group_flag_forces_lighting_reset))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_FORCES_LIGHTING_RESET";
	}
	if (flags.test(blofeld::_tag_group_flag_does_not_exist_in_cache_build))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_DOES_NOT_EXIST_IN_CACHE_BUILD";
	}
	if (flags.test(blofeld::_tag_group_flag_can_save_when_not_loaded_for_editing))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_CAN_SAVE_WHEN_NOT_LOADED_FOR_EDITING";
	}
	if (flags.test(blofeld::_tag_group_flag_do_not_attempt_to_predict_on_cache_miss))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_DO_NOT_ATTEMPT_TO_PREDICT_ON_CACHE_MISS";
	}
	if (flags.test(blofeld::_tag_group_flag_do_not_attempt_to_predict_through_dependencies))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_DO_NOT_ATTEMPT_TO_PREDICT_THROUGH_DEPENDENCIES";
	}
	if (flags.test(blofeld::_tag_group_flag_do_not_attempt_to_predict_children))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_DO_NOT_ATTEMPT_TO_PREDICT_CHILDREN";
	}
	if (flags.test(blofeld::_tag_group_flag_do_not_xsync_to_target_platform))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_DO_NOT_XSYNC_TO_TARGET_PLATFORM";
	}
	if (flags.test(blofeld::_tag_group_flag_restricted_on_xsync))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_RESTRICTED_ON_XSYNC";
	}
	if (flags.test(blofeld::_tag_group_flag_create_as_global_cache_file_tag))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_CREATE_AS_GLOBAL_CACHE_FILE_TAG";
	}
	if (flags.test(blofeld::_tag_group_flag_do_not_add_children_to_global_zone))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_DO_NOT_ADD_CHILDREN_TO_GLOBAL_ZONE";
	}
	if (flags.test(blofeld::_tag_group_flag_invalidates_structure_materials))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_INVALIDATES_STRUCTURE_MATERIALS";
	}
	if (flags.test(blofeld::_tag_group_flag_children_resolved_manually))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_CHILDREN_RESOLVED_MANUALLY";
	}
	if (flags.test(blofeld::_tag_group_flag_forces_script_recompile))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_FORCES_SCRIPT_RECOMPILE";
	}
	if (flags.test(blofeld::_tag_group_flag_forces_active_zone_set_reload))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_FORCES_ACTIVE_ZONE_SET_RELOAD";
	}
	if (flags.test(blofeld::_tag_group_flag_restricted_forces_active_zone_set_reload))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_RESTRICTED_FORCES_ACTIVE_ZONE_SET_RELOAD";
	}
	if (flags.test(blofeld::_tag_group_flag_cannot_be_created))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_CANNOT_BE_CREATED";
	}
	if (flags.test(blofeld::_tag_group_flag_should_not_be_used_as_a_resolving_reference))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_SHOULD_NOT_BE_USED_AS_A_RESOLVING_REFERENCE";
	}
	if (flags.test(blofeld::_tag_group_flag_do_not_make_script_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_DO_NOT_MAKE_SCRIPT_DEPENDENCY";
	}
	if (flags.test(blofeld::_tag_group_flag_do_not_write_out_until_cache_file_link_time))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_DO_NOT_WRITE_OUT_UNTIL_CACHE_FILE_LINK_TIME";
	}
	if (flags.test(blofeld::_tag_group_flag_not_language_neutral))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_NOT_LANGUAGE_NEUTRAL";
	}
	if (flags.test(blofeld::_tag_group_flag_invalidates_structure_bsp_geometry))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_INVALIDATES_STRUCTURE_BSP_GEOMETRY";
	}
	if (flags.test(blofeld::_tag_group_flag_discard_for_dedicated_server))
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_DISCARD_FOR_DEDICATED_SERVER";
	}
	if (flags.is_clear())
	{
		if (!flags_stream.str().empty()) flags_stream << " | " << std::endl;
		flags_stream << "\t\tTAG_GROUP_FLAG_NONE";
	}
	std::string flags_string = flags_stream.str();
	if (!flags_string.empty())
	{
		stream << flags_string;
	}
}

void c_blamtoozle_source_generator::write_tag_reference_flags(std::stringstream& stream, c_blamtoozle_tag_reference_definition& tag_reference_definition)
{
	// #TODO: The conversion from flag to string could be improved here

	std::stringstream flags_stream;

	blofeld::f_tag_reference_flags flags = tag_reference_definition.get_tag_reference_flags();

	if (flags.test(blofeld::_tag_reference_flag_not_a_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "TAG_REFERENCE_FLAG_NOT_A_DEPENDENCY";
	}
	if (flags.test(blofeld::_tag_reference_flag_dont_resolve_in_editor))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "TAG_REFERENCE_FLAG_DONT_RESOLVE_IN_EDITOR";
	}
	if (flags.test(blofeld::_tag_reference_flag_resolved_manually))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "TAG_REFERENCE_FLAG_RESOLVED_MANUALLY";
	}
	if (flags.test(blofeld::_tag_reference_flag_resolved_by_game))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "TAG_REFERENCE_FLAG_RESOLVED_BY_GAME";
	}
	if (flags.test(blofeld::_tag_reference_flag_not_a_resource_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "TAG_REFERENCE_FLAG_NOT_A_RESOURCE_DEPENDENCY";
	}
	if (flags.test(blofeld::_tag_reference_flag_dependency_for_cache_file_sharing))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "TAG_REFERENCE_FLAG_DEPENDENCY_FOR_CACHE_FILE_SHARING";
	}
	if (flags.test(blofeld::_tag_reference_flag_reference_ignored_by_bundle_builder))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "TAG_REFERENCE_FLAG_REFERENCE_IGNORED_BY_BUNDLE_BUILDER";
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

	stream << "#include <" << engine_namespace << "tagdefinitions-private-pch.h>" << std::endl;
	stream << "#include <TagFramework\\Definitions\\definitions.h>" << std::endl;
	stream << std::endl;
	stream << "namespace blofeld";
	if (engine_namespace)
	{
		stream << "::" << engine_namespace;
	}
	if (platform_namespace)
	{
		stream << "::" << platform_namespace;
	}
	stream << std::endl;
	stream << "{" << std::endl;
	stream << std::endl;

	for (auto& group_definition : group_definitions)
	{
		if (!is_group_exported(*group_definition))
		{
			c_blamtoozle_tag_block_definition& block_definition = group_definition->get_block_definition();
			c_blamtoozle_tag_struct_definition& struct_definition = block_definition.get_struct_definition();

			stream << "\tTAG_GROUP(" << std::endl;
			stream << "\t\t" << "\"" << group_definition->get_name() << "\"," << std::endl;
			stream << "\t\t" << group_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << group_definition->get_group_tag_macro_name() << "," << std::endl;
			stream << "\t\t" << group_definition->get_version() << "," << std::endl;
			if (c_blamtoozle_tag_group_definition* parent_group_definition = tag_definition_manager.get_tag_group_definition_by_group_tag(group_definition->get_parent_group_tag()))
			{
				stream << "\t\t&" << parent_group_definition->get_code_symbol_name() << "," << std::endl;
			}
			else
			{
				stream << "\t\t" << "nullptr," << std::endl;
			}
			stream << "\t\t" << block_definition.get_code_symbol_name() << "," << std::endl;
			write_tag_group_flags(stream, *group_definition); stream << ");" << std::endl;
			stream << std::endl;
		}
	}
	for (auto& block_definition : block_definitions)
	{
		if (!is_block_exported(*block_definition))
		{
			c_blamtoozle_tag_struct_definition& struct_definition = block_definition->get_struct_definition();

			stream << "\tTAG_BLOCK_FROM_STRUCT(" << std::endl;
			stream << "\t\t" << block_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << "\"" << block_definition->get_pretty_name() << "\"," << std::endl;
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
		write_tag_struct_source(stream, *struct_definition);
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

			std::string persistent_identifier_macro_name;
			write_persistent_identifier_macro(
				stream,
				api_interop_definition->get_persistent_identifier(),
				api_interop_definition->get_code_symbol_name(),
				persistent_identifier_macro_name);

			stream << "\tTAG_INTEROP(" << std::endl;
			stream << "\t\t" << api_interop_definition->get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << "\"" << api_interop_definition->get_code_symbol_name() << "\"," << std::endl;
			stream << "\t\t" << struct_definition.get_code_symbol_name() << "," << std::endl;
			stream << "\t\t" << persistent_identifier_macro_name << ");" << std::endl;
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
	stream << "} // namespace blofeld";
	if (engine_namespace)
	{
		stream << "::" << engine_namespace;
	}
	if (platform_namespace)
	{
		stream << "::" << platform_namespace;
	}
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
	stream << "namespace blofeld";
	if (engine_namespace)
	{
		stream << "::" << engine_namespace;
	}
	if (platform_namespace)
	{
		stream << "::" << platform_namespace;
	}
	stream << std::endl;
	stream << "{" << std::endl;
	stream << std::endl;

	stream << "\t" << "BCS_SHARED extern s_tag_group const* const tag_groups[];" << std::endl;

	stream << std::endl;
	stream << "} // namespace blofeld";
	if (engine_namespace)
	{
		stream << "::" << engine_namespace;
	}
	if (platform_namespace)
	{
		stream << "::" << platform_namespace;
	}
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
	stream << "namespace blofeld";
	if (engine_namespace)
	{
		stream << "::" << engine_namespace;
	}
	if (platform_namespace)
	{
		stream << "::" << platform_namespace;
	}
	stream << std::endl;
	stream << "{" << std::endl;
	stream << std::endl;

	stream << "\t" << "s_tag_group const* const tag_groups[] =" << std::endl;
	stream << "\t" << "{" << std::endl;
	for (auto& group_definition : group_definitions)
	{
		if (!is_group_exported(*group_definition))
		{
			stream << "\t\t" << "&" << group_definition->get_code_symbol_name() << "," << std::endl;
		}
	}
	stream << "\t" << "};" << std::endl;

	stream << std::endl;
	stream << "} // namespace blofeld";
	if (engine_namespace)
	{
		stream << "::" << engine_namespace;
	}
	if (platform_namespace)
	{
		stream << "::" << platform_namespace;
	}
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
	case blofeld::_tag_field_set_has_aggregate_types_bit:							return "SET_UNKNOWN5";
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
	case blofeld::_tag_field_set_exist_in_cache_build_bit:							return "SET_EXIST_IN_CACHE_BUILD";
	case blofeld::_tag_field_set_mandrill_has_versioning:							return "SET_MANDRILL_VERSIONING";
	}
	throw;
}

void c_blamtoozle_source_generator::write_fields(std::stringstream& stream, c_blamtoozle_tag_struct_definition::t_fields& fields, bool write_terminator, bool terminator_extra_new_line)
{
	//for (auto& _field : fields)
	for (size_t field_index = 0; field_index < fields.size(); field_index++)
	{
		t_blamtoozle_tag_field* blamtoozle_field = fields[field_index];

		if (c_blamtoozle_tag_field_combined_fixup* combined_fixup_field = dynamic_cast<c_blamtoozle_tag_field_combined_fixup*>(blamtoozle_field))
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
		else if (c_blamtoozle_tag_field_dummy_space* dummy_space_field = dynamic_cast<c_blamtoozle_tag_field_dummy_space*>(blamtoozle_field))
		{
			stream << std::endl;
		}
		else if (c_blamtoozle_tag_field* tag_field = dynamic_cast<c_blamtoozle_tag_field*>(blamtoozle_field))
		{
			blofeld::e_field field_type = tag_field->get_field_type();
			if (field_type == blofeld::_field_version)
			{
				if (field_index > 0)
				{
					stream << std::endl;
				}
				stream << "\t\t";
				blofeld::s_tag_field_versioning const& versioning = tag_field->get_tag_field_versioning();
				switch (versioning.mode)
				{
				case blofeld::_version_mode_invalid:
					stream << "{ _version_mode_invalid },";
					throw BCS_E_FATAL;
				case blofeld::_version_mode_custom:
					stream << "{ _version_mode_custom },";
					break;
				case blofeld::_version_mode_platform_include:
					stream << "{ _version_mode_platform_include },";
					break;
				case blofeld::_version_mode_platform_exclude:
					stream << "{ _version_mode_platform_exclude },";
					break;
				case blofeld::_version_mode_equal:
					stream << "{ _version_mode_equal },";
					break;
				case blofeld::_version_mode_not_equal:
					stream << "{ _version_mode_not_equal },";
					break;
				case blofeld::_version_mode_less:
					stream << "{ _version_mode_less },";
					break;
				case blofeld::_version_mode_greater:
					stream << "{ _version_mode_greater },";
					break;
				case blofeld::_version_mode_less_or_equal:
					stream << "{ _version_mode_less_or_equal },";
					break;
				case blofeld::_version_mode_greater_or_equal:
					stream << "{ _version_mode_greater_or_equal },";
					break;
				case blofeld::_version_mode_tag_group_equal:
					stream << "{ _version_mode_tag_group_equal },";
					break;
				case blofeld::_version_mode_tag_group_not_equal:
					stream << "{ _version_mode_tag_group_not_equal },";
					break;
				case blofeld::_struct_version_mode_equal:
					stream << "{ _struct_version_mode_equal, " << versioning.struct_version << ", " << versioning.version_field_skip_count << " },";
					break;
				case blofeld::_struct_version_mode_greater_or_equal:
					stream << "{ _struct_version_mode_greater_or_equal, " << versioning.struct_version << ", " << versioning.version_field_skip_count << " },";
					break;
				default:
					console_write_line("Unsupported version mode");
					throw BCS_E_FATAL;
				}
				stream << std::endl;
			}
			else
			{
				const char* field_generic_type_name;
				BCS_RESULT rs = blofeld::field_to_string(field_type, field_generic_type_name);
				ASSERT(BCS_SUCCEEDED(rs));

				std::string name = tag_field->get_name();
				std::string description = tag_field->get_description();
				std::string units = tag_field->get_units();
				std::string limits = tag_field->get_limits();
				std::string limits_legacy = tag_field->get_limits_legacy();
				std::vector<std::string> old_names = tag_field->get_old_names();
				blofeld::f_tag_field_flags flags = tag_field->get_field_flags();

				escape_string(name, true, true);
				escape_string(description, true, true);
				escape_string(units, true, true);
				escape_string(limits, true, true);
				escape_string(limits_legacy, true, true);
				for (std::string& old_name : old_names)
				{
					escape_string(old_name, true, true);
				}

				if (name.empty())
				{
					name = "value";
				}

				blofeld::e_tag_field_attributed_definition tag_field_attributed_definition = blofeld::_tag_field_attributed_definition_unknown_type;
				blofeld::e_tag_field_custom_type tag_field_custom_type = blofeld::_tag_field_custom_type_unknown_type;
				blofeld::e_field_id field_id = blofeld::_field_id_default;

				bool write_tag_field_attributed_definition = tag_field->get_tag_field_attributed_definition(tag_field_attributed_definition) && tag_field_attributed_definition;
				bool write_tag_field_custom_type = tag_field->get_tag_field_custom_type(tag_field_custom_type) && tag_field_custom_type;
				bool write_tag_field_id = tag_field->get_tag_field_id(field_id) && field_id;

				bool write_limits = !limits.empty();
				bool write_units = write_limits || !units.empty();
				bool write_description = write_units || !description.empty();
				bool write_old_name = !old_names.empty();
				bool write_flags = !flags.is_clear();
				bool write_pointer = false; // todo
				bool write_tag = write_tag_field_attributed_definition || write_tag_field_custom_type || write_tag_field_id;

				const char* field_id_string = "_field_id_default";
				if (write_tag_field_attributed_definition)
				{
					field_id_string = blofeld::tag_field_attributed_definition_to_string(tag_field_attributed_definition);
				}
				else if (write_tag_field_custom_type)
				{
					field_id_string = blofeld::tag_field_custom_type_to_string(tag_field_custom_type);
				}
				else if (write_tag_field_id)
				{
					field_id_string = blofeld::field_id_to_string(field_id);
				}
				ASSERT(field_id_string != nullptr);

				switch (field_type)
				{
				case blofeld::_field_custom:
				{
					ASSERT(!write_flags);

					if (tag_field_custom_type == blofeld::_tag_field_custom_type_field_group_begin)
					{
						ASSERT(!name.empty());
						ASSERT(description.empty());
						stream << "\t\tFIELD_GROUP_BEGIN(";
						if(!name.empty()) stream << "\"" << name.c_str() << "\"";
						else stream << "nullptr";
						stream << ")," << std::endl;
					}
					else if (tag_field_custom_type == blofeld::_tag_field_custom_type_field_group_end)
					{
						//ASSERT(display_name == "value" || display_name.empty());
						ASSERT(description.empty());

						if (name.empty() || strcmp(name.c_str(), "value") == 0) // #TODO: improve this with function
						{
							stream << "\t\tFIELD_GROUP_END()," << std::endl;
						}
						else
						{
							stream << "\t\tFIELD_GROUP_END2(";
							stream << "\"" << name.c_str() << "\"";
							stream << ")," << std::endl;
						}

						//stream << "\t\tFIELD_GROUP_END(";
						//if (!display_name.empty() && strcmp(display_name, "value") != 0) stream << "\"" << display_name.c_str() << "\"";
						//stream << ")," << std::endl;
					}
					else if (tag_field_custom_type == blofeld::_tag_field_custom_type_hide_group_begin)
					{
						ASSERT(name.empty() || name == "value");
						ASSERT(description.empty());
						stream << "\t\tFIELD_HIDE_BEGIN(";
						if (!name.empty() && name != "value") stream << "\"" << name.c_str() << "\"";
						stream << ")," << std::endl;
					}
					else if (tag_field_custom_type == blofeld::_tag_field_custom_type_hide_group_end)
					{
						ASSERT(name.empty() || name == "value");
						ASSERT(description.empty());
						stream << "\t\tFIELD_HIDE_END(";
						if (!name.empty() && name != "value") stream << "\"" << name.c_str() << "\"";
						stream << ")," << std::endl;
					}
					else if (tag_field_custom_type == blofeld::_tag_field_custom_type_individual_field_preview_group_begin)
					{
						ASSERT(name.empty() || name == "value");
						ASSERT(description.empty());
						stream << "\t\tFIELD_IFP_BEGIN(";
						if (!name.empty() && name != "value") stream << "\"" << name.c_str() << "\"";
						stream << ")," << std::endl;
					}
					else if (tag_field_custom_type == blofeld::_tag_field_custom_type_individual_field_preview_group_end)
					{
						ASSERT(name.empty() || name == "value");
						ASSERT(description.empty());
						stream << "\t\tFIELD_IFP_END(";
						if (!name.empty() && name != "value") stream << "\"" << name.c_str() << "\"";
						stream << ")," << std::endl;
					}
					else if (field_id == blofeld::_field_id_dont_checksum_begin)
					{
						ASSERT(name.empty() || name == "value");
						ASSERT(description.empty());
						stream << "\t\tFIELD_DONT_CHECKSUM_BEGIN(";
						if (!name.empty() && name != "value") stream << "\"" << name.c_str() << "\"";
						stream << ")," << std::endl;
					}
					else if (field_id == blofeld::_field_id_dont_checksum_end)
					{
						ASSERT(name.empty() || name == "value");
						ASSERT(description.empty());
						stream << "\t\tFIELD_DONT_CHECKSUM_END(";
						if (!name.empty() && name != "value") stream << "\"" << name.c_str() << "\"";
						stream << ")," << std::endl;
					}
					else
					{
						stream << "\t\tFIELD_CUSTOM(";
						if (!name.empty())
						{
							if (!name.empty()) stream << "\"" << name.c_str() << "\"";
						}
						/*if (!description.empty())
						{
							if (!description.empty()) stream << ", \"" << description.c_str() << "\"";
						*/
						stream << ", " << (field_id_string ? field_id_string : "_field_id_default");
						if (write_flags)
						{
							write_tag_field_flags(stream, flags);
						}
						stream << ")," << std::endl;
					}
					break;
				}
				case blofeld::_field_useless_pad:
				{
					ASSERT(!write_limits);
					ASSERT(!write_units);

					stream << "\t\tFIELD_USELESS_PAD(";
					if (!name.empty())
					{
						if (!name.empty()) stream << "\"" << name.c_str() << "\"";
					}
					if (!description.empty())
					{
						if (!description.empty()) stream << ", \"" << description.c_str() << "\"";
					}
					stream << ", " << tag_field->get_padding();
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
					}
					stream << "),";
					if (write_tag)
					{
						stream << " // " << field_id_string;
					}
					stream << std::endl;
				}
				break;
				case blofeld::_field_pad:
				{
					ASSERT(!write_limits);
					ASSERT(!write_units);

					if (!description.empty() || write_flags || write_tag)
					{
						stream << "\t\tFIELD_PAD_EX(";
						if (!name.empty())
						{
							stream << "\"" << name.c_str() << "\"";
						}
						else
						{
							stream << "nullptr";
						}
						if (!description.empty())
						{
							stream << ", \"" << description.c_str() << "\"";
						}
						else
						{
							stream << ", nullptr";
						}
						write_tag_field_flags(stream, flags);
						stream << ", " << tag_field->get_padding();
						stream << ", " << field_id_string;
						stream << ")," << std::endl;
					}
					else
					{
						stream << "\t\tFIELD_PAD(";
						if (!name.empty())
						{
							stream << "\"" << name.c_str() << "\"";
						}
						else
						{
							stream << "nullptr";
						}
						stream << ", " << tag_field->get_padding() << ")," << std::endl;
					}
				}
				break;
				case blofeld::_field_skip:
				{
					ASSERT(!write_limits);
					ASSERT(!write_units);
					ASSERT(!write_flags);

					stream << "\t\tFIELD_SKIP(";
					if (!name.empty())
					{
						if (!name.empty()) stream << "\"" << name.c_str() << "\"";
					}
					if (!description.empty())
					{
						if (!description.empty()) stream << ", \"" << description.c_str() << "\"";
					}
					stream << ", " << tag_field->get_skip_length();
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
					}
					stream << "),";
					if (write_tag)
					{
						stream << " // " << field_id_string;
					}
					stream << std::endl;
				}
				break;
				case blofeld::_field_explanation:
				{

					stream << "\t\tFIELD_EXPLANATION(";
					if (!name.empty())
					{
						if (!name.empty()) stream << "\"" << name.c_str() << "\"";
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
						write_tag_field_flags(stream, flags);
					}
					stream << ")," << std::endl;
				}
				break;
				case blofeld::_field_array:
				{
					stream << "\t\t{ ";
					stream << field_generic_type_name << ", ";
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						stream << ", ";
						write_tag_field_flags(stream, flags);
					}
					if (c_blamtoozle_tag_array_definition* array_definition = tag_field->get_array_definition())
					{
						stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << array_definition->get_code_symbol_name();
					}
					else
					{
						std::string const& field_name = tag_field->get_name();
						console_write_line("Failed to export null tag array definition for field '%s'", field_name.c_str());
					}
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
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
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
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
					}

					c_blamtoozle_tag_struct_definition* field_struct_definition = tag_field->get_struct_definition();
					if (field_struct_definition)
					{
						c_blamtoozle_tag_struct_definition& latest_struct_definition = field_struct_definition->get_latest_struct_definition();
						stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << latest_struct_definition.get_code_symbol_name();
					}
					else
					{
						std::string const& field_name = tag_field->get_name();
						console_write_line("Failed to export null tag struct definition for field '%s'", field_name.c_str());
					}

					if (write_tag)
					{
						stream << ", " << field_id_string;
					}

					stream << " },";
					if (field_struct_definition && field_struct_definition->is_legacy_struct())
					{
						stream << " // structure_version:" << field_struct_definition->get_structure_version();
					}
					stream << std::endl;
				}
				break;
				case blofeld::_field_api_interop:
				{
					stream << "\t\t{ ";
					stream << field_generic_type_name << ", ";
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
					}
					if (c_blamtoozle_tag_api_interop_definition* api_interop_definition = tag_field->get_api_interop_definition())
					{
						stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << api_interop_definition->get_code_symbol_name();
					}
					else
					{
						std::string const& field_name = tag_field->get_name();
						console_write_line("Failed to export null tag api interop definition for field '%s'", field_name.c_str());
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
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
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
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
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
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
					}
					if (c_blamtoozle_tag_resource_definition* resource_definition = tag_field->get_tag_resource_definition())
					{
						stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << resource_definition->get_code_symbol_name();
					}
					else
					{
						std::string const& field_name = tag_field->get_name();
						console_write_line("Failed to export null tag resource definition for field '%s'", field_name.c_str());
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
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
					}
					if (c_blamtoozle_tag_reference_definition* reference_definition = tag_field->get_tag_reference_definition())
					{
						stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << reference_definition->get_code_symbol_name();
					}
					else
					{
						std::string const& field_name = tag_field->get_name();
						console_write_line("Failed to export null tag reference definition for field '%s'", field_name.c_str());
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
					if (write_terminator)
					{
						if (terminator_extra_new_line)
						{
							stream << std::endl;
						}
						stream << "\t\t{ _field_terminator }" << std::endl;
					}
				}
				break;
				case blofeld::_field_char_enum:
				case blofeld::_field_short_enum:
				case blofeld::_field_long_enum:
				case blofeld::_field_long_flags:
				case blofeld::_field_word_flags:
				case blofeld::_field_byte_flags:
				{
					stream << "\t\t{ ";
					stream << field_generic_type_name << ", ";
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
					}

					if (c_blamtoozle_string_list_definition* string_list_definition = tag_field->get_string_list_definition())
					{
						stream << ", &blofeld::" << engine_namespace << "::" << platform_namespace << "::" << string_list_definition->get_code_symbol_name();
					}
					else
					{
						std::string const& field_name = tag_field->get_name();
						console_write_line("Failed to export null string list definition for field '%s'", field_name.c_str());
					}

					if (write_tag)
					{
						stream << ", " << field_id_string;
					}

					stream << " }," << std::endl;
				}
				break;
				default:
				{
					stream << "\t\t{ ";
					stream << field_generic_type_name << ", ";
					stream << "\"" << name.c_str() << "\"";
					if (write_description)
					{
						write_field_description(stream, description);
					}
					if (write_units)
					{
						write_field_units(stream, units);
					}
					if (write_limits)
					{
						write_field_limits(stream, limits);
					}
					if (write_old_name)
					{
						write_field_alt_names(stream, old_names);
					}
					if (write_flags)
					{
						write_tag_field_flags(stream, flags);
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
}

void c_blamtoozle_source_generator::write_field_description(std::stringstream& stream, std::string const& description)
{
	if (!description.empty()) stream << ", " << "\"" << description.c_str() << "\"";
	else stream << ", " << "nullptr";
}

void c_blamtoozle_source_generator::write_field_units(std::stringstream& stream, std::string const& units)
{
	if (!units.empty()) stream << ", " << "\"" << units.c_str() << "\"";
	else stream << ", " << "nullptr";
}

void c_blamtoozle_source_generator::write_field_limits(std::stringstream& stream, std::string const& limits)
{
	if (!limits.empty()) stream << ", " << "\"" << limits.c_str() << "\"";
	else stream << ", " << "nullptr";
}

void c_blamtoozle_source_generator::write_field_alt_names(std::stringstream& stream, std::vector<std::string> const& old_names)
{
	stream << ", MAKE_ALT_NAMES(";
	for (size_t old_name_index = 0; old_name_index < old_names.size(); old_name_index++)
	{
		std::string const& old_name = old_names[old_name_index];
		if (old_name_index > 0)
		{
			stream << ", ";
		}
		stream << "\"" << old_name.c_str() << "\"";
	}
	stream << ")";
}

void c_blamtoozle_source_generator::write_tag_field_flags(std::stringstream& stream, blofeld::f_tag_field_flags flags)
{
	uint32_t flags_written = 0;

	stream << ", ";

	if (flags.test(blofeld::_tag_field_flag_unknown0))
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_UNKNOWN0";
	}
	if (flags.test(blofeld::_tag_field_flag_read_only))
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_READ_ONLY";
	}
	if (flags.test(blofeld::_tag_field_flag_index))
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_INDEX";
	}
	if (flags.test(blofeld::_tag_field_flag_unknown3))
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_UNKNOWN3";
	}
	if (flags.test(blofeld::_tag_field_flag_unknown4))
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_UNKNOWN4";
	}
	if (flags.test(blofeld::_tag_field_flag_pointer))
	{
		if (flags_written++) stream << " | ";
		stream << "FIELD_FLAG_POINTER";
	}
	if (flags.is_clear())
	{
		stream << "FIELD_FLAG_NONE";
	}

	if (flags_written == 0 && !flags.is_clear())
	{
		console_write_line("Unknown field flag");
		throw BCS_E_FATAL;
	}
}

void c_blamtoozle_source_generator::coerce_definitions()
{
	std::set<c_blamtoozle_tag_group_definition*> _group_definitions;
	std::set<c_blamtoozle_tag_block_definition*> _block_definitions;
	std::set<c_blamtoozle_tag_reference_definition*> _tag_reference_definitions;
	std::set<c_blamtoozle_tag_array_definition*> _array_definitions;
	std::set<c_blamtoozle_tag_struct_definition*> _struct_definitions;
	std::set<c_blamtoozle_tag_data_definition*> _data_definitions;
	std::set<c_blamtoozle_string_list_definition*> _string_list_definitions;
	std::set<c_blamtoozle_tag_resource_definition*> _resource_definitions;
	std::set<c_blamtoozle_tag_api_interop_definition*> _api_interop_definitions;
	std::set<c_blamtoozle_tag_block_index_custom_search_definition*> _block_index_custom_search_definitions;

	c_blamtoozle_tag_struct_definition* x;
#define setup_sets(input, set) for (auto& definition : input) { set.insert(definition); }
#define setup_sets2(input, set) for (auto& definition : input) { set.insert(&definition->get_latest_struct_definition()); }
	setup_sets(tag_definition_manager.tag_group_definitions, _group_definitions);
	setup_sets2(tag_definition_manager.tag_struct_definitions, _struct_definitions);
	setup_sets(tag_definition_manager.tag_block_definitions, _block_definitions);
	setup_sets(tag_definition_manager.tag_reference_definitions, _tag_reference_definitions);
	setup_sets(tag_definition_manager.tag_array_definitions, _array_definitions);
	setup_sets(tag_definition_manager.tag_string_list_definitions, _string_list_definitions);
	setup_sets(tag_definition_manager.tag_resource_definitions, _resource_definitions);
	setup_sets(tag_definition_manager.tag_data_definitions, _data_definitions);
	setup_sets(tag_definition_manager.tag_api_interop_definitions, _api_interop_definitions);
	setup_sets(tag_definition_manager.tag_block_index_custom_search_definitions, _block_index_custom_search_definitions);
#undef setup_sets

	group_definitions.insert(group_definitions.begin(), _group_definitions.begin(), _group_definitions.end());
	block_definitions.insert(block_definitions.begin(), _block_definitions.begin(), _block_definitions.end());
	tag_reference_definitions.insert(tag_reference_definitions.begin(), _tag_reference_definitions.begin(), _tag_reference_definitions.end());
	array_definitions.insert(array_definitions.begin(), _array_definitions.begin(), _array_definitions.end());
	struct_definitions.insert(struct_definitions.begin(), _struct_definitions.begin(), _struct_definitions.end());
	data_definitions.insert(data_definitions.begin(), _data_definitions.begin(), _data_definitions.end());
	string_list_definitions.insert(string_list_definitions.begin(), _string_list_definitions.begin(), _string_list_definitions.end());
	resource_definitions.insert(resource_definitions.begin(), _resource_definitions.begin(), _resource_definitions.end());
	api_interop_definitions.insert(api_interop_definitions.begin(), _api_interop_definitions.begin(), _api_interop_definitions.end());
	block_index_custom_search_definitions.insert(block_index_custom_search_definitions.begin(), _block_index_custom_search_definitions.begin(), _block_index_custom_search_definitions.end());

	std::sort(group_definitions.begin(), group_definitions.end(), [](c_blamtoozle_tag_group_definition* a, c_blamtoozle_tag_group_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });
	std::sort(block_definitions.begin(), block_definitions.end(), [](c_blamtoozle_tag_block_definition* a, c_blamtoozle_tag_block_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });
	std::sort(tag_reference_definitions.begin(), tag_reference_definitions.end(), [](c_blamtoozle_tag_reference_definition* a, c_blamtoozle_tag_reference_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });
	std::sort(array_definitions.begin(), array_definitions.end(), [](c_blamtoozle_tag_array_definition* a, c_blamtoozle_tag_array_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });
	std::sort(struct_definitions.begin(), struct_definitions.end(), [](c_blamtoozle_tag_struct_definition* a, c_blamtoozle_tag_struct_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });
	std::sort(data_definitions.begin(), data_definitions.end(), [](c_blamtoozle_tag_data_definition* a, c_blamtoozle_tag_data_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });
	std::sort(string_list_definitions.begin(), string_list_definitions.end(), [](c_blamtoozle_string_list_definition* a, c_blamtoozle_string_list_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });
	std::sort(resource_definitions.begin(), resource_definitions.end(), [](c_blamtoozle_tag_resource_definition* a, c_blamtoozle_tag_resource_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });
	std::sort(api_interop_definitions.begin(), api_interop_definitions.end(), [](c_blamtoozle_tag_api_interop_definition* a, c_blamtoozle_tag_api_interop_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });
	std::sort(block_index_custom_search_definitions.begin(), block_index_custom_search_definitions.end(), [](c_blamtoozle_tag_block_index_custom_search_definition* a, c_blamtoozle_tag_block_index_custom_search_definition* b) { return strcmp(a->get_code_symbol_name(), b->get_code_symbol_name()) < 0; });

#define setup_helpers(set, helpers) for (auto& definition : set) { helpers.emplace_back(definition); }
	setup_helpers(_group_definitions, group_definitions_helpers);
	setup_helpers(_struct_definitions, struct_definitions_helpers);
	setup_helpers(_block_definitions, block_definitions_helpers);
	setup_helpers(_tag_reference_definitions, tag_reference_definitions_helpers);
	setup_helpers(_array_definitions, array_definitions_helpers);
	setup_helpers(_string_list_definitions, string_list_definitions_helpers);
	setup_helpers(_resource_definitions, resource_definitions_helpers);
	setup_helpers(_data_definitions, data_definitions_helpers);
	setup_helpers(_api_interop_definitions, api_interop_definitions_helpers);
	setup_helpers(_block_index_custom_search_definitions, block_index_custom_search_definitions_helpers);
#undef setup_helpers
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
