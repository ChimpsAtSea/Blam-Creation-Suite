#include "definitiontweaker-private-pch.h"

c_tag_serialization_context::c_tag_serialization_context(c_group_serialization_context* _group_serialization_context, s_engine_platform_build _engine_platform_build, const char* _tag_data_start) :
	num_errors(),
	max_serialization_error_type(_tag_serialization_state_good),
	engine_platform_build(_engine_platform_build),
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
	group_serialization_context(_group_serialization_context),
	serialization_errors()
{

}

c_tag_serialization_context::~c_tag_serialization_context()
{
	delete root_struct_serialization_context;

	for (auto seralization_error : serialization_errors)
	{
		delete seralization_error;
	}
}

unsigned int c_tag_serialization_context::read()
{
	tag_header = reinterpret_cast<const s_cache_file_tag_instance*>(tag_data_start);

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

		if (c_runtime_tag_block_definition* block_definition = group_serialization_context->tag_group.block_definition)
		{
			if (c_runtime_tag_struct_definition* struct_definition = block_definition->struct_definition)
			{
				root_struct_serialization_context = new c_tag_struct_serialization_context(
					*this,
					*struct_definition,
					expected_main_struct_size);

				unsigned int alignment = 1u << struct_definition->alignment_bits;
				unsigned int aligned_struct_size = ROUND_UP_VALUE(root_struct_serialization_context->struct_size, alignment);
				unsigned int aligned16_struct_size = ROUND_UP_VALUE(root_struct_serialization_context->struct_size, 16);
				int bytes_after_struct = static_cast<int>(expected_main_struct_size) - static_cast<int>(root_struct_serialization_context->struct_size);
				if (bytes_after_struct < 0 || bytes_after_struct >= 16)
				{
					serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "unexpected struct size expected:%u aligned:%u aligned16:%u unaligned:%u", expected_main_struct_size, aligned_struct_size, aligned16_struct_size, root_struct_serialization_context->struct_size));
				}
			}
			else
			{
				serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "runtime group block '%s' has no struct definition", group_serialization_context->tag_group.block_definition->name.c_str()));
			}
		}
		else
		{
			serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "runtime group '%s' has no block definition", group_serialization_context->tag_group.name.c_str()));
		}
	}
	else
	{
		tag group_tag = tag_header->group_tags[0];
		unsigned int group_tag_swapped = byteswap(group_tag);
		serialization_errors.push_back(new c_generic_serialization_error(_tag_serialization_state_error, "couldn't find tag group '%.4s'", &group_tag_swapped));
	}

	num_errors += serialization_errors.size();
	for (c_serialization_error* serialization_error : serialization_errors)
	{
		max_serialization_error_type = __max(max_serialization_error_type, serialization_error->error_type);
	}
	return num_errors;
}

unsigned int c_tag_serialization_context::traverse()
{
	num_errors += serialization_errors.size();
	return num_errors;
}
