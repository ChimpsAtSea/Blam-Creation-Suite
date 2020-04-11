#include "mantlereflect-private-pch.h"

c_legacy_ast_source_generator::c_legacy_ast_source_generator(const wchar_t* output_header_file, const wchar_t* output_source_file) :
	output_header_file(output_header_file),
	output_source_file(output_source_file)
{

}

void c_legacy_ast_source_generator::write_output()
{
	if (output_header_file) write_output_impl(header_string_stream, output_header_file);
	if(output_source_file) write_output_impl(source_string_stream, output_source_file);
}

void c_legacy_ast_source_generator::write_output_impl(std::stringstream& stringstream, const wchar_t* output_file)
{
	std::string reflection_header_text = stringstream.str();

	bool reflection_header_data_is_same = false;
	{
		FILE* existing_reflection_header = _wfopen(output_file, L"rb");
		if (existing_reflection_header)
		{
			fseek(existing_reflection_header, 0L, SEEK_END);
			uint64_t reflection_header_length = _ftelli64(existing_reflection_header);
			if (reflection_header_text.size() == reflection_header_length)
			{
				fseek(existing_reflection_header, 0L, SEEK_SET);
				char* existing_reflection_header_data = new char[static_cast<size_t>(reflection_header_length + 1)]{};
				for (uint64_t current_read_position = 0; current_read_position < reflection_header_length;)
				{
					current_read_position += fread(existing_reflection_header_data + current_read_position, 1, static_cast<size_t>(reflection_header_length - current_read_position), existing_reflection_header);
				}
				if (strcmp(reflection_header_text.c_str(), existing_reflection_header_data) == 0)
				{
					reflection_header_data_is_same = true;
				}
				delete[] existing_reflection_header_data;
			}
			fclose(existing_reflection_header);
		}
	}

	if (!reflection_header_data_is_same)
	{
		wprintf(L"MantleReflect> Updating %s\n", output_file);
		FILE* pReflectionHeader = _wfopen(output_file, L"wb");
		ASSERT(pReflectionHeader != nullptr);
		fwrite(reflection_header_text.c_str(), 1, reflection_header_text.length(), pReflectionHeader);
		fflush(pReflectionHeader);
		fclose(pReflectionHeader);
	}
	else
	{
		wprintf(L"MantleReflect> Skipping %s (output hasn't changed)\n", output_file);
	}
}
