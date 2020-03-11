#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <memory/static_arrays.h>
#include <tag_files/tag_groups.h>
#include <haloreach/editor/editor_definitions.h>
#include <haloreach/effects/cheap_particle_system.h>
#include <haloreach/objects/object_types.h>
#include <haloreach/objects/object_recycling.h>
#include <haloreach/sound/sound_acoustics_definitions.h>

/* ---------- constants */

enum
{
	k_scenario_group_tag = 'scnr',
	k_maximum_number_of_scenario_structure_bsps = 32,
};

/* ---------- types */

enum e_scenario_type
{
	_scenario_type_none = NONE,
	_scenario_type_campaign,
	_scenario_type_multiplayer,
	_scenario_type_mainmenu,
	_scenario_type_shared,
	_scenario_type_shared_campaign,
	_scenario_type_shared_multiplayer,
	k_number_of_scenario_types
};
extern s_enum_definition g_scenario_type_enum;

enum e_scenario_load_type
{
	_scenario_load_none = NONE,
	_scenario_load_default,
	_scenario_load_shared,
	_scenario_load_shared_campaign,
	_scenario_load_shared_multiplayer,
	k_number_of_scenario_load_types
};
extern s_enum_definition g_scenario_loade_type_enum;

enum e_scenario_flags
{
	_scenario_unknown0_bit,
	_scenario_unknown1_bit,
	_scenario_unknown2_bit,
	_scenario_unknown3_bit,
	_scenario_unknown4_bit,
	_scenario_unknown5_bit,
	_scenario_snap_to_white_at_start_bit,
	_scenario_unknown7_bit,
	_scenario_unknown8_bit,
	_scenario_unknown9_bit,
	_scenario_unknown10_bit,
	_scenario_unknown11_bit,
	_scenario_unknown12_bit,
	_scenario_firefight_bit,
	_scenario_unknown14_bit,
	_scenario_unknown15_bit,
	k_number_of_scenario_flags
};
extern s_enum_definition g_scenario_flags_enum;

enum e_scenario_structure_bsp_reference_flags
{
	_scenario_structure_bsp_reference_unknown0_bit,
	_scenario_structure_bsp_reference_unknown1_bit,
	_scenario_structure_bsp_reference_unknown2_bit,
	_scenario_structure_bsp_reference_unknown3_bit,
	_scenario_structure_bsp_reference_unknown4_bit,
	_scenario_structure_bsp_reference_unknown5_bit,
	_scenario_structure_bsp_reference_unknown6_bit,
	_scenario_structure_bsp_reference_unknown7_bit,
	_scenario_structure_bsp_reference_unknown8_bit,
	_scenario_structure_bsp_reference_unknown9_bit,
	_scenario_structure_bsp_reference_prevents_forging_bit,
	_scenario_structure_bsp_reference_unknown11_bit,
	_scenario_structure_bsp_reference_unknown12_bit,
	_scenario_structure_bsp_reference_unknown13_bit,
	_scenario_structure_bsp_reference_unknown14_bit,
	_scenario_structure_bsp_reference_unknown15_bit,
	k_number_of_scenario_structure_bsp_reference_flags
};

struct s_scenario_structure_bsp_reference
{
	s_tag_reference structure_bsp;
	s_tag_reference local_structure_bsp;
	s_tag_reference structure_lighting;
	s_tag_reference local_structure_lighting;
	long unknown3;
	real unknown4;
	real unknown5;
	real unknown6;
	c_flags<e_scenario_structure_bsp_reference_flags, word> flags;
	short unknown7;
	real unknown8;
	s_tag_reference cubemap;
	s_tag_reference wind;
	real unknown9;
	real unknown10;
	real unknown11;
	real unknown12;
	real unknown13;
	real unknown14;
	real unknown15;
	real unknown16;
	real unknown17;
	real unknown18;
	real unknown19;
	long unknown20;
	real custom_gravity_scale;
};
static_assert(sizeof(s_scenario_structure_bsp_reference) == 0xAC);
extern s_tag_block_definition g_scenario_structure_bsp_reference_block;

