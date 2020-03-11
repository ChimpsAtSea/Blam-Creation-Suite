#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>

/* ---------- enumerators */

enum e_vertex_type
{
	_vertex_type_none = NONE,
	_vertex_type_world,
	_vertex_type_rigid,
	_vertex_type_skinned,
	_vertex_type_particle_model,
	_vertex_type_flat_world,
	_vertex_type_flat_rigid,
	_vertex_type_flat_skinned,
	_vertex_type_screen,
	_vertex_type_debug,
	_vertex_type_transparent,
	_vertex_type_particle,
	_vertex_type_contrail,
	_vertex_type_light_volume,
	_vertex_type_chud_simple,
	_vertex_type_chud_fancy,
	_vertex_type_decorator,
	_vertex_type_tiny_position,
	_vertex_type_patchy_fog,
	_vertex_type_water,
	_vertex_type_ripple,
	_vertex_type_implicit,
	_vertex_type_beam,
	_vertex_type_world_tessellated,
	_vertex_type_rigid_tessellated,
	_vertex_type_skinned_tessellated,
	_vertex_type_shader_cache,
	_vertex_type_instance_imposter,
	_vertex_type_object_imposter,
	_vertex_type_rigid_compressed,
	_vertex_type_skinned_compressed,
	_vertex_type_light_volume_precompiled,
	_vertex_type_bink,
	//
	// TODO: finish
	//
	k_number_of_vertex_types
};

/* ---------- structures */

struct s_vertex_definition
{
	void *elements;
	long element_count;
	long : 32;
};

/* ---------- prototypes/VERTEX_DEFINITIONS.CPP */

s_vertex_definition *vertex_definition_get(
	e_vertex_type type);

long vertex_element_get_size(
	void *element_address);
