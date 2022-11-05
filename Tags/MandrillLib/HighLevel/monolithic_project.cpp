#include "mandrilllib-private-pch.h"




c_monolithic_tag_project::c_monolithic_tag_project(
	const wchar_t* directory,
	s_engine_platform_build engine_platform_build,
	c_status_interface* status_interface) :
	c_tag_project(engine_platform_build, status_interface),
	groups(),
	tags(),
	num_tag_partitions(),
	num_cache_partitions(),
	//cache_memory_mapped_files(),
	//cache_memory_mapped_file_infos(),
	root_chunk(),
	tag_file_index_chunk(),
	tag_file_blocks_chunk(),
	tag_heap_chunk(),
	tag_heap_list_chunk(),
	tag_partition_list_chunk(),
	cache_heap_chunk(),
	cache_heap_list_chunk(),
	cache_partition_list_chunk()
{
	for (const blofeld::s_tag_group** tag_group_iter = blofeld::get_tag_groups_by_engine_platform_build(engine_platform_build); *tag_group_iter; tag_group_iter++)
	{
		h_group* group = new() h_group(engine_platform_build, **tag_group_iter);
		groups.push_back(group);

	}

	wcscpy_s(root_directory, directory);
	wcscpy_s(tag_cache_directory, directory);
	wcscat_s(tag_cache_directory, L"tag_cache\\");
	wcscpy_s(blob_index_file_path, tag_cache_directory);
	wcscat_s(blob_index_file_path, L"blob_index.dat");

	c_stopwatch stopwatch;
	stopwatch.start();

	void* tag_file_data;
	uint64_t tag_file_data_size;
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = filesystem_read_file_to_memory(blob_index_file_path, tag_file_data, tag_file_data_size)))
	{
		throw rs;
	}
	ASSERT(tag_file_data_size > (sizeof(s_tag_file_header) + sizeof(tag)));

	BCS_RESULT parse_tag_blob_result = parse_tag_blob(tag_file_data, tag_file_data_size);
	BCS_FAIL_THROW(parse_tag_blob_result);
	BCS_RESULT init_monolithic_tag_file_views_result = init_monolithic_tag_file_views();
	BCS_FAIL_THROW(init_monolithic_tag_file_views_result);
	BCS_RESULT init_monolithic_cache_file_views_result = init_monolithic_cache_file_views();
	BCS_FAIL_THROW(init_monolithic_cache_file_views_result);
	BCS_RESULT read_tags_result = read_tags();
	BCS_FAIL_THROW(read_tags_result);
	BCS_RESULT resolve_unqualified_tags_result = resolve_unqualified_tags();
	BCS_FAIL_THROW(resolve_unqualified_tags_result);

	delete root_chunk;
	tracked_free(tag_file_data);

	memory_collect();

	stopwatch.stop();
	float tag_parse_time = stopwatch.get_miliseconds();
	if (status_interface)
	{
		status_interface->wait_status_bar_idle();
		status_interface->set_status_bar_status(_status_interface_priority_medium, 5.0f, "Finished creating project %S %0.2fms", root_directory, stopwatch.get_miliseconds());
	}
}

void c_monolithic_tag_project::destroy_tags(h_tag* const* tags, size_t index)
{
	h_tag* tag = tags[index];
	delete tag;
}

c_monolithic_tag_project::~c_monolithic_tag_project()
{
	ASSERT_NO_THROW(BCS_SUCCEEDED(deinit_monolithic_tag_file_views()));
	ASSERT_NO_THROW(BCS_SUCCEEDED(deinit_monolithic_cache_file_views()));

	parallel_invoke(size_t(0), tags.size(), (t_parallel_invoke_func<size_t>)destroy_tags, tags.data());

	for (h_group* group : groups)
	{
		delete group;
	}

	memory_collect();
}

struct s_init_monolithic_tag_file_views_userdata
{
	c_monolithic_tag_project* _this;
	BCS_RESULT error_result;
	uint32_t load_finished;
};

