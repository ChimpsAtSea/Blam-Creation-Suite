#pragma once

#include <cseries/cseries.h>
#include <datatypes/flags.h>
#include <math/color_math.h>
#include <math/real_math.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>
#include <haloreach/geometry/geometry_definitions.h>

/* ---------- constants */

constexpr tag k_chocolate_mountain_new_group_tag = 'chmt';
constexpr tag k_scenario_lightmap_bsp_data_group_tag = 'Lbsp';
constexpr tag k_scenario_wetness_bsp_data_group_tag = 'wetn';
constexpr tag k_scenario_lightmap_group_tag = 'sLdT';

/* ---------- types */

struct s_chocolate_mountain_new_lighting
{
	real lightmap_brightness_offset;
	real lightmap_darkness_offset;
	real unknown08;
	real dynamic_brightness_offset;
	real dynamic_darkness_offset;
};
static_assert(sizeof(s_chocolate_mountain_new_lighting) == 0x14);

struct s_chocolate_mountain_new_definition
{
	char unknown00;
	char unknown01;
	char unknown02;
	char unknown03;
	c_typed_tag_block<s_chocolate_mountain_new_lighting> lighting;
};
static_assert(sizeof(s_chocolate_mountain_new_definition) == 0x10);

struct s_scenario_lightmap_bsp_data_unknown1
{
	short vertex_buffer_index;
	short unknown2;
};
static_assert(sizeof(s_scenario_lightmap_bsp_data_unknown1) == 0x4);

struct s_scenario_lightmap_bsp_data_unknown2
{
	long unknown0;
	long unknown4;
};
static_assert(sizeof(s_scenario_lightmap_bsp_data_unknown2) == 0x8);

struct s_scenario_lightmap_coloring
{
	real unknown00;
	real unknown04;
	real red;
	real blue;
	real unknown10;
	long unknown14;
	real unknown18;
	real unknown1C;
	dword unknown20;
};
static_assert(sizeof(s_scenario_lightmap_coloring) == 0x24);

struct s_scenario_lightmap_instanced_geometry
{
	short unknown0;
	c_tag_block_index<s_scenario_lightmap_bsp_data_unknown1, short> unknown048_index;
	c_tag_block_index<s_scenario_lightmap_coloring, short> coloring;
	short unknown6;
	long unknown8;
};
static_assert(sizeof(s_scenario_lightmap_instanced_geometry) == 0xC);

struct s_scenario_lightmap_bsp_data_unknown4
{
	long unknown0;
};
static_assert(sizeof(s_scenario_lightmap_bsp_data_unknown4) == 0x4);

struct s_scenario_lightmap_bsp_data_unknown3
{
	c_typed_tag_block<s_scenario_lightmap_bsp_data_unknown4> unknown0;
};
static_assert(sizeof(s_scenario_lightmap_bsp_data_unknown3) == 0xC);

struct s_scenario_lightmap_airprobe
{
	s_real_point3d position;
	string_id name;
	long unknown10;
	long unknown14;
	long unknown18;
	long unknown1C;
	long unknown20;
	long unknown24;
	long unknown28;
	long unknown2C;
	long unknown30;
	long unknown34;
};
static_assert(sizeof(s_scenario_lightmap_airprobe) == 0x38);

struct s_scenario_lightmap_bsp_data_unknown5
{
	real unknown00;
	real unknown04;
	real unknown08;
	real unknown0C;
	real unknown10;
	real unknown14;
	real unknown18;
	real unknown1C;
	real unknown20;
	real unknown24;
	real unknown28;
};
static_assert(sizeof(s_scenario_lightmap_bsp_data_unknown5) == 0x2C);

struct s_scenario_lightmap_bsp_data_unknown7
{
	long unknown00;
	long unknown04;
	long unknown08;
	long unknown0C;
	long unknown10;
	long unknown14;
	long unknown18;
	long unknown1C;
	long unknown20;
	long unknown24;
	long unknown28;
	long unknown2C;
};
static_assert(sizeof(s_scenario_lightmap_bsp_data_unknown7) == 0x30);

