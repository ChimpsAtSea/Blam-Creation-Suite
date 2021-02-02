#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		antenna_group,
		ANTENNA_TAG,
		nullptr,
		INVALID_TAG,
		antenna_block );

	TAG_BLOCK_FROM_STRUCT(
		antenna_block,
		"antenna_block",
		1,
		antenna_struct_definition);

	#define ANTENNA_VERTEX_BLOCK_ID { 0x5F3BF4F0, 0x7754476A, 0x8359AD41, 0xAB160F49 }
	TAG_BLOCK(
		antenna_vertex_block,
		"antenna_vertex_block",
		MAXIMUM_NUMBER_OF_ANTENNA_VERTICES,
		"antenna_vertex",
		ANTENNA_VERTEX_BLOCK_ID)
	{
		{ _field_real_euler_angles_2d, "angles", "direction toward next vertex!" },
		{ _field_real, "length", "distance between this vertex and the next", "world units" },
		{ _field_short_integer, "sequence index", "bitmap group sequence index for this vertex\'s texture" },
		FIELD_PAD("NTCTQQF", nullptr, 2),
		{ _field_real_argb_color, "color", "color at this vertex" },
		{ _field_real_argb_color, "LOD color", "color at this vertex for the low-LOD line primitives!" },
		{ _field_real, "hermite t" },
		{ _field_real_vector_3d, "vector to next" },
		{ _field_terminator }
	};

	#define ANTENNA_STRUCT_DEFINITION_ID { 0xB3BE1D39, 0xEF274B86, 0x866479C8, 0xE030C9EE }
	TAG_STRUCT(
		antenna_struct_definition,
		"antenna_struct_definition",
		"antenna_definition",
		ANTENNA_STRUCT_DEFINITION_ID)
	{
		{ _field_old_string_id, "attachment marker name", "the marker name where the antenna should be attached" },
		{ _field_tag_reference, "bitmaps", &bitmap_reference$4 },
		{ _field_tag_reference, "physics", &global_point_physics_reference },
		{ _field_real_fraction, "spring strength coefficient", "strength of the spring (larger values make the spring stronger)" },
		{ _field_real, "texel to world width scale" },
		{ _field_real, "falloff pixels" },
		{ _field_real, "cutoff pixels" },
		{ _field_real, "point of bend", "[0,1]" },
		{ _field_real, "starting bend", "[0,1]" },
		{ _field_real, "ending bend", "[0,1]" },
		{ _field_real, "runtime total length" },
		{ _field_block, "vertices", &antenna_vertex_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

