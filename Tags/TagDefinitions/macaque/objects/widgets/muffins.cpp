#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MUFFIN_STRUCT_DEFINITION_ID { 0x9457B543, 0xE9544059, 0xB3F1A8B8, 0x4492C9F1 }
	TAG_BLOCK(
		muffin_block,
		"muffin_block",
		1,
		"s_muffin_definition",
		MUFFIN_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("link to render model", _custom_field_unknown_compile),
		{ _field_tag_reference, "render model*", &render_model_reference$5 },
		{ _field_block, "render model permutation names!", &muffin_permutation_name_block },
		{ _field_long_integer, "render model permutation name valid count!" },
		{ _field_block, "muffin markers{default markers}#defines where muffins appear, how often, and which types", &muffin_marker_block },
		{ _field_block, "muffin types", &global_muffin_type_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		muffin_group,
		MUFFIN_TAG,
		nullptr,
		INVALID_TAG,
		muffin_block );

	#define MUFFIN_PERMUTATION_NAME_BLOCK_ID { 0x549A4CAB, 0xC2DE4599, 0x8E98C68E, 0xC87E36AA }
	TAG_BLOCK(
		muffin_permutation_name_block,
		"muffin_permutation_name_block",
		SHORT_MAX,
		"string_id",
		MUFFIN_PERMUTATION_NAME_BLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_terminator }
	};

	#define MUFFIN_MARKER_BLOCK_ID { 0x02BF185B, 0xBDE44510, 0x94C0C253, 0x327F1A01 }
	TAG_BLOCK(
		muffin_marker_block,
		"muffin_marker_block",
		SHORT_MAX,
		"s_muffin_marker",
		MUFFIN_MARKER_BLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_word_integer, "muffinage chance:percent [0 - 100]#how often muffins will appear on this marker" },
		{ _field_word_block_flags, "allowed muffin types" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		global_muffin_type_block,
		"global_muffin_type_block",
		16,
		global_muffin_type_struct);

	#define GLOBAL_MUFFIN_TYPE_STRUCT_ID { 0x0EB31413, 0xE68F4840, 0xB0E7C088, 0x51EED254 }
	TAG_STRUCT(
		global_muffin_type_struct,
		"global_muffin_type_struct",
		"s_muffin_type",
		GLOBAL_MUFFIN_TYPE_STRUCT_ID)
	{
		{ _field_short_block_index, "mesh^" },
		{ _field_word_flags, "flags", &muffin_type_flags_definition },
		{ _field_real_bounds, "spawn delay:seconds#how long to wait before spawning these muffins" },
		{ _field_explanation, "SCALE", "animates the size of the muffin" },
		{ _field_real_bounds, "random scale:[0-1]" },
		{ _field_struct, "initial growth", &muffin_scalar_function_struct },
		{ _field_real, "growth time:seconds" },
		{ _field_struct, "periodic noise", &muffin_scalar_function_struct },
		{ _field_explanation, "JIGGLE", "Jigglypuff will kick your ass..." },
		{ _field_real, "jiggle:[0.0 - 1.0]#how much the muffin jiggles (0 = perfectly rigid, 1 = full jiggle, subject to parameters below)" },
		{ _field_real, "jiggle spring length:world units#spring length affects how the spring reacts to the model moving (this should be approximately how far the muffin sticks out from the model)" },
		{ _field_real, "jiggle spring strength:[0.01 - 1.0]#spring strength affects how fast the muffins jiggle (higher numbers jiggle faster)" },
		{ _field_real, "jiggle velocity damp:[0.5 - 0.95]#velocity damp affects how long the muffins jiggle (the higher numbers jiggle exponentially longer, 1.0 will never stop jiggling)" },
		{ _field_real, "jiggle max velocity:world units per frame#this just clamps how fast the muffin can jiggle, to keep it from exploding" },
		{ _field_explanation, "DEATH", "... and then you will be dead." },
		{ _field_real_bounds, "lifetime:seconds#how long before the muffins die" },
		{ _field_real, "immortality chance:[0.0 - 1.0]#the chance that any give muffin of this type will live forever" },
		{ _field_tag_reference, "death effect", &global_effect_reference },
		{ _field_terminator }
	};

	#define MUFFIN_SCALAR_FUNCTION_STRUCT_ID { 0xE0DF474A, 0xDBEB491C, 0xB0EC54D4, 0x593073E1 }
	TAG_STRUCT(
		muffin_scalar_function_struct,
		"muffin_scalar_function_struct",
		"s_muffin_scalar_function",
		MUFFIN_SCALAR_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(muffin_type_flags_definition)
	{
		"disable for debug",
		"jump to marker on transition#forces the muffins to the new marker location when they are transferred to a new model, may cause popping if the markers aren\'t aligned"
	};
	STRING_LIST(muffin_type_flags_definition, muffin_type_flags_definition_strings, _countof(muffin_type_flags_definition_strings));

} // namespace macaque

} // namespace blofeld

