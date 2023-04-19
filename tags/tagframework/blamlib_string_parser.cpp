#include "tagframework-private-pch.h"

c_blamlib_string_parser_v2::c_blamlib_string_parser_v2(const char* string, bool is_block, t_string_list_value_unique_counter* string_list_value_unique_counter) :
	pretty_name(),
	tag_file_name(),
	old_name(),
	old_name2(),
	flags(),
	units(),
	limits(),
	limits_legacy(),
	meta(),
	description(),
	code_name(),
	flag_unknown0(false),
	flag_read_only(false),
	flag_index(false),
	flag_unknown3(false),
	flag_unknown4(false),
	flag_pointer(false),
	is_block(is_block),
	code_index(0),
	string_list_value_unique_counter(string_list_value_unique_counter)
{
	if (string == nullptr)
	{
		return;
	}

	const char* read_position = string;

	c_fixed_string_2048 temp_buffer;
	{
		//#define NAME_SEARCH_PATTERN "%[^][:|#{]"
#define NAME_SEARCH_PATTERN "%[^:|#{] "
#define OLD_NAME_SEARCH_PATTERN " {%[^}]} "
#define FLAGS_SEARCH_PATTERN " %[^][:|#] "

		// read name, alt names, and flags
		int search_for_name_and_alt_name_try1 = sscanf_s(
			read_position,
			NAME_SEARCH_PATTERN OLD_NAME_SEARCH_PATTERN FLAGS_SEARCH_PATTERN,
			temp_buffer.data, sizeof(temp_buffer.data),
			old_name.data, sizeof(old_name.data),
			flags.data, sizeof(flags.data));

		// read name, alt names, and flags
		int search_for_name_and_alt_name_try2 = sscanf_s(
			read_position,
			NAME_SEARCH_PATTERN OLD_NAME_SEARCH_PATTERN OLD_NAME_SEARCH_PATTERN FLAGS_SEARCH_PATTERN,
			temp_buffer.data, sizeof(temp_buffer.data),
			old_name.data, sizeof(old_name.data),
			old_name2.data, sizeof(old_name2.data),
			flags.data, sizeof(flags.data));

		int found_elements = __min(search_for_name_and_alt_name_try1, search_for_name_and_alt_name_try2);
		bool has_second_old_name = search_for_name_and_alt_name_try2 >= search_for_name_and_alt_name_try1;

		if (found_elements >= 1) // found name
		{
			read_position = strstr(read_position, temp_buffer) + strlen(temp_buffer);

			// name flags cleanup
			fixup_flags(temp_buffer);
		}
		else *temp_buffer = 0;
		if (found_elements >= 2) // found old_name
		{
			read_position = strstr(read_position, old_name) + strlen(old_name);
			read_position += 1; // ]
		}
		else *old_name = 0;
		if (has_second_old_name && search_for_name_and_alt_name_try2 >= 3) // found old_name
		{
			read_position = strstr(read_position, old_name2) + strlen(old_name2);
			read_position += 1; // ]
		}
		else *old_name2 = 0;
		if ((has_second_old_name && search_for_name_and_alt_name_try2 >= 4) || (!has_second_old_name && search_for_name_and_alt_name_try1 >= 3)) // found flags
		{
			read_position = strstr(read_position, flags) + strlen(flags);
		}
		else *flags = 0;

#undef NAME_SEARCH_PATTERN
#undef OLD_NAME_SEARCH_PATTERN
#undef FLAGS_SEARCH_PATTERN

		{
			// scan for & in tag file name
			tag_file_name = temp_buffer;

			if (tag_file_name == "category dependencies&shared PS category dependencies")
			{
				debug_point;
			}

			//#define NAME_SEARCH_PATTERN "%[^][:|#{]"
#define NAME_SEARCH_PATTERN "%[^&] "
#define OLD_NAME_SEARCH_PATTERN " &%[^|#] "

			// read name, old name 3
			int search_for_name_and_old_name3 = sscanf_s(
				temp_buffer,
				NAME_SEARCH_PATTERN OLD_NAME_SEARCH_PATTERN,
				tag_file_name.data, sizeof(tag_file_name.data),
				old_name3.data, sizeof(old_name3.data));

			if (search_for_name_and_old_name3 > 1)
			{
				temp_buffer = tag_file_name;
				debug_point;
			}
		}

		debug_point;

#undef NAME_SEARCH_PATTERN
#undef OLD_NAME_SEARCH_PATTERN

#define NAME_IGNORE_SEARCH_PATTERN " %*[^[] "
#define LIMITS_LEGACY_SEARCH_PATTERN " [%[^]]] "

		// #NOTE: Tag include this junk inside of them.
		{
			// limits_legacy
			int search_for_limits_legacy = sscanf_s(
				temp_buffer,
				NAME_IGNORE_SEARCH_PATTERN LIMITS_LEGACY_SEARCH_PATTERN,
				limits_legacy.data, sizeof(limits_legacy.data));

			// only try to fixup specific formats
			// otherwise some fields with array names will break eg. 'havok w m_pad256[1]*~!!'
			if (strstr(limits_legacy, ",") != nullptr || strstr(limits_legacy, " to ") != nullptr)
			{
				if (search_for_limits_legacy >= 1)
				{
					char* pretty_name_end = strstr(temp_buffer, limits_legacy) - 1;
					while (pretty_name_end > temp_buffer && isspace(pretty_name_end[-1])) pretty_name_end--; // remove any whitespace from name
					*pretty_name_end = 0; // terminator
					debug_point;
				}
			}

			debug_point;
		}

#undef NAME_IGNORE_SEARCH_PATTERN
#undef LIMITS_LEGACY_SEARCH_PATTERN
	}

	while (isspace(*read_position)) read_position++;

	if (*read_position == ':') // has description
	{
#define UNIT_SEARCH_PATTERN " %[^][|#] "
#define LIMITS_SEARCH_PATTERN " %[^|#] "
		int search_for_description_and_units = sscanf_s(
			read_position,
			":" UNIT_SEARCH_PATTERN LIMITS_SEARCH_PATTERN,
			units.data, sizeof(units.data),
			limits.data, sizeof(limits.data));

		read_position += 1; // colon
		if (search_for_description_and_units == 0) // couldn't find units, check for limits
		{
			int search_for_limits = sscanf_s(
				read_position,
				LIMITS_SEARCH_PATTERN,
				limits.data, sizeof(limits.data));
			if (search_for_limits >= 1) // found limits
			{
				read_position = strstr(read_position, limits) + strlen(limits);

				// limits flags cleanup
				fixup_flags(limits);
			}
		}
		if (search_for_description_and_units >= 1) // found units
		{
			read_position = strstr(read_position, units) + strlen(units);

			// units flags cleanup
			fixup_flags(units);
		}
		if (search_for_description_and_units >= 2) // found limits
		{
			read_position = strstr(read_position, limits) + strlen(limits);

			// limits flags cleanup
			fixup_flags(limits);
		}

		debug_point;

#undef UNIT_SEARCH_PATTERN
#undef LIMITS_SEARCH_PATTERN
	}

	while (isspace(*read_position)) read_position++;

	if (*read_position == '|') // has meta
	{
#define META_SEARCH_PATTERN "%[^][#]"
		int search_for_meta = sscanf_s(
			read_position,
			"|" META_SEARCH_PATTERN,
			meta.data, sizeof(meta.data));

		read_position += 1; // vertical bar
		if (search_for_meta >= 1) // found meta
		{
			read_position += strlen(meta);
		}

		debug_point;

#undef META_SEARCH_PATTERN
	}

	while (isspace(*read_position)) read_position++;

	if (*read_position == '#') // has description
	{
#define DESCRIPTION_SEARCH_PATTERN " %[^\xFF] "
		int search_for_description = sscanf_s(
			read_position,
			"#" DESCRIPTION_SEARCH_PATTERN,
			description.data, sizeof(description.data));

		read_position += 1; // hash
		if (search_for_description >= 1) // found description
		{
			read_position = strstr(read_position, description) + strlen(description);

			// description flags cleanup
			fixup_flags(description);
		}

		debug_point;

#undef DESCRIPTION_SEARCH_PATTERN
	}

	while (isspace(*read_position)) read_position++;

	ASSERT(read_position == string + strlen(string));



	for (const char* flag = flags; *flag; flag++)
	{
		switch (*flag)
		{
		case field_flag_id_unknown0:
			flag_unknown0 = true;
			break;
		case field_flag_id_read_only:
			flag_read_only = true;
			break;
		case field_flag_id_index:
			flag_index = true;
			break;
		case field_flag_id_unknown3:
			flag_unknown3 = true;
			break;
		case field_flag_id_pointer:
			flag_pointer = true;
			break;
		default:
			console_write_line("unhandled flag '%.1s' 0x%02X example:'%s'", flag, static_cast<int>(*flag), string);
			FATAL_ERROR("Unknown flag");
		}

		debug_point;
	}

	// cleanup pretty name whitespace
	{
#define NAME_SEARCH_PATTERN " %[^:|#{] "

		int search_for_name_and_alt_name_try1 = sscanf_s(
			temp_buffer,
			NAME_SEARCH_PATTERN,
			pretty_name.data, sizeof(pretty_name.data));

		debug_point;
	}

	setup_code_name();
}

