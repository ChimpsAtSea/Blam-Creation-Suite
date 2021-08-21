#pragma once

struct s_h4_tag_group
{
	bptr32 name_address;
	bulong flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	bushort version;
	unsigned char initialized;
	unsigned char : 8;
	bulong vtable; // c_tag_group_vtable
	typed_bptr32<s_h4_tag_block_definition*> definition_address;
	btag_group child_group_tags[16];
	unsigned short num_child_group_tags;
	unsigned short : 16;
	bulong default_tag_path_address; // WRONG
};
//static_assert(sizeof(s_h4_tag_layout_header) == 112, "s_h4_tag_layout_header is incorrect size");

class c_h4_blamboozle;
class c_h4_tag_group
{
public:
	friend c_h4_blamboozle;
	const char* const name;
	unsigned long const flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	unsigned short version;
	unsigned char initialized;
protected:
	const s_h4_tag_block_definition* block_definition;
public:
	c_h4_tag_block& tag_block;
private:
	c_h4_tag_group(const char* h4_data, const s_h4_tag_group* layout_header);
};