#pragma once

namespace blofeld
{
	using t_iterate_structure_fields_callback = void(const s_tag_struct_definition& struct_definition, void* userdata);

	enum e_validation_result
	{
		_validation_result_ok,
		_validation_result_struct_invalid_size,
		_validation_result_field_validation_failure,
		_validation_result_string_list_limit_reached,
		_validation_result_field_missing_string_list,
		_validation_result_field_missing_struct_definition,
		_validation_result_field_missing_array_definition,
		_validation_result_field_missing_block_definition,
		_validation_result_field_missing_tag_reference,
	};

	void iterate_structure_fields(
		s_engine_platform_build engine_platform_build,
		const s_tag_struct_definition& struct_definition,
		bool recursive,
		bool recursive_block,
		t_iterate_structure_fields_callback* callback,
		void* userdata = nullptr);
	void iterate_structure_fields(
		const s_tag_struct_definition& struct_definition,
		bool recursive,
		bool recursive_block,
		t_iterate_structure_fields_callback* callback,
		void* userdata = nullptr);
	uint32_t calculate_struct_size(
		s_engine_platform_build engine_platform_build,
		const s_tag_struct_definition& struct_definition, 
		e_validation_result* block_failed_validation = nullptr,
		bool disable_platform_independent_warnings = false,
		std::map<const s_tag_field*, uint64_t>* warnings_tracking = nullptr);
	bool validate_all_definitions(std::map<const s_tag_field*, uint64_t>* warnings_tracking = nullptr);
	bool validate_gen3_definitions(std::map<const s_tag_field*, uint64_t>* warnings_tracking = nullptr);
}



