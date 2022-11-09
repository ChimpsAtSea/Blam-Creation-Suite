#include "definitiontweaker-private-pch.h"

#define _parent_serialization_context static_cast<c_tag_field_serialization_context*>(parent_serialization_context)

c_tag_api_interop_serialization_context::c_tag_api_interop_serialization_context(
	c_tag_field_serialization_context& _serialization_context,
	c_tag_serialization_context& _tag_serialization_context,
	void const* _interop_data,
	c_runtime_tag_api_interop_definition& _api_interop_definition) :
	c_serialization_context(
		_serialization_context,
		nullptr,
		crazy_no_string_copy_hacktastic_function(
			_api_interop_definition.name,
			_api_interop_definition.original_tag_interop_definition,
			_api_interop_definition.original_tag_interop_definition->name,
			owns_name_memory),
		owns_name_memory),
	tag_serialization_context(_tag_serialization_context),
	interop_data(_interop_data),
	struct_size(),
	runtime_tag_api_interop_definition(_api_interop_definition),
	cache_file_resource_location_struct_definition(),
	cache_file_resource_data_struct_definition(),
	cache_file_resource_location_struct_serialization_context(),
	cache_file_resource_data_struct_serialization_context(),
	cache_file_resource_location_struct_size(),
	cache_file_resource_data_struct_size()
{

}

c_tag_api_interop_serialization_context::~c_tag_api_interop_serialization_context()
{
	delete cache_file_resource_location_struct_serialization_context;
	delete cache_file_resource_data_struct_serialization_context;
}

#define CACHE_FILE_RESOURCE_LOCATION_STRUCT_ID { 0xA82CDAB9, 0xAF1B4171, 0x816BA199, 0xDD8E6C9C }
#define CACHE_FILE_RESOURCE_DATA_BLOCK_ID { 0x7EF6B5D, 0x210B4AD1, 0x9DEC2F43, 0xE9DCB6A4 }

BCS_RESULT c_tag_api_interop_serialization_context::read()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping read due to issues");
		return BCS_E_FAIL;
	}

	c_tag_serialization_context& tag_serialization_context = *find_parent_by_type<c_tag_serialization_context>();
	REFERENCE_ASSERT(tag_serialization_context);

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

		const char* interop_data_position = static_cast<const char*>(interop_data);
		interop_data_position += cache_file_resource_location_struct_size;
		interop_data_position += cache_file_resource_data_struct_size;
		data_end = interop_data_position;

		if (data_start > tag_serialization_context.data_start)
		{
			unsigned int bytes = static_cast<unsigned int>(static_cast<const char*>(data_start) - tag_serialization_context.data_start);
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_block_validation_error,
				"block address start is out of bounds bytes:%u", bytes);
		}

		if (data_end > tag_serialization_context.data_end)
		{
			unsigned int bytes = static_cast<unsigned int>(static_cast<const char*>(data_end) - tag_serialization_context.data_end);
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_block_validation_error,
				"block address end is out of bounds bytes:%u", bytes);
		}
	}

	return BCS_S_OK;
}

BCS_RESULT c_tag_api_interop_serialization_context::traverse()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping traverse due to issues");
		return BCS_E_FAIL;
	}

	const char* interop_data_position = static_cast<const char*>(interop_data);

	cache_file_resource_location_struct_serialization_context = new() c_tag_struct_serialization_context(
		*this,
		tag_serialization_context,
		interop_data_position,
		*cache_file_resource_location_struct_definition);

	cache_file_resource_location_struct_serialization_context->read();
	cache_file_resource_location_struct_serialization_context->traverse();

	interop_data_position += cache_file_resource_location_struct_size;

	cache_file_resource_data_struct_serialization_context = new() c_tag_struct_serialization_context(
		*this,
		tag_serialization_context,
		interop_data_position,
		*cache_file_resource_data_struct_definition);

	cache_file_resource_data_struct_serialization_context->read();
	cache_file_resource_data_struct_serialization_context->traverse();

	interop_data_position += cache_file_resource_data_struct_size;

	return BCS_S_OK;
}

BCS_RESULT c_tag_api_interop_serialization_context::calculate_memory()
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

	if (cache_file_resource_location_struct_serialization_context)
	{
		// tag_serialization_context.memory_intervals.push_back(cache_file_resource_location_struct_serialization_context);
		cache_file_resource_location_struct_serialization_context->calculate_memory();
	}

	if (cache_file_resource_data_struct_serialization_context)
	{
		// tag_serialization_context.memory_intervals.push_back(cache_file_resource_data_struct_serialization_context);
		cache_file_resource_data_struct_serialization_context->calculate_memory();
	}

	return BCS_S_OK;
}

void c_tag_api_interop_serialization_context::render_tree()
{
#define api_interop_definition banned
	const char* api_interop_name = name;

	ImGui::PushID(api_interop_name);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (cache_file_resource_location_struct_serialization_context || cache_file_resource_data_struct_serialization_context)
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	bool tree_node_result = ImGui::TreeNodeEx("##api_interop", flags, "%s", api_interop_name);
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	tag_serialization_context.definition_tweaker.render_definition_context_menu(_definition_type_interop_definition, &runtime_tag_api_interop_definition);
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
#undef api_interop_definition
}
