#include "blamboozle-private-pch.h"

const char* c_console::g_console_executable_name = "Blamboozle";

enum e_blamboozle_binary
{
	_blamboozle_binary_halo1_guerilla,
	_blamboozle_binary_halo2_guerilla,
	_blamboozle_binary_halo5_forge
};

uint64_t make_tool_version_runtime(uint64_t library_file_version, const wchar_t* library_description, const wchar_t* library_product_name)
{
	//#define MAKE_TOOL_VERSION(a, b, c, d, file_description, product_name) (MAKE_FILE_VERSION(a, b, c, d) ^ (file_description##product_name##_xxh64))
	//	_build_halo1_guerilla = MAKE_TOOL_VERSION(1, 0, 0, 609, "Guerilla MFC Application", "Guerilla Application"),
	//	_build_halo2_guerilla = MAKE_TOOL_VERSION(1, 0, 0, 0, "Tag Editor", "Halo 2 for Windows Vista"),

	char buffer[1024]{};
	snprintf(buffer, _countof(buffer) - 1, "%S%S", library_description, library_product_name);

	uint64_t hash = xxh64(buffer, strlen(buffer));
	uint64_t result = library_file_version ^ hash;

	return result;
}

int run(const wchar_t* output_directory, const wchar_t* binary_filepath)
{
	char* binary_data = nullptr;
	size_t binary_data_size = 0;
	if (!read_file_to_memory(binary_filepath, reinterpret_cast<void**>(&binary_data), &binary_data_size))
	{
		write_line_verbose("Failed to open binary file");
		return 1;
	}

	if (binary_data_size == 0)
	{
		write_line_verbose("Binary file was zero sized");
		return 1;
	}

	e_engine_type engine_type = _engine_type_not_set;
	e_build build = _build_not_set;

	{
		uint64_t library_file_version = get_library_file_version(binary_filepath);
		std::wstring library_description = get_library_description(binary_filepath);
		std::wstring library_product_name = get_library_product_name(binary_filepath);

		uint64_t tool_version = make_tool_version_runtime(library_file_version, library_description.c_str(), library_product_name.c_str());

		if (tool_version == _build_halo1_guerilla)
		{
			build = _build_halo1_guerilla;
			engine_type = _engine_type_halo1;
		}
		else if (tool_version == _build_halo2_guerilla)
		{
			build = _build_halo2_guerilla;
			engine_type = _engine_type_halo2;
		}
	}

	if (build == _build_not_set)
	{
		uint64_t hash = xxhash::xxh64(binary_data, binary_data_size);

		if (hash == _build_halo5_forge_1_114_4592_2)
		{
			build = _build_halo5_forge_1_114_4592_2;
			engine_type = _engine_type_halo5_forge;
		}
	}

	delete[] binary_data;

	if (build == _build_not_set)
	{
		write_line_verbose("Unrecognised executable provided");
		return 1;
	}

	const char* build_nice_name = build_to_string(build);
	write_line_verbose("Found %s build", build_nice_name);

	const char* engine_type_name = engine_type_to_string(engine_type);

	switch (build)
	{
	case _build_halo1_guerilla:
	{
		c_blamboozle_h1_guerilla h1_guerilla = c_blamboozle_h1_guerilla(output_directory, binary_filepath);
		h1_guerilla.run();
	}
	break;
	case _build_halo2_guerilla:
	{
		c_blamboozle_h2_guerilla h2_guerilla = c_blamboozle_h2_guerilla(output_directory, binary_filepath);
		h2_guerilla.run();
	}
	break;
	case _build_halo5_forge_1_114_4592_2:
	{
		c_blamboozle_h5_forge h5_forge = c_blamboozle_h5_forge(output_directory, binary_filepath);
		h5_forge.run();
	}
	break;
	}

	return 0;
}

int wmain(int argc, const wchar_t** argv)
{
	if (argc < 3)
	{
		if (argc < 2)
		{
			write_line_verbose("No output directory specified");
		}
		else
		{
			write_line_verbose("No binary file(s) specified");
		}
		write_line_verbose("Usage <output directory> <binary ...>");
		return 1;
	}

	const wchar_t* output_directory = argv[2]; // #TODO: Validate

	int result = 0;

	for (int binary_index = 2; binary_index < argc; binary_index++)
	{
		const wchar_t* binary_filepath = argv[binary_index];

		result += run(output_directory, binary_filepath);
	}

	return result;
}