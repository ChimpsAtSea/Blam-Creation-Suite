#pragma once

class c_reach_x360_tag_struct_definition;
class c_reach_x360_tag_group_definition;

struct s_reach_x360_tag_struct_persistent_identifier
{
	bulong data[4];
};

struct s_reach_x360_tag_struct_definition
{
	bptr32 pretty_name_address;
	bptr32 name_address;
	bptr32 filepath_address;
	blong line_number;
	s_reach_x360_tag_struct_persistent_identifier persistent_identifier;
	bptr32 fields_address;
	bulong structure_size;
	bptr32 size_string_address; // not included in release build
	bptr32 unknown;
	bulong unknown1;
	bulong unknown2;
	bulong alignment_bits;
	// ...
};
constexpr size_t k_reach_x360_tag_struct_definition_size = sizeof(s_reach_x360_tag_struct_definition);
////static_assert(k_reach_x360_tag_struct_definition_size == 200);

class c_reach_x360_tag_struct_definition
{
public:
	std::string pretty_name;
	std::string name;
	std::string code_name;
	unsigned long structure_size;
	unsigned long alignment_bits;
	s_reach_x360_tag_struct_persistent_identifier persistent_identifier;
	const s_reach_x360_tag_struct_definition& struct_definition;

	//c_reach_x360_tag_block_definition* block_definition;
	//c_reach_x360_tag_array_definition* array_definition;

	std::vector<c_reach_x360_tag_field*> fields;

	c_reach_x360_tag_struct_definition(const char* guerilla_data, const s_reach_x360_tag_struct_definition& definition_header);
	~c_reach_x360_tag_struct_definition();

	static std::map<ptr32, c_reach_x360_tag_struct_definition*> tag_struct_definitions;
	static c_reach_x360_tag_struct_definition* reach_x360_get_tag_struct_definition(const char* guerilla_data, ptr32 virtual_address);
};

