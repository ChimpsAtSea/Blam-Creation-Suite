#include "mandrilllib-private-pch.h"

c_string_id_interface::c_string_id_interface(c_gen3_cache_file& cache_file, uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits) :
	cache_file(cache_file),
	index_bits(index_bits),
	index_mask(0),
	namespace_bits(namespace_bits),
	namespace_mask(0),
	length_bits(length_bits),
	length_mask(0),
	length_shift(index_bits + namespace_bits),
	first_custom_index(0)
{
	for (uint32_t i = 0; i < index_bits; i++)
	{
		index_mask = (index_mask << 1) | 1;
	}
	index_mask << (0);
	for (uint32_t i = 0; i < namespace_bits; i++)
	{
		namespace_mask = (namespace_mask << 1) | 1;
	}
	namespace_mask << (index_bits);
	for (uint32_t i = 0; i < length_bits; i++)
	{
		length_mask = (length_mask << 1) | 1;
	}
	length_bits << (index_bits + namespace_bits);

	for (uint32_t current_set = 1; current_set < cache_file.string_id_namespace_count; current_set++) // #TODO: pre calculate this table
	{
		first_custom_index += cache_file.string_id_namespace_indices[current_set] & 0x1FFFF;
	}
}
