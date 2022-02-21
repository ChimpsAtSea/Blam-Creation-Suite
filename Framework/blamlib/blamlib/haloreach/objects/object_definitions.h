#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/haloreach/effects/jetwash.h>
#include <blamlib/math/real_math.h>
#include <blamlib/haloreach/objects/multiplayer_game_objects.h>
#include <blamlib/haloreach/objects/object_types.h>
#include <blamlib/haloreach/physics/water_physics.h>
#include <blamlib/tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_object_group_tag = 'obje';

constexpr int k_maximum_number_of_object_early_mover_obbs = 1;
constexpr int k_maximum_number_of_object_ai_properties = 1;
constexpr int k_maximum_number_of_object_functions = 256;
constexpr int k_maximum_number_of_object_function_interpolations = 2;
constexpr int k_maximum_number_of_object_runtime_interpolator_functions = k_maximum_number_of_object_functions;
constexpr int k_maximum_number_of_object_attachments = 48;
constexpr int k_maximum_number_of_object_widgets = 4;
constexpr int k_maximum_number_of_object_change_colors = 4;
constexpr int k_maximum_number_of_object_change_color_initial_permutations = 32;
constexpr int k_maximum_number_of_object_change_color_functions = k_maximum_number_of_object_change_colors;

/* ---------- types */

enum e_object_flags
{
	_object_does_not_cast_shadow_bit,
	_object_search_cardinal_direction_lightmaps_on_failure_bit,
	_object_preserves_initial_damage_owner_bit,
	_object_not_a_pathfinding_obstacle_bit,
	_object_extension_of_parent_bit,
	_object_does_not_cause_collision_damage_bit,
	_object_early_mover_bit,
	_object_early_mover_localized_physics_bit,
	_object_use_static_massive_lightmap_sample_bit,
	_object_scales_attachments_bit,
	_object_inherits_player_s_appearance_bit,
	_object_non_physical_in_map_editor_bit,
	_object_is_always_on_ceiling_bit,
	_object_sample_environment_lighting_only_ignore_object_lighting_bit,
	_object_effects_created_by_this_object_do_not_spawn_objects_in_multiplayer_bit,
	_object_does_not_collide_with_camera_bit,
	_object_force_collide_with_camera_bit,
	_object_damage_not_blocked_by_obstructions_bit,
	_object_does_not_damage_breakable_surfaces_bit,
	k_number_of_object_flags
};

enum e_object_lightmap_shadow_mode
{
	_object_lightmap_shadow_mode_default,
	_object_lightmap_shadow_mode_never,
	_object_lightmap_shadow_mode_always,
	_object_lightmap_shadow_mode_blur,
	k_number_of_object_lightmap_shadow_modes
};

enum e_object_sweetener_size
{
	_object_sweetener_size_small,
	_object_sweetener_size_medium,
	_object_sweetener_size_large,
	k_number_of_object_sweetener_sizes
};

enum e_object_runtime_flags
{
	_object_runtime_scaled_change_colors_bit,
	_object_runtime_is_physical_child_bit,
	_object_runtime_unknown2_bit,
	_object_runtime_unknown3_bit,
	_object_runtime_unknown4_bit,
	_object_runtime_unknown5_bit,
	_object_runtime_unknown6_bit,
	_object_runtime_unknown7_bit,
	_object_runtime_unknown8_bit,
	_object_runtime_unknown9_bit,
	_object_runtime_unknown10_bit,
	_object_runtime_unknown11_bit,
	_object_runtime_unknown12_bit,
	_object_runtime_unknown13_bit,
	_object_runtime_unknown14_bit,
	_object_runtime_unknown15_bit,
	_object_runtime_unknown16_bit,
	_object_runtime_unknown17_bit,
	_object_runtime_unknown18_bit,
	_object_runtime_unknown19_bit,
	_object_runtime_unknown20_bit,
	_object_runtime_unknown21_bit,
	_object_runtime_unknown22_bit,
	_object_runtime_unknown23_bit,
	_object_runtime_unknown24_bit,
	_object_runtime_unknown25_bit,
	_object_runtime_unknown26_bit,
	_object_runtime_unknown27_bit,
	_object_runtime_unknown28_bit,
	_object_runtime_unknown29_bit,
	_object_runtime_unknown30_bit,
	_object_runtime_unknown31_bit,
	k_number_of_object_runtime_flags
};

