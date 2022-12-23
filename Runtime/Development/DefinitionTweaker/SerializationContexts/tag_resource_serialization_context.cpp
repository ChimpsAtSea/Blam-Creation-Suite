#include "definitiontweaker-private-pch.h"

c_tag_resource_serialization_context::c_tag_resource_serialization_context(
	c_serialization_context& _serialization_context,
	c_tag_serialization_context& _tag_serialization_context,
	::s_tag_resource const& _tag_resource,
	c_runtime_tag_resource_definition& _resource_definition) :
	c_serialization_context(
		_serialization_context,
		nullptr,
		crazy_no_string_copy_hacktastic_function(
			_resource_definition.name,
			_resource_definition.original_tag_resource_definition,
			_resource_definition.original_tag_resource_definition->name,
			owns_name_memory),
		owns_name_memory),
	tag_serialization_context(_tag_serialization_context),
	tag_resource(_tag_resource),
	struct_size(),
	runtime_tag_resource_definition(_resource_definition),
	cache_file_resource_location_struct_definition(),
	cache_file_resource_data_struct_definition(),
	cache_file_resource_location_struct_serialization_context(),
	cache_file_resource_data_struct_serialization_context(),
	cache_file_resource_location_struct_size(),
	cache_file_resource_data_struct_size()
{

}

c_tag_resource_serialization_context::~c_tag_resource_serialization_context()
{
	delete cache_file_resource_location_struct_serialization_context;
	delete cache_file_resource_data_struct_serialization_context;
}

#define CACHE_FILE_RESOURCE_LOCATION_STRUCT_ID { 0xA82CDAB9, 0xAF1B4171, 0x816BA199, 0xDD8E6C9C }
#define CACHE_FILE_RESOURCE_DATA_BLOCK_ID { 0x7EF6B5D, 0x210B4AD1, 0x9DEC2F43, 0xE9DCB6A4 }

BCS_RESULT c_tag_resource_serialization_context::read()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping read due to issues");
		return BCS_E_FAIL;
	}

	if (tag_resource.definition_address != 0)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_data_validation_error,
			"pageable resource definition address is non zero %08X", tag_resource.definition_address);
	}



	//if (!tag_resource.resource_handle.valid())
	//{
	//	unsigned short identifier = tag_resource.resource_handle.get_identifier();
	//	unsigned short absolute_index = tag_resource.resource_handle.get_absolute_index();
	//	int value = tag_resource.resource_handle.get_value();
	//	enqueue_serialization_error<c_generic_serialization_error>(
	//		_serialization_error_type_data_validation_error,
	//		"pageable resource handle is invalid identifier:%08X absolute_index:%08X value:%08X", identifier, absolute_index, value);
	//}

	struct_size = c_tag_struct_serialization_context::calculate_struct_size(*this, *runtime_tag_resource_definition.struct_definition);

	unsigned int address = tag_resource.resource_handle.get_value();
	unsigned int address_segment = address >> 28;
	//unsigned int address_offset = tag_block.address * 4;
	unsigned int address_offset = address & 0x0FFFFFFF;
	unsigned int address_end = address_offset + struct_size;

	if (address_segment != 4)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_block_validation_error,
			"block address segment is %u expected 4", address_segment);
	}

	if (address_offset > tag_serialization_context.tag_header->total_size)
	{
		unsigned int bytes = tag_serialization_context.tag_header->total_size - address_offset;
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_block_validation_error,
			"block address start is out of bounds bytes:%u", bytes);
	}

	if (address_end > tag_serialization_context.tag_header->total_size)
	{
		unsigned int bytes = tag_serialization_context.tag_header->total_size - address_offset;
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_block_validation_error,
			"block address end is out of bounds bytes:%u", bytes);
	}

	c_blamtoozle_tag_struct_definition* blamtoozle_cache_file_resource_location_struct_definition = tag_serialization_context.definition_tweaker.runtime_tag_definitions->get_tag_struct_definition_by_persistent_id(CACHE_FILE_RESOURCE_LOCATION_STRUCT_ID);
	c_blamtoozle_tag_struct_definition* blamtoozle_cache_file_resource_data_struct_definition = tag_serialization_context.definition_tweaker.runtime_tag_definitions->get_tag_struct_definition_by_persistent_id(CACHE_FILE_RESOURCE_DATA_BLOCK_ID);
	cache_file_resource_location_struct_definition = dynamic_cast<c_runtime_tag_struct_definition*>(blamtoozle_cache_file_resource_location_struct_definition);
	cache_file_resource_data_struct_definition = dynamic_cast<c_runtime_tag_struct_definition*>(blamtoozle_cache_file_resource_data_struct_definition);

	if (blamtoozle_cache_file_resource_location_struct_definition == nullptr)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_fatal,
			"failed to find cache_file_resource_location_struct_definition");
	}
	else if (cache_file_resource_location_struct_definition == nullptr)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_fatal,
			"cache_file_resource_location_struct_definition is not a c_runtime_tag_struct_definition");
	}

	if (blamtoozle_cache_file_resource_data_struct_definition == nullptr)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_fatal,
			"failed to find cache_file_resource_data_struct_definition");
	}
	else if (cache_file_resource_data_struct_definition == nullptr)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_fatal,
			"cache_file_resource_data_struct_definition is not a c_runtime_tag_struct_definition");
	}

	if (cache_file_resource_location_struct_definition && cache_file_resource_data_struct_definition)
	{
		cache_file_resource_location_struct_size = c_tag_struct_serialization_context::calculate_struct_size(*this, *cache_file_resource_location_struct_definition);
		cache_file_resource_data_struct_size = c_tag_struct_serialization_context::calculate_struct_size(*this, *cache_file_resource_data_struct_definition);
	}

	return BCS_S_OK;
}

