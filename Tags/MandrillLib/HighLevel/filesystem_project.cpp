#include "mandrilllib-private-pch.h"

c_filesystem_tag_project::c_filesystem_tag_project(
	const wchar_t* directory, 
	s_engine_platform_build engine_platform_build,
	c_status_interface* status_interface) :
	c_tag_project(engine_platform_build, status_interface),
	groups(),
	tags()
{
	for (const blofeld::s_tag_group** tag_group_iter = blofeld::get_tag_groups_by_engine_platform_build(engine_platform_build); *tag_group_iter; tag_group_iter++)
	{
		h_group* group = new() h_group(engine_platform_build, **tag_group_iter);
		groups.push_back(group);
		
	}

	wcscpy(tags_directory, directory);
	wcscat(tags_directory, L"tags\\");

	c_stopwatch stopwatch;
	stopwatch.start();
	try_open_tag_files();
	stopwatch.stop();
	float miliseconds = stopwatch.get_miliseconds();

	stopwatch.start();

	read_tags();

	resolve_unqualified_tags();

	stopwatch.stop();
	float tag_parse_time = stopwatch.get_miliseconds();

	if (status_interface)
	{
		status_interface->wait_status_bar_idle();
		status_interface->set_status_bar_status(_status_interface_priority_medium, 15.0f, "Finished reading tags (%.2f ms)", tag_parse_time);
	}
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
	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Traversing tag directory");
	}
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

	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_medium, 5.0f, "Finished traversing tag directory");
	}
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
}

BCS_RESULT c_filesystem_tag_project::read_tag_gen3(const wchar_t* filepath, h_tag*& out_high_level_tag) const
{
	BCS_VALIDATE_ARGUMENT(filepath);

	BCS_RESULT rs = BCS_S_OK;
	void* tag_file_data = nullptr;
	h_tag* high_level_tag = nullptr;
	try
	{
		uint64_t tag_file_data_size;
		if (BCS_FAILED(rs = filesystem_read_file_to_memory(filepath, tag_file_data, tag_file_data_size)))
		{
			throw rs;
		}

		DEBUG_ASSERT(tag_file_data_size > (sizeof(s_tag_file_header) + sizeof(tag)));
		if (tag_file_data_size < (sizeof(s_tag_file_header) + sizeof(tag)))
		{
			throw BCS_S_CONTINUE;
		}

		c_high_level_tag_file_reader* high_level_tag_file_reader = new() c_high_level_tag_file_reader(
			engine_platform_build,
			tag_file_data,
			nullptr,
			nullptr);

		high_level_tag_file_reader->parse_high_level_object(high_level_tag);

		out_high_level_tag = high_level_tag;

		delete high_level_tag_file_reader;
	}
	catch (BCS_RESULT _rs)
	{
		rs = _rs;
	}
	catch (...)
	{
		rs = BCS_E_FATAL;
	}

	tracked_free(tag_file_data);

	if (BCS_FAILED(rs))
	{
		delete high_level_tag;
	}

	return rs;
}

BCS_RESULT c_filesystem_tag_project::read_tag(const wchar_t* filepath, const wchar_t* relative_filepath, h_tag*& out_high_level_tag, h_group*& out_tag_group) const
{
	BCS_VALIDATE_ARGUMENT(filepath);
	out_tag_group = nullptr;
	out_high_level_tag = nullptr;

	c_stopwatch s;
	s.start();

	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_medium, 15.0f, "Reading tag file %S", relative_filepath);
	}

	BCS_RESULT rs = BCS_S_OK;
	h_tag* high_level_tag = nullptr;
	if (engine_platform_build.engine_type == _engine_type_halo1)
	{
		if (BCS_FAILED(rs = c_gen1_tag_file_parse_context::parse_gen1_tag_file_data(high_level_tag, filepath, engine_platform_build)))
		{
			return BCS_S_CONTINUE;
			return rs;
		}
	}
	else if (engine_platform_build.engine_type == _engine_type_halo2)
	{
		if (BCS_FAILED(rs = c_gen2_tag_file_parse_context::parse_gen2_tag_file_data(high_level_tag, filepath, engine_platform_build)))
		{
			return BCS_S_CONTINUE;
			return rs;
		}
	}
	else if (engine_platform_build.engine_type == _engine_type_halo3)
	{
		// #TODO: Standardize
		if (BCS_FAILED(rs = read_tag_gen3(filepath, high_level_tag)))
		{
			return BCS_S_CONTINUE;
			return rs;
		}
	}
	else
	{
		return BCS_E_UNSUPPORTED;
	}

	wchar_t* filepath_without_extension = wcsdup(relative_filepath);
	filesystem_remove_filepath_extension(filepath_without_extension);
	BCS_WIDECHAR_TO_CHAR_HEAP(filepath_without_extension, filepath_without_extension_mb);
	high_level_tag->generate_filepaths(filepath_without_extension_mb);

	s.stop();
	float ms = s.get_miliseconds();

	console_write_line_info("Read tag %s (%.2f ms)", high_level_tag->get_file_path(), ms);
	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_medium, 15.0f, "Read tag %s (%.2f ms)", high_level_tag->get_file_path(), ms);
	}

	untracked_free(filepath_without_extension);
	tracked_free(filepath_without_extension_mb);

	const blofeld::s_tag_group& blofeld_tag_group = high_level_tag->get_blofeld_group_definition();
	h_group* tag_group;
	if (BCS_FAILED(rs = get_group_by_group_tag(blofeld_tag_group.group_tag, tag_group)))
	{
		delete high_level_tag;
		return BCS_E_UNSUPPORTED;
	}

	out_high_level_tag = high_level_tag;
	out_tag_group = tag_group;

	return rs;
}

