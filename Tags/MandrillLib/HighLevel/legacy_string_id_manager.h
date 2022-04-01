#pragma once

class c_legacy_string_id_manager :
	public c_string_id_manager
{
public:
	static constexpr unsigned long k_num_sets = 32;

	c_legacy_string_id_manager(unsigned long index_bits, unsigned long namespace_bits, unsigned long length_bits);

	virtual BCS_RESULT commit_string(unsigned long set, const char* string, unsigned long& string_id, bool is_user = false);
	virtual BCS_RESULT commit_string(unsigned long set, const char* string);
	virtual BCS_RESULT commit_string(const char* string, unsigned long& string_id) override;
	virtual BCS_RESULT commit_string(const char* string) override;

	void init_haloreach();

	unsigned long index_bits;
	unsigned long index_mask;
	unsigned long namespace_bits;
	unsigned long namespace_mask;
	unsigned long namespace_shift;
	unsigned long length_bits;
	unsigned long length_mask;
	unsigned long length_shift;
	unsigned long first_custom_index;

	unsigned long engine_set_counts[k_num_sets];
	std::vector<std::string> string_ids[k_num_sets];
	std::unordered_map<std::string, unsigned long> string_id_table;
};