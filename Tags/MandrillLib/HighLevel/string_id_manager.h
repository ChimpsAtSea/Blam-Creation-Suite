#pragma once

class c_string_id_manager
{
public:
	static constexpr uint32_t k_num_sets = 32;

	c_string_id_manager(uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits);

	uint32_t commit_engine_string(uint32_t set, const char* value, bool is_user = false);
	uint32_t commit_string(const char* value);

	void init_haloreach();

	uint32_t index_bits;
	uint32_t index_mask;
	uint32_t namespace_bits;
	uint32_t namespace_mask;
	uint32_t namespace_shift;
	uint32_t length_bits;
	uint32_t length_mask;
	uint32_t length_shift;
	uint32_t first_custom_index;

	uint32_t engine_set_counts[k_num_sets];
	std::vector<std::string> string_ids[k_num_sets];
	std::map<std::string, uint32_t> string_id_table;
};