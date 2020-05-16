#include "blamboozlelib-private-pch.h"

class c_h4_tag_group_container;

c_h4_source_file::c_h4_source_file(const char* filepath, c_h4_generator_preprocessor& preprocessor) :
	filepath(filepath),
	preprocessor(preprocessor),
	full_source_output_filepath(),
	full_header_output_filepath(),
	tag_groups()
{
	std::string output_directory = c_command_line::get_command_line_arg("-generated-output");
	ASSERT(!output_directory.empty());

	source_output_filepath = filepath;
	header_output_filepath = filepath;
	header_output_filepath.resize(header_output_filepath.size() - 3);
	header_output_filepath += "h";

	full_source_output_filepath = output_directory + "\\" + source_output_filepath;
	full_header_output_filepath = output_directory + "\\" + header_output_filepath;
}

c_h4_tag_group_container::c_h4_tag_group_container(c_h4_tag_group& tag_group, c_h4_generator_preprocessor& preprocessor, c_h4_source_file& source_file) :
	tag_group(tag_group),
	source_file(source_file),
	name(tag_group.name),
	name_uppercase(),
	use_tag_group_definition(true)
{
	REFERENCE_ASSERT(tag_group);
	REFERENCE_ASSERT(source_file);

	// #TODO: Use a better name based off of the group tag and the known String ID's

	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);

	// create the block ready for traversal so we can reserve structure names for tag groups as priority
	std::string expected_block_name = std::string(tag_group.name) + "_block";
	use_tag_group_definition = expected_block_name == tag_group.tag_block.name;
	tag_block_container = &preprocessor.traverse_tag_blocks(tag_group.tag_block, use_tag_group_definition, false);
	tag_block_container->is_tag = use_tag_group_definition;

	// fixup
	// #NOTE: Sometimes the tag's block is different from
	// the name. Usually `stereo_system_group` has `stereo_system_block`
	// but the HSC tag has `hsc_group` and `hs_source_files_block`
	if (use_tag_group_definition) // setup the name to correspond with the expected block name
	{
		name = tag_block_container->name;
	}

	source_file.tag_groups.push_back(this);
}

bool c_h4_tag_group_container::operator ==(const c_h4_tag_group_container& container) const
{
	return &tag_group == &container.tag_group;
}

bool string_ends_with(std::string const& string, std::string const& ending) 
{
	if (string.length() >= ending.length()) 
	{
		return (0 == string.compare(string.length() - ending.length(), ending.length(), ending));
	}
	return false;
}

c_h4_tag_block_container::c_h4_tag_block_container(c_h4_tag_block& tag_block, c_h4_generator_preprocessor& preprocessor, bool is_tag) :
	tag_block(tag_block),
	name(tag_block.name),
	name_uppercase(),
	use_tag_block_definition(true),
	is_tag(is_tag),
	has_traversed(false)
{
	REFERENCE_ASSERT(tag_block);

	uint32_t index = preprocessor.tag_type_name_unique_counter[name]++;
	if (index > 0)
	{
		std::string suffix = std::to_string(index + 1);
		name += "$";
		name += suffix;
	}
	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);


	bool is_havok_convex_shape = std::string("loadScreenBlock") == name;
	bool y = std::string(tag_block.tag_struct.name) == "character_perception_block_struct";

	//std::string expected_struct_name = std::string(tag_block.tag_struct.name) + "_block_struct";
	//use_tag_block_definition = expected_struct_name == tag_block.tag_struct.name;
	use_tag_block_definition = string_ends_with(tag_block.tag_struct.name, "_block_struct") || (std::string(tag_block.name) == tag_block.tag_struct.name);
	// && !string_ends_with(tag_block.tag_struct.name, "_struct_definition");
	tag_struct_container = &preprocessor.traverse_tag_structs(tag_block.tag_struct, use_tag_block_definition, false);
	tag_struct_container->is_block = use_tag_block_definition;

	preprocessor.tag_block_containers.push_back(this);
}

bool c_h4_tag_block_container::operator ==(const c_h4_tag_block_container& container) const
{
	return &tag_block == &container.tag_block;
}

