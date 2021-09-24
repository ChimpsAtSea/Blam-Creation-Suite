#include "tagdefinitions-private-pch.h"

using namespace blofeld;

s_tag_group::s_tag_group(
	const char* const name,
	const char* const filename,
	long const line,
	const char* const _group_tag_code_string,
	unsigned long const group_tag,
	unsigned long const parent_group_tag,
	const s_tag_block_definition& block_definition,
	const s_tag_group* const parent_tag_group) :
	name(name),
	group_tag(group_tag),
	parent_group_tag(parent_group_tag),
	block_definition(block_definition),
	parent_tag_group(parent_tag_group),
	group_tag_code_string(),
	group_tag_short_string(),
	symbol(c_runtime_symbols::runtime().get_public_symbol_by_virtual_address(this)),
	filename(filename),
	line(line)
{
	strncpy(group_tag_code_string, _group_tag_code_string, _countof(group_tag_code_string));
	unsigned long group_tag_swap = _byteswap_ulong(group_tag);
	snprintf(group_tag_short_string, _countof(group_tag_short_string), "%.4s", reinterpret_cast<const char*>(&group_tag_swap));
}
