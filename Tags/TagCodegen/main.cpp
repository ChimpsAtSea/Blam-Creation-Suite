#include "tagcodegen-private-pch.h"

const char* c_console::g_console_executable_name = "TagCodegen";

std::pair<const char*, const char*> bespoke_fixups[] =
{
	{ "class crates + vehicles", "class crates and vehicles" },
	{ "boundary -height", "boundary negative height" },
	{ "boundary +height", "boundary positive height" },
	{ "@weapon list (update _weapon_list enum in game_globals.h)", "weapon list"},
	{ "scale_x(scale}*", "scale_x{scale}*" } // what a bag of dicks
};

class c_field_formatter
{
public:
	c_field_formatter(const blofeld::s_tag_field* field, const char* name, std::map<std::string, int>& field_name_unique_counter) :
		display_name(),
		alt_name(),
		units(),
		description(),
		minimum("0"),
		maximum(),
		code_name(),
		read_only(false),
		is_index(false)
	{
		//name = "air reverb gain*!^{reverb gain}*!^:dB*!^[   -100  ]#how much reverb applies to this sound class";
		static int y = 0;
		//write_line_verbose("%i %s", y, name);
		if (name != nullptr)
		{
			// bespoke fixups
			for (std::pair<const char*, const char*>& fixup : bespoke_fixups)
			{
				if (strcmp(name, fixup.first) == 0)
				{
					name = fixup.second;
				}
			}

			c_fixed_string_16 flags0;
			c_fixed_string_16 flags1;
			c_fixed_string_16 flags2;

			size_t remainder_buffer_size = strlen(name) + 1;
			c_stack_string remainder_buffer_a = c_stack_string(remainder_buffer_size);
			c_stack_string remainder_buffer_b = c_stack_string(remainder_buffer_size);

			int description_scan = sscanf(name, "%[^#]#%2047[^\1]", remainder_buffer_a.data, description.data);
			int min_max_scan = sscanf(remainder_buffer_a.data, "%[^[][%*[\x20]%127[^\x20,]%*[\x20],%*[\x20]%127[^\x20]]]", remainder_buffer_b.data, minimum.data, maximum.data);
			int units_scan = sscanf(remainder_buffer_b.data, "%[^:]:%255[^*^!~?]%15[^\1]", remainder_buffer_a.data, units.data, flags0.data);
			int alt_name_scan = sscanf(remainder_buffer_a.data, "%[^{]{%[^}]}%15[^\1]", remainder_buffer_b.data, alt_name.data, flags1.data);
			int display_name_scan = sscanf(remainder_buffer_b.data, "%511[^*^!~?]%15[^\1]", display_name.data, flags2.data);

			c_fixed_string_64 flags;
			flags.format("%s%s%s", flags0, flags1, flags2);

			read_only = flags.contains('*');
			is_index = flags.contains('^');

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

			if (field->field_type == blofeld::_field_block && !code_name.ends_with("_block"))
			{
				code_name += "_block";
				debug_point;
			}
			else if (!units.is_empty() && units.size() < 6)
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
				debug_point;
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

			int unique_field_count = ++field_name_unique_counter[code_name.data];

			if (unique_field_count > 1)
			{
				c_fixed_string_512 temp = code_name;
				code_name.format("%s$%i", temp.data, unique_field_count);
			}

			debug_point;
			y++;
		}
	}

	void cleanup_code_name()
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
		code_name.remove('{');
		code_name.remove('}');
		code_name.remove('@');
		code_name.remove('(');
		code_name.remove(')');
		code_name.remove('.');
		code_name.remove(',');
		code_name.remove('\'');
		code_name.remove(';');
	}

	c_fixed_string_512 display_name;
	c_fixed_string_512 alt_name;
	c_fixed_string_128 units;
	c_fixed_string_2048 description;
	c_fixed_string_128 minimum;
	c_fixed_string_128 maximum;
	bool read_only;
	bool is_index;

	c_fixed_string_512 code_name;
};

void create_source_file()
{
	std::stringstream ss;

	std::string namespace_name = "halo4";

	ss << "namespace " << namespace_name << std::endl;
	ss << "{" << std::endl << std::endl;


	for (const blofeld::s_tag_struct_definition* tag_struct_definition : blofeld::tag_struct_definitions)
	{
		ss << "\t" << "struct s_" << tag_struct_definition->name << std::endl;
		ss << "\t" << "{" << std::endl;

		std::map<std::string, int> field_name_unique_counter;

		const blofeld::s_tag_field* current_field = tag_struct_definition->fields;
		while (current_field->field_type != blofeld::_field_terminator)
		{
			c_field_formatter field_formatter = c_field_formatter(current_field, current_field->name, field_name_unique_counter);
			const char* field_type_string = blofeld::field_to_string(current_field->field_type);




			switch (current_field->field_type)
			{
			case blofeld::_field_custom:
				break;
			case blofeld::_field_explanation:
				if (current_field->name)
				{
					if (current_field->explanation && *current_field->explanation)
					{
						ss << std::endl << "\t\t" << "/* " << current_field->name << std::endl;
						ss << "\t\t ";
						const char* current_pos = current_field->explanation;
						while (*current_pos)
						{
							switch (*current_pos)
							{
							case '\n':
								ss << *current_pos;
								ss << "\t\t ";
								break;
							default:
								ss << *current_pos;
							}
							current_pos++;
						}
						ss << std::endl;
						ss << "\t\t" << "*/" << std::endl << std::endl;
					}
					else
					{
						ss << std::endl << "\t\t" << "/* " << current_field->name << " */" << std::endl << std::endl;
					}
				}
				break;
			default:
				if (field_formatter.code_name.is_empty())
				{
					ss << "\t\t" << "// " << field_type_string << std::endl;
				}
				else if(!field_formatter.description.is_empty())
				{
					ss << "\t\t" << "int" << " " << field_formatter.code_name.data << "; // ";
					const char* current_pos = field_formatter.description.data;
					while (*current_pos)
					{
						switch (*current_pos)
						{
						case '\n':
							ss << ' ';
							break;
						default:
							ss << *current_pos;
						}
						current_pos++;
					}
					ss << std::endl;
				}
				else
				{
					ss << "\t\t" << "int" << " " << field_formatter.code_name.data << ";" << std::endl;
				}
				
			}
			current_field++;
		}

		ss << "\t" << "};" << std::endl << std::endl;

		debug_point;
	}

	ss << std::endl << "} // end namespace " << namespace_name << std::endl;

	std::string source_code = ss.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + "source.h";
	bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
	ASSERT(filesystem_write_file_from_memory_result);
}

int wmain(int argc, const wchar_t** argv)
{
	if (!c_command_line::has_command_line_arg("-output"))
	{
		return 1;
	}

	create_source_file();

	int result = 0;

	return result;
}