struct s_scenario_design_reference
{
	s_tag_reference structure_design;
	s_tag_reference local_structure_design;
};
static_assert(sizeof(s_scenario_design_reference) == 0x20);

struct s_scenario_sky_reference
{
	s_tag_reference sky_object;
	real unknown1;
	real unknown2;
	real unknown3;
	s_tag_reference unknown4;
	short name_index; // TODO: block index
	c_tag_block_flags<s_scenario_structure_bsp_reference, word> active_bsps;
};
static_assert(sizeof(s_scenario_sky_reference) == 0x30);

enum e_scenario_zone_set_pvs_flags
{
	_scenario_zone_set_pvs_empty_debug_bit,
	k_number_of_scenario_zone_set_pvs_flags
};

struct s_scenario_zone_set_bsp_checksum
{
	dword bsp_checksum;
};
static_assert(sizeof(s_scenario_zone_set_bsp_checksum) == 0x4);

enum e_scenario_zone_set_cluster_pvs_flags
{
	_scenario_zone_set_cluster_pvs_unknown0_bit,
	_scenario_zone_set_cluster_pvs_unknown1_bit,
	_scenario_zone_set_cluster_pvs_unknown2_bit,
	_scenario_zone_set_cluster_pvs_unknown3_bit,
	_scenario_zone_set_cluster_pvs_unknown4_bit,
	_scenario_zone_set_cluster_pvs_effects_bit,
	_scenario_zone_set_cluster_pvs_unknown6_bit,
	_scenario_zone_set_cluster_pvs_unknown7_bit,
	_scenario_zone_set_cluster_pvs_unknown8_bit,
	_scenario_zone_set_cluster_pvs_unknown9_bit,
	_scenario_zone_set_cluster_pvs_unknown10_bit,
	_scenario_zone_set_cluster_pvs_unknown11_bit,
	_scenario_zone_set_cluster_pvs_unknown12_bit,
	_scenario_zone_set_cluster_pvs_unknown13_bit,
	_scenario_zone_set_cluster_pvs_unknown14_bit,
	_scenario_zone_set_cluster_pvs_unknown15_bit,
	_scenario_zone_set_cluster_pvs_firing_effects_bit,
	_scenario_zone_set_cluster_pvs_unknown17_bit,
	_scenario_zone_set_cluster_pvs_unknown18_bit,
	_scenario_zone_set_cluster_pvs_unknown19_bit,
	_scenario_zone_set_cluster_pvs_unknown20_bit,
	_scenario_zone_set_cluster_pvs_unknown21_bit,
	_scenario_zone_set_cluster_pvs_unknown22_bit,
	_scenario_zone_set_cluster_pvs_unknown23_bit,
	_scenario_zone_set_cluster_pvs_decals_bit,
	_scenario_zone_set_cluster_pvs_unknown25_bit,
	_scenario_zone_set_cluster_pvs_unknown26_bit,
	_scenario_zone_set_cluster_pvs_unknown27_bit,
	_scenario_zone_set_cluster_pvs_unknown28_bit,
	_scenario_zone_set_cluster_pvs_unknown29_bit,
	_scenario_zone_set_cluster_pvs_unknown30_bit,
	_scenario_zone_set_cluster_pvs_unknown31_bit,
	k_number_of_scenario_zone_set_cluster_pvs_flags
};

struct s_scenario_zone_set_cluster_pvs_bit_vector
{
	c_flags<e_scenario_zone_set_cluster_pvs_flags, dword> bits;
};
static_assert(sizeof(s_scenario_zone_set_cluster_pvs_bit_vector) == 0x4);

struct s_scenario_zone_set_bsp_bits
{
	c_typed_tag_block<s_scenario_zone_set_cluster_pvs_bit_vector> bits;
};
static_assert(sizeof(s_scenario_zone_set_bsp_bits) == 0xC);

