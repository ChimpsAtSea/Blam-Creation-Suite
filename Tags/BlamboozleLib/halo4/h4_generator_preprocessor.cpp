#include "blamboozlelib-private-pch.h"

class c_h4_tag_group_container;




c_h4_source_file::c_h4_source_file(const char* filepath, c_h4_generator_preprocessor& preprocessor) :
	preprocessor(preprocessor),
	is_header(string_ends_with(filepath, ".h")),
	is_inline(string_ends_with(filepath, ".inl")),
	source_output_filepath(filepath),
	header_output_filepath(filepath),
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
	symbol_name(name),
	name_uppercase(),
	define_tag_group_block_and_fields(true)
{
	REFERENCE_ASSERT(tag_group);
	REFERENCE_ASSERT(source_file);

	// #TODO: Use a better name based off of the group tag and the known String ID's

	// create the block ready for traversal so we can reserve structure names for tag groups as priority

	//bool define_fields_candidate = string_ends_with(tag_group.tag_block.name, "_block");
	std::string expected_name = name + "_block";
	bool define_fields_candidate = tag_group.tag_block.name == expected_name;
	tag_block_container = &preprocessor.traverse_tag_blocks(tag_group.tag_block, define_fields_candidate, false);
	tag_struct_container = tag_block_container->tag_struct_container;
	tag_struct_container->is_tag_group = true;

	// #NOTE: If the struct isn't a block, we have to create a block to be able to use the structure!
	define_tag_group_block_and_fields = tag_struct_container->is_block && define_fields_candidate;
	tag_block_container->defined_by_tag_group = define_tag_group_block_and_fields;



	if (!tag_block_container->use_tag_block_definition)
	{
		ASSERT(!tag_struct_container->is_block);
	}


	if (define_tag_group_block_and_fields) // fixups
	{
		std::string expected_block_symbol_name = name + "_block";
		tag_block_container->symbol_name = expected_block_symbol_name;

		//std::string expected_struct_symbol_name = name + "_block_struct";
		std::string expected_struct_symbol_name = name;
		tag_struct_container->symbol_name = expected_struct_symbol_name;
	}
	symbol_name = name + "_group";
	if (symbol_name == tag_struct_container->symbol_name)
	{
		tag_struct_container->symbol_name += "_struct_definition";
	}
	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);
	source_file.tag_groups.push_back(this);
}

bool c_h4_tag_group_container::operator ==(const c_h4_tag_group_container& container) const
{
	return &tag_group == &container.tag_group;
}

c_h4_tag_interop_container::c_h4_tag_interop_container(c_h4_tag_interop& tag_interop_definition, c_h4_generator_preprocessor& preprocessor) :
	tag_interop_definition(tag_interop_definition),
	tag_struct_container(nullptr)
{
	tag_struct_container = &preprocessor.traverse_tag_structs(tag_interop_definition.tag_struct, false, false, true, false);
	tag_struct_container->is_interop = true;
	tag_struct_container->tag_interop_container = this;

	uint32_t index = preprocessor.tag_type_name_unique_counter[name]++;
	if (index > 0)
	{
		std::string suffix = std::to_string(index + 1);
		name += "$";
		name += suffix;
	}

	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);
	preprocessor.tag_interop_containers.push_back(this);
}

bool c_h4_tag_interop_container::operator ==(const c_h4_tag_interop_container& container) const
{
	return &tag_interop_definition == &container.tag_interop_definition;
}

c_h4_tag_block_container::c_h4_tag_block_container(c_h4_tag_block& tag_block, c_h4_generator_preprocessor& preprocessor, bool is_tag) :
	tag_block(tag_block),
	tag_struct_container(nullptr),
	name(tag_block.name),
	symbol_name(name),
	name_uppercase(),
	use_tag_block_definition(true),
	defined_by_tag_group(is_tag),
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

	//std::string expected_struct_name = std::string(tag_block.tag_struct.name) + "_block_struct";
	//use_tag_block_definition = expected_struct_name == tag_block.tag_struct.name;
	use_tag_block_definition = string_ends_with(tag_block.tag_struct.name, "_block_struct") || (std::string(tag_block.name) == tag_block.tag_struct.name);
	// && !string_ends_with(tag_block.tag_struct.name, "_struct_definition");
	tag_struct_container = &preprocessor.traverse_tag_structs(tag_block.tag_struct, use_tag_block_definition, tag_block.is_array, false, false);
	tag_struct_container->is_block = use_tag_block_definition;
	tag_struct_container->tag_block_container = this;

	if (tag_block.is_block)
	{
		symbol_name = name + "_block";
	}
	if (tag_block.is_array)
	{
		symbol_name = name + "_array";
	}
	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);
	preprocessor.tag_block_containers.push_back(this);
}

