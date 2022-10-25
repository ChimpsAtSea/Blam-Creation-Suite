#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_block_definition;

	struct s_tag_group
	{
		s_tag_group(
			const char* const name,
			const char* const pretty_name,
			const char* const symbol_name,
			const char* const filename,
			int32_t const line,
			const char* const group_tag_macro_symbol,
			uint32_t const group_tag,
			uint32_t const version,
			const s_tag_block_definition& block_definition,
			const s_tag_group* const parent_tag_group
		);

		const char* const name;
		const char* const pretty_name;
		uint32_t const group_tag;
		uint32_t const version;
		const s_tag_block_definition& block_definition;
		const s_tag_group* const parent_tag_group;
		char group_tag_short_string[8];
		s_symbol_file_public* symbol;
		const char* const group_tag_macro_symbol;
		const char* const symbol_name;
		const char* const filename;
		int32_t const line;
	};
}
