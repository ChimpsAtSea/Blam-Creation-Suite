#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(mux_generator, MUX_GENERATOR_TAG, mux_generator_block_block );

	TAG_BLOCK(mux_generator_material_block, s_mux_generator::k_max_materials)
	{
		{ _field_string_id, "name^" },
		{ _field_tag_reference, "mux material", &Tag::Reference<class c_render_method_shader_mux_material>::s_defaultDefinition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(mux_generator_block, 1, mux_generator_struct_definition_struct_definition );

	TAG_STRUCT(mux_generator_struct_definition)
	{
		{ _field_custom, "generate" },
		{ _field_explanation, "Blend Map" },
		{ _field_tag_reference, "blend texture", &bitmap_reference$10 },
		{ _field_long_block_index, "first material in blend map" },
		{ _field_long_block_index, "last material in blend map" },
		{ _field_block, "materials", &mux_generator_material_block_block },
		{ _field_explanation, "TARGETS" },
		{ _field_tag_reference, "target mux shader", &shader_mux_reference },
		{ _field_tag_reference, "target albedo base", &bitmap_reference$10 },
		{ _field_tag_reference, "target albedo detail", &bitmap_reference$10 },
		{ _field_tag_reference, "target bump base", &bitmap_reference$10 },
		{ _field_tag_reference, "target bump detail", &bitmap_reference$10 },
		{ _field_tag_reference, "target parallax", &bitmap_reference$10 },
		{ _field_tag_reference, "target material 0", &bitmap_reference$10 },
		{ _field_tag_reference, "target material 1", &bitmap_reference$10 },
		{ _field_terminator }
	};

} // namespace blofeld