c_blamlib_string_parser_v2::~c_blamlib_string_parser_v2()
{

}

void c_blamlib_string_parser_v2::fixup_flags(char* string)
{
	size_t length = strlen(string);
	if (length == 0)
	{
		return;
	}

	char* const flags_search_start = string;
	char* const flags_search_end = string + length;

	uint32_t flags_found = 0;
	char* flags_search_position = flags_search_end;
	while (
		flags_search_position > flags_search_start
		&& flags_search_position--
		&& !(
			isalnum(*flags_search_position) ||
			isspace(*flags_search_position) ||
			*flags_search_position == '-' ||
			*flags_search_position == '\'' ||
			*flags_search_position == '\"' ||
			*flags_search_position == ' ' ||
			*flags_search_position == '$' ||
			*flags_search_position == '%' ||
			*flags_search_position == ']' ||
			*flags_search_position == '?' ||
			*flags_search_position == ')' ||
			*flags_search_position == '.'))
	{
		flags_found++;
		debug_point;
	}
	flags_search_position = flags_search_end - flags_found;

	if (flags_search_position != flags_search_end)
	{
		// copies to the end of flags
		char* const flags_end = flags + strlen(flags);

		strcpy(flags_end, flags_search_position);
		flags_search_position[0] = 0; // terminate the field name buffer
	}

	debug_point;
}

