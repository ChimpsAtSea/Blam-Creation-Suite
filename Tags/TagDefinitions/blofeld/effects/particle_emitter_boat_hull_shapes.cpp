#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(particle_emitter_boat_hull_shape, PARTICLE_EMITTER_BOAT_HULL_SHAPE_TAG, particle_emitter_boat_hull_shape_block_block );

	TAG_BLOCK(particle_emitter_boat_hull_group_block, s_particle_emitter_boat_hull_shape_data::k_max_groups_per_hull_shape)
	{
		{ _field_string_id, "marker group^" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(particle_emitter_boat_hull_shape_block, 1, particle_emitter_boat_hull_shape_struct_definition_struct_definition );

	TAG_STRUCT(particle_emitter_boat_hull_shape_struct_definition)
	{
		{ _field_char_enum, "distribution#heuristic used to determine where to spawn particles", &particle_emitter_boat_hull_distribution_type },
		{ _field_pad, "PEBHSP1", 3 },
		{ _field_block, "markers", &particle_emitter_boat_hull_group_block_block },
		{ _field_terminator }
	};

	STRINGS(particle_emitter_boat_hull_distribution_type)
	{
		"connect the dots#project hull surface locations onto the water and spawn particles along the resulting path.",
		"along hull surface only#spawn particles on the hull surface where it intersects with the water."
	};
	STRING_LIST(particle_emitter_boat_hull_distribution_type, particle_emitter_boat_hull_distribution_type_strings, _countof(particle_emitter_boat_hull_distribution_type_strings));

	TAG_REFERENCE(particle_emitter_boat_hull_shape_reference, PARTICLE_EMITTER_BOAT_HULL_SHAPE_TAG);

} // namespace blofeld

