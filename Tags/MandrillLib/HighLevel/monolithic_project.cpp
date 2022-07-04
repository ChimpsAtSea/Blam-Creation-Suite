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
	for (const blofeld::s_tag_group** tag_group_iter = blofeld::tag_groups[engine_platform_build.engine_type]; *tag_group_iter; tag_group_iter++)
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
	unsigned long long tag_file_data_size;
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = filesystem_read_file_to_memory(blob_index_file_path, tag_file_data, tag_file_data_size)))
	{
		throw rs;
	}
	ASSERT(tag_file_data_size > (sizeof(s_single_tag_file_header) + sizeof(tag)));

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

BCS_RESULT c_monolithic_tag_project::resolve_unqualified_tags()
{
	BCS_RESULT rs = BCS_S_OK;

	c_stopwatch stopwatch;
	stopwatch.start();

	unsigned long num_tags = static_cast<unsigned long>(tags.size());

	if (status_interface)
	{
		status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Resolving unqualified tag references (%lu/%lu)", 0lu, num_tags);
	}

	parallel_invoke(0ul, num_tags, resolve_unqualified_tag_references, this);

	stopwatch.stop();
	float resolve_unqualified_tags_time = stopwatch.get_miliseconds();

	if (status_interface)
	{
		status_interface->wait_status_bar_idle();
		status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Resolving unqualified tag references finished %0.2fms", stopwatch.get_miliseconds());
	}

	return rs;
}

void c_monolithic_tag_project::resolve_unqualified_tag_references(void* _userdata, unsigned long tag_index)
{
	c_monolithic_tag_project* _this = static_cast<c_monolithic_tag_project*>(_userdata);

	h_tag* tag = _this->tags[tag_index];
	_this->resolve_unqualified_tag_references(*tag);

	if (_this->status_interface)
	{
		unsigned long num_tags = static_cast<unsigned long>(_this->tags.size());
		_this->status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Resolving unqualified tag references (%lu/%lu)", tag_index, num_tags);
	}
}

BCS_RESULT c_monolithic_tag_project::resolve_unqualified_tag_references(h_object& object)
{
	BCS_RESULT rs = BCS_S_OK;

	const blofeld::s_tag_field* const* field_list = object.get_blofeld_field_list();
	while (const blofeld::s_tag_field* field = *field_list++)
	{
		switch (field->field_type)
		{
		case blofeld::_field_struct:
		{
			h_object* struct_object = object.get_field_data<h_object>(*field);
			ASSERT(struct_object != nullptr);

			if (BCS_FAILED(rs = resolve_unqualified_tag_references(*struct_object)))
			{
				return rs;
			}
		}
		break;
		case blofeld::_field_array:
		case blofeld::_field_block:
		{
			h_enumerable* enumerable = object.get_field_data<h_enumerable>(*field);
			ASSERT(enumerable != nullptr);

			unsigned long enumerable_count = enumerable->size();
			for (unsigned long enumerable_index = 0; enumerable_index < enumerable_count; enumerable_index++)
			{
				h_object& enumerable_object = enumerable->get(enumerable_index);
				if (BCS_FAILED(rs = resolve_unqualified_tag_references(enumerable_object)))
				{
					return rs;
				}
			}

			debug_point;
		}
		break;
		case blofeld::_field_tag_reference:
		{
			h_tag_reference* tag_reference = object.get_field_data<h_tag_reference>(*field);
			ASSERT(tag_reference != nullptr);

			if (tag_reference->is_unqualified())
			{
				const char* target_tag_filepath = tag_reference->get_tag_path();
				tag group_tag = tag_reference->get_group_tag();
				if (group_tag != blofeld::INVALID_TAG)
				{
					h_group* group;
					if (BCS_SUCCEEDED(get_group_by_group_tag(group_tag, group)))
					{
						for (h_tag* current_tag : group->tags)
						{
							if (strcmp(current_tag->tag_filepath, target_tag_filepath) == 0)
							{
								tag_reference->set_group(group);
								tag_reference->set_tag(current_tag);
								goto next;
							}
						}
					}
				}
				debug_point;
			}
		}
		break;
		}
	next:;
	}

	return rs;
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
	long load_finished;
};

void c_monolithic_tag_project::init_monolithic_tag_file_views_impl(void* _userdata, unsigned long tag_partition_index)
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
	if (BCS_SUCCEEDED(command_line_has_argument("loadblobsmemory")))
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
		unsigned long load_finished = _InterlockedIncrement(&userdata->load_finished);
		_this->status_interface->set_status_bar_status(_status_interface_priority_low, INFINITY, "Loading monolithic tag blobs (%li/%lu)", load_finished, _this->num_tag_partitions);
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
	for (unsigned long cache_partition_index = 0; cache_partition_index < num_cache_partitions; cache_partition_index++)
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

	for (unsigned long tag_partition_index = 0; tag_partition_index < num_tag_partitions; tag_partition_index++)
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

	for (unsigned long cache_partition_index = 0; cache_partition_index < num_cache_partitions; cache_partition_index++)
	{
		c_monolithic_partition_view* partition_view = cache_partition_views[cache_partition_index];
		delete partition_view;
	}

	delete[] cache_partition_views;

	return rs;
}

BCS_RESULT c_monolithic_tag_project::parse_tag_blob(const void* tag_file_data, unsigned long long tag_file_data_size)
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
	unsigned long tag_heap_entry_index,
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
	unsigned long cache_heap_entry_index,
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

