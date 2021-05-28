
std::pair<const char*, const char*> c_blamlib_string_parser::bespoke_fixups[] =
{
	{ "class crates + vehicles", "class crates and vehicles" },
	{ "boundary -height", "boundary negative height" },
	{ "boundary +height", "boundary positive height" },
	{ "@weapon list (update _weapon_list enum in game_globals.h)", "weapon list"},
	{ "scale_x(scale}*", "scale_x{scale}*" }, // what a bag of dicks
	{ "pivot stride length scale: leg length * this = stride length", "pivot stride length scale#leg length * this = stride length" }
};

c_blamlib_string_parser::c_blamlib_string_parser(const char* _string, bool is_block, t_blamlib_string_parser_unique_counter* field_name_unique_counter) :
	string(_string ? _string : ""),
	display_name(),
	alt_name(),
	units(),
	description(),
	minimum(),
	maximum(),
	code_name(),
	read_only(false),
	is_index(false),
	is_pointer(false)
{
	if (string.empty())
	{
		return;
	}

	if (string[0] == '*')
	{
		string = string.c_str() + 1;
	}

	// bespoke fixups
	for (std::pair<const char*, const char*>& fixup : bespoke_fixups)
	{
		if (strcmp(string.c_str(), fixup.first) == 0)
		{
			string = fixup.second;
		}
	}

	c_fixed_string_16 flags0;
	c_fixed_string_16 flags1;
	c_fixed_string_16 flags2;

	size_t remainder_buffer_size = strlen(string.c_str()) + 1;
	c_stack_string remainder_buffer_a = c_stack_string(remainder_buffer_size);
	c_stack_string remainder_buffer_b = c_stack_string(remainder_buffer_size);

	int description_scan = sscanf(string.c_str(), "%[^#]#%2047[^\1]", remainder_buffer_a.data, description.data);
	int min_max_scan = sscanf(remainder_buffer_a.data, "%[^[][%*[\x20]%127[^\x20,]%*[\x20],%*[\x20]%127[^\x20]]]", remainder_buffer_b.data, minimum.data, maximum.data);
	int units_scan = sscanf(remainder_buffer_b.data, "%[^:]:%255[^*^!~?\1]%15[^\xFF]", remainder_buffer_a.data, units.data, flags0.data);
	int alt_name_scan = sscanf(remainder_buffer_a.data, "%[^{]{%[^}]}%15[^\xFF]", remainder_buffer_b.data, alt_name.data, flags1.data);
	int display_name_scan = sscanf(remainder_buffer_b.data, "%511[^*^!~?\1]%15[^\xFF]", display_name.data, flags2.data);

	flags0.trim_front();
	flags1.trim_front();
	flags2.trim_front();

	c_fixed_string_64 flags;
	flags.format("%s%s%s", flags0.data, flags1.data, flags2.data);

	read_only = flags.contains('*');
	is_index = flags.contains('^');
	is_pointer = flags.contains('\1');

	code_name = display_name;

	// bespoke fixups
	for (std::pair<const char*, const char*>& fixup : bespoke_fixups)
	{
		if (code_name == fixup.first)
		{
			code_name = fixup.second;
		}
	}

	cleanup_code_name();

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
		c_fixed_string_512 temp = code_name;
		code_name.format("percent%s", temp.data + 1);
	}
	if (code_name.ends_with('%'))
	{
		code_name.shrink(code_name.size() - 1);
		code_name += "percent";
	}
	if (code_name.starts_with_numeric())
	{
		c_fixed_string_512 temp = code_name;
		code_name.format("_%s", temp.data);
	}

	if (code_name == "char") code_name = "_char";
	if (code_name == "short") code_name = "_short";
	if (code_name == "class") code_name = "_class";
	if (code_name == "default") code_name = "_default";
	if (code_name == "operator") code_name = "_operator";
	if (code_name == "protected") code_name = "_protected";
	if (code_name == "static") code_name = "_static";
	if (code_name == "template") code_name = "_template";
	if (code_name == "and") code_name = "_and";
	if (code_name == "final") code_name = "_final";
	if (code_name == "real") code_name = "_real";
	if (code_name == "angle") code_name = "_angle";

	if (field_name_unique_counter)
	{
		int unique_field_count = ++(*field_name_unique_counter)[code_name.data];

		if (unique_field_count > 1)
		{
			c_fixed_string_512 temp = code_name;
			code_name.format("%s$%i", temp.data, unique_field_count);
		}
	}
}

void c_blamlib_string_parser::cleanup_code_name()
{
	code_name.lowercase();
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
}

