#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_block_definition;

	struct s_tag_group
	{
		s_tag_group(
			const char* const name,
			unsigned long const group_tag,
			unsigned long const parent_group_tag,
			const s_tag_block_definition& block_definition,
			const s_tag_group* const parent_tag_group
		);

		const char* const name;
		unsigned long const group_tag;
		unsigned long const parent_group_tag;
		const s_tag_block_definition& block_definition;
		const s_tag_group* const parent_tag_group;
		c_fixed_string_16 group_tag_str;
		s_symbol_file_public* symbol;
	};
}
