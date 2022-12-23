#pragma once

class c_blamtoozle_source_generator;

class c_blamtoozle_file_stream
{
public:
	c_blamtoozle_file_stream(c_blamtoozle_source_generator& source_generator, const wchar_t* file_path);
	c_blamtoozle_file_stream(const c_blamtoozle_file_stream&) = delete;
	c_blamtoozle_file_stream(c_blamtoozle_file_stream&&) = delete;
	virtual ~c_blamtoozle_file_stream();

	void write();

	c_blamtoozle_source_generator& source_generator;
	const wchar_t* file_path;
	std::stringstream stream;
};