void c_blamlib_string_parser_v2::setup_code_name()
{
#define assign_string_array(_array, value) strncpy(_array, value, _countof(_array)); _array[_countof(_array) - 1] = 0;

	code_name = pretty_name;

	cleanup_code_name();

	if (strcmp(code_name, "void") == 0)											code_name = "_void";
	if (strcmp(code_name, "char") == 0)											code_name = "_char";
	if (strcmp(code_name, "short") == 0)										code_name = "_short";
	if (strcmp(code_name, "long") == 0)											code_name = "_long";
	if (strcmp(code_name, "qword") == 0)										code_name = "_qword";
	if (strcmp(code_name, "dword") == 0)										code_name = "_dword";
	if (strcmp(code_name, "word") == 0)											code_name = "_word";
	if (strcmp(code_name, "byte") == 0)											code_name = "_byte";
	if (strcmp(code_name, "class") == 0)										code_name = "_class";
	if (strcmp(code_name, "default") == 0)										code_name = "_default";
	if (strcmp(code_name, "operator") == 0)										code_name = "_operator";
	if (strcmp(code_name, "protected") == 0)									code_name = "_protected";
	if (strcmp(code_name, "static") == 0)										code_name = "_static";
	if (strcmp(code_name, "template") == 0)										code_name = "_template";
	if (strcmp(code_name, "and") == 0)											code_name = "_and";
	if (strcmp(code_name, "final") == 0)										code_name = "_final";
	if (strcmp(code_name, "real") == 0)											code_name = "_real";
	if (strcmp(code_name, "angle") == 0)										code_name = "_angle";
	if (strcmp(code_name, "tag") == 0)											code_name = "_tag";
	if (strcmp(code_name, "typename") == 0)										code_name = "_typename";
	if (strcmp(code_name, "int") == 0)											code_name = "_int";
	if (strcmp(code_name, "float") == 0)										code_name = "_float";
	if (strcmp(code_name, "string") == 0)										code_name = "_string";
	if (strcmp(code_name, "register") == 0)										code_name = "_register";
	if (strcmp(code_name, "struct") == 0)										code_name = "_struct";
	if (strcmp(code_name, "s_point2d") == 0)									code_name = "_s_point2d";
	if (strcmp(code_name, "s_rectangle2d") == 0)								code_name = "_s_rectangle2d";
	if (strcmp(code_name, "pixel32") == 0)										code_name = "_pixel32";
	if (strcmp(code_name, "real_fraction") == 0)								code_name = "_real_fraction";
	if (strcmp(code_name, "real_point2d") == 0)									code_name = "_real_point2d";
	if (strcmp(code_name, "real_point3d") == 0)									code_name = "_real_point3d";
	if (strcmp(code_name, "real_vector2d") == 0)								code_name = "_real_vector2d";
	if (strcmp(code_name, "real_vector3d") == 0)								code_name = "_real_vector3d";
	if (strcmp(code_name, "real_quaternion") == 0)								code_name = "_real_quaternion";
	if (strcmp(code_name, "real_euler_angles2d") == 0)							code_name = "_real_euler_angles2d";
	if (strcmp(code_name, "real_euler_angles3d") == 0)							code_name = "_real_euler_angles3d";
	if (strcmp(code_name, "real_plane2d") == 0)									code_name = "_real_plane2d";
	if (strcmp(code_name, "real_plane3d") == 0)									code_name = "_real_plane3d";
	if (strcmp(code_name, "rgb_color") == 0)									code_name = "_rgb_color";
	if (strcmp(code_name, "argb_color") == 0)									code_name = "_argb_color";
	if (strcmp(code_name, "real_hsv_color") == 0)								code_name = "_real_hsv_color";
	if (strcmp(code_name, "real_ahsv_color") == 0)								code_name = "_real_ahsv_color";
	if (strcmp(code_name, "short_bounds") == 0)									code_name = "_short_bounds";
	if (strcmp(code_name, "angle_bounds") == 0)									code_name = "_angle_bounds";
	if (strcmp(code_name, "real_bounds") == 0)									code_name = "_real_bounds";
	if (strcmp(code_name, "not") == 0)											code_name = "_not";
	if (strcmp(code_name, "unused") == 0)										code_name = "_unused";

	//if (field->field_type == blofeld::_field_block && !code_name.ends_with("_block"))
	if (is_block && !code_name.ends_with("_block")) // #TODO: remove
	{
		code_name += "_block";
	}
	else if (!units.empty() && units.size() < 6)
	{
		code_name += "_";
		code_name += units;
		cleanup_code_name();
	}

	if (code_name.starts_with('%'))
	{
		c_fixed_string_512 temp = code_name.data;
		code_name.format("percent%s", temp.data + 1);
	}
	if (code_name.ends_with('%'))
	{
		code_name.shrink(code_name.size() - 1);
		code_name += "percent";
	}
	if (code_name.starts_with_numeric())
	{
		c_fixed_string_512 temp = code_name.data;
		code_name.format("_%s", temp.data);
	}

	if (string_list_value_unique_counter)
	{
		code_index = ++(*string_list_value_unique_counter)[code_name.data];
		if (code_index > 1)
		{
			c_fixed_string_512 temp = code_name.data;
			code_name.format("%s$%i", temp.data, code_index);
		}
	}
}

void c_blamlib_string_parser_v2::cleanup_code_name()
{
	code_name.lowercase();
	code_name.replace('\xA0', ' ');
	code_name.replace(' ', '_');
	code_name.replace('/', '_');
	code_name.replace('\\', '_');
	code_name.replace('-', '_');
	code_name.replace('+', '_');
	code_name.replace('&', '_');
	code_name.replace('|', '_');
	code_name.replace('>', '_');
	code_name.replace('<', '_');
	code_name.replace('=', '_');
	code_name.remove('[');
	code_name.remove(']');
	code_name.remove('%');
	code_name.remove('{');
	code_name.remove('}');
	code_name.remove('@');
	code_name.remove('(');
	code_name.remove(')');
	code_name.remove('.');
	code_name.remove(',');
	code_name.remove('\'');
	code_name.remove(':');
	code_name.remove(';');
	code_name.remove('\"');
	code_name.remove('?');
	code_name.remove('*');
	code_name.remove('!');

	// Halo Infinite Badness
	code_name.remove('\x92'); // Private Use Two
	code_name.remove('\xA0'); // Non-Breaking Space
}

