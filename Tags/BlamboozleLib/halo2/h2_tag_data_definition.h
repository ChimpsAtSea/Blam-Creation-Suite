#pragma once

struct s_h2_tag_data_definition
{
	ptr32 definition_name_address;
	unsigned long flags;
	unsigned long alignment_bit;
	unsigned long maximum_size;
	ptr32 maximum_size_string_address;
	ptr32 byteswap_procedure;
	ptr32 copy_procedure;
};
