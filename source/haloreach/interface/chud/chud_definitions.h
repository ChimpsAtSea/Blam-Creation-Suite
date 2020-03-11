#pragma once

#include <cseries/cseries.h>

/* ---------- constants */

enum
{
    k_chud_definition_group_tag = 'chdt'
};

/* ---------- types */

enum e_motion_tracker_noise
{
	_motion_tracker_noise_edge,
	_motion_tracker_noise_inner,
	_motion_tracker_noise_silent,
	k_motion_tracker_noise_count
};
