#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		particle_emitter_custom_points_group,
		PARTICLE_EMITTER_CUSTOM_POINTS_TAG,
		nullptr,
		INVALID_TAG,
		particle_emitter_custom_points_block );

	TAG_BLOCK_FROM_STRUCT(
		particle_emitter_custom_points_block,
		"particle_emitter_custom_points_block",
		1,
		particle_emitter_custom_points_struct_definition);

	#define PARTICLE_EMITTER_CUSTOM_POINT_BLOCK_ID { 0x705D9DDC, 0x15864BBC, 0x898A1244, 0x8425BCAE }
	TAG_BLOCK(
		particle_emitter_custom_point_block,
		"particle_emitter_custom_point_block",
		s_particle_emitter_custom_points::k_maximum_points,
		"s_particle_emitter_custom_points::s_point",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_EMITTER_CUSTOM_POINT_BLOCK_ID)
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

	#define PARTICLE_EMITTER_CUSTOM_POINTS_STRUCT_DEFINITION_ID { 0xB96E0D8B, 0xD98049CD, 0xB32EB972, 0x2FBDCDDB }
	TAG_STRUCT(
		particle_emitter_custom_points_struct_definition,
		"particle_emitter_custom_points_struct_definition",
		"s_particle_emitter_custom_points",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_EMITTER_CUSTOM_POINTS_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("import", nullptr, _field_id_unknown_compile),
		FIELD_EXPLANATION("PARTICLE POINTS", nullptr, "Explanation goes here.\nWoo....\n"),
		{ _field_tag_reference, "source reference", &particle_model_reference },
		{ _field_real_vector_3d, "compression scale" },
		{ _field_real_vector_3d, "compression offset" },
		{ _field_block, "points", &particle_emitter_custom_point_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(particle_emitter_custom_shape_reference, PARTICLE_EMITTER_CUSTOM_POINTS_TAG);

	TAG_REFERENCE(particle_model_reference, PARTICLE_MODEL_TAG);

} // namespace macaque

} // namespace blofeld