c_h4_tag_struct_container::c_h4_tag_struct_container(c_h4_tag_struct& tag_struct, c_h4_generator_preprocessor& preprocessor, bool is_block) :
	tag_struct(tag_struct),
	name(tag_struct.name),
	name_uppercase(),
	is_block(is_block),
	has_traversed(false)
{
	REFERENCE_ASSERT(tag_struct);

	uint32_t index = preprocessor.tag_type_name_unique_counter[name]++;
	bool is_havok_convex_shape = std::string("havok_convex_shape_struct") == name;
	if (!is_block)
	{
		//name = name.substr(0, name.rfind("_struct"));
		if (index > 0)
		{
			std::string suffix = std::to_string(index + 1);
			name += "$";
			name += suffix;
		}
	}
	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);

	preprocessor.tag_struct_containers.push_back(this);
}

bool c_h4_tag_struct_container::operator ==(const c_h4_tag_struct_container& container) const
{
	return &tag_struct == &container.tag_struct;
}

c_h4_generator_preprocessor::c_h4_generator_preprocessor(c_h4_blamboozle& blamboozle) :
	blamboozle(blamboozle),
	source_files()
{
	const char* perforce_blofeld_path = "d:\\perforce\\groundhog\\halo4\\shared\\engine\\source\\blofeld\\";
	for (c_h4_tag_group* tag_group : blamboozle.tag_groups) // create containers for tag groups and associate with source file
	{
		const char* perforce_path = strstr(tag_group->tag_block.tag_struct.filepath, perforce_blofeld_path);
		ASSERT(perforce_path != nullptr);
		const char* filepath = perforce_path + strlen(perforce_blofeld_path);

		c_h4_source_file& source_file = get_source_file(filepath, *this);
		c_h4_tag_group_container* tag_group_container = new c_h4_tag_group_container(*tag_group, *this, source_file);
		tag_group_containers.push_back(tag_group_container);
	}

	for (c_h4_tag_group_container* tag_group_container : tag_group_containers) // traverse tag groups to create tag blocks
	{
		c_h4_tag_group& tag_group = tag_group_container->tag_group;
		traverse_tag_blocks(tag_group.tag_block, tag_group_container->use_tag_group_definition);
	}
	cleanup_tag_blocks();

	for (c_h4_tag_block_container* tag_block_container : tag_block_containers) // associate tag groups with source file
	{
		c_h4_tag_block& tag_block = tag_block_container->tag_block;

		const char* perforce_path = strstr(tag_block.tag_struct.filepath, perforce_blofeld_path);
		ASSERT(perforce_path != nullptr);
		const char* filepath = perforce_path + strlen(perforce_blofeld_path);

		c_h4_source_file& source_file = get_source_file(filepath, *this);
		source_file.tag_blocks.push_back(tag_block_container);
	}

	for (c_h4_tag_block_container* tag_block_container : tag_block_containers) // traverse tag blocks to create tag structs
	{
		c_h4_tag_block& tag_block = tag_block_container->tag_block;
		bool y = std::string(tag_block_container->tag_block.tag_struct.name) == "cache_file_tag_zone_manifest_struct";
		traverse_tag_structs(tag_block.tag_struct, true);
	}
	cleanup_tag_structs();

	for (c_h4_tag_struct_container* tag_struct_container : tag_struct_containers) // associate tag structs with source file
	{
		c_h4_tag_struct& tag_struct = tag_struct_container->tag_struct;

		const char* perforce_path = strstr(tag_struct.filepath, perforce_blofeld_path);
		ASSERT(perforce_path != nullptr);
		const char* filepath = perforce_path + strlen(perforce_blofeld_path);

		c_h4_source_file& source_file = get_source_file(filepath, *this);
		source_file.tag_structs.push_back(tag_struct_container);
	}
}

c_h4_generator_preprocessor::~c_h4_generator_preprocessor()
{

}

c_h4_tag_block_container* c_h4_generator_preprocessor::find_existing_tag_block_container(c_h4_tag_block& tag_block)
{
	for (c_h4_tag_block_container* tag_block_container : tag_block_containers)
	{
		if (&tag_block_container->tag_block == &tag_block)
		{
			return tag_block_container;
		}
	}
	return nullptr;
}

