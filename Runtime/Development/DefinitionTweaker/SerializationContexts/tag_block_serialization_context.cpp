#include "definitiontweaker-private-pch.h"

c_tag_block_serialization_context::c_tag_block_serialization_context(
	c_serialization_context& _serialization_context,
	c_tag_serialization_context& _tag_serialization_context,
	const void* _block_data,
	c_runtime_tag_block_definition& _block_definition) :
	c_serialization_context(_serialization_context),
	tag_serialization_context(_tag_serialization_context),
	block_data(_block_data),
	struct_serialization_contexts(),
	runtime_tag_block_definition(_block_definition),
	name(runtime_tag_block_definition.name),
	traverse_count()
{

}

c_tag_block_serialization_context::~c_tag_block_serialization_context()
{
	for (c_tag_struct_serialization_context* struct_serialization_context : struct_serialization_contexts)
	{
		delete struct_serialization_context;
	}
}

BCS_RESULT c_tag_block_serialization_context::read()
{
	if (max_serialization_error_type >= _serialization_error_type_error)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping read due to issues");
		return BCS_E_FAIL;
	}

	::s_tag_block const& tag_block = *reinterpret_cast<decltype(&tag_block)>(block_data);

	struct_size = c_tag_struct_serialization_context::calculate_struct_size(*this, *runtime_tag_block_definition.struct_definition);

	unsigned int address_segment = tag_block.address >> 28;
	//unsigned int address_offset = tag_block.address * 4;
	unsigned int address_offset = tag_block.address & 0x0FFFFFFF;
	unsigned int data_size = struct_size * tag_block.count;
	unsigned int address_end = address_offset + data_size;

	if (tag_block.count > runtime_tag_block_definition.max_count)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_block_validation_error,
			"block count %08X exceeds maximum %08X", tag_block.count, runtime_tag_block_definition.max_count);
	}

	if (tag_block.count > 0 && struct_size == 0)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_block_validation_error,
			"block has data but struct size is zero");
	}

	if (tag_block.definition_address != 0)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_block_validation_error,
			"block definition_address is non zero");
	}

	if (tag_block.count == 0)
	{
		if (tag_block.address != 0)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_block_validation_error,
				"block count is %u but address is %08X", tag_block.count, tag_block.address);
		}
	}
	else // tag_block.count != 0
	{
		if (tag_block.address == 0)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_block_validation_error,
				"block count is %u but address is zero", tag_block.count);
		}

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

		debug_point;
	}
	return BCS_S_OK;
}

BCS_RESULT c_tag_block_serialization_context::traverse()
{
	unsigned int has_traversed = atomic_incu32(&traverse_count) > 1;
	ASSERT(!has_traversed);

	if (max_serialization_error_type >= _serialization_error_type_error)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping traverse due to issues");
		return BCS_E_FAIL;
	}

	::s_tag_block const& tag_block = *reinterpret_cast<decltype(&tag_block)>(block_data);
	unsigned int address_offset = tag_block.address & 0x0FFFFFFF;
	const char* block_position = tag_serialization_context.tag_data_start + address_offset;

	for (unsigned int block_index = 0; block_index < tag_block.count; block_index++)
	{
		c_tag_struct_serialization_context* tag_struct_serialization_context = new() c_tag_struct_serialization_context(
			*this,
			tag_serialization_context,
			block_position,
			*runtime_tag_block_definition.struct_definition);
		struct_serialization_contexts.push_back(tag_struct_serialization_context);

		block_position += struct_size;
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

void c_tag_block_serialization_context::render_tree()
{
#define block_definition banned
	const char* block_name = name.c_str();

	ImGui::PushID(block_name);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (struct_serialization_contexts.empty())
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	bool tree_node_result = ImGui::TreeNodeEx("##block", flags, "%s", block_name);
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	tag_serialization_context.definition_tweaker.render_definition_context_menu(_definition_type_block_definition, &runtime_tag_block_definition);
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
#undef block_definition
}
