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
			if (code_name == "final") code_name = "_final";
			if (code_name == "real") code_name = "_real";

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

const char* field_type_to_source_type(blofeld::e_field field_type)
{
	switch (field_type)
	{
	case blofeld::_field_string:							return "c_static_string<32>";
	case blofeld::_field_long_string:						return "c_static_string<256>";
	case blofeld::_field_string_id:							return "string_id";
	case blofeld::_field_old_string_id:						return "c_old_string_id";
	case blofeld::_field_char_integer:						return "char";
	case blofeld::_field_short_integer:						return "short";
	case blofeld::_field_long_integer:						return "long";
	case blofeld::_field_int64_integer:						return "long long";
	case blofeld::_field_angle:								return "angle";
	case blofeld::_field_tag:								return "tag";
	case blofeld::_field_char_enum:							return "char";
	case blofeld::_field_enum:								return "short";
	case blofeld::_field_long_enum:							return "long";
	case blofeld::_field_long_flags:						return "long";
	case blofeld::_field_word_flags:						return "word";
	case blofeld::_field_byte_flags:						return "byte";
	case blofeld::_field_point_2d:							return "s_point2d";
	case blofeld::_field_rectangle_2d:						return "s_rectangle2d";
	case blofeld::_field_rgb_color:							return "pixel32";
	case blofeld::_field_argb_color:						return "pixel32";
	case blofeld::_field_real:								return "real";
	case blofeld::_field_real_fraction:						return "real_fraction";
	case blofeld::_field_real_point_2d:						return "real_point2d";
	case blofeld::_field_real_point_3d:						return "real_point3d";
	case blofeld::_field_real_vector_2d:					return "real_vector2d";
	case blofeld::_field_real_vector_3d:					return "real_vector3d";
	case blofeld::_field_real_quaternion:					return "real_quaternion";
	case blofeld::_field_real_euler_angles_2d:				return "real_euler_angles2d";
	case blofeld::_field_real_euler_angles_3d:				return "real_euler_angles3d";
	case blofeld::_field_real_plane_2d:						return "real_plane2d";
	case blofeld::_field_real_plane_3d:						return "real_plane3d";
	case blofeld::_field_real_rgb_color:					return "rgb_color";
	case blofeld::_field_real_argb_color:					return "argb_color";
	case blofeld::_field_real_hsv_color:					return "real_hsv_color";
	case blofeld::_field_real_ahsv_color:					return "real_ahsv_color";
	case blofeld::_field_short_bounds:						return "short_bounds";
	case blofeld::_field_angle_bounds:						return "angle_bounds";
	case blofeld::_field_real_bounds:						return "real_bounds";
	case blofeld::_field_real_fraction_bounds:				return "real_bounds";
	case blofeld::_field_tag_reference:						return "s_tag_reference";
	case blofeld::_field_block:								return "s_tag_block";
	case blofeld::_field_long_block_flags:					return "long";
	case blofeld::_field_word_block_flags:					return "word";
	case blofeld::_field_byte_block_flags:					return "byte";
	case blofeld::_field_char_block_index:					return "char";
	case blofeld::_field_custom_char_block_index:			return "char";
	case blofeld::_field_short_block_index:					return "short";
	case blofeld::_field_custom_short_block_index:			return "short";
	case blofeld::_field_long_block_index:					return "long";
	case blofeld::_field_custom_long_block_index:			return "long";
	case blofeld::_field_data:								return "s_tag_data";
	case blofeld::_field_vertex_buffer:						return "s_tag_d3d_vertex_buffer";
	case blofeld::_field_pad:								throw;	// dynamic
	case blofeld::_field_useless_pad:						throw;	// dynamic
	case blofeld::_field_skip:								throw;	// dynamic
	case blofeld::_field_non_cache_runtime_value:			return "long";
	case blofeld::_field_explanation:						throw;	// empty
	case blofeld::_field_custom:							throw;	// empty
	case blofeld::_field_struct:							throw;	// dynamic
	case blofeld::_field_array:								throw;	// dynamic
	case blofeld::_field_pageable:							return "s_tag_resource";
	case blofeld::_field_api_interop:						return "s_tag_interop";
	case blofeld::_field_terminator:						throw;	// empty
	case blofeld::_field_byte_integer:						return "byte";
	case blofeld::_field_word_integer:						return "word";
	case blofeld::_field_dword_integer:						return "dword";
	case blofeld::_field_qword_integer:						return "qword";
	default: FATAL_ERROR(L"Unknown field type");
	}
}

class c_structure_relationship_node
{
public:
	c_structure_relationship_node(const blofeld::s_tag_struct_definition& tag_struct_definition) :
		tag_struct_definition(tag_struct_definition),
		written_to_source(false),
		child_nodes()
	{

	}

