#include "symbolslib-private-pch.h"

struct t_symbol_file_parser
{
public:
	t_symbol_file_parser() = delete;
	t_symbol_file_parser(t_symbol_file_parser const&) = delete;
	t_symbol_file_parser& operator=(t_symbol_file_parser const&) = delete;

	t_symbol_file_parser(const wchar_t* mapping_filepath, const char** excluded_libs, size_t excluded_libs_count);
	~t_symbol_file_parser();

	void write_output(const wchar_t* output_filepath);

	const char* get_symbol_data() const { return symbols_blob.data(); }
	size_t get_symbol_size() const { return symbols_blob.size(); }

private:
	void parse_mapping_file_lines(const wchar_t* mapping_filepath);
	void parse_mapping_file(const char** excluded_libs, size_t excluded_libs_count);
	static void parse_mapping_file_impl_a_callback(void* userdata, unsigned long long index);
	static void parse_mapping_file_impl_b_callback(void* userdata, unsigned long long index);
	void parse_mapping_file_impl_a(unsigned long long index);
	void parse_mapping_file_impl_b(unsigned long long index);
	void create_symbols_blob();

	std::vector<char> symbols_blob;
	unsigned long lines_count;
	std::vector<const char*> lines_vector;
	const char** lines;
	void* map_file = nullptr;
	s_symbol_file_header_temp temp_header;
	const char** formatted_excluded_libs;
	const char** original_excluded_libs;
	size_t excluded_libs_count;
};

BCS_RESULT symbol_file_parser_create(
	const wchar_t* mapping_filepath,
	const char** excluded_libs,
	unsigned long excluded_libs_count,
	t_symbol_file_parser*& symbol_file_parser
)
{
	try
	{
		symbol_file_parser = new t_symbol_file_parser(mapping_filepath, excluded_libs, excluded_libs_count);
		return BCS_S_OK;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
}

BCS_RESULT symbol_file_parser_write_output(t_symbol_file_parser* symbol_file_parser, const wchar_t* output_filepath)
{
	BCS_VALIDATE_ARGUMENT(symbol_file_parser);

	symbol_file_parser->write_output(output_filepath);

	return BCS_S_OK;
}

BCS_RESULT symbol_file_parser_get_symbol_data(t_symbol_file_parser* symbol_file_parser, const char*& symbol_data, unsigned long& symbol_data_size)
{
	BCS_VALIDATE_ARGUMENT(symbol_file_parser);

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = symbol_file_parser_get_symbol_data_size(symbol_file_parser, symbol_data_size)))
	{
		return rs;
	}

	symbol_data = symbol_file_parser->get_symbol_data();

	return rs;
}

BCS_RESULT symbol_file_parser_get_symbol_data_size(t_symbol_file_parser* symbol_file_parser, unsigned long& symbol_data_size)
{
	BCS_VALIDATE_ARGUMENT(symbol_file_parser);

	symbol_data_size = static_cast<unsigned long>(symbol_file_parser->get_symbol_size());

	return BCS_S_OK;
}

BCS_RESULT symbol_file_parser_destroy(t_symbol_file_parser* symbol_file_parser)
{
	BCS_VALIDATE_ARGUMENT(symbol_file_parser);
	delete symbol_file_parser;
	return BCS_S_OK;
}

