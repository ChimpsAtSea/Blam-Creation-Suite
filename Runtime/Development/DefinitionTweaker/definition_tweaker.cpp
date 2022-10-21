#include "definitiontweaker-private-pch.h"

static constexpr const char* binary_filepaths[k_num_binaries] =
{
	"tags.dat",
	"string_ids.dat",
	"video.dat",
	"audio.dat",
	"resources.dat",
	"textures.dat",
	"textures_b.dat",
};

c_definition_tweaker::c_definition_tweaker() :
	engine_platform_build{ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 },
	open_tag_indices(),
	serialization_contexts(),
	binary_data(),
	binary_data_size(),
	file_handles(),
	runtime_tag_definitions()
{


}

c_definition_tweaker::~c_definition_tweaker()
{

}

void c_definition_tweaker::init()
{
	const char* eldorado_directory;
	BCS_RESULT get_eldorado_directory_result = command_line_get_argument("eldoradodir", eldorado_directory);
	ASSERT(BCS_SUCCEEDED(get_eldorado_directory_result));

	for (unsigned int binary_filepath_index = 0; binary_filepath_index < _countof(binary_filepaths); binary_filepath_index++)
	{
		const char* binary_filepath = binary_filepaths[binary_filepath_index];
		size_t filepath_buffer_length = strlen(eldorado_directory) + strlen("\\maps\\") + strlen(binary_filepath) + 1;
		char* filepath = trivial_malloc(char, filepath_buffer_length);
		strcpy(filepath, eldorado_directory);
		strcat(filepath, "\\maps\\");
		strcat(filepath, binary_filepath);

		BCS_RESULT create_memory_mapped_file_result = create_memory_mapped_file(filepath, true, file_handles[binary_filepath_index]);
		ASSERT(BCS_SUCCEEDED(create_memory_mapped_file_result));

		if (binary_filepath_index == 0)
		{
			BCS_RESULT read_file_result = filesystem_read_file_to_memory(filepath, binary_data[binary_filepath_index], binary_data_size[binary_filepath_index]);
			ASSERT(BCS_SUCCEEDED(read_file_result));
		}
		else
		{
			s_memory_mapped_file_info file_info;
			BCS_RESULT get_memory_mapped_file_info_result = get_memory_mapped_file_info(file_handles[binary_filepath_index], file_info);
			ASSERT(BCS_SUCCEEDED(get_memory_mapped_file_info_result));

			binary_data[binary_filepath_index] = file_info.file_view_begin;
			binary_data_size[binary_filepath_index] = file_info.file_size;
		}
	}

	runtime_tag_definitions = new c_runtime_tag_definitions(engine_platform_build);

	parse_binary();
}

void c_definition_tweaker::parse_binary()
{
	for (auto serialization_context : serialization_contexts)
	{
		delete serialization_context;
	}

	for (c_runtime_tag_group_definition* tag_group : runtime_tag_definitions->group_definitions)
	{
		c_group_serialization_context* group_serialization_context = new c_group_serialization_context(*tag_group);
		group_serialization_contexts.push_back(group_serialization_context);
	}

	s_cache_file_tags_header* cache_file_tags_header = static_cast<s_cache_file_tags_header*>(binary_data[_binary_tags]);
	unsigned int* tag_cache_offsets = reinterpret_cast<unsigned int*>(static_cast<char*>(binary_data[_binary_tags]) + cache_file_tags_header->tag_cache_offsets);

	for (unsigned int tag_cache_offset_index = 0; tag_cache_offset_index < cache_file_tags_header->tag_count; tag_cache_offset_index++)
	{
		unsigned int tag_cache_offset = tag_cache_offsets[tag_cache_offset_index];
		if (tag_cache_offset == 0)
		{
			debug_point;
			continue;
		}

		const char* tag_data_start = static_cast<char*>(binary_data[_binary_tags]) + tag_cache_offset;
		const s_cache_file_tag_instance* tag_header = reinterpret_cast<const s_cache_file_tag_instance*>(tag_data_start);


		c_group_serialization_context* group_serialization_context = nullptr;
		for (c_group_serialization_context* current_group_serialization_context : group_serialization_contexts)
		{
			if (current_group_serialization_context->tag_group.group_tag == tag_header->group_tags[0])
			{
				group_serialization_context = current_group_serialization_context;
				break;
			}
		}

		c_tag_serialization_context* tag_serialization_context = new c_tag_serialization_context(group_serialization_context, engine_platform_build, tag_data_start);
		
		if (group_serialization_context)
		{
			group_serialization_context->serialization_contexts.push_back(tag_serialization_context);
		}
		serialization_contexts.push_back(tag_serialization_context);

		unsigned long errors = tag_serialization_context->read();
		if (errors == 0)
		{
			errors = tag_serialization_context->traverse();
		}

		debug_point;
	}

	debug_point;
}

void c_definition_tweaker::deinit()
{
	for (auto serialization_context : serialization_contexts)
	{
		delete serialization_context;
	}

	for (unsigned int binary_filepath_index = 0; binary_filepath_index < _countof(binary_filepaths); binary_filepath_index++)
	{
		if (binary_filepath_index == 0)
		{
			tracked_free(binary_data[binary_filepath_index]);
		}
		else
		{
			BCS_RESULT destroy_memory_mapped_file_result = destroy_memory_mapped_file(file_handles[binary_filepath_index]);
			ASSERT(BCS_SUCCEEDED(destroy_memory_mapped_file_result));
		}
	}

	delete runtime_tag_definitions;
}

void c_definition_tweaker::render_user_interface()
{
	if (ImGui::Begin("Serialization Contexts"))
	{
		ImGui::Text("<missing group>");
		for (auto tag_serialization_context : serialization_contexts)
		{
			if (tag_serialization_context->group_serialization_context == nullptr)
			{
				unsigned int group_tag_swapped = byteswap(tag_serialization_context->tag_header->group_tags[0]);
				ImGui::Text("%.4s", &group_tag_swapped);
			}
		}

		for (auto group_serialization_context : group_serialization_contexts)
		{
			ImGui::Text("%s (%zu)", group_serialization_context->tag_group.name.c_str(), group_serialization_context->serialization_contexts.size());
			for (auto tag_serialization_context : group_serialization_context->serialization_contexts)
			{

			}
		}

		for (auto open_tag_index : open_tag_indices)
		{
			if (open_tag_index < serialization_contexts.size())
			{
				c_tag_serialization_context* serialization_context = serialization_contexts[open_tag_index];


			}
		}
	}
	ImGui::End();
}