	void populate()
	{
		const blofeld::s_tag_field* current_field = tag_struct_definition.fields;
		while (current_field->field_type != blofeld::_field_terminator)
		{
			switch (current_field->field_type)
			{
			case blofeld::_field_struct:
			{
				c_structure_relationship_node& structure_relationship_node = get_node_by_structure(*current_field->struct_definition);
				child_nodes.emplace_back(&structure_relationship_node);
				break;
			}
			case blofeld::_field_block:
			{
				c_structure_relationship_node& structure_relationship_node = get_node_by_structure(current_field->block_definition->struct_definition);
				child_nodes.emplace_back(&structure_relationship_node);
				break;
			}
			case blofeld::_field_array:
			{
				c_structure_relationship_node& structure_relationship_node = get_node_by_structure(current_field->array_definition->struct_definition);
				child_nodes.emplace_back(&structure_relationship_node);
				break;
			}
			}
			current_field++;
		}
	}

	void create_sorted_tag_struct_definitions_impl()
	{
		if (!written_to_source)
		{
			written_to_source = true;

			for (c_structure_relationship_node* node : child_nodes)
			{
				node->create_sorted_tag_struct_definitions_impl();
			}
			sorted_tag_struct_definitions.push_back(&tag_struct_definition);
		}
	}

	static void create_sorted_tag_struct_definitions()
	{
		for (c_structure_relationship_node* node : nodes)
		{
			node->create_sorted_tag_struct_definitions_impl();
		}
	}

	static c_structure_relationship_node& get_node_by_structure(const blofeld::s_tag_struct_definition& tag_struct_definition)
	{
		for (c_structure_relationship_node* node : nodes)
		{
			if (&node->tag_struct_definition == &tag_struct_definition)
			{
				return *node;
			}
		}
		throw;
	}

	static void create_structure_relationships()
	{
		for (const blofeld::s_tag_struct_definition* tag_struct_definition : blofeld::tag_struct_definitions)
		{
			nodes.push_back(new c_structure_relationship_node(*tag_struct_definition));
		}
		for (c_structure_relationship_node* node : nodes)
		{
			node->populate();
		}
	}

	bool written_to_source;
	const blofeld::s_tag_struct_definition& tag_struct_definition;
	std::vector<c_structure_relationship_node*> child_nodes;
	static std::vector<c_structure_relationship_node*> nodes;
	static std::vector<const blofeld::s_tag_struct_definition*> sorted_tag_struct_definitions;
};
std::vector<c_structure_relationship_node*> c_structure_relationship_node::nodes;
std::vector<const blofeld::s_tag_struct_definition*> c_structure_relationship_node::sorted_tag_struct_definitions;
















const blofeld::s_tag_group* get_tag_group_by_group_tag(long group_tag)
{
	for (const blofeld::s_tag_group* tag_group : blofeld::tag_groups)
	{
		if (tag_group->group_tag == group_tag)
		{
			return tag_group;
		}
	}
	return nullptr;
}


