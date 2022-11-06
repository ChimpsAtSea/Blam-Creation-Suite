#include "definitiontweaker-private-pch.h"

c_group_serialization_context::c_group_serialization_context(c_definition_tweaker& _definition_tweaker, c_runtime_tag_group_definition& _runtime_tag_group_definition) :
	c_serialization_context(_definition_tweaker.engine_platform_build),
	definition_tweaker(_definition_tweaker),
	serialization_contexts(),
	serialization_contexts_mutex(),
	runtime_tag_group_definition(_runtime_tag_group_definition),
	name(runtime_tag_group_definition.name),
	group_tag(runtime_tag_group_definition.group_tag),
	tag_cache_offset_index(),
	tag_serialization_read_index(),
	tag_serialization_traverse_index()
{

}

c_group_serialization_context::~c_group_serialization_context()
{

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
	if (group_tag == blofeld::eldorado::pc32::SOUND_TAG)
	{
		debug_point;
		return;
	}

	const char* tag_data_start = static_cast<char*>(definition_tweaker.binary_data[_binary_tags]) + tag_cache_offset;
	const s_cache_file_tag_instance* tag_header = reinterpret_cast<const s_cache_file_tag_instance*>(tag_data_start);

	if (group_tag == blofeld::eldorado::pc32::CACHE_FILE_SOUND_TAG && tag_header->group_tags[0] == blofeld::eldorado::pc32::SOUND_TAG)
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
	serialization_contexts.push_back(tag_serialization_context);

	serialization_contexts_mutex.unlock();
}

BCS_RESULT c_group_serialization_context::read()
{
	if (tag_cache_offset_index < definition_tweaker.cache_file_tags_header->tag_count)
	{
		unsigned int invoke_tag_cache_offset_index = atomic_incu32(&this->tag_cache_offset_index) - 1;
		if (invoke_tag_cache_offset_index < definition_tweaker.cache_file_tags_header->tag_count)
		{
			read(invoke_tag_cache_offset_index);

			return BCS_S_CONTINUE;
		}
	}

	serialization_contexts_mutex.lock();
	unsigned int num_serialization_contexts = static_cast<unsigned int>(serialization_contexts.size());
	if (tag_serialization_read_index < num_serialization_contexts)
	{
		unsigned int invoke_tag_serialization_read_index = atomic_incu32(&this->tag_serialization_read_index) - 1;
		if (invoke_tag_serialization_read_index < num_serialization_contexts)
		{
			c_tag_serialization_context* tag_serialization_context = serialization_contexts[invoke_tag_serialization_read_index];
			serialization_contexts_mutex.unlock(); // #NOTE: Make sure we don't hang onto the lock during the tag serialization context read

			tag_serialization_context->read();

			return BCS_S_CONTINUE;
		}
		else
		{
			serialization_contexts_mutex.unlock();
		}
	}
	else
	{
		serialization_contexts_mutex.unlock();
	}
	return BCS_S_OK;
}

BCS_RESULT c_group_serialization_context::traverse()
{
	serialization_contexts_mutex.lock();
	unsigned int num_serialization_contexts = static_cast<unsigned int>(serialization_contexts.size());
	if (tag_serialization_traverse_index < num_serialization_contexts)
	{
		unsigned int invoke_tag_serialization_traverse_index = atomic_incu32(&this->tag_serialization_traverse_index) - 1;
		if (invoke_tag_serialization_traverse_index < num_serialization_contexts)
		{
			c_tag_serialization_context* tag_serialization_context = serialization_contexts[invoke_tag_serialization_traverse_index];
			serialization_contexts_mutex.unlock(); // #NOTE: Make sure we don't hang onto the lock during the tag serialization context read

			tag_serialization_context->traverse();

			return BCS_S_CONTINUE;
		}
		else
		{
			serialization_contexts_mutex.unlock();
		}
	}
	else
	{
		serialization_contexts_mutex.unlock();
	}

	return BCS_S_OK;
}

void c_group_serialization_context::render_tree()
{
	if (!serialization_contexts.empty())
	{
		ImGui::PushID(group_tag);

		ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

		ImGuiTreeNodeFlags flags =
			ImGuiTreeNodeFlags_SpanFullWidth;
		bool tree_node_result = ImGui::TreeNodeEx("##group", flags, "%s (%zu)", name.c_str(), serialization_contexts.size());
		render_hover_tooltip();
		definition_tweaker.render_definition_context_menu(_definition_type_group_definition, &runtime_tag_group_definition);
		if (tree_node_result)
		{
			for (c_tag_serialization_context* tag_serialization_context : serialization_contexts)
			{
				tag_serialization_context->render_tree();
			}

			ImGui::TreePop();
		}

		ImGui::PopStyleColor();

		ImGui::PopID();
	}
}