c_h4_tag_struct_container* c_h4_generator_preprocessor::find_existing_tag_struct_container(c_h4_tag_struct& tag_struct)
{
	for (c_h4_tag_struct_container* tag_struct_container : tag_struct_containers)
	{
		if (&tag_struct_container->tag_struct == &tag_struct)
		{
			return tag_struct_container;
		}
	}
	return nullptr;
}

c_h4_tag_block_container& c_h4_generator_preprocessor::traverse_tag_blocks(c_h4_tag_block& tag_block, bool is_tag, bool traverse)
{
	c_h4_tag_block_container* tag_block_container = find_existing_tag_block_container(tag_block);
	if (tag_block_container == nullptr)
	{
		tag_block_container = new c_h4_tag_block_container(tag_block, *this, is_tag);
	}
	if(traverse && !tag_block_container->has_traversed)
	{
		create_tag_block_source_count_constants(tag_block);

		for (c_h4_tag_field* tag_field : tag_block.tag_struct.tag_fields)
		{
			c_h4_tag_field_block* block_field = dynamic_cast<c_h4_tag_field_block*>(tag_field);
			if (block_field != nullptr)
			{
				c_h4_tag_block* block = block_field->tag_block_definition;
				ASSERT(block != nullptr);
				traverse_tag_blocks(*block);
			}

			c_h4_tag_field_struct* struct_field = dynamic_cast<c_h4_tag_field_struct*>(tag_field); // found a struct, traverse it for more tag blocks
			if (struct_field != nullptr)
			{
				c_h4_tag_struct* _struct = struct_field->tag_struct;
				ASSERT(_struct != nullptr);

				for (c_h4_tag_field* tag_field : _struct->tag_fields)
				{
					c_h4_tag_field_block* block_field = dynamic_cast<c_h4_tag_field_block*>(tag_field);
					if (block_field != nullptr)
					{
						c_h4_tag_block* block = block_field->tag_block_definition;
						ASSERT(block != nullptr);
						traverse_tag_blocks(*block);
					}
				}
			}
		}
		tag_block_container->has_traversed = true;
	}
	ASSERT(tag_block_container != nullptr);
	return *tag_block_container;
}

c_h4_tag_struct_container& c_h4_generator_preprocessor::traverse_tag_structs(c_h4_tag_struct& tag_struct, bool is_block, bool traverse)
{
	//bool y = std::string(tag_struct.name) == "cache_file_tag_zone_manifest_struct";
	c_h4_tag_struct_container* tag_struct_container = find_existing_tag_struct_container(tag_struct);
	if (tag_struct_container == nullptr)
	{
		tag_struct_container = new c_h4_tag_struct_container(tag_struct, *this, is_block);
	}
	if (traverse && !tag_struct_container->has_traversed)
	{
		for (c_h4_tag_field* tag_field : tag_struct.tag_fields)
		{
			c_h4_tag_field_struct* struct_field = dynamic_cast<c_h4_tag_field_struct*>(tag_field);
			//bool x = tag_field->name ? std::string(tag_field->name) == "cache zone manifest" : false;
			if (struct_field != nullptr)
			{
				c_h4_tag_struct* _struct = struct_field->tag_struct;
				ASSERT(_struct != nullptr);
				traverse_tag_structs(*_struct);
			}

			c_h4_tag_field_block* block_field = dynamic_cast<c_h4_tag_field_block*>(tag_field); // found a block, traverse it for more tag blocks
			if (block_field != nullptr)
			{
				c_h4_tag_block* block = block_field->tag_block_definition;
				ASSERT(block != nullptr);

				for (c_h4_tag_field* tag_field : block->tag_struct.tag_fields)
				{
					c_h4_tag_field_block* block_field = dynamic_cast<c_h4_tag_field_block*>(tag_field);
					if (block_field != nullptr)
					{
						c_h4_tag_block* block = block_field->tag_block_definition;
						ASSERT(block != nullptr);
						traverse_tag_structs(block->tag_struct, true);
					}
				}
			}
		}
		tag_struct_container->has_traversed = true;
	}
	ASSERT(tag_struct_container != nullptr);
	return *tag_struct_container;
}

