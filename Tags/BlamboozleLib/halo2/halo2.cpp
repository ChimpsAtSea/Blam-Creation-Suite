#include "blamboozlelib-private-pch.h"

const char* h2_va_to_pointer_with_external_string(const char* data, ptr32 address)
{
	if (address == 0) return nullptr;

	static std::string blamboozle_halo2_language = c_command_line::get_command_line_arg("-blamboozle-halo2-language");
	ASSERT(blamboozle_halo2_language.size() > 0);

	static HMODULE h2_language = LoadLibraryA(blamboozle_halo2_language.c_str());
	ASSERT(h2_language);

	static char string_buffer[5209][4096] = {};
	unsigned long string_index = address.value();
	if (string_index == 87)
	{
		return ""; // EMPTY STRING
	}
	else if (string_index < _countof(string_buffer))
	{
		int load_string_result = LoadStringA(h2_language, string_index, string_buffer[string_index], sizeof(string_buffer[string_index]));
		ASSERT(load_string_result >= 0);
		return string_buffer[string_index];
	}
	else
	{
		address = h2_va_to_rva(address); // convert from va to rva

		return h2_pa_to_pointer(data, address);
	}
}

const char* h2_va_to_pointer(const char* data, ptr32 address)
{
	if (address == 0) return nullptr;

	address = h2_va_to_rva(address); // convert from va to rva

	return h2_pa_to_pointer(data, address);
}

const char* h2_pa_to_pointer(const char* data, ptr32 address)
{
	if (address)
	{
		const void* result = dumpfile_to_pointer32(data, address);
		if (!result)
		{
			result = dumpfile_to_pointer64(data, address.value());
		}
		ASSERT(result != nullptr);
		return static_cast<const char*>(result);
	}
	return nullptr;
}

std::map<c_h2_tag_group_definition*, std::vector<c_h2_pseudo_struct_definition*>> struct_definitions;

void h2_sort_structures_struct(c_h2_tag_group_definition& group_definition, c_h2_pseudo_struct_definition& pseudo_struct_definition);

void h2_sort_structures_block(c_h2_tag_group_definition& group_definition, c_h2_tag_block_definition& block_definition)
{
	for (c_h2_pseudo_struct_definition* pseudo_struct_definition : block_definition.pseudo_struct_definitions)
	{
		h2_sort_structures_struct(group_definition, *pseudo_struct_definition);
	}
}

void h2_sort_structures_array(c_h2_tag_group_definition& group_definition, c_h2_pseudo_array_definition& pseudo_array_definition)
{
	h2_sort_structures_struct(group_definition, *pseudo_array_definition.array_pseudo_struct_definition);
}

void h2_sort_structures_struct(c_h2_tag_group_definition& group_definition, c_h2_pseudo_struct_definition& pseudo_struct_definition)
{
	for (auto& field : pseudo_struct_definition.pseudo_fields)
	{
		if (field->field_type == _h2_pseudo_field_type_struct)
		{
			h2_sort_structures_struct(group_definition, *field->struct_definition);
		}
		if (field->field_type == _h2_pseudo_field_type_array)
		{
			h2_sort_structures_array(group_definition, *field->pseudo_array_definition);
		}
		if (field->field_type == _h2_pseudo_field_type_block)
		{
			h2_sort_structures_block(group_definition, *field->block_definition);
		}
	}

	std::vector<c_h2_pseudo_struct_definition*>& pseudo_struct_definitions = struct_definitions[&group_definition];
	pseudo_struct_definitions.insert(pseudo_struct_definitions.begin(), &pseudo_struct_definition);
}

void h2_sort_structures(std::vector<c_h2_tag_group_definition*>& group_definitions)
{
	for (auto& group_definition : group_definitions)
	{
		h2_sort_structures_block(*group_definition, *group_definition->tag_block_definition);
	}
}

std::vector<c_h2_tag_group_definition*> exported_tag_group_definitions;
void h2_clear_exported_groups()
{
	exported_tag_group_definitions.clear();
}

bool is_group_exported(c_h2_tag_group_definition& tag_group_definition)
{
	for (c_h2_tag_group_definition* current_tag_group_definition : exported_tag_group_definitions)
	{
		if (current_tag_group_definition == &tag_group_definition)
		{
			return true;
		}
	}
	exported_tag_group_definitions.push_back(&tag_group_definition);
	return false;
}

