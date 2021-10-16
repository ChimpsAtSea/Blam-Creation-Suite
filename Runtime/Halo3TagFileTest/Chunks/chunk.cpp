#include "halo3tagfiletest-private-pch.h"

#define _signature *reinterpret_cast<tag*>(static_cast<char*>(chunk_data))
#define _metadata *reinterpret_cast<unsigned long*>(static_cast<char*>(chunk_data) + 4)
#define _chunk_size *reinterpret_cast<unsigned long*>(static_cast<char*>(chunk_data) + 8)
c_chunk::c_chunk(void* chunk_data, c_chunk* parent) :
	chunk_data(static_cast<char*>(chunk_data)),
	children(nullptr),
	signature(_signature),
	metadata(_metadata),
	chunk_size(_chunk_size),
	depth(parent ? parent->depth + 1 : 0),
	children_fast_allocation(),
	chunk_data_begin(static_cast<char*>(chunk_data) + 12),
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

void c_chunk::log(c_string_data_chunk* string_data_chunk) const
{
	log_pad();
	log_impl(string_data_chunk);

	for (c_chunk** children_iter = children; children && *children_iter; children_iter++)
	{
		c_chunk& child = **children_iter;
		child.log(string_data_chunk);
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

void c_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_end_line_verbose();
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

void c_chunk::parse_children(void* userdata, char* data, bool force_fast)
{
	if (data == nullptr)
	{
		data = chunk_data_begin;
	}

	intptr_t bytes_to_parse = chunk_data_end - data;
	if (bytes_to_parse <= 0x10000 || force_fast)
	{
		children_fast_allocation = 1;
		children = create_child_chunks_fast(data, userdata);
		//children = create_child_chunks_slow(data, userdata);
	}
	else
	{
		children = create_child_chunks_slow(data, userdata);
	}
}

c_chunk** c_chunk::create_child_chunks_fast(char* data_start, void* userdata)
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

	for (char* data_position = data_start; data_position < chunk_data_end;)
	{
#define STACK_CHUNK_CTOR(t_structure, ...) \
		case t_structure::signature: \
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
		unsigned long& signature = *reinterpret_cast<unsigned long*>(data_position);
		switch (signature)
		{
			STACK_CHUNK_CTOR(c_tag_header_chunk, data_position);
			STACK_CHUNK_CTOR(c_tag_group_layout_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_tag_layout_v3_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_string_data_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_string_offsets_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_string_lists_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_custom_block_index_search_names_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_data_definition_name_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_array_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_tag_field_types_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_fields_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_block_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_resource_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_interop_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_structure_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_binary_data_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_tag_block_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			STACK_CHUNK_CTOR(c_tag_struct_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			STACK_CHUNK_CTOR(c_tag_string_id_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			STACK_CHUNK_CTOR(c_tag_reference_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			STACK_CHUNK_CTOR(c_tag_data_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
		default: FATAL_ERROR("Unknown tag file chunk signature");
		}
#undef STACK_CHUNK_CTOR
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

c_chunk** c_chunk::create_child_chunks_slow(char* data_start, void* userdata)
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

	for (char* data_position = data_start; data_position < chunk_data_end;)
	{
#define STACK_CHUNK_CTOR(t_structure, ...) \
		case t_structure::signature: \
		{ \
			s_stack_chunk_list_entry* chunk_list_entry = new s_stack_chunk_list_entry; \
			chunk_list_length++; \
			c_chunk* chunk = chunk_list_entry->chunk = new t_structure(__VA_ARGS__); \
			chunk_list_entry->previous = chunk_list_start; \
			chunk_list_start = chunk_list_entry; \
			data_position = chunk->chunk_data_end; \
			break; \
		}

		unsigned long& signature = *reinterpret_cast<unsigned long*>(data_position);
		switch (signature)
		{
			STACK_CHUNK_CTOR(c_tag_header_chunk, data_position);
			STACK_CHUNK_CTOR(c_tag_group_layout_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_tag_layout_v3_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_string_data_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_string_offsets_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_string_lists_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_custom_block_index_search_names_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_data_definition_name_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_array_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_tag_field_types_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_fields_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_block_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_resource_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_interop_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_structure_definitions_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_binary_data_chunk, data_position, *this);
			STACK_CHUNK_CTOR(c_tag_block_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			STACK_CHUNK_CTOR(c_tag_struct_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			STACK_CHUNK_CTOR(c_tag_string_id_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			STACK_CHUNK_CTOR(c_tag_reference_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
			STACK_CHUNK_CTOR(c_tag_data_chunk, data_position, *this, *static_cast<c_single_tag_file_reader*>(userdata));
		default: FATAL_ERROR("Unknown tag file chunk signature");
		}
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