t_symbol_file_parser::t_symbol_file_parser(
	const wchar_t* mapping_filepath, 
	const char** _original_excluded_libs,
	size_t excluded_libs_count) :
	map_file(nullptr),
	formatted_excluded_libs(),
	original_excluded_libs(_original_excluded_libs),
	excluded_libs_count(excluded_libs_count)
{
	size_t formatted_excluded_libs_buffer_size = 0;
	for (size_t i = 0; i < excluded_libs_count; i++)
	{
		formatted_excluded_libs_buffer_size += snprintf(nullptr, 0, "%s:", _original_excluded_libs[i]) + 1;
	}
	formatted_excluded_libs = new const char* [excluded_libs_count];
	char* const formatted_excluded_libs_buffer = new char[formatted_excluded_libs_buffer_size];
	char* formatted_excluded_libs_buffer_pos = formatted_excluded_libs_buffer;
	for (size_t i = 0; i < excluded_libs_count; i++)
	{
		size_t length = sprintf(formatted_excluded_libs_buffer_pos, "%s:", _original_excluded_libs[i]) + 1;
		formatted_excluded_libs[i] = formatted_excluded_libs_buffer_pos;
		formatted_excluded_libs_buffer_pos += length;
	}

	parse_mapping_file_lines(mapping_filepath);
	parse_mapping_file(formatted_excluded_libs, excluded_libs_count);
	create_symbols_blob();

	delete[] formatted_excluded_libs;
	delete[] formatted_excluded_libs_buffer;
}

t_symbol_file_parser::~t_symbol_file_parser()
{
	if (map_file)
	{
		delete[] map_file;
	}
}

void t_symbol_file_parser::parse_mapping_file_lines(const wchar_t* mapping_filepath)
{
	unsigned long long map_file_size = 0;

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = filesystem_read_file_to_memory(mapping_filepath, map_file, map_file_size)))
	{
		console_write_line("Failed to open input file '%S'", mapping_filepath);
		FATAL_ERROR("Failed to open input file");

		// #TODO: cleanup
	}
	if (map_file_size == 0)
	{
		FATAL_ERROR("input file invalid size");

		// #TODO: cleanup
	}

	char* const start_read_position = static_cast<char*>(map_file);
	char* const end_read_position = start_read_position + map_file_size;
	
	{
		size_t line_buffer_count = 500;
		char* current_read_position = start_read_position;
		while (current_read_position < end_read_position)
		{
			if(*current_read_position == '\n')
			{
				line_buffer_count++;
			}
			current_read_position++;
		}
		lines_vector.reserve(line_buffer_count);
	}
	
	{
		char* current_read_position = start_read_position;
		while (current_read_position < end_read_position)
		{
			constexpr unsigned long iteration_lines_count = 64 * 1024;
			unsigned long lines_count = 0;
			char* lines_tmp[iteration_lines_count];
			while (current_read_position < end_read_position && lines_count < iteration_lines_count)
			{
				//while (*current_read_position == ' ' || *current_read_position == '\r' || *current_read_position == '\n')
				while (*current_read_position <= 33) // control characters + space
				{
					current_read_position++; // clear prefix spaces
				}
				lines_tmp[lines_count] = current_read_position;
				lines_count++;

				while (current_read_position < end_read_position)
				{
					if (*current_read_position < 32) // control characters
					{
						*current_read_position = 0;
						current_read_position++;
						if (current_read_position < end_read_position && *current_read_position < 32) // control characters
						{
							*current_read_position = 0;
							current_read_position++;
						}
						break;
					}
					else
					{
						current_read_position++;
					}
				}
			}
			lines_vector.insert(lines_vector.end(), (char**)lines_tmp, (char**)lines_tmp + lines_count);
		}

		lines_vector.push_back("");

		lines = lines_vector.data();
	}
}

static DWORD max_public_complete_symbol_name_length = 0;
static DWORD max_public_symbol_name_length = 0;
static DWORD max_private_complete_symbol_name_length = 0;
static DWORD max_private_symbol_name_length = 0;


void t_symbol_file_parser::parse_mapping_file_impl_a_callback(void* userdata, unsigned long long index)
{
	reinterpret_cast<t_symbol_file_parser*>(userdata)->parse_mapping_file_impl_a(index);
}

