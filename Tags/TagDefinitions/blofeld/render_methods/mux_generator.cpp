#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(mux_generator, MUX_GENERATOR_TAG, mux_generator_block_block );

	V5_TAG_BLOCK(mux_generator_material_block, s_mux_generator::k_max_materials)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_tag_reference, "mux material", &Tag::Reference<class c_render_method_shader_mux_material>::s_defaultDefinition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(mux_generator_block, 1, mux_generator_struct_definition_struct_definition );

	V5_TAG_STRUCT(mux_generator_struct_definition)
	{
		{ _field_legacy, _field_custom, "generate" },
		{ _field_legacy, _field_explanation, "Blend Map", "The blend map determines which material shows up where in your mux shader.\nWhere the blend map is black (color 0) you will see the first material\nWhere it is white (color 255), you will see the last material\nIn between it will blend through all the materials in order (at least once through the list)\nSo if you have 5 materials, first set to 1, and last set to 2, the material order is:\n1-2-3-4-0-1-2\nBy default, it starts and ends at the first material:\n0-1-2-3-4-0\n" },
		{ _field_legacy, _field_tag_reference, "blend texture", &bitmap_reference$10 },
		{ _field_legacy, _field_long_block_index, "first material in blend map" },
		{ _field_legacy, _field_long_block_index, "last material in blend map" },
		{ _field_legacy, _field_block, "materials", &mux_generator_material_block_block },
		{ _field_legacy, _field_explanation, "TARGETS", "these will be filled out automatically if you don\'t specify them\nthese are the tags that will be modified by this mux generator\n" },
		{ _field_legacy, _field_tag_reference, "target mux shader", &shader_mux_reference },
		{ _field_legacy, _field_tag_reference, "target albedo base", &bitmap_reference$10 },
		{ _field_legacy, _field_tag_reference, "target albedo detail", &bitmap_reference$10 },
		{ _field_legacy, _field_tag_reference, "target bump base", &bitmap_reference$10 },
		{ _field_legacy, _field_tag_reference, "target bump detail", &bitmap_reference$10 },
		{ _field_legacy, _field_tag_reference, "target parallax", &bitmap_reference$10 },
		{ _field_legacy, _field_tag_reference, "target material 0", &bitmap_reference$10 },
		{ _field_legacy, _field_tag_reference, "target material 1", &bitmap_reference$10 },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

