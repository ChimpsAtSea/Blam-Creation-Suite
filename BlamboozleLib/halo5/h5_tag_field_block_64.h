#pragma once

struct s_h5_tag_block_definition_header;
class c_h5_tag_block_definition;

class c_h5_tag_field_block_64 :
	public c_h5_tag_field
{
public:
	const s_h5_tag_block_definition_header* tag_block_definition_header;
	c_h5_tag_block_definition* tag_block_definition;

	c_h5_tag_field_block_64(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition);

};