bool c_h4_tag_block_container::operator ==(const c_h4_tag_block_container& container) const
{
	return &tag_block == &container.tag_block;
}

c_h4_tag_struct_container::c_h4_tag_struct_container(c_h4_tag_struct& tag_struct, c_h4_generator_preprocessor& preprocessor, bool is_block, bool is_array, bool is_interop) :
	tag_block_container(nullptr),
	tag_interop_container(nullptr),
	tag_struct(tag_struct),
	name(tag_struct.name),
	symbol_name(name),
	name_uppercase(),
	is_block(is_block),
	is_array(is_array),
	is_interop(is_interop),
	is_tag_group(false),
	has_traversed(false)
{
	REFERENCE_ASSERT(tag_struct);

	uint32_t index = preprocessor.tag_type_name_unique_counter[name]++;
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

	symbol_name = name;
	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);
	preprocessor.tag_struct_containers.push_back(this);
}

bool c_h4_tag_struct_container::operator ==(const c_h4_tag_struct_container& container) const
{
	return &tag_struct == &container.tag_struct;
}

c_h4_tag_enum_container::c_h4_tag_enum_container(c_h4_tag_enum& tag_enum, c_h4_generator_preprocessor& preprocessor) :
	tag_enum(tag_enum),
	name(tag_enum.name),
	symbol_name(name),
	name_uppercase()
{
	REFERENCE_ASSERT(tag_enum);

	uint32_t index = preprocessor.tag_type_name_unique_counter[name]++;
	if (index > 0)
	{
		std::string suffix = std::to_string(index + 1);
		name += "$";
		name += suffix;
	}

	symbol_name = name;
	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);
	preprocessor.tag_enum_containers.push_back(this);
}

bool c_h4_tag_enum_container::operator ==(const c_h4_tag_enum_container& container) const
{
	return &tag_enum == &container.tag_enum;
}

#include <MandrillLib\CacheInterface\tag_group_names.inl>

c_h4_tag_reference_container::c_h4_tag_reference_container(c_h4_tag_reference& tag_reference, c_h4_generator_preprocessor& preprocessor) :
	tag_reference(tag_reference),
	name(),
	symbol_name(),
	name_uppercase(),
	is_tag_group_reference(false),
	is_empty_and_unknown_reference(false),
	is_template(false)
{
	REFERENCE_ASSERT(tag_reference);

	if (tag_reference.public_symbol)
	{
		name = tag_reference.public_symbol->symbol_name;
		//if (!string_replace(name, "Tag::Reference<s_", "Tag::Reference<struct s_"))
		{
			//string_replace(name, "Tag::Reference<", "Tag::Reference<class ");
		}
		is_template = string_replace(name, "Tag::Reference<c_", "Tag::Reference<class c_") || string_replace(name, "Tag::Reference<", "Tag::Reference<struct ");

		symbol_name = name;

	}
	else if (tag_reference.tag_groups.size() == 0)
	{
		is_empty_and_unknown_reference = true; // don't know its symbol name, and it accepts any input. ignore it.
	}
	else if (tag_reference.tag_groups.size() == 1)
	{
		is_tag_group_reference = true;
		for (c_h4_tag_group* tag_group : preprocessor.blamboozle.tag_groups)
		{
			if (tag_reference.tag_groups[0].value == tag_group->group_tag.value)
			{
				name = std::string(tag_group->name) + "_reference";
				goto found;
			}
			if (tag_reference.tag_groups[0].value == _byteswap_ulong(*reinterpret_cast<const unsigned long*>(&tag_group->group_tag.value)))
			{
				name = std::string(tag_group->name) + "_reference";
				goto found;
			}
		}
		FATAL_ERROR(L"Whhhaaaattt???");
		for (std::pair<int, const char*>& tag_group : tag_group_names)
		{
			if (tag_reference.tag_groups[0].value == _byteswap_ulong(*reinterpret_cast<const unsigned long*>(&tag_group.first)))
			{
				name = std::string(tag_group.second) + "_reference";
				goto found;
			}
		}
		found:

		ASSERT(tag_reference.tag_groups.size() == 1);
	}

	if (!name.empty())
	{
		uint32_t index = preprocessor.tag_type_name_unique_counter[name]++;
		if (index > 0)
		{
			std::string suffix = std::to_string(index + 1);
			name += "$";
			name += suffix;
		}
	}

	name_uppercase = name;
	std::transform(name_uppercase.begin(), name_uppercase.end(), name_uppercase.begin(), ::toupper);
	preprocessor.tag_reference_containers.push_back(this);
}

