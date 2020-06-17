#pragma once

using t_cache_file_validator_field_type_render_callback = void(const blofeld::s_tag_field& field);
using t_cache_file_validator_callback = void(t_cache_file_validator_field_type_render_callback&);

class c_gen3_cache_file;
class c_gen3_tag_interface;
struct s_field_validation_result;

class c_gen3_cache_file_validator
{
	public:

		c_gen3_cache_file_validator(c_gen3_cache_file& cache_file);
		~c_gen3_cache_file_validator();

		static ImGuiDataType field_to_imgui_data_type(blofeld::e_field field_type);
		uint32_t get_struct_size(const blofeld::s_tag_struct_definition& struct_definition);
		uint32_t get_field_size(const blofeld::s_tag_field& field);
		uint32_t render_tag_struct_definition(int level, char* data, const blofeld::s_tag_struct_definition& struct_definition, bool is_block, bool render, bool& data_is_valid);
		uint32_t validate_tag_group(char* data, const blofeld::s_tag_group& group);

		void validate_tag_instance(c_gen3_tag_interface& tag_interface);

		c_gen3_cache_file& cache_file;
		e_engine_type engine_type;
#define render_field_callback_args char* data, const blofeld::s_tag_field& field, s_field_validation_result* result
		c_callback<void(render_field_callback_args)> field_type_render_callbacks[blofeld::k_number_of_blofeld_field_types];
		c_callback<void(render_field_callback_args, c_callback<void(render_field_callback_args)>&)> field_render_callback;
};

