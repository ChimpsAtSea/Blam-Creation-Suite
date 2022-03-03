#include "mandrilllib-private-pch.h"


c_chunk* root_chunk;

c_tag_file_index_chunk* tag_file_index_chunk;
c_tag_file_blocks_chunk* tag_file_blocks_chunk;

c_tag_heap_chunk* tag_heap_chunk;
c_partitioned_heap_entry_list_chunk* tag_heap_list_chunk;
c_partition_list_chunk* tag_partition_list_chunk;

c_cache_heap_chunk* cache_heap_chunk;
c_partitioned_heap_entry_list_chunk* cache_heap_list_chunk;
c_partition_list_chunk* cache_partition_list_chunk;

c_monolithic_tag_project::c_monolithic_tag_project(const wchar_t* directory, s_engine_platform_build engine_platform_build) :
	c_tag_project(engine_platform_build),
	groups(),
	tags(),
	num_tag_partitions(),
	tag_memory_mapped_files(),
	tag_memory_mapped_file_infos(),
	num_cache_partitions(),
	cache_memory_mapped_files(),
	cache_memory_mapped_file_infos()
{
	for (const blofeld::s_tag_group** tag_group_iter = blofeld::tag_groups[engine_platform_build.engine_type]; *tag_group_iter; tag_group_iter++)
	{
		h_group* group = new() h_group(engine_platform_build, **tag_group_iter);
		groups.push_back(group);
		debug_point;
	}

	wcscpy(tag_cache_directory, directory);
	wcscat(tag_cache_directory, L"tag_cache\\");
	wcscpy(blob_index_file_path, tag_cache_directory);
	wcscat(blob_index_file_path, L"blob_index.dat");


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

	parse_tag_blob(tag_file_data, tag_file_data_size);
	init_monolithic_tag_file_views();
	init_monolithic_cache_file_views();
	read_tags();

	delete root_chunk;
	tracked_free(tag_file_data);

	stopwatch.stop();
	float tag_parse_time = stopwatch.get_miliseconds();

	debug_point;
}

c_monolithic_tag_project::~c_monolithic_tag_project()
{
	ASSERT_NO_THROW(BCS_SUCCEEDED(deinit_monolithic_tag_file_views()));
	ASSERT_NO_THROW(BCS_SUCCEEDED(deinit_monolithic_cache_file_views()));

	for (h_tag* tag : tags)
	{
		delete tag;
	}

	for (h_group* group : groups)
	{
		delete group;
	}
}

BCS_RESULT c_monolithic_tag_project::init_monolithic_tag_file_views()
{
	BCS_RESULT rs = BCS_S_OK;

	num_tag_partitions = tag_partition_list_chunk->get_chunk_count();
	tag_memory_mapped_files = new() t_memory_mapped_file * [num_tag_partitions];
	tag_memory_mapped_file_infos = new() s_memory_mapped_file_info[num_tag_partitions];

	for (unsigned long tag_partition_index = 0; tag_partition_index < num_tag_partitions; tag_partition_index++)
	{
		c_partition_chunk* partition_chunk = dynamic_cast<c_partition_chunk*>(tag_partition_list_chunk->children[tag_partition_index]);
		ASSERT(partition_chunk != nullptr);
		ASSERT(partition_chunk->partition_header.file_index == tag_partition_index);

		wchar_t partition_filepath[0x10000];
		swprintf(partition_filepath, _countof(partition_filepath), L"%sblobs\\tags_%i", tag_cache_directory, partition_chunk->partition_header.file_index);

		t_memory_mapped_file*& tag_memory_mapped_file = tag_memory_mapped_files[tag_partition_index];
		s_memory_mapped_file_info& tag_memory_mapped_file_info = tag_memory_mapped_file_infos[tag_partition_index];

		if (BCS_FAILED(rs = create_memory_mapped_file(partition_filepath, true, tag_memory_mapped_file)))
		{
			return rs;
		}

		if (BCS_FAILED(rs = get_memory_mapped_file_info(tag_memory_mapped_file, tag_memory_mapped_file_info)))
		{
			return rs;
		}
	}

	return rs;
}

BCS_RESULT c_monolithic_tag_project::init_monolithic_cache_file_views()
{
	BCS_RESULT rs = BCS_S_OK;

	num_cache_partitions = cache_partition_list_chunk->get_chunk_count();
	cache_memory_mapped_files = new() t_memory_mapped_file * [num_cache_partitions];
	cache_memory_mapped_file_infos = new() s_memory_mapped_file_info[num_cache_partitions];

	for (unsigned long cache_partition_index = 0; cache_partition_index < num_cache_partitions; cache_partition_index++)
	{
		c_partition_chunk* partition_chunk = dynamic_cast<c_partition_chunk*>(cache_partition_list_chunk->children[cache_partition_index]);
		ASSERT(partition_chunk != nullptr);
		ASSERT(partition_chunk->partition_header.file_index == cache_partition_index);

		wchar_t partition_filepath[0x10000];
		swprintf(partition_filepath, _countof(partition_filepath), L"%sblobs\\cache_%i", tag_cache_directory, partition_chunk->partition_header.file_index);

		t_memory_mapped_file*& cache_memory_mapped_file = cache_memory_mapped_files[cache_partition_index];
		s_memory_mapped_file_info& cache_memory_mapped_file_info = cache_memory_mapped_file_infos[cache_partition_index];

		if (BCS_FAILED(rs = create_memory_mapped_file(partition_filepath, true, cache_memory_mapped_file)))
		{
			return rs;
		}

		if(BCS_FAILED(rs = get_memory_mapped_file_info(cache_memory_mapped_file, cache_memory_mapped_file_info)))
		{
			return rs;
		}
	}

	return rs;
}

