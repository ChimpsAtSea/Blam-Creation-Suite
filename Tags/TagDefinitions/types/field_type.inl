using namespace xxhash;
struct s_field_to_tagfile_field_type
{
	const char* tag_field_string;
	const char* tag_field_type;
};

static s_field_to_tagfile_field_type const k_field_to_tagfile_field_type[]
{
#define FIELD_TO_TAG_FIELD_TYPE(_field, _tag_field_type) { #_field, _tag_field_type }
		FIELD_TO_TAG_FIELD_TYPE(_field_string, "string"),
		FIELD_TO_TAG_FIELD_TYPE(_field_long_string, "long string"),
		FIELD_TO_TAG_FIELD_TYPE(_field_string_id, "string id"),
		FIELD_TO_TAG_FIELD_TYPE(_field_old_string_id, "old string id"),
		FIELD_TO_TAG_FIELD_TYPE(_field_char_integer, "char integer"),
		FIELD_TO_TAG_FIELD_TYPE(_field_short_integer, "short integer"),
		FIELD_TO_TAG_FIELD_TYPE(_field_long_integer, "long integer"),
		FIELD_TO_TAG_FIELD_TYPE(_field_int64_integer, "int64 integer"),
		FIELD_TO_TAG_FIELD_TYPE(_field_angle, "angle"),
		FIELD_TO_TAG_FIELD_TYPE(_field_tag, "tag"),
		FIELD_TO_TAG_FIELD_TYPE(_field_char_enum, "char enum"),
		FIELD_TO_TAG_FIELD_TYPE(_field_short_enum, "short enum"),
		FIELD_TO_TAG_FIELD_TYPE(_field_long_enum, "long enum"),
		FIELD_TO_TAG_FIELD_TYPE(_field_long_flags, "long flags"),
		FIELD_TO_TAG_FIELD_TYPE(_field_word_flags, "word flags"),
		FIELD_TO_TAG_FIELD_TYPE(_field_byte_flags, "byte flags"),
		FIELD_TO_TAG_FIELD_TYPE(_field_point_2d, "point 2d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_rectangle_2d, "rectangle 2d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_rgb_color, "rgb color"),
		FIELD_TO_TAG_FIELD_TYPE(_field_argb_color, "argb color"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real, "real"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_fraction, "real fraction"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_point_2d, "real point 2d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_point_3d, "real point 3d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_vector_2d, "real vector 2d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_vector_3d, "real vector 3d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_quaternion, "real quaternion"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_euler_angles_2d, "real euler angles 2d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_euler_angles_3d, "real euler angles 3d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_plane_2d, "real plane 2d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_plane_3d, "real plane 3d"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_rgb_color, "real rgb color"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_argb_color, "real argb color"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_hsv_color, "real hsv color"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_ahsv_color, "real ahsv color"),
		FIELD_TO_TAG_FIELD_TYPE(_field_short_integer_bounds, "short integer bounds"),
		FIELD_TO_TAG_FIELD_TYPE(_field_angle_bounds, "angle bounds"),
		FIELD_TO_TAG_FIELD_TYPE(_field_real_bounds, "real bounds"),
		FIELD_TO_TAG_FIELD_TYPE(_field_fraction_bounds, "fraction bounds"),
		FIELD_TO_TAG_FIELD_TYPE(_field_tag_reference, "tag reference"),
		FIELD_TO_TAG_FIELD_TYPE(_field_block, "block"),
		FIELD_TO_TAG_FIELD_TYPE(_field_long_block_flags, "long block flags"),
		FIELD_TO_TAG_FIELD_TYPE(_field_word_block_flags, "word block flags"),
		FIELD_TO_TAG_FIELD_TYPE(_field_byte_block_flags, "byte block flags"),
		FIELD_TO_TAG_FIELD_TYPE(_field_char_block_index, "char block index"),
		FIELD_TO_TAG_FIELD_TYPE(_field_custom_char_block_index, "custom char block index"),
		FIELD_TO_TAG_FIELD_TYPE(_field_short_block_index, "short block index"),
		FIELD_TO_TAG_FIELD_TYPE(_field_custom_short_block_index, "custom short block index"),
		FIELD_TO_TAG_FIELD_TYPE(_field_long_block_index, "long block index"),
		FIELD_TO_TAG_FIELD_TYPE(_field_custom_long_block_index, "custom long block index"),
		FIELD_TO_TAG_FIELD_TYPE(_field_data, "data"),
		FIELD_TO_TAG_FIELD_TYPE(_field_vertex_buffer, "vertex buffer"),
		FIELD_TO_TAG_FIELD_TYPE(_field_pad, "pad"),
		FIELD_TO_TAG_FIELD_TYPE(_field_useless_pad, "useless pad"),
		FIELD_TO_TAG_FIELD_TYPE(_field_skip, "skip"),
		FIELD_TO_TAG_FIELD_TYPE(_field_non_cache_runtime_value, "non-cache runtime value"),
		FIELD_TO_TAG_FIELD_TYPE(_field_explanation, "explanation"),
		FIELD_TO_TAG_FIELD_TYPE(_field_custom, "custom"),
		FIELD_TO_TAG_FIELD_TYPE(_field_struct, "struct"),
		FIELD_TO_TAG_FIELD_TYPE(_field_array, "array"),
		FIELD_TO_TAG_FIELD_TYPE(_field_pageable_resource, "pageable resource"),
		FIELD_TO_TAG_FIELD_TYPE(_field_api_interop, "api interop"),
		FIELD_TO_TAG_FIELD_TYPE(_field_terminator, "terminator X"),
		FIELD_TO_TAG_FIELD_TYPE(_field_byte_integer, "byte integer"),
		FIELD_TO_TAG_FIELD_TYPE(_field_word_integer, "word integer"),
		FIELD_TO_TAG_FIELD_TYPE(_field_dword_integer, "dword integer"),
		FIELD_TO_TAG_FIELD_TYPE(_field_qword_integer, "qword integer"),
		FIELD_TO_TAG_FIELD_TYPE(_field_data_path, "data path"), // H5F/INF
		FIELD_TO_TAG_FIELD_TYPE(_field_embedded_tag, "embedded tag"), // H5F/INF
		FIELD_TO_TAG_FIELD_TYPE(_field_pointer, "pointer"), // #NONSTANDARD
		FIELD_TO_TAG_FIELD_TYPE(_field_half, "half"), // #NONSTANDARD
	#undef FIELD_TO_TAG_FIELD_TYPE
};
static_assert(_countof(k_field_to_tagfile_field_type) == blofeld::k_number_of_blofeld_field_types);

BCS_RESULT blofeld::field_to_tagfile_field_type(e_field field, const char*& tag_field_type)
{
	if (field >= k_number_of_blofeld_field_types)
	{
		return BCS_E_NOT_FOUND;
	}

	tag_field_type = k_field_to_tagfile_field_type[field].tag_field_type;

	return BCS_S_OK;
}

BCS_RESULT blofeld::field_to_string(blofeld::e_field field, const char*& field_string)
{
	if (field >= blofeld::k_number_of_blofeld_field_types)
	{
		return BCS_E_NOT_FOUND;
	}

	field_string = k_field_to_tagfile_field_type[field].tag_field_string;

	return BCS_S_OK;
}