struct s_filesystem_tag_project_read_tags_callback_data
{
	union
	{
		struct // params
		{
			c_filesystem_tag_project* filesystem_tag_project;
			const wchar_t* filepath;
			const wchar_t* relative_filepath;
			volatile uint32_t* num_completed_tags;
			uint32_t num_tags;
		};
		struct // results
		{
			h_tag* high_level_tag;
			h_group* high_level_tag_group;
		};
	};
	BCS_RESULT result;
};

void c_filesystem_tag_project::read_tags_callback(s_filesystem_tag_project_read_tags_callback_data* callback_data_array, int32_t index)
{
	s_filesystem_tag_project_read_tags_callback_data& callback_data = callback_data_array[index];
	c_status_interface* status_interface = callback_data.filesystem_tag_project->status_interface;
	callback_data.result = callback_data.filesystem_tag_project->read_tag(callback_data.filepath, callback_data.relative_filepath, callback_data.high_level_tag, callback_data.high_level_tag_group);
	if (status_interface)
	{
		uint32_t num_completed_tags = atomic_addu32(callback_data.num_completed_tags, 1);
		status_interface->set_status_bar_load_percentage(float(num_completed_tags) / float(callback_data.num_tags));
	}
}

BCS_RESULT c_filesystem_tag_project::read_tags()
{
	BCS_RESULT rs = BCS_S_OK;

	c_stopwatch stopwatch;
	stopwatch.start();

	uint32_t candidate_entry_count = static_cast<uint32_t>(candidates.size());
	volatile uint32_t num_completed_tags = 0;
	s_filesystem_tag_project_read_tags_callback_data* callback_data_array = new() s_filesystem_tag_project_read_tags_callback_data[candidate_entry_count];
	for (uint32_t callback_data_index = 0; callback_data_index < candidate_entry_count; callback_data_index++)
	{
		s_filesystem_tag_project_read_tags_callback_data& callback_data = callback_data_array[callback_data_index];
		callback_data.filesystem_tag_project = this;
		callback_data.filepath = candidates[callback_data_index].filepath;
		callback_data.relative_filepath = candidates[callback_data_index].relative_filepath;
		callback_data.num_tags = candidate_entry_count;
		callback_data.num_completed_tags = &num_completed_tags;
		callback_data.result = BCS_S_CONTINUE;
	}

	const char* specific_tag_index_string;
	if (BCS_SUCCEEDED(command_line_get_argument("specifictagindex", specific_tag_index_string)))
	{
		uint32_t specific_tag_index = strtoul(specific_tag_index_string, nullptr, 10);

		read_tags_callback(callback_data_array, specific_tag_index);
	}
	else
	{
		parallel_invoke(
			0,
			candidate_entry_count,
			reinterpret_cast<t_parallel_invoke_long_func>(read_tags_callback),
			callback_data_array);
	}

	for (uint32_t callback_data_index = 0; callback_data_index < candidate_entry_count; callback_data_index++)
	{
		s_filesystem_tag_project_read_tags_callback_data& callback_data = callback_data_array[callback_data_index];
		if (BCS_FAILED(callback_data.result) && callback_data.result != BCS_E_UNSUPPORTED)
		{
			rs = callback_data.result;
		}
		else if (callback_data.result == BCS_S_OK)
		{
			ASSERT(callback_data.high_level_tag != nullptr);
			ASSERT(callback_data.high_level_tag_group != nullptr);

			// #TODO: can this be done inside and made thread safe? is that worth it?
			callback_data.high_level_tag_group->associate_tag_instance(*callback_data.high_level_tag);
			tags.push_back(callback_data.high_level_tag);
		}
	}
	delete[] callback_data_array;

	stopwatch.stop();
	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_low, 5.0f, "Finished creating project %S %0.2fms", tags_directory, stopwatch.get_miliseconds());
		status_interface->clear_status_bar_load_percentage();
	}

	return rs;
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
	for (h_group* current_group : groups)
	{
		if (strcmp(file_extension, current_group->tag_group.name) == 0)
		{
			group = current_group;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_filesystem_tag_project::get_tag_instances(h_tag* const*& tag_instances, uint32_t& tag_instance_count) const
{
	tag_instances = tags.data();
	tag_instance_count = static_cast<unsigned long>(tags.size());

	return BCS_S_OK;
}

BCS_RESULT c_filesystem_tag_project::get_tag_groups(h_group* const*& out_groups, uint32_t& out_group_count) const
{
	out_groups = groups.data();
	out_group_count = static_cast<unsigned long>(groups.size());

	return BCS_S_OK;
}