void t_symbol_file_parser::parse_mapping_file_impl_a(unsigned long long line_index)
{
	const char* public_symbol_string = lines[line_index];

	if (strstr(public_symbol_string, "UIPlatformAnimations_group"))
	{
		debug_point;
	}

	bool ignore = false;
	for (size_t excluded_lib_index = 0; excluded_lib_index < excluded_libs_count; excluded_lib_index++)
	{
		const char* excluded_lib = formatted_excluded_libs[excluded_lib_index];
		//if (*temp_public.lib_and_object == *excluded_lib && strstr(temp_public.lib_and_object, excluded_libs[excluded_lib_index]) != nullptr)
		//{
		//	ignore = true;
		//	break;
		//}
		if (strstr(public_symbol_string, excluded_lib) != nullptr)
		{
			ignore = true;
			break;
		}
	}
	if (!ignore)
	{
		s_symbol_file_public_temp temp_public = {};

		char overflow[4]; // if this is used, throw an error by checking the count

		int count = sscanf(
			public_symbol_string,
			"%x:%x %2047s%llx" // section_index, rva, symbol_name, rva_plus_base
			"%255s%255s%255s%255s" // auxillary
			"%3s", // overflow
			&temp_public.section_index,
			&temp_public.rva,
			&temp_public.mangled_symbol_name_buffer,
			&temp_public.rva_plus_base,
			&temp_public.auxillary[0], &temp_public.auxillary[1], &temp_public.auxillary[2], &temp_public.auxillary[3],
			&overflow);
		ASSERT(count >= 5);
		ASSERT(count <= 9);

		//const char* flags[15];
		//int flags_count = 0;
		//for (int argument_index = 4; argument_index < count; (argument_index++, flags_count++))
		//{
		//	flags[flags_count] = auxillary[flags_count];
		//}

		const char* lib_and_object_str = temp_public.auxillary[count - 5];
		*temp_public.lib_and_object = 0;
		strncat(temp_public.lib_and_object, lib_and_object_str, _countof(temp_public.lib_and_object) - 1);

		const char* mangled_symbol_name = temp_public.mangled_symbol_name_buffer;
		if (*mangled_symbol_name != '?')
		{
			const char* new_mangled_symbol_name = strstr(mangled_symbol_name + 1, "?");
			if (new_mangled_symbol_name) // mangled c names can be empty
			{
				mangled_symbol_name = new_mangled_symbol_name;
			}
		}

		temp_header.mutex.lock();
#ifndef _DEBUG
		DWORD complete_symbol_name_length = UnDecorateSymbolName(mangled_symbol_name, temp_public.complete_symbol_name, _countof(temp_public.complete_symbol_name), UNDNAME_COMPLETE);
		DEBUG_ASSERT(complete_symbol_name_length != 0);
		//if (complete_symbol_name_length != 0)
		//{
		//	console_write_line("%s(%i): warning SYM0: UnDecorateSymbolName failed %s", __FILE__, __LINE__, mangled_symbol_name);
		//}
		temp_public.complete_symbol_name[complete_symbol_name_length] = 0;
		max_public_complete_symbol_name_length = __max(complete_symbol_name_length, max_public_complete_symbol_name_length);
#endif
		DWORD symbol_name_length = UnDecorateSymbolName(mangled_symbol_name, temp_public.symbol_name, _countof(temp_public.symbol_name), UNDNAME_NAME_ONLY);
		DEBUG_ASSERT(symbol_name_length != 0);
		//if(symbol_name_length != 0)
		//{
		//	console_write_line("%s(%i): warning SYM1: UnDecorateSymbolName failed %s", __FILE__, __LINE__, mangled_symbol_name);
		//}
		temp_public.symbol_name[symbol_name_length] = 0;
		max_public_symbol_name_length = __max(symbol_name_length, max_public_symbol_name_length);

		temp_header.public_symbols.emplace_back(temp_public);
		temp_header.mutex.unlock();
	}
}

void t_symbol_file_parser::parse_mapping_file_impl_b_callback(void* userdata, unsigned long long index)
{
	reinterpret_cast<t_symbol_file_parser*>(userdata)->parse_mapping_file_impl_b(index);
}

