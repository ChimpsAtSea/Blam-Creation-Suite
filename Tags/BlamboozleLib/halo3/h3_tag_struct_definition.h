#pragma once

class c_h3_tag_struct_definition;
class c_h3_tag_group_definition;

struct s_h3_tag_struct_persistent_identifier
{
	unsigned long data[4];
};

struct s_h3_tag_struct_definition
{
	ptr64 pretty_name_address;
	ptr64 name_address;
	ptr64 filepath_address;
	long line_number;
	long padding;
	s_h3_tag_struct_persistent_identifier persistent_identifier;
	ptr64 fields_address;
	unsigned long structure_size;
	ptr64 size_string_address; // not included in release build
	ptr64 unknown;
	unsigned long unknown1;
	unsigned long unknown2;
	unsigned long alignment_bits;
	unsigned long long unk[17];
};
constexpr size_t k_h3_tag_struct_definition_size = sizeof(s_h3_tag_struct_definition);
//static_assert(k_h3_tag_struct_definition_size == 200);

class c_h3_tag_struct_definition
{
public:
	std::string pretty_name;
	std::string name;
	std::string code_name;
	unsigned long structure_size;
	unsigned long alignment_bits;
	s_h3_tag_struct_persistent_identifier persistent_identifier;
	const s_h3_tag_struct_definition& struct_definition;

	//c_h3_tag_block_definition* block_definition;
	//c_h3_tag_array_definition* array_definition;

	std::vector<c_h3_tag_field*> fields;

	c_h3_tag_struct_definition(const char* guerilla_data, const s_h3_tag_struct_definition& definition_header);
	~c_h3_tag_struct_definition();

	static std::map<ptr64, c_h3_tag_struct_definition*> tag_struct_definitions;
	static c_h3_tag_struct_definition* h3_get_tag_struct_definition(const char* guerilla_data, ptr64 virtual_address);
};

