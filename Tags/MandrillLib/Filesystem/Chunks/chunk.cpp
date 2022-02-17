#include "mandrilllib-private-pch.h"

#define _signature *reinterpret_cast<const tag*>(static_cast<const char*>(chunk_data))
#define _metadata *reinterpret_cast<const unsigned long*>(static_cast<const char*>(chunk_data) + 4)
#define _chunk_size *reinterpret_cast<const unsigned long*>(static_cast<const char*>(chunk_data) + 8)
c_chunk::c_chunk(const void* chunk_data, c_chunk* parent, bool is_big_endian) :
	chunk_data(static_cast<const char*>(chunk_data)),
	children(nullptr),
	is_big_endian(is_big_endian),
	children_fast_allocation(),
	depth(parent ? parent->depth + 1 : 0),
	signature(chunk_byteswap(_signature)),
	metadata(chunk_byteswap(_metadata)),
	chunk_size(chunk_byteswap(_chunk_size)),
	chunk_data_begin(static_cast<const char*>(chunk_data) + 12),
	chunk_data_end(chunk_data_begin + chunk_size)
{
	
}
#undef _signature
#undef _metadata
#undef _chunk_size

c_chunk::~c_chunk()
{
	if (children != nullptr)
	{
		if (children_fast_allocation)
		{
			for (c_chunk** current_chunk = children; *current_chunk; current_chunk++)
			{
				(*current_chunk)->~c_chunk();
			}
		}
		else
		{
			for (c_chunk** current_chunk = children; *current_chunk; current_chunk++)
			{
				delete* current_chunk;
			}
		}
		delete children;
	}
}

void c_chunk::log(c_single_tag_file_layout_reader* layout_reader) const
{
	log_pad();
	log_impl(layout_reader);

	for (c_chunk** children_iter = children; children && *children_iter; children_iter++)
	{
		c_chunk& child = **children_iter;
		child.log(layout_reader);
	}
}

void c_chunk::log_pad() const
{
	for (unsigned long i = 0; i < depth; i++)
	{
		console_write_verbose("  ");
	}
}

void c_chunk::log_signature() const
{
	union
	{
		unsigned long _signature_byteswapped;
		char _signature[4];
	};
	_signature_byteswapped = _byteswap_ulong(signature);
	console_write_verbose("%.4s ", _signature);
}

void c_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_verbose("0x%X ", chunk_size);
	console_end_line_verbose();
}

unsigned long c_chunk::get_chunk_count() const
{
	unsigned long child_count = 0;
	for (c_chunk** children_iter = children; children_iter && *children_iter; children_iter++)
	{
		child_count++;
	}
	return child_count;
}

c_chunk* c_chunk::find_first_chunk(unsigned long type) const
{
	for (c_chunk** children_iter = children; children_iter && *children_iter; children_iter++)
	{
		c_chunk& child = **children_iter;
		if (child.signature == type)
		{
			return &child;
		}
	}
	for (c_chunk** children_iter = children; children_iter && *children_iter; children_iter++)
	{
		c_chunk& child = **children_iter;

		c_chunk* child_search_result = child.find_first_chunk(type);
		if (child_search_result)
		{
			return child_search_result;
		}
	}
	return nullptr;
}

c_chunk* c_chunk::get_chunk(unsigned long index) const
{
	return children[index];
}

void c_chunk::parse_children(void* userdata, const char* data, bool force_fast)
{
	if (data == nullptr)
	{
		data = chunk_data_begin;
	}

	//intptr_t bytes_to_parse = chunk_data_end - data;
	//if (bytes_to_parse <= 0x10000 || force_fast)
	//{
	//	children_fast_allocation = 1;
	//	children = create_child_chunks_fast(data, userdata);
	//	//children = create_child_chunks_slow(data, userdata);
	//}
	//else
	{
		children = create_child_chunks_slow(data, userdata);
	}
}

