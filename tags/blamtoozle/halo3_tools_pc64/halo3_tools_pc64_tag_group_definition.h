#pragma once

#pragma once

class c_halo3_tools_pc64_tag_block_definition;
class c_halo3_tools_pc64_tag_struct_definition;

enum e_halo3_tag_group_flags
{
	_halo3_tag_group_flag_is_game_critical,
	_halo3_tag_group_flag_can_be_reloaded,
	_halo3_tag_group_flag_forces_map_reload,
	_halo3_tag_group_flag_forces_lighting_reset,
	_halo3_tag_group_flag_does_not_exist_in_cache_build,
	_halo3_tag_group_flag_can_save_when_not_loaded_for_editing,
	_halo3_tag_group_flag_do_not_attempt_to_predict_on_cache_miss,
	_halo3_tag_group_flag_do_not_attempt_to_predict_through_dependencies,
	_halo3_tag_group_flag_do_not_attempt_to_predict_children,
	_halo3_tag_group_flag_do_not_xsync_to_target_platform,
	_halo3_tag_group_flag_restricted_on_xsync,
	_halo3_tag_group_flag_create_as_global_cache_file_tag,
	_halo3_tag_group_flag_do_not_add_children_to_global_zone,
	_halo3_tag_group_flag_invalidates_structure_materials,
	_halo3_tag_group_flag_children_resolved_manually,
	_halo3_tag_group_flag_forces_script_recompile,
	_halo3_tag_group_flag_forces_active_zone_set_reload,
	_halo3_tag_group_flag_restricted_forces_active_zone_set_reload,
	_halo3_tag_group_flag_cannot_be_created,
	_halo3_tag_group_flag_should_not_be_used_as_a_resolving_reference,
	_halo3_tag_group_flag_do_not_make_script_dependency,
	_halo3_tag_group_flag_do_not_write_out_until_cache_file_link_time,
	_halo3_tag_group_flag_not_language_neutral,
	_halo3_tag_group_flag_invalidates_structure_bsp_geometry,
	_halo3_tag_group_flag_discard_for_dedicated_server,
	k_num_halo3_tag_group_flags
};

struct s_halo3_tools_pc64_tag_group_definition
{
	ptr64 name_address;
	c_flags<e_halo3_tag_group_flags, unsigned int, k_num_halo3_tag_group_flags> flags;
	tag group_tag;
	tag parent_group_tag;
	unsigned short version;
	unsigned short _padding12;
	ptr64 vtable_shim;
	ptr64 block_definition_address;
	unsigned char unknown[132];
	unsigned int child_count;
	ptr64 default_directory;
	unsigned char unknown2[288];
};
constexpr size_t k_halo3_tools_pc64_tag_group_size = sizeof(s_halo3_tools_pc64_tag_group_definition);
static_assert(k_halo3_tools_pc64_tag_group_size == 472);

class c_halo3_tools_pc64_tag_group_definition :
	public c_blamtoozle_tag_group_definition
{
protected:
	c_halo3_tools_pc64_tag_group_definition(c_halo3_tools_pc64_tag_definition_manager& tag_definition_manager, ptr64 definition_address);
	c_halo3_tools_pc64_tag_group_definition(const c_halo3_tools_pc64_tag_group_definition&) = delete;
	c_halo3_tools_pc64_tag_group_definition(c_halo3_tools_pc64_tag_group_definition&&) = delete;
	~c_halo3_tools_pc64_tag_group_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo3_tools_pc64_tag_definition_manager;
	friend c_halo3_tools_pc64_tag_struct_definition;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_group_tag_macro_name() override;
	virtual uint32_t get_version() override;
	virtual tag get_group_tag() override;
	virtual tag get_parent_group_tag() override;
	virtual c_blamtoozle_tag_block_definition& get_block_definition() override;
	virtual void traverse() override;
	virtual blofeld::f_tag_group_flags get_tag_group_flags() override;

protected:
	static thread_local c_halo3_tools_pc64_tag_group_definition* current_group_traverse_hack;

	ptr64 definition_address;
	s_halo3_tools_pc64_tag_group_definition group_definition;
	const char* name;
	std::string code_symbol_name;
	std::string group_tag_macro_name;
	c_halo3_tools_pc64_tag_block_definition* tag_block_definition;
};
