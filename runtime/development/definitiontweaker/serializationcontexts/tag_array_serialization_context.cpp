#include "definitiontweaker-private-pch.h"

c_tag_array_serialization_context::c_tag_array_serialization_context(
	c_serialization_context& _serialization_context,
	c_tag_serialization_context& _tag_serialization_context,
	const void* _array_data,
	c_runtime_tag_array_definition& _array_definition) :
	c_serialization_context(
		_serialization_context, 
		_array_data,
		crazy_string_no_copy_hacktastic_function(
			_array_definition.name,
			_array_definition.original_tag_array_definition,
			_array_definition.original_tag_array_definition->name,
			owns_name_memory),
		owns_name_memory),
	tag_serialization_context(_tag_serialization_context),
	struct_size(),
	array_size(),
	struct_serialization_contexts(),
	runtime_tag_array_definition(_array_definition)
{

}

c_tag_array_serialization_context::~c_tag_array_serialization_context()
{
	for (c_tag_struct_serialization_context* struct_serialization_context : struct_serialization_contexts)
	{
		delete struct_serialization_context;
	}
}

BCS_RESULT c_tag_array_serialization_context::read()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping read due to issues");
		return BCS_E_FAIL;
	}

	struct_size = c_tag_struct_serialization_context::calculate_struct_size(*this, *runtime_tag_array_definition.struct_definition);
	array_size = runtime_tag_array_definition.element_count;

	data_end = static_cast<const char*>(data_start) + array_size;

	// check read bounds of structure
	{
		const char* read_position = static_cast<const char*>(data_start);

		if (read_position < tag_serialization_context.data_start)
		{
			intptr_t bytes = static_cast<const char*>(tag_serialization_context.data_end) - read_position;
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_error,
				"array data read before tag data start (bytes:%zu)", bytes);
		}

		read_position += struct_size * array_size;

		if (read_position > tag_serialization_context.data_end)
		{
			intptr_t bytes = read_position - static_cast<const char*>(tag_serialization_context.data_end);
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_error,
				"array data read after tag data start (bytes:%zu)", bytes);
		}
	}

	return BCS_S_OK;
}

BCS_RESULT c_tag_array_serialization_context::traverse()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping traverse due to issues");
		return BCS_E_FAIL;
	}

	const char* array_position = static_cast<const char*>(data_start);

	for (unsigned int array_index = 0; array_index < array_size; array_index++)
	{
		c_tag_struct_serialization_context* tag_struct_serialization_context = new() c_tag_struct_serialization_context(
			*this,
			tag_serialization_context,
			array_position,
			*runtime_tag_array_definition.struct_definition);
		struct_serialization_contexts.push_back(tag_struct_serialization_context);

		array_position += struct_size;
	}

	for (c_tag_struct_serialization_context* struct_serialization_context : struct_serialization_contexts)
	{
		struct_serialization_context->read();
	}

	for (c_tag_struct_serialization_context* struct_serialization_context : struct_serialization_contexts)
	{
		struct_serialization_context->traverse();
	}

	debug_point;

	return BCS_S_OK;
}

BCS_RESULT c_tag_array_serialization_context::calculate_memory()
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

	for (c_tag_struct_serialization_context* struct_serialization_context : struct_serialization_contexts)
	{
		struct_serialization_context->calculate_memory();
	}

	return BCS_S_OK;
}

void c_tag_array_serialization_context::render_tree()
{
#define array_definition banned
	const char* array_name = name;

	ImGui::PushID(array_name);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (struct_serialization_contexts.empty())
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	bool tree_node_result = ImGui::TreeNodeEx("##array", flags, "%s", array_name);
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	tag_serialization_context.definition_tweaker.render_definition_context_menu(_definition_type_array_definition, &runtime_tag_array_definition);
	if (tree_node_result)
	{
		int index = 0;
		for (c_tag_struct_serialization_context* struct_serialization_context : struct_serialization_contexts)
		{
			ImGui::PushID(index++);
			struct_serialization_context->render_tree();
			ImGui::PopID();
		}

		ImGui::TreePop();
	}

	ImGui::PopStyleColor();
	ImGui::PopID();
#undef array_definition
}
