#pragma once

class c_cache_file;

struct s_engine_string_id_guesstimator_data
{
	const char* string;
	bool is_reliable;
};

class c_cache_file_string_id_guesstimator
{
public:
	c_cache_file_string_id_guesstimator(c_cache_file& cache_file);
	~c_cache_file_string_id_guesstimator();

	uint32_t string_id_to_index(string_id const stringid)
	{
		uint32_t start_index = 0;
		if (stringid.set == 0 && stringid.index >= engine_string_id_first_set_end_index)
		{
			start_index = cache_file_string_id_start_index;
		}
		else
		{
			if (stringid.set > _countof(string_id_set_start_indices))
			{
				return 0xFFFFFFFF;
			}
			start_index = string_id_set_start_indices[stringid.set];
		}

		uint32_t index = start_index + stringid.index;
		return index;
	}



private:
	uint32_t cache_file_string_id_start_index;
	uint32_t engine_string_id_first_set_end_index;
	uint32_t engine_string_id_last_set_end_index;
	uint32_t set_count;
	uint32_t string_id_set_ranges[32];
	uint32_t string_id_set_start_indices[32];
	uint32_t string_id_set_end_indices[32];

	c_cache_file& cache_file;

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

