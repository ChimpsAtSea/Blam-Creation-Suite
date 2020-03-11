#pragma once

#include <cseries/cseries.h>
#include <cseries/language.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

enum
{
	k_globals_group_tag = 'matg',
};

/* ---------- enumerators */

/* ---------- structures */

struct s_havok_cleanup_globals
{
	s_tag_reference effect;
};
static_assert(sizeof(s_havok_cleanup_globals) == 0x10);

struct s_fireteam_sound_globals
{
	s_tag_reference sound;
};
static_assert(sizeof(s_fireteam_sound_globals) == 0x10);

struct s_sound_globals
{
	s_tag_reference sound_classes;
	s_tag_reference sound_effects;
	s_tag_reference sound_mix;
	s_tag_reference sound_dialogue;
	s_tag_reference sound_propagation;
	c_typed_tag_block<s_fireteam_sound_globals> fireteam_sounds;
};
static_assert(sizeof(s_sound_globals) == 0x5C);

struct s_game_globals
{
	char unused[0xAC];
	c_enum<e_language, long> langage;
	c_typed_tag_block<s_havok_cleanup_globals> havok_cleanup;
	c_typed_tag_block<s_sound_globals> sound_globals;

	//
	// TODO: finish
	//
};
