#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo3_tools_pc64_tag_definition_manager&>(tag_definition_manager)

thread_local c_halo3_tools_pc64_tag_group_definition* c_halo3_tools_pc64_tag_group_definition::current_group_traverse_hack;

template<> void byteswap_inplace(s_halo3_tools_pc64_tag_group_definition& value)
{
	byteswap_inplace(value.name_address);
	byteswap_inplace(value.flags);
	byteswap_inplace(value.group_tag);
	byteswap_inplace(value.parent_group_tag);
	byteswap_inplace(value.version);
	byteswap_inplace(value._padding12);
	byteswap_inplace(value.vtable_shim);
	byteswap_inplace(value.block_definition_address);
}

c_halo3_tools_pc64_tag_group_definition::c_halo3_tools_pc64_tag_group_definition(c_halo3_tools_pc64_tag_definition_manager& _tag_definition_manager, ptr64 _definition_address) :
	c_blamtoozle_tag_group_definition(_tag_definition_manager),
	definition_address(_definition_address),
	group_definition(tag_definition_manager.read_structure<s_halo3_tools_pc64_tag_group_definition>(_definition_address)),
	name(tag_definition_manager.va_to_pointer(group_definition.name_address)),
	code_symbol_name(name),
	group_tag_macro_name(name),
	tag_block_definition()
{
	unsigned int unknown_checksum = 0;
	for (unsigned char& c : group_definition.unknown)
	{
		unknown_checksum += c;
	}
	unsigned int unknown2_checksum = 0;
	for (unsigned char& c : group_definition.unknown2)
	{
		unknown2_checksum += c;
	}

	ASSERT(unknown_checksum == 0);
	ASSERT(group_definition.child_count == 0);
	ASSERT(group_definition.default_directory == 0);
	ASSERT(unknown2_checksum == 0);

	code_symbol_name += "_group";
	group_tag_macro_name += "_TAG";

	for (char& c : group_tag_macro_name) c = toupper(c);

	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);
}

c_halo3_tools_pc64_tag_group_definition::~c_halo3_tools_pc64_tag_group_definition()
{

}

void c_halo3_tools_pc64_tag_group_definition::traverse()
{
	current_group_traverse_hack = this;

	tag_block_definition = &tag_definition_manager.eval_block(group_definition.block_definition_address);
	tag_block_definition->associate_tag_group_definition(this);

	if (strcmp(code_symbol_name.c_str(), tag_block_definition->struct_definition.code_symbol_name.c_str()) == 0)
	{
		tag_block_definition->struct_definition.code_symbol_name += "_struct_definition";
	}

	current_group_traverse_hack = nullptr;
}

