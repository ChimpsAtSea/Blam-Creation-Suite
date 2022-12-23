#pragma once

class c_tag_file_heap_partition_config_chunk : public c_typed_chunk<'prpf', false>
{
public:
	uint32_t string_length;
	char* string;

	BCS_SHARED c_tag_file_heap_partition_config_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_file_heap_partition_config_chunk();
	BCS_SHARED BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
};
