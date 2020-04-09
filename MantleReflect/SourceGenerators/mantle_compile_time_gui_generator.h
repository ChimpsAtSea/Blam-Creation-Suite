#pragma once
class c_mantle_compile_time_gui_generator :
	public c_ast_source_generator
{
public:
	c_mantle_compile_time_gui_generator(const wchar_t* output_header_file, const wchar_t* output_source_file);
	virtual void run(std::vector<c_reflection_type_container*>& reflection_type_containers) override;
	void write_render_gui_type_entry_source(const c_reflection_type_container& reflection_type_container);
	void write_render_gui_type_entry_header(const c_reflection_type_container& reflection_type_container);
};