struct s_scenario_zone_set_cluster_pvs
{
	c_typed_tag_block<s_scenario_zone_set_bsp_bits> cluster_pvs_bit_vectors;
};
static_assert(sizeof(s_scenario_zone_set_cluster_pvs) == 0xC);

struct s_scenario_zone_set_cluster_reference
{
	c_tag_block_index<s_scenario_structure_bsp_reference, char> structure_bsp;
	byte cluster_index; // TODO: block index
};
static_assert(sizeof(s_scenario_zone_set_cluster_reference) == 0x2);

struct s_scenario_zone_set_cluster_sky
{
	c_tag_block_index<s_scenario_sky_reference, char> sky;
};
static_assert(sizeof(s_scenario_zone_set_cluster_sky) == 0x1);

struct s_scenario_zone_set_bsp_seam_cluster_mapping
{
	c_typed_tag_block<s_scenario_zone_set_cluster_reference> root_clusters;
	c_typed_tag_block<s_scenario_zone_set_cluster_reference> attached_clusters;
	c_typed_tag_block<s_scenario_zone_set_cluster_reference> connected_clusters;
};
static_assert(sizeof(s_scenario_zone_set_bsp_seam_cluster_mapping) == 0x24);

struct s_scenario_zone_set_bsp_pvs_unknown
{
	long unknown;
};
static_assert(sizeof(s_scenario_zone_set_bsp_pvs_unknown) == 0x4);

struct s_scenario_zone_set_bsp_pvs
{
	c_typed_tag_block<s_scenario_zone_set_cluster_pvs> cluster_pvs;
	c_typed_tag_block<s_scenario_zone_set_cluster_pvs> cluster_pvs_doors_closed;
	c_typed_tag_block<s_scenario_zone_set_cluster_sky> cluster_skies;
	c_typed_tag_block<s_scenario_zone_set_cluster_sky> cluster_skies_visible;
	c_typed_tag_block<s_scenario_zone_set_bsp_pvs_unknown> unknown;
	c_typed_tag_block<s_scenario_zone_set_bsp_seam_cluster_mapping> bsp_cluster_mappings;
};
static_assert(sizeof(s_scenario_zone_set_bsp_pvs) == 0x48);

enum e_scenario_object_source
{
	_scenario_object_source_structure,
	_scenario_object_source_editor,
	_scenario_object_source_dynamic,
	_scenario_object_source_legacy,
	_scenario_object_source_sky,
	_scenario_object_source_parent,
	k_number_of_scenario_object_sources
};

struct s_scenario_object_id
{
	long unique_id;
	c_tag_block_index<s_scenario_structure_bsp_reference, short> origin_bsp;
	c_enum<e_object_type, char> type;
	c_enum<e_scenario_object_source, char> source;
};
static_assert(sizeof(s_scenario_object_id) == 0x8);

struct s_structure_device_portal_association
{
	s_scenario_object_id device_id;
	short first_game_portal_index;
	word game_portal_count;
};
static_assert(sizeof(s_structure_device_portal_association) == 0xC);

struct s_game_portal_to_portal_mapping
{
	short portal_index;
};
static_assert(sizeof(s_game_portal_to_portal_mapping) == 0x2);

struct s_occluding_portal_to_portal_mapping
{
	short portal_index;
};
static_assert(sizeof(s_occluding_portal_to_portal_mapping) == 0x2);

struct s_structure_portal_device_mapping
{
	c_typed_tag_block<s_structure_device_portal_association> device_portal_associations;
	c_typed_tag_block<s_game_portal_to_portal_mapping> game_portal_to_portal_map;
	c_typed_tag_block<s_occluding_portal_to_portal_mapping> occluding_portal_to_portal_map;
};
static_assert(sizeof(s_structure_portal_device_mapping) == 0x24);

