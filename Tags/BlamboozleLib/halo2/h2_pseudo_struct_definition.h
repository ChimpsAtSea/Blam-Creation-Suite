#pragma once

class c_h2_pseudo_field_definition;
class c_h2_pseudo_array_definition;
class c_h2_tag_block_definition;

struct s_h2_upgrade_definition
{
	unsigned long fields_address;				// .data:00983DF8 off_983DF8      dd offset off_9829A8
	unsigned long unknown4;						// .data:00983DFC                 dd 0
	unsigned long upgrade_procedure;			// .data:00983E00                 dd offset sub_5D7C70
};

struct s_h2_byte_swap_definition
{
	ptr32 name;
	unsigned long size;
	unsigned long unknown8;
	unsigned long signature;
	unsigned long unknown10;
	unsigned long unknown14;
	unsigned long unknown18;
	unsigned long unknown1C;
	unsigned long unknown20;
};

struct s_h2_tag_struct_definition
{
	s_h2_upgrade_definition upgrade_definition;
	unsigned long unknownC;
	unsigned long unknown10;
	unsigned long struct_size;
	unsigned long alignment_bits;
	unsigned long unknown1C;
	ptr32 fields_address;
	ptr32 size_string;
	s_h2_byte_swap_definition byte_swap_definition;
};

struct s_h2_tag_field_struct_definition
{
	ptr32 name;
	tag signature;
	ptr32 display_name;
	ptr32 block_definition_address;
};

class c_h2_pseudo_struct_definition
{
public:
	std::string name;
	std::string code_name;
	std::string struct_name;
	const char* size_string;
	unsigned long size;

	const s_h2_tag_struct_definition* struct_definition;

	std::vector<c_h2_tag_block_definition*> block_definitions;

	bool is_array;
	c_h2_pseudo_array_definition* pseudo_array_definition;

	std::vector<c_h2_pseudo_field_definition*> pseudo_fields;
	const s_h2_tag_field* fields_begin;
	const s_h2_tag_field* fields_end;

	c_h2_pseudo_struct_definition(
		const char* guerilla_data,
		const s_h2_tag_struct_definition& struct_definition,
		c_h2_tag_block_definition* tag_block_definition
	);
	c_h2_pseudo_struct_definition(
		const char* guerilla_data,
		const s_h2_tag_field* fields,
		c_h2_pseudo_array_definition& pseudo_array_definition);

	static std::map<ptr32, c_h2_pseudo_struct_definition*> pseudo_struct_definitions;
	static c_h2_pseudo_struct_definition* h2_get_pseudo_struct_definition(const char* guerilla_data, ptr32 virtual_address, c_h2_tag_block_definition* tag_block_definition);

	void associate_tag_block(c_h2_tag_block_definition& block_definition);

private:
	void process_fields(const char* guerilla_data);
};