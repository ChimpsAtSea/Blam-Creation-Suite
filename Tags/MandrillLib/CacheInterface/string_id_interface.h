#pragma once

class c_gen3_cache_file;

class c_string_id_interface
{
public:
	c_string_id_interface(c_gen3_cache_file& cache_file, uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits);

	virtual uint32_t string_id_to_index(string_id const stringid) = 0;

protected:
	c_gen3_cache_file& cache_file;
	uint32_t index_bits;
	uint32_t index_mask;
	uint32_t namespace_bits;
	uint32_t namespace_mask;
	uint32_t namespace_shift;
	uint32_t length_bits;
	uint32_t length_mask;
	uint32_t length_shift;
	uint32_t first_custom_index;
};