struct s_scenario_zone_set_pvs
{
	c_tag_block_flags<s_scenario_structure_bsp_reference, dword> active_bsps;
	short version;
	c_flags<e_scenario_zone_set_pvs_flags, word> flags;
	c_typed_tag_block<s_scenario_zone_set_bsp_checksum> bsp_checksums;
	c_typed_tag_block<s_scenario_zone_set_bsp_pvs> structure_bsp_pvs;
	c_typed_tag_block<s_structure_portal_device_mapping> portal_to_device_mapping;
};
static_assert(sizeof(s_scenario_zone_set_pvs) == 0x2C);

struct s_door_encoded_pas
{
	long encoded_data;
};
static_assert(sizeof(s_door_encoded_pas) == 0x4);

struct s_room_door_portal_encoded_pas
{
	long encoded_data;
};
static_assert(sizeof(s_room_door_portal_encoded_pas) == 0x4);

struct s_ai_deafening_encoded_pas
{
	long encoded_data;
};
static_assert(sizeof(s_ai_deafening_encoded_pas) == 0x4);

struct s_encoded_room_distance
{
	long encoded_data;
};
static_assert(sizeof(s_encoded_room_distance) == 0x4);

struct s_game_portal_to_door_occluder
{
	long first_door_occluder_index;
	long door_occluder_count;
};
static_assert(sizeof(s_game_portal_to_door_occluder) == 0x8);

struct s_bsp_cluster_to_room_bounds
{
	long first_room_index;
	long room_index_count;
};
static_assert(sizeof(s_bsp_cluster_to_room_bounds) == 0x8);

struct s_bsp_cluster_to_room_index
{
	short room_index;
};
static_assert(sizeof(s_bsp_cluster_to_room_index) == 0x2);

struct s_scenario_zone_set_audibility
{
	long door_portal_count;
	long room_count;
	s_real_bounds room_distance_bounds;
	c_typed_tag_block<s_door_encoded_pas> encoded_door_pas;
	c_typed_tag_block<s_room_door_portal_encoded_pas> room_door_portal_encoded_pas;
	c_typed_tag_block<s_ai_deafening_encoded_pas> ai_deafening_pas;
	c_typed_tag_block<s_encoded_room_distance> room_distances;
	c_typed_tag_block<s_game_portal_to_door_occluder> game_portal_to_door_occluder;
	c_typed_tag_block<s_bsp_cluster_to_room_bounds> bsp_cluster_to_room_bounds;
	c_typed_tag_block<s_bsp_cluster_to_room_index> bsp_cluster_to_room_indices;
};
static_assert(sizeof(s_scenario_zone_set_audibility) == 0x64);

enum e_scenario_zone_set_flags
{
	_scenario_zone_set_begin_loading_next_level_bit,
	_scenario_zone_set_interal_zone_set_bit,
	_scenario_zone_set_disable_sky_clearing_bit,
	_scenario_zone_set_override_sky_clear_color_bit,
	k_number_of_scenario_zone_set_flags
};

struct s_planar_fog_reference_definition
{
	c_tag_block_index<s_scenario_design_reference, short> structure_design;
	short fog_index; // TODO: block index
};
static_assert(sizeof(s_planar_fog_reference_definition) == 0x4);

struct s_planar_fog_cluster_visibility_definition
{
	c_typed_tag_block<s_planar_fog_reference_definition> attached_fogs;
};
static_assert(sizeof(s_planar_fog_cluster_visibility_definition) == 0xC);

struct s_planar_fog_structure_visibility_definition
{
	c_typed_tag_block<s_planar_fog_cluster_visibility_definition> cluster_visibility;
};
static_assert(sizeof(s_planar_fog_structure_visibility_definition) == 0xC);

struct s_planar_fog_zone_set_visibility_definition
{
	c_typed_tag_block<s_planar_fog_structure_visibility_definition> structure_visibility;
};
static_assert(sizeof(s_planar_fog_zone_set_visibility_definition) == 0xC);

struct s_scenario_designer_zone;

