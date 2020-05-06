#pragma once

struct s_h5_tag_layout_header
{
	const char* name_address;
	uint32_t flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	uint16_t version;
	uint8_t initialized;
	uint8_t : 8;
	void* _unknown_struct_address;
	void* definition_address;
	tag_group child_group_tags[16];
	uint16_t num_child_group_tags;
	uint16_t : 16;
	void* default_tag_path_address;
};
//static_assert(sizeof(s_h5_tag_layout_header) == 112, "s_h5_tag_layout_header is incorrect size");

class c_blamboozle_h5_forge;
class c_h5_tag_layout
{
public:
	friend c_blamboozle_h5_forge;
	const char* name;
	c_h5_tag_block_definition* tag_block_definition;

private:
	c_h5_tag_layout(const char* halo5_forge_data, const s_h5_tag_layout_header* layout_header);

};