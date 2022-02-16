#pragma once

enum e_reach_x360_tag_reference_definition_flags // #TODO: Check these. Strings should be in executable.
{
	_reach_x360_tag_reference_flag_not_a_dependency,
	_reach_x360_tag_reference_flag_dont_resolve_in_editor,
	_reach_x360_tag_reference_flag_resolved_manually,
	_reach_x360_tag_reference_flag_resolved_by_game,
	_reach_x360_tag_reference_flag_not_a_resource_dependency,
	_reach_x360_tag_reference_flag_dependency_for_cache_file_sharing,
	_reach_x360_tag_reference_flag_reference_ignored_by_bundle_builder
};

struct s_reach_x360_tag_reference_definition
{
	c_flags<e_reach_x360_tag_reference_definition_flags, unsigned long> flags;
	btag group_tag;
	ptr32 group_tags_address;
};

class c_reach_x360_tag_group_definition;

class c_reach_x360_tag_reference_definition
{
public:
	std::vector<tag> group_tags;
	std::vector<c_reach_x360_tag_group_definition*> group_tags2;

	const s_reach_x360_tag_reference_definition& tag_reference_definition;

	c_fixed_string_1024 name;
	c_fixed_string_1024 code_name;

	c_reach_x360_tag_reference_definition(const char* guerilla_data, const s_reach_x360_tag_reference_definition& tag_reference_definition);
};

c_reach_x360_tag_reference_definition* reach_x360_get_tag_reference_definition(const char* guerilla_data, ptr32 virtual_address);
