#pragma once

class c_legacy_string_id_manager :
	public c_string_id_manager
{
public:
	static constexpr uint32_t k_num_sets = 32;

	c_legacy_string_id_manager(uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits);

	virtual BCS_RESULT commit_string(uint32_t set, const char* string, uint32_t& string_id, bool is_user = false);
	virtual BCS_RESULT commit_string(uint32_t set, const char* string);
	virtual BCS_RESULT commit_string(const char* string, uint32_t& string_id) override;
	virtual BCS_RESULT commit_string(const char* string) override;

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
	std::unordered_map<std::string, unsigned long> string_id_table;
};