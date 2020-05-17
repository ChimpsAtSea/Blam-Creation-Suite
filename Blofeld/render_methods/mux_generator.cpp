#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(mux_generator, MUX_GENERATOR_TAG, mux_generator_block_block );

	TAG_BLOCK(mux_generator_material_block, s_mux_generator::k_max_materials)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_tag_reference, "mux material" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(mux_generator_block, 1, mux_generator_struct_definition_struct_definition );

	TAG_STRUCT(mux_generator_struct_definition)
	{
		FIELD( _field_custom, "generate" ),
		FIELD( _field_explanation, "Blend Map" ),
		FIELD( _field_tag_reference, "blend texture" ),
		FIELD( _field_long_block_index, "first material in blend map" ),
		FIELD( _field_long_block_index, "last material in blend map" ),
		FIELD( _field_block, "materials", &mux_generator_material_block_block ),
		FIELD( _field_explanation, "TARGETS" ),
		FIELD( _field_tag_reference, "target mux shader" ),
		FIELD( _field_tag_reference, "target albedo base" ),
		FIELD( _field_tag_reference, "target albedo detail" ),
		FIELD( _field_tag_reference, "target bump base" ),
		FIELD( _field_tag_reference, "target bump detail" ),
		FIELD( _field_tag_reference, "target parallax" ),
		FIELD( _field_tag_reference, "target material 0" ),
		FIELD( _field_tag_reference, "target material 1" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

