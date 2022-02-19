#pragma once

struct s_reach_x360_tag_field
{
	bigendian_type<e_reach_x360_field_type> field_type;
	bptr32 name_address;
	bptr32 definition_address;
	bulong meta;
};

class c_reach_x360_tag_block_definition;
class c_reach_x360_tag_reference_definition;
class c_reach_x360_tag_array_definition;
class c_reach_x360_tag_struct_definition;
class c_reach_x360_tag_pageable_resource_definition;
class c_reach_x360_tag_data_definition;
class c_reach_x360_tag_api_interop_definition;

using t_reach_x360_tag_field = t_virtual;

class c_reach_x360_tag_field :
	public t_reach_x360_tag_field
{
public:
	const char* name;
	const char* definition;
	const e_reach_x360_field_type field_type;
	const ptr32 name_address;
	const ptr32 definition_address;

	c_reach_x360_tag_block_definition* block_definition;
	c_reach_x360_tag_reference_definition* tag_reference_definition;
	c_reach_x360_tag_struct_definition* struct_definition;
	c_reach_x360_tag_array_definition* array_definition;
	c_reach_x360_string_list_definition* string_list_definition;
	c_reach_x360_tag_pageable_resource_definition* pageable_resource_definition;
	c_reach_x360_tag_data_definition* data_definition;
	c_reach_x360_tag_api_interop_definition* api_interop_definition;

	unsigned long long padding;
	unsigned long long skip_length;
	const char* explanation;
	blofeld::e_field_id field_id;
	const char* field_id_string;
	union
	{
		unsigned long long _field_id_byteswap;
		char field_id_short_string[sizeof(unsigned long long)];
	};

	c_reach_x360_tag_field(const char* guerilla_data, const s_reach_x360_tag_field& field_definition);
};

class c_reach_x360_tag_field_combined_fixup :
	public t_reach_x360_tag_field
{
public:
	c_reach_x360_tag_group_definition& group_definition;
	unsigned long count;

	c_reach_x360_tag_field_combined_fixup(c_reach_x360_tag_group_definition& group_definition, unsigned long count);
};

class c_reach_x360_tag_field_dummy_space :
	public t_reach_x360_tag_field
{
public:
};