std::vector<c_h2_tag_block_definition*> exported_tag_block_definitions;
void h2_clear_exported_blocks()
{
	exported_tag_block_definitions.clear();
}

bool is_block_exported(c_h2_tag_block_definition& tag_block_definition)
{
	for (c_h2_tag_block_definition* current_tag_block_definition : exported_tag_block_definitions)
	{
		if (current_tag_block_definition == &tag_block_definition)
		{
			return true;
		}
	}
	exported_tag_block_definitions.push_back(&tag_block_definition);
	return false;
}

std::vector<c_h2_pseudo_struct_definition*> exported_pseudo_struct_definitions;
void h2_clear_exported_structs()
{
	exported_pseudo_struct_definitions.clear();
}

bool is_struct_exported(c_h2_pseudo_struct_definition& pseudo_struct_definition)
{
	for (c_h2_pseudo_struct_definition* current_pseudo_struct_definition : exported_pseudo_struct_definitions)
	{
		if (current_pseudo_struct_definition == &pseudo_struct_definition)
		{
			return true;
		}
	}
	exported_pseudo_struct_definitions.push_back(&pseudo_struct_definition);
	return false;
}

std::vector<c_h2_tag_reference_definition*> exported_tag_reference_definitions;
void h2_clear_exported_tag_references()
{
	exported_tag_reference_definitions.clear();
}

bool is_tag_reference_exported(c_h2_tag_reference_definition& tag_reference_definition)
{
	for (c_h2_tag_reference_definition* current_tag_reference_definition : exported_tag_reference_definitions)
	{
		if (current_tag_reference_definition == &tag_reference_definition)
		{
			return true;
		}
	}
	exported_tag_reference_definitions.push_back(&tag_reference_definition);
	return false;
}

std::vector<c_h2_string_list_definition*> exported_string_list_definitions;
void h2_clear_exported_string_lists()
{
	exported_string_list_definitions.clear();
}

bool is_string_list_exported(c_h2_string_list_definition& string_list_definition)
{
	for (c_h2_string_list_definition* current_string_list_definition : exported_string_list_definitions)
	{
		if (current_string_list_definition == &string_list_definition)
		{
			return true;
		}
	}
	exported_string_list_definitions.push_back(&string_list_definition);
	return false;
}

std::vector<c_h2_tag_group_definition*> sorted_group_definitions;
c_h2_tag_group_definition* get_sorted_group_definition_by_group_tag(tag group_tag)
{
	for (c_h2_tag_group_definition* current_group_definition : sorted_group_definitions)
	{
		if (current_group_definition->tag_group_definition->group_tag.value == group_tag)
		{
			return current_group_definition;
		}
	}
	return nullptr;
}

bool h2_sort_group_definition(c_h2_tag_group_definition& group_definition)
{
	if (!get_sorted_group_definition_by_group_tag(group_definition.tag_group_definition->group_tag.value))
	{
		bool include = false;
		include |= group_definition.tag_group_definition->parent_group_tag.value == 0xFFFFFFFFu;
		include |= get_sorted_group_definition_by_group_tag(group_definition.tag_group_definition->parent_group_tag.value) != nullptr;
		if (include)
		{
			sorted_group_definitions.push_back(&group_definition);
			return true;
		}
	}
	return false;
}

void h2_sort_group_definitions(std::vector<c_h2_tag_group_definition*>& group_definitions)
{
	bool added_structure = false;
	do
	{
		added_structure = false;
		for (c_h2_tag_group_definition* group_definition : group_definitions)
		{
			added_structure |= h2_sort_group_definition(*group_definition);
		}
	} while (added_structure);
}

void h2_generate_tag_field_flags(std::stringstream& s, c_blamlib_string_parser_v2& string_parser)
{
	unsigned long flags_written = 0;

	if (string_parser.flag_unknown0)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_UNKNOWN0";
	}
	if (string_parser.flag_read_only)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_READ_ONLY";
	}
	if (string_parser.flag_index)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_INDEX";
	}
	if (string_parser.flag_unknown3)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_UNKNOWN3";
	}
	if (string_parser.flag_pointer)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_POINTER";
	}

	if (flags_written == 0)
	{
		s << "FIELD_FLAG_NONE";
	}
}