struct s_scenario_lightmap_bsp_data_unknown6
{
	long unknown00;
	long unknown04;
	long unknown08;
	long unknown0C;
	long unknown10;
	long unknown14;
	long unknown18;
	long unknown1C;
	c_typed_tag_block<s_scenario_lightmap_bsp_data_unknown7> unknown20;
};
static_assert(sizeof(s_scenario_lightmap_bsp_data_unknown6) == 0x2C);

struct s_scenario_lightmap_compile_data
{
	c_static_string<32> date;
	c_static_string<32> culprit;
	c_static_string<256> build;
	c_static_string<256> command;
};
static_assert(sizeof(s_scenario_lightmap_compile_data) == 0x240);

struct s_scenario_lightmap_bsp_data
{
	short unknown000;
	short structure_bsp_index;
	long structure_checksum;
	s_tag_reference unknown008;
	real brightness;
	s_tag_reference primary_map;
	s_tag_reference intensity_map;
	s_tag_block unknown03C;
	c_typed_tag_block<s_scenario_lightmap_bsp_data_unknown1> unknown048;
	c_typed_tag_block<s_scenario_lightmap_bsp_data_unknown2> unknown054;
	c_typed_tag_block<s_scenario_lightmap_instanced_geometry> instanced_geometry;
	c_typed_tag_block<s_scenario_lightmap_coloring> coloring;
	c_typed_tag_block<s_scenario_lightmap_bsp_data_unknown3> unknown120;
	s_render_geometry geometry;
	c_typed_tag_block<s_scenario_lightmap_airprobe> airprobes;
	c_typed_tag_block<s_scenario_lightmap_bsp_data_unknown5> unknown138;
	c_typed_tag_block<s_scenario_lightmap_bsp_data_unknown6> unknown144;
	s_tag_block unknown150;
	c_typed_tag_block<s_scenario_lightmap_compile_data> compile_data;
};
static_assert(sizeof(s_scenario_lightmap_bsp_data) == 0x168);

struct s_scenario_wetness_bsp_data_unknown1
{
	long unknown0;
};
static_assert(sizeof(s_scenario_wetness_bsp_data_unknown1) == 0x4);

struct s_scenario_wetness_bsp_data_unknown2
{
	byte unknown0;
};
static_assert(sizeof(s_scenario_wetness_bsp_data_unknown2) == 0x1);

struct s_scenario_wetness_bsp_data_unknown3
{
	long unknown0;
};
static_assert(sizeof(s_scenario_wetness_bsp_data_unknown3) == 0x4);

struct s_scenario_wetness_bsp_data_unknown4
{
	long unknown0;
	char unknown4;
	char unknown5;
	char unknown6;
	char unknown7;
};
static_assert(sizeof(s_scenario_wetness_bsp_data_unknown4) == 0x8);

struct s_scenario_wetness_bsp_data
{
	long unknown00;
	long structure_checksum1;
	long structure_checksum2;
	long unknown0C;
	long unknown10;
	long unknown14;
	long unknown18;
	s_tag_reference primary_map;
	c_typed_tag_block<s_scenario_wetness_bsp_data_unknown1> unknown2C;
	c_typed_tag_block<s_scenario_wetness_bsp_data_unknown2> unknown38;
	c_typed_tag_block<s_scenario_wetness_bsp_data_unknown3> unknown44;
	c_typed_tag_block<s_scenario_wetness_bsp_data_unknown4> unknown50;
};
static_assert(sizeof(s_scenario_wetness_bsp_data) == 0x5C);

struct s_scenario_lightmap_bsp_data_reference
{
	s_tag_reference lightmap_bsp_data;
	s_tag_reference wetness_bsp_data;
};
static_assert(sizeof(s_scenario_lightmap_bsp_data_reference) == 0x20);

struct s_scenario_lightmap
{
	c_typed_tag_block<s_scenario_lightmap_bsp_data_reference> bsp_data_references;
	c_typed_tag_block<s_scenario_lightmap_airprobe> airprobes;
	s_tag_block unused;
};
static_assert(sizeof(s_scenario_lightmap) == 0x24);
