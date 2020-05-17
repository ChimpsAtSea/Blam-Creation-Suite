#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(muffin, MUFFIN_TAG)
	{
		FIELD( _field_custom, "link to render model" ),
		FIELD( _field_tag_reference, "render model*" ),
		FIELD( _field_block, "render model permutation names!", &muffin_permutation_name_block_block ),
		FIELD( _field_long_integer, "render model permutation name valid count!" ),
		FIELD( _field_block, "muffin markers{default markers}#defines where muffins appear, how often, and which types", &muffin_marker_block_block ),
		FIELD( _field_block, "muffin types", &global_muffin_type_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(muffin_permutation_name_block, SHORT_MAX)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(muffin_marker_block, SHORT_MAX)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_word_integer, "muffinage chance:percent [0 - 100]#how often muffins will appear on this marker" ),
		FIELD( _field_word_block_flags, "allowed muffin types" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(global_muffin_type_block, 16, global_muffin_type_struct_struct_definition );

	TAG_STRUCT(global_muffin_type_struct)
	{
		FIELD( _field_short_block_index, "mesh^" ),
		FIELD( _field_word_flags, "flags", &muffin_type_flags_definition ),
		FIELD( _field_real_bounds, "spawn delay:seconds#how long to wait before spawning these muffins" ),
		FIELD( _field_explanation, "SCALE" ),
		FIELD( _field_real_bounds, "random scale:[0-1]" ),
		FIELD( _field_struct, "initial growth", &muffin_scalar_function_struct_struct_definition ),
		FIELD( _field_real, "growth time:seconds" ),
		FIELD( _field_struct, "periodic noise", &muffin_scalar_function_struct_struct_definition ),
		FIELD( _field_explanation, "JIGGLE" ),
		FIELD( _field_real, "jiggle:[0.0 - 1.0]#how much the muffin jiggles (0 = perfectly rigid, 1 = full jiggle, subject to parameters below)" ),
		FIELD( _field_real, "jiggle spring length:world units#spring length affects how the spring reacts to the model moving (this should be approximately how far the muffin sticks out from the model)" ),
		FIELD( _field_real, "jiggle spring strength:[0.01 - 1.0]#spring strength affects how fast the muffins jiggle (higher numbers jiggle faster)" ),
		FIELD( _field_real, "jiggle velocity damp:[0.5 - 0.95]#velocity damp affects how long the muffins jiggle (the higher numbers jiggle exponentially longer, 1.0 will never stop jiggling)" ),
		FIELD( _field_real, "jiggle max velocity:world units per frame#this just clamps how fast the muffin can jiggle, to keep it from exploding" ),
		FIELD( _field_explanation, "DEATH" ),
		FIELD( _field_real_bounds, "lifetime:seconds#how long before the muffins die" ),
		FIELD( _field_real, "immortality chance:[0.0 - 1.0]#the chance that any give muffin of this type will live forever" ),
		FIELD( _field_tag_reference, "death effect" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(muffin_scalar_function_struct)
	{
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(muffin_type_flags_definition, 2)
	{
		OPTION("disable for debug"),
		OPTION("jump to marker on transition#forces the muffins to the new marker location when they are transferred to a new model, may cause popping if the markers aren\'t aligned"),
	};

} // namespace blofeld

