#pragma once

struct s_h4_tag_group
{
	buint32_t name_address;
	buint32_t flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	buint16_t version;
	uint8_t initialized;
	uint8_t : 8;
	buint32_t vtable; // c_tag_group_vtable
	bpointer32<s_h4_tag_block_definition*> definition_address;
	btag_group child_group_tags[16];
	uint16_t num_child_group_tags;
	uint16_t : 16;
	buint32_t default_tag_path_address; // WRONG
};
//static_assert(sizeof(s_h4_tag_layout_header) == 112, "s_h4_tag_layout_header is incorrect size");

class c_h4_blamboozle;
class c_h4_tag_group
{
public:
	friend c_h4_blamboozle;
	const char* const name;
	uint32_t const flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	uint16_t version;
	uint8_t initialized;
protected:
	const s_h4_tag_block_definition* block_definition;
public:
	c_h4_tag_block& tag_block;
private:
	c_h4_tag_group(const char* h4_data, const s_h4_tag_group* layout_header);
};