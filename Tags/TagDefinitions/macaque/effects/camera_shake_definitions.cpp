#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		camera_shake_group,
		CAMERA_SHAKE_TAG,
		nullptr,
		INVALID_TAG,
		camera_shake_block );

	TAG_BLOCK_FROM_STRUCT(
		camera_shake_block,
		"camera_shake_block",
		1,
		camera_shake_struct_definition);

	#define GLOBAL_CAMERA_IMPULSE_BLOCK_ID { 0x57F39345, 0x0B824565, 0xA343C4B0, 0xFDAD9A47 }
	TAG_BLOCK(
		global_camera_impulse_block,
		"global_camera_impulse_block",
		1,
		"s_camera_impulse_globals",
		GLOBAL_CAMERA_IMPULSE_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "mapping", &mapping_function },
		{ _field_terminator }
	};

	#define CAMERA_SHAKE_STRUCT_DEFINITION_ID { 0x85B81D32, 0x7C1249A5, 0x863CDDB2, 0xA7052723 }
	TAG_STRUCT(
		camera_shake_struct_definition,
		"camera_shake_struct_definition",
		"s_camera_shake_definition",
		CAMERA_SHAKE_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "camera impulse", "" },
		{ _field_struct, "camera impulse", &camera_impulse_struct },
		{ _field_explanation, "camera shake", "" },
		{ _field_struct, "camera shake", &camera_shake_struct },
		{ _field_terminator }
	};

	#define CAMERA_IMPULSE_STRUCT_ID { 0xE55AD1CC, 0x22484F82, 0xAAEE9A87, 0xE60B4CDF }
	TAG_STRUCT(
		camera_impulse_struct,
		"camera_impulse_struct",
		"s_camera_impulse",
		CAMERA_IMPULSE_STRUCT_ID)
	{
		{ _field_real, "impulse duration:seconds" },
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "mapping", &mapping_function },
		{ _field_angle, "rotation:degrees" },
		{ _field_real, "pushback:world units" },
		{ _field_real_bounds, "jitter:world units" },
		{ _field_terminator }
	};

	#define CAMERA_SHAKE_STRUCT_ID { 0x21432949, 0x6E214B80, 0x8BD2D31B, 0x44AC9FAE }
	TAG_STRUCT(
		camera_shake_struct,
		"camera_shake_struct",
		"s_camera_shake",
		CAMERA_SHAKE_STRUCT_ID)
	{
		{ _field_real, "shake duration:seconds#the effect will last for this duration." },
		{ _field_explanation, "procedural camera shake", "" },
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "mapping", &mapping_function },
		{ _field_real, "random translation:world units#random translation in all directions" },
		{ _field_angle, "random rotation:degrees#random rotation in all directions" },
		{ _field_real, "wobble function period:seconds" },
		{ _field_real_fraction, "wobble weight#a value of 0.0 signifies that the wobble function has no effect; a value of 1.0 the wobble function completely scales the translational\n and rotational magnitudes.  The less the weight, the less the effect wobble has." },
		{ _field_enum, "wobble function#a function to perturb the effect\'s behavior over time", &global_periodic_functions_enum },
		{ _field_explanation, "animated camera shake", "" },
		{ _field_char_enum, "animated shake playback", &animated_camera_shake_playback_type_enum },
		{ _field_char_enum, "animated shake weight", &animated_camera_shake_weight_type_enum },
		{ _field_tag_reference, "animation graph", &global_animation_graph_reference },
		{ _field_string_id, "animation name" },
		{ _field_real, "zoom penalty linear #multiplier penalty that increases linearly with zoom over 1" },
		{ _field_real, "zoom penalty squareroot #multiplier penalty that increases with square root of zoom over 1" },
		{ _field_terminator }
	};

	STRINGS(animated_camera_shake_playback_type_enum)
	{
		"looping",
		"frame ratio"
	};
	STRING_LIST(animated_camera_shake_playback_type_enum, animated_camera_shake_playback_type_enum_strings, _countof(animated_camera_shake_playback_type_enum_strings));

	STRINGS(animated_camera_shake_weight_type_enum)
	{
		"effect scale",
		"full"
	};
	STRING_LIST(animated_camera_shake_weight_type_enum, animated_camera_shake_weight_type_enum_strings, _countof(animated_camera_shake_weight_type_enum_strings));

	TAG_REFERENCE(global_camera_shake_reference, CAMERA_SHAKE_TAG);

} // namespace macaque

} // namespace blofeld