extern void escape_string(
	const char* source,
	char* destination,
	bool remove_return,
	bool unescaped_comma);

extern std::string escape_string(std::string str);

void h2_write_fields(std::stringstream& s, std::vector<c_h2_pseudo_field_definition*>& pseudo_fields)
{
	for (auto& tag_field : pseudo_fields)
	{
		const char* field_generic_type_name = h2_pseudo_field_type_to_generic_field_type(tag_field->field_type);

		c_blamlib_string_parser_v2 string_parser = c_blamlib_string_parser_v2(tag_field->name);

		c_fixed_string_4096 name;
		c_fixed_string_4096 description;
		c_fixed_string_4096 units;
		c_fixed_string_4096 limits;
		c_fixed_string_4096 limits_legacy;
		c_fixed_string_4096 old_name;

		if (tag_field->name)
		{
			escape_string(string_parser.name, name, true, true);
			escape_string(string_parser.description, description, true, true);
			escape_string(string_parser.units, units, true, true);
			escape_string(string_parser.limits, limits, true, true);
			escape_string(string_parser.limits_legacy, limits_legacy, true, true);
			escape_string(string_parser.old_name, old_name, true, true);
		}
		if (name.empty())
		{
			name = "value";
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

		switch (tag_field->field_type)
		{
		case _h2_pseudo_field_type_pad:
		{
			ASSERT(!write_limits);
			ASSERT(!write_units);

			s << "\t\tFIELD_PAD(";
			if (!name.empty()) s << "\"" << name.c_str() << "\"";
			else s << "nullptr";
			if (!description.empty()) s << ", \"" << description.c_str() << "\"";
			else s << ", nullptr";
			s << ", "; h2_generate_tag_field_flags(s, string_parser);
			s << ", " << tag_field->padding;
			s << ")," << std::endl;
		}
		break;
		case _h2_pseudo_field_type_skip:
		{
			ASSERT(!write_limits);
			ASSERT(!write_units);

			s << "\t\tFIELD_SKIP(";
			if (!name.empty()) s << "\"" << name.c_str() << "\"";
			else s << "nullptr";
			if (!description.empty()) s << ", \"" << description.c_str() << "\"";
			else s << ", nullptr";
			s << ", "; h2_generate_tag_field_flags(s, string_parser);
			s << ", " << tag_field->skip_length;
			s << ")," << std::endl;
		}
		break;
		case _h2_pseudo_field_type_explanation:
		{
			s << "\t\tFIELD_EXPLANATION(";
			if (write_units) s << "\"" << tag_field->name << "\"";
			else if (!name.empty()) s << "\"" << name.c_str() << "\"";
			else s << "nullptr";
			if (!description.empty()) s << ", \"" << description.c_str() << "\"";
			else s << ", nullptr";
			s << ", "; h2_generate_tag_field_flags(s, string_parser);
			if (tag_field->explanation != nullptr && *tag_field->explanation)
			{
				std::string explanation = escape_string(tag_field->explanation);
				s << ", \"" << explanation << "\"";
			}
			else s << ", nullptr";
			s << ")," << std::endl;
		}
		break;
		case _h2_pseudo_field_type_array:
		{
			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				h2_generate_tag_field_flags(s, string_parser);
			}

			s << ", &blofeld::halo2::" << tag_field->pseudo_array_definition->code_name;

			s << " }," << std::endl;
		}
		break;
		case _h2_pseudo_field_type_char_block_index:
		case _h2_pseudo_field_type_short_block_index:
		case _h2_pseudo_field_type_long_block_index:
			break;
		case _h2_pseudo_field_type_block:
		{
			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				h2_generate_tag_field_flags(s, string_parser);
			}

			ASSERT(tag_field->block_definition);
			if (tag_field->block_definition)
			{
				s << ", &blofeld::halo2::" << tag_field->block_definition->code_name;
			}

			s << " }," << std::endl;
		}
		break;
		case _h2_pseudo_field_type_struct:
		{
			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				h2_generate_tag_field_flags(s, string_parser);
			}

			ASSERT(tag_field->struct_definition);
			if (tag_field->struct_definition)
			{
				s << ", &blofeld::halo2::" << tag_field->struct_definition->code_name;
			}

			s << " }," << std::endl;
		}
		break;
		case _h2_pseudo_field_type_tag_reference:
		{
			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				h2_generate_tag_field_flags(s, string_parser);
			}

			ASSERT(tag_field->tag_reference_definition);
			if (tag_field->tag_reference_definition)
			{
				s << ", &blofeld::halo2::" << tag_field->tag_reference_definition->code_name;
			}

			s << " }," << std::endl;
		}
		break;
		case _h2_pseudo_field_type_terminator:
		{
			s << "\t\t{ _field_terminator }" << std::endl;
		}
		break;
		case _h2_pseudo_field_type_char_enum:
		case _h2_pseudo_field_type_enum:
		case _h2_pseudo_field_type_long_enum:
		case _h2_pseudo_field_type_long_flags:
		case _h2_pseudo_field_type_word_flags:
		case _h2_pseudo_field_type_byte_flags:
			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				h2_generate_tag_field_flags(s, string_parser);
			}

			ASSERT(tag_field->string_list_definition);
			if (tag_field->string_list_definition)
			{
				s << ", &blofeld::halo2::" << tag_field->string_list_definition->code_name;
			}

			s << " }," << std::endl;
			break;
		default:
		{
			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				h2_generate_tag_field_flags(s, string_parser);
			}
			if (write_pointer) s << ", " << "nullptr";
			s << " }," << std::endl;
		}
		break;
		}
	}
}

