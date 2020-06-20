#pragma once

namespace blofeld
{
	using t_iterate_structure_fields_callback = void(const s_tag_struct_definition& struct_definition, void* userdata);

	void iterate_structure_fields(
		e_engine_type engine_type, 
		e_build build, 
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
	uint32_t calculate_struct_size(e_engine_type engine_type, e_build build, const s_tag_struct_definition& struct_definition, bool* block_failed_validation = nullptr);
	bool validate_gen3_definitions();
}



