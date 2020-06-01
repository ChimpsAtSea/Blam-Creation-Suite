#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(particle_emitter_custom_points, PARTICLE_EMITTER_CUSTOM_POINTS_TAG, particle_emitter_custom_points_block_block );

	TAG_BLOCK(particle_emitter_custom_point_block, s_particle_emitter_custom_points::k_maximum_points)
	{
		{ _field_short_integer, "position_x" },
		{ _field_short_integer, "position_y" },
		{ _field_short_integer, "position_z" },
		{ _field_char_integer, "normal_x" },
		{ _field_char_integer, "normal_y" },
		{ _field_char_integer, "normal_z" },
		{ _field_byte_integer, "correlation" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(particle_emitter_custom_points_block, 1, particle_emitter_custom_points_struct_definition_struct_definition );

	TAG_STRUCT(particle_emitter_custom_points_struct_definition)
	{
		{ _field_custom, "import" },
		{ _field_explanation, "PARTICLE POINTS", "Explanation goes here.\nWoo....\n" },
		{ _field_tag_reference, "source reference!", &particle_model_reference },
		{ _field_real_vector_3d, "compression scale" },
		{ _field_real_vector_3d, "compression offset" },
		{ _field_block, "points", &particle_emitter_custom_point_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(particle_emitter_custom_shape_reference, PARTICLE_EMITTER_CUSTOM_POINTS_TAG);

	TAG_REFERENCE(particle_model_reference, PARTICLE_MODEL_TAG);

} // namespace blofeld

