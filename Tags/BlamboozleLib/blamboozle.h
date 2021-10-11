#pragma once

enum e_blamboozle_binary
{
	_blamboozle_binary_halo1_guerilla,
	_blamboozle_binary_halo2_guerilla,
	_blamboozle_binary_halo5_forge
};

uint64_t make_tool_version_runtime(uint64_t library_file_version, const wchar_t* library_description, const wchar_t* library_product_name);
int blamboozle_run();
int blamboozle_run(const wchar_t* output_directory, const wchar_t* binary_filepath, e_engine_type engine_type, e_build build = _build_not_set, bool skip_hash_check = false);