void c_monolithic_tag_project::init_monolithic_tag_file_views_impl(void* _userdata, uint32_t tag_partition_index)
{
	s_init_monolithic_tag_file_views_userdata* userdata = static_cast<s_init_monolithic_tag_file_views_userdata*>(_userdata);
	c_monolithic_tag_project* _this = userdata->_this;
	BCS_RESULT rs = BCS_S_OK;

	c_partition_chunk* partition_chunk = _this->tag_partition_list_chunk->get_child_unsafe<c_partition_chunk>(tag_partition_index);
	ASSERT(partition_chunk != nullptr);
	ASSERT(partition_chunk->partition_header.file_index == tag_partition_index);

	wchar_t partition_filepath[0x10000];
	swprintf(partition_filepath, _countof(partition_filepath), L"%sblobs\\tags_%i", _this->tag_cache_directory, partition_chunk->partition_header.file_index);

	c_monolithic_partition_view* partition_view;
	if (BCS_SUCCEEDED(command_line_has_argument_internal("loadblobsmemory")))
	{
		partition_view = new() c_monolithic_partition_view(partition_filepath, _monolithic_partition_view_type_memory);
	}
	else
	{
		partition_view = new() c_monolithic_partition_view(partition_filepath, _monolithic_partition_view_type_mapped_file);
	}
	_this->tag_partition_views[tag_partition_index] = partition_view;

	if (_this->status_interface)
	{
		uint32_t load_finished = atomic_incu32(&userdata->load_finished);
		_this->status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Loading monolithic tag blobs (%u/%u)", load_finished, _this->num_tag_partitions);
	}
}

BCS_RESULT c_monolithic_tag_project::init_monolithic_tag_file_views()
{
	BCS_RESULT rs = BCS_S_OK;

	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Loading monolithic tag blobs");
	}

	num_tag_partitions = tag_partition_list_chunk->num_children;
	tag_partition_views = new() c_monolithic_partition_view * [num_tag_partitions];

	s_init_monolithic_tag_file_views_userdata userdata = {};
	userdata._this = this;
	userdata.error_result = BCS_S_OK;
	parallel_invoke(0ul, num_tag_partitions, init_monolithic_tag_file_views_impl, &userdata);

	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_low, 5.0f, "Finished monolithic loading tag blobs");
	}

	return rs;
}

BCS_RESULT c_monolithic_tag_project::init_monolithic_cache_file_views()
{
	BCS_RESULT rs = BCS_S_OK;

	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Loading monolithic cache blobs");
	}

	num_cache_partitions = cache_partition_list_chunk->num_children;
	cache_partition_views = new() c_monolithic_partition_view * [num_cache_partitions];
	for (uint32_t cache_partition_index = 0; cache_partition_index < num_cache_partitions; cache_partition_index++)
	{
		c_partition_chunk* partition_chunk = cache_partition_list_chunk->get_child_unsafe<c_partition_chunk>(cache_partition_index);
		ASSERT(partition_chunk != nullptr);
		ASSERT(partition_chunk->partition_header.file_index == cache_partition_index);

		wchar_t partition_filepath[0x10000];
		swprintf(partition_filepath, _countof(partition_filepath), L"%sblobs\\cache_%i", tag_cache_directory, partition_chunk->partition_header.file_index);

		c_monolithic_partition_view* partition_view = new() c_monolithic_partition_view(partition_filepath, _monolithic_partition_view_type_none);
		cache_partition_views[cache_partition_index] = partition_view;
	}

	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_medium, 5.0f, "Finished monolithic loading cache blobs");
	}

	return rs;
}

BCS_RESULT c_monolithic_tag_project::deinit_monolithic_tag_file_views()
{
	BCS_RESULT rs = BCS_S_OK;

	for (uint32_t tag_partition_index = 0; tag_partition_index < num_tag_partitions; tag_partition_index++)
	{
		c_monolithic_partition_view* partition_view = tag_partition_views[tag_partition_index];
		delete partition_view;
	}

	delete[] tag_partition_views;

	return rs;
}