void h2_write_tag_reference_flags(std::stringstream& s, c_h2_tag_reference_definition& tag_reference_definition)
{
	std::stringstream flags_stream;
	if (tag_reference_definition.tag_reference_definition.flags.test(_h4_tag_reference_flag_not_a_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_not_a_dependency";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_h4_tag_reference_flag_dont_resolve_in_editor))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_dont_resolve_in_editor";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_h4_tag_reference_flag_resolved_manually))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_resolved_manually";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_h4_tag_reference_flag_resolved_by_game))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_resolved_by_game";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_h4_tag_reference_flag_not_a_resource_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_not_a_resource_dependency";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_h4_tag_reference_flag_dependency_for_cache_file_sharing))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_dependency_for_cache_file_sharing";
	}
	if (tag_reference_definition.tag_reference_definition.flags.test(_h4_tag_reference_flag_reference_ignored_by_bundle_builder))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_reference_ignored_by_bundle_builder";
	}
	std::string flags_string = flags_stream.str();
	if (!flags_string.empty())
	{
		s << ", " << flags_string;
	}
}

void h2_write_tag_types_header(std::stringstream& s, std::vector<c_h2_pseudo_field_definition*>& pseudo_fields)
{
	for (auto& tag_field : pseudo_fields)
	{
		switch (tag_field->field_type)
		{
		case _h2_pseudo_field_type_char_enum:
		case _h2_pseudo_field_type_enum:
		case _h2_pseudo_field_type_long_enum:
		case _h2_pseudo_field_type_long_flags:
		case _h2_pseudo_field_type_word_flags:
		case _h2_pseudo_field_type_byte_flags:
		{
			ASSERT(tag_field->string_list_definition != nullptr);
			c_h2_string_list_definition& string_list_definition = *tag_field->string_list_definition;
			if (!is_string_list_exported(string_list_definition))
			{
				s << "\textern c_versioned_string_list " << string_list_definition.code_name << "_strings;" << std::endl;
				s << "\textern s_string_list_definition " << string_list_definition.code_name << ";" << std::endl;
			}
		}
		break;
		case _h2_pseudo_field_type_tag_reference:
		{
			ASSERT(tag_field->tag_reference_definition != nullptr);
			c_h2_tag_reference_definition& tag_reference_definition = *tag_field->tag_reference_definition;
			if (!is_tag_reference_exported(tag_reference_definition))
			{
				s << "\textern s_tag_reference_definition " << tag_reference_definition.code_name << ";";

				s << std::endl;
			}
		}
		break;
		}
	}
}

