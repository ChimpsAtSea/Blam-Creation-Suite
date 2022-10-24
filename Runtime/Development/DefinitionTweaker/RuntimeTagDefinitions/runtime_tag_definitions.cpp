#include "definitiontweaker-private-pch.h"

c_runtime_tag_definitions::c_runtime_tag_definitions(s_engine_platform_build _engine_platform_build) :
	engine_platform_build(_engine_platform_build),
	next_runtime_unique_id(0x13371337),
	group_definitions(),
	block_definitions(),
	struct_definitions(),
	array_definitions(),
	string_list_definitions(),
	reference_definitions(),
	resource_definitions(),
	interop_definitions(),
	data_definitions(),
	block_index_custom_search_definitions()
{
	for (const blofeld::s_tag_group** tag_group_iter = blofeld::get_tag_groups_by_engine_platform_build(engine_platform_build); *tag_group_iter; tag_group_iter++)
	{
		const blofeld::s_tag_group& tag_group = **tag_group_iter;
		enqueue_tag_group_definition(tag_group);
	}
}

c_runtime_tag_group_definition* c_runtime_tag_definitions::get_tag_group_by_group_tag(tag group_tag)
{
	for (c_runtime_tag_group_definition* group_definition : group_definitions)
	{
		if (group_definition->group_tag == group_tag)
		{
			return group_definition;
		}
	}
	return nullptr;
}

c_runtime_tag_group_definition& c_runtime_tag_definitions::create_tag_group_definition()
{
	c_runtime_tag_group_definition* group_definition = new c_runtime_tag_group_definition(*this);
	group_definitions.push_back(group_definition);
	return *group_definition;
}

c_runtime_tag_block_definition& c_runtime_tag_definitions::create_tag_block_definition()
{
	c_runtime_tag_block_definition* block_definition = new c_runtime_tag_block_definition(*this);
	block_definitions.push_back(block_definition);
	return *block_definition;
}

c_runtime_tag_struct_definition& c_runtime_tag_definitions::create_tag_struct_definition()
{
	c_runtime_tag_struct_definition* struct_definition = new c_runtime_tag_struct_definition(*this);
	struct_definitions.push_back(struct_definition);
	return *struct_definition;
}

c_runtime_tag_array_definition& c_runtime_tag_definitions::create_tag_array_definition()
{
	c_runtime_tag_array_definition* array_definition = new c_runtime_tag_array_definition(*this);
	array_definitions.push_back(array_definition);
	return *array_definition;
}

c_runtime_tag_string_list_definition& c_runtime_tag_definitions::create_string_list_definition()
{
	c_runtime_tag_string_list_definition* string_list_definition = new c_runtime_tag_string_list_definition(*this);
	string_list_definitions.push_back(string_list_definition);
	return *string_list_definition;
}

c_runtime_tag_reference_definition& c_runtime_tag_definitions::create_tag_reference_definition()
{
	c_runtime_tag_reference_definition* reference_definition = new c_runtime_tag_reference_definition(*this);
	reference_definitions.push_back(reference_definition);
	return *reference_definition;
}

c_runtime_tag_resource_definition& c_runtime_tag_definitions::create_tag_resource_definition()
{
	c_runtime_tag_resource_definition* resource_definition = new c_runtime_tag_resource_definition(*this);
	resource_definitions.push_back(resource_definition);
	return *resource_definition;
}

c_runtime_tag_interop_definition& c_runtime_tag_definitions::create_tag_interop_definition()
{
	c_runtime_tag_interop_definition* interop_definition = new c_runtime_tag_interop_definition(*this);
	interop_definitions.push_back(interop_definition);
	return *interop_definition;
}

c_runtime_tag_data_definition& c_runtime_tag_definitions::create_tag_data_definition()
{
	c_runtime_tag_data_definition* data_definition = new c_runtime_tag_data_definition(*this);
	data_definitions.push_back(data_definition);
	return *data_definition;
}

c_runtime_block_index_custom_search_definition& c_runtime_tag_definitions::create_block_index_custom_search_definition()
{
	c_runtime_block_index_custom_search_definition* block_index_custom_search_definition = new c_runtime_block_index_custom_search_definition(*this);
	block_index_custom_search_definitions.push_back(block_index_custom_search_definition);
	return *block_index_custom_search_definition;
}

