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
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MUFFIN_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("link to render model", nullptr, FIELD_FLAG_NONE, _field_id_unknown_compile),
		{ _field_tag_reference, "render model", FIELD_FLAG_READ_ONLY, &render_model_reference$5 },
		{ _field_block, "render model permutation names", FIELD_FLAG_UNKNOWN0, &muffin_permutation_name_block },
		{ _field_long_integer, "render model permutation name valid count", FIELD_FLAG_UNKNOWN0 },
		{ _field_block, "muffin markers", "defines where muffins appear, how often, and which types", &muffin_marker_block },
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
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MUFFIN_PERMUTATION_NAME_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define MUFFIN_MARKER_BLOCK_ID { 0x02BF185B, 0xBDE44510, 0x94C0C253, 0x327F1A01 }
	TAG_BLOCK(
		muffin_marker_block,
		"muffin_marker_block",
		SHORT_MAX,
		"s_muffin_marker",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MUFFIN_MARKER_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_word_integer, "muffinage chance", "how often muffins will appear on this marker", "percent ", "[0 - 100]" },
		{ _field_word_block_flags, "allowed muffin types", &global_muffin_type_block },
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
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_MUFFIN_TYPE_STRUCT_ID)
	{
		{ _field_short_block_index, "mesh", FIELD_FLAG_INDEX, &muffin_permutation_name_block },
		{ _field_word_flags, "flags", &muffin_type_flags_definition },
		{ _field_real_bounds, "spawn delay", "how long to wait before spawning these muffins", "seconds" },
		FIELD_EXPLANATION("SCALE", nullptr, FIELD_FLAG_NONE, "animates the size of the muffin"),
		{ _field_real_bounds, "random scale", nullptr, nullptr, "[0-1]" },
		{ _field_struct, "initial growth", &muffin_scalar_function_struct },
		{ _field_real, "growth time", nullptr, "seconds" },
		{ _field_struct, "periodic noise", &muffin_scalar_function_struct },
		FIELD_EXPLANATION("JIGGLE", nullptr, FIELD_FLAG_NONE, "Jigglypuff will kick your ass..."),
		{ _field_real, "jiggle", "how much the muffin jiggles (0 = perfectly rigid, 1 = full jiggle, subject to parameters below)", nullptr, "[0.0 - 1.0]" },
		{ _field_real, "jiggle spring length", "spring length affects how the spring reacts to the model moving (this should be approximately how far the muffin sticks out from the model)", "world units" },
		{ _field_real, "jiggle spring strength", "spring strength affects how fast the muffins jiggle (higher numbers jiggle faster)", nullptr, "[0.01 - 1.0]" },
		{ _field_real, "jiggle velocity damp", "velocity damp affects how long the muffins jiggle (the higher numbers jiggle exponentially longer, 1.0 will never stop jiggling)", nullptr, "[0.5 - 0.95]" },
		{ _field_real, "jiggle max velocity", "this just clamps how fast the muffin can jiggle, to keep it from exploding", "world units per frame" },
		FIELD_EXPLANATION("DEATH", nullptr, FIELD_FLAG_NONE, "... and then you will be dead."),
		{ _field_real_bounds, "lifetime", "how long before the muffins die", "seconds" },
		{ _field_real, "immortality chance", "the chance that any give muffin of this type will live forever", nullptr, "[0.0 - 1.0]" },
		{ _field_tag_reference, "death effect", &global_effect_reference },
		{ _field_terminator }
	};

	#define MUFFIN_SCALAR_FUNCTION_STRUCT_ID { 0xE0DF474A, 0xDBEB491C, 0xB0EC54D4, 0x593073E1 }
	TAG_STRUCT(
		muffin_scalar_function_struct,
		"muffin_scalar_function_struct",
		"s_muffin_scalar_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MUFFIN_SCALAR_FUNCTION_STRUCT_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
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