c_chunk** c_chunk::create_child_chunks_fast(const char* data_start, void* userdata)
{
#pragma pack(push, 1)
	struct s_stack_chunk_list_entry
	{
		s_stack_chunk_list_entry* previous;
		unsigned long chunk_size;
		char chunk_data[];
	};
#pragma pack(push, pop)
	s_stack_chunk_list_entry* chunk_list_start = nullptr;
	unsigned long chunk_list_length = 0;
	unsigned long chunk_list_data_size = 0;

	for (const char* data_position = data_start; data_position < chunk_data_end;)
	{
#define CHUNK_CTOR_EX(_signature, t_structure, ...) \
		case (_signature): \
		{ \
			DEBUG_ASSERT(signature == c_tag_header_chunk::signature || this != nullptr); \
			s_stack_chunk_list_entry* chunk_list_entry = (s_stack_chunk_list_entry*)alloca(sizeof(s_stack_chunk_list_entry) + sizeof(t_structure)); \
			chunk_list_length++; \
			chunk_list_entry->chunk_size = sizeof(t_structure); \
			chunk_list_data_size += sizeof(t_structure); \
			t_structure* chunk = new(chunk_list_entry->chunk_data) t_structure(__VA_ARGS__); \
			chunk_list_entry->previous = chunk_list_start; \
			chunk_list_start = chunk_list_entry; \
			data_position = chunk->chunk_data_end; \
			break; \
		}
#define CHUNK_CTOR(t_structure, ...) CHUNK_CTOR_EX(t_structure::signature, t_structure, __VA_ARGS__)
		unsigned long signature = chunk_byteswap(*reinterpret_cast<const unsigned long*>(data_position));
		if (signature == c_tag_layout_v3_chunk::signature)
		{
			s_tag_group_layout_header* tag_group_layout_header = static_cast<s_tag_group_layout_header*>(userdata);
			ASSERT(tag_group_layout_header != nullptr);
			switch (tag_group_layout_header->layout_version)
			{
				CHUNK_CTOR_EX(_tag_persist_layout_version_prechunk, c_tag_layout_prechunk_chunk, data_position, *this);
				CHUNK_CTOR_EX(_tag_persist_layout_version_preinterop, c_tag_layout_preinterop_chunk, data_position, *this);
				CHUNK_CTOR_EX(_tag_persist_layout_version_v3, c_tag_layout_v3_chunk, data_position, *this);
			}
		}
		else switch (signature)
		{
			CHUNK_CTOR(c_tag_header_chunk, data_position);
			CHUNK_CTOR(c_tag_group_layout_chunk, data_position, *this);
			CHUNK_CTOR(c_string_data_chunk, data_position, *this);
			CHUNK_CTOR(c_string_offsets_chunk, data_position, *this);
			CHUNK_CTOR(c_string_lists_chunk, data_position, *this);
			CHUNK_CTOR(c_custom_block_index_search_names_chunk, data_position, *this);
			CHUNK_CTOR(c_data_definition_name_chunk, data_position, *this);
			CHUNK_CTOR(c_array_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_field_types_chunk, data_position, *this);
			CHUNK_CTOR(c_fields_chunk, data_position, *this);
			CHUNK_CTOR(c_block_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_resource_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_interop_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_structure_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_binary_data_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_block_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_tag_struct_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_tag_string_id_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_tag_reference_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_tag_data_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_monolithic_tag_file_index_chunk, data_position, *this);
			CHUNK_CTOR(c_monolithic_index_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_file_index_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_heap_chunk, data_position, *this);
			CHUNK_CTOR(c_cache_heap_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_file_blocks_chunk, data_position, *this);
			CHUNK_CTOR(c_build_identifier_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_file_persistent_heap_chunk, data_position, *this);
			CHUNK_CTOR(c_partitioned_persistent_heap_backend_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_file_heap_partition_config_chunk, data_position, *this);
			CHUNK_CTOR(c_partition_list_chunk, data_position, *this);
			CHUNK_CTOR(c_partition_chunk, data_position, *this);
			CHUNK_CTOR(c_partitioned_heap_entry_list_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_dependency_index_loader_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_dependency_chunk, data_position, *this);
			CHUNK_CTOR(c_exploded_dependencies_chunk, data_position, *this);
			CHUNK_CTOR(c_optimized_dependencies_chunk, data_position, *this);
			CHUNK_CTOR(c_monolithic_tag_file_layout_registry_chunk, data_position, *this);
		default: FATAL_ERROR("Unknown tag file chunk signature");
		}
#undef CHUNK_CTOR
#undef CHUNK_CTOR_EX
	}

	c_chunk** chunk_pointers;
	// allocate memory and copy to heap
	{
		size_t chunk_pointer_list_size = sizeof(c_chunk*) * (chunk_list_length + 1);
		size_t chunk_allocation_size = chunk_pointer_list_size + chunk_list_data_size;

		char* chunk_data_allocation = new char[chunk_allocation_size];
		char* chunk_data_pos = chunk_data_allocation + chunk_pointer_list_size;
		chunk_pointers = reinterpret_cast<c_chunk**>(chunk_data_pos); // list stored in reverse

		*(--chunk_pointers) = nullptr;
		while (chunk_list_start)
		{
			c_chunk* chunk_data = (c_chunk*)(chunk_data_pos);
			memcpy(chunk_data, chunk_list_start->chunk_data, chunk_list_start->chunk_size);
			chunk_data_pos += chunk_list_start->chunk_size;
			*(--chunk_pointers) = chunk_data;
			chunk_list_start = chunk_list_start->previous;
		}

		ASSERT(static_cast<void*>(chunk_data_allocation) == static_cast<void*>(chunk_pointers));

		debug_point;
	}
	return chunk_pointers;
}

