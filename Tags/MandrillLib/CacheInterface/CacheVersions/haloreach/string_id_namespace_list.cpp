#include "mandrilllib-private-pch.h"

c_string_id_namespace_list::c_string_id_namespace_list(c_gen3_cache_file& cache_file, uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits) :
	c_string_id_interface(cache_file, index_bits, namespace_bits, length_bits)
{
	
}

c_string_id_namespace_list::~c_string_id_namespace_list()
{

}

uint32_t c_string_id_namespace_list::string_id_to_index(string_id const stringid)
{
	uint32_t const index = (stringid & index_mask);
	uint32_t const set = (stringid & namespace_mask) >> index_bits;
	uint32_t const length = (stringid & length_mask) >> length_shift;

	uint32_t index_offset = 0;
	if (set == 0 && index >= static_cast<uint32_t>(cache_file.string_id_namespace_indices[0]))
	{
		index_offset = first_custom_index;
	}
	else
	{
		//DEBUG_ASSERT(stringid.set < cache_file.string_id_namespace_count);
		if (set > cache_file.string_id_namespace_count)
		{
			return 0xFFFFFFFF;
		}	
		
		for (uint32_t current_set = 0; current_set < set; current_set++) // #TODO: pre calculate this table
		{
			index_offset += cache_file.string_id_namespace_indices[current_set] & 0x1FFFF;
		}
	}

	uint32_t string_index = index_offset + index;
	return string_index;
}