BCS_RESULT c_monolithic_tag_project::deinit_monolithic_cache_file_views()
{
	BCS_RESULT rs = BCS_S_OK;

	for (uint32_t cache_partition_index = 0; cache_partition_index < num_cache_partitions; cache_partition_index++)
	{
		c_monolithic_partition_view* partition_view = cache_partition_views[cache_partition_index];
		delete partition_view;
	}

	delete[] cache_partition_views;

	return rs;
}

BCS_RESULT c_monolithic_tag_project::parse_tag_blob(const void* tag_file_data, uint64_t tag_file_data_size)
{
	BCS_RESULT rs = BCS_S_OK;

	const blofeld::s_tag_persistent_identifier* session_identifier = static_cast<const blofeld::s_tag_persistent_identifier*>(tag_file_data);

	root_chunk = new() c_monolithic_tag_backend_chunk();
	root_chunk->read_chunk(nullptr, next_contiguous_pointer(blofeld::s_tag_persistent_identifier, session_identifier), true, true);
	root_chunk->log();

	tag_file_index_chunk = root_chunk->get_child_by_type_unsafe<c_tag_file_index_chunk>();
	tag_file_blocks_chunk = root_chunk->get_child_by_type_unsafe<c_tag_file_blocks_chunk>();

	tag_heap_chunk = root_chunk->get_child_by_type_unsafe<c_tag_heap_chunk>();
	tag_heap_list_chunk = tag_heap_chunk->get_child_by_type_unsafe<c_partitioned_heap_entry_list_chunk>();
	tag_partition_list_chunk = tag_heap_chunk->get_child_by_type_unsafe<c_partition_list_chunk>();

	cache_heap_chunk = root_chunk->get_child_by_type_unsafe<c_cache_heap_chunk>();
	cache_heap_list_chunk = cache_heap_chunk->get_child_by_type_unsafe<c_partitioned_heap_entry_list_chunk>();
	cache_partition_list_chunk = cache_heap_chunk->get_child_by_type_unsafe<c_partition_list_chunk>();

	ASSERT(tag_file_index_chunk != nullptr);
	ASSERT(tag_file_blocks_chunk != nullptr);
	ASSERT(tag_heap_chunk != nullptr);
	ASSERT(tag_heap_list_chunk != nullptr);
	ASSERT(tag_partition_list_chunk != nullptr);
	ASSERT(cache_heap_chunk != nullptr);
	ASSERT(cache_heap_list_chunk != nullptr);
	ASSERT(cache_partition_list_chunk != nullptr);

	root_chunk->log();

	return rs;
}

BCS_RESULT c_monolithic_tag_project::get_tag_partition_view(
	uint32_t tag_heap_entry_index,
	c_monolithic_partition_view*& tag_partition_view) const
{
	if (tag_heap_entry_index == 0xFFFFFFFF)
	{
		tag_partition_view = nullptr;
		return BCS_E_NOT_FOUND;
	}
	else
	{
		s_partitioned_heap_entry& tag_heap_entry = tag_heap_list_chunk->entries[tag_heap_entry_index];
		ASSERT(tag_heap_entry.partition_index < num_tag_partitions);
		tag_partition_view = tag_partition_views[tag_heap_entry.partition_index];
		return BCS_S_OK;
	}
}

BCS_RESULT c_monolithic_tag_project::get_cache_partition_view(
	uint32_t cache_heap_entry_index,
	c_monolithic_partition_view*& cache_partition_view) const
{
	if (cache_heap_entry_index == 0xFFFFFFFF)
	{
		cache_partition_view = nullptr;
		return BCS_E_NOT_FOUND;
	}
	else
	{
		s_partitioned_heap_entry& cache_heap_entry = cache_heap_list_chunk->entries[cache_heap_entry_index];
		ASSERT(cache_heap_entry.partition_index < num_cache_partitions);
		cache_partition_view = cache_partition_views[cache_heap_entry.partition_index];
		return BCS_S_OK;
	}
}

