#pragma once

class c_string_id_namespace_list :
	public c_string_id_interface
{
public:
	c_string_id_namespace_list(c_gen3_cache_file& cache_file, uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits);
	~c_string_id_namespace_list();

	virtual uint32_t string_id_to_index(string_id const stringid) override final;
};