blofeld::f_tag_group_flags c_halo3_tools_pc64_tag_group_definition::get_tag_group_flags()
{
	blofeld::f_tag_group_flags tag_group_flags;

	tag_group_flags.set(blofeld::_tag_group_flag_is_game_critical, group_definition.flags.test(_halo3_tag_group_flag_is_game_critical));
	tag_group_flags.set(blofeld::_tag_group_flag_can_be_reloaded, group_definition.flags.test(_halo3_tag_group_flag_can_be_reloaded));
	tag_group_flags.set(blofeld::_tag_group_flag_forces_map_reload, group_definition.flags.test(_halo3_tag_group_flag_forces_map_reload));
	tag_group_flags.set(blofeld::_tag_group_flag_forces_lighting_reset, group_definition.flags.test(_halo3_tag_group_flag_forces_lighting_reset));
	tag_group_flags.set(blofeld::_tag_group_flag_does_not_exist_in_cache_build, group_definition.flags.test(_halo3_tag_group_flag_does_not_exist_in_cache_build));
	tag_group_flags.set(blofeld::_tag_group_flag_can_save_when_not_loaded_for_editing, group_definition.flags.test(_halo3_tag_group_flag_can_save_when_not_loaded_for_editing));
	tag_group_flags.set(blofeld::_tag_group_flag_do_not_attempt_to_predict_on_cache_miss, group_definition.flags.test(_halo3_tag_group_flag_do_not_attempt_to_predict_on_cache_miss));
	tag_group_flags.set(blofeld::_tag_group_flag_do_not_attempt_to_predict_through_dependencies, group_definition.flags.test(_halo3_tag_group_flag_do_not_attempt_to_predict_through_dependencies));
	tag_group_flags.set(blofeld::_tag_group_flag_do_not_attempt_to_predict_children, group_definition.flags.test(_halo3_tag_group_flag_do_not_attempt_to_predict_children));
	tag_group_flags.set(blofeld::_tag_group_flag_do_not_xsync_to_target_platform, group_definition.flags.test(_halo3_tag_group_flag_do_not_xsync_to_target_platform));
	tag_group_flags.set(blofeld::_tag_group_flag_restricted_on_xsync, group_definition.flags.test(_halo3_tag_group_flag_restricted_on_xsync));
	tag_group_flags.set(blofeld::_tag_group_flag_create_as_global_cache_file_tag, group_definition.flags.test(_halo3_tag_group_flag_create_as_global_cache_file_tag));
	tag_group_flags.set(blofeld::_tag_group_flag_do_not_add_children_to_global_zone, group_definition.flags.test(_halo3_tag_group_flag_do_not_add_children_to_global_zone));
	tag_group_flags.set(blofeld::_tag_group_flag_invalidates_structure_materials, group_definition.flags.test(_halo3_tag_group_flag_invalidates_structure_materials));
	tag_group_flags.set(blofeld::_tag_group_flag_children_resolved_manually, group_definition.flags.test(_halo3_tag_group_flag_children_resolved_manually));
	tag_group_flags.set(blofeld::_tag_group_flag_forces_script_recompile, group_definition.flags.test(_halo3_tag_group_flag_forces_script_recompile));
	tag_group_flags.set(blofeld::_tag_group_flag_forces_active_zone_set_reload, group_definition.flags.test(_halo3_tag_group_flag_forces_active_zone_set_reload));
	tag_group_flags.set(blofeld::_tag_group_flag_restricted_forces_active_zone_set_reload, group_definition.flags.test(_halo3_tag_group_flag_restricted_forces_active_zone_set_reload));
	tag_group_flags.set(blofeld::_tag_group_flag_cannot_be_created, group_definition.flags.test(_halo3_tag_group_flag_cannot_be_created));
	tag_group_flags.set(blofeld::_tag_group_flag_should_not_be_used_as_a_resolving_reference, group_definition.flags.test(_halo3_tag_group_flag_should_not_be_used_as_a_resolving_reference));
	tag_group_flags.set(blofeld::_tag_group_flag_do_not_make_script_dependency, group_definition.flags.test(_halo3_tag_group_flag_do_not_make_script_dependency));
	tag_group_flags.set(blofeld::_tag_group_flag_do_not_write_out_until_cache_file_link_time, group_definition.flags.test(_halo3_tag_group_flag_do_not_write_out_until_cache_file_link_time));
	tag_group_flags.set(blofeld::_tag_group_flag_not_language_neutral, group_definition.flags.test(_halo3_tag_group_flag_not_language_neutral));
	tag_group_flags.set(blofeld::_tag_group_flag_invalidates_structure_bsp_geometry, group_definition.flags.test(_halo3_tag_group_flag_invalidates_structure_bsp_geometry));
	tag_group_flags.set(blofeld::_tag_group_flag_discard_for_dedicated_server, group_definition.flags.test(_halo3_tag_group_flag_discard_for_dedicated_server));

	return tag_group_flags;
}

const char* c_halo3_tools_pc64_tag_group_definition::get_name()
{
	return name;
}

const char* c_halo3_tools_pc64_tag_group_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}

const char* c_halo3_tools_pc64_tag_group_definition::get_group_tag_macro_name()
{
	return group_tag_macro_name.c_str();
}

uint32_t c_halo3_tools_pc64_tag_group_definition::get_version()
{
	return group_definition.version;
}

tag c_halo3_tools_pc64_tag_group_definition::get_group_tag()
{
	return group_definition.group_tag;
}

tag c_halo3_tools_pc64_tag_group_definition::get_parent_group_tag()
{
	return group_definition.parent_group_tag;
}

c_blamtoozle_tag_block_definition& c_halo3_tools_pc64_tag_group_definition::get_block_definition()
{
	ASSERT(tag_block_definition != nullptr);
	return *tag_block_definition;
}