BCS_RESULT c_monolithic_tag_project::read_tag(uint32_t index, h_tag*& out_high_level_tag, h_group*& out_tag_group) const
{
	s_compressed_tag_file_index_entry& tag_file_index_entry = tag_file_index_chunk->compressed_tag_file_index_entries[index];

	const char* relative_tag_file_path_without_extension = tag_file_index_chunk->name_buffer + tag_file_index_entry.name_offset;

	out_tag_group = nullptr;
	out_high_level_tag = nullptr;

	if (tag_file_index_entry.wide_block_index == 0xFFFFFFFF)
	{
		return BCS_S_CONTINUE;
	}

	if (tag_file_index_entry.wide_block_datum_index == 0xFFFFFFFF)
	{
		return BCS_S_CONTINUE;
	}

	unsigned short wide_block_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(tag_file_index_entry.wide_block_index);
	unsigned short wide_block_datum_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(tag_file_index_entry.wide_block_datum_index);

	uint32_t wide_data_cache_block_index = wide_block_index * 0xFFFFu + wide_block_datum_index;
	ASSERT(wide_data_cache_block_index < tag_file_blocks_chunk->num_wide_data_cache_blocks);

	s_wide_data_cache_block& wide_data_cache_block = tag_file_blocks_chunk->wide_data_cache_blocks[wide_data_cache_block_index];

	ASSERT(wide_data_cache_block.current_datum == tag_file_index_entry.wide_block_datum_index);

	c_monolithic_partition_view* tag_partition_view = nullptr;
	get_tag_partition_view(wide_data_cache_block.tag_heap_entry_index, tag_partition_view);

	c_monolithic_partition_view* resource_partition_view = nullptr;
	get_cache_partition_view(wide_data_cache_block.cache_heap_entry_index, resource_partition_view);

	c_stopwatch s;
	s.start();

	h_tag* high_level_tag = nullptr;
	if (wide_data_cache_block.tag_heap_entry_index != 0xFFFFFFFF)
	{
		s_partitioned_heap_entry& tag_heap_entry = tag_heap_list_chunk->entries[wide_data_cache_block.tag_heap_entry_index];
		c_partition_chunk* partition_chunk = tag_partition_list_chunk->get_child_unsafe<c_partition_chunk>(tag_heap_entry.partition_index);
		ASSERT(partition_chunk != nullptr);
		ASSERT(partition_chunk->partition_header.file_index == tag_heap_entry.partition_index);
		ASSERT(tag_heap_entry.partition_index < num_tag_partitions);

		unsigned short heap_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(tag_heap_entry.heap_datum);
		s_lruv_cache_block_ex& lruv_cache_block = partition_chunk->lruv_cache_blocks[heap_index];

		const void* tag_data = static_cast<char*>(tag_partition_view->buffer) + lruv_cache_block.offset;

		ASSERT(tag_partition_view->buffer_size > (sizeof(s_tag_file_header) + sizeof(tag)));

		const s_tag_file_header* src_header = static_cast<const s_tag_file_header*>(tag_data);
		bool is_little_endian_tag = src_header->blam == 'BLAM';
		bool is_big_endian_tag = byteswap(src_header->blam) == 'BLAM';
		ASSERT(is_little_endian_tag || is_big_endian_tag);

		s_tag_file_header header = *src_header;
		if (is_big_endian_tag)
		{
			byteswap_inplace(header);
		}

		c_high_level_tag_file_reader* high_level_tag_file_reader = new() c_high_level_tag_file_reader(
			engine_platform_build,
			tag_data,
			tag_partition_view,
			resource_partition_view);

		high_level_tag_file_reader->tag_group_layout_chunk->log(high_level_tag_file_reader);
		high_level_tag_file_reader->binary_data_chunk->log(high_level_tag_file_reader);

		// BENCHMARK_STOP(reader_log);

		// BENCHMARK_STOP(tag_read_chunks);
		// BENCHMARK_START(parse_high_level_object);

		high_level_tag_file_reader->parse_high_level_object(high_level_tag);


		delete high_level_tag_file_reader;

		// BENCHMARK_STOP(parse_high_level_object);
		// BENCHMARK_STOP(cleanup);
	}

	s.stop();
	float ms = s.get_miliseconds();

	if (high_level_tag != nullptr)
	{
		h_group* tag_group;
		ASSERT(BCS_SUCCEEDED(get_group_by_group_tag(tag_file_index_entry.group_tag, tag_group)));

		high_level_tag->generate_filepaths(relative_tag_file_path_without_extension);

		console_write_line_info("Read tag %s (%.2f ms)", high_level_tag->get_file_path(), ms);
		if (status_interface)
		{
			status_interface->set_status_bar_status(_status_interface_priority_low, 15.0f, "Read tag %s (%.2f ms)", high_level_tag->get_file_path(), ms);
		}

		// #TODO: should this be done here?
		// I don't think this is thread safe...
		//tag_group->associate_tag_instance(*high_level_tag);

		out_tag_group = tag_group;
		out_high_level_tag = high_level_tag;

		return BCS_S_OK;
	}


	return BCS_S_CONTINUE;
}

