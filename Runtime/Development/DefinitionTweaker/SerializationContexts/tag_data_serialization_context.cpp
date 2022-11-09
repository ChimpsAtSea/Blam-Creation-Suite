#include "definitiontweaker-private-pch.h"

c_tag_data_serialization_context::c_tag_data_serialization_context(
	c_serialization_context& _serialization_context,
	c_tag_serialization_context& _tag_serialization_context,
	::s_tag_data const& _tag_data,
	c_runtime_tag_data_definition& _data_definition) :
	c_serialization_context(_serialization_context, nullptr, _data_definition.name),
	tag_serialization_context(_tag_serialization_context),
	tag_data(_tag_data),
	struct_serialization_contexts(),
	runtime_tag_data_definition(_data_definition),
	name(runtime_tag_data_definition.name),
	traverse_count()
{

}

c_tag_data_serialization_context::~c_tag_data_serialization_context()
{
	for (c_tag_struct_serialization_context* struct_serialization_context : struct_serialization_contexts)
	{
		delete struct_serialization_context;
	}
}

BCS_RESULT c_tag_data_serialization_context::read()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping read due to issues");
		return BCS_E_FAIL;
	}

	if (tag_data.size < 0)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_data_validation_error,
			"invalid data size 0x%08X", tag_data.size);
	}
	else if (tag_data.size == 0)
	{
		if (tag_data.address != 0)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"size is zero but address is non zero 0x%08X", tag_data.size);
		}
	}
	else if (tag_data.size > 0)
	{
		unsigned int address_segment = tag_data.address >> 28;
		//unsigned int address_offset = tag_block.address * 4;
		unsigned int address_offset = tag_data.address & 0x0FFFFFFF;
		unsigned int address_end = address_offset + tag_data.size;

		if (address_segment != 4)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_block_validation_error,
				"data address segment is %u expected 4", address_segment);
		}

		if (address_offset > tag_serialization_context.tag_header->total_size)
		{
			unsigned int bytes = tag_serialization_context.tag_header->total_size - address_offset;
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_block_validation_error,
				"data address start is out of bounds bytes:%u", bytes);
		}

		if (address_end > tag_serialization_context.tag_header->total_size)
		{
			unsigned int bytes = tag_serialization_context.tag_header->total_size - address_offset;
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_block_validation_error,
				"data address end is out of bounds bytes:%u", bytes);
		}
	}

	if (tag_data.stream_flags != 0)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_data_validation_error,
			"stream_flags is non zero 0x%08X", tag_data.stream_flags);
	}

	if (tag_data.stream_offset != 0)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_data_validation_error,
			"stream_offset is non zero 0x%08X", tag_data.stream_offset);
	}

	if (tag_data.definition != 0)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_data_validation_error,
			"definition is non zero 0x%08X", tag_data.definition);
	}

	if (tag_data.size > runtime_tag_data_definition.maximum_element_count)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_data_validation_error,
			"data size is larger than expected size:0x%08X expected:0x%08X",
			tag_data.size,
			runtime_tag_data_definition.maximum_element_count);
	}

	unsigned int address_offset = tag_data.address & 0x0FFFFFFF;
	const char* data_position = static_cast<const char*>(tag_serialization_context.data_start) + address_offset;

	data_start = data_position;
	data_end = data_position + tag_data.size;

	return BCS_S_OK;
}

BCS_RESULT c_tag_data_serialization_context::traverse()
{
	unsigned int has_traversed = atomic_incu32(&traverse_count) > 1;
	ASSERT(!has_traversed);

	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping traverse due to issues");
		return BCS_E_FAIL;
	}

	// nothing to do here

	return BCS_S_OK;
}

BCS_RESULT c_tag_data_serialization_context::calculate_memory()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping traverse due to issues");
		return BCS_E_FAIL;
	}

	tag_serialization_context.memory_intervals.push_back(this);

	for (c_tag_struct_serialization_context* struct_serialization_context : struct_serialization_contexts)
	{
		struct_serialization_context->calculate_memory();
	}

	return BCS_S_OK;
}

void c_tag_data_serialization_context::render_tree()
{
#define data_definition banned
	const char* data_name = name.c_str();

	ImGui::PushID(data_name);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (struct_serialization_contexts.empty())
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	bool tree_node_result = ImGui::TreeNodeEx("##data", flags, "%s", data_name);
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	tag_serialization_context.definition_tweaker.render_definition_context_menu(_definition_type_data_definition, &runtime_tag_data_definition);
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
#undef data_definition
}
