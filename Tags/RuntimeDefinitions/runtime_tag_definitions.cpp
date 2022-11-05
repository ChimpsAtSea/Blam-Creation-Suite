#include "runtimedefinitions-private-pch.h"

#define coerce_underlying_map(map_name) reinterpret_cast<decltype(map_name)&>(c_blamtoozle_tag_definition_manager::map_name)

c_runtime_tag_definitions::c_runtime_tag_definitions(s_engine_platform_build _engine_platform_build) :
	c_blamtoozle_tag_definition_manager(),
	tag_group_definitions(coerce_underlying_map(tag_group_definitions)),
	tag_block_definitions(coerce_underlying_map(tag_block_definitions)),
	tag_struct_definitions(coerce_underlying_map(tag_struct_definitions)),
	tag_array_definitions(coerce_underlying_map(tag_array_definitions)),
	tag_string_list_definitions(coerce_underlying_map(tag_string_list_definitions)),
	tag_reference_definitions(coerce_underlying_map(tag_reference_definitions)),
	tag_resource_definitions(coerce_underlying_map(tag_resource_definitions)),
	tag_api_interop_definitions(coerce_underlying_map(tag_api_interop_definitions)),
	tag_data_definitions(coerce_underlying_map(tag_data_definitions)),
	tag_block_index_custom_search_definitions(coerce_underlying_map(tag_block_index_custom_search_definitions)),
	engine_platform_build(_engine_platform_build)
{
	for (const blofeld::s_tag_group** tag_group_iter = blofeld::get_tag_groups_by_engine_platform_build(engine_platform_build); *tag_group_iter; tag_group_iter++)
	{
		const blofeld::s_tag_group& tag_group = **tag_group_iter;
		enqueue_tag_group_definition(tag_group);
	}
}

void c_runtime_tag_definitions::traverse(ptr64 group_table_address, uint32_t num_tag_layouts)
{

}

const char* c_runtime_tag_definitions::va_to_pointer(ptr64 address)
{
	return reinterpret_cast<const char*>(static_cast<intptr_t>(address));
}

const char* c_runtime_tag_definitions::pa_to_pointer(ptr64 address)
{
	return reinterpret_cast<const char*>(static_cast<intptr_t>(address));
}

c_runtime_tag_group_definition* c_runtime_tag_definitions::get_tag_group_by_group_tag(tag group_tag)
{
	for (c_runtime_tag_group_definition* group_definition : tag_group_definitions)
	{
		if (group_definition->group_tag == group_tag)
		{
			return group_definition;
		}
	}
	return nullptr;
}

