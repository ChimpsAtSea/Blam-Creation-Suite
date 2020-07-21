#pragma once

using t_cache_file_validator_field_type_render_callback = void(const blofeld::s_tag_field& field);
using t_cache_file_validator_callback = void(t_cache_file_validator_field_type_render_callback&);

class c_gen3_cache_file;
class c_gen3_tag_interface;
struct s_field_validation_result;

struct s_tag_validation_data;
struct s_memory_region;

class c_gen3_cache_file_validator2
{
	public:
		non_copyconstructable(c_gen3_cache_file_validator2);

		c_gen3_cache_file_validator2(c_gen3_cache_file& cache_file);
		~c_gen3_cache_file_validator2();

		s_tag_validation_data* validate_tag_group(c_tag_interface& tag_interface, char* data, const blofeld::s_tag_struct_definition& struct_definition);
		void traverse_tag_struct(s_tag_validation_data& validation_data, char* const data, const blofeld::s_tag_struct_definition& struct_definition);
		void validate_tag_data(s_tag_validation_data& validation_data, char* const data, const char* field_name);
		void validate_tag_block(s_tag_validation_data& validation_data, char* data, const blofeld::s_tag_block_definition& block_definition);
		void validate_tag_struct(s_tag_validation_data& validation_data, char* data, const blofeld::s_tag_struct_definition& struct_definition);
		void validate_tag_instances();
private:
		uint32_t get_struct_size(const blofeld::s_tag_struct_definition& struct_definition);
		uint32_t get_field_size(const blofeld::s_tag_field& field);

		c_gen3_cache_file& cache_file;
		e_engine_type engine_type;
		e_platform_type platform_type;
};

