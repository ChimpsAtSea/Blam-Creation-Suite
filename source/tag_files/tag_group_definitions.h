#pragma once

#include <cseries/cseries.h>

/* ---------- persistent identifiers */

struct s_tag_persistent_identifier
{
	GUID uuid;
};
static_assert(sizeof(s_tag_persistent_identifier) == 0x10);

bool tag_persistent_identifiers_equal(
	s_tag_persistent_identifier const &identifier1,
	s_tag_persistent_identifier const &identifier2);

/* ----------- types */

enum e_field_type
{
	_field_tag,
	_field_short_string,
	_field_long_string,
	_field_string_id,
	_field_char_integer,
	_field_short_integer,
	_field_long_integer,
	_field_int64_integer,
	_field_byte_integer,
	_field_word_integer,
	_field_dword_integer,
	_field_qword_integer,
	_field_char_enum,
	_field_short_enum,
	_field_long_enum,
	_field_byte_flags,
	_field_word_flags,
	_field_long_flags,
	_field_point2d,
	_field_rectangle2d,
	_field_rgb_color,
	_field_argb_color,
	_field_angle,
	_field_real,
	_field_real_fraction,
	_field_real_point2d,
	_field_real_point3d,
	_field_real_vector2d,
	_field_real_vector3d,
	_field_real_quaternion,
	_field_real_euler_angles2d,
	_field_real_euler_angles3d,
	_field_real_plane2d,
	_field_real_plane3d,
	_field_real_matrix4x3,
	_field_real_rgb_color,
	_field_real_argb_color,
	_field_real_hsv_color,
	_field_real_ahsv_color,
	_field_real_rectangle3d,
	_field_short_bounds,
	_field_angle_bounds,
	_field_real_bounds,
	_field_fraction_bounds,
	_field_tag_reference,
	_field_block,
	_field_char_block_index,
	_field_short_block_index,
	_field_long_block_index,
	_field_byte_block_flags,
	_field_word_block_flags,
	_field_long_block_flags,
	_field_data,
	_field_datum_index,
	_field_resource,
	_field_struct,
	_field_array,
	_field_pad,
	_field_skip,
	_field_explanation,
	_field_terminator,
	k_number_of_field_types
};

struct s_field_definition
{
	e_field_type type;
#ifdef _WIN64
	long : 32;
#endif
	char const *name;
	const void *definition;
};

struct s_enum_option
{
	char const *name;
	long value;
#ifdef _WIN64
	long : 32;
#endif
};

struct s_enum_definition
{
	char const *name;
	long option_count;
#ifdef _WIN64
	long : 32;
#endif
	s_enum_option const *options;
};

struct s_struct_definition
{
	char const *name;
	tag group_tag;
	long size;
	long maximum_elements;
#ifdef _WIN64
	long : 32;
#endif
	s_field_definition const *fields;
	s_struct_definition const *parent;
};

struct s_array_definition
{
	e_field_type type;
#ifdef _WIN64
	long : 32;
#endif
	char const *name;
	long length;
#ifdef _WIN64
	long : 32;
#endif
	const void *definition;
};

struct s_tag_block_definition :
	s_struct_definition
{
};

struct s_tag_data_definition
{
	char const *name;
	long maximum_size;
#ifdef _WIN64
	long : 32;
#endif
};

struct s_tag_reference_definition
{
	char const *name;
	long group_tag_count;
#ifdef _WIN64
	long : 32;
#endif
	tag const *group_tags;
};

struct s_tag_group :
	s_struct_definition
{
};

struct s_pad_definition
{
	e_field_type type;
#ifdef _WIN64
	long : 32;
#endif
	char const *name;
	long length;
#ifdef _WIN64
	long : 32;
#endif
	const void *definition;
};

/* ---------- macros */

#define TAG_ENUM(name, option_count) \
	extern s_enum_option name##_options[]; \
	s_enum_definition name = { #name, static_cast<long>(option_count), name##_options }; \
	s_enum_option name##_options[] =

#define TAG_STRUCT(name, size, ...) \
	extern s_field_definition name##_fields[]; \
	s_struct_definition name = { #name, static_cast<tag>(NONE), size, NONE, name##_fields, __VA_ARGS__ }; \
	s_field_definition name##_fields[] =

#define TAG_ARRAY(type, name, length, ...) \
	s_array_definition name = { type, #name, length, __VA_ARGS__ }

#define TAG_BLOCK(name, size, maximum_count, ...) \
	extern s_field_definition name##_fields[]; \
	s_tag_block_definition name = { #name, static_cast<tag>(NONE), size, maximum_count, name##_fields, __VA_ARGS__ }; \
	s_field_definition name##_fields[] =

#define TAG_DATA(name, maximum_size) \
	s_tag_data_definition name = { #name, maximum_size }

#define TAG_REFERENCE(name, group_tag_count) \
	extern tag name##_group_tags[group_tag_count]; \
	s_tag_reference_definition name = { #name, group_tag_count, name##_group_tags }; \
	tag name##_group_tags[group_tag_count] =

#define TAG_GROUP(name, group_tag, size, ...) \
	extern s_field_definition name##_fields[]; \
	s_tag_group name = { #name, group_tag, size, NONE, name##_fields, __VA_ARGS__ }; \
	s_field_definition name##_fields[] =

#define TAG_PAD(type, name, length, ...) \
	s_pad_definition name = { type, #name, length, __VA_ARGS__ }
