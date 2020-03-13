#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <math/function_definitions.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_render_method_group_tag = 'rm  ';
constexpr tag k_render_method_shader_group_tag = 'rmsh';

/* ---------- types */

struct s_render_method_option_reference
{
	short index;
};
static_assert(sizeof(s_render_method_option_reference) == 0x2);

struct s_render_method_import_data
{
	// TODO
};

struct s_render_method_animated_parameter
{
	// TODO
};

struct s_render_method_postprocess_definition
{
	s_tag_reference base_template;
	s_tag_block shader_maps; // TODO
	s_tag_block arguments; // TODO
	s_tag_block unknown1; // TODO
	long unknown2;
	s_tag_block unknown3; // TODO
	s_tag_block unknown4; // TODO
	s_tag_block unknown5; // TODO
	s_tag_block functions; // TODO
	long unknown6;
	long unknown7;
	real unknown8;
	short unknown9;
	short unknown10;
	short unknown11;
	short unknown12;
	short unknown13;
	short unknown14;
	short unknown15;
	short unknown16;
	short unknown17;
	short unknown18;
	short unknown19;
	short unknown20;
	short unknown21;
	short unknown22;
	short unknown23;
	short unknown24;
	short unknown25;
	short unknown26;
	short unknown27;
	short unknown28;
	short unknown29;
	short unknown30;
	short unknown31;
	short unknown32;
	short unknown33;
	short unknown34;
	short unknown35;
	short unknown36;
	long resource_index;
	long : 32;
};
static_assert(sizeof(s_render_method_postprocess_definition) == 0xB4);

struct s_render_method_unknown
{
	// TODO
};

/* ---------- classes */

class c_render_method
{
public:
	s_tag_reference base_render_method;
	s_tag_reference unknown10;
	c_typed_tag_block<s_render_method_option_reference> options;
	c_typed_tag_block<s_render_method_import_data> import_data;
	c_typed_tag_block<s_render_method_postprocess_definition> postprocess_definitions;
	long unknown54;
	long unknown58;
	c_typed_tag_block<s_render_method_unknown> unknown5C;
	c_enum<e_function_variable_type, char> input_variable;
	c_enum<e_function_variable_type, char> range_variable;
	c_enum<e_function_output_modifier, char> output_modifier;
	c_enum<e_function_variable_type, char> output_modifier_input;
	real runtime_m_constant_value;
	long runtime_m_index;
};
static_assert(sizeof(c_render_method) == 0x64);

class c_render_method_shader : public c_render_method
{
public:
	string_id material_name;
};
static_assert(sizeof(c_render_method_shader) == sizeof(c_render_method) + 0x4);
