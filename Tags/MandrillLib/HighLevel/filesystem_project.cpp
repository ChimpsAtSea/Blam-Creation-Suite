#include "mandrilllib-private-pch.h"

c_filesystem_tag_project::c_filesystem_tag_project(const wchar_t* directory, s_engine_platform_build engine_platform_build) :
	c_tag_project(engine_platform_build),
	groups(),
	tags()
{
	for (const blofeld::s_tag_group** tag_group_iter = blofeld::tag_groups[engine_platform_build.engine_type]; *tag_group_iter; tag_group_iter++)
	{
		h_group* group = new() h_group(engine_platform_build, **tag_group_iter);
		groups.push_back(group);
		debug_point;
	}

	wcscpy(tags_directory, directory);
	wcscat(tags_directory, L"tags\\");

	c_stopwatch stopwatch;
	stopwatch.start();
	try_open_tag_files();
	stopwatch.stop();
	float miliseconds = stopwatch.get_miliseconds();

	stopwatch.start();
	for (auto& candidate : candidates)
	{
		const wchar_t* filepath = candidate.filepath;
		const wchar_t* relative_filepath = candidate.relative_filepath;

		if (strcmp(candidate.group->tag_group.name, "vehicle_group") == 0)
		{
			if (h_tag* high_level_tag = try_parse_tag_file(filepath))
			{
				BCS_WIDECHAR_TO_CHAR_STACK(relative_filepath, relative_filepath_mb);

				high_level_tag->tag_filename = filesystem_extract_filepath_filename(relative_filepath_mb);
				high_level_tag->tag_filepath = relative_filepath_mb;

				candidate.group->associate_tag_instance(*high_level_tag);
				debug_point;
			}
		}
	}
	stopwatch.stop();
	float tag_parse_time = stopwatch.get_miliseconds();

	debug_point;
}

c_filesystem_tag_project::~c_filesystem_tag_project()
{
	for (h_tag* tag : tags)
	{
		delete tag;
	}
}

void c_filesystem_tag_project::try_open_tag_files()
{
	filesystem_traverse_directory_folders(
		tags_directory,
		[](void* userdata_pointer, const wchar_t* directory, const wchar_t* relative_directory)
		{
			struct s_traverse_directory_userdata
			{
				c_filesystem_tag_project& configurator_tab;
				const wchar_t* directory;
				const wchar_t* relative_directory;
			};
			s_traverse_directory_userdata userdata = { *static_cast<c_filesystem_tag_project*>(userdata_pointer), directory, relative_directory };
			filesystem_traverse_directory_files(
				directory,
				L"*",
				[](void* userdata_pointer, const wchar_t* path, const wchar_t* relative_path)
				{
					s_traverse_directory_userdata& userdata = *static_cast<s_traverse_directory_userdata*>(userdata_pointer);

					c_fixed_wide_path relative_path_buffer;
					relative_path_buffer.format(L"%s%s", userdata.relative_directory + 1, relative_path + 1);

					userdata.configurator_tab.try_open_single_tag_file(path, relative_path_buffer);
					return true;
				},
				&userdata);
			return true;
		},
		this);
}

void c_filesystem_tag_project::try_open_single_tag_file(const wchar_t* filepath, const wchar_t* relative_filepath)
{
	const wchar_t* extension = filesystem_extract_filepath_extension(relative_filepath);
	if (*extension == 0 || *extension != '.')
	{
		return;
	}

	const wchar_t* group_name = extension + 1;
	BCS_WIDECHAR_TO_CHAR_STACK(group_name, group_name_mb);

	h_group* group;
	if (BCS_FAILED(get_group_by_file_extension(group_name_mb, group)))
	{
		return;
	}

	candidates.push_back({ group, _wcsdup(filepath), _wcsdup(relative_filepath) });

	debug_point;
}

h_tag* c_filesystem_tag_project::try_parse_tag_file(const wchar_t* filepath)
{
	void* tag_file_data;
	unsigned long long tag_file_data_size;

	s_single_tag_file_header* header_data;
	c_single_tag_file_layout_reader* layout_reader;
	c_single_tag_file_reader* reader;

	BCS_FAIL_THROW(filesystem_read_file_to_memory(filepath, tag_file_data, tag_file_data_size));
	ASSERT(tag_file_data_size > (sizeof(s_single_tag_file_header) + sizeof(tag)));
	header_data = static_cast<s_single_tag_file_header*>(tag_file_data);
	ASSERT(header_data->blam == 'BLAM');

	static constexpr tag k_tag_file_root_data_stream_tag = 'tag!';

	tag root_node_tag = *reinterpret_cast<tag*>(header_data + 1);
	bool is_little_endian_tag = root_node_tag == k_tag_file_root_data_stream_tag;
	bool is_big_endian_tag = byteswap(root_node_tag) == k_tag_file_root_data_stream_tag;
	ASSERT(is_little_endian_tag || is_big_endian_tag);

	c_stopwatch s;
	s.start();

	layout_reader = new() c_single_tag_file_layout_reader(*header_data, header_data);

	reader = new() c_single_tag_file_reader(
		*header_data,
		engine_platform_build,
		*layout_reader,
		*layout_reader->binary_data_chunk);

	s.stop();
	float ms = s.get_miliseconds();
	console_write_line("Processed chunks in %.2f ms", ms);

	//tag_group_layout_chunk->log(layout_reader->string_data_chunk);
	//binary_data_chunk->log(layout_reader->string_data_chunk);

	h_tag* high_level_tag;
	reader->parse_high_level_object(high_level_tag);
	debug_point;

	return high_level_tag;
}

BCS_RESULT c_filesystem_tag_project::get_group_by_group_tag(tag group_tag, h_group*& group) const
{
	for (h_group* current_group : groups)
	{
		if (current_group->tag_group.group_tag == group_tag)
		{
			group = current_group;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_filesystem_tag_project::get_group_by_file_extension(const char* file_extension, h_group*& group) const
{
	char file_extension_buffer[256];
	strcpy(file_extension_buffer, file_extension);
	strcat(file_extension_buffer, "_group");

	for (h_group* current_group : groups)
	{
		if (strcmp(file_extension_buffer, current_group->tag_group.name) == 0)
		{
			group = current_group;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_filesystem_tag_project::get_tag_instances(h_tag* const*& tag_instances, unsigned long& tag_instance_count) const
{
	tag_instances = tags.data();
	tag_instance_count = static_cast<unsigned long>(tags.size());

	return BCS_S_OK;
}

BCS_RESULT c_filesystem_tag_project::get_tag_groups(h_group* const*& out_groups, unsigned long& out_group_count) const
{
	out_groups = groups.data();
	out_group_count = static_cast<unsigned long>(groups.size());

	return BCS_S_OK;
}