BCS_RESULT c_monolithic_tag_project::read_tag(unsigned long index, h_tag*& out_high_level_tag, h_group*& out_tag_group) const
{
	s_compressed_tag_file_index_entry& tag_file_index_entry = tag_file_index_chunk->compressed_tag_file_index_entries[index];

	const char* tag_name = tag_file_index_chunk->name_buffer + tag_file_index_entry.name_offset;

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

	unsigned long wide_data_cache_block_index = wide_block_index * 0xFFFFu + wide_block_datum_index;
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

		ASSERT(tag_partition_view->buffer_size > (sizeof(s_single_tag_file_header) + sizeof(tag)));

		const s_single_tag_file_header* src_header = static_cast<const s_single_tag_file_header*>(tag_data);
		bool is_little_endian_tag = src_header->blam == 'BLAM';
		bool is_big_endian_tag = byteswap(src_header->blam) == 'BLAM';
		ASSERT(is_little_endian_tag || is_big_endian_tag);

		s_single_tag_file_header header = *src_header;
		if (is_big_endian_tag)
		{
			byteswap_inplace(header);
		}

		c_single_tag_file_layout_reader* layout_reader = new() c_single_tag_file_layout_reader(header, tag_data);

		c_single_tag_file_reader* reader = new() c_single_tag_file_reader(
			header,
			engine_platform_build,
			is_big_endian_tag,
			*layout_reader,
			*layout_reader->binary_data_chunk,
			tag_partition_view,
			resource_partition_view);

		layout_reader->tag_group_layout_chunk->log(layout_reader);
		layout_reader->binary_data_chunk->log(layout_reader);

		// BENCHMARK_STOP(reader_log);

		// BENCHMARK_STOP(tag_read_chunks);
		//BENCHMARK_START(parse_high_level_object);

		reader->parse_high_level_object(high_level_tag);


		delete reader;
		delete layout_reader;

		//BENCHMARK_STOP(parse_high_level_object);
		// BENCHMARK_STOP(cleanup);
	}

	s.stop();
	float ms = s.get_miliseconds();
	console_write_line_verbose("Processed chunks in %.2f ms", ms);

	if (high_level_tag != nullptr)
	{
		h_group* tag_group;
		ASSERT(BCS_SUCCEEDED(get_group_by_group_tag(tag_file_index_entry.group_tag, tag_group)));
		char relative_filepath_mb[0x10000];
		sprintf(relative_filepath_mb, "%s.%s", tag_name, tag_group->tag_group.name);

		high_level_tag->tag_filename = filesystem_extract_filepath_filename(relative_filepath_mb);
		high_level_tag->tag_filepath = relative_filepath_mb;

		console_write_line_info("Read tag %s (%.2f ms)", relative_filepath_mb, ms);
		if (status_interface)
		{
			status_interface->set_status_bar_status(_status_interface_priority_low, 15.0f, "Read tag %s (%.2f ms)", relative_filepath_mb, ms);
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

union u_read_tags_callback_data
{
	struct // params
	{
		c_monolithic_tag_project* monolithic_tag_project;
	};
	struct // results
	{
		h_tag* high_level_tag;
		h_group* high_level_tag_group;
		BCS_RESULT result;
	};
};

void c_monolithic_tag_project::read_tags_callback(u_read_tags_callback_data* callback_data_array, long index)
{
	u_read_tags_callback_data& callback_data = callback_data_array[index];
	callback_data.result = callback_data.monolithic_tag_project->read_tag(index, callback_data.high_level_tag, callback_data.high_level_tag_group);
}

BCS_RESULT c_monolithic_tag_project::read_tags()
{
	BCS_RESULT rs = BCS_S_OK;

	c_stopwatch stopwatch;
	stopwatch.start();

	unsigned long compressed_entry_count = tag_file_index_chunk->tag_file_index_header.compressed_entry_count;
	const char* max_tag_index_string;
	if (BCS_SUCCEEDED(command_line_get_argument("maxtagindex", max_tag_index_string)))
	{
		unsigned long max_tag_index = strtoul(max_tag_index_string, nullptr, 10);
		if (max_tag_index > 0)
		{
			compressed_entry_count = __min(max_tag_index, compressed_entry_count);
		}
	}
	u_read_tags_callback_data* callback_data_array = new() u_read_tags_callback_data[compressed_entry_count];
	for (unsigned long callback_data_index = 0; callback_data_index < compressed_entry_count; callback_data_index++)
	{
		u_read_tags_callback_data& callback_data = callback_data_array[callback_data_index];
		callback_data.monolithic_tag_project = this;
		callback_data.result = BCS_S_CONTINUE;
	}

	const char* specific_tag_index_string;
	if (BCS_SUCCEEDED(command_line_get_argument("specifictagindex", specific_tag_index_string)))
	{
		unsigned long specific_tag_index = strtoul(specific_tag_index_string, nullptr, 10);

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

	for (unsigned long callback_data_index = 0; callback_data_index < compressed_entry_count; callback_data_index++)
	{
		u_read_tags_callback_data& callback_data = callback_data_array[callback_data_index];
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

BCS_RESULT c_monolithic_tag_project::get_tag_instances(h_tag* const*& tag_instances, unsigned long& tag_instance_count) const
{
	tag_instances = tags.data();
	tag_instance_count = static_cast<unsigned long>(tags.size());

	return BCS_S_OK;
}

BCS_RESULT c_monolithic_tag_project::get_tag_groups(h_group* const*& out_groups, unsigned long& out_group_count) const
{
	out_groups = groups.data();
	out_group_count = static_cast<unsigned long>(groups.size());

	return BCS_S_OK;
}
