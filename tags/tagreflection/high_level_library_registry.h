#pragma once

class h_extended_type;
class h_prototype;
class h_prototype_serialization_info;

enum e_high_level_vtable_type
{
	_high_level_vtable_prototype,
	_high_level_vtable_field,
	k_num_high_level_vtable_types
};

struct h_high_level_function_table
{
	e_high_level_vtable_type high_level_vtable_type;
};

using t_create_high_level_prototype = h_prototype * (*)(const blofeld::s_tag_struct_definition& tag_struct_definition, h_prototype* copy_from_prototype);
using t_get_high_level_prototype_serialization_info = h_prototype_serialization_info const* (*)(const blofeld::s_tag_struct_definition& tag_struct_definition);

BCS_SHARED extern h_high_level_function_table** global_vtables[0x100];

BCS_SHARED extern BCS_RESULT high_level_registry_init();
BCS_SHARED extern BCS_RESULT high_level_registry_deinit();
BCS_SHARED extern BCS_RESULT high_level_registry_register_global_vtable(
	unsigned int global_vftable_index,
	s_engine_platform_build engine_platform_build,
	h_high_level_function_table** global_vtable,
	t_create_high_level_prototype create_high_level_prototype,
	t_get_high_level_prototype_serialization_info get_high_level_prototype_serialization_info);
BCS_SHARED extern BCS_RESULT high_level_registry_unregister_global_vtable(
	unsigned int global_vftable_index,
	s_engine_platform_build engine_platform_build);
BCS_SHARED extern BCS_RESULT high_level_registry_create_high_level_prototype(
	unsigned int global_vtables_index,
	unsigned int local_vtables_index,
	h_prototype*& prototype,
	h_extended_type* parent,
	h_prototype* copy_from_prototype = nullptr);
BCS_SHARED extern BCS_RESULT high_level_registry_create_high_level_prototype(
	s_engine_platform_build engine_platform_build,
	const blofeld::s_tag_struct_definition& tag_struct_definition,
	h_prototype*& prototype,
	h_prototype* copy_from_prototype = nullptr);
BCS_SHARED extern BCS_RESULT high_level_registry_get_high_level_prototype_serialization_info(
	s_engine_platform_build engine_platform_build,
	const blofeld::s_tag_struct_definition& tag_struct_definition,
	h_prototype_serialization_info const*& prototype_serialization_info);
