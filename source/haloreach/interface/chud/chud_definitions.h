#pragma once

#include <cseries/cseries.h>

/* ---------- constants */

constexpr tag k_chud_definition_group_tag = 'chdt';
constexpr tag k_chud_globals_group_tag = 'chgd';

/* ---------- types */

enum e_motion_tracker_noise
{
	_motion_tracker_noise_edge,
	_motion_tracker_noise_inner,
	_motion_tracker_noise_silent,
	k_motion_tracker_noise_count
};

struct s_chud_definition
{
	// TODO
};

struct s_chud_globals_definition
{
	// TODO
};