bool c_h4_tag_reference_container::operator ==(const c_h4_tag_reference_container& container) const
{
	return &tag_reference == &container.tag_reference;
}

c_h4_generator_preprocessor::c_h4_generator_preprocessor(c_h4_blamboozle& blamboozle) :
	blamboozle(blamboozle),
	source_files()
{
	for (c_h4_tag_group* tag_group : blamboozle.tag_groups) // create containers for tag groups and associate with source file
	{
		const char* blofeld_path = strstr(tag_group->tag_block.tag_struct.filepath, "blofeld\\");
		ASSERT(blofeld_path != nullptr);
		const char* filepath = blofeld_path + strlen("blofeld\\");

		c_h4_source_file& source_file = get_source_file(filepath, *this);
		c_h4_tag_group_container* group_container = new c_h4_tag_group_container(*tag_group, *this, source_file);
		group_containers.push_back(group_container);
	}

	for (c_h4_tag_group_container* group_container : group_containers) // traverse tag groups to create tag blocks
	{
		c_h4_tag_group& tag_group = group_container->tag_group;
		traverse_tag_blocks(tag_group.tag_block, group_container->define_tag_group_block_and_fields);
	}
	cleanup_tag_blocks();

	for (c_h4_tag_block_container* tag_block_container : tag_block_containers) // associate tag groups with source file
	{
		c_h4_tag_block& tag_block = tag_block_container->tag_block;

		const char* perforce_path = strstr(tag_block.tag_struct.filepath, "blofeld\\");
		ASSERT(perforce_path != nullptr);
		const char* filepath = perforce_path + strlen("blofeld\\");

		c_h4_source_file& source_file = get_source_file(filepath, *this);
		source_file.tag_blocks.push_back(tag_block_container);
	}

	for (c_h4_tag_block_container* tag_block_container : tag_block_containers) // traverse tag blocks to create tag structs
	{
		c_h4_tag_block& tag_block = tag_block_container->tag_block;
		traverse_tag_structs(tag_block.tag_struct, true, false, false, true);
	}
	cleanup_tag_structs();

	for (c_h4_tag_struct_container* tag_struct_container : tag_struct_containers) // associate tag structs with source file
	{
		c_h4_tag_struct& tag_struct = tag_struct_container->tag_struct;

		const char* perforce_path = strstr(tag_struct.filepath, "blofeld\\");
		ASSERT(perforce_path != nullptr);
		const char* filepath = perforce_path + strlen("blofeld\\");

		c_h4_source_file& source_file = get_source_file(filepath, *this);
		source_file.tag_structs.push_back(tag_struct_container);
	}

	for (std::pair<const void*, c_h4_tag_enum*> tag_enum_key : c_h4_blamboozle::tag_enum_definitions)
	{
		c_h4_tag_enum& tag_enum = *tag_enum_key.second;

		c_h4_tag_enum_container* tag_enum_container = find_existing_tag_enum_container(tag_enum);
		if (tag_enum_container == nullptr)
		{
			tag_enum_container = new c_h4_tag_enum_container(tag_enum, *this);
		}
	}

	for (c_h4_tag_enum_container* tag_enum_container : tag_enum_containers) // associate tag structs with source file
	{
		c_h4_tag_enum& tag_enum = tag_enum_container->tag_enum;

		const char* perforce_path = strstr(tag_enum.filepath, "blofeld\\");
		ASSERT(perforce_path != nullptr);
		const char* filepath = perforce_path + strlen("blofeld\\");

		c_h4_source_file& source_file = get_source_file(filepath, *this);
		source_file.tag_enums.push_back(tag_enum_container);
	}

	for (std::pair<const void*, c_h4_tag_reference*> tag_reference_key : c_h4_blamboozle::tag_reference_definitions)
	{
		c_h4_tag_reference& tag_reference = *tag_reference_key.second;

		c_h4_tag_reference_container* tag_reference_container = find_existing_tag_reference_container(tag_reference);
		if (tag_reference_container == nullptr)
		{
			tag_reference_container = new c_h4_tag_reference_container(tag_reference, *this);
		}
	}

	for (c_h4_tag_reference_container* tag_reference_container : tag_reference_containers) // associate tag structs with source file
	{
		c_h4_tag_reference& tag_reference = tag_reference_container->tag_reference;

		c_h4_source_file* assumed_source_file = nullptr;
		if (tag_reference_container->tag_reference.public_symbol)
		{
			if (string_ends_with(tag_reference_container->tag_reference.public_symbol->lib_and_object, ".obj"))
			{
				std::string approximate_filename = tag_reference_container->tag_reference.public_symbol->lib_and_object;
				size_t begin = approximate_filename.find(":") + 1;
				approximate_filename = std::string(approximate_filename.begin() + begin, approximate_filename.end() - 4);
				approximate_filename += ".cpp";
				string_transform_lowercase(&approximate_filename.front(), &approximate_filename.back());

				for (uint32_t pos = 0; pos < approximate_filename.size(); pos++)
				{
					approximate_filename[pos] = approximate_filename[pos];
				}

				for (c_h4_source_file* source_file : source_files)
				{
					if (string_ends_with(source_file->source_output_filepath, approximate_filename))
					{
						assumed_source_file = source_file;
						break;
					}
				}

				for (const char* filepath : source_tree)
				{
					if (string_ends_with(filepath, approximate_filename))
					{
						approximate_filename = filepath;
						const char* blofeld_path = strstr(filepath, "blofeld\\");
						ASSERT(blofeld_path != nullptr);
						approximate_filename = blofeld_path + strlen("blofeld\\");

						assumed_source_file = &get_source_file(approximate_filename.c_str(), *this);
						break;
					}
				}

				if (!assumed_source_file)
				{
					approximate_filename = std::string("__unknown\\") + approximate_filename;
					assumed_source_file = &get_source_file(approximate_filename.c_str(), *this);
				}
			}
		}
		if (assumed_source_file == nullptr)
		{
			assumed_source_file = &get_source_file("__unknown\\tag_references.cpp", *this);
		}

		ASSERT(assumed_source_file != nullptr);
		c_h4_source_file& source_file = *assumed_source_file;

		source_file.tag_references.push_back(tag_reference_container);
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

c_h4_tag_enum_container* c_h4_generator_preprocessor::find_existing_tag_enum_container(c_h4_tag_enum& tag_enum)
{
	for (c_h4_tag_enum_container* tag_enum_container : tag_enum_containers)
	{
		if (&tag_enum_container->tag_enum == &tag_enum)
		{
			return tag_enum_container;
		}
	}
	return nullptr;
}

c_h4_tag_reference_container* c_h4_generator_preprocessor::find_existing_tag_reference_container(c_h4_tag_reference& tag_reference)
{
	for (c_h4_tag_reference_container* tag_reference_container : tag_reference_containers)
	{
		if (&tag_reference_container->tag_reference == &tag_reference)
		{
			return tag_reference_container;
		}
	}
	return nullptr;
}

void c_h4_generator_preprocessor::process_tag_reference_field(c_h4_tag_field* tag_field, c_h4_tag_struct& tag_struct)
{
	c_h4_tag_field_tag_reference* tag_field_reference = dynamic_cast<c_h4_tag_field_tag_reference*>(tag_field);
	ASSERT(tag_field_reference);

	c_h4_tag_reference* tag_reference = tag_field_reference->reference;
	ASSERT(tag_reference != nullptr);

	c_h4_tag_reference_container* tag_reference_container = find_existing_tag_reference_container(*tag_reference);
	if (tag_reference_container == nullptr)
	{
		tag_reference_container = new c_h4_tag_reference_container(*tag_reference, *this);
	}

	if (tag_reference_container->name.empty())
	{
		std::vector<char> field_name_data = { tag_field->name, tag_field->name + (tag_field->name ? strlen(tag_field->name) : 0) };

		field_name_data.push_back(0);
		for (char& c : field_name_data)
		{
			if (c == '{' || c == '#')
			{
				c = 0;
				break;
			}
		}


		tag_reference_container->name = std::string(tag_struct.name) + "_" + field_name_data.data() + "_reference";


		string_remove(tag_reference_container->name, "^");
		string_remove(tag_reference_container->name, "*");
		string_remove(tag_reference_container->name, "(");
		string_remove(tag_reference_container->name, ")");
		string_replace(tag_reference_container->name, " ", "_");

		tag_reference_container->symbol_name = tag_reference_container->name;
		tag_reference_container->name_uppercase = tag_reference_container->name;
		string_transform_uppercase(tag_reference_container->name_uppercase.data(), tag_reference_container->name_uppercase.size());



		
	}
}

void c_h4_generator_preprocessor::process_tag_block_field(c_h4_tag_field* tag_field, c_h4_tag_struct& tag_struct)
{
	if (c_h4_tag_field_block* tag_field_block = dynamic_cast<c_h4_tag_field_block*>(tag_field))
	{
		c_h4_tag_block* tag_block = tag_field_block->tag_block_definition;
		ASSERT(tag_block != nullptr);
		traverse_tag_blocks(*tag_block);
	}

	if (c_h4_tag_field_array* tag_field_array = dynamic_cast<c_h4_tag_field_array*>(tag_field))
	{
		c_h4_tag_array* tag_struct = tag_field_array->tag_array_definition;
		ASSERT(tag_struct != nullptr);
		traverse_tag_blocks(*tag_struct);
	}

	if (c_h4_tag_field_tag_reference* tag_field_reference = dynamic_cast<c_h4_tag_field_tag_reference*>(tag_field))
	{
		process_tag_reference_field(tag_field, tag_struct);
	}

	if (c_h4_tag_field_struct* tag_field_struct = dynamic_cast<c_h4_tag_field_struct*>(tag_field)) // found a struct, traverse it for more tag blocks
	{
		c_h4_tag_struct* tag_struct = tag_field_struct->tag_struct;
		ASSERT(tag_struct != nullptr);
		traverse_tag_structs(*tag_struct, false, false, false, true);

		for (c_h4_tag_field* tag_field : tag_struct->tag_fields)
		{
			process_tag_struct_field(tag_field, *tag_struct);
		}
	}
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
			process_tag_block_field(tag_field, tag_block.tag_struct);
		}
		tag_block_container->has_traversed = true;
	}
	ASSERT(tag_block_container != nullptr);
	return *tag_block_container;
}

