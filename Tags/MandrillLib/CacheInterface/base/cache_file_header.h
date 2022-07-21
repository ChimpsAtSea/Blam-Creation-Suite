#pragma once

/* ---------- constants */

constexpr tag k_cache_header_signature = 'head';
constexpr tag k_cache_footer_signature = 'foot';
constexpr tag k_cache_tags_signature = 'tags';
constexpr tag k_cache_343i_signature = '343i';

/* ---------- types */

struct s_cache_file_header
{
	tag header_signature; // k_cache_header_signature
	int32_t file_version;
	int32_t file_length;
	int32_t file_compressed_length;
};