void t_symbol_file_parser::parse_mapping_file_impl_b(unsigned long long line_index)
{
	const char* static_symbol_string = lines[line_index];

	bool ignore = false;
	for (size_t excluded_lib_index = 0; excluded_lib_index < excluded_libs_count; excluded_lib_index++)
	{
		const char* excluded_lib = formatted_excluded_libs[excluded_lib_index];
		//if (*temp_static.lib_and_object == *excluded_lib && strstr(temp_static.lib_and_object, excluded_libs[excluded_lib_index]) != nullptr)
		//{
		//	ignore = true;
		//	break;
		//}
		if (strstr(static_symbol_string, excluded_lib) != nullptr)
		{
			ignore = true;
			break;
		}
	}
	if (!ignore)
	{
		s_symbol_file_static_temp temp_static = {};

		int count = sscanf(
			static_symbol_string,
			"%x:%x %2047s%llx%255s",
			&temp_static.section_index,
			&temp_static.rva,
			&temp_static.mangled_symbol_name_buffer,
			&temp_static.rva_plus_base,
			&temp_static.lib_and_object);
		ASSERT(count == 5);

		const char* mangled_symbol_name = temp_static.mangled_symbol_name_buffer;
		ASSERT(*mangled_symbol_name);
		if (*mangled_symbol_name != '?')
		{
			const char* new_mangled_symbol_name = strstr(mangled_symbol_name + 1, "?");
			if (new_mangled_symbol_name) // mangled c names can be empty
			{
				mangled_symbol_name = new_mangled_symbol_name;
			}
		}

		temp_header.mutex.lock();

#ifndef _DEBUG
		DWORD complete_symbol_name_length = UnDecorateSymbolName(mangled_symbol_name, temp_static.complete_symbol_name, _countof(temp_static.complete_symbol_name), UNDNAME_COMPLETE);
		ASSERT(complete_symbol_name_length != 0); // failure
		temp_static.complete_symbol_name[complete_symbol_name_length] = 0;
		max_private_complete_symbol_name_length = __max(complete_symbol_name_length, max_private_complete_symbol_name_length);

#endif
		DWORD symbol_name_length = UnDecorateSymbolName(mangled_symbol_name, temp_static.symbol_name, _countof(temp_static.symbol_name), UNDNAME_NAME_ONLY);
		ASSERT(symbol_name_length != 0);
		temp_static.symbol_name[symbol_name_length] = 0;
		max_private_symbol_name_length = __max(symbol_name_length, max_private_symbol_name_length);

		temp_header.static_symbols.emplace_back(temp_static);
		temp_header.mutex.unlock();
	}
}

