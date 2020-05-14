#include "blamboozlelib-private-pch.h"

class c_h4_tag_group_container;

c_h4_source_file::c_h4_source_file(const char* filepath) :
	filepath(filepath),
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

c_h4_tag_group_container::c_h4_tag_group_container(c_h4_tag_group& tag_group, c_h4_source_file& source_file) :
	tag_group(tag_group),
	source_file(source_file),
	name_uppercase(tag_group.name)
{
	REFERENCE_ASSERT(tag_group);
	REFERENCE_ASSERT(source_file);

	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);

	source_file.tag_groups.push_back(this);
}

bool c_h4_tag_group_container::operator ==(const c_h4_tag_group_container& container) const
{
	return &tag_group == &container.tag_group;
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

		c_h4_source_file& source_file = get_source_file(filepath);
		c_h4_tag_group_container* tag_group_container = new c_h4_tag_group_container(*tag_group, source_file);
		tag_group_containers.push_back(tag_group_container);
	}
}

c_h4_generator_preprocessor::~c_h4_generator_preprocessor()
{

}

c_h4_source_file& c_h4_generator_preprocessor::get_source_file(const char* filepath)
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
		source_file = new c_h4_source_file(filepath);
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