BCS_RESULT c_tag_resource_serialization_context::traverse()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping traverse due to issues");
		return BCS_E_FAIL;
	}

	unsigned int address = tag_resource.resource_handle.get_value();
	unsigned int address_offset = address & 0x0FFFFFFF;
	const char* resource_position = static_cast<const char*>(tag_serialization_context.data_start) + address_offset;

	data_start = resource_position;

	cache_file_resource_location_struct_serialization_context = new() c_tag_struct_serialization_context(
		*this,
		tag_serialization_context,
		resource_position,
		*cache_file_resource_location_struct_definition);

	cache_file_resource_location_struct_serialization_context->read();
	cache_file_resource_location_struct_serialization_context->traverse();

	resource_position += cache_file_resource_location_struct_size;

	cache_file_resource_data_struct_serialization_context = new() c_tag_struct_serialization_context(
		*this,
		tag_serialization_context,
		resource_position,
		*cache_file_resource_data_struct_definition);

	cache_file_resource_data_struct_serialization_context->read();
	cache_file_resource_data_struct_serialization_context->traverse();

	resource_position += cache_file_resource_data_struct_size;

	data_end = resource_position;

	debug_point;

	return BCS_S_OK;
}

BCS_RESULT c_tag_resource_serialization_context::calculate_memory()
{
	if (!c_definition_tweaker::get_serialization_force_calculate_memory_setting())
	{
		if (max_serialization_error_type >= _serialization_error_type_fatal)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_warning,
				"skipping calculate_memory due to issues");
			return BCS_E_FAIL;
		}
	}

	tag_serialization_context.memory_intervals.push_back(this);

	if (cache_file_resource_location_struct_serialization_context)
	{
		//tag_serialization_context.memory_intervals.push_back(cache_file_resource_location_struct_serialization_context);
		cache_file_resource_location_struct_serialization_context->calculate_memory();
	}

	if (cache_file_resource_data_struct_serialization_context)
	{
		//tag_serialization_context.memory_intervals.push_back(cache_file_resource_data_struct_serialization_context);
		cache_file_resource_data_struct_serialization_context->calculate_memory();
	}

	return BCS_S_OK;
}

void c_tag_resource_serialization_context::render_tree()
{
#define resource_definition banned
	const char* resource_name = name;

	ImGui::PushID(resource_name);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (cache_file_resource_location_struct_serialization_context || cache_file_resource_data_struct_serialization_context)
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	bool tree_node_result = ImGui::TreeNodeEx("##resource", flags, "%s", resource_name);
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	tag_serialization_context.definition_tweaker.render_definition_context_menu(_definition_type_resource_definition, &runtime_tag_resource_definition);
	if (tree_node_result)
	{
		if (cache_file_resource_location_struct_serialization_context)
		{
			cache_file_resource_location_struct_serialization_context->render_tree();
		}
		if (cache_file_resource_data_struct_serialization_context)
		{
			cache_file_resource_data_struct_serialization_context->render_tree();
		}

		ImGui::TreePop();
	}

	ImGui::PopStyleColor();
	ImGui::PopID();
#undef resource_definition
}