c_runtime_tag_group_definition& c_runtime_tag_definitions::duplicate_tag_group_definition(c_runtime_tag_group_definition& _group_definition)
{
	c_runtime_tag_group_definition* group_definition = new() c_runtime_tag_group_definition(*this, _group_definition);
	group_definitions.push_back(group_definition);
	return *group_definition;
}
c_runtime_tag_block_definition& c_runtime_tag_definitions::duplicate_tag_block_definition(c_runtime_tag_block_definition& _block_definition)
{
	c_runtime_tag_block_definition* block_definition = new() c_runtime_tag_block_definition(*this, _block_definition);
	block_definitions.push_back(block_definition);
	return *block_definition;
}
c_runtime_tag_struct_definition& c_runtime_tag_definitions::duplicate_tag_struct_definition(c_runtime_tag_struct_definition& _struct_definition)
{
	c_runtime_tag_struct_definition* struct_definition = new() c_runtime_tag_struct_definition(*this, _struct_definition);
	struct_definitions.push_back(struct_definition);
	return *struct_definition;
}
c_runtime_tag_array_definition& c_runtime_tag_definitions::duplicate_tag_array_definition(c_runtime_tag_array_definition& _array_definition)
{
	c_runtime_tag_array_definition* array_definition = new() c_runtime_tag_array_definition(*this, _array_definition);
	array_definitions.push_back(array_definition);
	return *array_definition;
}
c_runtime_tag_string_list_definition& c_runtime_tag_definitions::duplicate_string_list_definition(c_runtime_tag_string_list_definition& _string_list_definition)
{
	c_runtime_tag_string_list_definition* string_list_definition = new() c_runtime_tag_string_list_definition(*this, _string_list_definition);
	string_list_definitions.push_back(string_list_definition);
	return *string_list_definition;
}
c_runtime_tag_reference_definition& c_runtime_tag_definitions::duplicate_tag_reference_definition(c_runtime_tag_reference_definition& _reference_definition)
{
	c_runtime_tag_reference_definition* reference_definition = new() c_runtime_tag_reference_definition(*this, _reference_definition);
	reference_definitions.push_back(reference_definition);
	return *reference_definition;
}
c_runtime_tag_resource_definition& c_runtime_tag_definitions::duplicate_tag_resource_definition(c_runtime_tag_resource_definition& _resource_definition)
{
	c_runtime_tag_resource_definition* resource_definition = new() c_runtime_tag_resource_definition(*this, _resource_definition);
	resource_definitions.push_back(resource_definition);
	return *resource_definition;
}
c_runtime_tag_interop_definition& c_runtime_tag_definitions::duplicate_tag_interop_definition(c_runtime_tag_interop_definition& _interop_definition)
{
	c_runtime_tag_interop_definition* interop_definition = new() c_runtime_tag_interop_definition(*this, _interop_definition);
	interop_definitions.push_back(interop_definition);
	return *interop_definition;
}
c_runtime_tag_data_definition& c_runtime_tag_definitions::duplicate_tag_data_definition(c_runtime_tag_data_definition& _data_definition)
{
	c_runtime_tag_data_definition* data_definition = new() c_runtime_tag_data_definition(*this, _data_definition);
	data_definitions.push_back(data_definition);
	return *data_definition;
}
c_runtime_block_index_custom_search_definition& c_runtime_tag_definitions::duplicate_block_index_custom_search_definition(c_runtime_block_index_custom_search_definition& _block_index_custom_search_definition)
{
	c_runtime_block_index_custom_search_definition* block_index_custom_search_definition = new() c_runtime_block_index_custom_search_definition(*this, _block_index_custom_search_definition);
	block_index_custom_search_definitions.push_back(block_index_custom_search_definition);
	return *block_index_custom_search_definition;
}

c_runtime_tag_group_definition& c_runtime_tag_definitions::enqueue_tag_group_definition(const blofeld::s_tag_group& _tag_group_definition)
{
	for (c_runtime_tag_group_definition* group_definition : group_definitions)
	{
		if (group_definition->original_tag_group_definition == &_tag_group_definition)
		{
			return *group_definition;
		}
	}

	c_runtime_tag_group_definition* group_definition = new c_runtime_tag_group_definition(*this, _tag_group_definition);
	group_definitions.push_back(group_definition);
	return *group_definition;
}

c_runtime_tag_block_definition& c_runtime_tag_definitions::enqueue_tag_block_definition(const blofeld::s_tag_block_definition& _tag_block_definition)
{
	for (c_runtime_tag_block_definition* block_definition : block_definitions)
	{
		if (block_definition->original_tag_block_definition == &_tag_block_definition)
		{
			return *block_definition;
		}
	}

	c_runtime_tag_block_definition* block_definition = new c_runtime_tag_block_definition(*this, _tag_block_definition);
	block_definitions.push_back(block_definition);
	return *block_definition;
}

