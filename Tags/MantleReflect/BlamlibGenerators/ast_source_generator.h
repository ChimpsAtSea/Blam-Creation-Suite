#pragma once
class c_ast_source_generator
{
public:
	c_ast_source_generator(const wchar_t* output_header_file, const wchar_t* output_source_file);

	virtual void run(std::vector<c_reflection_type_container*>& reflection_type_containers) = 0;
	virtual void write_output();
protected:
	static void write_output_impl(std::stringstream& stringstream, const wchar_t* output_file);
	std::stringstream header_string_stream;
	std::stringstream source_string_stream;
	const wchar_t* output_header_file;
	const wchar_t* output_source_file;
};

