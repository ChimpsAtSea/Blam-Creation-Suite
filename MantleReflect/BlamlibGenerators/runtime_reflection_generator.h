#pragma once

class c_runtime_reflection_generator :
	public c_ast_source_generator
{
public:
	c_runtime_reflection_generator(const wchar_t* output_header_file, const wchar_t* output_source_file);
	virtual void run(std::vector<c_reflection_type_container*>& type_containers) override;
	void write_render_gui_type_entry_header(const c_reflection_type_container& type_container);
	void write_render_gui_type_entry_source(const c_reflection_type_container& type_container);
	void write_render_gui_type_entry_header2(const c_reflection_type_container& type_container);
	void write_render_gui_type_entry_source2(const c_reflection_type_container& type_container);
	void write_render_gui_type_entry_header3(const c_reflection_type_container& type_container);
	void write_render_gui_type_entry_source3(const c_reflection_type_container& type_container);

	uint32_t current_member_index = 0;
};

