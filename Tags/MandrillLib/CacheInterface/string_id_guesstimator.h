#pragma once

struct s_engine_string_id_guesstimator_data
{
	const char* string;
	bool is_reliable;
};

class c_string_id_guesstimator :
	public c_string_id_interface
{
public:
	c_string_id_guesstimator(c_gen3_cache_file& cache_file, uint32_t index_bits, uint32_t namespace_bits, uint32_t length_bits);
	~c_string_id_guesstimator();

	virtual uint32_t string_id_to_index(string_id const stringid) override final;

private:
	uint32_t cache_file_string_id_start_index;
	uint32_t engine_string_id_first_set_end_index;
	uint32_t engine_string_id_last_set_end_index;
	uint32_t set_count;
	uint32_t string_id_set_ranges[32];
	uint32_t string_id_set_start_indices[32];
	uint32_t string_id_set_end_indices[32];

	static std::pair<s_engine_string_id_guesstimator_data*, uint32_t> engine_string_id_guesstimator_data[17];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set0[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set1[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set2[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set3[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set4[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set5[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set6[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set7[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set8[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set9[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set10[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set11[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set12[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set13[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set14[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set15[];
	static s_engine_string_id_guesstimator_data engine_string_id_guesstimator_data_set16[];
};