BCS_RESULT c_monolithic_tag_project::deinit_monolithic_tag_file_views()
{
	BCS_RESULT rs = BCS_S_OK;

	for (unsigned long tag_partition_index = 0; tag_partition_index < num_tag_partitions; tag_partition_index++)
	{
		t_memory_mapped_file*& tag_memory_mapped_file = tag_memory_mapped_files[tag_partition_index];

		if (BCS_FAILED(rs = destroy_memory_mapped_file(tag_memory_mapped_file)))
		{
			return rs;
		}
	}

	delete[] tag_memory_mapped_files;
	delete[] tag_memory_mapped_file_infos;

	return rs;
}

BCS_RESULT c_monolithic_tag_project::deinit_monolithic_cache_file_views()
{
	BCS_RESULT rs = BCS_S_OK;

	for (unsigned long cache_partition_index = 0; cache_partition_index < num_cache_partitions; cache_partition_index++)
	{
		t_memory_mapped_file*& cache_memory_mapped_file = cache_memory_mapped_files[cache_partition_index];

		if (BCS_FAILED(rs = destroy_memory_mapped_file(cache_memory_mapped_file)))
		{
			return rs;
		}
	}

	delete[] cache_memory_mapped_files;
	delete[] cache_memory_mapped_file_infos;

	return rs;
}

BCS_RESULT c_monolithic_tag_project::parse_tag_blob(const void* tag_file_data, unsigned long long tag_file_data_size)
{
	BCS_RESULT rs = BCS_S_OK;

	const blofeld::s_tag_persistent_identifier* session_identifier = static_cast<const blofeld::s_tag_persistent_identifier*>(tag_file_data);

	root_chunk = new() c_monolithic_tag_backend_chunk(next_contiguous_pointer(session_identifier));

	root_chunk->parse_children(this, nullptr, true);

	tag_file_index_chunk = root_chunk->find_first_chunk<c_tag_file_index_chunk>();
	tag_file_blocks_chunk = root_chunk->find_first_chunk<c_tag_file_blocks_chunk>();

	tag_heap_chunk = root_chunk->find_first_chunk<c_tag_heap_chunk>();
	tag_heap_list_chunk = tag_heap_chunk->find_first_chunk<c_partitioned_heap_entry_list_chunk>();
	tag_partition_list_chunk = tag_heap_chunk->find_first_chunk<c_partition_list_chunk>();

	cache_heap_chunk = root_chunk->find_first_chunk<c_cache_heap_chunk>();
	cache_heap_list_chunk = cache_heap_chunk->find_first_chunk<c_partitioned_heap_entry_list_chunk>();
	cache_partition_list_chunk = cache_heap_chunk->find_first_chunk<c_partition_list_chunk>();

	root_chunk->log();

	debug_point;

	return rs;
}