c_runtime_tag_struct_definition& c_runtime_tag_definitions::enqueue_tag_struct_definition(const blofeld::s_tag_struct_definition& _tag_struct_definition)
{
	for (c_runtime_tag_struct_definition* struct_definition : struct_definitions)
	{
		if (struct_definition->original_tag_struct_definition == &_tag_struct_definition)
		{
			return *struct_definition;
		}
	}

	c_runtime_tag_struct_definition* struct_definition = new c_runtime_tag_struct_definition(*this, _tag_struct_definition);
	struct_definitions.push_back(struct_definition);
	return *struct_definition;
}

c_runtime_tag_array_definition& c_runtime_tag_definitions::enqueue_tag_array_definition(const blofeld::s_tag_array_definition& _tag_array_definition)
{
	for (c_runtime_tag_array_definition* array_definition : array_definitions)
	{
		if (array_definition->original_tag_array_definition == &_tag_array_definition)
		{
			return *array_definition;
		}
	}

	c_runtime_tag_array_definition* array_definition = new c_runtime_tag_array_definition(*this, _tag_array_definition);
	array_definitions.push_back(array_definition);
	return *array_definition;
}

c_runtime_tag_string_list_definition& c_runtime_tag_definitions::enqueue_string_list_definition(const blofeld::s_string_list_definition& _string_list_definition)
{
	for (c_runtime_tag_string_list_definition* string_list_definition : string_list_definitions)
	{
		if (string_list_definition->original_string_list_definition == &_string_list_definition)
		{
			return *string_list_definition;
		}
	}

	c_runtime_tag_string_list_definition* string_list_definition = new c_runtime_tag_string_list_definition(*this, _string_list_definition);
	string_list_definitions.push_back(string_list_definition);
	return *string_list_definition;
}

c_runtime_tag_reference_definition& c_runtime_tag_definitions::enqueue_tag_reference_definition(const blofeld::s_tag_reference_definition& _tag_reference_definition)
{
	for (c_runtime_tag_reference_definition* reference_definition : reference_definitions)
	{
		if (reference_definition->original_reference_definition == &_tag_reference_definition)
		{
			return *reference_definition;
		}
	}

	c_runtime_tag_reference_definition* reference_definition = new c_runtime_tag_reference_definition(*this, _tag_reference_definition);
	reference_definitions.push_back(reference_definition);
	return *reference_definition;
}

c_runtime_tag_resource_definition& c_runtime_tag_definitions::enqueue_tag_resource_definition(const blofeld::s_tag_resource_definition& _tag_resource_definition)
{
	for (c_runtime_tag_resource_definition* resource_definition : resource_definitions)
	{
		if (resource_definition->original_tag_resource_definition == &_tag_resource_definition)
		{
			return *resource_definition;
		}
	}

	c_runtime_tag_resource_definition* resource_definition = new c_runtime_tag_resource_definition(*this, _tag_resource_definition);
	resource_definitions.push_back(resource_definition);
	return *resource_definition;
}

c_runtime_tag_interop_definition& c_runtime_tag_definitions::enqueue_tag_interop_definition(const blofeld::s_tag_interop_definition& _tag_interop_definition)
{
	for (c_runtime_tag_interop_definition* interop_definition : interop_definitions)
	{
		if (interop_definition->original_tag_interop_definition == &_tag_interop_definition)
		{
			return *interop_definition;
		}
	}

	c_runtime_tag_interop_definition* interop_definition = new c_runtime_tag_interop_definition(*this, _tag_interop_definition);
	interop_definitions.push_back(interop_definition);
	return *interop_definition;
}

c_runtime_tag_data_definition& c_runtime_tag_definitions::enqueue_tag_data_definition(const blofeld::s_tag_data_definition& _tag_data_definition)
{
	for (c_runtime_tag_data_definition* data_definition : data_definitions)
	{
		if (data_definition->original_tag_data_definition == &_tag_data_definition)
		{
			return *data_definition;
		}
	}

	c_runtime_tag_data_definition* data_definition = new c_runtime_tag_data_definition(*this, _tag_data_definition);
	data_definitions.push_back(data_definition);
	return *data_definition;
}

c_runtime_block_index_custom_search_definition& c_runtime_tag_definitions::enqueue_block_index_custom_search_definition(const blofeld::s_block_index_custom_search_definition& _block_index_custom_search_definition)
{
	for (c_runtime_block_index_custom_search_definition* block_index_custom_search_definition : block_index_custom_search_definitions)
	{
		if (block_index_custom_search_definition->original_block_index_custom_search_definition == &_block_index_custom_search_definition)
		{
			return *block_index_custom_search_definition;
		}
	}

	c_runtime_block_index_custom_search_definition* block_index_custom_search_definition = new c_runtime_block_index_custom_search_definition(*this, _block_index_custom_search_definition);
	block_index_custom_search_definitions.push_back(block_index_custom_search_definition);
	return *block_index_custom_search_definition;
}
