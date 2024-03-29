#pragma once

namespace blofeld
{
	class c_tag_struct_definition_view;
	struct s_string_list_definition;
	struct s_tag_struct_definition;
	struct s_tag_block_definition;
	struct s_tag_group;

	bool definition_migration_compare_string_list(
		const s_string_list_definition& old_string_list_definition,
		const s_string_list_definition& new_string_list_definition,
		s_engine_platform_build engine_platform_build);

	bool definition_migration_compare_struct(
		const s_tag_struct_definition& old_struct_definition,
		const s_tag_struct_definition& new_struct_definition,
		s_engine_platform_build engine_platform_build);

	bool definition_migration_compare_block(
		s_tag_block_definition const& old_block_definition,
		s_tag_block_definition const& new_block_definition,
		s_engine_platform_build engine_platform_build);

	// #TODO: Convert this over to BCS_RESULT
	BCS_SHARED bool definition_migration(
		const s_tag_group** old_tag_groups,
		const s_tag_group** new_tag_groups,
		s_engine_platform_build engine_platform_build);

	BCS_SHARED BCS_RESULT definition_duplicate_check(c_tag_struct_definition_view& tag_structs_view);

}