void t_symbol_file_parser::parse_mapping_file(const char** excluded_libs, size_t excluded_libs_count)
{
	unsigned long thread_count = GetActiveProcessorCount(0);
	unsigned long long current_line = 0;
	temp_header.binary_name = lines[current_line++];
	temp_header.timestamp_string = lines[current_line++];
	const char* preferred_load_address_string = lines[current_line++];
	ASSERT(sscanf(preferred_load_address_string, "Preferred load address is %llx", &temp_header.preferred_load_address) == 1);

	const char* sections_search_string = lines[current_line];
	if (strstr(sections_search_string, "Start") == sections_search_string)
	{
		current_line++;

		const char* section_string = lines[current_line];
		while (strstr(section_string, ":") == &section_string[4]) // is 4th character ':'
		{
			s_symbol_file_section_temp& temp_section = temp_header.sections.emplace_back();

			int count = sscanf(section_string, "%x:%x %xH %31s%31s", &temp_section.section_index, &temp_section.rva, &temp_section.length, &temp_section.name_string, &temp_section.class_string);
			ASSERT(count == 5);

			section_string = lines[++current_line];
		}
	}
	
	const char* public_symbols_search_string = lines[current_line];
	if (strstr(public_symbols_search_string, "Address") == public_symbols_search_string)
	{
		current_line++;

		unsigned long long lines_start = current_line;
		{
			const char* public_symbol_string = lines[current_line];
			while (strstr(public_symbol_string, ":") == &public_symbol_string[4]) // is 4th character ':'
			{
				public_symbol_string = lines[++current_line];
			}
		}
		unsigned long long lines_end = current_line;
		
		parallel_invoke(
			lines_start, 
			lines_end, 
			parse_mapping_file_impl_a_callback,
			this);
	}

	const char* entry_point_at_search_string = lines[current_line];
	if (strstr(entry_point_at_search_string, "entry point at") == entry_point_at_search_string)
	{
		int count = sscanf(entry_point_at_search_string, "entry point at        %x:%x", &temp_header.entry_point_section_index, &temp_header.entry_point_rva);
		ASSERT(count >= 2);
		current_line++;
	}

	const char* static_symbols_search_string = lines[current_line];
	if (strstr(static_symbols_search_string, "Static symbols") == static_symbols_search_string)
	{
		current_line++;

		unsigned long long lines_start = current_line;
		{
			const char* static_symbol_string = lines[current_line];
			while (strstr(static_symbol_string, ":") == &static_symbol_string[4]) // is 4th character ':'
			{
				static_symbol_string = lines[++current_line];
			}
		}
		unsigned long long lines_end = current_line;

		parallel_invoke(
			lines_start,
			lines_end,
			parse_mapping_file_impl_b_callback,
			this);
	}
	
	ASSERT(max_public_symbol_name_length < _countof(s_symbol_file_public_temp::symbol_name) - 2);
	ASSERT(max_private_symbol_name_length < _countof(s_symbol_file_static_temp::symbol_name) - 2);
#ifndef _DEBUG
	ASSERT(max_public_complete_symbol_name_length < _countof(s_symbol_file_public_temp::complete_symbol_name) - 2);
	ASSERT(max_private_complete_symbol_name_length < _countof(s_symbol_file_static_temp::complete_symbol_name) - 2);
#endif
	debug_point;
}

