#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(particle_emitter_boat_hull_shape_struct_definition)
{
	FIELD( _field_char_enum, "distribution#heuristic used to determine where to spawn particles" ),
	FIELD( _field_pad, "PEBHSP1", 3 ),
	FIELD( _field_block, "markers", &particle_emitter_boat_hull_group_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(particle_emitter_boat_hull_group_block, s_particle_emitter_boat_hull_shape_data::k_max_groups_per_hull_shape)
{
	FIELD( _field_string_id, "marker group^" ),
	FIELD( _field_terminator )
};

TAG_GROUP(particle_emitter_boat_hull_shape_block, PARTICLE_EMITTER_BOAT_HULL_SHAPE_TAG)
{
	FIELD( _field_char_enum, "distribution#heuristic used to determine where to spawn particles" ),
	FIELD( _field_pad, "PEBHSP1", 3 ),
	FIELD( _field_block, "markers", &particle_emitter_boat_hull_group_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

