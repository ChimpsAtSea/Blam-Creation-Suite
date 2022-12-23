#pragma once

enum e_halo1_tools_pc64_tag_reference_definition_flags // #TODO: Check these. Strings should be in executable.
{
	_halo1_tools_pc64_tag_reference_flag_not_a_dependency,
	_halo1_tools_pc64_tag_reference_flag_dont_resolve_in_editor,
	_halo1_tools_pc64_tag_reference_flag_resolved_manually,
	_halo1_tools_pc64_tag_reference_flag_resolved_by_game,
	_halo1_tools_pc64_tag_reference_flag_not_a_resource_dependency,
	_halo1_tools_pc64_tag_reference_flag_dependency_for_cache_file_sharing,
	_halo1_tools_pc64_tag_reference_flag_reference_ignored_by_bundle_builder
};

struct s_halo1_tools_pc64_tag_reference_definition
{
	c_flags<e_halo1_tools_pc64_tag_reference_definition_flags, unsigned int> flags;
	tag group_tag;
	ptr32 group_tags_address;
};
constexpr size_t k_halo1_tools_pc64_tag_reference_definition_size = sizeof(s_halo1_tools_pc64_tag_reference_definition);
static_assert(k_halo1_tools_pc64_tag_reference_definition_size == 12);

class c_halo1_tools_pc64_tag_reference_definition :
	public c_blamtoozle_tag_reference_definition
{
protected:
	c_halo1_tools_pc64_tag_reference_definition(c_halo1_tools_pc64_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_halo1_tools_pc64_tag_reference_definition(const c_halo1_tools_pc64_tag_reference_definition&) = delete;
	c_halo1_tools_pc64_tag_reference_definition(c_halo1_tools_pc64_tag_reference_definition&&) = delete;
	~c_halo1_tools_pc64_tag_reference_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo1_tools_pc64_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual blofeld::f_tag_reference_flags get_tag_reference_flags() override;

protected:
	ptr32 definition_address;
	s_halo1_tools_pc64_tag_reference_definition reference_definition;
	std::string name;
	std::string code_symbol_name;
	blofeld::f_tag_reference_flags tag_reference_flags;
};
