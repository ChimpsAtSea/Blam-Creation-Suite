#pragma once

struct s_symbol_file_public;

namespace blofeld
{
	struct s_tag_block_definition;

	struct s_tag_group
	{
		BCS_SHARED s_tag_group(
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

#define TAG_GROUP_V7(symbol, group_tag, parent_group, parent_group_tag, block) \
s_tag_group symbol = s_tag_group(#symbol, #symbol, #symbol, __FILE__, __LINE__, #group_tag, group_tag, parent_group_tag, block, parent_group);

#define TAG_GROUP(name, symbol, group_tag, version, parent_group, block) \
s_tag_group symbol = s_tag_group(name, name, #symbol, __FILE__, __LINE__, #group_tag, group_tag, version, block, parent_group);
