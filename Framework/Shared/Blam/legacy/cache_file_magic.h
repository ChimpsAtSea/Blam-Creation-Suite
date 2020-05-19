#pragma once

enum e_cache_file_magic : uint32_t
{
	_cache_file_magic_header = 'head',
	_cache_file_magic_footer = 'foot',
	_cache_file_magic_tags = 'tags',
	_cache_file_magic_section = '343i',
};