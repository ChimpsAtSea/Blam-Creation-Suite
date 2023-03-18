#include "blamtoozle-private-pch.h"

void nuke_trailing_extension(char* string, const char* extension)
{
	char* search = __max(string, string + (strlen(string) + 1) - (strlen(extension) + 1));
	if (strcmp(search, extension) == 0)
	{
		*search = 0;
	}
}

void replace_trailing_extension(char* string, size_t buffer_size, const char* extension, const char* replacement)
{
	char* search = __max(string, string + (strlen(string) + 1) - (strlen(extension) + 1));
	if (strcmp(search, extension) == 0)
	{
		size_t buffer_size2 = buffer_size - static_cast<size_t>((search - string) * sizeof(search));
		strcpy_s(search, buffer_size2, replacement);
	}
}

void cleanup_code_symbol_name(char* buffer, size_t buffer_size)
{
	replace_trailing_extension(buffer, buffer_size, "_struct_struct_definition", "_struct_definition");
	nuke_trailing_extension(buffer, "_struct_definition");

	if (strstr(buffer, "g_") == buffer)
	{
		memmove(buffer, buffer + 2, strlen(buffer + 2) + 1);
	}

	if (strstr(buffer, "c_") == buffer)
	{
		memmove(buffer, buffer + 2, strlen(buffer + 2) + 1);
	}

	if (strstr(buffer, "s_") != buffer)
	{

		memmove(buffer + 2, buffer, strlen(buffer) + 1);
		strncpy_s(buffer, buffer_size, "s_", 2);
	}

	while (strstr(buffer + 1, "__") == buffer + 1)
	{

		memmove(buffer + 1, buffer + 2, strlen(buffer + 1) + 1);

	}
}

bool has_trailing_extension(char* string, const char* extension)
{
	char* search = __max(string, string + (strlen(string) + 1) - (strlen(extension) + 1));
	return strcmp(search, extension) == 0;
}

void blamtoozle_generate_source(
	c_blamtoozle_tag_definition_manager& tag_definition_manager,
	const wchar_t* tag_definitions_output_directory,
	const wchar_t* tag_groups_output_directory,
	const char* engine_namespace,
	const char* platform_namespace,
	const char* _source_suffix)
{
	c_blamtoozle_source_generator source_generator(tag_definition_manager, engine_namespace, platform_namespace);

	std::wstring source_suffix;
	if (_source_suffix)
	{
		source_suffix += L"-";
		BCS_CHAR_TO_WIDECHAR_STACK(_source_suffix, _source_suffix_wc);
		source_suffix += _source_suffix_wc;
	}

	std::wstringstream output_header_stream;
	output_header_stream << std::wstring(tag_definitions_output_directory) << engine_namespace << source_suffix << "-" << platform_namespace << L".h";

	std::wstringstream output_source_stream;
	output_source_stream << std::wstring(tag_definitions_output_directory) << engine_namespace << source_suffix << "-" << platform_namespace << L".cpp";

	std::wstringstream output_tag_groups_header_stream;
	output_tag_groups_header_stream << std::wstring(tag_groups_output_directory) << engine_namespace << source_suffix << "-" << platform_namespace << L"-groups.h";

	std::wstringstream output_tag_groups_source_stream;
	output_tag_groups_source_stream << std::wstring(tag_groups_output_directory) << engine_namespace << source_suffix << "-" << platform_namespace << L"-groups.cpp";

	std::wstring output_header = output_header_stream.str();
	std::wstring output_source = output_source_stream.str();
	std::wstring output_tag_groups_header = output_tag_groups_header_stream.str();
	std::wstring output_tag_groups_source = output_tag_groups_source_stream.str();

	source_generator.export_single_tag_definitions_header(output_header.c_str());
	source_generator.export_single_tag_definitions_source(output_source.c_str());
	source_generator.export_tag_groups_header(output_tag_groups_header.c_str());
	source_generator.export_tag_groups_source(output_tag_groups_source.c_str());
}
