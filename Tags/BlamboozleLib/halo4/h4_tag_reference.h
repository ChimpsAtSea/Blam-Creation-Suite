#pragma once

struct s_h4_tag_reference_definition;

enum e_h4_tag_reference_definition_flags
{
	_h4_tag_reference_flag_not_a_dependency,
	_h4_tag_reference_flag_dont_resolve_in_editor,
	_h4_tag_reference_flag_resolved_manually,
	_h4_tag_reference_flag_resolved_by_game,
	_h4_tag_reference_flag_not_a_resource_dependency,
	_h4_tag_reference_flag_dependency_for_cache_file_sharing,
	_h4_tag_reference_flag_reference_ignored_by_bundle_builder
};

class c_h4_tag_reference
{
public:
	const s_h4_tag_reference_definition* reference_definition;
	c_flags<e_h4_tag_reference_definition_flags, unsigned long> flags;
	std::vector<tag_group> tag_groups;
	s_symbol_file_public* public_symbol;

	c_h4_tag_reference(const char* h4_data, const s_h4_tag_reference_definition* reference_definition, unsigned long definition_address);
};

