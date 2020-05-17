#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(particle_emitter_boat_hull_shape, PARTICLE_EMITTER_BOAT_HULL_SHAPE_TAG, particle_emitter_boat_hull_shape_block_block );

	TAG_BLOCK(particle_emitter_boat_hull_group_block, s_particle_emitter_boat_hull_shape_data::k_max_groups_per_hull_shape)
	{
		FIELD( _field_string_id, "marker group^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(particle_emitter_boat_hull_shape_block, 1, particle_emitter_boat_hull_shape_struct_definition_struct_definition );

	TAG_STRUCT(particle_emitter_boat_hull_shape_struct_definition)
	{
		FIELD( _field_char_enum, "distribution#heuristic used to determine where to spawn particles", &particle_emitter_boat_hull_distribution_type ),
		FIELD( _field_pad, "PEBHSP1", 3 ),
		FIELD( _field_block, "markers", &particle_emitter_boat_hull_group_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(particle_emitter_boat_hull_distribution_type, 2)
	{
		OPTION("connect the dots#project hull surface locations onto the water and spawn particles along the resulting path."),
		OPTION("along hull surface only#spawn particles on the hull surface where it intersects with the water."),
	};

} // namespace blofeld

