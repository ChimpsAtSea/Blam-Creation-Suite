/*
CACHE_FILES.H
Wednesday, February 26, 2020 12:22:43 PM
*/

#pragma once

#include <blamlib/cseries/cseries.h>

namespace blamlib
{

	/* ---------- constants */

	constexpr tag k_cache_header_signature = 'head';
	constexpr tag k_cache_footer_signature = 'foot';
	constexpr tag k_module_header_signature = 'mohd';
	constexpr tag k_cache_tags_signature = 'tags';
	constexpr tag k_cache_343i_signature = '343i';

	/* ---------- types */

	struct s_cache_file_header
	{
		tag header_signature;
		int file_version;
		int file_length;
		int file_compressed_length;
	};

}
