#include "halo3tagfiletest-private-pch.h"

c_single_tag_file_reader::c_single_tag_file_reader(c_single_tag_file_layout_reader& layout_reader, c_binary_data_chunk& binary_data_chunk) :
	layout_reader(layout_reader),
	binary_data_chunk(binary_data_chunk),
	metadata_stack()
{
	metadata_stack.push(layout_reader.tag_group_layout_chunk.tag_group_layout_header->tag_group_block_index);
	debug_point;

	binary_data_chunk.parse_children(this);
}
