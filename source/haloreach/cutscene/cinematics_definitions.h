#pragma once

#include <cseries/cseries.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_cinematic_group_tag = 'cine';
constexpr tag k_cinematic_scene_group_tag = 'cisc';
constexpr tag k_cinematic_transition_group_tag = 'citr';

/* ---------- types */

enum e_cinematic_transition_type
{
	// TODO
	k_number_of_cinematic_transition_types
};

enum e_cinematic_channel_type
{
	// TODO
	k_number_of_cinematic_channel_types
};

struct s_cinematic_scene
{
	// TODO
};

struct s_cinematic_scene_reference
{
	// TODO
};

struct s_cinematic_transition_definition
{
	// TODO
};

struct s_cinematic_definition
{
	// TODO
};
