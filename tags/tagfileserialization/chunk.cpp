#include "tagfileserialization-private-pch.h"

template<> void byteswap_inplace(s_chunk_header_gen3& value)
{
	byteswap_inplace(value.signature);
	byteswap_inplace(value.metadata);
	byteswap_inplace(value.chunk_size);
}

c_chunk* const c_chunk::children_list_empty[1] = { nullptr };

c_chunk::c_chunk(tag _signature, c_chunk* _parent) :
	parent(_parent),
	children(const_cast<c_chunk**>(children_list_empty)),
	chunk_data(nullptr),
	chunk_size(0),
	metadata(),
	signature(_signature),
	is_read_only(false),
	is_big_endian(false),
	is_data_allocated(false),
	is_data_valid(false),
	depth(parent ? parent->depth + 1 : 0),
	num_children(0)
{

}

c_chunk::~c_chunk()
{
	if (is_data_allocated)
	{
		tracked_free(chunk_data);
	}

	if (num_children > 0)
	{
		for (c_chunk* const* current_chunk = children; *current_chunk; current_chunk++)
		{
			delete* current_chunk;
		}
		trivial_free(children);
	}
}

BCS_RESULT c_chunk::add_child(c_chunk& chunk)
{
	ASSERT(chunk.parent == nullptr || chunk.parent == this);
	chunk.parent = this;

	uint32_t old_child_count = num_children;
	uint32_t new_child_count = old_child_count + 1;

	c_chunk** new_children = trivial_malloc(c_chunk*, new_child_count + 1);
	memcpy(new_children, children, sizeof(*children) * old_child_count);

	new_children[old_child_count] = &chunk;
	new_children[new_child_count] = nullptr;

	// #TODO: is it okay to allow duplicate entries of the same pointer?

	if (num_children > 0)
	{
		trivial_free(children);
	}
	children = new_children;
	num_children = new_child_count;

	return BCS_S_OK;
}