void t_symbol_file_parser::create_symbols_blob()
{
	// #TODO: Replace with fixed array
	symbols_blob.reserve(128 * 1024 * 1024); // 128MB
	std::vector<char> appended_data;
	appended_data.reserve(512 * 1024 * 1024); // 512MB

	size_t const headers_data_size =
		sizeof(s_symbol_file_header) +
		sizeof(s_symbol_file_section) * temp_header.sections.size() +
		sizeof(s_symbol_file_public) * temp_header.public_symbols.size() +
		sizeof(s_symbol_file_static) * temp_header.static_symbols.size();

#define headers_data_offset (headers_data.size())
#define appdend_data_offset (headers_data_size + appended_data.size())
#define enqueue_header(header_type) *new((symbols_blob.resize(symbols_blob.size() + sizeof(header_type)), symbols_blob.data() + (symbols_blob.size() - sizeof(header_type)))) header_type()
#define enqueue_string(string) (appended_data.insert(appended_data.end(), string, string + strlen(string) + 1), appdend_data_offset - (strlen(string) + 1))

	s_symbol_file_header& header = enqueue_header(s_symbol_file_header);
	header.binary_name_offset = enqueue_string(temp_header.binary_name);
	header.timestamp_string_offset = enqueue_string(temp_header.timestamp_string);
	header.preferred_load_address = temp_header.preferred_load_address;
	header.entry_point_section_index = temp_header.entry_point_section_index;
	header.entry_point_rva = temp_header.entry_point_rva;

	header.sections_offset = symbols_blob.size();
	header.sections_count = static_cast<unsigned short>(temp_header.sections.size());
	for (s_symbol_file_section_temp& temp_section : temp_header.sections)
	{
		s_symbol_file_section& section = enqueue_header(s_symbol_file_section);
		section.section_index = temp_section.section_index;
		section.rva = temp_section.rva;
		section.length = temp_section.length;
		section.name_string_offset = enqueue_string(temp_section.name_string);
		section.class_string_offset = enqueue_string(temp_section.class_string);

		temp_section.section = &section;
	}

	header.public_symbols_offset = symbols_blob.size();
	header.public_symbols_count = static_cast<unsigned long>(temp_header.public_symbols.size());
	for (s_symbol_file_public_temp& temp_public_symbol : temp_header.public_symbols)
	{
		s_symbol_file_public& public_symbol = enqueue_header(s_symbol_file_public);
		public_symbol.section_index = temp_public_symbol.section_index;
		public_symbol.rva = temp_public_symbol.rva;
		public_symbol.rva_plus_base = temp_public_symbol.rva_plus_base;
		public_symbol.symbol_name_offset = enqueue_string(temp_public_symbol.symbol_name);
		public_symbol.lib_and_object_offset = enqueue_string(temp_public_symbol.lib_and_object);
		public_symbol.mangled_symbol_name_offset = enqueue_string(temp_public_symbol.mangled_symbol_name_buffer);
#ifndef _DEBUG
		public_symbol.complete_symbol_name_offset = enqueue_string(temp_public_symbol.complete_symbol_name);
#endif

		temp_public_symbol.public_symbol = &public_symbol;
	}

	header.static_symbols_offset = symbols_blob.size();
	header.static_symbols_count = static_cast<unsigned long>(temp_header.static_symbols.size());
	for (s_symbol_file_static_temp& temp_static_symbol : temp_header.static_symbols)
	{
		s_symbol_file_static& static_symbol = enqueue_header(s_symbol_file_static);
		static_symbol.section_index = temp_static_symbol.section_index;
		static_symbol.rva = temp_static_symbol.rva;
		static_symbol.rva_plus_base = temp_static_symbol.rva_plus_base;
		static_symbol.symbol_name_offset = enqueue_string(temp_static_symbol.symbol_name);
		static_symbol.lib_and_object_offset = enqueue_string(temp_static_symbol.lib_and_object);
		static_symbol.mangled_symbol_name_offset = enqueue_string(temp_static_symbol.mangled_symbol_name_buffer);
#ifndef _DEBUG
		static_symbol.complete_symbol_name_offset = enqueue_string(temp_static_symbol.complete_symbol_name);
#endif

		temp_static_symbol.static_symbol = &static_symbol;
	}

//	for (s_symbol_file_section_temp& temp_section : temp_header.sections)
//	{
//		s_symbol_file_section& section = *temp_section.section;
//		section.name_string_offset = enqueue_string(temp_section.name_string);
//		section.class_string_offset = enqueue_string(temp_section.class_string);
//	}
//
//	for (s_symbol_file_public_temp& temp_public_symbol : temp_header.public_symbols)
//	{
//		s_symbol_file_public& public_symbol = *temp_public_symbol.public_symbol;
//		public_symbol.lib_and_object_offset = enqueue_string(temp_public_symbol.lib_and_object);
//		public_symbol.mangled_symbol_name_offset = enqueue_string(temp_public_symbol.mangled_symbol_name_buffer);
//#ifndef _DEBUG
//		public_symbol.complete_symbol_name_offset = enqueue_string(temp_public_symbol.complete_symbol_name);
//#endif
//	}
//
//	for (s_symbol_file_static_temp& temp_static_symbol : temp_header.static_symbols)
//	{
//		s_symbol_file_static& static_symbol = *temp_static_symbol.static_symbol;
//		static_symbol.lib_and_object_offset = enqueue_string(temp_static_symbol.lib_and_object);
//		static_symbol.mangled_symbol_name_offset = enqueue_string(temp_static_symbol.mangled_symbol_name_buffer);
//#ifndef _DEBUG
//		static_symbol.complete_symbol_name_offset = enqueue_string(temp_static_symbol.complete_symbol_name);
//#endif
//	}

	symbols_blob.insert(symbols_blob.end(), appended_data.begin(), appended_data.end());
}

void t_symbol_file_parser::write_output(const wchar_t* output_filepath)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = filesystem_write_file_from_memory(output_filepath, symbols_blob.data(), symbols_blob.size())))
	{
		console_write_line("Failed to write output file");
		FATAL_ERROR("Failed to write output file");
	}

	// #TODO: cleanup
}