void h2_write_tag_types_source(std::stringstream& s, std::vector<c_h2_pseudo_field_definition*>& pseudo_fields)
{
	for (auto& tag_field : pseudo_fields)
	{
		switch (tag_field->field_type)
		{
		case _h2_pseudo_field_type_char_enum:
		case _h2_pseudo_field_type_enum:
		case _h2_pseudo_field_type_long_enum:
		case _h2_pseudo_field_type_long_flags:
		case _h2_pseudo_field_type_word_flags:
		case _h2_pseudo_field_type_byte_flags:
		{
			ASSERT(tag_field->string_list_definition != nullptr);
			c_h2_string_list_definition& string_list_definition = *tag_field->string_list_definition;
			if (!is_string_list_exported(string_list_definition))
			{
				if (string_list_definition.options.size() > 0)
				{
					s << "\tSTRINGS(" << string_list_definition.code_name << ")" << std::endl;
					s << "\t{" << std::endl;
					for (unsigned long i = 0; i < string_list_definition.options.size(); i++)
					{
						const char* option = string_list_definition.options[i];
						std::string escaped_option = escape_string(option);
						if (escaped_option.empty()) escaped_option = "unused";
						if (i != string_list_definition.options.size() - 1)
						{
							s << "\t\t\"" << escaped_option << "\"," << std::endl;
						}
						else
						{
							s << "\t\t\"" << escaped_option << "\"" << std::endl;
						}
					}
					s << "\t};" << std::endl;

					s << "\tSTRING_LIST(" << string_list_definition.code_name << ", " << string_list_definition.code_name << "_strings, _countof(" << string_list_definition.code_name << "_strings));" << std::endl;
				}
				else
				{
					s << "\tSTRING_LIST(" << string_list_definition.code_name << ", empty_string_list, 0);" << std::endl;
				}

				s << std::endl;
			}
		}
		break;
		case _h2_pseudo_field_type_tag_reference:
		{
			ASSERT(tag_field->tag_reference_definition != nullptr);
			c_h2_tag_reference_definition& tag_reference_definition = *tag_field->tag_reference_definition;
			if (!is_tag_reference_exported(tag_reference_definition))
			{
				if (tag_reference_definition.group_tags.size() > 1)
				{
					s << "\tTAG_REFERENCE_GROUP(" << tag_reference_definition.code_name;
					h2_write_tag_reference_flags(s, tag_reference_definition);
					s << ")" << std::endl;
					s << "\t{" << std::endl;
					bool first = true;
					for (c_h2_tag_group_definition* group_definition : tag_reference_definition.group_tags2)
					{
						s << "\t\t" << group_definition->tag_symbol_name << "," << std::endl;
						first = false;
					}
					s << "\t\tINVALID_TAG" << std::endl;

					s << "\t};" << std::endl;
				}
				else if (tag_reference_definition.group_tags.size() == 1)
				{
					s << "\tTAG_REFERENCE(" << tag_reference_definition.code_name << ", " << tag_reference_definition.group_tags2[0]->tag_symbol_name;
					h2_write_tag_reference_flags(s, tag_reference_definition);
					s << ");" << std::endl;
				}
				else
				{
					s << "\tTAG_REFERENCE(" << tag_reference_definition.code_name;
					h2_write_tag_reference_flags(s, tag_reference_definition);
					s << ");" << std::endl;
				}

				s << std::endl;
			}
		}
		break;
		}
	}
}