BCS_RESULT c_chunk::remove_child(c_chunk& chunk)
{
	if (num_children >= 0)
	{
		uint32_t new_child_count = num_children;
		{
			for (c_chunk** current_chunk = children; *current_chunk; current_chunk++)
			{
				if (*current_chunk == &chunk)
				{
					delete* current_chunk;
					*current_chunk = nullptr;
					new_child_count--;
				}
			}
		}

		if (new_child_count < num_children)
		{
			c_chunk** new_children = trivial_malloc(c_chunk*, new_child_count + 1);
			{
				uint32_t destination_index = 0;
				for (uint32_t child_index = 0; child_index < num_children; child_index++)
				{
					c_chunk* current_chunk = children[child_index];
					if (current_chunk != &chunk)
					{
						new_children[destination_index] = current_chunk;
						destination_index++;
					}
				}
				new_children[new_child_count] = nullptr;
			}

			trivial_free(children);
			children = new_children;
			num_children = num_children;

			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_chunk::get_children(c_chunk* const*& out_children, uint32_t& out_num_children)
{
	if (children != nullptr)
	{
		out_children = children;
		out_num_children = num_children;
	}
	else
	{
		out_children = children_list_empty;
		out_num_children = 0;
	}
	return BCS_S_OK;
}

c_chunk* const* c_chunk::get_children_unsafe() const
{
	return children;
}

c_chunk* c_chunk::get_child_unsafe(uint32_t index) const
{
	ASSERT(index < num_children);
	return children[index];
}

c_chunk* c_chunk::get_child_by_signature_unsafe(tag signature, t_chunk_child_iterator* _iterator) const
{
	for (t_chunk_child_iterator iterator = _iterator != nullptr ? *_iterator : get_children_unsafe(); *iterator; iterator++)
	{
		c_chunk& child = **iterator;

		if (child.signature == signature)
		{
			return &child;
		}
	}
	return nullptr;
}

c_chunk* c_chunk::get_child_by_signature_recursive_unsafe(tag signature, t_chunk_child_iterator* _iterator) const
{
	if (c_chunk* child = get_child_by_signature_unsafe(signature, _iterator))
	{
		return child;
	}
	for (t_chunk_child_iterator iterator = _iterator != nullptr ? *_iterator : get_children_unsafe(); *iterator; iterator++)
	{
		c_chunk& child = **iterator;

		if (c_chunk* recursive_child = child.get_child_by_signature_unsafe(signature))
		{
			return recursive_child;
		}
	}
	return nullptr;
}

const char* c_chunk::get_chunk_data_start() const
{
	ASSERT(is_data_valid);
	return static_cast<const char*>(chunk_data);
}

const char* c_chunk::get_chunk_data_end() const
{
	ASSERT(is_data_valid);
	return static_cast<const char*>(chunk_data) + chunk_size;
}

BCS_RESULT c_chunk::append_data(const void* new_data, uint32_t new_data_size)
{
	if (!is_data_valid)
	{
		return set_data(new_data, new_data_size);
	}
	else if (new_data_size > 0)
	{
		uint32_t data_size = chunk_size + new_data_size;
		char* _chunk_data_temp = static_cast<char*>(tracked_malloc(data_size));

		char* old_chunk_data = _chunk_data_temp;
		memcpy(old_chunk_data, chunk_data, chunk_size);

		char* new_chunk_data = _chunk_data_temp + chunk_size;
		memcpy(new_chunk_data, new_data, new_data_size);

		set_data(_chunk_data_temp, data_size);

		tracked_free(_chunk_data_temp);
	}

	return BCS_S_OK;
}

BCS_RESULT c_chunk::set_data(const void* data, uint32_t data_size)
{
	if (is_data_allocated)
	{
		tracked_free(chunk_data);
	}

	void* _chunk_data = tracked_malloc(data_size);
	memcpy(_chunk_data, data, data_size);

	chunk_data = _chunk_data;
	chunk_size = data_size;

	is_data_valid = true;
	is_data_allocated = true;

	return BCS_S_OK;
}

BCS_RESULT c_chunk::get_data(const void*& data, uint32_t& data_size)
{
	if (chunk_data == nullptr)
	{
		return BCS_E_FAIL;
	}

	data = chunk_data;
	data_size = chunk_size;

	return BCS_S_OK;
}

BCS_RESULT c_chunk::read_chunk_header(void* userdata, const void* header_data)
{
	const s_chunk_header_gen3* chunk_header_pointer = static_cast<const s_chunk_header_gen3*>(header_data);

	is_big_endian = signature == byteswap(chunk_header_pointer->signature);

	s_chunk_header_gen3 chunk_header = *chunk_header_pointer;
	chunk_byteswap_inplace(chunk_header);
	ASSERT(chunk_header.signature == signature || signature == c_tag_layout_prechunk_chunk::k_signature);

	metadata = chunk_header.metadata;
	chunk_size = chunk_header.chunk_size;
	chunk_data = next_contiguous_pointer(char, chunk_header_pointer);
	is_data_valid = true;

	return BCS_S_OK;
}

BCS_RESULT c_chunk::read_chunk(
	void* userdata,
	const void* data,
	bool use_read_only,
	bool parse_children)
{
	BCS_VALIDATE_ARGUMENT(data);

	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = read_chunk_header(userdata, data)))
	{
		return rs;
	}

	if (!use_read_only)
	{
		set_data(chunk_data, chunk_size);
	}

	if (parse_children)
	{
		read_child_chunks(userdata, use_read_only);
	}

	return rs;
}

#pragma pack(push, 1)
//struct s_stack_chunk_list_entry2
//{
//	s_stack_chunk_list_entry* previous;
//	c_chunk* chunk;
//};
struct s_stack_chunk_list_entry
{
	//s_stack_chunk_list_entry* previous;
	c_chunk* chunk;
};
using t_stack_chunk_list_entry = c_chunk;
#pragma pack(push, pop)

constexpr uint32_t _max_size = 0x80000;
constexpr uint32_t _chunk_count = 1024;
constexpr uint32_t k_fixed_chunk = 1;
constexpr uint32_t k_dynamic_chunks = _max_size / _chunk_count;
constexpr bool k_simple_alloc = __is_trivially_constructible(s_stack_chunk_list_entry) && __is_trivially_copyable(s_stack_chunk_list_entry);
class c_dynamic_chunked_array
{
public:
	uint32_t current_size;
	s_stack_chunk_list_entry* entries[k_dynamic_chunks];
	s_stack_chunk_list_entry fixed_entries[_chunk_count];

	c_dynamic_chunked_array() :
		current_size(0),
		entries{ fixed_entries }
	{

	}

	BCS_SHARED ~c_dynamic_chunked_array()
	{
		uint32_t chunks = current_size / _chunk_count;
		for (uint32_t chunk_index = 1; chunk_index < chunks; chunk_index++)
		{
			if constexpr (k_simple_alloc)
			{
				tracked_free(entries[chunk_index]);
			}
			else
			{
				delete[] entries[chunk_index];
			}
		}
	}

	uint32_t get_size()
	{
		return current_size;
	}

	s_stack_chunk_list_entry& operator[](uint32_t index)
	{
		ASSERT(index < current_size);
		uint32_t chunk = index / _chunk_count;
		uint32_t chunk_index = index % _chunk_count;

		return entries[chunk][chunk_index];
	}

	s_stack_chunk_list_entry& emplace_back()
	{
		uint32_t index = current_size;
		uint32_t chunk = index / _chunk_count;
		uint32_t chunk_index = index % _chunk_count;

		s_stack_chunk_list_entry*& entry = entries[chunk];
		if (entry == nullptr)
		{
			if constexpr (k_simple_alloc)
			{
				entry = static_cast<s_stack_chunk_list_entry*>(tracked_malloc(sizeof(s_stack_chunk_list_entry) * _chunk_count));
			}
			else
			{
				entry = new s_stack_chunk_list_entry[_chunk_count];
			}
		}

		current_size++;

		return entries[chunk][chunk_index];
	}
};

BCS_RESULT c_chunk::read_child_chunks(void* userdata, bool use_read_only, const char* data_start)
{
	BCS_RESULT rs = BCS_S_OK;

	if (data_start == nullptr)
	{
		data_start = get_chunk_data_start();
	}
	ASSERT(data_start != nullptr);

	try
	{
		c_hybrid_chunked_resizable_array<c_chunk*, 1024, 1024, 512> chunk_list;

		const void* chunk_data_end = get_chunk_data_end();
		for (const char* data_position = data_start; data_position < chunk_data_end;)
		{
			tag next_signature = *reinterpret_cast<const tag*>(data_position);
			chunk_byteswap_inplace(next_signature);

			//const s_chunk_header_gen3* chunk_header_pointer = reinterpret_cast<const s_chunk_header_gen3*>(data_position);
			//uint32_t next_signature = chunk_byteswap(chunk_header_pointer->signature);
			//uint32_t chunk_size = chunk_byteswap(chunk_header_pointer->chunk_size) + sizeof(s_chunk_header_gen3);

#define CHUNK_CTOR_EX(_signature, t_structure, ...) \
		case (_signature): \
		{ \
			c_chunk*& chunk_storage = chunk_list.emplace_back(); \
			t_structure* chunk = new() t_structure(__VA_ARGS__); \
			chunk_storage = chunk; \
			chunk->read_chunk(userdata, data_position, use_read_only, t_structure::k_should_parse_children); \
			/*data_position += chunk_size;*/ \
			data_position = chunk->get_chunk_data_end(); \
			break; \
		}

#define CHUNK_CTOR(t_structure, ...) CHUNK_CTOR_EX(t_structure::k_signature, t_structure, __VA_ARGS__)
			if (next_signature == c_tag_layout_v3_chunk::k_signature)
			{
				s_tag_group_layout_header* tag_group_layout_header = static_cast<s_tag_group_layout_header*>(userdata);
				ASSERT(tag_group_layout_header != nullptr);
				switch (tag_group_layout_header->layout_version)
				{
					CHUNK_CTOR_EX(_tag_persist_layout_version_prechunk, c_tag_layout_prechunk_chunk, *this);
					CHUNK_CTOR_EX(_tag_persist_layout_version_preinterop, c_tag_layout_preinterop_chunk, *this);
					CHUNK_CTOR_EX(_tag_persist_layout_version_v3, c_tag_layout_v3_chunk, *this);
				}
			}
			else switch (next_signature)
			{
				CHUNK_CTOR(c_tag_block_chunk, *this);
				CHUNK_CTOR(c_tag_struct_chunk, *this);
				CHUNK_CTOR(c_tag_group_layout_chunk, *this);
				CHUNK_CTOR(c_tag_string_id_chunk, *this);
				CHUNK_CTOR(c_tag_data_chunk, *this);
				CHUNK_CTOR(c_tag_reference_chunk, *this);
				CHUNK_CTOR(c_tag_resource_null_chunk, *this);
				CHUNK_CTOR(c_string_data_chunk, *this);
				CHUNK_CTOR(c_string_offsets_chunk, *this);
				CHUNK_CTOR(c_string_lists_chunk, *this);
				CHUNK_CTOR(c_custom_block_index_search_names_chunk, *this);
				CHUNK_CTOR(c_data_definition_name_chunk, *this);
				CHUNK_CTOR(c_array_definitions_chunk, *this);
				CHUNK_CTOR(c_field_types_chunk, *this);
				CHUNK_CTOR(c_fields_chunk, *this);
				CHUNK_CTOR(c_block_definitions_chunk, *this);
				CHUNK_CTOR(c_resource_definitions_chunk, *this);
				CHUNK_CTOR(c_interop_definitions_chunk, *this);
				CHUNK_CTOR(c_structure_definitions_chunk, *this);
				CHUNK_CTOR(c_binary_data_chunk, *this);
				CHUNK_CTOR(c_tag_resource_exploded_chunk, *this);
				CHUNK_CTOR(c_tag_resource_data_chunk, *this);
				CHUNK_CTOR(c_tag_resource_xsynced_chunk, *this);
				CHUNK_CTOR(c_tag_header_chunk);
				CHUNK_CTOR(c_monolithic_tag_file_index_chunk, *this);
				CHUNK_CTOR(c_monolithic_index_chunk, *this);
				CHUNK_CTOR(c_tag_file_index_chunk, *this);
				CHUNK_CTOR(c_tag_heap_chunk, *this);
				CHUNK_CTOR(c_cache_heap_chunk, *this);
				CHUNK_CTOR(c_tag_file_blocks_chunk, *this);
				CHUNK_CTOR(c_build_identifier_chunk, *this);
				CHUNK_CTOR(c_tag_file_persistent_heap_chunk, *this);
				CHUNK_CTOR(c_partitioned_persistent_heap_backend_chunk, *this);
				CHUNK_CTOR(c_tag_file_heap_partition_config_chunk, *this);
				CHUNK_CTOR(c_partition_list_chunk, *this);
				CHUNK_CTOR(c_partition_chunk, *this);
				CHUNK_CTOR(c_partitioned_heap_entry_list_chunk, *this);
				CHUNK_CTOR(c_tag_dependency_index_loader_chunk, *this);
				CHUNK_CTOR(c_tag_dependency_chunk, *this);
				CHUNK_CTOR(c_exploded_dependencies_chunk, *this);
				CHUNK_CTOR(c_optimized_dependencies_chunk, *this);
				CHUNK_CTOR(c_monolithic_tag_file_layout_registry_chunk, *this);
			default: FATAL_ERROR("Unknown tag file chunk signature");
			}
#undef CHUNK_CTOR
#undef CHUNK_CTOR_EX
		}

		uint32_t chunk_list_length = chunk_list.size;
		if (chunk_list_length > 0)
		{
			c_chunk** chunk_pointers = trivial_malloc(c_chunk*, chunk_list_length + 1);
			chunk_pointers[chunk_list_length] = 0;

			for (uint32_t chunk_index = 0; chunk_index < chunk_list_length; chunk_index++)
			{
				c_chunk* chunk = chunk_list[chunk_index];
				chunk_pointers[chunk_index] = chunk;
			}

			children = chunk_pointers;
		}
		else
		{
			children = const_cast<c_chunk**>(children_list_empty);
		}
		num_children = chunk_list_length;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return rs;
}

void c_chunk::log(c_tag_file_string_debugger* string_debugger) const
{
	if (!console_is_verbose())
	{
		return;
	}

	log_pad();
	log_impl(string_debugger);

	for (c_chunk** children_iter = children; children && *children_iter; children_iter++)
	{
		c_chunk& child = **children_iter;
		child.log(string_debugger);
	}
}

void c_chunk::log_pad() const
{
	for (uint32_t i = 0; i < depth; i++)
	{
		console_write_verbose("  ");
	}
}

void c_chunk::log_signature() const
{
	union
	{
		uint32_t _signature_byteswapped;
		char _signature[4];
	};
	_signature_byteswapped = _byteswap_ulong(signature);
	console_write_verbose("%.4s ", _signature);
}

void c_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_verbose("0x%X ", chunk_size);
	console_end_line_verbose();
}
