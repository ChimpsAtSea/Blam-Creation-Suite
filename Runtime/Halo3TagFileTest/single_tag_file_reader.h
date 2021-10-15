#pragma once

#include <stack>

class c_single_tag_file_layout_reader;
class c_binary_data_chunk;

class c_single_tag_file_reader
{
public:
	c_single_tag_file_layout_reader& layout_reader;
	c_binary_data_chunk& binary_data_chunk;

	std::stack<unsigned long> metadata_stack;

	c_single_tag_file_reader(c_single_tag_file_layout_reader& layout_reader, c_binary_data_chunk& binary_data_chunk);


};
