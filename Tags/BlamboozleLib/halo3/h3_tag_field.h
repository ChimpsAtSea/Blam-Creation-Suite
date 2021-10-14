#pragma once

struct s_h3_tag_field
{
	e_h3_field_type field_type;
	ptr64 name_address;
	ptr64 definition_address;
	unsigned long meta;
};

class c_h3_tag_block_definition;
class c_h3_tag_reference_definition;
class c_h3_tag_array_definition;
class c_h3_tag_struct_definition;
class c_h3_tag_pageable_resource_definition;

class c_h3_tag_field
{
public:
	const char* name;
	const char* definition;
	const e_h3_field_type& field_type;
	const ptr64& name_address;
	const ptr64& definition_address;

	c_h3_tag_block_definition* block_definition;
	c_h3_tag_reference_definition* tag_reference_definition;
	c_h3_tag_struct_definition* struct_definition;
	c_h3_tag_array_definition* array_definition;
	c_h3_string_list_definition* string_list_definition;
	c_h3_tag_pageable_resource_definition* pageable_resource_definition;

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

	c_h3_tag_field(const char* guerilla_data, const s_h3_tag_field& field_definition);
};