void h2_export_header(
	std::stringstream& s,
	std::vector<c_h2_tag_group_definition*>& group_definitions,
	std::vector<c_h2_tag_block_definition*>& block_definitions,
	std::vector<c_h2_pseudo_struct_definition*>& _struct_definitions)
{
	h2_clear_exported_blocks();
	h2_clear_exported_groups();
	h2_clear_exported_structs();
	h2_clear_exported_tag_references();
	h2_clear_exported_string_lists();

	s << "#pragma once" << std::endl;
	s << std::endl;
	s << "namespace blofeld" << std::endl;
	s << "{" << std::endl;
	s << "namespace halo2 {" << std::endl;
	s << std::endl;

	for (auto& group_definition : group_definitions)
	{
		size_t start_length = s.str().size();
		if (!is_group_exported(*group_definition))
		{
			ASSERT(!is_block_exported(*group_definition->tag_block_definition));
			c_h2_pseudo_struct_definition* pseudo_struct_definition = group_definition->tag_block_definition->latest_pseudo_struct_definition;
			ASSERT(!is_struct_exported(*pseudo_struct_definition));
			c_h2_tag_block_definition& block_definition = *group_definition->tag_block_definition;

			char group_tag_buffer[5] = {};
			unsigned long group_tag_swapped = _byteswap_ulong(group_definition->tag_group_definition->group_tag.value);
			sprintf(group_tag_buffer, "%.4s", reinterpret_cast<const char*>(&group_tag_swapped));
			char* group_tag_string = *group_tag_buffer ? group_tag_buffer : (group_tag_buffer + 1);

			s << "\tstatic constexpr unsigned long " << group_definition->tag_symbol_name << " = '" << group_tag_string << "';" << std::endl;
			s << "\textern s_tag_group " << group_definition->name << "_group;" << std::endl;

			s << "\textern s_tag_block_definition " << block_definition.code_name << ";" << std::endl;
			s << "\textern s_tag_struct_definition " << block_definition.code_name << "_struct_definition;" << std::endl;

			// #HACK #TODO: Move this
			pseudo_struct_definition->code_name = block_definition.code_name + "_struct_definition";

			h2_write_tag_types_header(s, pseudo_struct_definition->pseudo_fields);
		}
		if (start_length != s.str().size()) s << std::endl;
	}

	for (auto& block_definition : block_definitions)
	{
		size_t start_length = s.str().size();
		if (!is_block_exported(*block_definition))
		{
			c_h2_pseudo_struct_definition* pseudo_struct_definition = block_definition->latest_pseudo_struct_definition;

			s << "\textern s_tag_block_definition " << block_definition->code_name << ";" << std::endl;
			if (pseudo_struct_definition->block_definitions.size() == 1)
			{
				ASSERT(!is_struct_exported(*pseudo_struct_definition));

				// #HACK #TODO: Move this
				pseudo_struct_definition->code_name = block_definition->code_name + "_struct_definition";

				s << "\textern s_tag_struct_definition " << pseudo_struct_definition->code_name << ";" << std::endl;

				h2_write_tag_types_header(s, pseudo_struct_definition->pseudo_fields);
			}
		}
		if (start_length != s.str().size()) s << std::endl;
	}

	for (auto& pseudo_struct_definition : _struct_definitions)
	{
		if (pseudo_struct_definition->code_name == "collision_bsp_struct_definition")
		{
			debug_point;
		}
		size_t start_length = s.str().size();
		if (!is_struct_exported(*pseudo_struct_definition))
		{
			if (pseudo_struct_definition->pseudo_array_definition)
			{
				c_h2_pseudo_array_definition& pseudo_array_definition = *pseudo_struct_definition->pseudo_array_definition;

				s << "\textern s_tag_array_definition " << pseudo_array_definition.code_name << ";" << std::endl;
				s << "\textern s_tag_struct_definition " << pseudo_struct_definition->code_name << ";" << std::endl;

				h2_write_tag_types_header(s, pseudo_array_definition.array_pseudo_struct_definition->pseudo_fields);
			}
			else
			{
				s << "\textern s_tag_struct_definition " << pseudo_struct_definition->code_name << "; " << std::endl;

				h2_write_tag_types_header(s, pseudo_struct_definition->pseudo_fields);
			}
		}
		if (start_length != s.str().size()) s << std::endl;

		debug_point;
	}

	s << std::endl;
	s << "} // namespace blofeld" << std::endl;
	s << std::endl;
	s << "} // namespace halo2" << std::endl;
	s << std::endl;
}