BCS_RESULT c_monolithic_tag_project::read_tags()
{
	BCS_RESULT rs = BCS_S_OK;

	for (unsigned long index = 0; index < tag_file_index_chunk->tag_file_index_header.compressed_entry_count; index++)
	{
		s_compressed_tag_file_index_entry& tag_file_index_entry = tag_file_index_chunk->compressed_tag_file_index_entries[index];

		const char* tag_name = tag_file_index_chunk->name_buffer + tag_file_index_entry.name_offset;

		if (tag_file_index_entry.wide_block_index == 0xFFFFFFFF)
		{
			continue;
		}

		if (tag_file_index_entry.wide_block_datum_index == 0xFFFFFFFF)
		{
			continue;
		}

		unsigned short wide_block_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(tag_file_index_entry.wide_block_index);
		unsigned short wide_block_datum_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(tag_file_index_entry.wide_block_datum_index);

		unsigned long wide_data_cache_block_index = wide_block_index * 0xFFFFu + wide_block_datum_index;
		ASSERT(wide_data_cache_block_index < tag_file_blocks_chunk->num_wide_data_cache_blocks);

		s_wide_data_cache_block& wide_data_cache_block = tag_file_blocks_chunk->wide_data_cache_blocks[wide_data_cache_block_index];

		ASSERT(wide_data_cache_block.current_datum == tag_file_index_entry.wide_block_datum_index);

		const void* tag_file_data = nullptr;
		unsigned long long tag_file_data_size = 0;
		if (wide_data_cache_block.tag_heap_entry_index != 0xFFFFFFFF)
		{
			s_partitioned_heap_entry& tag_heap_entry = tag_heap_list_chunk->entries[wide_data_cache_block.tag_heap_entry_index];
			c_partition_chunk* partition_chunk = dynamic_cast<c_partition_chunk*>(tag_partition_list_chunk->children[tag_heap_entry.partition_index]);
			ASSERT(partition_chunk != nullptr);
			ASSERT(partition_chunk->partition_header.file_index == tag_heap_entry.partition_index);

			unsigned short heap_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(tag_heap_entry.heap_datum);
			s_lruv_cache_block_ex& lruv_cache_block = partition_chunk->lruv_cache_blocks[heap_index];

			s_memory_mapped_file_info& file_info = tag_memory_mapped_file_infos[tag_heap_entry.partition_index];

			char* data = file_info.file_view_begin + lruv_cache_block.offset;

			h_group* tag_group;
			ASSERT(BCS_SUCCEEDED(get_group_by_group_tag(tag_file_index_entry.group_tag, tag_group)));

			wchar_t tag_filepath_buf[0x10000];
			swprintf(tag_filepath_buf, _countof(tag_filepath_buf), L"tags\\%S.%S", tag_name, tag_group->tag_group.name);
			wchar_t* tag_filepath2 = const_cast<wchar_t*>(filesystem_extract_filepath_filename(tag_filepath_buf));
			tag_filepath2[wcslen(tag_filepath2) - strlen("_group")] = 0;

			wchar_t tag_filepath[0x10000];
			swprintf(tag_filepath, _countof(tag_filepath), L"tags\\%s", tag_filepath2);

			//ASSERT(BCS_SUCCEEDED(filesystem_write_file_from_memory(tag_filepath, data, lruv_cache_block.size)));

			debug_point;

			tag_file_data = data;
			tag_file_data_size = lruv_cache_block.size;
		}

		if (wide_data_cache_block.cache_heap_entry_index != 0xFFFFFFFF)
		{
			s_partitioned_heap_entry& cache_heap_entry = cache_heap_list_chunk->entries[wide_data_cache_block.cache_heap_entry_index];
			c_partition_chunk* partition_chunk = dynamic_cast<c_partition_chunk*>(cache_partition_list_chunk->children[cache_heap_entry.partition_index]);
			ASSERT(partition_chunk != nullptr);
			ASSERT(partition_chunk->partition_header.file_index == cache_heap_entry.partition_index);

			unsigned short heap_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(cache_heap_entry.heap_datum);
			s_lruv_cache_block_ex& lruv_cache_block = partition_chunk->lruv_cache_blocks[heap_index];

			debug_point;
		}

		c_stopwatch s;
		s.start();

		h_tag* high_level_tag = nullptr;
		if (wide_data_cache_block.tag_heap_entry_index != 0xFFFFFFFF)
		{
			ASSERT(tag_file_data_size > (sizeof(s_single_tag_file_header) + sizeof(tag)));

			const s_single_tag_file_header* src_header = static_cast<const s_single_tag_file_header*>(tag_file_data);
			bool is_little_endian_tag = src_header->blam == 'BLAM';
			bool is_big_endian_tag = byteswap(src_header->blam) == 'BLAM';
			ASSERT(is_little_endian_tag || is_big_endian_tag);

			s_single_tag_file_header header = *src_header;
			if (is_big_endian_tag)
			{
				byteswap_inplace(header);
			}


			c_single_tag_file_layout_reader* layout_reader = new() c_single_tag_file_layout_reader(header, tag_file_data);

			c_single_tag_file_reader*  reader = new() c_single_tag_file_reader(
				header,
				engine_platform_build,
				*layout_reader,
				*layout_reader->binary_data_chunk);


			//tag_group_layout_chunk->log(layout_reader->string_data_chunk);
			//binary_data_chunk->log(layout_reader->string_data_chunk);

			reader->parse_high_level_object(high_level_tag);
			debug_point;

			delete reader;
			delete layout_reader;
		}

		s.stop();
		float ms = s.get_miliseconds();
		console_write_line_verbose("Processed chunks in %.2f ms", ms);

		if (high_level_tag)
		{
			h_group* tag_group;
			ASSERT(BCS_SUCCEEDED(get_group_by_group_tag(tag_file_index_entry.group_tag, tag_group)));
			char relative_filepath_mb[0x10000];
			sprintf(relative_filepath_mb, "%s.%s", tag_name, tag_group->tag_group.name);

			high_level_tag->tag_filename = filesystem_extract_filepath_filename(relative_filepath_mb);
			high_level_tag->tag_filepath = relative_filepath_mb;

			tag_group->associate_tag_instance(*high_level_tag);
			debug_point;

			console_write_line("Read tag %s (%.2f ms)", relative_filepath_mb, ms);
		}

		debug_point;

		//break;

	}

	debug_point;

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
