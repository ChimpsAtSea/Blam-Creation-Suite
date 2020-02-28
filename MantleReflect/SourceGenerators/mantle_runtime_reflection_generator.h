#pragma once
class c_mantle_runtime_reflection_generator :
	public c_ast_source_generator
{
public:
	c_mantle_runtime_reflection_generator(const wchar_t* output_header_file, const wchar_t* output_source_file, std::vector<c_reflection_type_container*>& reflection_types);
	virtual void run() override;
	void write_tag_type_lookup_function();
	void write_reflection_type_entry(const c_reflection_type_container& rType);
};

