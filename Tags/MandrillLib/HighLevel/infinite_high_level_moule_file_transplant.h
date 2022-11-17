#pragma once

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE

class c_infinite_cache_cluster;
class c_infinite_module_file_reader;

class c_infinite_high_level_moule_file_transplant
{
public:
	c_infinite_high_level_moule_file_transplant(const c_infinite_high_level_moule_file_transplant&) = delete;
	c_infinite_high_level_moule_file_transplant(c_infinite_high_level_moule_file_transplant&&) = delete;
	c_infinite_high_level_moule_file_transplant(
		c_high_level_cache_cluster_transplant& high_level_cache_cluster_transplant,
		s_engine_platform_build engine_platform_build,
		c_tag_instance& tag_instance,
		h_tag_instance& root_high_level,
		blofeld::s_tag_struct_definition const& struct_definition,
		c_infinite_ucs_reader& ucs_reader,
		c_infinite_cache_cluster& cache_cluster,
		c_infinite_module_file_reader& cache_file_reader);
	~c_infinite_high_level_moule_file_transplant();

	BCS_RESULT transplant_module_file_data(
		h_prototype& high_level,
		int32_t tag_block_index,
		const char* const tag_block_data,
		int32_t nugget_index,
		const char* current_data_position,
		blofeld::s_tag_struct_definition const& struct_definition);

protected:
	c_high_level_cache_cluster_transplant& high_level_cache_cluster_transplant;
	s_engine_platform_build engine_platform_build;
	c_infinite_ucs_reader& ucs_reader;
	c_tag_instance& tag_instance;
	h_tag_instance& root_high_level;
	blofeld::s_tag_struct_definition const& root_struct_definition;
	c_infinite_cache_cluster& cache_cluster;
	c_infinite_module_file_reader& cache_file_reader;
	c_infinite_string_id_manager infinite_string_id_manager;
	uint32_t root_struct_size;
};

#endif