void c_h4_generator_preprocessor::process_tag_struct_field(c_h4_tag_field* tag_field, c_h4_tag_struct& tag_struct)
{
	if (c_h4_tag_field_struct* struct_field = dynamic_cast<c_h4_tag_field_struct*>(tag_field))
	{
		c_h4_tag_struct* _struct = struct_field->tag_struct;
		ASSERT(_struct != nullptr);
		traverse_tag_structs(*_struct, false, false, false, true);
	}

	if (c_h4_tag_interop_definition* interop_field = dynamic_cast<c_h4_tag_interop_definition*>(tag_field))
	{
		c_h4_tag_interop* tag_interop = interop_field->tag_interop_definition;
		ASSERT(tag_interop != nullptr);
		c_h4_tag_struct& _struct = tag_interop->tag_struct;
		traverse_tag_structs(_struct, false, false, false, true);
	}

	if (c_h4_tag_field_array* tag_field_array = dynamic_cast<c_h4_tag_field_array*>(tag_field))
	{
		c_h4_tag_array* tag_array = tag_field_array->tag_array_definition;
		ASSERT(tag_array != nullptr);
		traverse_tag_blocks(*tag_array);
	}

	if (c_h4_tag_field_tag_reference* tag_field_reference = dynamic_cast<c_h4_tag_field_tag_reference*>(tag_field))
	{
		process_tag_reference_field(tag_field, tag_struct);
	}

	// found a block, traverse it for more tag blocks
	if (c_h4_tag_field_block* block_field = dynamic_cast<c_h4_tag_field_block*>(tag_field))
	{
		c_h4_tag_block* block = block_field->tag_block_definition;
		ASSERT(block != nullptr);
		traverse_tag_blocks(*block, false, true);

		for (c_h4_tag_field* tag_field : block->tag_struct.tag_fields)
		{
			process_tag_block_field(tag_field, block->tag_struct);
		}
	}
}

c_h4_tag_struct_container& c_h4_generator_preprocessor::traverse_tag_structs(c_h4_tag_struct& tag_struct, bool is_block, bool is_array, bool is_interop, bool traverse)
{
	//bool y = std::string(tag_struct.name) == "cache_file_tag_zone_manifest_struct";
	c_h4_tag_struct_container* tag_struct_container = find_existing_tag_struct_container(tag_struct);
	if (tag_struct_container == nullptr)
	{
		tag_struct_container = new c_h4_tag_struct_container(tag_struct, *this, is_block, is_array, is_interop);
	}
	if (traverse && !tag_struct_container->has_traversed)
	{
		for (c_h4_tag_field* tag_field : tag_struct.tag_fields)
		{
			process_tag_struct_field(tag_field, tag_struct);
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
		if (current_source_file->source_output_filepath == filepath)
		{
			source_file = current_source_file;
			break;
		}
		if (current_source_file->header_output_filepath == filepath)
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
		for (c_h4_tag_group_container* group_container : group_containers)
		{
			if (group_container->tag_group.group_tag.value == group_tag)
			{
				return group_container;
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
