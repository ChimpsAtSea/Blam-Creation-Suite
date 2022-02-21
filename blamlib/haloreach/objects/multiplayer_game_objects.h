#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/real_math.h>
#include <blamlib/memory/static_arrays.h>
#include <blamlib/tag_files/tag_groups.h>

/* ---------- constants */

constexpr int k_maximum_number_of_multiplayer_object_definitions = 1;

/* ---------- types */

enum e_multiplayer_object_type
{
	_multiplayer_object_type_ordinary,
	_multiplayer_object_type_weapon,
	_multiplayer_object_type_grenade,
	_multiplayer_object_type_projectile,
	_multiplayer_object_type_powerup,
	_multiplayer_object_type_equipment,
	_multiplayer_object_type_ammo_pack,
	_multiplayer_object_type_light_land_vehicle,
	_multiplayer_object_type_heavy_land_vehicle,
	_multiplayer_object_type_flying_vehicle,
	_multiplayer_object_type_turret,
	_multiplayer_object_type_device,
	_multiplayer_object_type_teleporter_2_way,
	_multiplayer_object_type_teleporter_sender,
	_multiplayer_object_type_teleporter_receiver,
	_multiplayer_object_type_player_spawn_location,
	_multiplayer_object_type_player_respawn_zone,
	_multiplayer_object_type_secondary_objective,
	_multiplayer_object_type_primary_objective,
	_multiplayer_object_type_named_location_area,
	_multiplayer_object_type_danger_zone,
	_multiplayer_object_type_fireteam_1_respawn_zone,
	_multiplayer_object_type_fireteam_2_respawn_zone,
	_multiplayer_object_type_fireteam_3_respawn_zone,
	_multiplayer_object_type_fireteam_4_respawn_zone,
	_multiplayer_object_type_safe_volume,
	_multiplayer_object_type_kill_volume,
	_multiplayer_object_type_cinematic_camera_position,
	k_number_of_multiplayer_object_types
};

enum e_multiplayer_object_teleporter_flags
{
	_multiplayer_object_teleporter_disallow_players_bit,
	_multiplayer_object_teleporter_allow_light_land_vehicles_bit,
	_multiplayer_object_teleporter_allow_heavy_land_vehicles_bit,
	_multiplayer_object_teleporter_allow_flying_vehicles_bit,
	_multiplayer_object_teleporter_allow_projectiles_bit,
	k_number_of_multiplayer_object_teleporter_flags
};

enum e_multiplayer_object_boundary_shape
{
	_multiplayer_object_boundary_shape_none,
	_multiplayer_object_boundary_shape_sphere,
	_multiplayer_object_boundary_shape_cylinder,
	_multiplayer_object_boundary_shape_box,
	k_number_of_multiplayer_object_boundary_shapes
};

enum e_multiplayer_object_spawn_timer_type
{
	_multiplayer_object_spawn_timer_starts_on_death,
	_multiplayer_object_spawn_timer_starts_on_disturbance,
	k_number_of_multiplayer_object_spawn_timer_types
};

enum e_multiplayer_object_flags
{
	_multiplayer_object_only_render_in_editor_bit,
	_multiplayer_object_phased_physics_in_forge_bit,
	_multiplayer_object_valid_initial_player_spawn_bit,
	_multiplayer_object_fixed_boundary_orientation_bit,
	_multiplayer_object_candy_monitor_should_ignore_bit,
	_multiplayer_object_inherit_owning_team_color_bit,
	_multiplayer_object_boundary_volume_doesnt_kill_immediately_bit,
	_multiplayer_object_only_collision_in_editor_bit,
	_multiplayer_object_only_physics_in_editor_bit,
	_multiplayer_object_force_render_in_forge_bit,
	_multiplayer_object_respawn_player_spawn_bit,
	_multiplayer_object_fallback_player_spawn_bit,
	k_number_of_multiplayer_object_flags
};

struct s_multiplayer_object_boundary_shader_definition
{
	s_tag_reference standard_shader;
	s_tag_reference opaque_shader;
};
static_assert(sizeof(s_multiplayer_object_boundary_shader_definition) == 0x20);

struct s_multiplayer_object_definition
{
	c_enum<e_multiplayer_object_type, short> type;
	c_flags<e_multiplayer_object_teleporter_flags, byte> teleporter_passability;
	char : 8;
	real boundary_width;
	real boundary_length;
	real boundary_top;
	real boundary_bottom;
	c_enum<e_multiplayer_object_boundary_shape, char> boundary_shape;
	c_enum<e_multiplayer_object_spawn_timer_type, char> spawn_timer_type;
	short default_spawn_time;
	short default_abandon_time;
	c_flags<e_multiplayer_object_flags, word> flags;
	real normal_weight;
	string_id boundary_center_marker;
	string_id spawned_object_marker_name;
	s_tag_reference spawned_object;
	string_id nyi_boundary_material;
	s_multiplayer_object_boundary_shader_definition boundary_shaders[
		k_number_of_multiplayer_object_boundary_shapes];
};
static_assert(sizeof(s_multiplayer_object_definition) == 0xBC);
