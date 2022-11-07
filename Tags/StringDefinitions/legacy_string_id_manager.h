#pragma once

class c_legacy_string_id_manager :
	public c_string_id_manager
{
public:
	static constexpr uint32_t k_num_sets = 32;

	c_legacy_string_id_manager() = delete;
	c_legacy_string_id_manager(c_legacy_string_id_manager const&) = delete;
	BCS_SHARED c_legacy_string_id_manager(uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits);

	BCS_SHARED BCS_RESULT init_from_engine_platform_build(s_engine_platform_build engine_platform_build);
	BCS_SHARED BCS_RESULT commit_string(uint32_t set, const char* string, uint32_t& string_id, bool defined_in_tags = true);
	BCS_SHARED BCS_RESULT commit_string(uint32_t set, const char* string, bool defined_in_tags = true);
	BCS_SHARED BCS_RESULT commit_string(const char* string, uint32_t& string_id, bool defined_in_tags);
	BCS_SHARED BCS_RESULT commit_string(const char* string, bool defined_in_tags);
	BCS_SHARED virtual BCS_RESULT commit_string(const char* string, uint32_t& string_id) override final;
	BCS_SHARED virtual BCS_RESULT commit_string(const char* string) override final;
	BCS_SHARED virtual BCS_RESULT fetch_string_id(const char* string, uint32_t& string_id) const override final;
	BCS_SHARED virtual BCS_RESULT fetch_string(uint32_t string_id, const char*& string) const override final;
	BCS_SHARED BCS_RESULT calculate_string_id(uint32_t _namespace, uint32_t index, uint32_t length, uint32_t& string_id) const;
	BCS_SHARED BCS_RESULT deconstruct_string_id(uint32_t string_id, uint32_t& _namespace, uint32_t& index, uint32_t& length) const;
	BCS_SHARED virtual BCS_RESULT clear() override final;
	BCS_SHARED virtual uint32_t get_total_engine_strings() const override final;

protected:
	using t_string_map = std::map<std::string, unsigned long>;
	using t_string_vector = std::vector<std::string>;
	t_string_vector string_ids[k_num_sets];
	uint32_t engine_namespace_counts[k_num_sets];
	uint32_t global_namespace_counts[k_num_sets];
	uint32_t total_engine_strings;
	uint32_t total_strings;
	t_string_map string_id_table;

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
