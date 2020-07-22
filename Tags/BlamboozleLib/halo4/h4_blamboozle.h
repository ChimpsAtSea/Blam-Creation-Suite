#pragma once

struct s_h4_tag_group;
struct s_h4_tag_block_definition;
struct s_h4_tag_array_definition;
struct s_h4_tag_struct_definition;
struct s_h4_tag_enum_definition;
struct s_h4_tag_reference_definition;
struct s_h4_tag_interop_definition;
struct s_h4_tag_resource_definition;

class c_h4_tag_block;
using c_h4_tag_array = c_h4_tag_block;
class c_h4_tag_struct;
class c_h4_tag_group;
class c_h4_tag_enum;
class c_h4_tag_reference;
class c_h4_tag_interop;
class c_h4_tag_resource;

class c_h4_blamboozle :
	public c_blamboozle_base
{
public:
	c_h4_blamboozle(const wchar_t* output_directory, const wchar_t* binary_filepath);
	~c_h4_blamboozle();
	virtual int run() override final;

	static c_h4_tag_block* get_tag_block_definition(
		const char* h4_data,
		const s_h4_tag_block_definition* definition_header,
		const s_h4_tag_group* tag_layout_header = nullptr);
	static c_h4_tag_array* get_tag_array_definition(const char* h4_data, const s_h4_tag_array_definition* definition_header);
	static std::map<const void*, c_h4_tag_block*> tag_block_definitions;

	static c_h4_tag_struct* get_tag_struct_definition(
		const char* h4_data,
		const s_h4_tag_struct_definition* definition_header,
		uint32_t offset);
	static std::map<const void*, c_h4_tag_struct*> tag_struct_definitions;

	static c_h4_tag_interop* get_tag_interop_definition(
		const char* h4_data,
		const s_h4_tag_interop_definition* definition_header);
	static std::map<const void*, c_h4_tag_interop*> tag_interop_definitions;

	static c_h4_tag_resource* get_tag_resource_definition(
		const char* h4_data,
		const s_h4_tag_resource_definition* definition_header);
	static std::map<const void*, c_h4_tag_resource*> tag_resource_definitions;

	static c_h4_tag_enum* get_tag_enum_definition(
		const char* h4_data,
		const s_h4_tag_enum_definition* definition_header);
	static std::map<const void*, c_h4_tag_enum*> tag_enum_definitions;

	static c_h4_tag_reference* get_tag_reference_definition(
		const char* h4_data,
		const s_h4_tag_reference_definition* definition_header,
		uint32_t definition_address);
	static std::map<const void*, c_h4_tag_reference*> tag_reference_definitions;

	char* h4_data = nullptr;
	size_t data_size = 0;
	std::vector<c_h4_tag_group*> tag_groups;
	static c_runtime_symbols* symbols;
};