void h2_export_source(
	std::stringstream& s,
	std::vector<c_h2_tag_group_definition*>& group_definitions,
	std::vector<c_h2_tag_block_definition*>& block_definitions,
	std::vector<c_h2_pseudo_struct_definition*>& _struct_definitions)
{
	h2_clear_exported_blocks();
	h2_clear_exported_groups();
	h2_clear_exported_structs();
	h2_clear_exported_tag_references();
	h2_clear_exported_string_lists();

	s << "#include <tagdefinitions-private-pch.h>" << std::endl;
	s << "#include <macaque_field_type_override.h>" << std::endl;
	s << std::endl;
	s << "namespace blofeld" << std::endl;
	s << "{" << std::endl;
	s << "namespace halo2 {" << std::endl;
	s << std::endl;

	for (auto& group_definition : group_definitions)
	{
		if (!is_group_exported(*group_definition))
		{
			ASSERT(!is_block_exported(*group_definition->tag_block_definition));
			c_h2_pseudo_struct_definition* pseudo_struct_definition = group_definition->tag_block_definition->latest_pseudo_struct_definition;
			ASSERT(!is_struct_exported(*pseudo_struct_definition));
			c_h2_tag_block_definition& block_definition = *group_definition->tag_block_definition;

			s << "\tTAG_GROUP(" << std::endl;
			s << "\t\t" << group_definition->name << "_group," << std::endl;
			s << "\t\t" << group_definition->tag_symbol_name.c_str() << "," << std::endl;
			if (c_h2_tag_group_definition* parent_group_definition = get_sorted_group_definition_by_group_tag(group_definition->tag_group_definition->parent_group_tag.value))
			{
				s << "\t\t&" << parent_group_definition->code_name << "_group," << std::endl;
				s << "\t\t" << parent_group_definition->tag_symbol_name.c_str() << "," << std::endl;
			}
			else
			{
				s << "\t\t" << "nullptr," << std::endl;
				s << "\t\t" << "INVALID_TAG," << std::endl;
			}
			s << "\t\t" << block_definition.code_name << ");" << std::endl;
			s << std::endl;

			s << "\tTAG_BLOCK(" << std::endl;
			s << "\t\t" << block_definition.code_name << "," << std::endl;
			s << "\t\t" << "\"" << block_definition.display_name << "\"," << std::endl;
			s << "\t\t" << block_definition.maximum_element_count << "," << std::endl;
			s << "\t\t" << "\"" << pseudo_struct_definition->struct_name << "\"," << std::endl;
			s << "\t\t" << "SET_DEFAULT," << std::endl;
			s << "\t\t" << "TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY)," << std::endl;
			s << "\t\t" << "PERSISTENT_ID_UNKNOWN)" << std::endl;
			s << "\t" << "{" << std::endl;
			h2_write_fields(s, pseudo_struct_definition->pseudo_fields);
			s << "\t" << "};" << std::endl;
			s << std::endl;

			h2_write_tag_types_source(s, pseudo_struct_definition->pseudo_fields);
		}
	}

	for (auto& block_definition : block_definitions)
	{
		if (!is_block_exported(*block_definition))
		{
			c_h2_pseudo_struct_definition* pseudo_struct_definition = block_definition->latest_pseudo_struct_definition;
			if (pseudo_struct_definition->block_definitions.size() == 1)
			{
				ASSERT(!is_struct_exported(*pseudo_struct_definition));

				s << "\tTAG_BLOCK(" << std::endl;
				s << "\t\t" << block_definition->code_name << "," << std::endl;
				s << "\t\t" << "\"" << block_definition->display_name << "\"," << std::endl;
				s << "\t\t" << block_definition->maximum_element_count << "," << std::endl;
				s << "\t\t" << "\"" << pseudo_struct_definition->struct_name << "\"," << std::endl;
				s << "\t\t" << "SET_DEFAULT," << std::endl;
				s << "\t\t" << "TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY)," << std::endl;
				s << "\t\t" << "PERSISTENT_ID_UNKNOWN)" << std::endl;
				s << "\t" << "{" << std::endl;
				h2_write_fields(s, pseudo_struct_definition->pseudo_fields);
				s << "\t" << "};" << std::endl;
				s << std::endl;

				h2_write_tag_types_source(s, pseudo_struct_definition->pseudo_fields);
			}
			else
			{
				s << "\tTAG_BLOCK_FROM_STRUCT(" << std::endl;
				s << "\t\t" << block_definition->code_name << "," << std::endl;
				s << "\t\t" << "\"" << block_definition->display_name << "\"," << std::endl;
				s << "\t\t" << block_definition->maximum_element_count << "," << std::endl;
				s << "\t\t" << pseudo_struct_definition->code_name << "); " << std::endl;
			}

			s << std::endl;
		}
	}

	for (auto& pseudo_struct_definition : _struct_definitions)
	{
		if (!is_struct_exported(*pseudo_struct_definition))
		{
			if (pseudo_struct_definition->pseudo_array_definition)
			{
				c_h2_pseudo_array_definition& pseudo_array_definition = *pseudo_struct_definition->pseudo_array_definition;

				s << "\tTAG_ARRAY(" << std::endl;
				s << "\t\t" << pseudo_array_definition.code_name << "," << std::endl;
				s << "\t\t" << "\"" << pseudo_array_definition.name << "\"," << std::endl;
				s << "\t\t" << pseudo_array_definition.count << "," << std::endl;
				s << "\t\t" << "\"" << pseudo_struct_definition->struct_name << "\"," << std::endl;
				s << "\t\t" << "SET_DEFAULT," << std::endl;
				s << "\t\t" << "TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY)," << std::endl;
				s << "\t\t" << "PERSISTENT_ID_UNKNOWN)" << std::endl;
				s << "\t" << "{" << std::endl;
				h2_write_fields(s, pseudo_struct_definition->pseudo_fields);
				s << "\t" << "};" << std::endl;
				s << std::endl;

				h2_write_tag_types_source(s, pseudo_struct_definition->pseudo_fields);
			}
			else
			{
				s << "\tTAG_STRUCT(" << std::endl;
				s << "\t\t" << pseudo_struct_definition->code_name << "," << std::endl;
				s << "\t\t" << "\"" << pseudo_struct_definition->name << "\"," << std::endl;
				s << "\t\t" << "\"" << pseudo_struct_definition->struct_name << "\"," << std::endl;
				s << "\t\t" << "SET_DEFAULT," << std::endl;
				s << "\t\t" << "TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY)," << std::endl;
				s << "\t\t" << "PERSISTENT_ID_UNKNOWN)" << std::endl;
				s << "\t" << "{" << std::endl;
				h2_write_fields(s, pseudo_struct_definition->pseudo_fields);
				s << "\t" << "};" << std::endl;
				s << std::endl;

				h2_write_tag_types_source(s, pseudo_struct_definition->pseudo_fields);
			}

			s << std::endl;
		}

		debug_point;
	}

	s << std::endl;
	s << "} // namespace blofeld" << std::endl;
	s << std::endl;
	s << "} // namespace halo2" << std::endl;
	s << std::endl;
}