void create_source_file()
{
	c_structure_relationship_node::create_structure_relationships();
	c_structure_relationship_node::create_sorted_tag_struct_definitions();








	std::stringstream ss;

	std::string namespace_name = "halo4";

	ss << std::endl;
	ss << std::endl;

	ss << "namespace blofeld" << std::endl;
	ss << "{" << std::endl;
	ss << "\tnamespace " << namespace_name << std::endl;
	ss << "\t{" << std::endl;
	ss << "#pragma pack(push, 1)" << std::endl << std::endl;


	for (const blofeld::s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		ss << "\t\t" << "struct s_" << tag_struct_definition->name << std::endl;
		ss << "\t\t" << "{" << std::endl;

		std::map<std::string, int> field_name_unique_counter;

		const blofeld::s_tag_field* current_field = tag_struct_definition->fields;
		while (current_field->field_type != blofeld::_field_terminator)
		{
			c_field_formatter field_formatter = c_field_formatter(current_field, current_field->name, field_name_unique_counter);
			const char* field_type_string = blofeld::field_to_string(current_field->field_type);




			switch (current_field->field_type)
			{
			case blofeld::_field_pad:
				ss << "\t\t\t" << "char " << field_formatter.code_name << "[" << current_field->padding << "]; // padding" << std::endl;
				break;
			case blofeld::_field_skip:
				ss << "\t\t\t" << "char " << field_formatter.code_name << "[" << current_field->padding << "]; // skip" << std::endl;
				break;
			case blofeld::_field_useless_pad:
				ss << "\t\t\t" << "// char " << field_formatter.code_name << "[" << current_field->padding << "]; // useless padding" << std::endl;
				break;
			case blofeld::_field_custom:
				ss << "\t\t\t" << "// " << field_type_string;
				if (!field_formatter.code_name.is_empty())
				{
					ss << " " << field_formatter.code_name;
				}
				ss << std::endl;
				break;
			case blofeld::_field_terminator:
				ss << "\t\t\t" << "// " << field_type_string << std::endl;
				break;
			case blofeld::_field_explanation:
			{
				if (current_field->name)
				{
					if (current_field->explanation && *current_field->explanation)
					{
						ss << std::endl << "\t\t\t" << "/* " << current_field->name << std::endl;
						ss << "\t\t\t ";
						const char* current_pos = current_field->explanation;
						while (*current_pos)
						{
							switch (*current_pos)
							{
							case '\n':
								ss << *current_pos;
								ss << "\t\t\t ";
								break;
							default:
								ss << *current_pos;
							}
							current_pos++;
						}
						ss << std::endl;
						ss << "\t\t\t" << "*/" << std::endl << std::endl;
					}
					else
					{
						ss << std::endl << "\t\t\t" << "/* " << current_field->name << " */" << std::endl << std::endl;
					}
				}
				break;
			}
			case blofeld::_field_array:
			{
				const char* field_source_type = current_field->array_definition->struct_definition.name;
				ss << "\t\t\t" << "s_" << field_source_type << " " << field_formatter.code_name << "[" << current_field->array_definition->count << "];";
				break;
			}
			case blofeld::_field_struct:
			{
				const char* field_source_type = current_field->struct_definition->name;
				ss << "\t\t\t" << "s_" << field_source_type << " " << field_formatter.code_name << ";";
				break;
			}
			case blofeld::_field_block:
			{
				const char* field_source_type = current_field->block_definition->struct_definition.name;
				ss << "\t\t\t" << "c_typed_tag_block<s_" << field_source_type << "> " << field_formatter.code_name << ";";
				break;
			}
			case blofeld::_field_tag_reference:
			{
				ASSERT(current_field->tag_reference_definition);
				
				bool handled = false;

				long group_tag = current_field->tag_reference_definition->group_tag;
				uint32_t group_tag_count = current_field->tag_reference_definition->group_tag;



				std::vector<unsigned long> group_tags;

				if (current_field->tag_reference_definition->group_tag != blofeld::INVALID_TAG)
				{
					group_tags.emplace_back(current_field->tag_reference_definition->group_tag);
				}
				else if (current_field->tag_reference_definition->group_tags)
				{
					for (const unsigned long* current_group_tag = current_field->tag_reference_definition->group_tags; *current_group_tag != blofeld::INVALID_TAG; current_group_tag++)
					{
						group_tags.push_back(*current_group_tag);
					}
				}


				if (group_tags.empty())
				{
					ss << "\t\t\t" << "s_tag_reference " << field_formatter.code_name << ";";
				}
				else
				{
					
					ss << "\t\t\t" << "c_typed_tag_reference<";

					for (size_t group_tag_index = 0; group_tag_index < group_tags.size(); group_tag_index++)
					{
						const blofeld::s_tag_group* tag_group = get_tag_group_by_group_tag(group_tags[group_tag_index]);
						ASSERT(tag_group != nullptr);
						if (group_tag_index > 0)
						{
							ss << ", ";
						}

						c_fixed_string_128 tag_group_name = tag_group->name;
						tag_group_name += "_TAG";
						tag_group_name.uppercase();

						ss << tag_group_name.data;
					}
					ss << "> " << field_formatter.code_name << ";";
				}

				break;
			}
			default:
			{
				const char* field_source_type = field_type_to_source_type(current_field->field_type);
				ASSERT(!field_formatter.code_name.is_empty());
				ss << "\t\t\t" << field_source_type << " " << field_formatter.code_name.data << ";";
			}
			}

			constexpr bool k_write_field_types = false;
			switch (current_field->field_type)
			{
			case blofeld::_field_pad:
			case blofeld::_field_skip:
			case blofeld::_field_useless_pad:
			case blofeld::_field_custom:
			case blofeld::_field_terminator:
			case blofeld::_field_explanation:
				break;
			default:
				if (!field_formatter.description.is_empty() || k_write_field_types)
				{
					ss << " // ";
					if constexpr (k_write_field_types) ss << field_type_string << " ";
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
				}
				ss << std::endl;
			}

			current_field++;
		}

		ss << "\t\t" << "};" << std::endl;

		uint32_t struct_size = calculate_struct_size(*tag_struct_definition);

		ss << "\t\t" << "static constexpr size_t " << tag_struct_definition->name << "_size = sizeof(s_" << tag_struct_definition->name << ");" << std::endl;
		ss << "\t\t" << "static_assert(" << tag_struct_definition->name << "_size == " << std::uppercase << std::dec << __max(1u, struct_size) << ", \"struct s_" << tag_struct_definition->name << " is invalid size\");" << std::endl;

		ss << std::endl;

		debug_point;


	}

	ss << "#pragma pack(pop)" << std::endl;
	ss << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	ss << std::endl << "} // end namespace blofeld" << std::endl;

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
