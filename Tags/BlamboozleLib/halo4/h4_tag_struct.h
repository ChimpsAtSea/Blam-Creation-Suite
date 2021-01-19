#pragma once

class c_h4_blamboozle;
class c_h4_tag_field;
struct s_h4_tag_field_definition;
struct s_h4_tag_struct_definition;

enum e_h4_tag_memory_type : unsigned long
{
	_h4_tag_memory_node = 1
};

enum e_h4_tag_memory_usage_bit : unsigned long
{
	_h4_tag_memory_physical_bit = 0,
	_h4_tag_memory_writeable_bit = 3,
	_h4_tag_memory_combined_bit = 4,
	_h4_tag_memory_streaming_bit = 5,
	_h4_tag_memory_non_aliased_bit = 6,
	k_num_tag_memory_usage_bits = 7
};

enum e_h4_runtime_flags_bit : unsigned long
{
	_h4_runtime_flags_is_built_from_disk = 6,
	_h4_runtime_flags_no_children_with_resources = 13, // cannot have any children with resources
	_h4_runtime_flags_no_children_with_level_specific_data = 16, // cannot have any children that are level specific (string_ids, tag_references)
};

struct c_h4_tag_memory_attributes
{
	e_h4_tag_memory_type memory_type;
	e_h4_tag_memory_usage_bit usage_flags;
};

struct s_tag_persistent_identifier
{
	int32_t data[4];
};

class c_h4_tag_struct
{
public:
	friend class c_h4_blamboozle;

	const char* const pretty_name;
	const char* const name;
	const char* const filepath;
	uint32_t const line_number;
	const s_h4_tag_field_definition* const fields;
	const s_h4_tag_struct_definition* const struct_header;
	uint32_t const size;
	const char* const size_string;
	uint32_t const alignment_bits;
	uint32_t legacy_struct_tag[3];
	std::vector<c_h4_tag_field*> tag_fields;
	uint32_t offset;
	e_h4_runtime_flags_bit const runtime_flags;
	c_h4_tag_memory_attributes memory_attributes;
	s_tag_persistent_identifier persistent_identifier;

protected:
	c_h4_tag_struct(const char* h4_data, const s_h4_tag_struct_definition* struct_header, uint32_t offset);
};