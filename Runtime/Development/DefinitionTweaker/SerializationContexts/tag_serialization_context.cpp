#include "definitiontweaker-private-pch.h"

c_tag_serialization_context::c_tag_serialization_context(c_group_serialization_context& _group_serialization_context, unsigned int _index, const char* _tag_data_start) :
	c_serialization_context(_group_serialization_context),
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
	group_serialization_context(&_group_serialization_context),
	index(_index),
	definition_tweaker(_group_serialization_context.definition_tweaker),
	traverse_count()
{

}

c_tag_serialization_context::c_tag_serialization_context(c_definition_tweaker& _definition_tweaker, s_engine_platform_build _engine_platform_build, unsigned int _index, const char* _tag_data_start) :
	c_serialization_context(_engine_platform_build),
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
	group_serialization_context(nullptr),
	index(_index),
	definition_tweaker(_definition_tweaker),
	traverse_count()
{

}

c_tag_serialization_context::~c_tag_serialization_context()
{
	delete root_struct_serialization_context;
}

BCS_RESULT c_tag_serialization_context::read()
{
	tag_header = reinterpret_cast<const eldorado::s_cache_file_tag_instance*>(tag_data_start);

	tag_data_end = tag_data_start + tag_header->total_size;

	if (group_serialization_context)
	{
		dependencies = reinterpret_cast<const int*>(tag_header);
		data_fixups = dependencies + tag_header->dependency_count;
		resource_fixups = data_fixups + tag_header->data_fixup_count;
		_end = resource_fixups + tag_header->resource_fixup_count;

		ASSERT(tag_header->padding == 0);

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

		if (c_runtime_tag_block_definition* block_definition = group_serialization_context->runtime_tag_group_definition.block_definition)
		{
			if (c_runtime_tag_struct_definition* struct_definition = block_definition->struct_definition)
			{
				root_struct_serialization_context = new() c_tag_struct_serialization_context(
					*this,
					*this,
					tag_root_structure,
					*struct_definition,
					expected_main_struct_size);

				root_struct_serialization_context->read();

				unsigned int alignment = 1u << struct_definition->alignment_bits;
				unsigned int aligned_struct_size = ROUND_UP_VALUE(root_struct_serialization_context->struct_size, alignment);
				unsigned int aligned16_struct_size = ROUND_UP_VALUE(root_struct_serialization_context->struct_size, 16);
				int bytes_after_struct = static_cast<int>(expected_main_struct_size) - static_cast<int>(root_struct_serialization_context->struct_size);
				if (bytes_after_struct < 0 || bytes_after_struct >= 16)
				{
					root_struct_serialization_context->enqueue_serialization_error<c_generic_serialization_error>(
						_serialization_error_type_warning,
						"unexpected struct size expected:%u aligned:%u aligned16:%u unaligned:%u",
						expected_main_struct_size,
						aligned_struct_size,
						aligned16_struct_size,
						root_struct_serialization_context->struct_size);
				}
			}
			else
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_error,
					"runtime group block '%s' has no struct definition",
					group_serialization_context->runtime_tag_group_definition.block_definition->name.c_str());
			}
		}
		else
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_error,
				"runtime group '%s' has no block definition",
				group_serialization_context->runtime_tag_group_definition.name.c_str());
		}
	}
	else
	{
		tag group_tag = tag_header->group_tags[0];
		unsigned int group_tag_swapped = byteswap(group_tag);
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_error, 
			"couldn't find tag group '%.4s'", 
			&group_tag_swapped);
	}
	return BCS_S_OK;
}

BCS_RESULT c_tag_serialization_context::traverse()
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

	if (root_struct_serialization_context)
	{
		root_struct_serialization_context->traverse();
	}
	return BCS_S_OK;
}

void c_tag_serialization_context::render_tree()
{
	ImGui::PushID(index);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (root_struct_serialization_context == nullptr)
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	bool tree_node_result;
	if (group_serialization_context)
	{
		const char* group_name = group_serialization_context->name.c_str();
		tree_node_result = ImGui::TreeNodeEx("##tag", flags, "%s [%u]", group_name, index);
	}
	else
	{
		unsigned int group_tag_swapped = byteswap(tag_header->group_tags[0]);
		tree_node_result = ImGui::TreeNodeEx("##tag", flags, "%.4s [%u]", &group_tag_swapped, index);
	}
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	if (tree_node_result)
	{
		if (c_tag_struct_serialization_context* struct_serialization_context = root_struct_serialization_context)
		{
			struct_serialization_context->render_tree();
		}
		ImGui::TreePop();
	}

	ImGui::PopStyleColor();
	ImGui::PopID();
}