c_chunk** c_chunk::create_child_chunks_slow(const char* data_start, void* userdata)
{
#pragma pack(push, 1)
	struct s_stack_chunk_list_entry
	{
		s_stack_chunk_list_entry* previous;
		c_chunk* chunk;
	};
#pragma pack(push, pop)
	s_stack_chunk_list_entry* chunk_list_start = nullptr;
	unsigned long chunk_list_length = 0;

	for (const char* data_position = data_start; data_position < chunk_data_end;)
	{
#define CHUNK_CTOR_EX(_signature, t_structure, ...) \
		case (_signature): \
		{ \
			s_stack_chunk_list_entry* chunk_list_entry = new s_stack_chunk_list_entry; \
			chunk_list_length++; \
			c_chunk* chunk = chunk_list_entry->chunk = new t_structure(__VA_ARGS__); \
			chunk_list_entry->previous = chunk_list_start; \
			chunk_list_start = chunk_list_entry; \
			data_position = chunk->chunk_data_end; \
			break; \
		}
#define CHUNK_CTOR(t_structure, ...) CHUNK_CTOR_EX(t_structure::signature, t_structure, __VA_ARGS__)
		unsigned long signature = chunk_byteswap(*reinterpret_cast<const unsigned long*>(data_position));
		if (signature == c_tag_layout_v3_chunk::signature)
		{
			s_tag_group_layout_header* tag_group_layout_header = static_cast<s_tag_group_layout_header*>(userdata);
			ASSERT(tag_group_layout_header != nullptr);
			switch (tag_group_layout_header->layout_version)
			{
				CHUNK_CTOR_EX(_tag_persist_layout_version_prechunk, c_tag_layout_prechunk_chunk, data_position, *this);
				CHUNK_CTOR_EX(_tag_persist_layout_version_preinterop, c_tag_layout_preinterop_chunk, data_position, *this);
				CHUNK_CTOR_EX(_tag_persist_layout_version_v3, c_tag_layout_v3_chunk, data_position, *this);
			}
		}
		else switch (signature)
		{
			CHUNK_CTOR(c_tag_header_chunk, data_position);
			CHUNK_CTOR(c_tag_group_layout_chunk, data_position, *this);
			CHUNK_CTOR(c_string_data_chunk, data_position, *this);
			CHUNK_CTOR(c_string_offsets_chunk, data_position, *this);
			CHUNK_CTOR(c_string_lists_chunk, data_position, *this);
			CHUNK_CTOR(c_custom_block_index_search_names_chunk, data_position, *this);
			CHUNK_CTOR(c_data_definition_name_chunk, data_position, *this);
			CHUNK_CTOR(c_array_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_field_types_chunk, data_position, *this);
			CHUNK_CTOR(c_fields_chunk, data_position, *this);
			CHUNK_CTOR(c_block_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_resource_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_interop_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_structure_definitions_chunk, data_position, *this);
			CHUNK_CTOR(c_binary_data_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_block_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_tag_struct_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_tag_string_id_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_tag_reference_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_tag_data_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			CHUNK_CTOR(c_monolithic_tag_file_index_chunk, data_position, *this);
			CHUNK_CTOR(c_monolithic_index_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_file_index_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_heap_chunk, data_position, *this);
			CHUNK_CTOR(c_cache_heap_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_file_blocks_chunk, data_position, *this);
			CHUNK_CTOR(c_build_identifier_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_file_persistent_heap_chunk, data_position, *this);
			CHUNK_CTOR(c_partitioned_persistent_heap_backend_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_file_heap_partition_config_chunk, data_position, *this);
			CHUNK_CTOR(c_partition_list_chunk, data_position, *this);
			CHUNK_CTOR(c_partition_chunk, data_position, *this);
			CHUNK_CTOR(c_partitioned_heap_entry_list_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_dependency_index_loader_chunk, data_position, *this);
			CHUNK_CTOR(c_tag_dependency_chunk, data_position, *this);
			CHUNK_CTOR(c_exploded_dependencies_chunk, data_position, *this);
			CHUNK_CTOR(c_optimized_dependencies_chunk, data_position, *this);
			CHUNK_CTOR(c_monolithic_tag_file_layout_registry_chunk, data_position, *this);
			default: FATAL_ERROR("Unknown tag file chunk signature");
		}
#undef CHUNK_CTOR
#undef CHUNK_CTOR_EX
	}

	c_chunk** chunk_pointers;
	// allocate memory and copy to heap
	{
		c_chunk** chunk_pointers_alloc = chunk_pointers = new c_chunk * [chunk_list_length + 1];
		chunk_pointers += chunk_list_length + 1;

		*(--chunk_pointers) = nullptr;
		while (chunk_list_start)
		{
			s_stack_chunk_list_entry* current_chunk_list_entry = chunk_list_start;
			*(--chunk_pointers) = current_chunk_list_entry->chunk;
			chunk_list_start = current_chunk_list_entry->previous;
			delete current_chunk_list_entry;
		}

		ASSERT(chunk_pointers_alloc == chunk_pointers);

		debug_point;
	}
	return chunk_pointers;
}
