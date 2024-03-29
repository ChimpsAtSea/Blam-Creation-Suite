#include "tagframework-private-pch.h"

using namespace blofeld;

s_tag_group::s_tag_group(
	const char* const _name,
	const char* const _pretty_name,
	const char* const _symbol_name,
	const char* const _filename,
	int32_t const _line,
	const char* const _group_tag_macro_symbol,
	uint32_t const _group_tag,
	uint32_t const _version,
	s_tag_block_definition const& _block_definition,
	const s_tag_group* const _parent_tag_group) :
	name(_name),
	pretty_name(_pretty_name),
	flags(),
	group_tag(_group_tag),
	version(_version),
	block_definition(_block_definition),
	parent_tag_group(_parent_tag_group),
	group_tag_short_string(),
	group_tag_macro_symbol(_group_tag_macro_symbol),
	symbol_name(_symbol_name),
	filename(_filename),
	line(_line)
{
	uint32_t group_tag_swap = _byteswap_ulong(group_tag);
	snprintf(group_tag_short_string, _countof(group_tag_short_string), "%.4s", reinterpret_cast<const char*>(&group_tag_swap));
}

s_tag_group::s_tag_group(
	const char* const _name,
	const char* const _pretty_name,
	const char* const _symbol_name,
	const char* const _filename,
	int32_t const _line,
	f_tag_group_flags _flags,
	const char* const _group_tag_macro_symbol,
	uint32_t const _group_tag,
	uint32_t const _version,
	s_tag_block_definition const& _block_definition,
	const s_tag_group* const _parent_tag_group) :
	name(_name),
	pretty_name(_pretty_name),
	flags(_flags),
	group_tag(_group_tag),
	version(_version),
	block_definition(_block_definition),
	parent_tag_group(_parent_tag_group),
	group_tag_short_string(),
	group_tag_macro_symbol(_group_tag_macro_symbol),
	symbol_name(_symbol_name),
	filename(_filename),
	line(_line)
{
	uint32_t group_tag_swap = _byteswap_ulong(group_tag);
	snprintf(group_tag_short_string, _countof(group_tag_short_string), "%.4s", reinterpret_cast<const char*>(&group_tag_swap));
}