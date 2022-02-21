#pragma once

#include <blamlib/cseries/cseries.h>

/* ---------- constants */

constexpr tag k_sound_classes_group_tag = 'sncl';

/* ---------- types */

enum e_sound_class
{
	_sound_class_projectile_impact,
	_sound_class_projectile_detonation,
	_sound_class_projectile_flyby,
	_sound_class_projectile_detonation_lod,
	_sound_class_weapon_fire,
	_sound_class_weapon_ready,
	_sound_class_weapon_reload,
	_sound_class_weapon_empty,
	_sound_class_weapon_charge,
	_sound_class_weapon_overheat,
	_sound_class_weapon_idle,
	_sound_class_weapon_melee,
	_sound_class_weapon_animation,
	_sound_class_object_impacts,
	_sound_class_particle_impacts,
	_sound_class_weapon_fire_lod,
	_sound_class_water_transitions,
	_sound_class_lowpass_effects,
	_sound_class_unit_footsteps,
	_sound_class_unit_dialog,
	_sound_class_unit_animation,
	_sound_class_unit_unused,
	_sound_class_vehicle_collision,
	_sound_class_vehicle_engine,
	_sound_class_vehicle_animation,
	_sound_class_vehicle_engine_lod,
	_sound_class_device_door,
	_sound_class_device_unused0,
	_sound_class_device_machinery,
	_sound_class_device_stationary,
	_sound_class_device_unused1,
	_sound_class_device_unused2,
	_sound_class_music,
	_sound_class_ambient_nature,
	_sound_class_ambient_machinery,
	_sound_class_ambient_stationary,
	_sound_class_huge_ass,
	_sound_class_object_looping,
	_sound_class_cinematic_music,
	_sound_class_unknown_unused0,
	_sound_class_unknown_unused1,
	_sound_class_ambient_flock,
	_sound_class_no_pad,
	_sound_class_no_pad_stationary,
	_sound_class_equipment_effect,
	_sound_class_mission_dialog,
	_sound_class_cinematic_dialog,
	_sound_class_scripted_cinematic_foley,
	_sound_class_game_event,
	_sound_class_ui,
	_sound_class_test,
	_sound_class_multiplayer_dialog,
	_sound_class_ambient_nature_details,
	_sound_class_ambient_machinery_details,
	_sound_class_inside_surround_tail,
	_sound_class_outside_surround_tail,
	_sound_class_vehicle_detonation,
	_sound_class_ambient_detonation,
	_sound_class_first_person_inside,
	_sound_class_first_person_outside,
	_sound_class_first_person_anywhere,
	_sound_class_space_projectile_detonation,
	_sound_class_space_projectile_flyby,
	_sound_class_space_vehicle_engine,
	_sound_class_space_weapon_fire,
	_sound_class_player_voice_team,
	_sound_class_player_voice_proxy,
	_sound_class_projectile_impact_postpone,
	_sound_class_unit_footsteps_postpone,
	_sound_class_weapon_ready_third_person,
	_sound_class_ui_music,
	k_number_of_sound_classes
};

struct s_sound_classes_definition
{
	// TODO
};
