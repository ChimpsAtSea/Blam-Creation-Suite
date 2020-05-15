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
	use_standard_naming_convention(true)
{
	REFERENCE_ASSERT(tag_group);
	REFERENCE_ASSERT(source_file);

	// #TODO: Use a better name based off of the group tag and the known String ID's

	// fixup
	// #NOTE: Sometimes the tag's block is different from
	// the name. Usually `stereo_system_group` has `stereo_system_block`
	// but the HSC tag has `hsc_group` and `hs_source_files_block`

	std::string expected_block_name = std::string(tag_group.name) + "_block";
	use_standard_naming_convention = expected_block_name == tag_group.tag_block->name;

	// create the block ready for traversal so we can reserve structure names for tag groups as priority
	tag_block_container = &preprocessor.traverse_tag_blocks(tag_group.tag_block, use_standard_naming_convention, false);
	if (use_standard_naming_convention)
	{
		// setup the name to correspond with the expected block name

		bool is_sound2 = tag_block_container->name == "sound2";
		name = tag_block_container->name;
		debug_point;
	}
	

	//uint32_t index = preprocessor.tag_block_name_unique_counter[name]++;
	//if (index > 0)
	//{
	//	std::string suffix = std::to_string(index + 1);
	//	name += suffix;
	//}
	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);

	source_file.tag_groups.push_back(this);
}

bool c_h4_tag_group_container::operator ==(const c_h4_tag_group_container& container) const
{
	return &tag_group == &container.tag_group;
}

c_h4_tag_block_container::c_h4_tag_block_container(c_h4_tag_block& block, c_h4_generator_preprocessor& preprocessor, bool is_tag) :
	block(block),
	name(block.name),
	name_uppercase(),
	is_tag(is_tag),
	has_traversed(false)
{
	REFERENCE_ASSERT(block);

	name = name.substr(0, name.rfind("_block"));
	bool y = name == "authored_light_probe";
	uint32_t index = preprocessor.tag_block_name_unique_counter[name]++;
	if (index > 0)
	{
		std::string suffix = std::to_string(index + 1);
		name += "$";
		name += suffix;
	}
	bool x = name == "authored_light_probe2";
	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);

	preprocessor.tag_blocks.push_back(this);
}

bool c_h4_tag_block_container::operator ==(const c_h4_tag_block_container& container) const
{
	return &block == &container.block;
}

c_h4_generator_preprocessor::c_h4_generator_preprocessor(c_h4_blamboozle& blamboozle) :
	blamboozle(blamboozle),
	source_files()
{
	const char* perforce_blofeld_path = "d:\\perforce\\groundhog\\halo4\\shared\\engine\\source\\blofeld\\";
	for (c_h4_tag_group* tag_group : blamboozle.tag_groups)
	{
		const char* perforce_path = strstr(tag_group->tag_block->tag_struct->filepath, perforce_blofeld_path);
		ASSERT(perforce_path != nullptr);
		const char* filepath = perforce_path + strlen(perforce_blofeld_path);

		c_h4_source_file& source_file = get_source_file(filepath, *this);
		c_h4_tag_group_container* tag_group_container = new c_h4_tag_group_container(*tag_group, *this, source_file);
		tag_group_containers.push_back(tag_group_container);
	}

	for (c_h4_tag_group_container* tag_group_container : tag_group_containers)
	{
		c_h4_tag_group& tag_group = tag_group_container->tag_group;
		traverse_tag_blocks(tag_group.tag_block, tag_group_container->use_standard_naming_convention);
	}
	cleanup_tag_blocks();

	for (c_h4_tag_block_container* tag_block_container : tag_blocks)
	{
		c_h4_tag_block& tag_block = tag_block_container->block;

		const char* perforce_path = strstr(tag_block.tag_struct->filepath, perforce_blofeld_path);
		ASSERT(perforce_path != nullptr);
		const char* filepath = perforce_path + strlen(perforce_blofeld_path);

		c_h4_source_file& source_file = get_source_file(filepath, *this);
		source_file.tag_blocks.push_back(tag_block_container);
	}
}

c_h4_generator_preprocessor::~c_h4_generator_preprocessor()
{

}

c_h4_tag_block_container* c_h4_generator_preprocessor::find_existing_tag_block_container(c_h4_tag_block* tag_block)
{
	for (c_h4_tag_block_container* tag_block_container : tag_blocks)
	{
		if (&tag_block_container->block == tag_block)
		{
			return tag_block_container;
		}
	}
	return nullptr;
}

c_h4_tag_block_container& c_h4_generator_preprocessor::traverse_tag_blocks(c_h4_tag_block* tag_block, bool is_tag, bool traverse)
{
	c_h4_tag_block_container* tag_block_container = find_existing_tag_block_container(tag_block);
	if (tag_block_container == nullptr)
	{
		tag_block_container = new c_h4_tag_block_container(*tag_block, *this, is_tag);
		tag_blocks.push_back(tag_block_container);
	}
	if(traverse && !tag_block_container->has_traversed)
	{
		create_tag_block_source_count_constants(*tag_block);

		for (c_h4_tag_field* tag_field : tag_block->tag_struct->tag_fields)
		{
			c_h4_tag_field_block* block_field = dynamic_cast<c_h4_tag_field_block*>(tag_field);
			if (block_field != nullptr)
			{
				c_h4_tag_block* block = block_field->tag_block_definition;
				ASSERT(block != nullptr);
				//if (std::find(tag_blocks.begin(), tag_blocks.end(), block) == tag_blocks.end())
				{
					traverse_tag_blocks(block_field->tag_block_definition);
				}
			}
		}
		tag_block_container->has_traversed = true;
	}
	ASSERT(tag_block_container != nullptr);
	return *tag_block_container;
}

void c_h4_generator_preprocessor::cleanup_tag_blocks()
{
	decltype(tag_blocks)::iterator tag_blocks_new_end = std::unique(tag_blocks.begin(), tag_blocks.end());
	tag_blocks.erase(tag_blocks_new_end, tag_blocks.end());
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
	c_h4_tag_struct* tag_struct = tag_block.tag_struct;

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