void h2_export_code(
	std::vector<c_h2_tag_group_definition*>& group_definitions,
	std::vector<c_h2_tag_block_definition*>& block_definitions,
	std::vector<c_h2_pseudo_struct_definition*>& struct_definitions)
{
	std::stringstream header_stream;
	std::stringstream source_stream;

	h2_sort_group_definitions(group_definitions);
	h2_sort_structures(sorted_group_definitions);

	h2_export_header(header_stream, sorted_group_definitions, block_definitions, struct_definitions);
	h2_export_source(source_stream, sorted_group_definitions, block_definitions, struct_definitions);

	std::string header_string = header_stream.str();
	std::string source_string = source_stream.str();


	std::string output_directory = c_command_line::get_command_line_arg("-blamboozle-output");
	ASSERT(!output_directory.empty());
	std::string source_output_filepath = output_directory + "\\halo2.cpp";
	std::string header_output_filepath = output_directory + "\\halo2.h";

	bool macaque_header_write_file_result = filesystem_write_file_from_memory(header_output_filepath.c_str(), header_string.c_str(), header_string.size());
	ASSERT(macaque_header_write_file_result);

	bool macaque_header_write_file_result2 = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_string.c_str(), source_string.size());
	ASSERT(macaque_header_write_file_result2);
}


std::string h2_convert_to_code_name(std::string name)
{
	c_fixed_string_1024 str = name.c_str();
	str.lowercase();
	str.replace(' ', '_');
	str.replace('/', '_');
	str.replace('\\', '_');
	str.replace('-', '_');
	str.replace('+', '_');
	str.replace('&', '_');
	str.replace('|', '_');
	str.replace('>', '_');
	str.replace('<', '_');
	str.replace('=', '_');
	str.remove('*');
	str.remove('{');
	str.remove('}');
	str.remove('@');
	str.remove('(');
	str.remove(')');
	str.remove('.');
	str.remove(',');
	str.remove('\'');
	str.remove(':');
	str.remove(';');
	str.remove('\"');

	return str.c_str();
}