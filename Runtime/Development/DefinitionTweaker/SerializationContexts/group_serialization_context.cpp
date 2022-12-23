#include "definitiontweaker-private-pch.h"

using namespace blofeld::taggroups;

c_group_serialization_context::c_group_serialization_context(c_definition_tweaker& _definition_tweaker, c_runtime_tag_group_definition& _runtime_tag_group_definition) :
	c_serialization_context(
		_definition_tweaker.engine_platform_build, 
		nullptr,
		crazy_no_string_copy_hacktastic_function(
			_runtime_tag_group_definition.name,
			_runtime_tag_group_definition.original_tag_group_definition,
			_runtime_tag_group_definition.original_tag_group_definition->name,
			owns_name_memory),
		owns_name_memory),
	definition_tweaker(_definition_tweaker),
	tag_serialization_contexts(),
	serialization_contexts_mutex(),
	runtime_tag_group_definition(_runtime_tag_group_definition),
	group_tag(runtime_tag_group_definition.group_tag),
	tag_cache_offset_index(),
	tag_cache_checked_index(),
	tag_serialization_read_index(),
	tag_serialization_traverse_sorted(),
	tag_serialization_traverse_index(),
	tag_serialization_calculate_memory_index()
{

}

c_group_serialization_context::~c_group_serialization_context()
{
	for (c_serialization_context* serialization_context : tag_serialization_contexts)
	{
		if (serialization_context->parent_serialization_context == this)
		{
			delete serialization_context;
		}
	}
}

void c_group_serialization_context::read(unsigned int tag_cache_offset_index)
{
	unsigned int tag_cache_offset = definition_tweaker.tag_cache_offsets[tag_cache_offset_index];
	if (tag_cache_offset == 0)
	{
		debug_point;
		return;
	}

	// skip sound tags as these aren't actually used
	if (group_tag == SOUND_TAG)
	{
		debug_point;
		return;
	}

	const char* tag_data_start = static_cast<char*>(definition_tweaker.binary_data[_binary_tags]) + tag_cache_offset;
	const blofeld::eldorado::s_cache_file_tag_instance* tag_header = reinterpret_cast<const blofeld::eldorado::s_cache_file_tag_instance*>(tag_data_start);

	if (group_tag == CACHE_FILE_SOUND_TAG && tag_header->group_tags[0] == SOUND_TAG)
	{
		// sound tags are weird and the sound tag is interpreted as the cache file sound tag
		debug_point;
	}
	else if (tag_header->group_tags[0] != runtime_tag_group_definition.group_tag)
	{
		return;
	}

	serialization_contexts_mutex.lock();

	c_tag_serialization_context* tag_serialization_context = new() c_tag_serialization_context(*this, tag_cache_offset_index, tag_data_start);
	tag_serialization_contexts.push_back(tag_serialization_context);

	serialization_contexts_mutex.unlock();
}

BCS_RESULT c_group_serialization_context::read()
{
	if (c_definition_tweaker::get_serialization_definition_list_group_setting() != blofeld::INVALID_TAG && c_definition_tweaker::get_serialization_definition_list_group_setting() != group_tag)
	{
		return BCS_S_OK;
	}

	if (tag_cache_offset_index < definition_tweaker.cache_file_tags_header->tag_count)
	{
		unsigned int invoke_tag_cache_offset_index = atomic_incu32(&this->tag_cache_offset_index);
		if (invoke_tag_cache_offset_index < definition_tweaker.cache_file_tags_header->tag_count)
		{
			read(invoke_tag_cache_offset_index);
			atomic_incu32(&this->tag_cache_checked_index);
			return BCS_S_CONTINUE;
		}
	}
	else if (tag_cache_checked_index < definition_tweaker.cache_file_tags_header->tag_count)
	{
		return BCS_S_SKIP; // another thread is still processing, request skip to avoid contention
	}
	else
	{
		unsigned int num_serialization_contexts = static_cast<unsigned int>(tag_serialization_contexts.size());
		if (tag_serialization_read_index < num_serialization_contexts)
		{
			unsigned int invoke_tag_serialization_read_index = atomic_incu32(&this->tag_serialization_read_index);
			if (invoke_tag_serialization_read_index < num_serialization_contexts)
			{
				c_tag_serialization_context* tag_serialization_context = tag_serialization_contexts[invoke_tag_serialization_read_index];
				tag_serialization_context->read();

				return BCS_S_CONTINUE; // request call again
			}
		}

		return BCS_S_OK; // finished state
	}

	return BCS_S_OK;
}

BCS_RESULT c_group_serialization_context::traverse()
{
	if (tag_serialization_traverse_sorted != 2)
	{
		if (atomic_cmpxchgu32(&tag_serialization_traverse_sorted, 1, 0) == 0)
		{
			std::sort(
				tag_serialization_contexts.begin(),
				tag_serialization_contexts.end(),
				[](c_tag_serialization_context* a, c_tag_serialization_context* b)
				{
					return a->index < b->index;
				});
			tag_serialization_traverse_sorted = 2;
		}
		else
		{
			return BCS_S_SKIP; // defer until sort is complete
		}
	}

	unsigned int num_serialization_contexts = static_cast<unsigned int>(tag_serialization_contexts.size());

	if (tag_serialization_traverse_index < num_serialization_contexts)
	{
		unsigned int invoke_tag_serialization_traverse_index = atomic_incu32(&this->tag_serialization_traverse_index);
		if (invoke_tag_serialization_traverse_index < num_serialization_contexts)
		{
			c_tag_serialization_context* tag_serialization_context = tag_serialization_contexts[invoke_tag_serialization_traverse_index];
			tag_serialization_context->traverse();

			return BCS_S_CONTINUE; // request call again
		}
	}

	return BCS_S_OK; // finished state
}

BCS_RESULT c_group_serialization_context::calculate_memory()
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

	unsigned int num_serialization_contexts = static_cast<unsigned int>(tag_serialization_contexts.size());

	if (tag_serialization_calculate_memory_index < num_serialization_contexts)
	{
		unsigned int invoke_tag_serialization_calculate_memory_index = atomic_incu32(&this->tag_serialization_calculate_memory_index);
		if (invoke_tag_serialization_calculate_memory_index < num_serialization_contexts)
		{
			c_tag_serialization_context* tag_serialization_context = tag_serialization_contexts[invoke_tag_serialization_calculate_memory_index];
			tag_serialization_context->calculate_memory();

			return BCS_S_CONTINUE; // request call again
		}
	}

	return BCS_S_OK; // finished state
}

void c_group_serialization_context::render_tree()
{
	if (!tag_serialization_contexts.empty())
	{
		ImGui::PushID(group_tag);

		ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

		ImGuiTreeNodeFlags flags =
			ImGuiTreeNodeFlags_SpanFullWidth;
		bool tree_node_result = ImGui::TreeNodeEx("##group", flags, "%s (%zu)", name, tag_serialization_contexts.size());
		render_hover_tooltip();
		definition_tweaker.render_definition_context_menu(_definition_type_group_definition, &runtime_tag_group_definition);
		if (tree_node_result)
		{
			for (c_tag_serialization_context* tag_serialization_context : tag_serialization_contexts)
			{
				tag_serialization_context->render_tree();
			}

			ImGui::TreePop();
		}

		ImGui::PopStyleColor();

		ImGui::PopID();
	}
}