struct s_object_early_mover_obb
{
	string_id node_name;
	real_bounds x_bounds;
	real_bounds y_bounds;
	real_bounds z_bounds;
	real_euler_angles3d angles;
};
static_assert(sizeof(s_object_early_mover_obb) == 0x28);

enum e_object_ai_properties_flags
{
	_object_ai_properties_destroyable_cover_bit,
	_object_ai_properties_pathfinding_ignore_when_dead_bit,
	_object_ai_properties_dynamic_cover_bit,
	_object_ai_properties_non_flight_blocking_bit,
	_object_ai_properties_dynamic_cover_from_center_bit,
	_object_ai_properties_has_corner_markers_bit,
	_object_ai_properties_consider_for_interaction_bit,
	_object_ai_properties_leap_on_cover_target_bit,
	k_number_of_object_ai_properties_flags
};

enum e_object_ai_size
{
	_object_ai_size_default,
	_object_ai_size_tiny,
	_object_ai_size_small,
	_object_ai_size_medium,
	_object_ai_size_large,
	_object_ai_size_huge,
	_object_ai_size_immobile,
	k_number_of_object_ai_sizes
};

enum e_object_ai_distance
{
	_object_ai_distance_none,
	_object_ai_distance_down,
	_object_ai_distance_step,
	_object_ai_distance_crouch,
	_object_ai_distance_stand,
	_object_ai_distance_storey,
	_object_ai_distance_tower,
	_object_ai_distance_infinite,
	k_number_of_object_ai_distances
};

struct s_object_ai_properties
{
	c_flags<e_object_ai_properties_flags, dword> flags;
	string_id ai_type_name;
	string_id interaction_name;
	c_enum<e_object_ai_size, short> size;
	c_enum<e_object_ai_distance, short> leap_jump_speed;
};
static_assert(sizeof(s_object_ai_properties) == 0x10);

enum e_object_function_interpolation_mode
{
	_object_function_interpolation_constant_velocity,
	_object_function_interpolation_linear_acceleration,
	_object_function_interpolation_damped_spring,
	_object_function_interpolation_fractional,
	k_number_of_object_function_interpolations
};

struct s_object_function_interpolation
{
	c_enum<e_object_function_interpolation_mode, long> interpolation_mode;
	real linear_travel_time;
	real acceleration;
	real spring_k;
	real spring_c;
	real fraction;
};
static_assert(sizeof(s_object_function_interpolation) == 0x18);

struct s_object_runtime_interpolator_function
{
	long runtime_interpolator_to_object_function_mapping;
};
static_assert(sizeof(s_object_runtime_interpolator_function) == 0x4);

enum e_object_function_flags
{
	_object_function_invert_bit,
	_object_function_mapping_does_not_control_active_bit,
	_object_function_always_active_bit,
	_object_function_random_time_offset_bit,
	_object_function_always_exports_value_bit,
	_object_function_turn_off_with_uses_magnitude_bit,
	k_number_of_object_function_flags
};

struct s_object_function
{
	c_flags<e_object_function_flags, long> flags;
	string_id import_name;
	string_id export_name;
	string_id turn_off_with;
	string_id ranged_interpolation_name;
	real minimum_value;
	s_tag_function default_function;
	string_id scale_by;
	c_typed_tag_block<s_object_function_interpolation> interpolation;
	c_tag_block_index<s_object_runtime_interpolator_function, long> runtime_interpolator_index;
};
static_assert(sizeof(s_object_function) == 0x40);

enum e_object_attachment_change_color
{
	_object_attachment_change_color_none,
	_object_attachment_change_color_primary,
	_object_attachment_change_color_secondary,
	_object_attachment_change_color_tertiary,
	_object_attachment_change_color_quaternary,
	k_number_of_object_attachment_change_colors
};

enum e_object_attachment_flags
{
	_object_attachment_force_always_on_bit,
	_object_attachment_effect_size_scale_from_object_scale_bit,
	k_number_of_object_attachment_flags
};

