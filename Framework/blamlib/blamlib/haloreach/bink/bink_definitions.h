#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/tag_files/tag_groups.h>
#include <blamlib/tag_files/tag_resource_internals.h>

/* ---------- constants */

constexpr tag k_bink_group_tag = 'bink';

/* ---------- types */

struct s_bink_definition
{
	int frame_count;
	s_tag_resource resource;
	s_tag_reference external_sound_track;
	int : 32;
};
static_assert(sizeof(s_bink_definition) == 0x20);

struct s_bink_resource_definition
{
	s_tag_data data;
};
static_assert(sizeof(s_bink_resource_definition) == 0x14);
