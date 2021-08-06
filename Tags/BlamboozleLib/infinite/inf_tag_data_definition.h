#pragma once

struct s_inf_tag_data_definition
{
	ptr64 definition_name_address;
	unsigned long flags;
	unsigned long alignment_bit;
	unsigned long maximum_size;
	ptr64 maximum_size_string_address;
	ptr64 byteswap_procedure;
	ptr64 copy_procedure;
};
