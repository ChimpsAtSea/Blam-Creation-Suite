#pragma once

#include <cseries/cseries.h>
#include <memory/static_arrays.h>

/* ---------- constants */

constexpr int k_maximum_number_of_breakable_surfaces = 32;
constexpr int k_maximum_number_of_breakable_surface_keys = 8192;

/* ---------- types */

struct s_bsp_breakable_surface_info
{
	short first_set_index;
	short set_count;
};

struct s_breakable_surface_set
{
	long unknown0;
	long unknown4;
	c_big_flags_typed_no_init<long, 256> flags;
	c_static_array<char, 16> unknown28;

	s_breakable_surface_set();
};

struct s_breakable_surface_redirection_globals
{
	/* ------ fields */

	long : 32;
	long : 32;

	c_static_array<
		s_bsp_breakable_surface_info,
		k_maximum_number_of_breakable_surfaces> breakable_surface_info;

	c_static_array<
		c_static_array<short, k_maximum_number_of_breakable_surface_keys>,
		k_maximum_number_of_breakable_surfaces> breakable_surface_keys;

	/* ------ methods */

	void structure_breakable_surface_set(
		long surface_value,
		long surface_index,
		long set_count,
		long instance_set_count);

	void instance_breakable_surface_set(
		long surface_index,
		long key_index,
		long first_set_index);

	void breakable_surface_info_clear(
		long surface_index);

	short structure_breakable_surface_get_first_set_index(
		long structure_bsp_index);

	short structure_breakable_surface_get_set_count(
		long structure_bsp_index);

	short instance_breakable_surface_get_first_set_index(
		long structure_bsp_index,
		long instance_index);

	short instance_breakable_surface_get_set_count(
		long structure_bsp_index,
		long instance_index);
};

/* ---------- globals */

extern s_breakable_surface_redirection_globals g_breakable_surface_redirection_globals;

/* ---------- prototypes/BREAKABLE_SURFACES.CPP */

//
// TODO
//