struct s_scenario_zone_set
{
	string_id name;
	c_static_string<256> name_string;
	c_tag_block_index<s_scenario_zone_set_pvs, long> pvs;
	c_flags<e_scenario_zone_set_flags, dword> flags;
	c_tag_block_flags<s_scenario_structure_bsp_reference, dword> structure_bsps;
	c_tag_block_flags<s_scenario_design_reference, dword> structure_designs;
	c_tag_block_flags<s_scenario_structure_bsp_reference, dword> runtime_structure_bsps;
	c_tag_block_flags<s_scenario_design_reference, dword> runtime_structure_designs;
	c_tag_block_flags<s_scenario_designer_zone, dword> active_designer_zones;
	c_tag_block_flags<s_scenario_designer_zone, dword> inactive_designer_zones;
	c_tag_block_flags<s_scenario_designer_zone, dword> active_cinematic_zones;
	c_tag_block_index<s_scenario_zone_set, long> hint_previous_zone_set;
	c_tag_block_index<s_scenario_zone_set_audibility, long> audibility;
	c_typed_tag_block<s_planar_fog_zone_set_visibility_definition> planar_fog_visibility;
};
static_assert(sizeof(s_scenario_zone_set) == 0x13C);

struct s_scenario_structured_buffer_interop
{
	// TODO
};