void c_h4_generator_preprocessor::cleanup_tag_blocks()
{
	decltype(tag_block_containers)::iterator tag_blocks_new_end = std::unique(tag_block_containers.begin(), tag_block_containers.end());
	tag_block_containers.erase(tag_blocks_new_end, tag_block_containers.end());
}

void c_h4_generator_preprocessor::cleanup_tag_structs()
{
	decltype(tag_struct_containers)::iterator tag_structs_new_end = std::unique(tag_struct_containers.begin(), tag_struct_containers.end());
	tag_struct_containers.erase(tag_structs_new_end, tag_struct_containers.end());
}

c_h4_source_file& c_h4_generator_preprocessor::get_source_file(const char* filepath, c_h4_generator_preprocessor& preprocessor)
{
	c_h4_source_file* source_file = nullptr;
	for (c_h4_source_file* current_source_file : source_files)
	{
		if (current_source_file->filepath == filepath)
		{
			source_file = current_source_file;
			break;
		}
	}

	if (source_file == nullptr)
	{
		source_file = new c_h4_source_file(filepath, preprocessor);
		source_files.push_back(source_file);
	}

	return *source_file;
}

c_h4_tag_group_container* c_h4_generator_preprocessor::get_container_by_group_tag(uint32_t group_tag)
{
	if (group_tag != 0xFFFFFFFF)
	{
		for (c_h4_tag_group_container* tag_group_container : tag_group_containers)
		{
			if (tag_group_container->tag_group.group_tag.value == group_tag)
			{
				return tag_group_container;
			}
		}
	}

	return nullptr;
}

void c_h4_generator_preprocessor::create_tag_block_source_count_constants(c_h4_tag_block& tag_block)
{
	const char* const maximum_element_count_string = tag_block.maximum_element_count_string;

	bool only_contains_digits = true;
	{
		const char* digits_search_string = maximum_element_count_string;
		while (*digits_search_string)
		{
			if (!isdigit(*digits_search_string++))
			{
				only_contains_digits = false;
				break;
			}
		}
	}

	if (!only_contains_digits)
	{
		std::stringstream source_line_stream;


		const char* maximum_element_count_string_namespace_end = strstr(maximum_element_count_string, "::");
		std::vector<std::string>* maximum_count_constants_source_lines = nullptr;
		if (maximum_element_count_string_namespace_end)
		{
			maximum_count_constants_source_lines = &maximum_count_constants_source_lines_struct;
			std::string _namespace = { maximum_element_count_string , maximum_element_count_string_namespace_end };
			maximum_element_count_string_namespace_end += 2;

			source_line_stream << "struct " << _namespace << std::endl;
			source_line_stream << "{" << std::endl;
			source_line_stream << "\tconst unsigned long " << maximum_element_count_string_namespace_end << " = " << tag_block.maximum_element_count << ";" << std::endl;
			source_line_stream << "};" << std::endl;
		}
		else if (islower(*tag_block.maximum_element_count_string) || !isalpha(*tag_block.maximum_element_count_string))
		{
			maximum_count_constants_source_lines = &maximum_count_constants_source_lines_constant;
			source_line_stream << "const unsigned long " << tag_block.maximum_element_count_string << " = " << tag_block.maximum_element_count << ";" << std::endl;
		}
		else
		{
			maximum_count_constants_source_lines = &maximum_count_constants_source_lines_define;
			source_line_stream << "#define " << tag_block.maximum_element_count_string << " " << tag_block.maximum_element_count << std::endl;
		}

		std::string source_line = source_line_stream.str();

		std::vector<std::string>::iterator source_line_search = std::find(
			maximum_count_constants_source_lines->begin(),
			maximum_count_constants_source_lines->end(),
			source_line
		);

		if (source_line_search == maximum_count_constants_source_lines->end())
		{
			maximum_count_constants_source_lines->push_back(source_line);
		}
	}
}
