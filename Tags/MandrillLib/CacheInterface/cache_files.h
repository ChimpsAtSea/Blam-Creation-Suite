#pragma once

enum CF_RESULT
{
	CF_ERR_GENERIC = -1,
	CF_SUCCESS = 0,
};

#define CF_FAILED(result) (result < 0)
#define CF_SUCCEEDED(result) (result >= 0)

struct s_cache_file_build_info
{
	e_engine_type engine_type;
	e_platform_type platform_type;
	e_build build;
};

CF_RESULT get_cache_file_build_info(const char* filepath, s_cache_file_build_info& build_info);





