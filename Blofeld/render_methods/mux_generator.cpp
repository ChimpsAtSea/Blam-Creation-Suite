#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(mux_generator_material, s_mux_generator::k_max_materials)
{
	{ _field_string_id, "name^" },
	{ _field_tag_reference, "mux material" },
	{ _field_terminator },
};

TAG_GROUP(mux_generator, MUX_GENERATOR_TAG)
{
	{ _field_custom, "generate" },
	{ _field_explanation, "Blend Map" },
	{ _field_tag_reference, "blend texture" },
	{ _field_long_block_index, "first material in blend map" },
	{ _field_long_block_index, "last material in blend map" },
	{ _field_block, "materials", &mux_generator_material_block },
	{ _field_explanation, "TARGETS" },
	{ _field_tag_reference, "target mux shader" },
	{ _field_tag_reference, "target albedo base" },
	{ _field_tag_reference, "target albedo detail" },
	{ _field_tag_reference, "target bump base" },
	{ _field_tag_reference, "target bump detail" },
	{ _field_tag_reference, "target parallax" },
	{ _field_tag_reference, "target material 0" },
	{ _field_tag_reference, "target material 1" },
	{ _field_terminator },
};

} // namespace blofeld