struct s_object_attachment
{
	s_tag_reference type;
	string_id marker;
	c_enum<e_object_attachment_change_color, short> change_color;
	c_flags<e_object_attachment_flags, word> flags;
	string_id primary_scale;
	string_id secondary_scale;
};
static_assert(sizeof(s_object_attachment) == 0x20);

struct s_object_widget
{
	s_tag_reference type;
};
static_assert(sizeof(s_object_widget) == 0x10);

struct s_object_change_color_initial_permutation
{
	real weight;
	rgb_color color_lower_bound;
	rgb_color color_upper_bound;
	string_id variant_name;
};
static_assert(sizeof(s_object_change_color_initial_permutation) == 0x20);

enum e_object_change_color_function_flags
{
	_object_change_color_function_blend_in_hsv_bit,
	_object_change_color_function_more_colors_bit,
	k_number_of_object_change_color_function_flags
};

struct s_object_change_color_function
{
	c_enum<e_object_change_color_function_flags, long> flags;
	rgb_color color_lower_bound;
	rgb_color color_upper_bound;
	string_id darken_by;
	string_id scale_by;
};
static_assert(sizeof(s_object_change_color_function) == 0x24);

struct s_object_change_color
{
	c_typed_tag_block<s_object_change_color_initial_permutation> initial_permutations;
	c_typed_tag_block<s_object_change_color_function> functions;
};
static_assert(sizeof(s_object_change_color) == 0x18);

struct s_object_predicted_resource
{
	short type_index; // TODO: block index
	short resource_index; // TODO: block index
	long tag_index;
};
static_assert(sizeof(s_object_predicted_resource) == 0x8);

struct s_object_reviving_equipment
{
	s_tag_reference type;
};
static_assert(sizeof(s_object_reviving_equipment) == 0x10);

struct s_object_definition
{
	c_enum<e_object_type, short> object_type;
	short : 16;
	c_enum<e_object_flags, long> object_flags;
	real bounding_radius;
	real_point3d bounding_offset;
	real horizontal_acceleration_scale;
	real vertical_acceleration_scale;
	real angular_acceleration_scale;
	c_enum<e_object_lightmap_shadow_mode, short> lightmap_shadow_mode;
	c_enum<e_object_sweetener_size, char> sweetener_size;
	c_enum<e_water_density, char> water_density;
	c_flags<e_object_runtime_flags, dword> runtime_flags;
	real dynamic_light_sphere_radius;
	real_point3d dynamic_light_sphere_offset;
	string_id generic_hud_text;
	s_tag_reference generic_name_list;
	s_tag_reference generic_service_tag_list;
	string_id default_variant;
	s_tag_reference model;
	s_tag_reference crate_object;
	s_tag_reference collision_damage;
	s_tag_reference brittle_collision_damage;
	c_typed_tag_block<s_object_early_mover_obb> early_mover_obb;
	s_tag_reference creation_effect;
	s_tag_reference material_effects;
	s_tag_reference melee_sound;
	c_typed_tag_block<s_object_ai_properties> ai_properties;
	c_typed_tag_block<s_object_function> functions;
	c_typed_tag_block<s_object_runtime_interpolator_function> runtime_interpolator_functions;
	short hud_text_message_index;
	short : 16;
	c_typed_tag_block<s_object_attachment> attachments;
	c_typed_tag_block<s_water_physics_hull_surface_definition> surface_hulls;
	c_typed_tag_block<s_jetwash_definition> jetwash;
	c_typed_tag_block<s_object_widget> widgets;
	c_typed_tag_block<s_object_change_color> change_colors;
	c_typed_tag_block<s_object_predicted_resource> predicted_resources;
	c_typed_tag_block<s_multiplayer_object_definition> multiplayer_object;
	s_tag_reference simulation_interpolation;
	c_typed_tag_block<s_object_reviving_equipment> reviving_equipment;
};
static_assert(sizeof(s_object_definition) == 0x178);

struct s_scenario_object_palette_entry
{
	s_tag_reference definition;
};
static_assert(sizeof(s_scenario_object_palette_entry) == 0x10);

struct s_scenario_object
{
	// TODO
};
