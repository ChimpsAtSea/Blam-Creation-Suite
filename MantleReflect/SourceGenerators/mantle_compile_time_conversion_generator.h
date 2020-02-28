#pragma once
class c_mantle_compile_time_conversion_generator : 
	public c_ast_source_generator
{
public:
	c_mantle_compile_time_conversion_generator(const wchar_t* output_header_file, const wchar_t* output_source_file, std::vector<c_reflection_type_container*>& reflection_types);
	virtual void run() override;
};