c_blamlib_string_parser_v2::c_blamlib_string_parser_v2(const char* string) :
	buffer_length(string ? static_cast<uint32_t>(strlen(string) + 1u) : 0u),
	buffer_aggregate(string ? new char[k_num_buffers * buffer_length]{} : nullptr),
	name(*reinterpret_cast<char(*)[]>(&buffer_aggregate[_buffer_name * buffer_length])),
	old_name(*reinterpret_cast<char(*)[]>(&buffer_aggregate[_buffer_old_name * buffer_length])),
	flags(*reinterpret_cast<char(*)[]>(&buffer_aggregate[_buffer_flags * buffer_length])),
	units(*reinterpret_cast<char(*)[]>(&buffer_aggregate[_buffer_units * buffer_length])),
	limits(*reinterpret_cast<char(*)[]>(&buffer_aggregate[_buffer_limits * buffer_length])),
	limits_legacy(*reinterpret_cast<char(*)[]>(&buffer_aggregate[_buffer_limits_legacy * buffer_length])),
	meta(*reinterpret_cast<char(*)[]>(&buffer_aggregate[_buffer_meta * buffer_length])),
	description(*reinterpret_cast<char(*)[]>(&buffer_aggregate[_buffer_description * buffer_length])),
	flag_unknown0(false),
	flag_read_only(false),
	flag_index(false),
	flag_unknown3(false),
	flag_unknown4(false),
	flag_pointer(false)
{
	if (string == nullptr)
	{
		return;
	}

	// these strings have been incorrectly entered by Bungie/343.
	// if you are responsible for this, fuck you. you wasted so
	// much of my fucking time.
	struct s_string_replacement { const char* const old_string; const char* const new_string; };
	const s_string_replacement bad_strings[] =
	{
		{ "scale_x(scale}*", "scale_x{scale}*" }, // what a bag of dicks
	{ "name^`", "name^" }, // it's okay, get a third party reverse engineer to review your code years later
	};
	for (const s_string_replacement& string_replacement : bad_strings)
	{
		if (strcmp(string, string_replacement.old_string) == 0)
		{
			string = string_replacement.new_string;
			break;
		}
	}

	const char* read_position = string;

	{
		//#define NAME_SEARCH_PATTERN "%[^][:|#{]"
#define NAME_SEARCH_PATTERN " %[^:|#{] "
#define OLD_NAME_SEARCH_PATTERN " {%[^}]} "
#define FLAGS_SEARCH_PATTERN " %[^][:|#] "

		// read name, alt names, and flags
		int search_for_name_and_alt_name = sscanf(read_position, NAME_SEARCH_PATTERN OLD_NAME_SEARCH_PATTERN FLAGS_SEARCH_PATTERN, name, old_name, flags);

		if (search_for_name_and_alt_name >= 1) // found name
		{
			read_position = strstr(read_position, name) + strlen(name);

			// name flags cleanup
			fixup_flags(name);
		}
		if (search_for_name_and_alt_name >= 2) // found old_name
		{
			read_position = strstr(read_position, old_name) + strlen(old_name);
			read_position += 1; // ]
		}
		if (search_for_name_and_alt_name >= 3) // found flags
		{
			read_position = strstr(read_position, flags) + strlen(flags);
		}

		debug_point;

#undef NAME_SEARCH_PATTERN
#undef OLD_NAME_SEARCH_PATTERN
#undef FLAGS_SEARCH_PATTERN

#define NAME_IGNORE_SEARCH_PATTERN " %*[^[] "
#define LIMITS_LEGACY_SEARCH_PATTERN " [%[^]]] "

		{
			// limits_legacy
			int search_for_limits_legacy = sscanf(name, NAME_IGNORE_SEARCH_PATTERN LIMITS_LEGACY_SEARCH_PATTERN, limits_legacy);

			// only try to fixup specific formats
			// otherwise some fields with array names will break eg. 'havok w m_pad256[1]*~!!'
			if (strstr(limits_legacy, ",") != nullptr || strstr(limits_legacy, " to ") != nullptr)
			{
				if (search_for_limits_legacy >= 1)
				{
					char* name_end = strstr(name, limits_legacy) - 1;
					while (name_end > name && isspace(name_end[-1])) name_end--; // remove any whitespace from name
					*name_end = 0; // terminator
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
		int search_for_description_and_units = sscanf(read_position, ":" UNIT_SEARCH_PATTERN LIMITS_SEARCH_PATTERN, units, limits);

		read_position += 1; // colon
		if (search_for_description_and_units == 0) // couldn't find units, check for limits
		{
			int search_for_limits = sscanf(read_position, LIMITS_SEARCH_PATTERN, limits);
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
		int search_for_meta = sscanf(read_position, "|" META_SEARCH_PATTERN, meta);

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
		int search_for_description = sscanf(read_position, "#" DESCRIPTION_SEARCH_PATTERN, description);

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
			c_console::write_line("unhandled flag '%.1s' 0x%02X example:'%s'", flag, static_cast<int>(*flag), string);
			FATAL_ERROR(L"Unknown flag");
		}

		debug_point;
	}
}

c_blamlib_string_parser_v2::~c_blamlib_string_parser_v2()
{
	delete[] buffer_aggregate;
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

