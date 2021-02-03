#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		particle_emitter_boat_hull_shape_group,
		PARTICLE_EMITTER_BOAT_HULL_SHAPE_TAG,
		nullptr,
		INVALID_TAG,
		particle_emitter_boat_hull_shape_block );

	TAG_BLOCK_FROM_STRUCT(
		particle_emitter_boat_hull_shape_block,
		"particle_emitter_boat_hull_shape_block",
		1,
		particle_emitter_boat_hull_shape_struct_definition);

	#define PARTICLE_EMITTER_BOAT_HULL_GROUP_BLOCK_ID { 0xC25B4B2B, 0x662C49B9, 0xAAA42775, 0xAE9CE079 }
	TAG_BLOCK(
		particle_emitter_boat_hull_group_block,
		"particle_emitter_boat_hull_group_block",
		s_particle_emitter_boat_hull_shape_data::k_max_groups_per_hull_shape,
		"s_particle_emitter_boat_hull_shape_data::s_marker_group",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_EMITTER_BOAT_HULL_GROUP_BLOCK_ID)
	{
		{ _field_string_id, "marker group" },
		{ _field_terminator }
	};

	#define PARTICLE_EMITTER_BOAT_HULL_SHAPE_STRUCT_DEFINITION_ID { 0xD30AB71D, 0xA7974D90, 0x8547B676, 0x631E2683 }
	TAG_STRUCT(
		particle_emitter_boat_hull_shape_struct_definition,
		"particle_emitter_boat_hull_shape_struct_definition",
		"s_particle_emitter_boat_hull_shape_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_EMITTER_BOAT_HULL_SHAPE_STRUCT_DEFINITION_ID)
	{
		{ _field_char_enum, "distribution", &particle_emitter_boat_hull_distribution_type },
		FIELD_PAD("PEBHSP1", nullptr, 3),
		{ _field_block, "markers", &particle_emitter_boat_hull_group_block },
		{ _field_terminator }
	};

	STRINGS(particle_emitter_boat_hull_distribution_type)
	{
		"connect the dots#project hull surface locations onto the water and spawn particles along the resulting path.",
		"along hull surface only#spawn particles on the hull surface where it intersects with the water."
	};
	STRING_LIST(particle_emitter_boat_hull_distribution_type, particle_emitter_boat_hull_distribution_type_strings, _countof(particle_emitter_boat_hull_distribution_type_strings));

	TAG_REFERENCE(particle_emitter_boat_hull_shape_reference, PARTICLE_EMITTER_BOAT_HULL_SHAPE_TAG);

} // namespace macaque

} // namespace blofeld