struct s_monolithic_tag_project_read_tags_callback_data
{
	union
	{
		struct // params
		{
			c_monolithic_tag_project* monolithic_tag_project;
		};
		struct // results
		{
			h_tag* high_level_tag;
			h_group* high_level_tag_group;
		};
	};
	BCS_RESULT result;
};

void c_monolithic_tag_project::read_tags_callback(s_monolithic_tag_project_read_tags_callback_data* callback_data_array, int32_t index)
{
	s_monolithic_tag_project_read_tags_callback_data& callback_data = callback_data_array[index];
	callback_data.result = callback_data.monolithic_tag_project->read_tag(index, callback_data.high_level_tag, callback_data.high_level_tag_group);
}

BCS_RESULT c_monolithic_tag_project::read_tags()
{
	BCS_RESULT rs = BCS_S_OK;

	c_stopwatch stopwatch;
	stopwatch.start();

	uint32_t compressed_entry_count = tag_file_index_chunk->tag_file_index_header.compressed_entry_count;
	const char* max_tag_index_string;
	if (BCS_SUCCEEDED(command_line_get_argument("maxtagindex", max_tag_index_string)))
	{
		uint32_t max_tag_index = strtoul(max_tag_index_string, nullptr, 10);
		if (max_tag_index > 0)
		{
			compressed_entry_count = __min(max_tag_index, compressed_entry_count);
		}
	}
	s_monolithic_tag_project_read_tags_callback_data* callback_data_array = new() s_monolithic_tag_project_read_tags_callback_data[compressed_entry_count];
	for (uint32_t callback_data_index = 0; callback_data_index < compressed_entry_count; callback_data_index++)
	{
		s_monolithic_tag_project_read_tags_callback_data& callback_data = callback_data_array[callback_data_index];
		callback_data.monolithic_tag_project = this;
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
			compressed_entry_count,
			reinterpret_cast<t_parallel_invoke_long_func>(read_tags_callback),
			callback_data_array);
	}

	for (uint32_t callback_data_index = 0; callback_data_index < compressed_entry_count; callback_data_index++)
	{
		s_monolithic_tag_project_read_tags_callback_data& callback_data = callback_data_array[callback_data_index];
		if (BCS_FAILED(callback_data.result))
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
		status_interface->set_status_bar_status(_status_interface_priority_low, 5.0f, "Finished creating project %S %0.2fms", root_directory, stopwatch.get_miliseconds());
	}

	return rs;
}

BCS_RESULT c_monolithic_tag_project::get_group_by_group_tag(tag group_tag, h_group*& group) const
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

BCS_RESULT c_monolithic_tag_project::get_group_by_file_extension(const char* file_extension, h_group*& group) const
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

BCS_RESULT c_monolithic_tag_project::get_tag_instances(h_tag* const*& tag_instances, uint32_t& tag_instance_count) const
{
	tag_instances = tags.data();
	tag_instance_count = static_cast<unsigned long>(tags.size());

	return BCS_S_OK;
}

BCS_RESULT c_monolithic_tag_project::get_tag_groups(h_group* const*& out_groups, uint32_t& out_group_count) const
{
	out_groups = groups.data();
	out_group_count = static_cast<unsigned long>(groups.size());

	return BCS_S_OK;
}
