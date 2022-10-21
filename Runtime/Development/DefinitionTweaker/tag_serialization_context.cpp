#include "definitiontweaker-private-pch.h"

c_tag_serialization_context::c_tag_serialization_context(c_group_serialization_context* _group_serialization_context, s_engine_platform_build _engine_platform_build, const char* _tag_data_start) :
	engine_platform_build(_engine_platform_build),
	tag_data_start(_tag_data_start),
	tag_data_end(),
	tag_header(),
	dependencies(),
	data_fixups(),
	resource_fixups(),
	_end(),
	tag_root_structure(),
	expected_main_struct_size(),
	root_struct_serialization_context(),
	group_serialization_context(_group_serialization_context),
	serialization_errors()
{

}

c_tag_serialization_context::~c_tag_serialization_context()
{
	delete root_struct_serialization_context;

	for (auto seralization_error : serialization_errors)
	{
		delete seralization_error;
	}
}

unsigned int c_tag_serialization_context::read()
{
	tag_header = reinterpret_cast<const s_cache_file_tag_instance*>(tag_data_start);

	tag_data_end = tag_data_start + tag_header->total_size;

	tag group_tag = tag_header->group_tags[0];
	const blofeld::s_tag_group* tag_group = nullptr;
	for (const blofeld::s_tag_group** tag_group_iter = blofeld::get_tag_groups_by_engine_platform_build(engine_platform_build); *tag_group_iter; tag_group_iter++)
	{
		const blofeld::s_tag_group& current_tag_group = **tag_group_iter;
		if (current_tag_group.group_tag == group_tag)
		{
			tag_group = &current_tag_group;
		}
	}

	if (tag_group)
	{
		dependencies = reinterpret_cast<const int*>(tag_header);
		data_fixups = dependencies + tag_header->dependency_count;
		resource_fixups = data_fixups + tag_header->data_fixup_count;
		_end = resource_fixups + tag_header->resource_fixup_count;

		if (tag_header->dependency_count == 0)
		{
			dependencies = nullptr;
		}

		if (tag_header->data_fixup_count == 0)
		{
			data_fixups = nullptr;
		}

		if (tag_header->resource_fixup_count == 0)
		{
			resource_fixups = nullptr;
		}

		tag_root_structure = tag_data_start + tag_header->offset;
		expected_main_struct_size = tag_header->total_size - tag_header->offset;

		root_struct_serialization_context = new c_tag_struct_serializtion_context(*this, tag_group->block_definition.struct_definition, expected_main_struct_size);

		if (expected_main_struct_size != root_struct_serialization_context->struct_size)
		{
			serialization_errors.push_back(new c_generic_serializtion_error("unexpected struct size expected:%u calculated:%u", expected_main_struct_size, root_struct_serialization_context->struct_size));
		}
	}
	else
	{
		unsigned int group_tag_swapped = byteswap(group_tag);
		serialization_errors.push_back(new c_generic_serializtion_error("couldn't find tag group '%.4s'", &group_tag_swapped));
	}

	return serialization_errors.size();
}

unsigned int c_tag_serialization_context::traverse()
{
	unsigned int num_errors = 0;



	return num_errors;
}