void c_runtime_tag_definitions::sort_tag_group_definitions()
{
	std::sort(
		tag_group_definitions.begin(),
		tag_group_definitions.end(),
		[](c_runtime_tag_group_definition* a, c_runtime_tag_group_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

void c_runtime_tag_definitions::sort_tag_block_definitions()
{
	std::sort(
		tag_block_definitions.begin(),
		tag_block_definitions.end(),
		[](c_runtime_tag_block_definition* a, c_runtime_tag_block_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

void c_runtime_tag_definitions::sort_tag_struct_definitions()
{
	std::sort(
		tag_struct_definitions.begin(),
		tag_struct_definitions.end(),
		[](c_runtime_tag_struct_definition* a, c_runtime_tag_struct_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

void c_runtime_tag_definitions::sort_tag_array_definitions()
{
	std::sort(
		tag_array_definitions.begin(),
		tag_array_definitions.end(),
		[](c_runtime_tag_array_definition* a, c_runtime_tag_array_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

void c_runtime_tag_definitions::sort_string_list_definitions()
{
	std::sort(
		tag_string_list_definitions.begin(),
		tag_string_list_definitions.end(),
		[](c_runtime_string_list_definition* a, c_runtime_string_list_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

void c_runtime_tag_definitions::sort_tag_reference_definitions()
{
	std::sort(
		tag_reference_definitions.begin(),
		tag_reference_definitions.end(),
		[](c_runtime_tag_reference_definition* a, c_runtime_tag_reference_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

void c_runtime_tag_definitions::sort_tag_resource_definitions()
{
	std::sort(
		tag_resource_definitions.begin(),
		tag_resource_definitions.end(),
		[](c_runtime_tag_resource_definition* a, c_runtime_tag_resource_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

void c_runtime_tag_definitions::sort_tag_api_interop_definitions()
{
	std::sort(
		tag_api_interop_definitions.begin(),
		tag_api_interop_definitions.end(),
		[](c_runtime_tag_api_interop_definition* a, c_runtime_tag_api_interop_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

void c_runtime_tag_definitions::sort_tag_data_definitions()
{
	std::sort(
		tag_data_definitions.begin(),
		tag_data_definitions.end(),
		[](c_runtime_tag_data_definition* a, c_runtime_tag_data_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

void c_runtime_tag_definitions::sort_block_index_custom_search_definitions()
{
	std::sort(
		tag_block_index_custom_search_definitions.begin(),
		tag_block_index_custom_search_definitions.end(),
		[](c_runtime_tag_block_index_custom_search_definition* a, c_runtime_tag_block_index_custom_search_definition* b)
		{
			return stricmp(a->name.c_str(), b->name.c_str()) < 0;
		});
}

c_runtime_tag_group_definition& c_runtime_tag_definitions::create_tag_group_definition()
{
	c_runtime_tag_group_definition* group_definition = new() c_runtime_tag_group_definition(*this);
	tag_group_definitions.push_back(group_definition);
	return *group_definition;
}

c_runtime_tag_block_definition& c_runtime_tag_definitions::create_tag_block_definition()
{
	c_runtime_tag_block_definition* block_definition = new() c_runtime_tag_block_definition(*this);
	tag_block_definitions.push_back(block_definition);
	return *block_definition;
}

c_runtime_tag_struct_definition& c_runtime_tag_definitions::create_tag_struct_definition()
{
	c_runtime_tag_struct_definition* struct_definition = new() c_runtime_tag_struct_definition(*this);
	tag_struct_definitions.push_back(struct_definition);
	return *struct_definition;
}

c_runtime_tag_array_definition& c_runtime_tag_definitions::create_tag_array_definition()
{
	c_runtime_tag_array_definition* array_definition = new() c_runtime_tag_array_definition(*this);
	tag_array_definitions.push_back(array_definition);
	return *array_definition;
}

c_runtime_string_list_definition& c_runtime_tag_definitions::create_string_list_definition()
{
	c_runtime_string_list_definition* string_list_definition = new() c_runtime_string_list_definition(*this);
	tag_string_list_definitions.push_back(string_list_definition);
	return *string_list_definition;
}

c_runtime_tag_reference_definition& c_runtime_tag_definitions::create_tag_reference_definition()
{
	c_runtime_tag_reference_definition* reference_definition = new() c_runtime_tag_reference_definition(*this);
	tag_reference_definitions.push_back(reference_definition);
	return *reference_definition;
}

c_runtime_tag_resource_definition& c_runtime_tag_definitions::create_tag_resource_definition()
{
	c_runtime_tag_resource_definition* resource_definition = new() c_runtime_tag_resource_definition(*this);
	tag_resource_definitions.push_back(resource_definition);
	return *resource_definition;
}

c_runtime_tag_api_interop_definition& c_runtime_tag_definitions::create_tag_api_interop_definition()
{
	c_runtime_tag_api_interop_definition* api_interop_definition = new() c_runtime_tag_api_interop_definition(*this);
	tag_api_interop_definitions.push_back(api_interop_definition);
	return *api_interop_definition;
}

c_runtime_tag_data_definition& c_runtime_tag_definitions::create_tag_data_definition()
{
	c_runtime_tag_data_definition* data_definition = new() c_runtime_tag_data_definition(*this);
	tag_data_definitions.push_back(data_definition);
	return *data_definition;
}

c_runtime_tag_block_index_custom_search_definition& c_runtime_tag_definitions::create_block_index_custom_search_definition()
{
	c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition = new() c_runtime_tag_block_index_custom_search_definition(*this);
	tag_block_index_custom_search_definitions.push_back(block_index_custom_search_definition);
	return *block_index_custom_search_definition;
}

c_runtime_tag_field_definition& c_runtime_tag_definitions::create_tag_field_definition()
{
	c_runtime_tag_field_definition* field_definition = new() c_runtime_tag_field_definition(*this);
	tag_field_definitions.push_back(field_definition);
	return *field_definition;
}

c_runtime_tag_group_definition& c_runtime_tag_definitions::duplicate_tag_group_definition(c_runtime_tag_group_definition& _group_definition)
{
	c_runtime_tag_group_definition* group_definition = new() c_runtime_tag_group_definition(*this, _group_definition);
	tag_group_definitions.push_back(group_definition);
	return *group_definition;
}

c_runtime_tag_block_definition& c_runtime_tag_definitions::duplicate_tag_block_definition(c_runtime_tag_block_definition& _block_definition)
{
	c_runtime_tag_block_definition* block_definition = new() c_runtime_tag_block_definition(*this, _block_definition);
	tag_block_definitions.push_back(block_definition);
	return *block_definition;
}

c_runtime_tag_struct_definition& c_runtime_tag_definitions::duplicate_tag_struct_definition(c_runtime_tag_struct_definition& _struct_definition)
{
	c_runtime_tag_struct_definition* struct_definition = new() c_runtime_tag_struct_definition(*this, _struct_definition);
	tag_struct_definitions.push_back(struct_definition);
	return *struct_definition;
}

c_runtime_tag_array_definition& c_runtime_tag_definitions::duplicate_tag_array_definition(c_runtime_tag_array_definition& _array_definition)
{
	c_runtime_tag_array_definition* array_definition = new() c_runtime_tag_array_definition(*this, _array_definition);
	tag_array_definitions.push_back(array_definition);
	return *array_definition;
}

c_runtime_string_list_definition& c_runtime_tag_definitions::duplicate_string_list_definition(c_runtime_string_list_definition& _string_list_definition)
{
	c_runtime_string_list_definition* string_list_definition = new() c_runtime_string_list_definition(*this, _string_list_definition);
	tag_string_list_definitions.push_back(string_list_definition);
	return *string_list_definition;
}

c_runtime_tag_reference_definition& c_runtime_tag_definitions::duplicate_tag_reference_definition(c_runtime_tag_reference_definition& _reference_definition)
{
	c_runtime_tag_reference_definition* reference_definition = new() c_runtime_tag_reference_definition(*this, _reference_definition);
	tag_reference_definitions.push_back(reference_definition);
	return *reference_definition;
}

c_runtime_tag_resource_definition& c_runtime_tag_definitions::duplicate_tag_resource_definition(c_runtime_tag_resource_definition& _resource_definition)
{
	c_runtime_tag_resource_definition* resource_definition = new() c_runtime_tag_resource_definition(*this, _resource_definition);
	tag_resource_definitions.push_back(resource_definition);
	return *resource_definition;
}

c_runtime_tag_api_interop_definition& c_runtime_tag_definitions::duplicate_tag_api_interop_definition(c_runtime_tag_api_interop_definition& _api_interop_definition)
{
	c_runtime_tag_api_interop_definition* api_interop_definition = new() c_runtime_tag_api_interop_definition(*this, _api_interop_definition);
	tag_api_interop_definitions.push_back(api_interop_definition);
	return *api_interop_definition;
}

c_runtime_tag_data_definition& c_runtime_tag_definitions::duplicate_tag_data_definition(c_runtime_tag_data_definition& _data_definition)
{
	c_runtime_tag_data_definition* data_definition = new() c_runtime_tag_data_definition(*this, _data_definition);
	tag_data_definitions.push_back(data_definition);
	return *data_definition;
}

c_runtime_tag_block_index_custom_search_definition& c_runtime_tag_definitions::duplicate_block_index_custom_search_definition(c_runtime_tag_block_index_custom_search_definition& _block_index_custom_search_definition)
{
	c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition = new() c_runtime_tag_block_index_custom_search_definition(*this, _block_index_custom_search_definition);
	tag_block_index_custom_search_definitions.push_back(block_index_custom_search_definition);
	return *block_index_custom_search_definition;
}

c_runtime_tag_field_definition& c_runtime_tag_definitions::duplicate_tag_field_definition(c_runtime_tag_field_definition& _field_definition)
{
	c_runtime_tag_field_definition* field_definition = new() c_runtime_tag_field_definition(*this, _field_definition);
	tag_field_definitions.push_back(field_definition);
	return *field_definition;
}

template<typename T>
bool valid_by_value(std::vector<T*>& vector, T* value)
{
	for (size_t index = 0; index < vector.size(); index++)
	{
		if (vector[index] == value)
		{
			return true;
		}
	}
	return false;
}

bool c_runtime_tag_definitions::is_tag_group_definition_valid(c_runtime_tag_group_definition* group_definition)
{
	bool is_valid = valid_by_value(tag_group_definitions, group_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_tag_block_definition_valid(c_runtime_tag_block_definition* block_definition)
{
	bool is_valid = valid_by_value(tag_block_definitions, block_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_tag_struct_definition_valid(c_runtime_tag_struct_definition* struct_definition)
{
	bool is_valid = valid_by_value(tag_struct_definitions, struct_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_tag_array_definition_valid(c_runtime_tag_array_definition* array_definition)
{
	bool is_valid = valid_by_value(tag_array_definitions, array_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_string_list_definition_valid(c_runtime_string_list_definition* string_list_definition)
{
	bool is_valid = valid_by_value(tag_string_list_definitions, string_list_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_tag_reference_definition_valid(c_runtime_tag_reference_definition* reference_definition)
{
	bool is_valid = valid_by_value(tag_reference_definitions, reference_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_tag_resource_definition_valid(c_runtime_tag_resource_definition* resource_definition)
{
	bool is_valid = valid_by_value(tag_resource_definitions, resource_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_tag_api_interop_definition_valid(c_runtime_tag_api_interop_definition* api_interop_definition)
{
	bool is_valid = valid_by_value(tag_api_interop_definitions, api_interop_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_tag_data_definition_valid(c_runtime_tag_data_definition* data_definition)
{
	bool is_valid = valid_by_value(tag_data_definitions, data_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_block_index_custom_search_definition_valid(c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition)
{
	bool is_valid = valid_by_value(tag_block_index_custom_search_definitions, block_index_custom_search_definition);
	return is_valid;
}

bool c_runtime_tag_definitions::is_tag_field_definition_valid(c_runtime_tag_field_definition* field_definition)
{
	bool is_valid = valid_by_value(tag_field_definitions, field_definition);
	return is_valid;
}

template<typename T>
void erase_by_value(std::vector<T*>& vector, T* value)
{
	for (size_t index = 0; index < vector.size(); index++)
	{
		if (vector[index] == value)
		{
			vector.erase(vector.begin() + index);
			break;
		}
	}
}

void c_runtime_tag_definitions::delete_tag_group_definition(c_runtime_tag_group_definition& group_definition)
{
	erase_by_value(tag_group_definitions, &group_definition);
	delete& group_definition;

	//for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	//{
	//	if (tag_field_definition->group_definition == &group_definition)
	//	{
	//		tag_field_definition->group_definition = nullptr;
	//	}
	//}
}

void c_runtime_tag_definitions::delete_tag_block_definition(c_runtime_tag_block_definition& block_definition)
{
	erase_by_value(tag_block_definitions, &block_definition);
	delete& block_definition;

	for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	{
		if (tag_field_definition->block_definition == &block_definition)
		{
			tag_field_definition->block_definition = nullptr;
		}
	}

	for (c_runtime_tag_group_definition* tag_group_definition : tag_group_definitions)
	{
		if (tag_group_definition->block_definition == &block_definition)
		{
			tag_group_definition->block_definition = nullptr;
		}
	}
}

void c_runtime_tag_definitions::delete_tag_struct_definition(c_runtime_tag_struct_definition& struct_definition)
{
	erase_by_value(tag_struct_definitions, &struct_definition);
	delete& struct_definition;


	for (c_runtime_tag_array_definition* tag_array_definition : tag_array_definitions)
	{
		if (tag_array_definition->struct_definition == &struct_definition)
		{
			tag_array_definition->struct_definition = nullptr;
		}
	}

	for (c_runtime_tag_block_definition* tag_block_definition : tag_block_definitions)
	{
		if (tag_block_definition->struct_definition == &struct_definition)
		{
			tag_block_definition->struct_definition = nullptr;
		}
	}

	for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	{
		if (tag_field_definition->struct_definition == &struct_definition)
		{
			tag_field_definition->struct_definition = nullptr;
		}
	}
}

void c_runtime_tag_definitions::delete_tag_array_definition(c_runtime_tag_array_definition& array_definition)
{
	erase_by_value(tag_array_definitions, &array_definition);
	delete& array_definition;

	for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	{
		if (tag_field_definition->array_definition == &array_definition)
		{
			tag_field_definition->array_definition = nullptr;
		}
	}
}

void c_runtime_tag_definitions::delete_string_list_definition(c_runtime_string_list_definition& string_list_definition)
{
	erase_by_value(tag_string_list_definitions, &string_list_definition);
	delete& string_list_definition;

	for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	{
		if (tag_field_definition->string_list_definition == &string_list_definition)
		{
			tag_field_definition->string_list_definition = nullptr;
		}
	}
}

void c_runtime_tag_definitions::delete_tag_reference_definition(c_runtime_tag_reference_definition& reference_definition)
{
	erase_by_value(tag_reference_definitions, &reference_definition);
	delete& reference_definition;

	for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	{
		if (tag_field_definition->tag_reference_definition == &reference_definition)
		{
			tag_field_definition->tag_reference_definition = nullptr;
		}
	}
}

void c_runtime_tag_definitions::delete_tag_resource_definition(c_runtime_tag_resource_definition& resource_definition)
{
	erase_by_value(tag_resource_definitions, &resource_definition);
	delete& resource_definition;

	for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	{
		if (tag_field_definition->tag_resource_definition == &resource_definition)
		{
			tag_field_definition->tag_resource_definition = nullptr;
		}
	}
}

void c_runtime_tag_definitions::delete_tag_api_interop_definition(c_runtime_tag_api_interop_definition& api_interop_definition)
{
	erase_by_value(tag_api_interop_definitions, &api_interop_definition);
	delete& api_interop_definition;

	for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	{
		if (tag_field_definition->tag_interop_definition == &api_interop_definition)
		{
			tag_field_definition->tag_interop_definition = nullptr;
		}
	}
}

void c_runtime_tag_definitions::delete_tag_data_definition(c_runtime_tag_data_definition& data_definition)
{
	erase_by_value(tag_data_definitions, &data_definition);
	delete& data_definition;

	for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	{
		if (tag_field_definition->tag_data_definition == &data_definition)
		{
			tag_field_definition->tag_data_definition = nullptr;
		}
	}
}

void c_runtime_tag_definitions::delete_block_index_custom_search_definition(c_runtime_tag_block_index_custom_search_definition& block_index_custom_search_definition)
{
	erase_by_value(tag_block_index_custom_search_definitions, &block_index_custom_search_definition);
	delete& block_index_custom_search_definition;

	for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	{
		if (tag_field_definition->block_index_custom_search_definition == &block_index_custom_search_definition)
		{
			tag_field_definition->block_index_custom_search_definition = nullptr;
		}
	}
}

void c_runtime_tag_definitions::delete_tag_field_definition(c_runtime_tag_field_definition& field_definition)
{
	erase_by_value(tag_field_definitions, &field_definition);
	delete& field_definition;

	//for (c_runtime_tag_field_definition* tag_field_definition : tag_field_definitions)
	//{
	//	if (tag_field_definition->field_definition == &field_definition)
	//	{
	//		tag_field_definition->field_definition = nullptr;
	//	}
	//}
}


c_runtime_tag_group_definition& c_runtime_tag_definitions::enqueue_tag_group_definition(const blofeld::s_tag_group& _tag_group_definition)
{
	for (c_runtime_tag_group_definition* group_definition : tag_group_definitions)
	{
		if (group_definition->original_tag_group_definition == &_tag_group_definition)
		{
			return *group_definition;
		}
	}
	for (c_runtime_tag_group_definition* group_definition : tag_group_definitions)
	{
		if (const blofeld::s_tag_group* original_tag_group_definition = group_definition->original_tag_group_definition)
		{
			if (strcmp(original_tag_group_definition->symbol_name, _tag_group_definition.symbol_name) == 0)
			{
				return *group_definition;
			}
		}
	}

	c_runtime_tag_group_definition* group_definition = new() c_runtime_tag_group_definition(*this, _tag_group_definition);
	tag_group_definitions.push_back(group_definition);
	sort_tag_group_definitions();
	return *group_definition;
}

c_runtime_tag_block_definition& c_runtime_tag_definitions::enqueue_tag_block_definition(const blofeld::s_tag_block_definition& _tag_block_definition)
{
	for (c_runtime_tag_block_definition* block_definition : tag_block_definitions)
	{
		if (block_definition->original_tag_block_definition == &_tag_block_definition)
		{
			return *block_definition;
		}
	}
	for (c_runtime_tag_block_definition* block_definition : tag_block_definitions)
	{
		if (const blofeld::s_tag_block_definition* original_tag_block_definition = block_definition->original_tag_block_definition)
		{
			if (strcmp(original_tag_block_definition->symbol_name, _tag_block_definition.symbol_name) == 0)
			{
				return *block_definition;
			}
		}
	}

	c_runtime_tag_block_definition* block_definition = trivial_malloc(c_runtime_tag_block_definition, 1);
	tag_block_definitions.push_back(block_definition);
	block_definition = new(block_definition) c_runtime_tag_block_definition(*this, _tag_block_definition);

	sort_tag_block_definitions();
	return *block_definition;
}

c_runtime_tag_struct_definition& c_runtime_tag_definitions::enqueue_tag_struct_definition(const blofeld::s_tag_struct_definition& _tag_struct_definition)
{
	for (c_runtime_tag_struct_definition* struct_definition : tag_struct_definitions)
	{
		if (struct_definition->original_tag_struct_definition == &_tag_struct_definition)
		{
			return *struct_definition;
		}
	}
	for (c_runtime_tag_struct_definition* struct_definition : tag_struct_definitions)
	{
		if (const blofeld::s_tag_struct_definition* original_tag_struct_definition = struct_definition->original_tag_struct_definition)
		{
			if (strcmp(original_tag_struct_definition->symbol_name, _tag_struct_definition.symbol_name) == 0)
			{
				return *struct_definition;
			}
		}
	}

	c_runtime_tag_struct_definition* struct_definition = trivial_malloc(c_runtime_tag_struct_definition, 1);
	tag_struct_definitions.push_back(struct_definition);
	struct_definition = new(struct_definition) c_runtime_tag_struct_definition(*this, _tag_struct_definition);
	sort_tag_struct_definitions();
	return *struct_definition;
}

c_runtime_tag_array_definition& c_runtime_tag_definitions::enqueue_tag_array_definition(const blofeld::s_tag_array_definition& _tag_array_definition)
{
	for (c_runtime_tag_array_definition* array_definition : tag_array_definitions)
	{
		if (array_definition->original_tag_array_definition == &_tag_array_definition)
		{
			return *array_definition;
		}
	}
	for (c_runtime_tag_array_definition* array_definition : tag_array_definitions)
	{
		if (const blofeld::s_tag_array_definition* original_tag_array_definition = array_definition->original_tag_array_definition)
		{
			if (strcmp(original_tag_array_definition->symbol_name, _tag_array_definition.symbol_name) == 0)
			{
				return *array_definition;
			}
		}
	}

	c_runtime_tag_array_definition* array_definition = new() c_runtime_tag_array_definition(*this, _tag_array_definition);
	tag_array_definitions.push_back(array_definition);
	sort_tag_array_definitions();
	return *array_definition;
}

c_runtime_string_list_definition& c_runtime_tag_definitions::enqueue_string_list_definition(const blofeld::s_string_list_definition& _string_list_definition)
{
	for (c_runtime_string_list_definition* string_list_definition : tag_string_list_definitions)
	{
		if (string_list_definition->original_string_list_definition == &_string_list_definition)
		{
			return *string_list_definition;
		}
	}
	for (c_runtime_string_list_definition* string_list_definition : tag_string_list_definitions)
	{
		if (const blofeld::s_string_list_definition* original_string_list_definition = string_list_definition->original_string_list_definition)
		{
			if (strcmp(original_string_list_definition->symbol_name, _string_list_definition.symbol_name) == 0)
			{
				return *string_list_definition;
			}
		}
	}

	c_runtime_string_list_definition* string_list_definition = new() c_runtime_string_list_definition(*this, _string_list_definition);
	tag_string_list_definitions.push_back(string_list_definition);
	sort_string_list_definitions();
	return *string_list_definition;
}

c_runtime_tag_reference_definition& c_runtime_tag_definitions::enqueue_tag_reference_definition(const blofeld::s_tag_reference_definition& _tag_reference_definition)
{
	for (c_runtime_tag_reference_definition* reference_definition : tag_reference_definitions)
	{
		if (reference_definition->original_reference_definition == &_tag_reference_definition)
		{
			return *reference_definition;
		}
	}
	for (c_runtime_tag_reference_definition* reference_definition : tag_reference_definitions)
	{
		if (const blofeld::s_tag_reference_definition* original_reference_definition = reference_definition->original_reference_definition)
		{
			if (strcmp(original_reference_definition->symbol_name, _tag_reference_definition.symbol_name) == 0)
			{
				return *reference_definition;
			}
		}
	}

	c_runtime_tag_reference_definition* reference_definition = new() c_runtime_tag_reference_definition(*this, _tag_reference_definition);
	tag_reference_definitions.push_back(reference_definition);
	sort_tag_reference_definitions();
	return *reference_definition;
}

c_runtime_tag_resource_definition& c_runtime_tag_definitions::enqueue_tag_resource_definition(const blofeld::s_tag_resource_definition& _tag_resource_definition)
{
	for (c_runtime_tag_resource_definition* resource_definition : tag_resource_definitions)
	{
		if (resource_definition->original_tag_resource_definition == &_tag_resource_definition)
		{
			return *resource_definition;
		}
	}
	for (c_runtime_tag_resource_definition* resource_definition : tag_resource_definitions)
	{
		if (const blofeld::s_tag_resource_definition* original_tag_resource_definition = resource_definition->original_tag_resource_definition)
		{
			if (strcmp(original_tag_resource_definition->symbol_name, _tag_resource_definition.symbol_name) == 0)
			{
				return *resource_definition;
			}
		}
	}

	c_runtime_tag_resource_definition* resource_definition = new() c_runtime_tag_resource_definition(*this, _tag_resource_definition);
	tag_resource_definitions.push_back(resource_definition);
	sort_tag_resource_definitions();
	return *resource_definition;
}

c_runtime_tag_api_interop_definition& c_runtime_tag_definitions::enqueue_tag_api_interop_definition(const blofeld::s_tag_interop_definition& _tag_api_interop_definition)
{
	for (c_runtime_tag_api_interop_definition* api_interop_definition : tag_api_interop_definitions)
	{
		if (api_interop_definition->original_tag_interop_definition == &_tag_api_interop_definition)
		{
			return *api_interop_definition;
		}
	}
	for (c_runtime_tag_api_interop_definition* api_interop_definition : tag_api_interop_definitions)
	{
		if (const blofeld::s_tag_interop_definition* original_tag_interop_definition = api_interop_definition->original_tag_interop_definition)
		{
			if (strcmp(original_tag_interop_definition->symbol_name, _tag_api_interop_definition.symbol_name) == 0)
			{
				return *api_interop_definition;
			}
		}
	}

	c_runtime_tag_api_interop_definition* api_interop_definition = new() c_runtime_tag_api_interop_definition(*this, _tag_api_interop_definition);
	tag_api_interop_definitions.push_back(api_interop_definition);
	sort_tag_api_interop_definitions();
	return *api_interop_definition;
}

c_runtime_tag_data_definition& c_runtime_tag_definitions::enqueue_tag_data_definition(const blofeld::s_tag_data_definition& _tag_data_definition)
{
	for (c_runtime_tag_data_definition* data_definition : tag_data_definitions)
	{
		if (data_definition->original_tag_data_definition == &_tag_data_definition)
		{
			return *data_definition;
		}
	}
	for (c_runtime_tag_data_definition* data_definition : tag_data_definitions)
	{
		if (const blofeld::s_tag_data_definition* original_tag_data_definition = data_definition->original_tag_data_definition)
		{
			if (strcmp(original_tag_data_definition->symbol_name, _tag_data_definition.symbol_name) == 0)
			{
				return *data_definition;
			}
		}
	}

	c_runtime_tag_data_definition* data_definition = new() c_runtime_tag_data_definition(*this, _tag_data_definition);
	tag_data_definitions.push_back(data_definition);
	sort_tag_data_definitions();
	return *data_definition;
}

c_runtime_tag_block_index_custom_search_definition& c_runtime_tag_definitions::enqueue_block_index_custom_search_definition(const blofeld::s_block_index_custom_search_definition& _block_index_custom_search_definition)
{
	for (c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition : tag_block_index_custom_search_definitions)
	{
		if (block_index_custom_search_definition->original_block_index_custom_search_definition == &_block_index_custom_search_definition)
		{
			return *block_index_custom_search_definition;
		}
	}
	for (c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition : tag_block_index_custom_search_definitions)
	{
		if (const blofeld::s_block_index_custom_search_definition* original_block_index_custom_search_definition = block_index_custom_search_definition->original_block_index_custom_search_definition)
		{
			if (strcmp(original_block_index_custom_search_definition->symbol_name, _block_index_custom_search_definition.symbol_name) == 0)
			{
				return *block_index_custom_search_definition;
			}
		}
	}

	c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition = new() c_runtime_tag_block_index_custom_search_definition(*this, _block_index_custom_search_definition);
	tag_block_index_custom_search_definitions.push_back(block_index_custom_search_definition);
	sort_block_index_custom_search_definitions();
	return *block_index_custom_search_definition;
}

c_runtime_tag_field_definition& c_runtime_tag_definitions::enqueue_tag_field_definition(const blofeld::s_tag_field& _tag_field_definition)
{
	for (c_runtime_tag_field_definition* field_definition : tag_field_definitions)
	{
		if (field_definition->original_field == &_tag_field_definition)
		{
			return *field_definition;
		}
	}

	c_runtime_tag_field_definition* field_definition = new() c_runtime_tag_field_definition(*this, _tag_field_definition);
	tag_field_definitions.push_back(field_definition);
	// sort_tag_field_definitions();
	return *field_definition;
}