struct s_scenario
{
	c_enum<e_scenario_type, short> scenario_type;
	c_flags<e_scenario_flags, word> flags;
	long unknown1;
	long campaign_id;
	long map_id;
	string_id scenario_name;
	short campaign_level_index;
	short unknown2;
	long unknown3;
	real local_north;
	real unknown4;
	real unknown5;
	real unknown6;
	real unknown7;
	real unknown8;
	real sandbox_budget;
	string_id default_vehicle_filter;
	s_tag_reference performance_throttle_profile;
	c_typed_tag_block<s_scenario_structure_bsp_reference> structure_bsps;
	c_typed_tag_block<s_scenario_design_reference> structure_designs;
	s_tag_reference structure_seams;
	s_tag_reference local_structure_seams;
	c_typed_tag_block<s_scenario_sky_reference> skies;
	c_typed_tag_block<s_scenario_zone_set_pvs> zone_set_pvs;
	c_typed_tag_block<s_scenario_zone_set_audibility> zone_set_audibility;
	c_typed_tag_block<s_scenario_zone_set> zone_sets;
	s_tag_block unknown9;
	s_tag_block unknown10;
	s_tag_block unknown11;
	s_tag_block unknown12;
	s_tag_data editor_scenario_data;
	s_tag_block unknown13;
	s_tag_block object_names;
	s_tag_block scenery;
	s_tag_block scenery_palette;
	s_tag_block bipeds;
	s_tag_block biped_palette;
	s_tag_block vehicles;
	s_tag_block vehicle_palette;
	s_tag_block equipment;
	s_tag_block equipment_palette;
	s_tag_block weapons;
	s_tag_block weapon_palette;
	s_tag_block device_groups;
	s_tag_block machines;
	s_tag_block machine_palette;
	s_tag_block terminals;
	s_tag_block terminal_palette;
	s_tag_block controls;
	s_tag_block control_palette;
	s_tag_block sound_scenery;
	s_tag_block sound_scenery_palette;
	s_tag_block giants;
	s_tag_block giant_palette;
	s_tag_block effect_scenery;
	s_tag_block effect_scenery_palette;
	s_tag_block light_volumes;
	s_tag_block light_volume_palette;
	s_tag_block sandbox_palette;
	s_tag_block legacy_sandbox_info;
	s_tag_reference multiplayer_object_types;
	s_tag_block unknown14;
	s_tag_block soft_ceilings;
	s_tag_block player_starting_profile;
	s_tag_block player_starting_locations;
	s_tag_block trigger_volumes;
	c_typed_tag_block<s_scenario_acoustic_sector> acoustic_sectors;
	s_tag_block unknown16;
	s_tag_block unknown17;
	s_tag_block unknown18;
	s_tag_block unknown19;
	s_tag_block zone_set_switch_trigger_volumes;
	s_tag_block named_location_volumes;
	s_tag_reference airstrike_globals;
	s_tag_block unknown20;
	s_tag_block unknown21;
	s_tag_block unknown22;
	s_tag_block unknown23;
	s_tag_block unknown24;
	s_tag_block unknown25;
	s_tag_block unknown26;
	s_tag_block unknown27;
	s_tag_block unknown28;
	s_tag_block unknown29;
	s_tag_block decals;
	s_tag_block decal_palette;
	s_tag_block unknown30;
	s_tag_block unknown31;
	s_tag_block squad_groups;
	s_tag_block squads;
	s_tag_block zones;
	s_tag_block unknown32;
	s_tag_block ai_cues;
	s_tag_block unknown33;
	s_tag_block unknown34;
	s_tag_block unknown35;
	s_tag_block character_palette;
	s_tag_block unknown36;
	s_tag_block ai_pathfinding_data;
	s_tag_block unknown37;
	s_tag_data script_strings;
	s_tag_block scripts;
	s_tag_block globals;
	s_tag_block script_references;
	s_tag_block unknown38;
	s_tag_block scripting_data;
	s_tag_block cutscene_flags;
	s_tag_block cutscene_camera_points;
	s_tag_block cutscene_titles;
	s_tag_reference custom_object_name_strings;
	s_tag_reference chapter_title_strings;
	s_tag_block scenario_resources;
	s_tag_block unit_seats_mapping;
	s_tag_block kill_triggers;
	s_tag_block safe_triggers;
	s_tag_block mopp_triggers;
	s_tag_block unknown39;
	s_tag_block unknown40;
	s_tag_block script_expressions;
	s_tag_block unknown41;
	s_tag_block unknown42;
	c_typed_tag_block<s_scenario_acoustics_palette_entry> acoustics_palette;
	s_tag_block fog;
	s_tag_block camera_fx;
	s_tag_block weather;
	s_tag_block scenario_cluster_data;
	long object_identifiers[32];
	s_tag_block spawn_data;
	s_tag_reference sound_effects_collection;
	s_tag_block crates;
	s_tag_block crate_palette;
	s_tag_block flock_palette;
	s_tag_block flocks;
	s_tag_reference subtitle_strings;
	s_tag_block unknown43;
	s_tag_block creature_palette;
	s_tag_block big_battle_creatures;
	c_typed_tag_block<s_scenario_editor_folder> editor_folders;
	s_tag_reference territory_location_name_strings;
	long unknown44;
	long unknown45;
	s_tag_block mission_dialogue;
	s_tag_reference objective_strings;
	s_tag_reference scenario_interpolator;
	s_tag_block unknown46;
	s_tag_reference default_camera_fx;
	s_tag_reference default_screen_fx;
	s_tag_reference ambient_occlusion_profile;
	s_tag_reference sky_parameters;
	s_tag_reference fog_parameters;
	s_tag_reference global_lighting;
	s_tag_reference lightmap;
	s_tag_reference performance_throttles;
	s_tag_block unknown47;
	s_tag_block ai_objectives;
	s_tag_block designer_zones;
	s_tag_block unknown48;
	s_tag_block unknown49;
	c_typed_tag_block<s_scenario_cheap_particle_emitter_palette_entry> neuticle_palette;
	c_typed_tag_block<s_scenario_cheap_particle_system> neuticles;
	s_tag_block cinematics;
	s_tag_block cinematic_lights;
	s_tag_block unknown51;
	s_tag_block campaign_metagame;
	s_tag_block unknown52;
	s_tag_block unknown53;
	s_tag_block unknown54;
	s_tag_block unknown55;
	s_tag_block unknown56;
	s_tag_block vignettes;
	s_tag_reference location_name_globals;
	c_typed_tag_block<s_garbage_collection_globals> garbage_collection;
	s_tag_reference mission_hud;
	s_tag_reference required_resources;
	s_tag_reference variant_globals;
	c_typed_tag_block<s_scenario_structured_buffer_interop> structured_buffer_interop;
};
static_assert(sizeof(s_scenario) == 0x884);

/* ---------- globals */

extern s_tag_group g_scenario_group;
