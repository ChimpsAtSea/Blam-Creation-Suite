#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/real_math.h>
#include <blamlib/memory/static_arrays.h>
#include <blamlib/tag_files/tag_groups.h>
#include <blamlib/haloreach/editor/editor_definitions.h>
#include <blamlib/haloreach/structures/cluster_reference_packed.h>

/* ---------- constants */

constexpr int k_maximum_number_of_scenario_acoustic_sector_points = 32;
constexpr int k_maximum_number_of_scenario_acoustic_sectors = 300;
constexpr int k_maximum_number_of_scenario_acoustic_transitions = k_maximum_number_of_scenario_acoustic_sectors;
constexpr int k_maximum_number_of_scenario_acoustic_palette_entries = 128;

/* ---------- types */

enum e_scenario_acoustics_environment_type
{
	_scenario_acoustics_environment_type_default,
	_scenario_acoustics_environment_type_interior_narrow,
	_scenario_acoustics_environment_type_interior_small,
	_scenario_acoustics_environment_type_interior_med,
	_scenario_acoustics_environment_type_interior_large,
	_scenario_acoustics_environment_type_exterior_small,
	_scenario_acoustics_environment_type_exterior_med,
	_scenario_acoustics_environment_type_exterior_large,
	_scenario_acoustics_environment_type_exterior_half_open,
	_scenario_acoustics_environment_type_exterior_open,
	k_number_of_scenario_acoustics_environment_types
};

struct s_scenario_acoustics_environment
{
	s_tag_reference sound_environment;
	c_enum<e_scenario_acoustics_environment_type, long> type;
	real cutoff_distance;
	real interpolation_time;
};
static_assert(sizeof(s_scenario_acoustics_environment) == 0x1C);

enum e_scenario_acoustics_scale_flags
{
	_scenario_acoustics_override_default_scale_bit,
	_scenario_acoustics_use_adjacent_cluster_as_portal_scale_bit,
	_scenario_acoustics_use_adjacent_cluster_as_exterior_scale_bit,
	_scenario_acoustics_scale_with_weather_intensity_bit,
	k_number_of_scenario_acoustics_scale_flags
};

struct s_scenario_acoustics_ambience
{
	s_tag_reference background_sound;
	s_tag_reference weather_sound; // plays when rain is active, weather rate gets applied to scale
	s_tag_reference entry_sound; // plays when entering this area
	s_tag_reference exit_sound; // plays when exiting this area
	real cutoff_distance;
	real interpolation_time;
	c_flags<e_scenario_acoustics_scale_flags, dword> flags;
	real interior_scale;
	real portal_scale;
	real exterior_scale;
};
static_assert(sizeof(s_scenario_acoustics_ambience) == 0x58);

struct s_scenario_acoustics_palette_entry
{
	string_id name;
	s_scenario_acoustics_environment environment;
	s_scenario_acoustics_ambience ambience;
};
static_assert(sizeof(s_scenario_acoustics_palette_entry) == 0x78);

struct s_real_sector_point
{
	real_point3d position;
};
static_assert(sizeof(s_real_sector_point) == 0xC);

struct s_scenario_acoustic_sector
{
	c_typed_tag_block<s_real_sector_point> points;
	real_plane3d top_plane;
	real_plane3d bottom_plane;
	c_tag_block_index<s_scenario_acoustics_palette_entry, short> acoustics;
	c_tag_block_index<s_scenario_editor_folder, short> editor_folder;
	real height;
	real sink;
};
static_assert(sizeof(s_scenario_acoustic_sector) == 0x38);

struct s_scenario_acoustic_location
{
	c_tag_block_index<s_scenario_acoustic_sector, short> sector;
	s_cluster_reference cluster;
};
static_assert(sizeof(s_scenario_acoustic_location) == 0x4);

struct s_scenario_acoustic_transition
{
	real_point3d center;
	real_point3d forward;
	real_point3d up;
	real half_width;
	real half_height;
	real sample_point_offsets[2];
	c_tag_block_index<s_scenario_acoustics_palette_entry, short> samples[2];
	s_scenario_acoustic_location locations[2];
	c_tag_block_index<s_scenario_editor_folder, short> editor_folder;
	short : 16;
};
static_assert(sizeof(s_scenario_acoustic_transition) == 0x44);

class __declspec(novtable) c_sector_accessor
{
public:
	virtual bool get_sector_position_value(
		s_tag_block *positions_block,
		long position_index,
		real_point3d *out_position) = 0;

	virtual bool get_sector_orientation_value(
		s_tag_block *orientations_block,
		long orientation_index,
		real_euler_angles2d *out_orientation) = 0;
};

class c_acoustic_sector_accessor final :
	public c_sector_accessor
{
public:
	bool get_sector_position_value(
		s_tag_block *positions_block,
		long position_index,
		real_point3d *out_position);

	bool get_sector_orientation_value(
		s_tag_block *orientations_block,
		long orientation_index,
		real_euler_angles2d *out_orientation);
};

/* ---------- prototypes/SOUND_ACOUSTICS_DEFINITIONS.CPP */

bool point_in_acoustic_sector(
	real_point3d const &point,
	s_scenario_acoustic_sector const &sector);

float distance_to_acoustic_transition(
	real_point3d const &point,
	s_scenario_acoustic_transition const &transition);

bool point_in_front_of_acoustic_transition(
	real_point3d const &point,
	s_scenario_acoustic_transition const &transition);

bool point_in_acoustic_transition(
	real_point3d const &point,
	s_scenario_acoustic_transition const &transition);
