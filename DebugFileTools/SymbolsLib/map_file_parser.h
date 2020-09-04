#pragma once

class c_map_file_parser
{
public:

	c_map_file_parser(const wchar_t* mapping_filepath, const char** excluded_libs, size_t excluded_libs_count);
	~c_map_file_parser();

	void write_output(const wchar_t* output_filepath);

	const char* get_symbol_data() const { return symbols_blob.data(); }
	size_t get_symbol_size() const { return symbols_blob.size(); }

private:
	void parse_mapping_file_lines(const wchar_t* mapping_filepath);
	void parse_mapping_file(const char** excluded_libs, size_t excluded_libs_count);
	void create_symbols_blob();

	std::vector<char> symbols_blob;
	uint32_t lines_count;
	std::vector<const char*> lines_vector;
	const char** lines;
	char* map_file = nullptr;
	s_symbol_file_header_temp temp_header;
};