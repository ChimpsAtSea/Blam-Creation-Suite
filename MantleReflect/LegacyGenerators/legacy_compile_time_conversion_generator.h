#pragma once
class c_legacy_compile_time_conversion_generator : 
	public c_legacy_ast_source_generator
{
public:
	c_legacy_compile_time_conversion_generator(const wchar_t* output_header_file, const wchar_t* output_source_file);
	virtual void run(std::vector<c_reflection_type_container*>& reflection_type_containers) override;
};

